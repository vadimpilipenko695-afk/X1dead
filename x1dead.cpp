#include <jni.h>
#include <android/log.h>
#include <dlfcn.h>
#include <link.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pthread.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>

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

void* watch_thread(void*) {
    while (true) {
        if (access("/data/local/tmp/win_trigger", F_OK) != -1) {
            LOG("Trigger detected! Applying win...");
            apply_win(8);
            unlink("/data/local/tmp/win_trigger"); // Удаляем файл
        }
        sleep(1);
    }
    return nullptr;
}

__attribute__((constructor))
void init() {
    LOG("libx1dead loaded (no imgui)!");
    
    // Ждем загрузки игры
    for (int i = 0; i < 20; ++i) {
        if (dlopen("libil2cpp.so", RTLD_NOW | RTLD_NOLOAD)) break;
        sleep(1);
    }
    
    if (IL2::init()) {
        LOG("il2cpp found. Starting watcher thread.");
        pthread_t t;
        pthread_create(&t, nullptr, watch_thread, nullptr);
        pthread_detach(t);
    }
}
