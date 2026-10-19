LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := dobby
LOCAL_SRC_FILES := libraries/$(TARGET_ARCH_ABI)/libdobby.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := x1dead
LOCAL_SRC_FILES := main.cpp \
    ImGui/imgui.cpp ImGui/imgui_draw.cpp ImGui/imgui_tables.cpp ImGui/imgui_widgets.cpp \
    ImGui/backends/imgui_impl_opengl3.cpp ImGui/backends/imgui_impl_android.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/ImGui $(LOCAL_PATH)/Includes $(LOCAL_PATH)/KittyMemory
LOCAL_CPPFLAGS   := -std=c++20 -O2 -fvisibility=hidden
LOCAL_LDLIBS     := -llog -landroid -lEGL -lGLESv3 -ldl
LOCAL_STATIC_LIBRARIES := dobby
include $(BUILD_SHARED_LIBRARY)
