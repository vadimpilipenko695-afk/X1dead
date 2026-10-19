LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := x1dead
LOCAL_SRC_FILES := main.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_CPPFLAGS   := -std=c++20 -O2
LOCAL_LDLIBS     := -llog -landroid -ldl
include $(BUILD_SHARED_LIBRARY)
