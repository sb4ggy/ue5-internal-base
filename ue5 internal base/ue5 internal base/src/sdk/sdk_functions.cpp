#pragma once
#include "sdk_functions.h"

extern TUObjectArray* ObjectArray;

namespace functions {
	UObject* K2_GetActorLocation_FN = 0;

	UObject* K2_GetActorRotation_FN = 0;

	UObject* K2_DrawText_FN;

	UObject* K2_DrawLine_FN;

	UObject* LineOfSightTo_FN;

	UObject* ProjectWorldLocationToScreen_FN;

	UObject* GetActorBounds_FN;

	UObject* GetWorldDeltaSeconds_FN;

	UObject* FindLookAtRotation_FN;

	UObject* VInterpTo_FN;

	UObject* GetCameraLocation_FN;

	UObject* GetCameraRotation_FN;

	UObject* SetControlRotation_FN;

	UObject* Class_GamePlayStatics;

	UObject* Class_KismetMathLibrary;

	UObject* FOV_FN;

	UObject* GetSocketLocation_FN;

	UObject* GetBoneName_FN;

	UObject* K2_TeleportTo_FN;

	UObject* SetName_FN;

	UObject* ServerChangeName_FN;

	UObject* K2_SetActorLocation_FN;

	UObject* GetMaterial_FN;

	UObject* GetMaterials_FN;

	UObject* SetMaterial_FN;

	UObject* K2_SetActorRotation_FN;

	void init() {
		K2_GetActorLocation_FN = ObjectArray->FindObject("Function Engine.Actor.K2_GetActorLocation");

		K2_GetActorRotation_FN = ObjectArray->FindObject("Function Engine.Actor.K2_GetActorRotation");

		K2_DrawText_FN = ObjectArray->FindObject("Function Engine.Canvas.K2_DrawText");

		K2_DrawLine_FN = ObjectArray->FindObject("Function Engine.Canvas.K2_DrawLine");

		LineOfSightTo_FN = ObjectArray->FindObject("Function Engine.Controller.LineOfSightTo");

		ProjectWorldLocationToScreen_FN = ObjectArray->FindObject("Function Engine.PlayerController.ProjectWorldLocationToScreen");

		GetActorBounds_FN = ObjectArray->FindObject("Function Engine.Actor.GetActorBounds");

		GetWorldDeltaSeconds_FN = ObjectArray->FindObject("Function Engine.GameplayStatics.GetWorldDeltaSeconds");

		FindLookAtRotation_FN = ObjectArray->FindObject("Function Engine.KismetMathLibrary.FindLookAtRotation");

		VInterpTo_FN = ObjectArray->FindObject("Function Engine.KismetMathLibrary.VInterpTo");

		GetCameraLocation_FN = ObjectArray->FindObject("Function Engine.PlayerCameraManager.GetCameraLocation");

		GetCameraRotation_FN = ObjectArray->FindObject("Function Engine.PlayerCameraManager.GetCameraRotation");

		SetControlRotation_FN = ObjectArray->FindObject("Function Engine.Controller.SetControlRotation");

		Class_GamePlayStatics = ObjectArray->FindObject("Class Engine.GameplayStatics");

		Class_KismetMathLibrary = ObjectArray->FindObject("Class Engine.KismetMathLibrary");

		FOV_FN = ObjectArray->FindObject("Function Engine.PlayerController.FOV");

		GetSocketLocation_FN = ObjectArray->FindObject("Function Engine.SceneComponent.GetSocketLocation");

		GetBoneName_FN = ObjectArray->FindObject("Function Engine.SkinnedMeshComponent.GetBoneName");

		K2_TeleportTo_FN = ObjectArray->FindObject("Function Engine.Actor.K2_TeleportTo");

		SetName_FN = ObjectArray->FindObject("Function Engine.PlayerController.SetName");

		ServerChangeName_FN = ObjectArray->FindObject("Function Engine.PlayerController.ServerChangeName");

		K2_SetActorLocation_FN = ObjectArray->FindObject("Function Engine.Actor.K2_SetActorLocation");

		GetMaterial_FN = ObjectArray->FindObject("Function Engine.StaticMesh.GetMaterial");

		GetMaterials_FN = ObjectArray->FindObject("Function Engine.MeshComponent.GetMaterials");

		SetMaterial_FN = ObjectArray->FindObject("Function Engine.PrimitiveComponent.SetMaterial");

		K2_SetActorRotation_FN = ObjectArray->FindObject("Function Engine.Actor.K2_SetActorRotation");
	}
}
