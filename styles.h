#pragma once
#include "imgui.h"

void initBlueTheme() {
    ImGui::StyleColorsDark();
    
    const ImVec4 main_blue(0.00f, 0.50f, 0.80f, 1.00f);
    const ImVec4 blue_hover(0.00f, 0.60f, 1.00f, 1.00f);
    const ImVec4 blue_active(0.00f, 0.40f, 0.70f, 1.00f);
    const ImVec4 bg_dark(0.08f, 0.08f, 0.10f, 1.00f);
    const ImVec4 bg_mid(0.12f, 0.12f, 0.15f, 1.00f);

    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = bg_dark;
    colors[ImGuiCol_ChildBg] = bg_mid;
    colors[ImGuiCol_PopupBg] = bg_dark;
    colors[ImGuiCol_MenuBarBg] = bg_mid;

    colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.35f, 0.50f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = main_blue;
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.25f, 0.40f, 0.60f);

    colors[ImGuiCol_Button] = ImVec4(main_blue.x, main_blue.y, main_blue.z, 0.30f);
    colors[ImGuiCol_ButtonHovered] = blue_hover;
    colors[ImGuiCol_ButtonActive] = blue_active;
    colors[ImGuiCol_Header] = main_blue;
    colors[ImGuiCol_HeaderHovered] = blue_hover;
    colors[ImGuiCol_HeaderActive] = blue_active;
    colors[ImGuiCol_Tab] = bg_mid;
    colors[ImGuiCol_TabHovered] = blue_hover;
    colors[ImGuiCol_TabActive] = main_blue;
    colors[ImGuiCol_TabUnfocused] = bg_mid;

    colors[ImGuiCol_SliderGrab] = main_blue;
    colors[ImGuiCol_SliderGrabActive] = blue_active;
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.25f, 0.60f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.70f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.78f, 1.00f, 1.00f);

    colors[ImGuiCol_Border] = ImVec4(0.15f, 0.15f, 0.20f, 0.88f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
    style.FrameBorderSize = 1.0f;

    colors[ImGuiCol_ScrollbarBg] = bg_mid;
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = blue_hover;
    colors[ImGuiCol_ScrollbarGrabActive] = blue_active;

    colors[ImGuiCol_NavHighlight] = blue_hover;
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
    colors[ImGuiCol_PlotLines] = main_blue;
    colors[ImGuiCol_PlotHistogram] = main_blue;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.TabRounding = 5.0f;
    style.LogSliderDeadzone = 5.0f;

    style.DisplayWindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

void initGreenTheme() {
    ImGui::StyleColorsDark();
    
    const ImVec4 main_green(0.00f, 0.50f, 0.00f, 1.00f);
    const ImVec4 green_hover(0.00f, 0.60f, 0.00f, 1.00f);
    const ImVec4 green_active(0.00f, 0.40f, 0.00f, 1.00f);
    const ImVec4 bg_dark(0.08f, 0.08f, 0.10f, 1.00f);
    const ImVec4 bg_mid(0.12f, 0.12f, 0.15f, 1.00f);

    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = bg_dark;
    colors[ImGuiCol_ChildBg] = bg_mid;
    colors[ImGuiCol_PopupBg] = bg_dark;
    colors[ImGuiCol_MenuBarBg] = bg_mid;

    colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.35f, 0.00f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = main_green;
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.25f, 0.00f, 0.60f);

    colors[ImGuiCol_Button] = ImVec4(main_green.x, main_green.y, main_green.z, 0.30f);
    colors[ImGuiCol_ButtonHovered] = green_hover;
    colors[ImGuiCol_ButtonActive] = green_active;
    colors[ImGuiCol_Header] = main_green;
    colors[ImGuiCol_HeaderHovered] = green_hover;
    colors[ImGuiCol_HeaderActive] = green_active;
    colors[ImGuiCol_Tab] = bg_mid;
    colors[ImGuiCol_TabHovered] = green_hover;
    colors[ImGuiCol_TabActive] = main_green;
    colors[ImGuiCol_TabUnfocused] = bg_mid;

    colors[ImGuiCol_SliderGrab] = main_green;
    colors[ImGuiCol_SliderGrabActive] = green_active;
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.25f, 0.60f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.70f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.78f, 0.00f, 1.00f);

    colors[ImGuiCol_Border] = ImVec4(0.15f, 0.15f, 0.20f, 0.88f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
    style.FrameBorderSize = 1.0f;

    colors[ImGuiCol_ScrollbarBg] = bg_mid;
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = green_hover;
    colors[ImGuiCol_ScrollbarGrabActive] = green_active;

    colors[ImGuiCol_NavHighlight] = green_hover;
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
    colors[ImGuiCol_PlotLines] = main_green;
    colors[ImGuiCol_PlotHistogram] = main_green;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.TabRounding = 5.0f;
    style.LogSliderDeadzone = 5.0f;

    style.DisplayWindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

void initRedTheme() {
    ImGui::StyleColorsDark();
    
    const ImVec4 main_red(0.80f, 0.00f, 0.00f, 1.00f);
    const ImVec4 red_hover(1.00f, 0.00f, 0.00f, 1.00f);
    const ImVec4 red_active(0.60f, 0.00f, 0.00f, 1.00f);
    const ImVec4 bg_dark(0.08f, 0.08f, 0.10f, 1.00f);
    const ImVec4 bg_mid(0.12f, 0.12f, 0.15f, 1.00f);

    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = bg_dark;
    colors[ImGuiCol_ChildBg] = bg_mid;
    colors[ImGuiCol_PopupBg] = bg_dark;
    colors[ImGuiCol_MenuBarBg] = bg_mid;

    colors[ImGuiCol_TitleBg] = ImVec4(0.70f, 0.00f, 0.00f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = main_red;
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.50f, 0.00f, 0.00f, 0.60f);

    colors[ImGuiCol_Button] = ImVec4(main_red.x, main_red.y, main_red.z, 0.30f);
    colors[ImGuiCol_ButtonHovered] = red_hover;
    colors[ImGuiCol_ButtonActive] = red_active;
    colors[ImGuiCol_Header] = main_red;
    colors[ImGuiCol_HeaderHovered] = red_hover;
    colors[ImGuiCol_HeaderActive] = red_active;
    colors[ImGuiCol_Tab] = bg_mid;
    colors[ImGuiCol_TabHovered] = red_hover;
    colors[ImGuiCol_TabActive] = main_red;
    colors[ImGuiCol_TabUnfocused] = bg_mid;

    colors[ImGuiCol_SliderGrab] = main_red;
    colors[ImGuiCol_SliderGrabActive] = red_active;
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.25f, 0.60f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.70f);
    colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);

    colors[ImGuiCol_Border] = ImVec4(0.15f, 0.15f, 0.20f, 0.88f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
    style.FrameBorderSize = 1.0f;

    colors[ImGuiCol_ScrollbarBg] = bg_mid;
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = red_hover;
    colors[ImGuiCol_ScrollbarGrabActive] = red_active;

    colors[ImGuiCol_NavHighlight] = red_hover;
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
    colors[ImGuiCol_PlotLines] = main_red;
    colors[ImGuiCol_PlotHistogram] = main_red;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.TabRounding = 5.0f;
    style.LogSliderDeadzone = 5.0f;

    style.DisplayWindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

void initYellowTheme() {
    ImGui::StyleColorsDark();
    
    const ImVec4 main_yellow(0.90f, 0.80f, 0.00f, 1.00f);
    const ImVec4 yellow_hover(1.00f, 0.90f, 0.00f, 1.00f);
    const ImVec4 yellow_active(0.80f, 0.70f, 0.00f, 1.00f);
    const ImVec4 bg_dark(0.08f, 0.08f, 0.10f, 1.00f);
    const ImVec4 bg_mid(0.12f, 0.12f, 0.15f, 1.00f);

    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = bg_dark;
    colors[ImGuiCol_ChildBg] = bg_mid;
    colors[ImGuiCol_PopupBg] = bg_dark;
    colors[ImGuiCol_MenuBarBg] = bg_mid;

    colors[ImGuiCol_TitleBg] = ImVec4(0.70f, 0.60f, 0.00f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = main_yellow;
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.50f, 0.45f, 0.00f, 0.60f);

    colors[ImGuiCol_Button] = ImVec4(main_yellow.x, main_yellow.y, main_yellow.z, 0.30f);
    colors[ImGuiCol_ButtonHovered] = yellow_hover;
    colors[ImGuiCol_ButtonActive] = yellow_active;
    colors[ImGuiCol_Header] = main_yellow;
    colors[ImGuiCol_HeaderHovered] = yellow_hover;
    colors[ImGuiCol_HeaderActive] = yellow_active;
    colors[ImGuiCol_Tab] = bg_mid;
    colors[ImGuiCol_TabHovered] = yellow_hover;
    colors[ImGuiCol_TabActive] = main_yellow;
    colors[ImGuiCol_TabUnfocused] = bg_mid;

    colors[ImGuiCol_SliderGrab] = main_yellow;
    colors[ImGuiCol_SliderGrabActive] = yellow_active;
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.25f, 0.60f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.70f);
    colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.90f, 0.00f, 1.00f);

    colors[ImGuiCol_Border] = ImVec4(0.15f, 0.15f, 0.20f, 0.88f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
    style.FrameBorderSize = 1.0f;

    colors[ImGuiCol_ScrollbarBg] = bg_mid;
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = yellow_hover;
    colors[ImGuiCol_ScrollbarGrabActive] = yellow_active;

    colors[ImGuiCol_NavHighlight] = yellow_hover;
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
    colors[ImGuiCol_PlotLines] = main_yellow;
    colors[ImGuiCol_PlotHistogram] = main_yellow;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.TabRounding = 5.0f;
    style.LogSliderDeadzone = 5.0f;

    style.DisplayWindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

void initPinkTheme() {
    ImGui::StyleColorsDark();
    
    const ImVec4 main_pink(1.00f, 0.41f, 0.71f, 1.00f);
    const ImVec4 pink_hover(1.00f, 0.50f, 0.80f, 1.00f);
    const ImVec4 pink_active(0.90f, 0.35f, 0.65f, 1.00f);
    const ImVec4 bg_dark(0.08f, 0.08f, 0.10f, 1.00f);
    const ImVec4 bg_mid(0.12f, 0.12f, 0.15f, 1.00f);

    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = bg_dark;
    colors[ImGuiCol_ChildBg] = bg_mid;
    colors[ImGuiCol_PopupBg] = bg_dark;
    colors[ImGuiCol_MenuBarBg] = bg_mid;

    colors[ImGuiCol_TitleBg] = ImVec4(0.80f, 0.30f, 0.60f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = main_pink;
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.70f, 0.25f, 0.55f, 0.60f);

    colors[ImGuiCol_Button] = ImVec4(main_pink.x, main_pink.y, main_pink.z, 0.30f);
    colors[ImGuiCol_ButtonHovered] = pink_hover;
    colors[ImGuiCol_ButtonActive] = pink_active;
    colors[ImGuiCol_Header] = main_pink;
    colors[ImGuiCol_HeaderHovered] = pink_hover;
    colors[ImGuiCol_HeaderActive] = pink_active;
    colors[ImGuiCol_Tab] = bg_mid;
    colors[ImGuiCol_TabHovered] = pink_hover;
    colors[ImGuiCol_TabActive] = main_pink;
    colors[ImGuiCol_TabUnfocused] = bg_mid;

    colors[ImGuiCol_SliderGrab] = main_pink;
    colors[ImGuiCol_SliderGrabActive] = pink_active;
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.25f, 0.60f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.70f);
    colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.55f, 0.80f, 1.00f);

    colors[ImGuiCol_Border] = ImVec4(0.15f, 0.15f, 0.20f, 0.88f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
    style.FrameBorderSize = 1.0f;

    colors[ImGuiCol_ScrollbarBg] = bg_mid;
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = pink_hover;
    colors[ImGuiCol_ScrollbarGrabActive] = pink_active;

    colors[ImGuiCol_NavHighlight] = pink_hover;
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
    colors[ImGuiCol_PlotLines] = main_pink;
    colors[ImGuiCol_PlotHistogram] = main_pink;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.TabRounding = 5.0f;
    style.LogSliderDeadzone = 5.0f;

    style.DisplayWindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

void initWhiteTheme() {
    ImGui::StyleColorsDark();
    
    const ImVec4 main_white(1.00f, 1.00f, 1.00f, 1.00f);
    const ImVec4 white_hover(0.90f, 0.90f, 0.90f, 1.00f);
    const ImVec4 white_active(0.80f, 0.80f, 0.80f, 1.00f);
    const ImVec4 bg_dark(0.08f, 0.08f, 0.10f, 1.00f);
    const ImVec4 bg_mid(0.12f, 0.12f, 0.15f, 1.00f);

    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;

    // Исправлен цвет текста и прозрачность элементов
    colors[ImGuiCol_Text] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f); // Темный текст
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = bg_dark;
    colors[ImGuiCol_ChildBg] = bg_mid;
    colors[ImGuiCol_PopupBg] = bg_dark;
    colors[ImGuiCol_MenuBarBg] = bg_mid;

    colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = main_white;
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.15f, 0.15f, 0.15f, 0.60f);

    // Увеличена прозрачность кнопок
    colors[ImGuiCol_Button] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
    colors[ImGuiCol_ButtonHovered] = white_hover;
    colors[ImGuiCol_ButtonActive] = white_active;
    
    // Исправленные цвета для контраста
    colors[ImGuiCol_Header] = ImVec4(1.00f, 1.00f, 1.00f, 0.20f);
    colors[ImGuiCol_HeaderHovered] = white_hover;
    colors[ImGuiCol_HeaderActive] = white_active;
    
    colors[ImGuiCol_Tab] = bg_mid;
    colors[ImGuiCol_TabHovered] = white_hover;
    colors[ImGuiCol_TabActive] = main_white;
    colors[ImGuiCol_TabUnfocused] = bg_mid;

    colors[ImGuiCol_SliderGrab] = main_white;
    colors[ImGuiCol_SliderGrabActive] = white_active;
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.25f, 0.60f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.70f);
    colors[ImGuiCol_CheckMark] = main_white;

    colors[ImGuiCol_Border] = ImVec4(0.15f, 0.15f, 0.20f, 0.88f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
    style.FrameBorderSize = 1.0f;

    colors[ImGuiCol_ScrollbarBg] = bg_mid;
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = white_hover;
    colors[ImGuiCol_ScrollbarGrabActive] = white_active;

    colors[ImGuiCol_NavHighlight] = white_hover;
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
    colors[ImGuiCol_PlotLines] = main_white;
    colors[ImGuiCol_PlotHistogram] = main_white;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.TabRounding = 5.0f;
    style.LogSliderDeadzone = 5.0f;

    style.DisplayWindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

void initGreyTheme() {
    ImGui::StyleColorsDark();
    
    const ImVec4 main_gray(0.50f, 0.50f, 0.50f, 1.00f);
    const ImVec4 gray_hover(0.60f, 0.60f, 0.60f, 1.00f);
    const ImVec4 gray_active(0.40f, 0.40f, 0.40f, 1.00f);
    const ImVec4 bg_dark(0.08f, 0.08f, 0.10f, 1.00f);
    const ImVec4 bg_mid(0.12f, 0.12f, 0.15f, 1.00f);

    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = bg_dark;
    colors[ImGuiCol_ChildBg] = bg_mid;
    colors[ImGuiCol_PopupBg] = bg_dark;
    colors[ImGuiCol_MenuBarBg] = bg_mid;

    colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = main_gray;
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.15f, 0.15f, 0.15f, 0.60f);

    colors[ImGuiCol_Button] = ImVec4(main_gray.x, main_gray.y, main_gray.z, 0.30f);
    colors[ImGuiCol_ButtonHovered] = gray_hover;
    colors[ImGuiCol_ButtonActive] = gray_active;
    colors[ImGuiCol_Header] = main_gray;
    colors[ImGuiCol_HeaderHovered] = gray_hover;
    colors[ImGuiCol_HeaderActive] = gray_active;
    colors[ImGuiCol_Tab] = bg_mid;
    colors[ImGuiCol_TabHovered] = gray_hover;
    colors[ImGuiCol_TabActive] = main_gray;
    colors[ImGuiCol_TabUnfocused] = bg_mid;

    colors[ImGuiCol_SliderGrab] = main_gray;
    colors[ImGuiCol_SliderGrabActive] = gray_active;
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.25f, 0.60f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.70f);
    colors[ImGuiCol_CheckMark] = main_gray;

    colors[ImGuiCol_Border] = ImVec4(0.15f, 0.15f, 0.20f, 0.88f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
    style.FrameBorderSize = 1.0f;

    colors[ImGuiCol_ScrollbarBg] = bg_mid;
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = gray_hover;
    colors[ImGuiCol_ScrollbarGrabActive] = gray_active;

    colors[ImGuiCol_NavHighlight] = gray_hover;
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
    colors[ImGuiCol_PlotLines] = main_gray;
    colors[ImGuiCol_PlotHistogram] = main_gray;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.TabRounding = 5.0f;
    style.LogSliderDeadzone = 5.0f;

    style.DisplayWindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}
