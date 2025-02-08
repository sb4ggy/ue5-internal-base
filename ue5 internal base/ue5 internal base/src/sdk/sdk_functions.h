#pragma once
#include "engine.h"

namespace functions {
	extern UObject* K2_GetActorLocation_FN;

	extern UObject* K2_GetActorRotation_FN;

	extern UObject* K2_DrawText_FN;

	extern UObject* K2_DrawLine_FN;

	extern UObject* LineOfSightTo_FN;

	extern UObject* ProjectWorldLocationToScreen_FN;

	extern UObject* GetActorBounds_FN;

	extern UObject* GetWorldDeltaSeconds_FN;

	extern UObject* FindLookAtRotation_FN;

	extern UObject* VInterpTo_FN;

	extern UObject* GetCameraLocation_FN;

	extern UObject* GetCameraRotation_FN;

	extern UObject* SetControlRotation_FN;

	extern UObject* Class_GamePlayStatics;

	extern UObject* Class_KismetMathLibrary;

	extern UObject* FOV_FN;

	extern UObject* GetSocketLocation_FN;
	
	extern UObject* GetBoneName_FN;

	extern UObject* K2_TeleportTo_FN;

	extern UObject* SetName_FN;

	extern UObject* K2_SetActorLocation_FN;

	extern UObject* GetMaterial_FN;

	extern UObject* GetMaterials_FN;

	extern UObject* SetMaterial_FN;

	extern UObject* K2_SetActorRotation_FN;;


	extern void init();
}
