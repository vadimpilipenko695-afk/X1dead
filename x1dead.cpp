#include <jni.h>
#include <android/log.h>
#include <android/input.h>
#include <dlfcn.h>
#include <link.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "imgui/backends/imgui_impl_android.h"

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "x1dead", __VA_ARGS__)

namespace IL2 {
    inline uintptr_t base = 0;
    inline bool init() {
        struct Ctx { bool found; } c{false};
        dl_iterate_phdr([](dl_phdr_info* info, size_t, void* d) -> int {
            if (info->dlpi_name && strstr(info->dlpi_name, "libil2cpp.so")) {
                base = info->dlpi_addr;
                ((Ctx*)d)->found = true;
                return 1;
            }
            return 0;
        }, &c);
        return c.found;
    }
    inline void* at(uintptr_t rva) { return (void*)(base + rva); }
}

namespace O {
    constexpr uintptr_t GameController_get_Instance = 0x123C37C;
    constexpr uintptr_t GameController_PlayerController = 0x200;
    constexpr uintptr_t PC_Team = 0x49;
    constexpr uintptr_t PhotonNetwork_GetRoom = 0x18D80F0;
    constexpr uintptr_t RoomInfo_CustomProperties = 0x18;
    constexpr uintptr_t Room_SetTime = 0x136F67C;
    constexpr uintptr_t Room_SetRound = 0x136F798;
    constexpr uintptr_t Room_SetScore = 0x1370124;
    constexpr uintptr_t Room_SetRoundsCount = 0x13712A0;
    constexpr uintptr_t Room_SetCustomProperties = 0x1570F1C;
}

typedef void* (*GetInstFn)(void*);
typedef void* (*GetRoomFn)(void*);
typedef void (*SetScoreFn)(void*, void*, int, int);
typedef void (*SetRoundFn)(void*, void*, int);
typedef void (*SetRcFn)(void*, void*, int);
typedef void (*SetTimeFn)(void*, void*, double);
typedef void (*SetCustFn)(void*, void*, void*, void*);

void apply_win(int score) {
    auto get_inst = (GetInstFn)(IL2::base + O::GameController_get_Instance);
    auto get_room = (GetRoomFn)(IL2::base + O::PhotonNetwork_GetRoom);
    auto set_score = (SetScoreFn)(IL2::base + O::Room_SetScore);
    auto set_round = (SetRoundFn)(IL2::base + O::Room_SetRound);
    auto set_rc    = (SetRcFn)(IL2::base + O::Room_SetRoundsCount);
    auto set_time  = (SetTimeFn)(IL2::base + O::Room_SetTime);
    auto set_cust  = (SetCustFn)(IL2::base + O::Room_SetCustomProperties);

    void* gc = get_inst(nullptr);
    if (!gc) return;
    void* lpc = *(void**)((uintptr_t)gc + O::GameController_PlayerController);
    if (!lpc) return;
    int my_team = *(uint8_t*)((uintptr_t)lpc + O::PC_Team);
    int enemy = (my_team == 1) ? 2 : 1;

    void* room = get_room(nullptr);
    if (!room) return;
    void* props = *(void**)((uintptr_t)room + O::RoomInfo_CustomProperties);
    if (!props) return;

    set_score(nullptr, props, my_team, score);
    set_score(nullptr, props, enemy, 0);
    set_round(nullptr, props, score);
    set_rc   (nullptr, props, score);
    set_time (nullptr, props, 0.0);
    set_cust (room, props, nullptr, nullptr);
    LOG("AutoWin applied: %d:0", score);
}

bool g_menu = false;
int g_score = 8;

typedef EGLBoolean (*SwapFn)(EGLDisplay, EGLSurface);
SwapFn g_orig_swap = nullptr;
bool g_imgui_ready = false;

EGLBoolean hk_swap(EGLDisplay d, EGLSurface s) {
    if (!g_imgui_ready) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::GetIO().IniFilename = nullptr;
        ImGui::StyleColorsDark();
        ImGui_ImplOpenGL3_Init("#version 300 es");
        ImGui_ImplAndroid_Init(nullptr);
        g_imgui_ready = true;
        LOG("ImGui Ready");
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();
    ImGui::NewFrame();

    if (g_menu) {
        ImGui::SetNextWindowSize(ImVec2(300, 150), ImGuiCond_FirstUseEver);
        ImGui::Begin("by.x1dead", nullptr, ImGuiWindowFlags_NoCollapse);
        
        ImGui::Text("StandRise AutoWin");
        ImGui::Separator();
        ImGui::SliderInt("Score", &g_score, 1, 16);
        if (ImGui::Button("WIN NOW", ImVec2(280, 50))) {
            apply_win(g_score);
        }
        ImGui::End();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return g_orig_swap ? g_orig_swap(d, s) : EGL_FALSE;
}

extern "C" int32_t input_cb(AInputEvent* ev, void*) {
    if (AInputEvent_getType(ev) != AINPUT_EVENT_TYPE_MOTION) return 0;
    int32_t a = AMotionEvent_getAction(ev);
    int32_t action = a & AMOTION_EVENT_ACTION_MASK;
    if (action == AMOTION_EVENT_ACTION_POINTER_DOWN && AMotionEvent_getPointerCount(ev) >= 3) {
        g_menu = !g_menu;
    }
    return 0;
}

// Встроенный хук для arm64 (замена Dobby)
void inline_hook(void* target, void* replace, void** origin) {
    if (!target) return;
    uintptr_t page_size = sysconf(_SC_PAGESIZE);
    uintptr_t page_start = (uintptr_t)target & ~(page_size - 1);
    if (mprotect((void*)page_start, page_size * 2, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) return;

    uint32_t* p = (uint32_t*)target;
    *origin = (void*)((uintptr_t)target + 16);

    // ARM64: LDR X16, #8 ; BR X16 ; .quad replace
    p[0] = 0x58000050; 
    p[1] = 0xD61F0200;
    
    // ИСПРАВЛЕНО ЗДЕСЬ: добавлено (uintptr_t)
    *(uint64_t*)((uintptr_t)target + 8) = (uint64_t)replace;
}

__attribute__((constructor))
void init() {
    LOG("libx1dead loading...");
    for (int i = 0; i < 100; ++i) {
        if (dlopen("libil2cpp.so", RTLD_NOW | RTLD_NOLOAD)) break;
        usleep(50000);
    }
    IL2::init();
    
    void* h = dlopen("libEGL.so", RTLD_NOW);
    if (h) {
        void* target = dlsym(h, "eglSwapBuffers");
        if (target) {
            inline_hook(target, (void*)hk_swap, (void**)&g_orig_swap);
            LOG("Hook installed at %p", target);
        }
    }
    LOG("libx1dead ready!");
}
