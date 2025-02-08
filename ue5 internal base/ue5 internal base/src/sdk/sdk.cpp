#include "sdk.h"
#include "sdk_functions.h"

#define M_PI       3.14159265358979323846   // pi

FVector AActor::K2_GetActorLocation() 
{
	struct {
		FVector return_value;
	} parms;

	ProcessEvent(functions::K2_GetActorLocation_FN, &parms);

	return parms.return_value;
}

FRotator AActor::K2_GetActorRotation() 
{
	struct {
		FRotator return_value;
	} parms;
	
	ProcessEvent(functions::K2_GetActorRotation_FN, &parms);
	return parms.return_value;
}

void UCanvas::K2_DrawText(UObject* RenderFont, const F_String& RenderText, const FVector2D& ScreenPosition, const FVector2D& Scale, const FLinearColor& RenderColor, float Kerning, const FLinearColor& ShadowColor, const FVector2D& ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, const FLinearColor& OutlineColor)
{
	struct {
		UObject* RenderFont;
		F_String RenderText;
		FVector2D ScreenPosition;
		FVector2D Scale;
		FLinearColor RenderColor;
		float Kerning;
		FLinearColor ShadowColor;
		FVector2D ShadowOffset;
		bool bCentreX;
		bool bCentreY;
		bool bOutlined;
		FLinearColor OutlineColor;
	}parms{};
	parms.RenderFont = RenderFont;
	parms.RenderText = RenderText;
	parms.ScreenPosition = ScreenPosition;
	parms.Scale = Scale;
	parms.RenderColor = RenderColor;
	parms.Kerning = Kerning;
	parms.ShadowColor = ShadowColor;
	parms.ShadowOffset = ShadowOffset;
	parms.bCentreX = bCentreX;
	parms.bCentreY = bCentreY;
	parms.bOutlined = bOutlined;
	parms.OutlineColor = OutlineColor;

	ProcessEvent(functions::K2_DrawText_FN, &parms);
}

void UCanvas::K2_DrawLine(const FVector2D& ScreenPositionA, const FVector2D& ScreenPositionB, float Thickness, const FLinearColor& RenderColor)
{
	struct {
		FVector2D ScreenPositionA;
		FVector2D ScreenPositionB;
		float Thickness;
		FLinearColor RenderColor;
	}parms{};

	parms.ScreenPositionA = ScreenPositionA;
	parms.ScreenPositionB = ScreenPositionB;
	parms.Thickness = Thickness;
	parms.RenderColor = RenderColor;

	ProcessEvent(functions::K2_DrawLine_FN, &parms);
}

bool AController::LineOfSightTo(AActor* Other, const FVector& ViewPoint, bool bAlternateChecks)
{
	struct {
		AActor* Other;
		FVector ViewPoint;
		bool bAlternateChecks;
		bool return_value;
	}parms{};

	parms.Other = Other;
	parms.ViewPoint = ViewPoint;
	parms.bAlternateChecks = bAlternateChecks;

	ProcessEvent(functions::LineOfSightTo_FN, &parms);

	return parms.return_value;
}

bool APlayerController::ProjectWorldLocationToScreen(FVector WorldLocation, FVector2D& ScreenLocation, bool bPlayerViewportRelative) 
{
	struct {
		FVector WorldLocation;
		FVector2D ScreenLocation;
		bool bPlayerViewportRelative;
		bool return_value;
	}parms{};

	parms.WorldLocation = WorldLocation;
	parms.ScreenLocation = ScreenLocation;
	parms.bPlayerViewportRelative = bPlayerViewportRelative;

	ProcessEvent(functions::ProjectWorldLocationToScreen_FN, &parms);

	ScreenLocation = parms.ScreenLocation;

	return parms.return_value;
}


void AActor::GetActorBounds(bool bOnlyCollidingComponents, FVector& Origin, FVector& BoxExtent, bool bIncludeFromChildActors)
{
	struct {
		bool bOnlyCollidingComponents;
		FVector Origin;
		FVector BoxExtent;
		bool bIncludeFromChildActors;
	}parms{};

	parms.bOnlyCollidingComponents = bOnlyCollidingComponents;
	parms.Origin = Origin;
	parms.BoxExtent = BoxExtent;
	parms.bIncludeFromChildActors = bIncludeFromChildActors;

	ProcessEvent(functions::GetActorBounds_FN, &parms);

	Origin = parms.Origin;

	BoxExtent = parms.BoxExtent;
}

FVector UKismetMathLibrary::VInterpTo(FVector Current, FVector Target, float DeltaTime, float InterpSpeed)
{
	struct {
		FVector Current;
		FVector Target;
		float DeltaTime;
		float InterpSpeed;

		FVector return_value;
	}parms{};

	parms.Current = Current;
	parms.Target = Target;
	parms.DeltaTime = DeltaTime;
	parms.InterpSpeed = InterpSpeed;

	ProcessEvent(functions::VInterpTo_FN, &parms);

	return parms.return_value;
}

FRotator UKismetMathLibrary::FindLookAtRotation(const FVector& Start, const FVector& Target)
{

	struct {
		FVector Start;
		FVector Target;

		FRotator return_value;
	}parms{};

	parms.Start = Start;
	parms.Target = Target;
	ProcessEvent(functions::FindLookAtRotation_FN, &parms);

	return parms.return_value;
}

