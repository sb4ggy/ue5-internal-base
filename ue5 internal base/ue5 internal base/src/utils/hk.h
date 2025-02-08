#pragma once
#include "../sdk/sdk_functions.h"
#include "../sdk/sdk.h"
#include <future>

int post_render_index = 0x63;
int process_event_index = 0x44;

std::future<void> main_future;
TUObjectArray* ObjectArray;
UObject* FN_ServerShortTimeout = 0;
UObject* engine_font = 0;
UMaterial* TransparentMaterial_FN = 0;
UObject* projectile = 0;

using pevent_fn = void(__thiscall*)(UObject*, UObject*, void* pararms);
pevent_fn process_event_original = 0;

using fn = void(__thiscall*)(UGameViewportClient*, UCanvas*);
fn post_render_original = 0;

void process_event_hook(UObject* caller, UObject* fn, void* parms) {

    process_event_original(caller, fn, parms);
}