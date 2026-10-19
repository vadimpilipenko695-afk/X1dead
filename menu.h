    // Три кнопки сверху (Visuals, Rage, Settings)
    if (ImGui::Button(OBFUSCATE("Visuals"), ImVec2(200, 70))) {
        visual_page = true;
        functions_page = false;
        settings_page = false;
    }
    ImGui::SameLine();
    if (ImGui::Button(OBFUSCATE("Rage"), ImVec2(200, 70))) {
        visual_page = false;
        functions_page = true;
        settings_page = false;
    }
    ImGui::SameLine();
    if (ImGui::Button(OBFUSCATE("Settings"), ImVec2(200, 70))) {
        visual_page = false;
        functions_page = false;
        settings_page = true;
    }

    ImGui::BeginChild(OBFUSCATE("##content"), ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_AlwaysVerticalScrollbar);
    {
        if (visual_page) {
            // ... (тут оставляешь код ВХ (Чамсов) от ZEFF, не трогай его)
            ImGui::Spacing();
            ImGui::Indent(10.0f);
            ImGui::Text(OBFUSCATE("Visuals Settings:"));
            ImGui::Unindent(10.0f);
            ImGui::Separator();
            ImGui::Indent(10.0f);

            ImGui::PushItemWidth(500);
            ImGui::Combo(OBFUSCATE("Current Chams"), &chamsint, Chams, IM_ARRAYSIZE(Chams));
            // ... и так далее
        }
        else if (functions_page) {
            ImGui::Spacing();
            ImGui::Indent(10.0f);
            ImGui::Text(OBFUSCATE("Rage Features:"));
            ImGui::Unindent(10.0f);
            ImGui::Separator();
            ImGui::Indent(10.0f);

            // НАШИ ФИЧИ
            ImGui::Checkbox(OBFUSCATE("Aimbot (Silent)"), &aimbot_enabled);
            ImGui::Checkbox(OBFUSCATE("No Recoil"), &no_recoil_enabled);
            ImGui::Checkbox(OBFUSCATE("Auto Win (8:0)"), &autowin_enabled);
            
            ImGui::Unindent(10.0f);
        }
        else if (settings_page) {
            // ... (тут оставляешь настройки ZEFF)
        }
    }
    ImGui::EndChild();
