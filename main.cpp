#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <dlfcn.h>
#include <pthread.h>
#include <string>

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
#define O_Weapon_CastBullet 0x13E5318

uintptr_t base = 0;
bool enable_aimbot = false;

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

typedef void (*CastBulletFn)(void*, void*, void*, void*);
CastBulletFn orig_CastBullet;

void hk_CastBullet(void* self, void* pos, void* dir, void* params) {
    if (enable_aimbot) {
        LOG("Aimbot: Shot intercepted!");
    }
    orig_CastBullet(self, pos, dir, params);
}

void* hack_thread(void*) {
    LOG("Waiting for libil2cpp.so...");
    do {
        base = (uintptr_t)dlopen("libil2cpp.so", RTLD_LAZY | RTLD_NOLOAD);
        sleep(1);
    } while (!base);

    LOG("il2cpp found at %p! Hooking...", (void*)base);
    void* target = (void*)(base + O_Weapon_CastBullet);
    DobbyHook(target, (void*)hk_CastBullet, (void**)&orig_CastBullet);
    
    return nullptr;
}

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    pthread_t t;
    pthread_create(&t, NULL, hack_thread, NULL);
    pthread_detach(t);
    return JNI_VERSION_1_6;
}

// Вместо ImGui просто будем вызывать функции по команде из скрипта
extern "C" JNIEXPORT void JNICALL
Java_com_mycompany_application_GLES3JNIView_step(JNIEnv* env, jobject obj) {
    // Ничего не рисуем, просто проверяем триггер
    if (access("/data/local/tmp/win_trigger", F_OK) != -1) {
        apply_win(8);
        unlink("/data/local/tmp/win_trigger");
    }
}
