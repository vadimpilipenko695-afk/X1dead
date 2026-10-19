#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/mman.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "x1dead", __VA_ARGS__)

#define O_GameController_get_Instance 0x123C37C
#define O_GameController_PlayerController 0x200
#define O_PC_Team 0x49
#define O_PhotonNetwork_GetRoom 0x18D80F0
#define O_RoomInfo_CustomProperties 0x18
#define O_Room_SetTime 0x136F67C
#define O_Room_SetRound 0x136F798
#define O_Room_SetScore 0x1370124
#define O_Room_SetRoundsCount 0x13712A0
#define O_Room_SetCustomProperties 0x1570F1C

uintptr_t base = 0;

typedef void* (*GetInstFn)(void*);
typedef void* (*GetRoomFn)(void*);
typedef void (*SetScoreFn)(void*, void*, int, int);
typedef void (*SetRoundFn)(void*, void*, int);
typedef void (*SetRcFn)(void*, void*, int);
typedef void (*SetTimeFn)(void*, void*, double);
typedef void (*SetCustFn)(void*, void*, void*, void*);

void apply_win(int score) {
    if (!base) return;
    auto get_inst = (GetInstFn)(base + O_GameController_get_Instance);
    auto get_room = (GetRoomFn)(base + O_PhotonNetwork_GetRoom);
    auto set_score = (SetScoreFn)(base + O_Room_SetScore);
    auto set_round = (SetRoundFn)(base + O_Room_SetRound);
    auto set_rc    = (SetRcFn)(base + O_Room_SetRoundsCount);
    auto set_time  = (SetTimeFn)(base + O_Room_SetTime);
    auto set_cust  = (SetCustFn)(base + O_Room_SetCustomProperties);

    void* gc = get_inst(nullptr);
    if (!gc) return;
    void* lpc = *(void**)((uintptr_t)gc + O_GameController_PlayerController);
    if (!lpc) return;
    
    int my_team = *(uint8_t*)((uintptr_t)lpc + O_PC_Team);
    int enemy = (my_team == 1) ? 2 : 1;

    void* room = get_room(nullptr);
    if (!room) return;
    void* props = *(void**)((uintptr_t)room + O_RoomInfo_CustomProperties);
    if (!props) return;

    set_score(nullptr, props, my_team, score);
    set_score(nullptr, props, enemy, 0);
    set_round(nullptr, props, score);
    set_rc   (nullptr, props, score);
    set_time (nullptr, props, 0.0);
    set_cust (room, props, nullptr, nullptr);
    LOG("AutoWin applied: %d:0", score);
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

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOG("JNI_OnLoad called!");
    
    base = (uintptr_t)dlopen("libil2cpp.so", RTLD_LAZY | RTLD_NOLOAD);
    
    if (base) {
        LOG("il2cpp found! Waiting 15 sec for lobby...");
        sleep(15); // Ждем, пока игра прогрузится и ты попадешь в лобби
        apply_win(8); // ЕБАШИМ АВТО-ВИН АВТОМАТИЧЕСКИ
    }
    
    return JNI_VERSION_1_6;
}