float UGameplayStatics::GetWorldDeltaSeconds(UObject* WorldContextObject)
{
	struct {
		UObject* WorldContextObject;
		float return_value;
	}parms{};

	parms.WorldContextObject = WorldContextObject;

	ProcessEvent(functions::GetWorldDeltaSeconds_FN, &parms);

	return parms.return_value;
}

FVector APlayerCameraManager::GetCameraLocation()
{
	struct {
		FVector return_value;
	}parms{};

	ProcessEvent(functions::GetCameraLocation_FN, &parms);

	return parms.return_value;
}

FRotator APlayerCameraManager::GetCameraRotation()
{
	struct {
		FRotator return_value;
	}parms{};

	ProcessEvent(functions::GetCameraRotation_FN, &parms);

	return parms.return_value;
}

void AController::SetControlRotation(const FRotator& NewRotation)
{
	struct {
		struct FRotator NewRotation;
	}parms;

	parms.NewRotation = NewRotation;

	ProcessEvent(functions::SetControlRotation_FN, &parms);
}

void APlayerController::FOV(float NewFOV)
{
	struct {
		float NewFOV;
	}parms{};

	parms.NewFOV = NewFOV;

	ProcessEvent(functions::FOV_FN, &parms);
}

FVector USceneComponent::GetSocketLocation(FName InSocketName)
{
	struct {
		FName InSocketName;
		FVector return_value;
	}parms{};

	parms.InSocketName = InSocketName;

	ProcessEvent(functions::GetSocketLocation_FN, &parms);

	return parms.return_value;
}

FName USkinnedMeshComponent::GetBoneName(int32_t BoneIndex) 
{
	struct {
		int32_t BoneIndex;

		FName retrun_value;
	}parms{};

	parms.BoneIndex = BoneIndex;

	ProcessEvent(functions::GetBoneName_FN, &parms);

	return parms.retrun_value;
}

bool AActor::K2_SetActorRotation(const FRotator& NewRotation, bool bTeleportPhysics)
{
	struct {
		FRotator NewLocation;
		bool bTeleportPhysics;

		bool retrun_value;
	}parms{};

	ProcessEvent(functions::K2_SetActorRotation_FN, &parms);

	return parms.retrun_value;
}

bool AActor::K2_TeleportTo(const FVector& DestLocation, const FRotator& DestRotation)
{
	struct {
		FVector DestLocation;
		FRotator DestRotation;

		bool return_value;
	}parms{};

	parms.DestLocation = DestLocation;
	parms.DestRotation = DestRotation;

	ProcessEvent(functions::K2_TeleportTo_FN, &parms);

	return parms.return_value;
}

void APlayerController::SetName(const F_String& S)
{
	struct {
		F_String S;
	}parms{};

	parms.S = S;

	ProcessEvent(functions::SetName_FN, &parms);
}

void APlayerController::ServerChangeName(const F_String& S)
{
	struct {
		F_String S;
	}parms{};

	parms.S = S;

	ProcessEvent(functions::SetName_FN, &parms);
}

FVector GetVectorForward(FRotator angles)
{

	float sp, sy, cp, cy;
	float angle;

	angle = angles.y * (M_PI / 180.0f);
	sy = sinf(angle);
	cy = cosf(angle);
	angle = -angles.x * (M_PI / 180.0f);
	sp = sinf(angle);
	cp = cosf(angle);

	return { cp * cy, cp * sy, -sp };
}

bool AActor::K2_SetActorLocation(const FVector& NewLocation, bool bSweep, FHitResult* SweepHitResult, bool bTeleport)
{
	struct {
		FVector NewLocation;
		bool bSweep;
		FHitResult* SweepHitResult;
		bool bTeleport;

		bool retrun_value;
	}parms{};

	parms.NewLocation = NewLocation;
	parms.bSweep = bSweep;
	parms.SweepHitResult = SweepHitResult;
	parms.bTeleport = bTeleport;

	ProcessEvent(functions::K2_SetActorLocation_FN, &parms);

	return parms.retrun_value;
}

UMaterialInterface* UPrimitiveComponent::GetMaterial(int32_t ElementIndex)
{
	struct {
		int32_t ElementIndex;
		UMaterialInterface* retrun_value;
	}parms{};

	parms.ElementIndex = ElementIndex;

	ProcessEvent(functions::GetMaterial_FN, &parms);

	return parms.retrun_value;
}

void UPrimitiveComponent::SetMaterial(int32_t ElementIndex, UMaterialInterface* Material)
{
	struct {
		int32_t ElementIndex;
		UMaterialInterface* Material;
	}parms{};

	parms.ElementIndex = ElementIndex;
	parms.Material = Material;

	ProcessEvent(functions::SetMaterial_FN, &parms);

}

TArray<class UMaterialInterface*> UMeshComponent::GetMaterials()
{
	struct {
		TArray<class UMaterialInterface*> return_value;
	}parms{};

	ProcessEvent(functions::GetMaterials_FN, &parms);

	return parms.return_value;
}
