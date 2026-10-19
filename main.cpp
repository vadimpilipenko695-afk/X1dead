#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <dlfcn.h>
#include <pthread.h>
#include <string>
#include "dobby.h"  // <--- ВОТ ЭТА СТРОЧКА

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "x1dead", __VA_ARGS__)
// ... дальше идет остальной код ...
