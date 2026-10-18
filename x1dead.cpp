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
    constexpr uintptr_t PlayerController_Update = 0x15B1994;
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
bool g_imgui_ready = false;

typedef EGLBoolean (*SwapFn)(EGLDisplay, EGLSurface);
SwapFn g_orig_swap = nullptr;

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

    ImGui::SetNextWindowPos(ImVec2(20, 200), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(60, 60), ImGuiCond_Always);
    ImGui::Begin("##btn", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
    if (ImGui::Button("X1", ImVec2(60, 60))) {
        g_menu = !g_menu;
    }
    ImGui::End();

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

void inline_hook(void* target, void* replace, void** origin) {
    if (!target) return;
    uintptr_t page_size = sysconf(_SC_PAGESIZE);
    uintptr_t page_start = (uintptr_t)target & ~(page_size - 1);
    if (mprotect((void*)page_start, page_size * 2, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) return;

    uint8_t* orig_code = (uint8_t*)malloc(16);
    memcpy(orig_code, target, 16);
    *origin = (void*)orig_code;

    uint32_t* p = (uint32_t*)target;
    p[0] = 0x58000050; 
    p[1] = 0xD61F0200;
    *(uint64_t*)((uintptr_t)target + 8) = (uint64_t)replace;
    __builtin___clear_cache((char*)target, (char*)target + 16);
}

typedef void (*UpdateFn)(void*, void*);
UpdateFn orig_update = nullptr;

void hk_update(void* self, void* method) {
    if (orig_update) orig_update(self, method);
    
    static bool hooked_swap = false;
    if (!hooked_swap) {
        void* h = dlopen("libEGL.so", RTLD_NOW | RTLD_NOLOAD);
        if (h) {
            void* swap = dlsym(h, "eglSwapBuffers");
            if (swap) {
                inline_hook(swap, (void*)hk_swap, (void**)&g_orig_swap);
                hooked_swap = true;
                LOG("EGL hooked from Update!");
            }
        }
    }
}

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOG("JNI_OnLoad called!");
    if (IL2::init()) {
        void* target = IL2::at(O::PlayerController_Update);
        inline_hook(target, (void*)hk_update, (void**)&orig_update);
        LOG("Update Hook installed!");
    }
    return JNI_VERSION_1_6;
}
