#pragma once
#include "draw.h"
#include "global.h"


void update_keybind() {
    if (GetAsyncKeyState(VK_INSERT) & 1) {
        vars::is_open = !vars::is_open;
    }
}

void update_menu(UCanvas* canvas) {
    ZeroGUI::SetupCanvas(canvas);

    ZeroGUI::Input::Handle();

    if (ZeroGUI::Window(L"Sbaggy Internal Base", &vars::pos, { 600.f, 600.f }, vars::is_open)) {
        if (ZeroGUI::ButtonTab(L"Aimbot", FVector2D{ 198.f, 30.f }, vars::current_tab == 0))
            vars::current_tab = 0;
        ZeroGUI::SameLine();
        if (ZeroGUI::ButtonTab(L"Visual", FVector2D{ 198.f, 30.f }, vars::current_tab == 1))
            vars::current_tab = 1;
        ZeroGUI::SameLine();
        if (ZeroGUI::ButtonTab(L"Exploits", FVector2D{ 198.f, 30.f }, vars::current_tab == 2))
            vars::current_tab = 2;

        switch (vars::current_tab) {
        case 0:
            ZeroGUI::Checkbox(L"Enable Aimbot", &vars::aimbot);
            break;
        case 1:
            ZeroGUI::Checkbox(L"Enable Skeletons", &vars::skeleton);
            ZeroGUI::Checkbox(L"Enable Box", &vars::box);
            ZeroGUI::Checkbox(L"Enable Name", &vars::name);
            break;
        case 2:
            ZeroGUI::Checkbox(L"Fov changer", &vars::fov_changer);
            ZeroGUI::SliderFloat(L"Fov Value", &vars::fov_value, 0, 200);
            ZeroGUI::Checkbox(L"Name Spoofing", &vars::name_spoofing);
            ZeroGUI::Checkbox(L"Speed Hack", &vars::speed_hack);
            ZeroGUI::SliderFloat(L"Max Acceleration", &vars::maxmovement, 100, 10000);
            ZeroGUI::SliderFloat(L"Max Walk Speed", &vars::maxspeedwalk, 100, 10000);
            ZeroGUI::Checkbox(L"Fly Hack", &vars::fly_hack);
            ZeroGUI::SliderFloat(L"Fly Hack Speed", &vars::flyhack_speed, 0, 200);
            ZeroGUI::Checkbox(L"Teleport To Player", &vars::tp_to_player);
            ZeroGUI::Checkbox(L"SpinBot", &vars::spinbot);
            break;
        }
        
       
    }

    ZeroGUI::Draw_Cursor(is_open);

    ZeroGUI::Render();
}