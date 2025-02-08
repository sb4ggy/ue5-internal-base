#include <Windows.h>
#include <vector>
#include <Psapi.h>
#include <iostream>
#include <thread>
#include <future>
#include "utils/draw.h"
#include "minhook/minhook.h"
#include <random>
#include <string>
#include "utils/hk.h"
#include "utils/menu.h"

FRotator spin;

std::wstring gen_random_name() {
    const std::wstring chars = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::wstring randomName;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    for (int i = 0; i < 8; ++i) {
        randomName += chars[dist(gen)];
    }
    return randomName;
}

void post_render_hook(UGameViewportClient* viewport_client, UCanvas* canvas) {

    static std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();
    static std::wstring currentName;
    const auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate).count() >= 5) {
        currentName = gen_random_name();
        lastUpdate = now;
    }

    RenderText(canvas, { 15.f, 15.f }, "UE5 Base Internal By Sbaggy", { 1.f, 0.f, 1.f, 1.f });

    auto world = viewport_client->World;

    auto game_instance = viewport_client->GameInstance;

    if (!game_instance->LocalPlayers.Objects[0]) return;

    auto local_player = game_instance->LocalPlayers.Objects[0];
    
    if (!local_player) return;

    auto controller = local_player->PlayerController;

    if (!controller) return;

    auto camera = controller->PlayerCameraManager;

    if (!camera) return;

    if (controller->Character) {
        auto comp = controller->Character->CharacterMovement;
        if (vars::fly_hack) {
            comp->MovementMode = EMovementMode::MOVE_Flying;

            FVector sum;
            FRotator NewRot;
            float fly_speed = vars::flyhack_speed;

            auto rot = camera->GetCameraRotation();

            if (GetAsyncKeyState(VK_SHIFT))
                fly_speed *= 1.5f;
            else if (GetAsyncKeyState('W'))
                sum += GetVectorForward(rot) * fly_speed;
            else if (GetAsyncKeyState('S')) {
                NewRot = {
                -rot.x,
                rot.y + 180.f,
                0.0f
                };

                sum += GetVectorForward(NewRot) * fly_speed;
            }
            else if (GetAsyncKeyState('D')) {
                NewRot = {
                0.0f,
                rot.y + 90.f,
                0.0f
                };
                sum += GetVectorForward(NewRot) * fly_speed;
            }
            else if (GetAsyncKeyState('A')) {
                NewRot = {
                0.0f,
                rot.y + 270.f,
                0.0f
                };
                sum += GetVectorForward(NewRot) * fly_speed;
            }
            controller->Character->RootComponent->RelativeLocation += sum;
        }
        if (vars::speed_hack) {
            comp->MaxWalkSpeed = vars::maxspeedwalk;
            comp->MaxAcceleration = vars::maxmovement;
            controller->bCanBeDamaged = false;
            controller->bHidden = true;
        }
    }

    const auto my_player = controller->AcknowledgedPawn;

    if (!my_player) return;

    auto camera_location = camera->GetCameraLocation();

    auto camera_rotation = camera->GetCameraRotation();

    float closest_player_dist = FLT_MAX;

    FRotator closest_player;

    FVector closest_player_head;

    FVector2D closest_player_w2s_res;

    if (controller) {
        controller->FOV(vars::fov_changer ? vars::fov_value : 90);
    }

    if (vars::spinbot) {
        if (GetAsyncKeyState(VK_LBUTTON) < 0)
        {
            my_player->K2_SetActorRotation({ 0, spin.y, 0 }, 0);
            spin.y += 20;
        }
    }

    if (vars::name_spoofing) {
        controller->SetName(currentName.c_str());
      //  controller->ServerChangeName(currentName.c_str());
    }


    update_keybind();
    update_menu(canvas);
    for (int i = 0; i < world->Levels.count; i++) {
        auto level = world->Levels.Objects[i];
        if (level) {
            for (int j = 0; j < level->Actors.count; j++) {
                auto actor = level->Actors.Objects[j]; 
                if (actor && actor->RootComponent && actor->GetName().find("BP_Bullet") != std::string::npos) {
                    actor->K2_SetActorLocation(closest_player_head, false, 0, true);
                }
                if (actor && actor->RootComponent && actor->GetName().find("BP_Character") != std::string::npos) {

                    if (actor == my_player) continue;

                    bool is_visible = controller->LineOfSightTo(actor, { 0.f, 0.f, 0.f }, false);
                    AHumanCharacter* base_class = (AHumanCharacter*)actor;

                    FVector location = base_class->K2_GetActorLocation();
                    FVector BoxExtent;


                    //auto materials = base_class->Mesh->GetMaterials();

                    //for (size_t t = 0; t < materials.count; t++) {
                    //    base_class->Mesh->SetMaterial(t, (UMaterialInterface*)TransparentMaterial_FN);
                    //}


                  //  actor->GetActorBounds(true, location, BoxExtent, false);

                    FVector foot_location = base_class->Mesh->GetSocketLocation(base_class->Mesh->GetBoneName(Bones::Root));
                    FVector head_location = base_class->Mesh->GetSocketLocation(base_class->Mesh->GetBoneName(Bones::Head));

                    FVector2D head_pos, foot_pos;
                      
                    FVector2D BoneScreen, PrevBoneScreen;
                    for (const std::pair<int, int>& Connection : Connections)
                    {
                        const auto Bone1 = Connection.first;
                        const auto Bone2 = Connection.second;
                        const auto BoneLoc1 = base_class->Mesh->GetSocketLocation(base_class->Mesh->GetBoneName(Bone1));
                        const auto BoneLoc2 = base_class->Mesh->GetSocketLocation(base_class->Mesh->GetBoneName(Bone2));
                        if (controller->ProjectWorldLocationToScreen(BoneLoc1, BoneScreen, false) && controller->ProjectWorldLocationToScreen(BoneLoc2, PrevBoneScreen, false))
                        {
                            if (vars::skeleton) {
                                RenderLine(canvas, { BoneScreen.x, BoneScreen.y }, { PrevBoneScreen.x, PrevBoneScreen.y }, 1.f, is_visible ? FLinearColor{ 0.f,1.f,0.f,1.f } : FLinearColor{ 1.f, 0.f, 0.f, 1.f });
                            }
                        }
                    }

                    if (controller->ProjectWorldLocationToScreen(foot_location, foot_pos, false) && controller->ProjectWorldLocationToScreen(head_location, head_pos, false)) {
                        const float h = abs(foot_pos.y - head_pos.y);
                        const float w = h * 0.6f;

                        FVector2D top = { head_pos.x - w * 0.5f, head_pos.y };
                        FVector2D bottom = { head_pos.x + w * 0.5f, foot_pos.y };

                        if (vars::box) {
                            RenderBox(canvas, top, bottom, is_visible ? FLinearColor{ 0.f,1.f,0.f,1.f } : FLinearColor{ 1.f, 0.f, 0.f, 1.f }, 1.f);
                        }

                        if (vars::name) {
                            RenderText(canvas, { head_pos.x, head_pos.y }, base_class->PlayerState->PlayerNamePrivate.is_valid() ? base_class->PlayerState->PlayerNamePrivate.to_string().c_str() : " ", is_visible ? FLinearColor{ 0.f,1.f,0.f,1.f } : FLinearColor{ 1.f, 0.f, 0.f, 1.f });
                        }

                        auto res = ((UKismetMathLibrary*)functions::Class_KismetMathLibrary)->FindLookAtRotation(camera_location, head_location);

                        auto distance = res.Distance2D(camera_rotation);

                        if (distance < closest_player_dist) {
                            closest_player_dist = distance;

                            closest_player = res;

                            closest_player_head = head_location;

                            closest_player_w2s_res = head_pos;
                        }
                    }
                }
            }
        }
    }

    if (closest_player_dist != FLT_MAX && GetAsyncKeyState(VK_XBUTTON1)) {
        if (vars::tp_to_player) {
            my_player->K2_SetActorLocation({ closest_player.x, closest_player.y, my_player->K2_GetActorLocation().z }, false, 0, true);
        }
    }


    if (closest_player_dist != FLT_MAX && GetAsyncKeyState(VK_RBUTTON)) {
        if (vars::aimbot) {
            controller->SetControlRotation(closest_player);
        }

        RenderText(canvas, closest_player_w2s_res, "Closest Player", { 0.f, 1.f, 0.f, 1.f });
    }

    post_render_original(viewport_client, canvas);
}


BYTE* vmt_hook(void** VFTable, uint32_t index, void* TargetFunction) {
    BYTE* org = reinterpret_cast<BYTE*>(VFTable[index]);

    DWORD protect = 0;

    VirtualProtect(&VFTable[index], 8, PAGE_EXECUTE_READWRITE, &protect);

    VFTable[index] = TargetFunction;

    VirtualProtect(&VFTable[index], 8, protect, 0);

    return org;
}

void init() {
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    uint64_t game_base = reinterpret_cast<uint64_t>(GetModuleHandle(NULL));

    UWorld* world = *reinterpret_cast<UWorld**>(game_base + 0x535BE10); // UWorld offset
    NamePool = (FNamePool*)(game_base + 0x51D4D00); // NamePool offset
    ObjectArray = (TUObjectArray*)(game_base + 0x5211050); // ObjectArray offset

    functions::init();

    auto game_instance = world->OwningGameInstance;

    auto local_player = game_instance->LocalPlayers.Objects[0];

    auto viewport_client = local_player->ViewportClient;

    void** VFTable = (void**)viewport_client->vtable;

    post_render_original = reinterpret_cast<decltype(post_render_original)>(vmt_hook(VFTable, post_render_index, &post_render_hook));

    auto process_event_addr = world->GetProcessEventAddr();

    FN_ServerShortTimeout = ObjectArray->FindObject("Function Engine.PlayerController.ServerShortTimeout");

    TransparentMaterial_FN = (UMaterial*)ObjectArray->FindObject("Material M_GradientRadial.M_GradientRadial");

    //TransparentMaterial_FN->bDisableDepthTest = true;
    //TransparentMaterial_FN->Wireframe = true;

    MH_Initialize();
    MH_CreateHook((LPVOID)process_event_addr, &process_event_hook, reinterpret_cast<void**>(&process_event_original));
    MH_EnableHook((DWORD_PTR*)process_event_addr);

    engine_font = ObjectArray->FindObject("Font Roboto.Roboto");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        std::async(std::launch::async, init);
        break;
    }
    }
    return TRUE;
}
