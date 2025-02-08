#pragma once
#include "classes.h"
#include <cstdint>

FVector GetVectorForward(FRotator angles);



class UActorComponent : public UObject
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x0028   (0x0008)  MISSED
	char                        PrimaryComponentTick[0x30];                                       // 0x0030   (0x0030)  
	TArray<FName>                                      ComponentTags;                                              // 0x0060   (0x0010)  
	TArray<class UAssetUserData*>                      AssetUserData;                                              // 0x0070   (0x0010)  
	unsigned char                                      UnknownData01_6[0x4];                                       // 0x0080   (0x0004)  MISSED
	int32_t                                            UCSSerializationIndex;                                      // 0x0084   (0x0004)  
	unsigned char                                      UnknownBit02 : 1;                                           // 0x0088:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit03 : 1;                                           // 0x0088:1 (0x0001)  MISSED
	unsigned char                                      UnknownBit04 : 1;                                           // 0x0088:2 (0x0001)  MISSED
	bool                                               bNetAddressable : 1;                                        // 0x0088:3 (0x0001)  
	bool                                               bReplicates : 1;                                            // 0x0088:4 (0x0001)  
	unsigned char                                      UnknownBit05 : 1;                                           // 0x0088:5 (0x0001)  MISSED
	unsigned char                                      UnknownBit06 : 1;                                           // 0x0088:6 (0x0001)  MISSED
	unsigned char                                      UnknownBit07 : 1;                                           // 0x0088:7 (0x0001)  MISSED
	unsigned char                                      UnknownBit08 : 1;                                           // 0x0089:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit09 : 1;                                           // 0x0089:1 (0x0001)  MISSED
	unsigned char                                      UnknownBit10 : 1;                                           // 0x0089:2 (0x0001)  MISSED
	unsigned char                                      UnknownBit11 : 1;                                           // 0x0089:3 (0x0001)  MISSED
	unsigned char                                      UnknownBit12 : 1;                                           // 0x0089:4 (0x0001)  MISSED
	unsigned char                                      UnknownBit13 : 1;                                           // 0x0089:5 (0x0001)  MISSED
	unsigned char                                      UnknownBit14 : 1;                                           // 0x0089:6 (0x0001)  MISSED
	bool                                               bAutoActivate : 1;                                          // 0x0089:7 (0x0001)  
	bool                                               bIsActive : 1;                                              // 0x008A:0 (0x0001)  
	bool                                               bEditableWhenInherited : 1;                                 // 0x008A:1 (0x0001)  
	unsigned char                                      UnknownBit15 : 1;                                           // 0x008A:2 (0x0001)  MISSED
	bool                                               bCanEverAffectNavigation : 1;                               // 0x008A:3 (0x0001)  
	unsigned char                                      UnknownBit16 : 1;                                           // 0x008A:4 (0x0001)  MISSED
	bool                                               bIsEditorOnly : 1;                                          // 0x008A:5 (0x0001)  
	unsigned char                                      UnknownData17_5[0x1];                                       // 0x008B   (0x0001)  MISSED
	char                           CreationMethod;                                             // 0x008C   (0x0001)  
	char OnComponentActivated;                                 // 0x008D   (0x0001)  
	char OnComponentDeactivated;                               // 0x008E   (0x0001)  
	unsigned char                                      UnknownData18_6[0x1];                                       // 0x008F   (0x0001)  MISSED
	char                     UCSModifiedProperties[0x10];                                      // 0x0090   (0x0010)  
	unsigned char                                      UnknownData19_7[0x10];                                      // 0x00A0   (0x0010)  MISSED
};

class USceneComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x00B0   (0x0008)  MISSED
	class APhysicsVolume*             PhysicsVolume;                                              // 0x00B8   (0x0008)  
	class USceneComponent* AttachParent;                                               // 0x00C0   (0x0008)  
	FName                                              AttachSocketName;                                           // 0x00C8   (0x0008)  
	TArray<class USceneComponent*>                     AttachChildren;                                             // 0x00D0   (0x0010)  
	TArray<class USceneComponent*>                     ClientAttachedChildren;                                     // 0x00E0   (0x0010)  
	unsigned char                                      UnknownData01_6[0x2C];                                      // 0x00F0   (0x002C)  MISSED
	FVector                                            RelativeLocation;                                           // 0x011C   (0x000C)  
	FRotator                                           RelativeRotation;                                           // 0x0128   (0x000C)  
	FVector                                            RelativeScale3D;                                            // 0x0134   (0x000C)  
	FVector                                            ComponentVelocity;                                          // 0x0140   (0x000C)  
	bool                                               bComponentToWorldUpdated : 1;                               // 0x014C:0 (0x0001)  
	unsigned char                                      UnknownBit02 : 1;                                           // 0x014C:1 (0x0001)  MISSED
	bool                                               bAbsoluteLocation : 1;                                      // 0x014C:2 (0x0001)  
	bool                                               bAbsoluteRotation : 1;                                      // 0x014C:3 (0x0001)  
	bool                                               bAbsoluteScale : 1;                                         // 0x014C:4 (0x0001)  
	bool                                               bVisible : 1;                                               // 0x014C:5 (0x0001)  
	bool                                               bShouldBeAttached : 1;                                      // 0x014C:6 (0x0001)  
	bool                                               bShouldSnapLocationWhenAttached : 1;                        // 0x014C:7 (0x0001)  
	bool                                               bShouldSnapRotationWhenAttached : 1;                        // 0x014D:0 (0x0001)  
	bool                                               bShouldUpdatePhysicsVolume : 1;                             // 0x014D:1 (0x0001)  
	bool                                               bHiddenInGame : 1;                                          // 0x014D:2 (0x0001)  
	bool                                               bBoundsChangeTriggersStreamingDataRebuild : 1;              // 0x014D:3 (0x0001)  
	bool                                               bUseAttachParentBound : 1;                                  // 0x014D:4 (0x0001)  
	unsigned char                                      UnknownData03_5[0x1];                                       // 0x014E   (0x0001)  MISSED
	EComponentMobility                    Mobility;                                                   // 0x014F   (0x0001)  
	EDetailMode                           DetailMode;                                                 // 0x0150   (0x0001)  
	char PhysicsVolumeChangedDelegate;                         // 0x0151   (0x0001)  
	unsigned char                                      UnknownData04_7[0xA6];                                      // 0x0152   (0x00A6)  MISSED


	void DetachFromParent(bool bMaintainWorldPosition, bool bCallModify);
	void K2_AddLocalOffset(const struct FVector& DeltaLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddLocalRotation(const struct FRotator& DeltaRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddLocalTransform(const struct FTransform& DeltaTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddRelativeLocation(const struct FVector& DeltaLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddRelativeRotation(const struct FRotator& DeltaRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddWorldOffset(const struct FVector& DeltaLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddWorldRotation(const struct FRotator& DeltaRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddWorldTransform(const struct FTransform& DeltaTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddWorldTransformKeepScale(const struct FTransform& DeltaTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	bool K2_AttachTo(class USceneComponent* InParent, class FName InSocketName, EAttachLocation AttachType, bool bWeldSimulatedBodies);
	bool K2_AttachToComponent(class USceneComponent* Parent, class FName SocketName, EAttachmentRule LocationRule, EAttachmentRule RotationRule, EAttachmentRule ScaleRule, bool bWeldSimulatedBodies);
	void K2_DetachFromComponent(EDetachmentRule LocationRule, EDetachmentRule RotationRule, EDetachmentRule ScaleRule, bool bCallModify);
	void K2_SetRelativeLocation(const struct FVector& NewLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetRelativeLocationAndRotation(const struct FVector& NewLocation, const struct FRotator& NewRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetRelativeRotation(const struct FRotator& NewRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetRelativeTransform(const struct FTransform& NewTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetWorldLocation(const struct FVector& NewLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetWorldLocationAndRotation(const struct FVector& NewLocation, const struct FRotator& NewRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetWorldRotation(const struct FRotator& NewRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetWorldTransform(const struct FTransform& NewTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void OnRep_AttachChildren();
	void OnRep_AttachParent();
	void OnRep_AttachSocketName();
	void OnRep_Transform();
	void OnRep_Visibility(bool OldValue);
	void ResetRelativeTransform();
	void SetAbsolute(bool bNewAbsoluteLocation, bool bNewAbsoluteRotation, bool bNewAbsoluteScale);
	void SetHiddenInGame(bool NewHidden, bool bPropagateToChildren);
	void SetMobility(EComponentMobility NewMobility);
	void SetRelativeScale3D(const struct FVector& NewScale3D);
	void SetShouldUpdatePhysicsVolume(bool bInShouldUpdatePhysicsVolume);
	void SetVisibility(bool bNewVisibility, bool bPropagateToChildren);
	void SetWorldScale3D(const struct FVector& NewScale);
	bool SnapTo(class USceneComponent* InParent, class FName InSocketName);
	void ToggleVisibility(bool bPropagateToChildren);

	bool DoesSocketExist(class FName InSocketName) const;
	TArray<class FName> GetAllSocketNames() const;
	class USceneComponent* GetAttachParent() const;
	class FName GetAttachSocketName() const;
	class USceneComponent* GetChildComponent(int32_t ChildIndex) const;
	void GetChildrenComponents(bool bIncludeAllDescendants, TArray<class USceneComponent*>* Children) const;
	struct FVector GetComponentVelocity() const;
	struct FVector GetForwardVector() const;
	int32_t GetNumChildrenComponents() const;
	void GetParentComponents(TArray<class USceneComponent*>* Parents) const;
	class APhysicsVolume* GetPhysicsVolume() const;
	struct FTransform GetRelativeTransform() const;
	struct FVector GetRightVector() const;
	bool GetShouldUpdatePhysicsVolume() const;
	struct FVector GetSocketLocation(class FName InSocketName);
	struct FQuat GetSocketQuaternion(class FName InSocketName) const;
	struct FRotator GetSocketRotation(class FName InSocketName) const;
	struct FTransform GetSocketTransform(class FName InSocketName, ERelativeTransformSpace TransformSpace) const;
	struct FVector GetUpVector() const;
	bool IsAnySimulatingPhysics() const;
	bool IsSimulatingPhysics(class FName BoneName) const;
	bool IsVisible() const;
	struct FVector K2_GetComponentLocation() const;
	struct FRotator K2_GetComponentRotation() const;
	struct FVector K2_GetComponentScale() const;
	struct FTransform K2_GetComponentToWorld() const;

};

class UPrimitiveComponent : public USceneComponent
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x01F8   (0x0008)  MISSED
	float                                              MinDrawDistance;                                            // 0x0200   (0x0004)  
	float                                              LDMaxDrawDistance;                                          // 0x0204   (0x0004)  
	float                                              CachedMaxDrawDistance;                                      // 0x0208   (0x0004)  
	float                                              LDCullScreenSpaceSize;                                      // 0x020C   (0x0004)  
	float                                              CachedCullScreenSpaceSize;                                  // 0x0210   (0x0004)  
	ESceneDepthPriorityGroup              DepthPriorityGroup;                                         // 0x0214   (0x0001)  
	ESceneDepthPriorityGroup              ViewOwnerDepthPriorityGroup;                                // 0x0215   (0x0001)  
	EIndirectLightingCacheQuality         IndirectLightingCacheQuality;                               // 0x0216   (0x0001)  
	ELightmapType                                      LightmapType;                                               // 0x0217   (0x0001)  
	bool                                               bUseMaxLODAsImposter : 1;                                   // 0x0218:0 (0x0001)  
	bool                                               bBatchImpostersAsInstances : 1;                             // 0x0218:1 (0x0001)  
	bool                                               bNeverDistanceCull : 1;                                     // 0x0218:2 (0x0001)  
	unsigned char                                      UnknownBit01 : 1;                                           // 0x0218:3 (0x0001)  MISSED
	unsigned char                                      UnknownBit02 : 1;                                           // 0x0218:4 (0x0001)  MISSED
	unsigned char                                      UnknownBit03 : 1;                                           // 0x0218:5 (0x0001)  MISSED
	unsigned char                                      UnknownBit04 : 1;                                           // 0x0218:6 (0x0001)  MISSED
	bool                                               bAlwaysCreatePhysicsState : 1;                              // 0x0218:7 (0x0001)  
	bool                                               bGenerateOverlapEvents : 1;                                 // 0x0219:0 (0x0001)  
	bool                                               bMultiBodyOverlap : 1;                                      // 0x0219:1 (0x0001)  
	bool                                               bTraceComplexOnMove : 1;                                    // 0x0219:2 (0x0001)  
	bool                                               bReturnMaterialOnMove : 1;                                  // 0x0219:3 (0x0001)  
	bool                                               bUseViewOwnerDepthPriorityGroup : 1;                        // 0x0219:4 (0x0001)  
	bool                                               bAllowCullDistanceVolume : 1;                               // 0x0219:5 (0x0001)  
	bool                                               bHasMotionBlurVelocityMeshes : 1;                           // 0x0219:6 (0x0001)  
	bool                                               bVisibleInReflectionCaptures : 1;                           // 0x0219:7 (0x0001)  
	bool                                               bVisibleInRealTimeSkyCaptures : 1;                          // 0x021A:0 (0x0001)  
	bool                                               bVisibleInRayTracing : 1;                                   // 0x021A:1 (0x0001)  
	bool                                               bRenderInMainPass : 1;                                      // 0x021A:2 (0x0001)  
	bool                                               bRenderInDepthPass : 1;                                     // 0x021A:3 (0x0001)  
	bool                                               bReceivesDecals : 1;                                        // 0x021A:4 (0x0001)  
	bool                                               bOwnerNoSee : 1;                                            // 0x021A:5 (0x0001)  
	bool                                               bOnlyOwnerSee : 1;                                          // 0x021A:6 (0x0001)  
	bool                                               bTreatAsBackgroundForOcclusion : 1;                         // 0x021A:7 (0x0001)  
	bool                                               bUseAsOccluder : 1;                                         // 0x021B:0 (0x0001)  
	unsigned char                                      UnknownBit05 : 1;                                           // 0x021B:1 (0x0001)  MISSED
	unsigned char                                      UnknownBit06 : 1;                                           // 0x021B:2 (0x0001)  MISSED
	unsigned char                                      UnknownBit07 : 1;                                           // 0x021B:3 (0x0001)  MISSED
	unsigned char                                      UnknownBit08 : 1;                                           // 0x021B:4 (0x0001)  MISSED
	unsigned char                                      UnknownBit09 : 1;                                           // 0x021B:5 (0x0001)  MISSED
	unsigned char                                      UnknownBit10 : 1;                                           // 0x021B:6 (0x0001)  MISSED
	unsigned char                                      UnknownBit11 : 1;                                           // 0x021B:7 (0x0001)  MISSED
	bool                                               bUseAsRainOccluder : 1;                                     // 0x021C:0 (0x0001)  
	unsigned char                                      UnknownData12_3[0x3];                                       // 0x021D   (0x0003)  MISSED
	bool                                               bSelectable : 1;                                            // 0x0220:0 (0x0001)  
	bool                                               bForceMipStreaming : 1;                                     // 0x0220:1 (0x0001)  
	bool                                               bHasPerInstanceHitProxies : 1;                              // 0x0220:2 (0x0001)  
	bool                                               CastShadow : 1;                                             // 0x0220:3 (0x0001)  
	bool                                               bAffectDynamicIndirectLighting : 1;                         // 0x0220:4 (0x0001)  
	bool                                               bAffectDistanceFieldLighting : 1;                           // 0x0220:5 (0x0001)  
	bool                                               bCastDynamicShadow : 1;                                     // 0x0220:6 (0x0001)  
	bool                                               bCastStaticShadow : 1;                                      // 0x0220:7 (0x0001)  
	bool                                               bCastVolumetricTranslucentShadow : 1;                       // 0x0221:0 (0x0001)  
	bool                                               bCastContactShadow : 1;                                     // 0x0221:1 (0x0001)  
	bool                                               bSelfShadowOnly : 1;                                        // 0x0221:2 (0x0001)  
	bool                                               bCastFarShadow : 1;                                         // 0x0221:3 (0x0001)  
	bool                                               bCastInsetShadow : 1;                                       // 0x0221:4 (0x0001)  
	bool                                               bCastCinematicShadow : 1;                                   // 0x0221:5 (0x0001)  
	bool                                               bCastHiddenShadow : 1;                                      // 0x0221:6 (0x0001)  
	bool                                               bCastShadowAsTwoSided : 1;                                  // 0x0221:7 (0x0001)  
	bool                                               bLightAsIfStatic : 1;                                       // 0x0222:0 (0x0001)  
	char                         LightmapGenerationOverride;                                 // 0x0223   (0x0001)  
	bool                                               bLightAttachmentsAsGroup : 1;                               // 0x0224:0 (0x0001)  
	bool                                               bExcludeFromLightAttachmentGroup : 1;                       // 0x0224:1 (0x0001)  
	bool                                               bReceiveMobileCSMShadows : 1;                               // 0x0224:2 (0x0001)  
	bool                                               bSingleSampleShadowFromStationaryLights : 1;                // 0x0224:3 (0x0001)  
	bool                                               bIgnoreRadialImpulse : 1;                                   // 0x0224:4 (0x0001)  
	bool                                               bIgnoreRadialForce : 1;                                     // 0x0224:5 (0x0001)  
	bool                                               bApplyImpulseOnDamage : 1;                                  // 0x0224:6 (0x0001)  
	bool                                               bReplicatePhysicsToAutonomousProxy : 1;                     // 0x0224:7 (0x0001)  
	bool                                               bFillCollisionUnderneathForNavmesh : 1;                     // 0x0225:0 (0x0001)  
	bool                                               AlwaysLoadOnClient : 1;                                     // 0x0225:1 (0x0001)  
	bool                                               AlwaysLoadOnServer : 1;                                     // 0x0225:2 (0x0001)  
	bool                                               bUseEditorCompositing : 1;                                  // 0x0225:3 (0x0001)  
	bool                                               bRenderCustomDepth : 1;                                     // 0x0225:4 (0x0001)  
	bool                                               bVisibleInSceneCaptureOnly : 1;                             // 0x0225:5 (0x0001)  
	bool                                               bHiddenInSceneCapture : 1;                                  // 0x0225:6 (0x0001)  
	EHasCustomNavigableGeometry           bHasCustomNavigableGeometry;                                // 0x0226   (0x0001)  
	unsigned char                                      UnknownData13_6[0x1];                                       // 0x0227   (0x0001)  MISSED
	ECanBeCharacterBase                   CanCharacterStepUpOn;                                       // 0x0228   (0x0001)  
	char                                   LightingChannels;                                           // 0x0229   (0x0001)  
	ERendererStencilMask                               CustomDepthStencilWriteMask;                                // 0x022A   (0x0001)  
	unsigned char                                      UnknownData14_6[0x1];                                       // 0x022B   (0x0001)  MISSED
	int32_t                                            CustomDepthStencilValue;                                    // 0x022C   (0x0004)  
	char                                CustomPrimitiveData[0x10];                                        // 0x0230   (0x0010)  
	char                                CustomPrimitiveDataInternal[0x10];                                // 0x0240   (0x0010)  
	unsigned char                                      UnknownData15_6[0x8];                                       // 0x0250   (0x0008)  MISSED
	int32_t                                            TranslucencySortPriority;                                   // 0x0258   (0x0004)  
	float                                              TranslucencySortDistanceOffset;                             // 0x025C   (0x0004)  
	int32_t                                            VisibilityId;                                               // 0x0260   (0x0004)  
	unsigned char                                      UnknownData16_6[0x4];                                       // 0x0264   (0x0004)  MISSED
	TArray<class URuntimeVirtualTexture*>              RuntimeVirtualTextures;                                     // 0x0268   (0x0010)  
	int8_t                                             VirtualTextureLodBias;                                      // 0x0278   (0x0001)  
	int8_t                                             VirtualTextureCullMips;                                     // 0x0279   (0x0001)  
	int8_t                                             VirtualTextureMinCoverage;                                  // 0x027A   (0x0001)  
	ERuntimeVirtualTextureMainPassType                 VirtualTextureRenderPassType;                               // 0x027B   (0x0001)  
	unsigned char                                      UnknownData17_6[0x4];                                       // 0x027C   (0x0004)  MISSED
	float                                              LpvBiasMultiplier;                                          // 0x0280   (0x0004)  
	unsigned char                                      UnknownData18_6[0x8];                                       // 0x0284   (0x0008)  MISSED
	float                                              BoundsScale;                                                // 0x028C   (0x0004)  
	unsigned char                                      UnknownData19_6[0x10];                                      // 0x0290   (0x0010)  MISSED
	TArray<class AActor*>                              MoveIgnoreActors;                                           // 0x02A0   (0x0010)  
	TArray<class UPrimitiveComponent*>                 MoveIgnoreComponents;                                       // 0x02B0   (0x0010)  
	unsigned char                                      UnknownData20_6[0x10];                                      // 0x02C0   (0x0010)  MISSED
	char                                       BodyInstance[0x158];                                               // 0x02D0   (0x0158)  
	char OnComponentHit;                                       // 0x0428   (0x0001)  
	char OnComponentBeginOverlap;                              // 0x0429   (0x0001)  
	char OnComponentEndOverlap;                                // 0x042A   (0x0001)  
	char OnComponentWake;                                      // 0x042B   (0x0001)  
	char OnComponentSleep;                                     // 0x042C   (0x0001)  
	unsigned char                                      UnknownData21_6[0x1];                                       // 0x042D   (0x0001)  MISSED
	char OnBeginCursorOver;                                    // 0x042E   (0x0001)  
	char OnEndCursorOver;                                      // 0x042F   (0x0001)  
	char OnClicked;                                            // 0x0430   (0x0001)  
	char OnReleased;                                           // 0x0431   (0x0001)  
	char OnInputTouchBegin;                                    // 0x0432   (0x0001)  
	char OnInputTouchEnd;                                      // 0x0433   (0x0001)  
	char OnInputTouchEnter;                                    // 0x0434   (0x0001)  
	char OnInputTouchLeave;                                    // 0x0435   (0x0001)  
	unsigned char                                      UnknownData22_6[0x1A];                                      // 0x0436   (0x001A)  MISSED
	class UPrimitiveComponent* LODParentPrimitive;                                         // 0x0450   (0x0008)  

	void AddAngularImpulse(const struct FVector& Impulse, class FName BoneName, bool bVelChange);
	void AddAngularImpulseInDegrees(const struct FVector& Impulse, class FName BoneName, bool bVelChange);
	void AddAngularImpulseInRadians(const struct FVector& Impulse, class FName BoneName, bool bVelChange);
	void AddForce(const struct FVector& Force, class FName BoneName, bool bAccelChange);
	void AddForceAtLocation(const struct FVector& Force, const struct FVector& Location, class FName BoneName);
	void AddForceAtLocationLocal(const struct FVector& Force, const struct FVector& Location, class FName BoneName);
	void AddImpulse(const struct FVector& Impulse, class FName BoneName, bool bVelChange);
	void AddImpulseAtLocation(const struct FVector& Impulse, const struct FVector& Location, class FName BoneName);
	void AddRadialForce(const struct FVector& Origin, float Radius, float Strength, char Falloff, bool bAccelChange);
	void AddRadialImpulse(const struct FVector& Origin, float Radius, float Strength, char Falloff, bool bVelChange);
	void AddTorque(const struct FVector& Torque, class FName BoneName, bool bAccelChange);
	void AddTorqueInDegrees(const struct FVector& Torque, class FName BoneName, bool bAccelChange);
	void AddTorqueInRadians(const struct FVector& Torque, class FName BoneName, bool bAccelChange);
	void ClearMoveIgnoreActors();
	void ClearMoveIgnoreComponents();
	TArray<class AActor*> CopyArrayOfMoveIgnoreActors();
	TArray<class UPrimitiveComponent*> CopyArrayOfMoveIgnoreComponents();
	class UMaterialInstanceDynamic* CreateAndSetMaterialInstanceDynamic(int32_t ElementIndex);
	class UMaterialInstanceDynamic* CreateAndSetMaterialInstanceDynamicFromMaterial(int32_t ElementIndex, class UMaterialInterface* Parent);
	class UMaterialInstanceDynamic* CreateDynamicMaterialInstance(int32_t ElementIndex, class UMaterialInterface* SourceMaterial, class FName OptionalName);
	struct FVector GetPhysicsLinearVelocity(class FName BoneName);
	struct FVector GetPhysicsLinearVelocityAtPoint(const struct FVector& Point, class FName BoneName);
	void IgnoreActorWhenMoving(class AActor* Actor, bool bShouldIgnore);
	void IgnoreComponentWhenMoving(class UPrimitiveComponent* Component, bool bShouldIgnore);
	bool IsAnyRigidBodyAwake();
	bool K2_BoxOverlapComponent(const struct FVector& InBoxCentre, const struct FBox& InBox, bool bTraceComplex, bool bShowTrace, bool bPersistentShowTrace, struct FVector* HitLocation, struct FVector* HitNormal, class FName* BoneName, struct FHitResult* OutHit);
	bool K2_LineTraceComponent(const struct FVector& TraceStart, const struct FVector& TraceEnd, bool bTraceComplex, bool bShowTrace, bool bPersistentShowTrace, struct FVector* HitLocation, struct FVector* HitNormal, class FName* BoneName, struct FHitResult* OutHit);
	bool K2_SphereOverlapComponent(const struct FVector& InSphereCentre, float InSphereRadius, bool bTraceComplex, bool bShowTrace, bool bPersistentShowTrace, struct FVector* HitLocation, struct FVector* HitNormal, class FName* BoneName, struct FHitResult* OutHit);
	bool K2_SphereTraceComponent(const struct FVector& TraceStart, const struct FVector& TraceEnd, float SphereRadius, bool bTraceComplex, bool bShowTrace, bool bPersistentShowTrace, struct FVector* HitLocation, struct FVector* HitNormal, class FName* BoneName, struct FHitResult* OutHit);
	void PutRigidBodyToSleep(class FName BoneName);
	void SetAllMassScale(float InMassScale);
	void SetAllPhysicsAngularVelocityInDegrees(const struct FVector& NewAngVel, bool bAddToCurrent);
	void SetAllPhysicsAngularVelocityInRadians(const struct FVector& NewAngVel, bool bAddToCurrent);
	void SetAllPhysicsLinearVelocity(const struct FVector& NewVel, bool bAddToCurrent);
	void SetAllUseCCD(bool InUseCCD);
	void SetAngularDamping(float InDamping);
	void SetBoundsScale(float NewBoundsScale);
	void SetCastHiddenShadow(bool NewCastHiddenShadow);
	void SetCastInsetShadow(bool bInCastInsetShadow);
	void SetCastShadow(bool NewCastShadow);
	void SetCenterOfMass(const struct FVector& CenterOfMassOffset, class FName BoneName);
	void SetCollisionEnabled(ECollisionEnabled NewType);
	void SetCollisionObjectType(ECollisionChannel Channel);
	void SetCollisionProfileName(class FName InCollisionProfileName, bool bUpdateOverlaps);
	void SetCollisionResponseToAllChannels(ECollisionResponse NewResponse);
	void SetCollisionResponseToChannel(ECollisionChannel Channel, ECollisionResponse NewResponse);
	void SetConstraintMode(EDOFMode ConstraintMode);
	void SetCullDistance(float NewCullDistance);
	void SetCullScreenSpaceSize(float NewCullScreenSpaceSize);
	void SetCustomDepthStencilValue(int32_t Value);
	void SetCustomDepthStencilWriteMask(ERendererStencilMask WriteMaskBit);
	void SetCustomPrimitiveDataFloat(int32_t DataIndex, float Value);
	void SetCustomPrimitiveDataVector2(int32_t DataIndex, const struct FVector2D& Value);
	void SetCustomPrimitiveDataVector3(int32_t DataIndex, const struct FVector& Value);
	void SetCustomPrimitiveDataVector4(int32_t DataIndex, const struct FVector4& Value);
	void SetDefaultCustomPrimitiveDataFloat(int32_t DataIndex, float Value);
	void SetDefaultCustomPrimitiveDataVector2(int32_t DataIndex, const struct FVector2D& Value);
	void SetDefaultCustomPrimitiveDataVector3(int32_t DataIndex, const struct FVector& Value);
	void SetDefaultCustomPrimitiveDataVector4(int32_t DataIndex, const struct FVector4& Value);
	void SetEnableGravity(bool bGravityEnabled);
	void SetExcludeFromLightAttachmentGroup(bool bInExcludeFromLightAttachmentGroup);
	void SetGenerateOverlapEvents(bool bInGenerateOverlapEvents);
	void SetHiddenInSceneCapture(bool bValue);
	void SetLightAttachmentsAsGroup(bool bInLightAttachmentsAsGroup);
	void SetLightingChannels(bool bChannel0, bool bChannel1, bool bChannel2);
	void SetLinearDamping(float InDamping);
	void SetMassOverrideInKg(class FName BoneName, float MassInKg, bool bOverrideMass);
	void SetMassScale(class FName BoneName, float InMassScale);
	void SetMaterial(int32_t ElementIndex, class UMaterialInterface* Material);
	void SetMaterialByName(class FName MaterialSlotName, class UMaterialInterface* Material);
	void SetNotifyRigidBodyCollision(bool bNewNotifyRigidBodyCollision);
	void SetOnlyOwnerSee(bool bNewOnlyOwnerSee);
	void SetOwnerNoSee(bool bNewOwnerNoSee);
	void SetPhysicsAngularVelocity(const struct FVector& NewAngVel, bool bAddToCurrent, class FName BoneName);
	void SetPhysicsAngularVelocityInDegrees(const struct FVector& NewAngVel, bool bAddToCurrent, class FName BoneName);
	void SetPhysicsAngularVelocityInRadians(const struct FVector& NewAngVel, bool bAddToCurrent, class FName BoneName);
	void SetPhysicsLinearVelocity(const struct FVector& NewVel, bool bAddToCurrent, class FName BoneName);
	void SetPhysicsMaxAngularVelocity(float NewMaxAngVel, bool bAddToCurrent, class FName BoneName);
	void SetPhysicsMaxAngularVelocityInDegrees(float NewMaxAngVel, bool bAddToCurrent, class FName BoneName);
	void SetPhysicsMaxAngularVelocityInRadians(float NewMaxAngVel, bool bAddToCurrent, class FName BoneName);
	void SetPhysMaterialOverride(class UPhysicalMaterial* NewPhysMaterial);
	void SetReceivesDecals(bool bNewReceivesDecals);
	void SetRenderCustomDepth(bool bValue);
	void SetRenderInMainPass(bool bValue);
	void SetSimulatePhysics(bool bSimulate);
	void SetSingleSampleShadowFromStationaryLights(bool bNewSingleSampleShadowFromStationaryLights);
	void SetTranslucencySortDistanceOffset(float NewTranslucencySortDistanceOffset);
	void SetTranslucentSortPriority(int32_t NewTranslucentSortPriority);
	void SetUseCCD(bool InUseCCD, class FName BoneName);
	void SetVisibleInSceneCaptureOnly(bool bValue);
	void SetWalkableSlopeOverride(const struct FWalkableSlopeOverride& NewOverride);
	void WakeAllRigidBodies();
	void WakeRigidBody(class FName BoneName);

	bool CanCharacterStepUp(class APawn* Pawn) const;
	float GetAngularDamping() const;
	struct FVector GetCenterOfMass(class FName BoneName) const;
	float GetClosestPointOnCollision(const struct FVector& Point, struct FVector* OutPointOnBody, class FName BoneName) const;
	ECollisionEnabled GetCollisionEnabled() const;
	ECollisionChannel GetCollisionObjectType() const;
	class FName GetCollisionProfileName() const;
	ECollisionResponse GetCollisionResponseToChannel(ECollisionChannel Channel) const;
	bool GetGenerateOverlapEvents() const;
	struct FVector GetInertiaTensor(class FName BoneName) const;
	float GetLinearDamping() const;
	float GetMass() const;
	float GetMassScale(class FName BoneName) const;
	class UMaterialInterface* GetMaterial(int32_t ElementIndex);
	class UMaterialInterface* GetMaterialFromCollisionFaceIndex(int32_t FaceIndex, int32_t* SectionIndex) const;
	int32_t GetNumMaterials() const;
	void GetOverlappingActors(TArray<class AActor*>* OverlappingActors, class AActor ClassFilter) const;
	void GetOverlappingComponents(TArray<class UPrimitiveComponent*>* OutOverlappingComponents) const;
	struct FVector GetPhysicsAngularVelocity(class FName BoneName) const;
	struct FVector GetPhysicsAngularVelocityInDegrees(class FName BoneName) const;
	struct FVector GetPhysicsAngularVelocityInRadians(class FName BoneName) const;
	const struct FWalkableSlopeOverride GetWalkableSlopeOverride() const;
	bool IsGravityEnabled() const;
	bool IsOverlappingActor(const class AActor* Other) const;
	bool IsOverlappingComponent(const class UPrimitiveComponent* OtherComp) const;
	bool K2_IsCollisionEnabled() const;
	bool K2_IsPhysicsCollisionEnabled() const;
	bool K2_IsQueryCollisionEnabled() const;
	struct FVector ScaleByMomentOfInertia(const struct FVector& InputVector, class FName BoneName) const;
	bool WasRecentlyRendered(float Tolerance) const;

};
class UMeshComponent : public UPrimitiveComponent
{
public:
	TArray<class UMaterialInterface*>                  OverrideMaterials;                                          // 0x0458   (0x0010)  
	unsigned char                                      UnknownData00_6[0x10];                                      // 0x0468   (0x0010)  MISSED
	bool                                               bEnableMaterialParameterCaching : 1;                        // 0x0478:0 (0x0001)  
	unsigned char                                      UnknownData01_7[0x7];                                       // 0x0479   (0x0007)  MISSED


	void PrestreamTextures(float Seconds, bool bPrioritizeCharacterTextures, int32_t CinematicTextureGroups);
	void SetScalarParameterValueOnMaterials(const class FName ParameterName, const float ParameterValue);
	void SetVectorParameterValueOnMaterials(const class FName ParameterName, const struct FVector& ParameterValue);

	int32_t GetMaterialIndex(class FName MaterialSlotName) const;
	TArray<class UMaterialInterface*> GetMaterials();
	TArray<class FName> GetMaterialSlotNames() const;
	bool IsMaterialSlotNameValid(class FName MaterialSlotName) const;
};

class USkinnedMeshComponent : public UMeshComponent
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x0480   (0x0008)  MISSED
	class USkeletalMesh* SkeletalMesh;                                               // 0x0488   (0x0008)  
	class USkinnedMeshComponent*       MasterPoseComponent;                                        // 0x0490   (0x0008)  
	TArray<ESkinCacheUsage>                            SkinCacheUsage;                                             // 0x0498   (0x0010)  
	TArray<struct FVertexOffsetUsage>                         VertexOffsetUsage;                                          // 0x04A8   (0x0010)  
	unsigned char                                      UnknownData01_6[0xF8];                                      // 0x04B8   (0x00F8)  MISSED
	class UPhysicsAsset* PhysicsAssetOverride;                                       // 0x05B0   (0x0008)  
	int32_t                                            ForcedLodModel;                                             // 0x05B8   (0x0004)  
	int32_t                                            MinLodModel;                                                // 0x05BC   (0x0004)  
	unsigned char                                      UnknownData02_6[0x8];                                       // 0x05C0   (0x0008)  MISSED
	float                                              StreamingDistanceMultiplier;                                // 0x05C8   (0x0004)  
	unsigned char                                      UnknownData03_6[0xC];                                       // 0x05CC   (0x000C)  MISSED
	TArray<struct FSkelMeshComponentLODInfo>                  LODInfo;                                                    // 0x05D8   (0x0010)  
	unsigned char                                      UnknownData04_6[0x24];                                      // 0x05E8   (0x0024)  MISSED
	EVisibilityBasedAnimTickOption                     VisibilityBasedAnimTickOption;                              // 0x060C   (0x0001)  
	unsigned char                                      UnknownData05_6[0x1];                                       // 0x060D   (0x0001)  MISSED
	unsigned char                                      UnknownBit06 : 1;                                           // 0x060E:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit07 : 1;                                           // 0x060E:1 (0x0001)  MISSED
	unsigned char                                      UnknownBit08 : 1;                                           // 0x060E:2 (0x0001)  MISSED
	bool                                               bOverrideMinLod : 1;                                        // 0x060E:3 (0x0001)  
	bool                                               bUseBoundsFromMasterPoseComponent : 1;                      // 0x060E:4 (0x0001)  
	bool                                               bForceWireframe : 1;                                        // 0x060E:5 (0x0001)  
	bool                                               bDisplayBones : 1;                                          // 0x060E:6 (0x0001)  
	bool                                               bDisableMorphTarget : 1;                                    // 0x060E:7 (0x0001)  
	bool                                               bHideSkin : 1;                                              // 0x060F:0 (0x0001)  
	bool                                               bPerBoneMotionBlur : 1;                                     // 0x060F:1 (0x0001)  
	bool                                               bComponentUseFixedSkelBounds : 1;                           // 0x060F:2 (0x0001)  
	bool                                               bConsiderAllBodiesForBounds : 1;                            // 0x060F:3 (0x0001)  
	bool                                               bSyncAttachParentLOD : 1;                                   // 0x060F:4 (0x0001)  
	bool                                               bCanHighlightSelectedSections : 1;                          // 0x060F:5 (0x0001)  
	bool                                               bRecentlyRendered : 1;                                      // 0x060F:6 (0x0001)  
	bool                                               bCastCapsuleDirectShadow : 1;                               // 0x060F:7 (0x0001)  
	bool                                               bCastCapsuleIndirectShadow : 1;                             // 0x0610:0 (0x0001)  
	bool                                               bCPUSkinning : 1;                                           // 0x0610:1 (0x0001)  
	bool                                               bEnableUpdateRateOptimizations : 1;                         // 0x0610:2 (0x0001)  
	bool                                               bDisplayDebugUpdateRateOptimizations : 1;                   // 0x0610:3 (0x0001)  
	bool                                               bRenderStatic : 1;                                          // 0x0610:4 (0x0001)  
	bool                                               bIgnoreMasterPoseComponentLOD : 1;                          // 0x0610:5 (0x0001)  
	unsigned char                                      UnknownBit09 : 1;                                           // 0x0610:6 (0x0001)  MISSED
	unsigned char                                      UnknownBit10 : 1;                                           // 0x0610:7 (0x0001)  MISSED
	bool                                               bCachedLocalBoundsUpToDate : 1;                             // 0x0611:0 (0x0001)  
	unsigned char                                      UnknownBit11 : 1;                                           // 0x0611:1 (0x0001)  MISSED
	bool                                               bForceMeshObjectUpdate : 1;                                 // 0x0611:2 (0x0001)  
	unsigned char                                      UnknownData12_5[0x2];                                       // 0x0612   (0x0002)  MISSED
	float                                              CapsuleIndirectShadowMinVisibility;                         // 0x0614   (0x0004)  
	unsigned char                                      UnknownData13_6[0x10];                                      // 0x0618   (0x0010)  MISSED
	char                                    CachedWorldSpaceBounds[0x1C];                                     // 0x0628   (0x001C)  
	unsigned char                                      UnknownData14_6[0xC];                                       // 0x0644   (0x000C)  MISSED
	char                                             CachedWorldToLocalTransform[0x40];                                // 0x0650   (0x0040)  
	unsigned char                                      UnknownData15_7[0x20];                                      // 0x0690   (0x0020)  MISSED


	void ClearSkinWeightOverride(int32_t LODIndex);
	void ClearSkinWeightProfile();
	void ClearVertexColorOverride(int32_t LODIndex);
	struct FVector GetRefPosePosition(int32_t BoneIndex);
	void HideBoneByName(class FName BoneName, EPhysBodyOp PhysBodyOption);
	bool IsBoneHiddenByName(class FName BoneName);
	bool IsMaterialSectionShown(int32_t MaterialID, int32_t LODIndex);
	void SetCapsuleIndirectShadowMinVisibility(float NewValue);
	void SetCastCapsuleDirectShadow(bool bNewValue);
	void SetCastCapsuleIndirectShadow(bool bNewValue);
	void SetForcedLOD(int32_t InNewForcedLOD);
	void SetMasterPoseComponent(class USkinnedMeshComponent* NewMasterBoneComponent, bool bForceUpdate);
	void SetMinLOD(int32_t InNewMinLOD);
	void SetPhysicsAsset(class UPhysicsAsset* NewPhysicsAsset, bool bForceReInit);
	void SetPostSkinningOffsets(int32_t LODIndex, const TArray<struct FVector>& Offsets);
	void SetPreSkinningOffsets(int32_t LODIndex, const TArray<struct FVector>& Offsets);
	void SetRenderStatic(bool bNewValue);
	void SetSkeletalMesh(class USkeletalMesh* NewMesh, bool bReinitPose);
	void SetSkinWeightOverride(int32_t LODIndex, const TArray<struct FSkelMeshSkinWeightInfo>& SkinWeights);
	bool SetSkinWeightProfile(class FName InProfileName);
	void SetVertexColorOverride_LinearColor(int32_t LODIndex, const TArray<struct FLinearColor>& VertexColors);
	void SetVertexOffsetUsage(int32_t LODIndex, int32_t Usage);
	void ShowAllMaterialSections(int32_t LODIndex);
	void ShowMaterialSection(int32_t MaterialID, int32_t SectionIndex, bool bShow, int32_t LODIndex);
	void TransformFromBoneSpace(class FName BoneName, const struct FVector& InPosition, const struct FRotator& InRotation, struct FVector* OutPosition, struct FRotator* OutRotation);
	void UnHideBoneByName(class FName BoneName);
	void UnloadSkinWeightProfile(class FName InProfileName);

	bool BoneIsChildOf(class FName BoneName, class FName ParentBoneName) const;
	class FName FindClosestBone_K2(const struct FVector& TestLocation, struct FVector* BoneLocation, float IgnoreScale, bool bRequirePhysicsAsset) const;
	int32_t GetBoneIndex(class FName BoneName) const;
	class FName GetBoneName(int32_t BoneIndex);
	class FName GetCurrentSkinWeightProfileName() const;
	struct FTransform GetDeltaTransformFromRefPose(class FName BoneName, class FName BaseName) const;
	int32_t GetForcedLOD() const;
	int32_t GetNumBones() const;
	int32_t GetNumLODs() const;
	class FName GetParentBone(class FName BoneName) const;
	class FName GetSocketBoneName(class FName InSocketName) const;
	bool GetTwistAndSwingAngleOfDeltaRotationFromRefPose(class FName BoneName, float* OutTwistAngle, float* OutSwingAngle) const;
	int32_t GetVertexOffsetUsage(int32_t LODIndex) const;
	bool IsUsingSkinWeightProfile() const;
	void TransformToBoneSpace(class FName BoneName, const struct FVector& InPosition, const struct FRotator& InRotation, struct FVector* OutPosition, struct FRotator* OutRotation) const;
};



class USkeletalMeshComponent : public USkinnedMeshComponent
{
public:
	class UAnimBlueprintGeneratedClass* AnimBlueprintGeneratedClass;                                // 0x06B0   (0x0008)  
	class UClass* AnimClass;                                                  // 0x06B8   (0x0008)  
	class UAnimInstance* AnimScriptInstance;                                         // 0x06C0   (0x0008)  
	class UAnimInstance* PostProcessAnimInstance;                                    // 0x06C8   (0x0008)  
	char                           AnimationData[0x18];                                              // 0x06D0   (0x0018)  
	unsigned char                                      UnknownData00_6[0x10];                                      // 0x06E8   (0x0010)  MISSED
	FVector                                            RootBoneTranslation;                                        // 0x06F8   (0x000C)  
	FVector                                            LineCheckBoundsScale;                                       // 0x0704   (0x000C)  
	unsigned char                                      UnknownData01_6[0x30];                                      // 0x0710   (0x0030)  MISSED
	TArray<class UAnimInstance*>                       LinkedInstances;                                            // 0x0740   (0x0010)  
	TArray<FTransform>                                 CachedBoneSpaceTransforms;                                  // 0x0750   (0x0010)  
	TArray<FTransform>                                 CachedComponentSpaceTransforms;                             // 0x0760   (0x0010)  
	unsigned char                                      UnknownData02_6[0x150];                                     // 0x0770   (0x0150)  MISSED
	float                                              GlobalAnimRateScale;                                        // 0x08C0   (0x0004)  
	EKinematicBonesUpdateToPhysics        KinematicBonesUpdateType;                                   // 0x08C4   (0x0001)  
	EPhysicsTransformUpdateMode           PhysicsTransformUpdateMode;                                 // 0x08C5   (0x0001)  
	unsigned char                                      UnknownData03_6[0x1];                                       // 0x08C6   (0x0001)  MISSED
	EAnimationMode                        AnimationMode;                                              // 0x08C7   (0x0001)  
	unsigned char                                      UnknownData04_6[0x1];                                       // 0x08C8   (0x0001)  MISSED
	bool                                               bDisablePostProcessBlueprint : 1;                           // 0x08C9:0 (0x0001)  
	unsigned char                                      UnknownBit05 : 1;                                           // 0x08C9:1 (0x0001)  MISSED
	bool                                               bUpdateOverlapsOnAnimationFinalize : 1;                     // 0x08C9:2 (0x0001)  
	unsigned char                                      UnknownBit06 : 1;                                           // 0x08C9:3 (0x0001)  MISSED
	bool                                               bHasValidBodies : 1;                                        // 0x08C9:4 (0x0001)  
	bool                                               bBlendPhysics : 1;                                          // 0x08C9:5 (0x0001)  
	bool                                               bEnablePhysicsOnDedicatedServer : 1;                        // 0x08C9:6 (0x0001)  
	bool                                               bUpdateJointsFromAnimation : 1;                             // 0x08C9:7 (0x0001)  
	bool                                               bDisableClothSimulation : 1;                                // 0x08CA:0 (0x0001)  
	unsigned char                                      UnknownData07_3[0x5];                                       // 0x08CB   (0x0005)  MISSED
	unsigned char                                      UnknownBit08 : 1;                                           // 0x08D0:0 (0x0001)  MISSED
	bool                                               bDisableRigidBodyAnimNode : 1;                              // 0x08D0:1 (0x0001)  
	bool                                               bAllowAnimCurveEvaluation : 1;                              // 0x08D0:2 (0x0001)  
	bool                                               bDisableAnimCurves : 1;                                     // 0x08D0:3 (0x0001)  
	unsigned char                                      UnknownBit09 : 1;                                           // 0x08D0:4 (0x0001)  MISSED
	unsigned char                                      UnknownBit10 : 1;                                           // 0x08D0:5 (0x0001)  MISSED
	unsigned char                                      UnknownBit11 : 1;                                           // 0x08D0:6 (0x0001)  MISSED
	bool                                               bCollideWithEnvironment : 1;                                // 0x08D0:7 (0x0001)  
	bool                                               bCollideWithAttachedChildren : 1;                           // 0x08D1:0 (0x0001)  
	bool                                               bLocalSpaceSimulation : 1;                                  // 0x08D1:1 (0x0001)  
	bool                                               bResetAfterTeleport : 1;                                    // 0x08D1:2 (0x0001)  
	unsigned char                                      UnknownBit12 : 1;                                           // 0x08D1:3 (0x0001)  MISSED
	bool                                               bDeferKinematicBoneUpdate : 1;                              // 0x08D1:4 (0x0001)  
	bool                                               bNoSkeletonUpdate : 1;                                      // 0x08D1:5 (0x0001)  
	bool                                               bPauseAnims : 1;                                            // 0x08D1:6 (0x0001)  
	bool                                               bUseRefPoseOnInitAnim : 1;                                  // 0x08D1:7 (0x0001)  
	bool                                               bEnablePerPolyCollision : 1;                                // 0x08D2:0 (0x0001)  
	bool                                               bForceRefpose : 1;                                          // 0x08D2:1 (0x0001)  
	bool                                               bOnlyAllowAutonomousTickPose : 1;                           // 0x08D2:2 (0x0001)  
	bool                                               bIsAutonomousTickPose : 1;                                  // 0x08D2:3 (0x0001)  
	bool                                               bOldForceRefPose : 1;                                       // 0x08D2:4 (0x0001)  
	bool                                               bShowPrePhysBones : 1;                                      // 0x08D2:5 (0x0001)  
	bool                                               bRequiredBonesUpToDate : 1;                                 // 0x08D2:6 (0x0001)  
	bool                                               bAnimTreeInitialised : 1;                                   // 0x08D2:7 (0x0001)  
	bool                                               bIncludeComponentLocationIntoBounds : 1;                    // 0x08D3:0 (0x0001)  
	bool                                               bEnableLineCheckWithBounds : 1;                             // 0x08D3:1 (0x0001)  
	bool                                               bPropagateCurvesToSlaves : 1;                               // 0x08D3:2 (0x0001)  
	bool                                               bSkipKinematicUpdateWhenInterpolating : 1;                  // 0x08D3:3 (0x0001)  
	bool                                               bSkipBoundsUpdateWhenInterpolating : 1;                     // 0x08D3:4 (0x0001)  
	unsigned char                                      UnknownBit13 : 1;                                           // 0x08D3:5 (0x0001)  MISSED
	unsigned char                                      UnknownBit14 : 1;                                           // 0x08D3:6 (0x0001)  MISSED
	bool                                               bNeedsQueuedAnimEventsDispatched : 1;                       // 0x08D3:7 (0x0001)  
	unsigned char                                      UnknownData15_5[0x2];                                       // 0x08D4   (0x0002)  MISSED
	uint16_t                                           CachedAnimCurveUidVersion;                                  // 0x08D6   (0x0002)  
	float                                              ClothBlendWeight;                                           // 0x08D8   (0x0004)  
	bool                                               bWaitForParallelClothTask;                                  // 0x08DC   (0x0001)  
	unsigned char                                      UnknownData16_6[0x3];                                       // 0x08DD   (0x0003)  MISSED
	TArray<FName>                                      DisallowedAnimCurves;                                       // 0x08E0   (0x0010)  
	class UBodySetup* BodySetup;                                                  // 0x08F0   (0x0008)  
	unsigned char                                      UnknownData17_6[0x8];                                       // 0x08F8   (0x0008)  MISSED
	char OnConstraintBroken[0x10];                                  // 0x0900   (0x0010)  
	class UClass* ClothingSimulationFactory;                                  // 0x0910   (0x0008)  
	unsigned char                                      UnknownData18_6[0xD0];                                      // 0x0918   (0x00D0)  MISSED
	float                                              TeleportDistanceThreshold;                                  // 0x09E8   (0x0004)  
	float                                              TeleportRotationThreshold;                                  // 0x09EC   (0x0004)  
	unsigned char                                      UnknownData19_6[0x8];                                       // 0x09F0   (0x0008)  MISSED
	uint32_t                                           LastPoseTickFrame;                                          // 0x09F8   (0x0004)  
	unsigned char                                      UnknownData20_6[0x54];                                      // 0x09FC   (0x0054)  MISSED
	class UClothingSimulationInteractor* ClothingInteractor;                                         // 0x0A50   (0x0008)  
	unsigned char                                      UnknownData21_6[0xC8];                                      // 0x0A58   (0x00C8)  MISSED
	char OnAnimInitialized[0x10];                                   // 0x0B20   (0x0010)  
	unsigned char                                      UnknownData22_7[0x3A8];                                     // 0x0B30   (0x03A8)  MISSED


	void AccumulateAllBodiesBelowPhysicsBlendWeight(const class FName& InBoneName, float AddPhysicsBlendWeight, bool bSkipCustomPhysicsType);
	void AddForceToAllBodiesBelow(const struct FVector& Force, class FName BoneName, bool bAccelChange, bool bIncludeSelf);
	void AddImpulseToAllBodiesBelow(const struct FVector& Impulse, class FName BoneName, bool bVelChange, bool bIncludeSelf);
	void AllowAnimCurveEvaluation(class FName NameOfCurve, bool bAllow);
	void BindClothToMasterPoseComponent();
	void BreakConstraint(const struct FVector& Impulse, const struct FVector& HitLocation, class FName InBoneName);
	void ClearMorphTargets();
	class FName FindConstraintBoneName(int32_t ConstraintIndex);
	void ForceClothNextUpdateTeleport();
	void ForceClothNextUpdateTeleportAndReset();
	class UClass* GetAnimClass();
	void GetCurrentJointAngles(class FName InBoneName, float* Swing1Angle, float* TwistAngle, float* Swing2Angle);
	bool GetFloatAttribute(const class FName& BoneName, const class FName& AttributeName, float DefaultValue, float* OutValue, ECustomBoneAttributeLookup LookupType);
	bool GetFloatAttribute_Ref(const class FName& BoneName, const class FName& AttributeName, float& OutValue, ECustomBoneAttributeLookup LookupType);
	bool GetIntegerAttribute(const class FName& BoneName, const class FName& AttributeName, int32_t DefaultValue, int32_t* OutValue, ECustomBoneAttributeLookup LookupType);
	bool GetIntegerAttribute_Ref(const class FName& BoneName, const class FName& AttributeName, int32_t& OutValue, ECustomBoneAttributeLookup LookupType);
	bool GetStringAttribute(const class FName& BoneName, const class FName& AttributeName, const class FString& DefaultValue, class FString* OutValue, ECustomBoneAttributeLookup LookupType);
	bool GetStringAttribute_Ref(const class FName& BoneName, const class FName& AttributeName, class FString& OutValue, ECustomBoneAttributeLookup LookupType);
	bool IsBodyGravityEnabled(class FName BoneName);
	void LinkAnimClassLayers(class UAnimInstance InClass);
	void LinkAnimGraphByTag(class FName InTag, class UAnimInstance InClass);
	void OverrideAnimationData(class UAnimationAsset* InAnimToPlay, bool bIsLooping, bool bIsPlaying, float Position, float PlayRate);
	void Play(bool bLooping);
	void PlayAnimation(class UAnimationAsset* NewAnimToPlay, bool bLooping);
	void ResetAllBodiesSimulatePhysics();
	void ResetAllowedAnimCurveEvaluation();
	void ResetAnimInstanceDynamics(ETeleportType InTeleportType);
	void ResetClothTeleportMode();
	void ResumeClothingSimulation();
	void SetAllBodiesBelowPhysicsBlendWeight(const class FName& InBoneName, float PhysicsBlendWeight, bool bSkipCustomPhysicsType, bool bIncludeSelf);
	void SetAllBodiesBelowSimulatePhysics(const class FName& InBoneName, bool bNewSimulate, bool bIncludeSelf);
	void SetAllBodiesPhysicsBlendWeight(float PhysicsBlendWeight, bool bSkipCustomPhysicsType);
	void SetAllBodiesSimulatePhysics(bool bNewSimulate);
	void SetAllMotorsAngularDriveParams(float InSpring, float InDamping, float InForceLimit, bool bSkipCustomPhysicsType);
	void SetAllMotorsAngularPositionDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, bool bSkipCustomPhysicsType);
	void SetAllMotorsAngularVelocityDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, bool bSkipCustomPhysicsType);
	void SetAllowAnimCurveEvaluation(bool bInAllow);
	void SetAllowedAnimCurvesEvaluation(const TArray<class FName>& List, bool bAllow);
	void SetAllowRigidBodyAnimNode(bool bInAllow, bool bReinitAnim);
	void SetAngularLimits(class FName InBoneName, float Swing1LimitAngle, float TwistLimitAngle, float Swing2LimitAngle);
	void SetAnimation(class UAnimationAsset* NewAnimToPlay);
	void SetAnimationMode(EAnimationMode InAnimationMode);
	void SetAnimClass(class UClass* NewClass);
	void SetBodyNotifyRigidBodyCollision(bool bNewNotifyRigidBodyCollision, class FName BoneName);
	void SetClothMaxDistanceScale(float Scale);
	void SetConstraintProfile(class FName JointName, class FName ProfileName, bool bDefaultIfNotFound);
	void SetConstraintProfileForAll(class FName ProfileName, bool bDefaultIfNotFound);
	void SetDisableAnimCurves(bool bInDisableAnimCurves);
	void SetDisablePostProcessBlueprint(bool bInDisablePostProcess);
	void SetEnableBodyGravity(bool bEnableGravity, class FName BoneName);
	void SetEnableGravityOnAllBodiesBelow(bool bEnableGravity, class FName BoneName, bool bIncludeSelf);
	void SetEnablePhysicsBlending(bool bNewBlendPhysics);
	void SetMorphTarget(class FName MorphTargetName, float Value, bool bRemoveZeroWeight);
	void SetNotifyRigidBodyCollisionBelow(bool bNewNotifyRigidBodyCollision, class FName BoneName, bool bIncludeSelf);
	void SetPhysicsBlendWeight(float PhysicsBlendWeight);
	void SetPlayRate(float Rate);
	void SetPosition(float InPos, bool bFireNotifies);
	void SetTeleportDistanceThreshold(float Threshold);
	void SetTeleportRotationThreshold(float Threshold);
	void SetUpdateAnimationInEditor(const bool NewUpdateState);
	void SetUpdateClothInEditor(const bool NewUpdateState);
	void SnapshotPose(struct FPoseSnapshot& Snapshot);
	void Stop();
	void SuspendClothingSimulation();
	void TermBodiesBelow(class FName ParentBoneName);
	void ToggleDisablePostProcessBlueprint();
	void UnbindClothFromMasterPoseComponent(bool bRestoreSimulationSpace);
	void UnlinkAnimClassLayers(class UAnimInstance InClass);

	bool GetAllowedAnimCurveEvaluate() const;
	bool GetAllowRigidBodyAnimNode() const;
	EAnimationMode GetAnimationMode() const;
	class UAnimInstance* GetAnimInstance() const;
	float GetBoneMass(class FName BoneName, bool bScaleMass) const;
	class UClothingSimulationInteractor* GetClothingSimulationInteractor() const;
	float GetClothMaxDistanceScale() const;
	bool GetDisableAnimCurves() const;
	bool GetDisablePostProcessBlueprint() const;
	class UAnimInstance* GetLinkedAnimGraphInstanceByTag(class FName InTag) const;
	void GetLinkedAnimGraphInstancesByTag(class FName InTag, TArray<class UAnimInstance*>* OutLinkedInstances) const;
	class UAnimInstance* GetLinkedAnimLayerInstanceByClass(class UAnimInstance InClass) const;
	class UAnimInstance* GetLinkedAnimLayerInstanceByGroup(class FName InGroup) const;
	float GetMorphTarget(class FName MorphTargetName) const;
	float GetPlayRate() const;
	float GetPosition() const;
	class UAnimInstance* GetPostProcessInstance() const;
	struct FVector GetSkeletalCenterOfMass() const;
	float GetTeleportDistanceThreshold() const;
	float GetTeleportRotationThreshold() const;
	bool HasValidAnimationInstance() const;
	bool IsClothingSimulationSuspended() const;
	bool IsPlaying() const;
	bool K2_GetClosestPointOnPhysicsAsset(const struct FVector& WorldPosition, struct FVector* ClosestWorldPosition, struct FVector* Normal, class FName* BoneName, float* Distance) const;
};

class UScriptViewportClient : public UObject
{
public:
	unsigned char                                      UnknownData00_1[0x10];                                      // 0x0028   (0x0010)  MISSED
};

class UGameViewportClient : public UScriptViewportClient
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x0038   (0x0008)  MISSED
	class UConsole* ViewportConsole;                                            // 0x0040   (0x0008)  
	TArray<struct FDebugDisplayProperty>                      DebugProperties;                                            // 0x0048   (0x0010)  
	unsigned char                                      UnknownData01_6[0x10];                                      // 0x0058   (0x0010)  MISSED
	int32_t                                            MaxSplitscreenPlayers;                                      // 0x0068   (0x0004)  
	unsigned char                                      UnknownData02_6[0xC];                                       // 0x006C   (0x000C)  MISSED
	class UWorld* World;                                                      // 0x0078   (0x0008)  
	class UGameInstance* GameInstance;                                               // 0x0080   (0x0008)  
	unsigned char                                      UnknownData03_7[0x2D8];                                     // 0x0088   (0x02D8)  MISSED


	/// Functions
	// Function /Script/Engine.GameViewportClient.SSSwapControllers
	// void SSSwapControllers();                                                                                                // [0xb51130] Exec|Native|Public   
	// Function /Script/Engine.GameViewportClient.ShowTitleSafeArea
	// void ShowTitleSafeArea();                                                                                                // [0x1434030] Exec|Native|Public   
	// Function /Script/Engine.GameViewportClient.SetConsoleTarget
	// void SetConsoleTarget(int32_t PlayerIndex);                                                                              // [0x337ae70] Exec|Native|Public   
};

class AActor : public UObject
{
public:
	char                                 PrimaryActorTick[0x30];                                           // 0x0028   (0x0030)  
	bool                                               bNetTemporary : 1;                                          // 0x0058:0 (0x0001)  
	bool                                               bNetStartup : 1;                                            // 0x0058:1 (0x0001)  
	bool                                               bOnlyRelevantToOwner : 1;                                   // 0x0058:2 (0x0001)  
	bool                                               bAlwaysRelevant : 1;                                        // 0x0058:3 (0x0001)  
	bool                                               bReplicateMovement : 1;                                     // 0x0058:4 (0x0001)  
	bool                                               bHidden : 1;                                                // 0x0058:5 (0x0001)  
	bool                                               bTearOff : 1;                                               // 0x0058:6 (0x0001)  
	bool                                               bForceNetAddressable : 1;                                   // 0x0058:7 (0x0001)  
	bool                                               bExchangedRoles : 1;                                        // 0x0059:0 (0x0001)  
	bool                                               bNetLoadOnClient : 1;                                       // 0x0059:1 (0x0001)  
	bool                                               bNetUseOwnerRelevancy : 1;                                  // 0x0059:2 (0x0001)  
	bool                                               bRelevantForNetworkReplays : 1;                             // 0x0059:3 (0x0001)  
	bool                                               bRelevantForLevelBounds : 1;                                // 0x0059:4 (0x0001)  
	bool                                               bReplayRewindable : 1;                                      // 0x0059:5 (0x0001)  
	bool                                               bAllowTickBeforeBeginPlay : 1;                              // 0x0059:6 (0x0001)  
	bool                                               bAutoDestroyWhenFinished : 1;                               // 0x0059:7 (0x0001)  
	bool                                               bCanBeDamaged : 1;                                          // 0x005A:0 (0x0001)  
	bool                                               bBlockInput : 1;                                            // 0x005A:1 (0x0001)  
	bool                                               bCollideWhenPlacing : 1;                                    // 0x005A:2 (0x0001)  
	bool                                               bFindCameraComponentWhenViewTarget : 1;                     // 0x005A:3 (0x0001)  
	bool                                               bGenerateOverlapEventsDuringLevelStreaming : 1;             // 0x005A:4 (0x0001)  
	bool                                               bIgnoresOriginShifting : 1;                                 // 0x005A:5 (0x0001)  
	bool                                               bEnableAutoLODGeneration : 1;                               // 0x005A:6 (0x0001)  
	bool                                               bIsEditorOnlyActor : 1;                                     // 0x005A:7 (0x0001)  
	bool                                               bActorSeamlessTraveled : 1;                                 // 0x005B:0 (0x0001)  
	bool                                               bReplicates : 1;                                            // 0x005B:1 (0x0001)  
	bool                                               bCanBeInCluster : 1;                                        // 0x005B:2 (0x0001)  
	bool                                               bAllowReceiveTickEventOnDedicatedServer : 1;                // 0x005B:3 (0x0001)  
	unsigned char                                      UnknownBit00 : 1;                                           // 0x005B:4 (0x0001)  MISSED
	unsigned char                                      UnknownBit01 : 1;                                           // 0x005B:5 (0x0001)  MISSED
	unsigned char                                      UnknownBit02 : 1;                                           // 0x005B:6 (0x0001)  MISSED
	unsigned char                                      UnknownBit03 : 1;                                           // 0x005B:7 (0x0001)  MISSED
	unsigned char                                      UnknownBit04 : 1;                                           // 0x005C:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit05 : 1;                                           // 0x005C:1 (0x0001)  MISSED
	unsigned char                                      UnknownBit06 : 1;                                           // 0x005C:2 (0x0001)  MISSED
	bool                                               bActorEnableCollision : 1;                                  // 0x005C:3 (0x0001)  
	bool                                               bActorIsBeingDestroyed : 1;                                 // 0x005C:4 (0x0001)  
	char                         UpdateOverlapsMethodDuringLevelStreaming;                   // 0x005D   (0x0001)  
	char                         DefaultUpdateOverlapsMethodDuringLevelStreaming;            // 0x005E   (0x0001)  
	char                              RemoteRole;                                                 // 0x005F   (0x0001)  
	char                                       ReplicatedMovement[0x34];                                         // 0x0060   (0x0034)  
	float                                              InitialLifeSpan;                                            // 0x0094   (0x0004)  
	float                                              CustomTimeDilation;                                         // 0x0098   (0x0004)  
	unsigned char                                      UnknownData07_6[0x4];                                       // 0x009C   (0x0004)  MISSED
	char                                     AttachmentReplication[0x40];                                      // 0x00A0   (0x0040)  
	class AActor* Owner;                                                      // 0x00E0   (0x0008)  
	char                                              NetDriverName[0x8];                                              // 0x00E8   (0x0008)  
	char                             Role;                                                       // 0x00F0   (0x0001)  
	char                          NetDormancy;                                                // 0x00F1   (0x0001)  
	char                 SpawnCollisionHandlingMethod;                               // 0x00F2   (0x0001)  
	char                     AutoReceiveInput;                                           // 0x00F3   (0x0001)  
	int32_t                                            InputPriority;                                              // 0x00F4   (0x0004)  
	class UInputComponent* InputComponent;                                             // 0x00F8   (0x0008)  
	float                                              NetCullDistanceSquared;                                     // 0x0100   (0x0004)  
	int32_t                                            NetTag;                                                     // 0x0104   (0x0004)  
	float                                              NetUpdateFrequency;                                         // 0x0108   (0x0004)  
	float                                              MinNetUpdateFrequency;                                      // 0x010C   (0x0004)  
	float                                              NetPriority;                                                // 0x0110   (0x0004)  
	unsigned char                                      UnknownData08_6[0x4];                                       // 0x0114   (0x0004)  MISSED
	class APawn* Instigator;                                                 // 0x0118   (0x0008)  
	TArray<class AActor*>                              Children;                                                   // 0x0120   (0x0010)  
	class USceneComponent* RootComponent;                                              // 0x0130   (0x0008)  
	TArray<class AMatineeActor*>                       ControllingMatineeActors;                                   // 0x0138   (0x0010)  
	unsigned char                                      UnknownData09_6[0x8];                                       // 0x0148   (0x0008)  MISSED
	TArray<FName>                                      Layers;                                                     // 0x0150   (0x0010)  
	char        ParentComponent[0x8];                                            // 0x0160   (0x0008)  
	unsigned char                                      UnknownData10_6[0x8];                                       // 0x0168   (0x0008)  MISSED
	TArray<FName>                                      Tags;                                                       // 0x0170   (0x0010)  
	char OnTakeAnyDamage;                                      // 0x0180   (0x0001)  
	char OnTakePointDamage;                                    // 0x0181   (0x0001)  
	char OnTakeRadialDamage;                                   // 0x0182   (0x0001)  
	char OnActorBeginOverlap;                                  // 0x0183   (0x0001)  
	char OnActorEndOverlap;                                    // 0x0184   (0x0001)  
	char OnBeginCursorOver;                                    // 0x0185   (0x0001)  
	char OnEndCursorOver;                                      // 0x0186   (0x0001)  
	char OnClicked;                                            // 0x0187   (0x0001)  
	char OnReleased;                                           // 0x0188   (0x0001)  
	char OnInputTouchBegin;                                    // 0x0189   (0x0001)  
	char OnInputTouchEnd;                                      // 0x018A   (0x0001)  
	char OnInputTouchEnter;                                    // 0x018B   (0x0001)  
	char OnInputTouchLeave;                                    // 0x018C   (0x0001)  
	char OnActorHit;                                           // 0x018D   (0x0001)  
	char OnDestroyed;                                          // 0x018E   (0x0001)  
	char OnEndPlay;                                            // 0x018F   (0x0001)  
	unsigned char                                      UnknownData11_6[0x60];                                      // 0x0190   (0x0060)  MISSED
	TArray<class UActorComponent*>                     InstanceComponents;                                         // 0x01F0   (0x0010)  
	TArray<class UActorComponent*>                     BlueprintCreatedComponents;                                 // 0x0200   (0x0010)  
	unsigned char                                      UnknownData12_7[0x10];                                      // 0x0210   (0x0010)  MISSED

public:

	class UActorComponent* AddComponent(class FName TemplateName, bool bManualAttachment, const struct FTransform& RelativeTransform, const class UObject* ComponentTemplateContext, bool bDeferredFinish);
	class UActorComponent* AddComponentByClass(UActorComponent Class_0, bool bManualAttachment, const struct FTransform& RelativeTransform, bool bDeferredFinish);
	void AddTickPrerequisiteActor(class AActor* PrerequisiteActor);
	void AddTickPrerequisiteComponent(class UActorComponent* PrerequisiteComponent);
	void DetachRootComponentFromParent(bool bMaintainWorldPosition);
	void DisableInput(class APlayerController* PlayerController);
	void EnableInput(class APlayerController* PlayerController);
	void FinishAddComponent(class UActorComponent* Component, bool bManualAttachment, const struct FTransform& RelativeTransform);
	void FlushNetDormancy();
	void ForceNetUpdate();
	bool GetTickableWhenPaused();
	void K2_AddActorLocalOffset(const struct FVector& DeltaLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddActorLocalRotation(const struct FRotator& DeltaRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddActorLocalTransform(const struct FTransform& NewTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddActorWorldOffset(const struct FVector& DeltaLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddActorWorldRotation(const struct FRotator& DeltaRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddActorWorldTransform(const struct FTransform& DeltaTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AddActorWorldTransformKeepScale(const struct FTransform& DeltaTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_AttachRootComponentTo(class USceneComponent* InParent, class FName InSocketName, EAttachLocation AttachLocationType, bool bWeldSimulatedBodies);
	void K2_AttachRootComponentToActor(class AActor* InParentActor, class FName InSocketName, EAttachLocation AttachLocationType, bool bWeldSimulatedBodies);
	void K2_AttachToActor(class AActor* ParentActor, class FName SocketName, EAttachmentRule LocationRule, EAttachmentRule RotationRule, EAttachmentRule ScaleRule, bool bWeldSimulatedBodies);
	void K2_AttachToComponent(class USceneComponent* Parent, class FName SocketName, EAttachmentRule LocationRule, EAttachmentRule RotationRule, EAttachmentRule ScaleRule, bool bWeldSimulatedBodies);
	void K2_DestroyActor();
	void K2_DestroyComponent(class UActorComponent* Component);
	void K2_DetachFromActor(EDetachmentRule LocationRule, EDetachmentRule RotationRule, EDetachmentRule ScaleRule);
	void K2_OnBecomeViewTarget(class APlayerController* PC);
	void K2_OnEndViewTarget(class APlayerController* PC);
	void K2_OnReset();
	bool K2_SetActorLocation(const struct FVector& NewLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	bool K2_SetActorLocationAndRotation(const struct FVector& NewLocation, const struct FRotator& NewRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetActorRelativeLocation(const struct FVector& NewRelativeLocation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetActorRelativeRotation(const struct FRotator& NewRelativeRotation, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	void K2_SetActorRelativeTransform(const struct FTransform& NewRelativeTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	bool K2_SetActorRotation(const struct FRotator& NewRotation, bool bTeleportPhysics);
	bool K2_SetActorTransform(const struct FTransform& NewTransform, bool bSweep, struct FHitResult* SweepHitResult, bool bTeleport);
	bool K2_TeleportTo(const struct FVector& DestLocation, const struct FRotator& DestRotation);
	class UMaterialInstanceDynamic* MakeMIDForMaterial(class UMaterialInterface* Parent);
	void MakeNoise(float Loudness, class APawn* NoiseInstigator, const struct FVector& NoiseLocation, float MaxRange, class FName Tag);
	void OnRep_AttachmentReplication();
	void OnRep_Instigator();
	void OnRep_Owner();
	void OnRep_ReplicatedMovement();
	void OnRep_ReplicateMovement();
	void PrestreamTextures(float Seconds, bool bEnableStreaming, int32_t CinematicTextureGroups);
	void ReceiveActorBeginCursorOver();
	void ReceiveActorBeginOverlap(class AActor* OtherActor);
	void ReceiveActorEndCursorOver();
	void ReceiveActorEndOverlap(class AActor* OtherActor);
	void ReceiveActorOnClicked(const struct FKey& ButtonPressed);
	void ReceiveActorOnInputTouchBegin(const ETouchIndex FingerIndex);
	void ReceiveActorOnInputTouchEnd(const ETouchIndex FingerIndex);
	void ReceiveActorOnInputTouchEnter(const ETouchIndex FingerIndex);
	void ReceiveActorOnInputTouchLeave(const ETouchIndex FingerIndex);
	void ReceiveActorOnReleased(const struct FKey& ButtonReleased);
	void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, class AActor* DamageCauser);
	void ReceiveBeginPlay();
	void ReceiveDestroyed();
	void ReceiveEndPlay(EEndPlayReason EndPlayReason);
	void ReceiveHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, const struct FVector& HitLocation, const struct FVector& HitNormal, const struct FVector& NormalImpulse, const struct FHitResult& Hit);
	void ReceivePointDamage(float Damage, const class UDamageType* DamageType, const struct FVector& HitLocation, const struct FVector& HitNormal, class UPrimitiveComponent* HitComponent, class FName BoneName, const struct FVector& ShotFromDirection, class AController* InstigatedBy, class AActor* DamageCauser, const struct FHitResult& HitInfo);
	void ReceiveRadialDamage(float DamageReceived, const class UDamageType* DamageType, const struct FVector& Origin, const struct FHitResult& HitInfo, class AController* InstigatedBy, class AActor* DamageCauser);
	void ReceiveTick(float DeltaSeconds);
	void RemoveTickPrerequisiteActor(class AActor* PrerequisiteActor);
	void RemoveTickPrerequisiteComponent(class UActorComponent* PrerequisiteComponent);
	void SetActorEnableCollision(bool bNewActorEnableCollision);
	void SetActorHiddenInGame(bool bNewHidden);
	void SetActorRelativeScale3D(const struct FVector& NewRelativeScale);
	void SetActorScale3D(const struct FVector& NewScale3D);
	void SetActorTickEnabled(bool bEnabled);
	void SetActorTickInterval(float TickInterval);
	void SetAutoDestroyWhenFinished(bool bVal);
	void SetLifeSpan(float InLifespan);
	void SetNetDormancy(ENetDormancy NewDormancy);
	void SetOwner(class AActor* NewOwner);
	void SetReplicateMovement(bool bInReplicateMovement);
	void SetReplicates(bool bInReplicates);
	void SetTickableWhenPaused(bool bTickableWhenPaused);
	void SetTickGroup(ETickingGroup NewTickGroup);
	void SnapRootComponentTo(class AActor* InParentActor, class FName InSocketName);
	void TearOff();
	void UserConstructionScript();

	bool ActorHasTag(class FName Tag) const;
	void GetActorBounds(bool bOnlyCollidingComponents, struct FVector& Origin, struct FVector& BoxExtent, bool bIncludeFromChildActors);
	bool GetActorEnableCollision() const;
	void GetActorEyesViewPoint(struct FVector* OutLocation, struct FRotator* OutRotation) const;
	struct FVector GetActorForwardVector() const;
	struct FVector GetActorRelativeScale3D() const;
	struct FVector GetActorRightVector() const;
	struct FVector GetActorScale3D() const;
	float GetActorTickInterval() const;
	float GetActorTimeDilation() const;
	struct FVector GetActorUpVector() const;
	void GetAllChildActors(TArray<class AActor*>* ChildActors, bool bIncludeDescendants) const;
	void GetAttachedActors(TArray<class AActor*>* OutActors, bool bResetArray) const;
	class AActor* GetAttachParentActor() const;
	class FName GetAttachParentSocketName() const;
	class UActorComponent* GetComponentByClass(UActorComponent ComponentClass) const;
	TArray<class UActorComponent*> GetComponentsByInterface(struct IInterface Interface) const;
	TArray<class UActorComponent*> GetComponentsByTag(UActorComponent ComponentClass, class FName Tag) const;
	float GetDistanceTo(const class AActor* OtherActor) const;
	float GetDotProductTo(const class AActor* OtherActor) const;
	float GetGameTimeSinceCreation() const;
	float GetHorizontalDistanceTo(const class AActor* OtherActor) const;
	float GetHorizontalDotProductTo(const class AActor* OtherActor) const;
	float GetInputAxisKeyValue(const struct FKey& InputAxisKey) const;
	float GetInputAxisValue(const class FName InputAxisName) const;
	struct FVector GetInputVectorAxisValue(const struct FKey& InputAxisKey) const;
	class APawn* GetInstigator() const;
	class AController* GetInstigatorController() const;
	float GetLifeSpan() const;
	ENetRole GetLocalRole() const;
	void GetOverlappingActors(TArray<class AActor*>* OverlappingActors,AActor ClassFilter) const;
	void GetOverlappingComponents(TArray<class UPrimitiveComponent*>* OverlappingComponents) const;
	class AActor* GetOwner() const;
	class AActor* GetParentActor() const;
	class UChildActorComponent* GetParentComponent() const;
	ENetRole GetRemoteRole() const;
	float GetSquaredDistanceTo(const class AActor* OtherActor) const;
	float GetSquaredHorizontalDistanceTo(const class AActor* OtherActor) const;
	const struct FTransform GetTransform() const;
	struct FVector GetVelocity() const;
	float GetVerticalDistanceTo(const class AActor* OtherActor) const;
	bool HasAuthority() const;
	bool IsActorBeingDestroyed() const;
	bool IsActorTickEnabled() const;
	bool IsChildActor() const;
	bool IsOverlappingActor(const class AActor* Other) const;
	struct FVector K2_GetActorLocation();
	struct FRotator K2_GetActorRotation();
	TArray<class UActorComponent*> K2_GetComponentsByClass(UActorComponent ComponentClass) const;
	class USceneComponent* K2_GetRootComponent() const;
	bool WasRecentlyRendered(float Tolerance) const;
};

struct FHitResult
{
public:
	int32_t                                         FaceIndex;                                         // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Time;                                              // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Distance;                                          // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char                    Location[0xC];                                          // 0x000C(0x000C)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char                    ImpactPoint[0xC];                                       // 0x0018(0x000C)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char              Normal[0xC];                                            // 0x0024(0x000C)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char              ImpactNormal[0xC];                                      // 0x0030(0x000C)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char                    TraceStart[0xC];                                        // 0x003C(0x000C)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char                    TraceEnd[0xC];                                          // 0x0048(0x000C)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PenetrationDepth;                                  // 0x0054(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32_t                                         Item;                                              // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8_t                                         ElementIndex;                                      // 0x005C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8_t                                         bBlockingHit : 1;                                  // 0x005D(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8_t                                         bStartPenetrating : 1;                             // 0x005D(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8_t                                         Pad_5E[0x2];                                       // 0x005E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	char       PhysMaterial[0x8];                                      // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor                  Actor;                                             // 0x0068(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UPrimitiveComponent     Component;                                         // 0x0070(0x0008)(ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EPhysicalSurface                              ShapeSurfaceType;                                  // 0x0078(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8_t                                         Pad_79[0x3];                                       // 0x0079(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   BoneName;                                          // 0x007C(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   MyBoneName;                                        // 0x0084(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

class APawn : public AActor
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x0220   (0x0008)  MISSED
	bool                                               bUseControllerRotationPitch : 1;                            // 0x0228:0 (0x0001)  
	bool                                               bUseControllerRotationYaw : 1;                              // 0x0228:1 (0x0001)  
	bool                                               bUseControllerRotationRoll : 1;                             // 0x0228:2 (0x0001)  
	bool                                               bCanAffectNavigationGeneration : 1;                         // 0x0228:3 (0x0001)  
	unsigned char                                      UnknownData01_5[0x3];                                       // 0x0229   (0x0003)  MISSED
	float                                              BaseEyeHeight;                                              // 0x022C   (0x0004)  
	char                     AutoPossessPlayer;                                          // 0x0230   (0x0001)  
	char                                     AutoPossessAI;                                              // 0x0231   (0x0001)  
	char                                               RemoteViewPitch;                                            // 0x0232   (0x0001)  
	unsigned char                                      UnknownData02_6[0x5];                                       // 0x0233   (0x0005)  MISSED
	class UClass* AIControllerClass;                                          // 0x0238   (0x0008)  
	class APlayerState* PlayerState;                                                // 0x0240   (0x0008)  
	unsigned char                                      UnknownData03_6[0x8];                                       // 0x0248   (0x0008)  MISSED
	class AController* LastHitBy;                                                  // 0x0250   (0x0008)  
	class AController* Controller;                                                 // 0x0258   (0x0008)  
	unsigned char                                      UnknownData04_6[0x4];                                       // 0x0260   (0x0004)  MISSED
	FVector                                            ControlInputVector;                                         // 0x0264   (0x000C)  
	FVector                                            LastControlInputVector;                                     // 0x0270   (0x000C)  
	unsigned char                                      UnknownData05_7[0x4];                                       // 0x027C   (0x0004)  MISSED
};

class ACharacter : public APawn
{
public:
	class USkeletalMeshComponent* Mesh;                                                       // 0x0280   (0x0008)  
	class UCharacterMovementComponent* CharacterMovement;                                          // 0x0288   (0x0008)  
	class UCapsuleComponent* CapsuleComponent;                                           // 0x0290   (0x0008)  
	char                                 BasedMovement[0x30];                                              // 0x0298   (0x0030)  
	char                                 ReplicatedBasedMovement[0x30];                                    // 0x02C8   (0x0030)  
	float                                              AnimRootMotionTranslationScale;                             // 0x02F8   (0x0004)  
	FVector                                            BaseTranslationOffset;                                      // 0x02FC   (0x000C)  
	unsigned char                                      UnknownData00_6[0x8];                                       // 0x0308   (0x0008)  MISSED
	char                                              BaseRotationOffset[0x10];                                         // 0x0310   (0x0010)  
	float                                              ReplicatedServerLastTransformUpdateTimeStamp;               // 0x0320   (0x0004)  
	float                                              ReplayLastTransformUpdateTimeStamp;                         // 0x0324   (0x0004)  
	char                                               ReplicatedMovementMode;                                     // 0x0328   (0x0001)  
	bool                                               bInBaseReplication;                                         // 0x0329   (0x0001)  
	unsigned char                                      UnknownData01_6[0x2];                                       // 0x032A   (0x0002)  MISSED
	float                                              CrouchedEyeHeight;                                          // 0x032C   (0x0004)  
	bool                                               bIsCrouched : 1;                                            // 0x0330:0 (0x0001)  
	bool                                               bProxyIsJumpForceApplied : 1;                               // 0x0330:1 (0x0001)  
	bool                                               bPressedJump : 1;                                           // 0x0330:2 (0x0001)  
	bool                                               bClientUpdating : 1;                                        // 0x0330:3 (0x0001)  
	bool                                               bClientWasFalling : 1;                                      // 0x0330:4 (0x0001)  
	bool                                               bClientResimulateRootMotion : 1;                            // 0x0330:5 (0x0001)  
	bool                                               bClientResimulateRootMotionSources : 1;                     // 0x0330:6 (0x0001)  
	bool                                               bSimGravityDisabled : 1;                                    // 0x0330:7 (0x0001)  
	bool                                               bClientCheckEncroachmentOnNetUpdate : 1;                    // 0x0331:0 (0x0001)  
	bool                                               bServerMoveIgnoreRootMotion : 1;                            // 0x0331:1 (0x0001)  
	bool                                               bWasJumping : 1;                                            // 0x0331:2 (0x0001)  
	unsigned char                                      UnknownData02_5[0x2];                                       // 0x0332   (0x0002)  MISSED
	float                                              JumpKeyHoldTime;                                            // 0x0334   (0x0004)  
	float                                              JumpForceTimeRemaining;                                     // 0x0338   (0x0004)  
	float                                              ProxyJumpForceStartedTime;                                  // 0x033C   (0x0004)  
	float                                              JumpMaxHoldTime;                                            // 0x0340   (0x0004)  
	int32_t                                            JumpMaxCount;                                               // 0x0344   (0x0004)  
	int32_t                                            JumpCurrentCount;                                           // 0x0348   (0x0004)  
	int32_t                                            JumpCurrentCountPreJump;                                    // 0x034C   (0x0004)  
	unsigned char                                      UnknownData03_6[0x8];                                       // 0x0350   (0x0008)  MISSED
	char OnReachedJumpApex[0x10];                                   // 0x0358   (0x0010)  
	unsigned char                                      UnknownData04_6[0x10];                                      // 0x0368   (0x0010)  MISSED
	char MovementModeChangedDelegate[0x10];                         // 0x0378   (0x0010)  
	char OnCharacterMovementUpdated[0x10];                          // 0x0388   (0x0010)  
	char                             SavedRootMotion[0x38];                                            // 0x0398   (0x0038)  
	char                          ClientRootMotionParams[0x40];                                     // 0x03D0   (0x0040)  
	char         RootMotionRepMoves[0x10];                                         // 0x0410   (0x0010)  
	char                              RepRootMotion[0x98];                                              // 0x0420   (0x0098)  
	unsigned char                                      UnknownData05_7[0x8];                                       // 0x04B8   (0x0008)  MISSED
};

class AController : public AActor
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x0220   (0x0008)  MISSED
	class APlayerState* PlayerState;                                                // 0x0228   (0x0008)  
	unsigned char                                      UnknownData01_6[0x8];                                       // 0x0230   (0x0008)  MISSED
	char OnInstigatedAnyDamage[0x10];                               // 0x0238   (0x0010)  
	FName                                              StateName;                                                  // 0x0248   (0x0008)  
	class APawn* Pawn;                                                       // 0x0250   (0x0008)  
	unsigned char                                      UnknownData02_6[0x8];                                       // 0x0258   (0x0008)  MISSED
	class ACharacter* Character;                                                  // 0x0260   (0x0008)  
	class USceneComponent* TransformComponent;                                         // 0x0268   (0x0008)  
	unsigned char                                      UnknownData03_6[0x18];                                      // 0x0270   (0x0018)  MISSED
	FRotator                                           ControlRotation;                                            // 0x0288   (0x000C)  
	bool                                               bAttachToPawn : 1;                                          // 0x0294:0 (0x0001)  
	unsigned char                                      UnknownData04_7[0x3];                                       // 0x0295   (0x0003)  MISSED

	class APlayerController* CastToPlayerController();
	void ClientSetLocation(const struct FVector& NewLocation, const struct FRotator& NewRotation);
	void ClientSetRotation(const struct FRotator& NewRotation, bool bResetCamera);
	void OnRep_Pawn();
	void OnRep_PlayerState();
	void Possess(class APawn* InPawn);
	void ReceiveInstigatedAnyDamage(float Damage, const class UDamageType* DamageType, class AActor* DamagedActor, class AActor* DamageCauser);
	void ReceivePossess(class APawn* PossessedPawn);
	void ReceiveUnPossess(class APawn* UnpossessedPawn);
	void ResetIgnoreInputFlags();
	void ResetIgnoreLookInput();
	void ResetIgnoreMoveInput();
	void SetControlRotation(const struct FRotator& NewRotation);
	void SetIgnoreLookInput(bool bNewLookInput);
	void SetIgnoreMoveInput(bool bNewMoveInput);
	void SetInitialLocationAndRotation(const struct FVector& NewLocation, const struct FRotator& NewRotation);
	void StopMovement();
	void UnPossess();

	struct FRotator GetControlRotation() const;
	struct FRotator GetDesiredRotation() const;
	class AActor* GetViewTarget() const;
	bool IsLocalController() const;
	bool IsLocalPlayerController() const;
	bool IsLookInputIgnored() const;
	bool IsMoveInputIgnored() const;
	bool IsPlayerController() const;
	class APawn* K2_GetPawn() const;
	bool LineOfSightTo(AActor* Other, const struct FVector& ViewPoint, bool bAlternateChecks) ;
};

class APlayerCameraManager : public AActor
{
public:
	class APlayerController* PCOwner;                                                    // 0x0220   (0x0008)  
	class USceneComponent* TransformComponent;                                         // 0x0228   (0x0008)  
	unsigned char                                      UnknownData00_6[0x8];                                       // 0x0230   (0x0008)  MISSED
	float                                              DefaultFOV;                                                 // 0x0238   (0x0004)  
	unsigned char                                      UnknownData01_6[0x4];                                       // 0x023C   (0x0004)  MISSED
	float                                              DefaultOrthoWidth;                                          // 0x0240   (0x0004)  
	unsigned char                                      UnknownData02_6[0x4];                                       // 0x0244   (0x0004)  MISSED
	float                                              DefaultAspectRatio;                                         // 0x0248   (0x0004)  
	unsigned char                                      UnknownData03_6[0x44];                                      // 0x024C   (0x0044)  MISSED
	char                                  CameraCache[0x630];                                                // 0x0290   (0x0630)  
	char                                  LastFrameCameraCache[0x630];                                       // 0x08C0   (0x0630)  
	char                                       ViewTarget[0x640];                                                 // 0x0EF0   (0x0640)  
	char                                       PendingViewTarget[0x640];                                          // 0x1530   (0x0640)  
	unsigned char                                      UnknownData04_6[0x30];                                      // 0x1B70   (0x0030)  MISSED
	char                                  CameraCachePrivate[0x630];                                         // 0x1BA0   (0x0630)  
	char                                  LastFrameCameraCachePrivate[0x630];                                // 0x21D0   (0x0630)  
	TArray<class UCameraModifier*>                     ModifierList;                                               // 0x2800   (0x0010)  
	TArray<class UClass*>                              DefaultModifiers;                                           // 0x2810   (0x0010)  
	float                                              FreeCamDistance;                                            // 0x2820   (0x0004)  
	FVector                                            FreeCamOffset;                                              // 0x2824   (0x000C)  
	FVector                                            ViewTargetOffset;                                           // 0x2830   (0x000C)  
	unsigned char                                      UnknownData05_6[0x4];                                       // 0x283C   (0x0004)  MISSED
	char OnAudioFadeChangeEvent[0x10];                             // 0x2840   (0x0010)  
	unsigned char                                      UnknownData06_6[0x10];                                      // 0x2850   (0x0010)  MISSED
	TArray<class AEmitterCameraLensEffectBase*>        CameraLensEffects;                                          // 0x2860   (0x0010)  
	class UCameraModifier_CameraShake* CachedCameraShakeMod;                                       // 0x2870   (0x0008)  
	class UCameraAnimInst* AnimInstPool[8];                                            // 0x2878   (0x0040)  
	char                       PostProcessBlendCache[0x10];                                      // 0x28B8   (0x0010)  
	unsigned char                                      UnknownData07_6[0x10];                                      // 0x28C8   (0x0010)  MISSED
	TArray<class UCameraAnimInst*>                     ActiveAnims;                                                // 0x28D8   (0x0010)  
	TArray<class UCameraAnimInst*>                     FreeAnims;                                                  // 0x28E8   (0x0010)  
	class ACameraActor* AnimCameraActor;                                            // 0x28F8   (0x0008)  
	bool                                               bIsOrthographic : 1;                                        // 0x2900:0 (0x0001)  
	bool                                               bDefaultConstrainAspectRatio : 1;                           // 0x2900:1 (0x0001)  
	unsigned char                                      UnknownBit08 : 1;                                           // 0x2900:2 (0x0001)  MISSED
	unsigned char                                      UnknownBit09 : 1;                                           // 0x2900:3 (0x0001)  MISSED
	unsigned char                                      UnknownBit10 : 1;                                           // 0x2900:4 (0x0001)  MISSED
	unsigned char                                      UnknownBit11 : 1;                                           // 0x2900:5 (0x0001)  MISSED
	bool                                               bClientSimulatingViewTarget : 1;                            // 0x2900:6 (0x0001)  
	bool                                               bUseClientSideCameraUpdates : 1;                            // 0x2900:7 (0x0001)  
	unsigned char                                      UnknownBit12 : 1;                                           // 0x2901:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit13 : 1;                                           // 0x2901:1 (0x0001)  MISSED
	bool                                               bGameCameraCutThisFrame : 1;                                // 0x2901:2 (0x0001)  
	unsigned char                                      UnknownData14_5[0x2];                                       // 0x2902   (0x0002)  MISSED
	float                                              ViewPitchMin;                                               // 0x2904   (0x0004)  
	float                                              ViewPitchMax;                                               // 0x2908   (0x0004)  
	float                                              ViewYawMin;                                                 // 0x290C   (0x0004)  
	float                                              ViewYawMax;                                                 // 0x2910   (0x0004)  
	float                                              ViewRollMin;                                                // 0x2914   (0x0004)  
	float                                              ViewRollMax;                                                // 0x2918   (0x0004)  
	unsigned char                                      UnknownData15_6[0x4];                                       // 0x291C   (0x0004)  MISSED
	float                                              ServerUpdateCameraTimeout;                                  // 0x2920   (0x0004)  
	unsigned char                                      UnknownData16_7[0xC];                                       // 0x2924   (0x000C)  MISSED


public:
	class AEmitterCameraLensEffectBase* AddCameraLensEffect(class AEmitterCameraLensEffectBase LensEffectEmitterClass);
	class UCameraModifier* AddNewCameraModifier(class UCameraModifier ModifierClass);
	bool BlueprintUpdateCamera(class AActor* CameraTarget, struct FVector* NewCameraLocation, struct FRotator* NewCameraRotation, float* NewCameraFOV);
	void ClearCameraLensEffects();
	class UCameraModifier* FindCameraModifierByClass(class UCameraModifier ModifierClass);
	void OnPhotographyMultiPartCaptureEnd();
	void OnPhotographyMultiPartCaptureStart();
	void OnPhotographySessionEnd();
	void OnPhotographySessionStart();
	void PhotographyCameraModify(const struct FVector& NewCameraLocation, const struct FVector& PreviousCameraLocation, const struct FVector& OriginalCameraLocation, struct FVector* ResultCameraLocation);
	class UCameraAnimInst* PlayCameraAnim(class UCameraAnim* Anim, float Rate, float Scale, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, float Duration, ECameraShakePlaySpace PlaySpace, const struct FRotator& UserPlaySpaceRot);
	void RemoveCameraLensEffect(class AEmitterCameraLensEffectBase* Emitter);
	bool RemoveCameraModifier(class UCameraModifier* ModifierToRemove);
	void SetGameCameraCutThisFrame();
	void SetManualCameraFade(float InFadeAmount, const struct FLinearColor& Color, bool bInFadeAudio);
	void StartCameraFade(float FromAlpha, float ToAlpha, float Duration, const struct FLinearColor& Color, bool bShouldFadeAudio, bool bHoldWhenFinished);
	class UCameraShakeBase* StartCameraShake(class UCameraShakeBase ShakeClass, float Scale, ECameraShakePlaySpace PlaySpace, const struct FRotator& UserPlaySpaceRot);
	class UCameraShakeBase* StartCameraShakeFromSource(class UCameraShakeBase ShakeClass, class UCameraShakeSourceComponent* SourceComponent, float Scale, ECameraShakePlaySpace PlaySpace, const struct FRotator& UserPlaySpaceRot);
	void StopAllCameraAnims(bool bImmediate);
	void StopAllCameraShakes(bool bImmediately);
	void StopAllCameraShakesFromSource(class UCameraShakeSourceComponent* SourceComponent, bool bImmediately);
	void StopAllInstancesOfCameraAnim(class UCameraAnim* Anim, bool bImmediate);
	void StopAllInstancesOfCameraShake(class UCameraShakeBase Shake, bool bImmediately);
	void StopAllInstancesOfCameraShakeFromSource(class UCameraShakeBase Shake, class UCameraShakeSourceComponent* SourceComponent, bool bImmediately);
	void StopCameraAnimInst(class UCameraAnimInst* AnimInst, bool bImmediate);
	void StopCameraFade();
	void StopCameraShake(class UCameraShakeBase* ShakeInstance, bool bImmediately);
	void SwapPendingViewTargetWhenUsingClientSideCameraUpdates();

	struct FVector GetCameraLocation();
	struct FRotator GetCameraRotation();
	float GetFOVAngle() const;
	class APlayerController* GetOwningPlayerController() const;
};


class APlayerController : public AController
{
public:
	class UPlayer* Player;                                                     // 0x0298   (0x0008)  
	class APawn* AcknowledgedPawn;                                           // 0x02A0   (0x0008)  
	class UInterpTrackInstDirector* ControllingDirTrackInst;                                    // 0x02A8   (0x0008)  
	class AHUD* MyHUD;                                                      // 0x02B0   (0x0008)  
	class APlayerCameraManager* PlayerCameraManager;                                        // 0x02B8   (0x0008)  
	class UClass* PlayerCameraManagerClass;                                   // 0x02C0   (0x0008)  
	bool                                               bAutoManageActiveCameraTarget;                              // 0x02C8   (0x0001)  
	unsigned char                                      UnknownData00_6[0x3];                                       // 0x02C9   (0x0003)  MISSED
	FRotator                                           TargetViewRotation;                                         // 0x02CC   (0x000C)  
	unsigned char                                      UnknownData01_6[0xC];                                       // 0x02D8   (0x000C)  MISSED
	float                                              SmoothTargetViewRotationSpeed;                              // 0x02E4   (0x0004)  
	unsigned char                                      UnknownData02_6[0x8];                                       // 0x02E8   (0x0008)  MISSED
	TArray<class AActor*>                              HiddenActors;                                               // 0x02F0   (0x0010)  
	char HiddenPrimitiveComponents[0x10];       // 0x0300   (0x0010)  
	unsigned char                                      UnknownData03_6[0x4];                                       // 0x0310   (0x0004)  MISSED
	float                                              LastSpectatorStateSynchTime;                                // 0x0314   (0x0004)  
	FVector                                            LastSpectatorSyncLocation;                                  // 0x0318   (0x000C)  
	FRotator                                           LastSpectatorSyncRotation;                                  // 0x0324   (0x000C)  
	int32_t                                            ClientCap;                                                  // 0x0330   (0x0004)  
	unsigned char                                      UnknownData04_6[0x4];                                       // 0x0334   (0x0004)  MISSED
	class UCheatManager* CheatManager;                                               // 0x0338   (0x0008)  
	class UClass* CheatClass;                                                 // 0x0340   (0x0008)  
	class UPlayerInput* PlayerInput;                                                // 0x0348   (0x0008)  
	char                 ActiveForceFeedbackEffects[0x10];                                 // 0x0350   (0x0010)  
	unsigned char                                      UnknownData05_6[0x80];                                      // 0x0360   (0x0080)  MISSED
	unsigned char                                      UnknownBit06 : 1;                                           // 0x03E0:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit07 : 1;                                           // 0x03E0:1 (0x0001)  MISSED
	unsigned char                                      UnknownBit08 : 1;                                           // 0x03E0:2 (0x0001)  MISSED
	unsigned char                                      UnknownBit09 : 1;                                           // 0x03E0:3 (0x0001)  MISSED
	bool                                               bPlayerIsWaiting : 1;                                       // 0x03E0:4 (0x0001)  
	unsigned char                                      UnknownData10_5[0x3];                                       // 0x03E1   (0x0003)  MISSED
	char                                               NetPlayerIndex;                                             // 0x03E4   (0x0001)  
	unsigned char                                      UnknownData11_6[0x3B];                                      // 0x03E5   (0x003B)  MISSED
	class UNetConnection* PendingSwapConnection;                                      // 0x0420   (0x0008)  
	class UNetConnection* NetConnection;                                              // 0x0428   (0x0008)  
	unsigned char                                      UnknownData12_6[0xC];                                       // 0x0430   (0x000C)  MISSED
	float                                              InputYawScale;                                              // 0x043C   (0x0004)  
	float                                              InputPitchScale;                                            // 0x0440   (0x0004)  
	float                                              InputRollScale;                                             // 0x0444   (0x0004)  
	bool                                               bShowMouseCursor : 1;                                       // 0x0448:0 (0x0001)  
	bool                                               bEnableClickEvents : 1;                                     // 0x0448:1 (0x0001)  
	bool                                               bEnableTouchEvents : 1;                                     // 0x0448:2 (0x0001)  
	bool                                               bEnableMouseOverEvents : 1;                                 // 0x0448:3 (0x0001)  
	bool                                               bEnableTouchOverEvents : 1;                                 // 0x0448:4 (0x0001)  
	bool                                               bForceFeedbackEnabled : 1;                                  // 0x0448:5 (0x0001)  
	unsigned char                                      UnknownData13_5[0x3];                                       // 0x0449   (0x0003)  MISSED
	float                                              ForceFeedbackScale;                                         // 0x044C   (0x0004)  
	char                                       ClickEventKeys[0x10];                                             // 0x0450   (0x0010)  
	char                          DefaultMouseCursor;                                         // 0x0460   (0x0001)  
	char                          CurrentMouseCursor;                                         // 0x0461   (0x0001)  
	char                     DefaultClickTraceChannel;                                   // 0x0462   (0x0001)  
	char                     CurrentClickTraceChannel;                                   // 0x0463   (0x0001)  
	float                                              HitResultTraceDistance;                                     // 0x0464   (0x0004)  
	uint16_t                                           SeamlessTravelCount;                                        // 0x0468   (0x0002)  
	uint16_t                                           LastCompletedSeamlessTravelCount;                           // 0x046A   (0x0002)  
	unsigned char                                      UnknownData14_6[0x74];                                      // 0x046C   (0x0074)  MISSED
	class UInputComponent* InactiveStateInputComponent;                                // 0x04E0   (0x0008)  
	unsigned char                                      UnknownBit15 : 1;                                           // 0x04E8:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit16 : 1;                                           // 0x04E8:1 (0x0001)  MISSED
	bool                                               bShouldPerformFullTickWhenPaused : 1;                       // 0x04E8:2 (0x0001)  
	unsigned char                                      UnknownData17_5[0x17];                                      // 0x04E9   (0x0017)  MISSED
	class UTouchInterface* CurrentTouchInterface;                                      // 0x0500   (0x0008)  
	unsigned char                                      UnknownData18_6[0x50];                                      // 0x0508   (0x0050)  MISSED
	class ASpectatorPawn* SpectatorPawn;                                              // 0x0558   (0x0008)  
	unsigned char                                      UnknownData19_6[0x4];                                       // 0x0560   (0x0004)  MISSED
	bool                                               bIsLocalPlayerController;                                   // 0x0564   (0x0001)  
	unsigned char                                      UnknownData20_6[0x3];                                       // 0x0565   (0x0003)  MISSED
	FVector                                            SpawnLocation;                                              // 0x0568   (0x000C)  
	unsigned char                                      UnknownData21_7[0xC];                                       // 0x0574   (0x000C)  MISSED

	void ActivateTouchInterface(class UTouchInterface* NewTouchInterface);
	void AddPitchInput(float Val);
	void AddRollInput(float Val);
	void AddYawInput(float Val);
	void Camera(class FName NewMode);
	bool CanRestartPlayer();
	void ClearAudioListenerAttenuationOverride();
	void ClearAudioListenerOverride();
	void ClientAddTextureStreamingLoc(const struct FVector& InLoc, float Duration, bool bOverrideLocation);
	void ClientCancelPendingMapChange();
	void ClientCapBandwidth(int32_t Cap);
	void ClientClearCameraLensEffects();
	void ClientCommitMapChange();
	void ClientEnableNetworkVoice(bool bEnable);
	void ClientEndOnlineSession();
	void ClientFlushLevelStreaming();
	void ClientForceGarbageCollection();
	void ClientGameEnded(class AActor* EndGameFocus, bool bIsWinner);
	void ClientGotoState(class FName NewState);
	void ClientIgnoreLookInput(bool bIgnore);
	void ClientIgnoreMoveInput(bool bIgnore);
	void ClientMessage(const class FString& S, class FName Type, float MsgLifeTime);
	void ClientMutePlayer(const struct FUniqueNetIdRepl& PlayerId);
	void ClientPlayCameraAnim(class UCameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, ECameraShakePlaySpace Space, const struct FRotator& CustomPlaySpace);
	void ClientPlayForceFeedback_Internal(class UForceFeedbackEffect* ForceFeedbackEffect, const struct FForceFeedbackParameters& Params_0);
	void ClientPlaySound(class USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier);
	void ClientPlaySoundAtLocation(class USoundBase* Sound, const struct FVector& Location, float VolumeMultiplier, float PitchMultiplier);
	void ClientPrepareMapChange(class FName LevelName, bool bFirst, bool bLast);
	void ClientPrestreamTextures(class AActor* ForcedActor, float ForceDuration, bool bEnableStreaming, int32_t CinematicTextureGroups);
	void ClientReceiveLocalizedMessage(class ULocalMessage Message, int32_t Switch, class APlayerState* RelatedPlayerState_1, class APlayerState* RelatedPlayerState_2, class UObject* OptionalObject);
	void ClientRepObjRef(class UObject* Object);
	void ClientReset();
	void ClientRestart(class APawn* NewPawn);
	void ClientRetryClientRestart(class APawn* NewPawn);
	void ClientReturnToMainMenu(const class FString& ReturnReason);
	void ClientReturnToMainMenuWithTextReason(const class FText& ReturnReason);
	void ClientSetBlockOnAsyncLoading();
	void ClientSetCameraFade(bool bEnableFading, const struct FColor& FadeColor, const struct FVector2D& FadeAlpha, float FadeTime, bool bFadeAudio, bool bHoldWhenFinished);
	void ClientSetCameraMode(class FName NewCamMode);
	void ClientSetCinematicMode(bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsHUD);
	void ClientSetForceMipLevelsToBeResident(class UMaterialInterface* Material, float ForceDuration, int32_t CinematicTextureGroups);
	void ClientSetHUD(class AHUD NewHUDClass);
	void ClientSetSpectatorWaiting(bool bWaiting);
	void ClientSetViewTarget(class AActor* A, const struct FViewTargetTransitionParams& TransitionParams);
	void ClientSpawnCameraLensEffect(class AEmitterCameraLensEffectBase LensEffectEmitterClass);
	void ClientStartCameraShake(class UCameraShakeBase Shake, float Scale, ECameraShakePlaySpace PlaySpace, const struct FRotator& UserPlaySpaceRot);
	void ClientStartCameraShakeFromSource(class UCameraShakeBase Shake, class UCameraShakeSourceComponent* SourceComponent);
	void ClientStartOnlineSession();
	void ClientStopCameraAnim(class UCameraAnim* AnimToStop);
	void ClientStopCameraShake(class UCameraShakeBase Shake, bool bImmediately);
	void ClientStopCameraShakesFromSource(class UCameraShakeSourceComponent* SourceComponent, bool bImmediately);
	void ClientStopForceFeedback(class UForceFeedbackEffect* ForceFeedbackEffect, class FName Tag);
	void ClientTeamMessage(class APlayerState* SenderPlayerState, const class FString& S, class FName Type, float MsgLifeTime);
	void ClientTravel(const class FString& URL, ETravelType TravelType, bool bSeamless, const struct FGuid& MapPackageGuid);
	void ClientTravelInternal(const class FString& URL, ETravelType TravelType, bool bSeamless, const struct FGuid& MapPackageGuid);
	void ClientUnmutePlayer(const struct FUniqueNetIdRepl& PlayerId);
	void ClientUpdateLevelStreamingStatus(class FName PackageName, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad, int32_t LODIndex);
	void ClientUpdateMultipleLevelsStreamingStatus(const TArray<struct FUpdateLevelStreamingLevelStatus>& LevelStatuses);
	void ClientVoiceHandshakeComplete();
	void ClientWasKicked(const class FText& KickReason);
	void ConsoleKey(const struct FKey& Key);
	void EnableCheats();
	void FOV(float NewFOV);
	void K2_ClientPlayForceFeedback(class UForceFeedbackEffect* ForceFeedbackEffect, class FName Tag, bool bLooping, bool bIgnoreTimeDilation, bool bPlayWhilePaused);
	void LocalTravel(const class FString& URL);
	void OnServerStartedVisualLogger(bool bIsLogging);
	void Pause();
	void PlayDynamicForceFeedback(float Intensity, float Duration, bool bAffectsLeftLarge, bool bAffectsLeftSmall, bool bAffectsRightLarge, bool bAffectsRightSmall, EDynamicForceFeedbackAction Action, const struct FLatentActionInfo& LatentInfo);
	void PlayHapticEffect(class UHapticFeedbackEffect_Base* HapticEffect, EControllerHand Hand, float Scale, bool bLoop);
	void ResetControllerLightColor();
	void RestartLevel();
	void SendToConsole(const class FString& Command);
	void ServerAcknowledgePossession(class APawn* P);
	void ServerCamera(class FName NewMode);
	void ServerChangeName(const class F_String& S);
	void ServerCheckClientPossession();
	void ServerCheckClientPossessionReliable();
	void ServerExec(const class FString& Msg);
	void ServerExecRPC(const class FString& Msg);
	void ServerMutePlayer(const struct FUniqueNetIdRepl& PlayerId);
	void ServerNotifyLoadedWorld(class FName WorldPackageName);
	void ServerPause();
	void ServerRestartPlayer();
	void ServerSetSpectatorLocation(const struct FVector& NewLoc, const struct FRotator& NewRot);
	void ServerSetSpectatorWaiting(bool bWaiting);
	void ServerShortTimeout();
	void ServerToggleAILogging();
	void ServerUnmutePlayer(const struct FUniqueNetIdRepl& PlayerId);
	void ServerUpdateCamera(const struct FVector_NetQuantize& CamLoc, int32_t CamPitchAndYaw);
	void ServerUpdateLevelVisibility(const struct FUpdateLevelVisibilityLevelInfo& LevelVisibility);
	void ServerUpdateMultipleLevelsVisibility(const TArray<struct FUpdateLevelVisibilityLevelInfo>& LevelVisibilities);
	void ServerVerifyViewTarget();
	void ServerViewNextPlayer();
	void ServerViewPrevPlayer();
	void ServerViewSelf(const struct FViewTargetTransitionParams& TransitionParams);
	void SetAudioListenerAttenuationOverride(class USceneComponent* AttachToComponent, const struct FVector& AttenuationLocationOVerride);
	void SetAudioListenerOverride(class USceneComponent* AttachToComponent, const struct FVector& Location, const struct FRotator& Rotation);
	void SetCinematicMode(bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning);
	void SetControllerLightColor(const struct FColor& Color);
	void SetDisableHaptics(bool bNewDisabled);
	void SetHapticsByValue(const float Frequency, const float Amplitude, EControllerHand Hand);
	void SetMouseCursorWidget(EMouseCursor Cursor, class UUserWidget* CursorWidget);
	void SetMouseLocation(const int32_t X, const int32_t Y);
	void SetName(const class F_String& S);
	void SetViewTargetWithBlend(class AActor* NewViewTarget, float BlendTime, EViewTargetBlendFunction BlendFunc, float BlendExp, bool bLockOutgoing);
	void SetVirtualJoystickVisibility(bool bVisible);
	void StartFire(uint8_t FireModeNum);
	void StopHapticEffect(EControllerHand Hand);
	void SwitchLevel(const class FString& URL);
	void TestServerLevelVisibilityChange(const class FName PackageName, const class FName Filename);
	void ToggleSpeaking(bool bInSpeaking);

	bool DeprojectMousePositionToWorld(struct FVector* WorldLocation, struct FVector* WorldDirection) const;
	bool DeprojectScreenPositionToWorld(float ScreenX, float ScreenY, struct FVector* WorldLocation, struct FVector* WorldDirection) const;
	struct FVector GetFocalLocation() const;
	bool GetHitResultUnderCursor(ECollisionChannel TraceChannel, bool bTraceComplex, struct FHitResult* HitResult) const;
	bool GetHitResultUnderCursorByChannel(ETraceTypeQuery TraceChannel, bool bTraceComplex, struct FHitResult* HitResult) const;
	bool GetHitResultUnderCursorForObjects(const TArray<EObjectTypeQuery>& ObjectTypes, bool bTraceComplex, struct FHitResult* HitResult) const;
	bool GetHitResultUnderFinger(ETouchIndex FingerIndex, ECollisionChannel TraceChannel, bool bTraceComplex, struct FHitResult* HitResult) const;
	bool GetHitResultUnderFingerByChannel(ETouchIndex FingerIndex, ETraceTypeQuery TraceChannel, bool bTraceComplex, struct FHitResult* HitResult) const;
	bool GetHitResultUnderFingerForObjects(ETouchIndex FingerIndex, const TArray<EObjectTypeQuery>& ObjectTypes, bool bTraceComplex, struct FHitResult* HitResult) const;
	class AHUD* GetHUD() const;
	float GetInputAnalogKeyState(const struct FKey& Key) const;
	void GetInputAnalogStickState(EControllerAnalogStick WhichStick, float* StickX, float* StickY) const;
	float GetInputKeyTimeDown(const struct FKey& Key) const;
	void GetInputMotionState(struct FVector* Tilt, struct FVector* RotationRate, struct FVector* Gravity, struct FVector* Acceleration) const;
	void GetInputMouseDelta(float* DeltaX, float* DeltaY) const;
	void GetInputTouchState(ETouchIndex FingerIndex, float* LocationX, float* LocationY, bool* bIsCurrentlyPressed) const;
	struct FVector GetInputVectorKeyState(const struct FKey& Key) const;
	bool GetMousePosition(float* LocationX, float* LocationY) const;
	class ASpectatorPawn* GetSpectatorPawn() const;
	void GetViewportSize(int32_t* SizeX, int32_t* SizeY) const;
	bool IsInputKeyDown(const struct FKey& Key) const;
	bool ProjectWorldLocationToScreen(FVector WorldLocation, struct FVector2D& ScreenLocation, bool bPlayerViewportRelative);
	bool WasInputKeyJustPressed(const struct FKey& Key) const;
	bool WasInputKeyJustReleased(const struct FKey& Key) const;
};

class UPlayer : public UObject
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x0028   (0x0008)  MISSED
	class APlayerController* PlayerController;                                           // 0x0030   (0x0008)  
	int32_t                                            CurrentNetSpeed;                                            // 0x0038   (0x0004)  
	int32_t                                            ConfiguredInternetSpeed;                                    // 0x003C   (0x0004)  
	int32_t                                            ConfiguredLanSpeed;                                         // 0x0040   (0x0004)  
	unsigned char                                      UnknownData01_7[0x4];                                       // 0x0044   (0x0004)  MISSED
};



class ULocalPlayer : public UPlayer
{
public:
	unsigned char                                      UnknownData00_8[0x28];                                      // 0x0048   (0x0028)  MISSED
	class UGameViewportClient* ViewportClient;                                             // 0x0070   (0x0008)  
	unsigned char                                      UnknownData01_6[0x1C];                                      // 0x0078   (0x001C)  MISSED
	char           AspectRatioAxisConstraint;                                  // 0x0094   (0x0001)  
	unsigned char                                      UnknownData02_6[0x3];                                       // 0x0095   (0x0003)  MISSED
	class UClass* PendingLevelPlayerControllerClass;                          // 0x0098   (0x0008)  
	bool                                               bSentSplitJoin : 1;                                         // 0x00A0:0 (0x0001)  
	unsigned char                                      UnknownData03_5[0x17];                                      // 0x00A1   (0x0017)  MISSED
	int32_t                                            ControllerId;                                               // 0x00B8   (0x0004)  
	unsigned char                                      UnknownData04_7[0x19C];                                     // 0x00BC   (0x019C)  MISSED
};

class UGameInstance : public UObject
{
public:
	unsigned char                                      UnknownData00_8[0x10];                                      // 0x0028   (0x0010)  MISSED
	TArray<class ULocalPlayer*>                        LocalPlayers;                                               // 0x0038   (0x0010)  
	class UOnlineSession* OnlineSession;                                              // 0x0048   (0x0008)  
	TArray<class UObject*>                             ReferencedObjects;                                          // 0x0050   (0x0010)  
	unsigned char                                      UnknownData01_6[0x18];                                      // 0x0060   (0x0018)  MISSED
	char OnPawnControllerChangedDelegates[0x10];                    // 0x0078   (0x0010)  
	unsigned char                                      UnknownData02_7[0x120];                                     // 0x0088   (0x0120)  MISSED


	/// Functions
	// Function /Script/Engine.GameInstance.ReceiveShutdown
	// void ReceiveShutdown();                                                                                                  // [0x17b99b0] Event|Public|BlueprintEvent 
	// Function /Script/Engine.GameInstance.ReceiveInit
	// void ReceiveInit();                                                                                                      // [0x17b99b0] Event|Public|BlueprintEvent 
	// Function /Script/Engine.GameInstance.HandleTravelError
	// void HandleTravelError(TEnumAsByte<ETravelFailure> FailureType);                                                         // [0x17b99b0] Event|Public|BlueprintEvent 
	// Function /Script/Engine.GameInstance.HandleNetworkError
	// void HandleNetworkError(TEnumAsByte<ENetworkFailure> FailureType, bool bIsServer);                                       // [0x17b99b0] Event|Public|BlueprintEvent 
	// Function /Script/Engine.GameInstance.DebugRemovePlayer
	// void DebugRemovePlayer(int32_t ControllerId);                                                                            // [0x335dc00] Exec|Native|Public   
	// Function /Script/Engine.GameInstance.DebugCreatePlayer
	// void DebugCreatePlayer(int32_t ControllerId);                                                                            // [0x335db70] Exec|Native|Public   
};

//class ULevel
//{
//public:
//	unsigned char                                      UnknownData00_8[0x90];                                      // 0x0028   (0x0090)  MISSED
//	TArray<class AActor*> NearActors;
//
//
//public:
//
//};

//class ULevel : public UObject
//{
//public:
//	unsigned char                                      UnknownData00_8[0x90];                                      // 0x0028   (0x0090)  MISSED
//	TArray<class AActor*> actors;
//};

class ULevel : public UObject
{
public:
	char                                         Pad_28[0x70];                                      // 0x0028(0x0070)(Fixing Size After Last Property [ Dumper-7 ])
	class TArray<class AActor*>                   Actors;                                            // 0x0098(0x0010)(THIS IS THE ARRAY YOU'RE LOOKING FOR! [NOT AUTO-GENERATED PROPERTY])
	char                                         Pad_A8[0x10];                                      // 0x00A8(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	class UWorld* OwningWorld;                                       // 0x00B8(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UModel* Model;                                             // 0x00C0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class UModelComponent*>                ModelComponents;                                   // 0x00C8(0x0010)(ExportObject, ZeroConstructor, ContainsInstancedReference, NativeAccessSpecifierPublic)
	class ULevelActorContainer* ActorCluster;                                      // 0x00D8(0x0008)(ExportObject, ZeroConstructor, Transient, InstancedReference, DuplicateTransient, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32_t                                         NumTextureStreamingUnbuiltComponents;              // 0x00E0(0x0004)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32_t                                         NumTextureStreamingDirtyResources;                 // 0x00E4(0x0004)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class ALevelScriptActor* LevelScriptActor;                                  // 0x00E8(0x0008)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class ANavigationObjectBase* NavListStart;                                      // 0x00F0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class ANavigationObjectBase* NavListEnd;                                        // 0x00F8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class UNavigationDataChunk*>           NavDataChunks;                                     // 0x0100(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	float                                         LightmapTotalSize;                                 // 0x0110(0x0004)(Edit, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ShadowmapTotalSize;                                // 0x0114(0x0004)(Edit, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FVector>                        StaticNavigableGeometry;                           // 0x0118(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FGuid>                          StreamingTextureGuids;                             // 0x0128(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	char                                         Pad_138[0x98];                                     // 0x0138(0x0098)(Fixing Size After Last Property [ Dumper-7 ])
	char                                  LevelBuildDataId[0x10];                                  // 0x01D0(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UMapBuildDataRegistry* MapBuildData;                                      // 0x01E0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, NonPIEDuplicateTransient, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char                             LightBuildLevelOffset[0xC];                             // 0x01E8(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	char                                         bIsLightingScenario : 1;                           // 0x01F4(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	char                                         BitPad_1F4_1 : 2;                                  // 0x01F4(0x0001)(Fixing Bit-Field Size Between Bits [ Dumper-7 ])
	char                                         bTextureStreamingRotationChanged : 1;              // 0x01F4(0x0001)(BitIndex: 0x03, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	char                                         bStaticComponentsRegisteredInStreamingManager : 1; // 0x01F4(0x0001)(BitIndex: 0x04, PropSize: 0x0001 (Transient, DuplicateTransient, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	char                                         bIsVisible : 1;                                    // 0x01F4(0x0001)(BitIndex: 0x05, PropSize: 0x0001 (Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	char                                         Pad_1F5[0x63];                                     // 0x01F5(0x0063)(Fixing Size After Last Property [ Dumper-7 ])
	class AWorldSettings* WorldSettings;                                     // 0x0258(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	char                                         Pad_260[0x8];                                      // 0x0260(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UAssetUserData*>                 AssetUserData;                                     // 0x0268(0x0010)(ExportObject, ZeroConstructor, ContainsInstancedReference, Protected, NativeAccessSpecifierProtected)
	char                                         Pad_278[0x10];                                     // 0x0278(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FReplicatedStaticActorDestructionInfo> DestroyedReplicatedStaticActors;                   // 0x0288(0x0010)(ZeroConstructor, Transient, NativeAccessSpecifierPrivate)
};

class AInfo : public AActor
{
public:
};

class APlayerState : public AInfo
{
public:
	float                                              Score;                                                      // 0x0220   (0x0004)  
	int32_t                                            PlayerId;                                                   // 0x0224   (0x0004)  
	char                                               Ping;                                                       // 0x0228   (0x0001)  
	unsigned char                                      UnknownData00_6[0x1];                                       // 0x0229   (0x0001)  MISSED
	bool                                               bShouldUpdateReplicatedPing : 1;                            // 0x022A:0 (0x0001)  
	bool                                               bIsSpectator : 1;                                           // 0x022A:1 (0x0001)  
	bool                                               bOnlySpectator : 1;                                         // 0x022A:2 (0x0001)  
	bool                                               bIsABot : 1;                                                // 0x022A:3 (0x0001)  
	unsigned char                                      UnknownBit01 : 1;                                           // 0x022A:4 (0x0001)  MISSED
	bool                                               bIsInactive : 1;                                            // 0x022A:5 (0x0001)  
	bool                                               bFromPreviousLevel : 1;                                     // 0x022A:6 (0x0001)  
	unsigned char                                      UnknownData02_5[0x1];                                       // 0x022B   (0x0001)  MISSED
	int32_t                                            StartTime;                                                  // 0x022C   (0x0004)  
	class UClass* EngineMessageClass;                                         // 0x0230   (0x0008)  
	unsigned char                                      UnknownData03_6[0x8];                                       // 0x0238   (0x0008)  MISSED
	char                                            SavedNetworkAddress[0x10];                                        // 0x0240   (0x0010)  
	char                                   UniqueId[0x28];                                                   // 0x0250   (0x0028)  
	unsigned char                                      UnknownData04_6[0x8];                                       // 0x0278   (0x0008)  MISSED
	class APawn* PawnPrivate;                                                // 0x0280   (0x0008)  
	unsigned char                                      UnknownData05_6[0x78];                                      // 0x0288   (0x0078)  MISSED
	F_String                                            PlayerNamePrivate;                                          // 0x0300   (0x0010)  
	unsigned char                                      UnknownData06_7[0x10];                                      // 0x0310   (0x0010)  MISSED
};

class AGameStateBase : public AInfo
{
public:
	class UClass* GameModeClass;                                              // 0x0220   (0x0008)  
	class AGameModeBase* AuthorityGameMode;                                          // 0x0228   (0x0008)  
	class UClass* SpectatorClass;                                             // 0x0230   (0x0008)  
	TArray<class APlayerState*>                        PlayerArray;                                                // 0x0238   (0x0010)  
	bool                                               bReplicatedHasBegunPlay;                                    // 0x0248   (0x0001)  
	unsigned char                                      UnknownData00_6[0x3];                                       // 0x0249   (0x0003)  MISSED
	float                                              ReplicatedWorldTimeSeconds;                                 // 0x024C   (0x0004)  
	float                                              ServerWorldTimeSecondsDelta;                                // 0x0250   (0x0004)  
	float                                              ServerWorldTimeSecondsUpdateFrequency;                      // 0x0254   (0x0004)  
	unsigned char                                      UnknownData01_7[0x18];                                      // 0x0258   (0x0018)  MISSED
};

class UWorld : public UObject
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x0028   (0x0008)  MISSED
	class ULevel* PersistentLevel;                                            // 0x0030   (0x0008)  
	class UNetDriver* NetDriver;                                                  // 0x0038   (0x0008)  
	class ULineBatchComponent* LineBatcher;                                                // 0x0040   (0x0008)  
	class ULineBatchComponent* PersistentLineBatcher;                                      // 0x0048   (0x0008)  
	class ULineBatchComponent* ForegroundLineBatcher;                                      // 0x0050   (0x0008)  
	class AGameNetworkManager* NetworkManager;                                             // 0x0058   (0x0008)  
	class UPhysicsCollisionHandler* PhysicsCollisionHandler;                                    // 0x0060   (0x0008)  
	TArray<class UObject*>                             ExtraReferencedObjects;                                     // 0x0068   (0x0010)  
	TArray<class UObject*>                             PerModuleDataObjects;                                       // 0x0078   (0x0010)  
	TArray<class ULevelStreaming*>                     StreamingLevels;                                            // 0x0088   (0x0010)  
	char                         StreamingLevelsToConsider[0x28];                                  // 0x0098   (0x0028)  
	char                                            StreamingLevelsPrefix[0x10];                                      // 0x00C0   (0x0010)  
	class ULevel* CurrentLevelPendingVisibility;                              // 0x00D0   (0x0008)  
	class ULevel* CurrentLevelPendingInvisibility;                            // 0x00D8   (0x0008)  
	class UDemoNetDriver* DemoNetDriver;                                              // 0x00E0   (0x0008)  
	class AParticleEventManager* MyParticleEventManager;                                     // 0x00E8   (0x0008)  
	class APhysicsVolume* DefaultPhysicsVolume;                                       // 0x00F0   (0x0008)  
	unsigned char                                      UnknownData01_6[0x16];                                      // 0x00F8   (0x0016)  MISSED
	unsigned char                                      UnknownBit02 : 1;                                           // 0x010E:0 (0x0001)  MISSED
	unsigned char                                      UnknownBit03 : 1;                                           // 0x010E:1 (0x0001)  MISSED
	bool                                               bAreConstraintsDirty : 1;                                   // 0x010E:2 (0x0001)  
	unsigned char                                      UnknownData04_5[0x1];                                       // 0x010F   (0x0001)  MISSED
	class UNavigationSystemBase* NavigationSystem;                                           // 0x0110   (0x0008)  
	class AGameModeBase* AuthorityGameMode;                                          // 0x0118   (0x0008)  
	class AGameStateBase* GameState;                                                  // 0x0120   (0x0008)  
	class UAISystemBase* AISystem;                                                   // 0x0128   (0x0008)  
	class UAvoidanceManager* AvoidanceManager;                                           // 0x0130   (0x0008)  
	TArray<class ULevel*>                              Levels;                                                     // 0x0138   (0x0010)  
	char                          LevelCollections[0x10];                                           // 0x0148   (0x0010)  
	unsigned char                                      UnknownData05_6[0x28];                                      // 0x0158   (0x0028)  MISSED
	class UGameInstance* OwningGameInstance;                                         // 0x0180   (0x0008)  
	TArray<class UMaterialParameterCollectionInstance*> ParameterCollectionInstances;                              // 0x0188   (0x0010)  
	class UCanvas* CanvasForRenderingToTarget;                                 // 0x0198   (0x0008)  
	class UCanvas* CanvasForDrawMaterialToRenderTarget;                        // 0x01A0   (0x0008)  
	unsigned char                                      UnknownData06_6[0x50];                                      // 0x01A8   (0x0050)  MISSED
	class UPhysicsFieldComponent* PhysicsField;                                               // 0x01F8   (0x0008)  
	char ComponentsThatNeedPreEndOfFrameSync[0x50];                  // 0x0200   (0x0050)  
	TArray<class UActorComponent*>                     ComponentsThatNeedEndOfFrameUpdate;                         // 0x0250   (0x0010)  
	TArray<class UActorComponent*>                     ComponentsThatNeedEndOfFrameUpdate_OnGameThread;            // 0x0260   (0x0010)  
	unsigned char                                      UnknownData07_6[0x370];                                     // 0x0270   (0x0370)  MISSED
	class UWorldComposition* WorldComposition;                                           // 0x05E0   (0x0008)  
	unsigned char                                      UnknownData08_6[0x90];                                      // 0x05E8   (0x0090)  MISSED
	char                                      PSCPool[0x58];                                                    // 0x0678   (0x0058)  
	unsigned char                                      UnknownData09_7[0xC8];                                      // 0x06D0   (0x00C8)  MISSED


	/// Functions
	// Function /Script/Engine.World.K2_GetWorldSettings
	// class AWorldSettings* K2_GetWorldSettings();                                                                             // [0x3488820] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.World.HandleTimelineScrubbed
	// void HandleTimelineScrubbed();                                                                                           // [0x3488800] Final|Native|Public  
};

class UCanvas : public UObject
{
public:
	float                                              OrgX;                                                       // 0x0028   (0x0004)  
	float                                              OrgY;                                                       // 0x002C   (0x0004)  
	float                                              ClipX;                                                      // 0x0030   (0x0004)  
	float                                              ClipY;                                                      // 0x0034   (0x0004)  
	int                                             DrawColor;                                                  // 0x0038   (0x0004)  
	bool                                               bCenterX : 1;                                               // 0x003C:0 (0x0001)  
	bool                                               bCenterY : 1;                                               // 0x003C:1 (0x0001)  
	bool                                               bNoSmooth : 1;                                              // 0x003C:2 (0x0001)  
	unsigned char                                      UnknownData00_5[0x3];                                       // 0x003D   (0x0003)  MISSED
	int32_t                                            SizeX;                                                      // 0x0040   (0x0004)  
	int32_t                                            SizeY;                                                      // 0x0044   (0x0004)  
	unsigned char                                      UnknownData01_6[0x8];                                       // 0x0048   (0x0008)  MISSED
	int                                             ColorModulate;                                              // 0x0050   (0x0010)  
	class UTexture2D* DefaultTexture;                                             // 0x0060   (0x0008)  
	class UTexture2D* GradientTexture0;                                           // 0x0068   (0x0008)  
	class UReporterGraph* ReporterGraph;                                              // 0x0070   (0x0008)  
	unsigned char                                      UnknownData02_7[0x258];                                     // 0x0078   (0x0258)  MISSED
public:
	void K2_Deproject(const struct FVector2D& ScreenPosition, struct FVector* WorldOrigin, struct FVector* WorldDirection);
	void K2_DrawBorder(class UTexture* BorderTexture, class UTexture* BackgroundTexture, class UTexture* LeftBorderTexture, class UTexture* RightBorderTexture, class UTexture* TopBorderTexture, class UTexture* BottomBorderTexture, const struct FVector2D& ScreenPosition, const struct FVector2D& ScreenSize, const struct FVector2D& CoordinatePosition, const struct FVector2D& CoordinateSize, const struct FLinearColor& RenderColor, const struct FVector2D& BorderScale, const struct FVector2D& BackgroundScale, float Rotation, const struct FVector2D& PivotPoint, const struct FVector2D& CornerSize);
	void K2_DrawBox(const struct FVector2D& ScreenPosition, const struct FVector2D& ScreenSize, float Thickness, const struct FLinearColor& RenderColor);
	void K2_DrawLine(const struct FVector2D& ScreenPositionA, const struct FVector2D& ScreenPositionB, float Thickness, const struct FLinearColor& RenderColor);
	void K2_DrawMaterial(class UMaterialInterface* RenderMaterial, const struct FVector2D& ScreenPosition, const struct FVector2D& ScreenSize, const struct FVector2D& CoordinatePosition, const struct FVector2D& CoordinateSize, float Rotation, const struct FVector2D& PivotPoint);
	void K2_DrawMaterialTriangle(class UMaterialInterface* RenderMaterial, const TArray<struct FCanvasUVTri>& Triangles);
	void K2_DrawPolygon(class UTexture* RenderTexture, const struct FVector2D& ScreenPosition, const struct FVector2D& Radius, int32_t NumberOfSides, const struct FLinearColor& RenderColor);
	void K2_DrawText(class UObject* RenderFont, const class F_String& RenderText, const struct FVector2D& ScreenPosition, const struct FVector2D& Scale, const struct FLinearColor& RenderColor, float Kerning, const struct FLinearColor& ShadowColor, const struct FVector2D& ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, const struct FLinearColor& OutlineColor);
	void K2_DrawTriangle(class UTexture* RenderTexture, const TArray<struct FCanvasUVTri>& Triangles);
	struct FVector K2_Project(const struct FVector& WorldLocation);
	struct FVector2D K2_StrLen(class UFont* RenderFont, const class FString& RenderText);
	struct FVector2D K2_TextSize(class UFont* RenderFont, const class FString& RenderText, const struct FVector2D& Scale);
};



class UMovementComponent : public UActorComponent
{
public:
	class USceneComponent* UpdatedComponent;                                           // 0x00B0   (0x0008)  
	class UPrimitiveComponent* UpdatedPrimitive;                                           // 0x00B8   (0x0008)  
	unsigned char                                      UnknownData00_6[0x4];                                       // 0x00C0   (0x0004)  MISSED
	FVector                                            Velocity;                                                   // 0x00C4   (0x000C)  
	FVector                                            PlaneConstraintNormal;                                      // 0x00D0   (0x000C)  
	FVector                                            PlaneConstraintOrigin;                                      // 0x00DC   (0x000C)  
	bool                                               bUpdateOnlyIfRendered : 1;                                  // 0x00E8:0 (0x0001)  
	bool                                               bAutoUpdateTickRegistration : 1;                            // 0x00E8:1 (0x0001)  
	bool                                               bTickBeforeOwner : 1;                                       // 0x00E8:2 (0x0001)  
	bool                                               bAutoRegisterUpdatedComponent : 1;                          // 0x00E8:3 (0x0001)  
	bool                                               bConstrainToPlane : 1;                                      // 0x00E8:4 (0x0001)  
	bool                                               bSnapToPlaneAtStart : 1;                                    // 0x00E8:5 (0x0001)  
	bool                                               bAutoRegisterPhysicsVolumeUpdates : 1;                      // 0x00E8:6 (0x0001)  
	bool                                               bComponentShouldUpdatePhysicsVolume : 1;                    // 0x00E8:7 (0x0001)  
	unsigned char                                      UnknownData01_5[0x2];                                       // 0x00E9   (0x0002)  MISSED
	char                        PlaneConstraintAxisSetting;                                 // 0x00EB   (0x0001)  
	unsigned char                                      UnknownData02_7[0x4];                                       // 0x00EC   (0x0004)  MISSED


	/// Functions
	// Function /Script/Engine.MovementComponent.StopMovementImmediately
	// void StopMovementImmediately();                                                                                          // [0x340b8b0] Native|Public|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.SnapUpdatedComponentToPlane
	// void SnapUpdatedComponentToPlane();                                                                                      // [0x340b890] Native|Public|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.SetUpdatedComponent
	// void SetUpdatedComponent(class USceneComponent* NewUpdatedComponent);                                                    // [0x340b720] Native|Public|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.SetPlaneConstraintOrigin
	// void SetPlaneConstraintOrigin(FVector PlaneOrigin);                                                                      // [0x340b5c0] Native|Public|HasDefaults|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.SetPlaneConstraintNormal
	// void SetPlaneConstraintNormal(FVector PlaneNormal);                                                                      // [0x340b530] Native|Public|HasDefaults|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.SetPlaneConstraintFromVectors
	// void SetPlaneConstraintFromVectors(FVector Forward, FVector Up);                                                         // [0x340b440] Native|Public|HasDefaults|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.SetPlaneConstraintEnabled
	// void SetPlaneConstraintEnabled(bool bEnabled);                                                                           // [0x340b3b0] Native|Public|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.SetPlaneConstraintAxisSetting
	// void SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting NewAxisSetting);                                          // [0x340b330] Native|Public|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.PhysicsVolumeChanged
	// void PhysicsVolumeChanged(class APhysicsVolume* NewVolume);                                                              // [0x340b100] Native|Public        
	// Function /Script/Engine.MovementComponent.K2_MoveUpdatedComponent
	// bool K2_MoveUpdatedComponent(FVector Delta, FRotator NewRotation, FHitResult& OutHit, bool bSweep, bool bTeleport);      // [0x340ac20] Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable 
	// Function /Script/Engine.MovementComponent.K2_GetModifiedMaxSpeed
	// float K2_GetModifiedMaxSpeed();                                                                                          // [0x340abe0] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.K2_GetMaxSpeedModifier
	// float K2_GetMaxSpeedModifier();                                                                                          // [0x340aba0] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.IsExceedingMaxSpeed
	// bool IsExceedingMaxSpeed(float MaxSpeed);                                                                                // [0x340aa60] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.GetPlaneConstraintOrigin
	// FVector GetPlaneConstraintOrigin();                                                                                      // [0x340aa20] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.GetPlaneConstraintNormal
	// FVector GetPlaneConstraintNormal();                                                                                      // [0x340a9e0] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.GetPlaneConstraintAxisSetting
	// EPlaneConstraintAxisSetting GetPlaneConstraintAxisSetting();                                                             // [0x340a9c0] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.GetPhysicsVolume
	// class APhysicsVolume* GetPhysicsVolume();                                                                                // [0x340a990] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.GetMaxSpeed
	// float GetMaxSpeed();                                                                                                     // [0x340a950] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.GetGravityZ
	// float GetGravityZ();                                                                                                     // [0x340a770] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.ConstrainNormalToPlane
	// FVector ConstrainNormalToPlane(FVector Normal);                                                                          // [0x340a6c0] Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.ConstrainLocationToPlane
	// FVector ConstrainLocationToPlane(FVector Location);                                                                      // [0x340a610] Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.MovementComponent.ConstrainDirectionToPlane
	// FVector ConstrainDirectionToPlane(FVector Direction);                                                                    // [0x340a560] Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
};

class UNavMovementComponent : public UMovementComponent
{
public:
	char                                NavAgentProps[0x30];                                              // 0x00F0   (0x0030)  
	float                                              FixedPathBrakingDistance;                                   // 0x0120   (0x0004)  
	bool                                               bUpdateNavAgentWithOwnersCollision : 1;                     // 0x0124:0 (0x0001)  
	bool                                               bUseAccelerationForPaths : 1;                               // 0x0124:1 (0x0001)  
	bool                                               bUseFixedBrakingDistanceForPaths : 1;                       // 0x0124:2 (0x0001)  
	char                                MovementState;                                              // 0x0125   (0x0001)  
	unsigned char                                      UnknownData00_6[0x2];                                       // 0x0126   (0x0002)  MISSED
	class UObject* PathFollowingComp;                                          // 0x0128   (0x0008)  


	/// Functions
	// Function /Script/Engine.NavMovementComponent.StopMovementKeepPathing
	// void StopMovementKeepPathing();                                                                                          // [0x340e380] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.NavMovementComponent.StopActiveMovement
	// void StopActiveMovement();                                                                                               // [0x340e360] Native|Public|BlueprintCallable 
	// Function /Script/Engine.NavMovementComponent.IsSwimming
	// bool IsSwimming();                                                                                                       // [0x340e330] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.NavMovementComponent.IsMovingOnGround
	// bool IsMovingOnGround();                                                                                                 // [0x337ca10] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.NavMovementComponent.IsFlying
	// bool IsFlying();                                                                                                         // [0x340e300] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.NavMovementComponent.IsFalling
	// bool IsFalling();                                                                                                        // [0x33251f0] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.NavMovementComponent.IsCrouching
	// bool IsCrouching();                                                                                                      // [0x340e2d0] Native|Public|BlueprintCallable|BlueprintPure|Const 
};

class UPawnMovementComponent : public UNavMovementComponent
{
public:
	class APawn* PawnOwner;                                                  // 0x0130   (0x0008)  


	/// Functions
	// Function /Script/Engine.PawnMovementComponent.K2_GetInputVector
	// FVector K2_GetInputVector();                                                                                             // [0x3423840] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.PawnMovementComponent.IsMoveInputIgnored
	// bool IsMoveInputIgnored();                                                                                               // [0x3423950] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.PawnMovementComponent.GetPendingInputVector
	// FVector GetPendingInputVector();                                                                                         // [0x3423840] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.PawnMovementComponent.GetPawnOwner
	// class APawn* GetPawnOwner();                                                                                             // [0x3423810] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.PawnMovementComponent.GetLastInputVector
	// FVector GetLastInputVector();                                                                                            // [0x34236b0] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.PawnMovementComponent.ConsumeInputVector
	// FVector ConsumeInputVector();                                                                                            // [0x3423340] Native|Public|HasDefaults|BlueprintCallable 
	// Function /Script/Engine.PawnMovementComponent.AddInputVector
	// void AddInputVector(FVector WorldVector, bool bForce);                                                                   // [0x3422d80] Native|Public|HasDefaults|BlueprintCallable 
};

class UCharacterMovementComponent : public UPawnMovementComponent
{
public:
	unsigned char                                      UnknownData00_8[0x10];                                      // 0x0138   (0x0010)  MISSED
	class ACharacter* CharacterOwner;                                             // 0x0148   (0x0008)  
	float                                              GravityScale;                                               // 0x0150   (0x0004)  
	float                                              MaxStepHeight;                                              // 0x0154   (0x0004)  
	float                                              JumpZVelocity;                                              // 0x0158   (0x0004)  
	float                                              JumpOffJumpZFactor;                                         // 0x015C   (0x0004)  
	float                                              WalkableFloorAngle;                                         // 0x0160   (0x0004)  
	float                                              WalkableFloorZ;                                             // 0x0164   (0x0004)  
	EMovementMode                         MovementMode;                                               // 0x0168   (0x0001)  
	char                                               CustomMovementMode;                                         // 0x0169   (0x0001)  
	char                              NetworkSmoothingMode;                                       // 0x016A   (0x0001)  
	unsigned char                                      UnknownData01_6[0x1];                                       // 0x016B   (0x0001)  MISSED
	float                                              GroundFriction;                                             // 0x016C   (0x0004)  
	unsigned char                                      UnknownData02_6[0x1C];                                      // 0x0170   (0x001C)  MISSED
	float                                              MaxWalkSpeed;                                               // 0x018C   (0x0004)  
	float                                              MaxWalkSpeedCrouched;                                       // 0x0190   (0x0004)  
	float                                              MaxSwimSpeed;                                               // 0x0194   (0x0004)  
	float                                              MaxFlySpeed;                                                // 0x0198   (0x0004)  
	float                                              MaxCustomMovementSpeed;                                     // 0x019C   (0x0004)  
	float                                              MaxAcceleration;                                            // 0x01A0   (0x0004)  
	float                                              MinAnalogWalkSpeed;                                         // 0x01A4   (0x0004)  
	float                                              BrakingFrictionFactor;                                      // 0x01A8   (0x0004)  
	float                                              BrakingFriction;                                            // 0x01AC   (0x0004)  
	float                                              BrakingSubStepTime;                                         // 0x01B0   (0x0004)  
	float                                              BrakingDecelerationWalking;                                 // 0x01B4   (0x0004)  
	float                                              BrakingDecelerationFalling;                                 // 0x01B8   (0x0004)  
	float                                              BrakingDecelerationSwimming;                                // 0x01BC   (0x0004)  
	float                                              BrakingDecelerationFlying;                                  // 0x01C0   (0x0004)  
	float                                              AirControl;                                                 // 0x01C4   (0x0004)  
	float                                              AirControlBoostMultiplier;                                  // 0x01C8   (0x0004)  
	float                                              AirControlBoostVelocityThreshold;                           // 0x01CC   (0x0004)  
	float                                              FallingLateralFriction;                                     // 0x01D0   (0x0004)  
	float                                              CrouchedHalfHeight;                                         // 0x01D4   (0x0004)  
	float                                              Buoyancy;                                                   // 0x01D8   (0x0004)  
	float                                              PerchRadiusThreshold;                                       // 0x01DC   (0x0004)  
	float                                              PerchAdditionalHeight;                                      // 0x01E0   (0x0004)  
	FRotator                                           RotationRate;                                               // 0x01E4   (0x000C)  
	bool                                               bUseSeparateBrakingFriction : 1;                            // 0x01F0:0 (0x0001)  
	bool                                               bApplyGravityWhileJumping : 1;                              // 0x01F0:1 (0x0001)  
	bool                                               bUseControllerDesiredRotation : 1;                          // 0x01F0:2 (0x0001)  
	bool                                               bOrientRotationToMovement : 1;                              // 0x01F0:3 (0x0001)  
	bool                                               bSweepWhileNavWalking : 1;                                  // 0x01F0:4 (0x0001)  
	unsigned char                                      UnknownBit03 : 1;                                           // 0x01F0:5 (0x0001)  MISSED
	bool                                               bMovementInProgress : 1;                                    // 0x01F0:6 (0x0001)  
	bool                                               bEnableScopedMovementUpdates : 1;                           // 0x01F0:7 (0x0001)  
	bool                                               bEnableServerDualMoveScopedMovementUpdates : 1;             // 0x01F1:0 (0x0001)  
	bool                                               bForceMaxAccel : 1;                                         // 0x01F1:1 (0x0001)  
	bool                                               bRunPhysicsWithNoController : 1;                            // 0x01F1:2 (0x0001)  
	bool                                               bForceNextFloorCheck : 1;                                   // 0x01F1:3 (0x0001)  
	bool                                               bShrinkProxyCapsule : 1;                                    // 0x01F1:4 (0x0001)  
	bool                                               bCanWalkOffLedges : 1;                                      // 0x01F1:5 (0x0001)  
	bool                                               bCanWalkOffLedgesWhenCrouching : 1;                         // 0x01F1:6 (0x0001)  
	unsigned char                                      UnknownBit04 : 1;                                           // 0x01F1:7 (0x0001)  MISSED
	unsigned char                                      UnknownBit05 : 1;                                           // 0x01F2:0 (0x0001)  MISSED
	bool                                               bNetworkSkipProxyPredictionOnNetUpdate : 1;                 // 0x01F2:1 (0x0001)  
	bool                                               bNetworkAlwaysReplicateTransformUpdateTimestamp : 1;        // 0x01F2:2 (0x0001)  
	bool                                               bDeferUpdateMoveComponent : 1;                              // 0x01F2:3 (0x0001)  
	bool                                               bEnablePhysicsInteraction : 1;                              // 0x01F2:4 (0x0001)  
	bool                                               bTouchForceScaledToMass : 1;                                // 0x01F2:5 (0x0001)  
	bool                                               bPushForceScaledToMass : 1;                                 // 0x01F2:6 (0x0001)  
	bool                                               bPushForceUsingZOffset : 1;                                 // 0x01F2:7 (0x0001)  
	bool                                               bScalePushForceToVelocity : 1;                              // 0x01F3:0 (0x0001)  
	unsigned char                                      UnknownData06_5[0x4];                                       // 0x01F4   (0x0004)  MISSED
	class USceneComponent* DeferredUpdatedMoveComponent;                               // 0x01F8   (0x0008)  
	float                                              MaxOutOfWaterStepHeight;                                    // 0x0200   (0x0004)  
	float                                              OutofWaterZ;                                                // 0x0204   (0x0004)  
	float                                              Mass;                                                       // 0x0208   (0x0004)  
	float                                              StandingDownwardForceScale;                                 // 0x020C   (0x0004)  
	float                                              InitialPushForceFactor;                                     // 0x0210   (0x0004)  
	float                                              PushForceFactor;                                            // 0x0214   (0x0004)  
	float                                              PushForcePointZOffsetFactor;                                // 0x0218   (0x0004)  
	float                                              TouchForceFactor;                                           // 0x021C   (0x0004)  
	float                                              MinTouchForce;                                              // 0x0220   (0x0004)  
	float                                              MaxTouchForce;                                              // 0x0224   (0x0004)  
	float                                              RepulsionForce;                                             // 0x0228   (0x0004)  
	FVector                                            Acceleration;                                               // 0x022C   (0x000C)  
	unsigned char                                      UnknownData07_6[0x8];                                       // 0x0238   (0x0008)  MISSED
	char                                              LastUpdateRotation[0x10];                                         // 0x0240   (0x0010)  
	FVector                                            LastUpdateLocation;                                         // 0x0250   (0x000C)  
	FVector                                            LastUpdateVelocity;                                         // 0x025C   (0x000C)  
	float                                              ServerLastTransformUpdateTimeStamp;                         // 0x0268   (0x0004)  
	float                                              ServerLastClientGoodMoveAckTime;                            // 0x026C   (0x0004)  
	float                                              ServerLastClientAdjustmentTime;                             // 0x0270   (0x0004)  
	FVector                                            PendingImpulseToApply;                                      // 0x0274   (0x000C)  
	FVector                                            PendingForceToApply;                                        // 0x0280   (0x000C)  
	float                                              AnalogInputModifier;                                        // 0x028C   (0x0004)  
	unsigned char                                      UnknownData08_6[0xC];                                       // 0x0290   (0x000C)  MISSED
	float                                              MaxSimulationTimeStep;                                      // 0x029C   (0x0004)  
	int32_t                                            MaxSimulationIterations;                                    // 0x02A0   (0x0004)  
	int32_t                                            MaxJumpApexAttemptsPerSimulation;                           // 0x02A4   (0x0004)  
	float                                              MaxDepenetrationWithGeometry;                               // 0x02A8   (0x0004)  
	float                                              MaxDepenetrationWithGeometryAsProxy;                        // 0x02AC   (0x0004)  
	float                                              MaxDepenetrationWithPawn;                                   // 0x02B0   (0x0004)  
	float                                              MaxDepenetrationWithPawnAsProxy;                            // 0x02B4   (0x0004)  
	float                                              NetworkSimulatedSmoothLocationTime;                         // 0x02B8   (0x0004)  
	float                                              NetworkSimulatedSmoothRotationTime;                         // 0x02BC   (0x0004)  
	float                                              ListenServerNetworkSimulatedSmoothLocationTime;             // 0x02C0   (0x0004)  
	float                                              ListenServerNetworkSimulatedSmoothRotationTime;             // 0x02C4   (0x0004)  
	float                                              NetProxyShrinkRadius;                                       // 0x02C8   (0x0004)  
	float                                              NetProxyShrinkHalfHeight;                                   // 0x02CC   (0x0004)  
	float                                              NetworkMaxSmoothUpdateDistance;                             // 0x02D0   (0x0004)  
	float                                              NetworkNoSmoothUpdateDistance;                              // 0x02D4   (0x0004)  
	float                                              NetworkMinTimeBetweenClientAckGoodMoves;                    // 0x02D8   (0x0004)  
	float                                              NetworkMinTimeBetweenClientAdjustments;                     // 0x02DC   (0x0004)  
	float                                              NetworkMinTimeBetweenClientAdjustmentsLargeCorrection;      // 0x02E0   (0x0004)  
	float                                              NetworkLargeClientCorrectionDistance;                       // 0x02E4   (0x0004)  
	float                                              LedgeCheckThreshold;                                        // 0x02E8   (0x0004)  
	float                                              JumpOutOfWaterPitch;                                        // 0x02EC   (0x0004)  
	char                                   CurrentFloor[0x98];                                               // 0x02F0   (0x0098)  
	char                         DefaultLandMovementMode;                                    // 0x0388   (0x0001)  
	char                         DefaultWaterMovementMode;                                   // 0x0389   (0x0001)  
	char                         GroundMovementMode;                                         // 0x038A   (0x0001)  
	bool                                               bMaintainHorizontalGroundVelocity : 1;                      // 0x038B:0 (0x0001)  
	bool                                               bImpartBaseVelocityX : 1;                                   // 0x038B:1 (0x0001)  
	bool                                               bImpartBaseVelocityY : 1;                                   // 0x038B:2 (0x0001)  
	bool                                               bImpartBaseVelocityZ : 1;                                   // 0x038B:3 (0x0001)  
	bool                                               bImpartBaseAngularVelocity : 1;                             // 0x038B:4 (0x0001)  
	bool                                               bJustTeleported : 1;                                        // 0x038B:5 (0x0001)  
	bool                                               bNetworkUpdateReceived : 1;                                 // 0x038B:6 (0x0001)  
	bool                                               bNetworkMovementModeChanged : 1;                            // 0x038B:7 (0x0001)  
	bool                                               bIgnoreClientMovementErrorChecksAndCorrection : 1;          // 0x038C:0 (0x0001)  
	bool                                               bServerAcceptClientAuthoritativePosition : 1;               // 0x038C:1 (0x0001)  
	bool                                               bNotifyApex : 1;                                            // 0x038C:2 (0x0001)  
	bool                                               bCheatFlying : 1;                                           // 0x038C:3 (0x0001)  
	bool                                               bWantsToCrouch : 1;                                         // 0x038C:4 (0x0001)  
	bool                                               bCrouchMaintainsBaseLocation : 1;                           // 0x038C:5 (0x0001)  
	bool                                               bIgnoreBaseRotation : 1;                                    // 0x038C:6 (0x0001)  
	bool                                               bFastAttachedMove : 1;                                      // 0x038C:7 (0x0001)  
	bool                                               bAlwaysCheckFloor : 1;                                      // 0x038D:0 (0x0001)  
	bool                                               bUseFlatBaseForFloorChecks : 1;                             // 0x038D:1 (0x0001)  
	bool                                               bPerformingJumpOff : 1;                                     // 0x038D:2 (0x0001)  
	bool                                               bWantsToLeaveNavWalking : 1;                                // 0x038D:3 (0x0001)  
	bool                                               bUseRVOAvoidance : 1;                                       // 0x038D:4 (0x0001)  
	bool                                               bRequestedMoveUseAcceleration : 1;                          // 0x038D:5 (0x0001)  
	unsigned char                                      UnknownBit09 : 1;                                           // 0x038D:6 (0x0001)  MISSED
	bool                                               bWasSimulatingRootMotion : 1;                               // 0x038D:7 (0x0001)  
	bool                                               bAllowPhysicsRotationDuringAnimRootMotion : 1;              // 0x038E:0 (0x0001)  
	bool                                               bHasRequestedVelocity : 1;                                  // 0x038E:1 (0x0001)  
	bool                                               bRequestedMoveWithMaxSpeed : 1;                             // 0x038E:2 (0x0001)  
	bool                                               bWasAvoidanceUpdated : 1;                                   // 0x038E:3 (0x0001)  
	unsigned char                                      UnknownBit10 : 1;                                           // 0x038E:4 (0x0001)  MISSED
	unsigned char                                      UnknownBit11 : 1;                                           // 0x038E:5 (0x0001)  MISSED
	bool                                               bProjectNavMeshWalking : 1;                                 // 0x038E:6 (0x0001)  
	bool                                               bProjectNavMeshOnBothWorldChannels : 1;                     // 0x038E:7 (0x0001)  
	unsigned char                                      UnknownData12_5[0x11];                                      // 0x038F   (0x0011)  MISSED
	float                                              AvoidanceConsiderationRadius;                               // 0x03A0   (0x0004)  
	FVector                                            RequestedVelocity;                                          // 0x03A4   (0x000C)  
	int32_t                                            AvoidanceUID;                                               // 0x03B0   (0x0004)  
	int                                  AvoidanceGroup;                                             // 0x03B4   (0x0004)  
	int                                  GroupsToAvoid;                                              // 0x03B8   (0x0004)  
	int                                  GroupsToIgnore;                                             // 0x03BC   (0x0004)  
	float                                              AvoidanceWeight;                                            // 0x03C0   (0x0004)  
	FVector                                            PendingLaunchVelocity;                                      // 0x03C4   (0x000C)  
	unsigned char                                      UnknownData13_6[0xA4];                                      // 0x03D0   (0x00A4)  MISSED
	float                                              NavMeshProjectionInterval;                                  // 0x0474   (0x0004)  
	float                                              NavMeshProjectionTimer;                                     // 0x0478   (0x0004)  
	float                                              NavMeshProjectionInterpSpeed;                               // 0x047C   (0x0004)  
	float                                              NavMeshProjectionHeightScaleUp;                             // 0x0480   (0x0004)  
	float                                              NavMeshProjectionHeightScaleDown;                           // 0x0484   (0x0004)  
	float                                              NavWalkingFloorDistTolerance;                               // 0x0488   (0x0004)  
	unsigned char                                      UnknownData14_6[0x4];                                       // 0x048C   (0x0004)  MISSED
	char PostPhysicsTickFunction[0x30];                                    // 0x0490   (0x0030)  
	unsigned char                                      UnknownData15_6[0x18];                                      // 0x04C0   (0x0018)  MISSED
	float                                              MinTimeBetweenTimeStampResets;                              // 0x04D8   (0x0004)  
	unsigned char                                      UnknownData16_6[0x4AC];                                     // 0x04DC   (0x04AC)  MISSED
	char                             CurrentRootMotion[0x38];                                          // 0x0988   (0x0038)  
	char                             ServerCorrectionRootMotion[0x38];                                 // 0x09C0   (0x0038)  
	unsigned char                                      UnknownData17_6[0x98];                                      // 0x09F8   (0x0098)  MISSED
	char                          RootMotionParams[0x40];                                           // 0x0A90   (0x0040)  
	FVector                                            AnimRootMotionVelocity;                                     // 0x0AD0   (0x000C)  
	unsigned char                                      UnknownData18_7[0x24];                                      // 0x0ADC   (0x0024)  MISSED


	/// Functions
	// Function /Script/Engine.CharacterMovementComponent.SetWalkableFloorZ
	// void SetWalkableFloorZ(float InWalkableFloorZ);                                                                          // [0x337d380] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetWalkableFloorAngle
	// void SetWalkableFloorAngle(float InWalkableFloorAngle);                                                                  // [0x337d300] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetMovementMode
	// void SetMovementMode(TEnumAsByte<EMovementMode> NewMovementMode, char NewCustomMode);                                    // [0x337d230] Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetGroupsToIgnoreMask
	// void SetGroupsToIgnoreMask(FNavAvoidanceMask& GroupMask);                                                                // [0x337d1a0] Final|Native|Public|HasOutParms|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetGroupsToIgnore
	// void SetGroupsToIgnore(int32_t GroupFlags);                                                                              // [0x337d110] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetGroupsToAvoidMask
	// void SetGroupsToAvoidMask(FNavAvoidanceMask& GroupMask);                                                                 // [0x337d080] Final|Native|Public|HasOutParms|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetGroupsToAvoid
	// void SetGroupsToAvoid(int32_t GroupFlags);                                                                               // [0x337cff0] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetAvoidanceGroupMask
	// void SetAvoidanceGroupMask(FNavAvoidanceMask& GroupMask);                                                                // [0x337cf60] Final|Native|Public|HasOutParms|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetAvoidanceGroup
	// void SetAvoidanceGroup(int32_t GroupFlags);                                                                              // [0x337ced0] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.SetAvoidanceEnabled
	// void SetAvoidanceEnabled(bool bEnable);                                                                                  // [0x337ce40] Final|Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.K2_GetWalkableFloorZ
	// float K2_GetWalkableFloorZ();                                                                                            // [0x337ce10] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.K2_GetWalkableFloorAngle
	// float K2_GetWalkableFloorAngle();                                                                                        // [0x337cde0] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.K2_GetModifiedMaxAcceleration
	// float K2_GetModifiedMaxAcceleration();                                                                                   // [0x337cda0] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.K2_FindFloor
	// void K2_FindFloor(FVector CapsuleLocation, FFindFloorResult& FloorResult);                                               // [0x337cc50] Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.K2_ComputeFloorDist
	// void K2_ComputeFloorDist(FVector CapsuleLocation, float LineDistance, float SweepDistance, float SweepRadius, FFindFloorResult& FloorResult); // [0x337ca40] Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.IsWalking
	// bool IsWalking();                                                                                                        // [0x337ca10] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.IsWalkable
	// bool IsWalkable(FHitResult& Hit);                                                                                        // [0x337c940] Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetValidPerchRadius
	// float GetValidPerchRadius();                                                                                             // [0x337c910] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetPerchRadiusThreshold
	// float GetPerchRadiusThreshold();                                                                                         // [0x337c8e0] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetMovementBase
	// class UPrimitiveComponent* GetMovementBase();                                                                            // [0x337c8b0] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetMinAnalogSpeed
	// float GetMinAnalogSpeed();                                                                                               // [0x337c870] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetMaxJumpHeightWithJumpTime
	// float GetMaxJumpHeightWithJumpTime();                                                                                    // [0x337c830] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetMaxJumpHeight
	// float GetMaxJumpHeight();                                                                                                // [0x337c7f0] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetMaxBrakingDeceleration
	// float GetMaxBrakingDeceleration();                                                                                       // [0x337c7b0] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetMaxAcceleration
	// float GetMaxAcceleration();                                                                                              // [0x337c770] Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetLastUpdateVelocity
	// FVector GetLastUpdateVelocity();                                                                                         // [0x337c740] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetLastUpdateRotation
	// FRotator GetLastUpdateRotation();                                                                                        // [0x337c6f0] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetLastUpdateLocation
	// FVector GetLastUpdateLocation();                                                                                         // [0x337c6c0] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetImpartedMovementBaseVelocity
	// FVector GetImpartedMovementBaseVelocity();                                                                               // [0x337c680] Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetCurrentAcceleration
	// FVector GetCurrentAcceleration();                                                                                        // [0x337c640] Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetCharacterOwner
	// class ACharacter* GetCharacterOwner();                                                                                   // [0x337c620] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.GetAnalogInputModifier
	// float GetAnalogInputModifier();                                                                                          // [0x337c5f0] Final|Native|Public|BlueprintCallable|BlueprintPure|Const 
	// Function /Script/Engine.CharacterMovementComponent.DisableMovement
	// void DisableMovement();                                                                                                  // [0x337c5d0] Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.ClearAccumulatedForces
	// void ClearAccumulatedForces();                                                                                           // [0x337c5b0] Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.CapsuleTouched
	// void CapsuleTouched(class UPrimitiveComponent* OverlappedComp, class AActor* Other, class UPrimitiveComponent* OtherComp, int32_t OtherBodyIndex, bool bFromSweep, FHitResult& SweepResult); // [0x337c3b0] Native|Protected|HasOutParms 
	// Function /Script/Engine.CharacterMovementComponent.CalcVelocity
	// void CalcVelocity(float DeltaTime, float Friction, bool bFluid, float BrakingDeceleration);                              // [0x337c240] Native|Public|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.AddImpulse
	// void AddImpulse(FVector Impulse, bool bVelocityChange);                                                                  // [0x337c160] Native|Public|HasDefaults|BlueprintCallable 
	// Function /Script/Engine.CharacterMovementComponent.AddForce
	// void AddForce(FVector Force);                                                                                            // [0x337c0d0] Native|Public|HasDefaults|BlueprintCallable 
};

class UBlueprintFunctionLibrary : public UObject
{
public:
};

class UGameplayStatics : public UBlueprintFunctionLibrary
{
public:
	void UnRetainAllSoundsInSoundClass(class USoundClass* InSoundClass);
	void UnloadStreamLevelBySoftObjectPtr(class UObject* WorldContextObject, const struct FLatentActionInfo& LatentInfo, bool bShouldBlockOnUnload);
	void UnLoadStreamLevel(class UObject* WorldContextObject, const class FName& LevelName, const struct FLatentActionInfo& LatentInfo, bool bShouldBlockOnUnload);
	bool SuggestProjectileVelocity_CustomArc(class UObject* WorldContextObject, struct FVector* OutLaunchVelocity, const struct FVector& StartPos, const struct FVector& EndPos, float OverrideGravityZ, float ArcParam);
	class UAudioComponent* SpawnSoundAttached(class USoundBase* Sound, class USceneComponent* AttachToComponent, const class FName& AttachPointName, const struct FVector& Location, const struct FRotator& Rotation, EAttachLocation LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings, class USoundConcurrency* ConcurrencySettings, bool bAutoDestroy);
	class UAudioComponent* SpawnSoundAtLocation(class UObject* WorldContextObject, class USoundBase* Sound, const struct FVector& Location, const struct FRotator& Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings, class USoundConcurrency* ConcurrencySettings, bool bAutoDestroy);
	class UAudioComponent* SpawnSound2D(class UObject* WorldContextObject, class USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundConcurrency* ConcurrencySettings, bool bPersistAcrossLevelTransition, bool bAutoDestroy);
	class UObject* SpawnObject(class UClass* ObjectClass, class UObject* Outer);
	class UForceFeedbackComponent* SpawnForceFeedbackAttached(class UForceFeedbackEffect* ForceFeedbackEffect, class USceneComponent* AttachToComponent, const class FName& AttachPointName, const struct FVector& Location, const struct FRotator& Rotation, EAttachLocation LocationType, bool bStopWhenAttachedToDestroyed, bool bLooping, float IntensityMultiplier, float StartTime, class UForceFeedbackAttenuation* AttenuationSettings, bool bAutoDestroy);
	class UForceFeedbackComponent* SpawnForceFeedbackAtLocation(class UObject* WorldContextObject, class UForceFeedbackEffect* ForceFeedbackEffect, const struct FVector& Location, const struct FRotator& Rotation, bool bLooping, float IntensityMultiplier, float StartTime, class UForceFeedbackAttenuation* AttenuationSettings, bool bAutoDestroy);
	class UParticleSystemComponent* SpawnEmitterAttached(class UParticleSystem* EmitterTemplate, class USceneComponent* AttachToComponent, const class FName& AttachPointName, const struct FVector& Location, const struct FRotator& Rotation, const struct FVector& Scale, EAttachLocation LocationType, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate);
	class UParticleSystemComponent* SpawnEmitterAtLocation(class UObject* WorldContextObject, class UParticleSystem* EmitterTemplate, const struct FVector& Location, const struct FRotator& Rotation, const struct FVector& Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivateSystem);
	class UAudioComponent* SpawnDialogueAttached(class UDialogueWave* Dialogue, const struct FDialogueContext& Context, class USceneComponent* AttachToComponent, const class FName& AttachPointName, const struct FVector& Location, const struct FRotator& Rotation, EAttachLocation LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings, bool bAutoDestroy);
	class UAudioComponent* SpawnDialogueAtLocation(class UObject* WorldContextObject, class UDialogueWave* Dialogue, const struct FDialogueContext& Context, const struct FVector& Location, const struct FRotator& Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings, bool bAutoDestroy);
	class UAudioComponent* SpawnDialogue2D(class UObject* WorldContextObject, class UDialogueWave* Dialogue, const struct FDialogueContext& Context, float VolumeMultiplier, float PitchMultiplier, float StartTime, bool bAutoDestroy);
	class UDecalComponent* SpawnDecalAttached(class UMaterialInterface* DecalMaterial, const struct FVector& DecalSize, class USceneComponent* AttachToComponent, const class FName& AttachPointName, const struct FVector& Location, const struct FRotator& Rotation, EAttachLocation LocationType, float LifeSpan);
	class UDecalComponent* SpawnDecalAtLocation(class UObject* WorldContextObject, class UMaterialInterface* DecalMaterial, const struct FVector& DecalSize, const struct FVector& Location, const struct FRotator& Rotation, float LifeSpan);
	void SetWorldOriginLocation(class UObject* WorldContextObject, const struct FIntVector& NewLocation);
	void SetViewportMouseCaptureMode(class UObject* WorldContextObject, EMouseCaptureMode MouseCaptureMode);
	void SetSubtitlesEnabled(bool bEnabled);
	void SetSoundMixClassOverride(class UObject* WorldContextObject, class USoundMix* InSoundMixModifier, class USoundClass* InSoundClass, float Volume, float Pitch, float FadeInTime, bool bApplyToChildren);
	void SetSoundClassDistanceScale(class UObject* WorldContextObject, class USoundClass* SoundClass, float DistanceAttenuationScale, float TimeSec);
	void SetPlayerControllerID(class APlayerController* Player, int32_t ControllerId);
	void SetMaxAudioChannelsScaled(class UObject* WorldContextObject, float MaxChannelCountScale);
	void SetGlobalTimeDilation(class UObject* WorldContextObject, float TimeDilation);
	void SetGlobalPitchModulation(class UObject* WorldContextObject, float PitchModulation, float TimeSec);
	void SetGlobalListenerFocusParameters(class UObject* WorldContextObject, float FocusAzimuthScale, float NonFocusAzimuthScale, float FocusDistanceScale, float NonFocusDistanceScale, float FocusVolumeScale, float NonFocusVolumeScale, float FocusPriorityScale, float NonFocusPriorityScale);
	bool SetGamePaused(class UObject* WorldContextObject, bool bPaused);
	void SetForceDisableSplitscreen(class UObject* WorldContextObject, bool bDisable);
	void SetEnableWorldRendering(class UObject* WorldContextObject, bool bEnable);
	void SetBaseSoundMix(class UObject* WorldContextObject, class USoundMix* InSoundMix);
	bool SaveGameToSlot(class USaveGame* SaveGameObject, const class FString& SlotName, int32_t UserIndex);
	void RemovePlayer(class APlayerController* Player, bool bDestroyPawn);
	struct FVector RebaseZeroOriginOntoLocal(class UObject* WorldContextObject, const struct FVector& WorldLocation);
	struct FVector RebaseLocalOriginOntoZero(class UObject* WorldContextObject, const struct FVector& WorldLocation);
	void PushSoundMixModifier(class UObject* WorldContextObject, class USoundMix* InSoundMixModifier);
	bool ProjectWorldToScreen(class APlayerController* Player, const struct FVector& WorldPosition, struct FVector2D* ScreenPosition, bool bPlayerViewportRelative);
	void PrimeSound(class USoundBase* InSound);
	void PrimeAllSoundsInSoundClass(class USoundClass* InSoundClass);
	void PopSoundMixModifier(class UObject* WorldContextObject, class USoundMix* InSoundMixModifier);
	void PlayWorldCameraShake(class UObject* WorldContextObject, class UClass* Shake, const struct FVector& Epicenter, float InnerRadius, float OuterRadius, float Falloff, bool bOrientShakeTowardsEpicenter);
	void PlaySoundAtLocation(class UObject* WorldContextObject, class USoundBase* Sound, const struct FVector& Location, const struct FRotator& Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings, class USoundConcurrency* ConcurrencySettings, class AActor* OwningActor);
	void PlaySound2D(class UObject* WorldContextObject, class USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundConcurrency* ConcurrencySettings, class AActor* OwningActor, bool bIsUISound);
	void PlayDialogueAtLocation(class UObject* WorldContextObject, class UDialogueWave* Dialogue, const struct FDialogueContext& Context, const struct FVector& Location, const struct FRotator& Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings);
	void PlayDialogue2D(class UObject* WorldContextObject, class UDialogueWave* Dialogue, const struct FDialogueContext& Context, float VolumeMultiplier, float PitchMultiplier, float StartTime);
	class FString ParseOption(const class FString& Options, const class FString& Key);
	void OpenLevelBySoftObjectPtr(class UObject* WorldContextObject, bool bAbsolute, const class FString& Options);
	void OpenLevel(class UObject* WorldContextObject, const class FName& LevelName, bool bAbsolute, const class FString& Options);
	struct FHitResult MakeHitResult(bool bBlockingHit, bool bInitialOverlap, float Time, float Distance, const struct FVector& Location, const struct FVector& ImpactPoint, const struct FVector& Normal, const struct FVector& ImpactNormal, class UPhysicalMaterial* PhysMat, class AActor* HitActor, class UPrimitiveComponent* HitComponent, const class FName& HitBoneName, int32_t HitItem, int32_t ElementIndex, int32_t FaceIndex, const struct FVector& TraceStart, const struct FVector& TraceEnd);
	void LoadStreamLevelBySoftObjectPtr(class UObject* WorldContextObject, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, const struct FLatentActionInfo& LatentInfo);
	void LoadStreamLevel(class UObject* WorldContextObject, const class FName& LevelName, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, const struct FLatentActionInfo& LatentInfo);
	class USaveGame* LoadGameFromSlot(const class FString& SlotName, int32_t UserIndex);
	bool IsSplitscreenForceDisabled(class UObject* WorldContextObject);
	bool IsGamePaused(class UObject* WorldContextObject);
	bool HasOption(const class FString& Options, const class FString& InKey);
	bool HasLaunchOption(const class FString& OptionToCheck);
	int32_t GrassOverlappingSphereCount(class UObject* WorldContextObject, class UStaticMesh* StaticMesh, const struct FVector& CenterPosition, float Radius);
	struct FIntVector GetWorldOriginLocation(class UObject* WorldContextObject);
	float GetWorldDeltaSeconds(class UObject* WorldContextObject);
	void GetViewProjectionMatrix(const struct FMinimalViewInfo& DesiredView, struct FMatrix* ViewMatrix, struct FMatrix* ProjectionMatrix, struct FMatrix* ViewProjectionMatrix);
	EMouseCaptureMode GetViewportMouseCaptureMode(class UObject* WorldContextObject);
	float GetUnpausedTimeSeconds(class UObject* WorldContextObject);
	float GetTimeSeconds(class UObject* WorldContextObject);
	EPhysicalSurface GetSurfaceType(const struct FHitResult& Hit);
	class ULevelStreaming* GetStreamingLevel(class UObject* WorldContextObject, const class FName& PackageName);
	float GetRealTimeSeconds(class UObject* WorldContextObject);
	class APawn* GetPlayerPawn(class UObject* WorldContextObject, int32_t PlayerIndex);
	int32_t GetPlayerControllerID(class APlayerController* Player);
	class APlayerController* GetPlayerControllerFromID(class UObject* WorldContextObject, int32_t ControllerId);
	class APlayerController* GetPlayerController(class UObject* WorldContextObject, int32_t PlayerIndex);
	class ACharacter* GetPlayerCharacter(class UObject* WorldContextObject, int32_t PlayerIndex);
	class APlayerCameraManager* GetPlayerCameraManager(class UObject* WorldContextObject, int32_t PlayerIndex);
	class FString GetPlatformName();
	class UClass* GetObjectClass(class UObject* Object);
	int32_t GetMaxAudioChannelCount(class UObject* WorldContextObject);
	void GetKeyValue(const class FString& Pair, class FString* Key, class FString* Value);
	int32_t GetIntOption(const class FString& Options, const class FString& Key, int32_t DefaultValue);
	float GetGlobalTimeDilation(class UObject* WorldContextObject);
	class AGameStateBase* GetGameState(class UObject* WorldContextObject);
	class AGameModeBase* GetGameMode(class UObject* WorldContextObject);
	class UGameInstance* GetGameInstance(class UObject* WorldContextObject);
	bool GetEnableWorldRendering(class UObject* WorldContextObject);
	class UReverbEffect* GetCurrentReverbEffect(class UObject* WorldContextObject);
	class FString GetCurrentLevelName(class UObject* WorldContextObject, bool bRemovePrefixString);
	bool GetClosestListenerLocation(class UObject* WorldContextObject, const struct FVector& Location, float MaximumRange, bool bAllowAttenuationOverride, struct FVector* ListenerPosition);
	float GetAudioTimeSeconds(class UObject* WorldContextObject);
	void GetAllActorsWithTag(class UObject* WorldContextObject, const class FName& Tag, TArray<class AActor*>* OutActors);
	void GetAllActorsWithInterface(class UObject* WorldContextObject, class UClass* Interface, TArray<class AActor*>* OutActors);
	void GetAllActorsOfClassWithTag(class UObject* WorldContextObject, class UClass* ActorClass, const class FName& Tag, TArray<class AActor*>* OutActors);
	void GetAllActorsOfClass(class UObject* WorldContextObject, class UClass* ActorClass, TArray<class AActor*>* OutActors);
	class AActor* GetActorOfClass(class UObject* WorldContextObject, class UClass* ActorClass);
	void GetActorArrayBounds(TArray<class AActor*> Actors, bool bOnlyCollidingComponents, struct FVector* Center, struct FVector* BoxExtent);
	struct FVector GetActorArrayAverageLocation(TArray<class AActor*> Actors);
	void GetAccurateRealTime(int32_t* Seconds, float* PartialSeconds);
	void FlushLevelStreaming(class UObject* WorldContextObject);
	class AActor* FinishSpawningActor(class AActor* Actor, const struct FTransform& SpawnTransform);
	class AActor* FindNearestActor(const struct FVector& Origin, TArray<class AActor*> ActorsToCheck, float* Distance);
	bool FindCollisionUV(const struct FHitResult& Hit, int32_t UVChannel, struct FVector2D* UV);
	void EnableLiveStreaming(bool enable);
	bool DoesSaveGameExist(const class FString& SlotName, int32_t UserIndex);
	bool DeprojectScreenToWorld(class APlayerController* Player, const struct FVector2D& ScreenPosition, struct FVector* WorldPosition, struct FVector* WorldDirection);
	bool DeleteGameInSlot(const class FString& SlotName, int32_t UserIndex);
	void DeactivateReverbEffect(class UObject* WorldContextObject, const class FName& TagName);
	class UAudioComponent* CreateSound2D(class UObject* WorldContextObject, class USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundConcurrency* ConcurrencySettings, bool bPersistAcrossLevelTransition, bool bAutoDestroy);
	class USaveGame* CreateSaveGameObject(class UClass* SaveGameClass);
	class APlayerController* CreatePlayer(class UObject* WorldContextObject, int32_t ControllerId, bool bSpawnPlayerController);
	void ClearSoundMixModifiers(class UObject* WorldContextObject);
	void ClearSoundMixClassOverride(class UObject* WorldContextObject, class USoundMix* InSoundMixModifier, class USoundClass* InSoundClass, float FadeOutTime);
	void CancelAsyncLoading();
	void BreakHitResult(const struct FHitResult& Hit, bool* bBlockingHit, bool* bInitialOverlap, float* Time, float* Distance, struct FVector* Location, struct FVector* ImpactPoint, struct FVector* Normal, struct FVector* ImpactNormal, class UPhysicalMaterial** PhysMat, class AActor** HitActor, class UPrimitiveComponent** HitComponent, class FName* HitBoneName, int32_t* HitItem, int32_t* ElementIndex, int32_t* FaceIndex, struct FVector* TraceStart, struct FVector* TraceEnd);
	bool BlueprintSuggestProjectileVelocity(class UObject* WorldContextObject, struct FVector* TossVelocity, const struct FVector& StartLocation, const struct FVector& EndLocation, float LaunchSpeed, float OverrideGravityZ, ESuggestProjVelocityTraceOption TraceOption, float CollisionRadius, bool bFavorHighArc, bool bDrawDebug);
	bool Blueprint_PredictProjectilePath_ByTraceChannel(class UObject* WorldContextObject, struct FHitResult* OutHit, TArray<struct FVector>* OutPathPositions, struct FVector* OutLastTraceDestination, const struct FVector& StartPos, const struct FVector& LaunchVelocity, bool bTracePath, float ProjectileRadius, ECollisionChannel TraceChannel, bool bTraceComplex, TArray<class AActor*> ActorsToIgnore, EDrawDebugTrace DrawDebugType, float DrawDebugTime, float SimFrequency, float MaxSimTime, float OverrideGravityZ);
	bool Blueprint_PredictProjectilePath_ByObjectType(class UObject* WorldContextObject, struct FHitResult* OutHit, TArray<struct FVector>* OutPathPositions, struct FVector* OutLastTraceDestination, const struct FVector& StartPos, const struct FVector& LaunchVelocity, bool bTracePath, float ProjectileRadius, TArray<EObjectTypeQuery> ObjectTypes, bool bTraceComplex, TArray<class AActor*> ActorsToIgnore, EDrawDebugTrace DrawDebugType, float DrawDebugTime, float SimFrequency, float MaxSimTime, float OverrideGravityZ);
	bool Blueprint_PredictProjectilePath_Advanced(class UObject* WorldContextObject, const struct FPredictProjectilePathParams& PredictParams, struct FPredictProjectilePathResult* PredictResult);
	class AActor* BeginSpawningActorFromClass(class UObject* WorldContextObject, class UClass* ActorClass, const struct FTransform& SpawnTransform, bool bNoCollisionFail, class AActor* Owner);
	class AActor* BeginSpawningActorFromBlueprint(class UObject* WorldContextObject, class UBlueprint* Blueprint, const struct FTransform& SpawnTransform, bool bNoCollisionFail);
	class AActor* BeginDeferredActorSpawnFromClass(class UObject* WorldContextObject, class UClass* ActorClass, const struct FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride, class AActor* Owner);
	bool AreSubtitlesEnabled();
	bool AreAnyListenersWithinRange(class UObject* WorldContextObject, const struct FVector& Location, float MaximumRange);
	bool ApplyRadialDamageWithFalloff(class UObject* WorldContextObject, float BaseDamage, float MinimumDamage, const struct FVector& Origin, float DamageInnerRadius, float DamageOuterRadius, float DamageFalloff, class UClass* DamageTypeClass, TArray<class AActor*> IgnoreActors, class AActor* DamageCauser, class AController* InstigatedByController, ECollisionChannel DamagePreventionChannel);
	bool ApplyRadialDamage(class UObject* WorldContextObject, float BaseDamage, const struct FVector& Origin, float DamageRadius, class UClass* DamageTypeClass, TArray<class AActor*> IgnoreActors, class AActor* DamageCauser, class AController* InstigatedByController, bool bDoFullDamage, ECollisionChannel DamagePreventionChannel);
	float ApplyPointDamage(class AActor* DamagedActor, float BaseDamage, const struct FVector& HitFromDirection, const struct FHitResult& HitInfo, class AController* EventInstigator, class AActor* DamageCauser, class UClass* DamageTypeClass);
	float ApplyDamage(class AActor* DamagedActor, float BaseDamage, class AController* EventInstigator, class AActor* DamageCauser, class UClass* DamageTypeClass);
	void AnnounceAccessibleString(const class FString& AnnouncementString);
	void ActivateReverbEffect(class UObject* WorldContextObject, class UReverbEffect* ReverbEffect, const class FName& TagName, float Priority, float Volume, float FadeTime);
	static UClass* StaticClass();
};

struct UGameplayStatics_GetAllActorsOfClass_Params
{
public:
	class UObject* WorldContextObject;                                      // 0x0000(0x0008)  (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UClass* ActorClass;                                              // 0x0008(0x0008)  (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class AActor*>                                      OutActors;                                               // 0x0010(0x0010)  (Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

class UFunction : public UStruct
{
public:
	unsigned char                                      UnknownData00_1[0x30];                                      // 0x00B0   (0x0030)  MISSED
};

class AHumanCharacter : public ACharacter
{
public:
	unsigned char                                      UnknownData00_8[0x8];                                       // 0x04C0   (0x0008)  MISSED
	char CloudLoadedAuthority[0x10];                               // 0x04C8   (0x0010)  
	char CloudLoadedClient[0x10];                                  // 0x04D8   (0x0010)  
	char AttachedCharactersChanged[0x10];                          // 0x04E8   (0x0010)  
	char PlayGestureDelegate[0x10];                                // 0x04F8   (0x0010)  
	char                                               AffiliationID;                                              // 0x0508   (0x0001)  
	unsigned char                                      UnknownData01_6[0x1];                                       // 0x0509   (0x0001)  MISSED
	bool                                               bIsAutonomous;                                              // 0x050A   (0x0001)  
	bool                                               bIsAutonomousOrAuthority;                                   // 0x050B   (0x0001)  
	unsigned char                                      UnknownData02_6[0x2];                                       // 0x050C   (0x0002)  MISSED
	bool                                               bEnableSkinDebug;                                           // 0x050E   (0x0001)  
	unsigned char                                      UnknownData03_6[0x1];                                       // 0x050F   (0x0001)  MISSED
	class UAccessorComponent* Accessor;                                                   // 0x0510   (0x0008)  
	class UInventoryComponent* Inventory;                                                  // 0x0518   (0x0008)  
	class UInventoryCustomizationComponent* Customization;                                              // 0x0520   (0x0008)  
	class UDefaultInventoryComponent* DefaultInventory;                                           // 0x0528   (0x0008)  
	class UStateMachineComponent* StateMachine;                                               // 0x0530   (0x0008)  
	class UGameplayActionsComponent* GameplayActions;                                            // 0x0538   (0x0008)  
	class UCanAimComponent* CanAimComponent;                                            // 0x0540   (0x0008)  
	class UCharacterHitZoneComponent* HitZoneManager;                                             // 0x0548   (0x0008)  
	class UWoundsManagerComponent* WoundsManagerComponent;                                     // 0x0550   (0x0008)  
	class UHealthComponent* HealthComponent;                                            // 0x0558   (0x0008)  
	class USkeletalMeshComponent* BaseMesh;                                                   // 0x0560   (0x0008)  
	class UUniformComponent* Uniform;                                                    // 0x0568   (0x0008)  
	class UHairComponent* Hair;                                                       // 0x0570   (0x0008)  
	class UHeadComponent* Head;                                                       // 0x0578   (0x0008)  
	class UGlovesComponent* Gloves;                                                     // 0x0580   (0x0008)  
	class UBackpackComponent* Backpack;                                                   // 0x0588   (0x0008)  
	class UHeadgearUpperComponent* HeadgearUpper;                                              // 0x0590   (0x0008)  
	class UHeadgearMiddleComponent* HeadgearMiddle;                                             // 0x0598   (0x0008)  
	class UHeadgearLowerComponent* HeadgearLower;                                              // 0x05A0   (0x0008)  
	unsigned char                                      UnknownData04_6[0x8];                                       // 0x05A8   (0x0008)  MISSED
	class UClass* FootStepClass;                                              // 0x05B0   (0x0008)  
	unsigned char                                      UnknownData05_6[0x8];                                       // 0x05B8   (0x0008)  MISSED
	class UClass* VegetationClass;                                            // 0x05C0   (0x0008)  
	unsigned char                                      UnknownData06_6[0x8];                                       // 0x05C8   (0x0008)  MISSED
	class UClass* StaminaClass;                                               // 0x05D0   (0x0008)  
	class UStaminaComponent* StaminaComponent;                                           // 0x05D8   (0x0008)  
	class UClass* PoiseClass;                                                 // 0x05E0   (0x0008)  
	class UPoiseComponent* PoiseComponent;                                             // 0x05E8   (0x0008)  
	class UClass* SpeedModifierClass;                                         // 0x05F0   (0x0008)  
	class USpeedModifierComponent* SpeedModifierComponent;                                     // 0x05F8   (0x0008)  
	class UClass* CameraManagerClass;                                         // 0x0600   (0x0008)  
	class UCameraManagerComponentBase* CameraManagerComponent;                                     // 0x0608   (0x0008)  
	class UDataTable* ArchetypeDataTable;                                         // 0x0610   (0x0008)  
	FName                                              ArchetypeName;                                              // 0x0618   (0x0008)  
	char                                       LastKnownLoadoutBeforeDeath[0x28];                                // 0x0620   (0x0028)  
	bool                                               bFireRequested;                                             // 0x0648   (0x0001)  
	bool                                               bAllowFire;                                                 // 0x0649   (0x0001)  
	unsigned char                                      UnknownData07_6[0x2];                                       // 0x064A   (0x0002)  MISSED
	float                                              ADSTransitionDelay;                                         // 0x064C   (0x0004)  
	unsigned char                                      UnknownData08_6[0x8];                                       // 0x0650   (0x0008)  MISSED
	bool                                               bIsADS;                                                     // 0x0658   (0x0001)  
	unsigned char                                      UnknownData09_6[0x2];                                       // 0x0659   (0x0002)  MISSED
	bool                                               bIsADSThrowable;                                            // 0x065B   (0x0001)  
	bool                                               bHasUsedThrowable;                                          // 0x065C   (0x0001)  
	unsigned char                                      UnknownData10_6[0xB];                                       // 0x065D   (0x000B)  MISSED
	float                                              InteractionADSMinTime;                                      // 0x0668   (0x0004)  
	unsigned char                                      UnknownData11_6[0x10];                                      // 0x066C   (0x0010)  MISSED
	float                                              ProneTransitionDispersion;                                  // 0x067C   (0x0004)  
	float                                              ProneTransitionDispersion1PV;                               // 0x0680   (0x0004)  
	bool                                               bInfiniteAmmo;                                              // 0x0684   (0x0001)  
	bool                                               bInfiniteReload;                                            // 0x0685   (0x0001)  
	bool                                               bAllowReload;                                               // 0x0686   (0x0001)  
	bool                                               bDebugAmmoReplication;                                      // 0x0687   (0x0001)  
	unsigned char                                      UnknownData12_6[0x10];                                      // 0x0688   (0x0010)  MISSED
	class UHumanAnimInstace* HumanAnimInstance;                                          // 0x0698   (0x0008)  
	unsigned char                                      UnknownData13_6[0x68];                                      // 0x06A0   (0x0068)  MISSED
	class UAudioComponent* BreathAudioComponent;                                       // 0x0708   (0x0008)  
	class ULayeredSoundAudioComponent* HeartbeatAudioComponent;                                    // 0x0710   (0x0008)  
	class UAudioComponent* Foley1AudioComponent;                                       // 0x0718   (0x0008)  
	class UAudioComponent* Foley2AudioComponent;                                       // 0x0720   (0x0008)  
	class UAudioComponent* WeaponRattleAudioComponent;                                 // 0x0728   (0x0008)  
	class UAudioComponent* LeftFootStepAudioComponent;                                 // 0x0730   (0x0008)  
	class UAudioComponent* RightFootStepAudioComponent;                                // 0x0738   (0x0008)  
	class UAudioComponent* LeftArmStepAudioComponent;                                  // 0x0740   (0x0008)  
	class UAudioComponent* RightArmStepAudioComponent;                                 // 0x0748   (0x0008)  
	class UAudioComponent* FoliageFoleyAudioComponent;                                 // 0x0750   (0x0008)  
	unsigned char                                      UnknownData14_6[0x80];                                      // 0x0758   (0x0080)  MISSED
	bool                                               bTriggerDown;                                               // 0x07D8   (0x0001)  
	unsigned char                                      UnknownData15_6[0x7];                                       // 0x07D9   (0x0007)  MISSED
	float                                              ProneAngleAdjustmentRate;                                   // 0x07E0   (0x0004)  
	float                                              ProneMaxAngleDiffMax;                                       // 0x07E4   (0x0004)  
	float                                              ProneMaxAngleDiffMin;                                       // 0x07E8   (0x0004)  
	float                                              ProneMaxAngleThresholdMax;                                  // 0x07EC   (0x0004)  
	float                                              ProneMaxAngleThresholdMin;                                  // 0x07F0   (0x0004)  
	float                                              ProneCrouchDelay;                                           // 0x07F4   (0x0004)  
	unsigned char                                      UnknownData16_6[0x10];                                      // 0x07F8   (0x0010)  MISSED
	float                                              MinAimPointDistance;                                        // 0x0808   (0x0004)  
	float                                              MinCharacterAimPointDistance;                               // 0x080C   (0x0004)  
	float                                              MaxAimPointDistance;                                        // 0x0810   (0x0004)  
	float                                              InteractionDistance;                                        // 0x0814   (0x0004)  
	bool                                               bCanToggleCrouch;                                           // 0x0818   (0x0001)  
	bool                                               bCanToggleProne;                                            // 0x0819   (0x0001)  
	bool                                               bCanToggleStand;                                            // 0x081A   (0x0001)  
	bool                                               bIsDigging;                                                 // 0x081B   (0x0001)  
	bool                                               bCanJumpHuman;                                              // 0x081C   (0x0001)  
	unsigned char                                      UnknownData17_6[0x7];                                       // 0x081D   (0x0007)  MISSED
	bool                                               IsSprintAllowed;                                            // 0x0824   (0x0001)  
	unsigned char                                      UnknownData18_6[0x3];                                       // 0x0825   (0x0003)  MISSED
	float                                              SprintBreachAngle;                                          // 0x0828   (0x0004)  
	unsigned char                                      UnknownData19_6[0x4];                                       // 0x082C   (0x0004)  MISSED
	float                                              CapsuleRotationRate;                                        // 0x0830   (0x0004)  
	char                                               DisableMovementCount;                                       // 0x0834   (0x0001)  
	unsigned char                                      UnknownData20_6[0x3];                                       // 0x0835   (0x0003)  MISSED
	float                                              WaterMovementModifier;                                      // 0x0838   (0x0004)  
	float                                              MovementDepthThreshold;                                     // 0x083C   (0x0004)  
	float                                              WaterTickInterval;                                          // 0x0840   (0x0004)  
	unsigned char                                      UnknownData21_6[0xC];                                       // 0x0844   (0x000C)  MISSED
	float                                              DashTimeout;                                                // 0x0850   (0x0004)  
	bool                                               bIsAiming;                                                  // 0x0854   (0x0001)  
	unsigned char                                      UnknownData22_6[0x3];                                       // 0x0855   (0x0003)  MISSED
	float                                              MaxAimBlockDistance;                                        // 0x0858   (0x0004)  
	bool                                               bBulletTrajectoryBlocked;                                   // 0x085C   (0x0001)  
	unsigned char                                      UnknownData23_6[0x7];                                       // 0x085D   (0x0007)  MISSED
	FVector                                            AimBlockedLocation;                                         // 0x0864   (0x000C)  
	unsigned char                                      UnknownData24_6[0x18];                                      // 0x0870   (0x0018)  MISSED
	uint16_t                                           CompressedLookRotation;                                     // 0x0888   (0x0002)  
	bool                                               bCanShootWhileJumping;                                      // 0x088A   (0x0001)  
	unsigned char                                      UnknownData25_6[0x1];                                       // 0x088B   (0x0001)  MISSED
	float                                              LookRotationInterpSpeed;                                    // 0x088C   (0x0004)  
	bool                                               bIsWeaponUp;                                                // 0x0890   (0x0001)  
	unsigned char                                      UnknownData26_6[0x7];                                       // 0x0891   (0x0007)  MISSED
	class UCurveFloat* FallDamageCurve;                                            // 0x0898   (0x0008)  
	class UCurveFloat* FallSlideDamageCurve;                                       // 0x08A0   (0x0008)  
	class UCurveFloat* FallDamageTimeThresholdCurve;                               // 0x08A8   (0x0008)  
	float                                              FallDamageWaterThreshold;                                   // 0x08B0   (0x0004)  
	float                                              FallDamageWaterMultiplier;                                  // 0x08B4   (0x0004)  
	float                                              ClimbVaultStaminaCostPercentage;                            // 0x08B8   (0x0004)  
	unsigned char                                      UnknownData27_6[0x4];                                       // 0x08BC   (0x0004)  MISSED
	class UCurveFloat* JumpCooldownCurve;                                          // 0x08C0   (0x0008)  
	float                                              DispersionAfterLandingTime;                                 // 0x08C8   (0x0004)  
	unsigned char                                      UnknownData28_6[0xC];                                       // 0x08CC   (0x000C)  MISSED
	class UCurveFloat* FallStunnedCurve;                                           // 0x08D8   (0x0008)  
	class UCurveFloat* FallSlowDownCurve;                                          // 0x08E0   (0x0008)  
	unsigned char                                      UnknownData29_6[0x8];                                       // 0x08E8   (0x0008)  MISSED
	class UCurveFloat* AttackMultiplierCurve;                                      // 0x08F0   (0x0008)  
	bool                                               FallShowDebug;                                              // 0x08F8   (0x0001)  
	unsigned char                                      UnknownData30_6[0x17];                                      // 0x08F9   (0x0017)  MISSED
	char                                               SimulatedInsufficientDistance;                              // 0x0910   (0x0001)  
	unsigned char                                      UnknownData31_6[0x7];                                       // 0x0911   (0x0007)  MISSED
	char OnCameraStateChanged[0x10];                               // 0x0918   (0x0010)  
	char OnStanceChanged[0x10];                                    // 0x0928   (0x0010)  
	unsigned char                                      UnknownData32_6[0x1C];                                      // 0x0938   (0x001C)  MISSED
	ECollisionChannel                     TraceChannel;                                               // 0x0954   (0x0001)  
	unsigned char                                      UnknownData33_6[0x3];                                       // 0x0955   (0x0003)  MISSED
	class UClass* CharOutline;                                                // 0x0958   (0x0008)  
	class UClass* AnimConfig;                                                 // 0x0960   (0x0008)  
	class USoundAttenuation* OwnerSoundAttenuation;                                      // 0x0968   (0x0008)  
	unsigned char                                      UnknownData34_6[0x34];                                      // 0x0970   (0x0034)  MISSED
	float                                              WaterPullStrength;                                          // 0x09A4   (0x0004)  
	float                                              WaterPushStrength;                                          // 0x09A8   (0x0004)  
	unsigned char                                      UnknownData35_6[0x2C];                                      // 0x09AC   (0x002C)  MISSED
	class UWaterComponent* WaterOverlapped;                                            // 0x09D8   (0x0008)  
	unsigned char                                      UnknownData36_6[0x19];                                      // 0x09E0   (0x0019)  MISSED
	bool                                               bLagSwitching;                                              // 0x09F9   (0x0001)  
	unsigned char                                      UnknownData37_6[0x6];                                       // 0x09FA   (0x0006)  MISSED
	int32_t                                            CharacterVersionServer;                                     // 0x0A00   (0x0004)  
	unsigned char                                      UnknownData38_6[0x2];                                       // 0x0A04   (0x0002)  MISSED
	bool                                               bAllowReloadWhenCannotAim;                                  // 0x0A06   (0x0001)  
	unsigned char                                      UnknownData39_6[0x1];                                       // 0x0A07   (0x0001)  MISSED
	float                                              FiredWeaponCooldownOnFireTime;                              // 0x0A08   (0x0004)  
	float                                              FireWeaponCooldownQuickMeleeTime;                           // 0x0A0C   (0x0004)  
	float                                              FireWeaponCooldownIsFiringTime;                             // 0x0A10   (0x0004)  
	float                                              FireWeaponCooldownIsFiringTimeMelee;                        // 0x0A14   (0x0004)  
	unsigned char                                      UnknownData40_6[0x18];                                      // 0x0A18   (0x0018)  MISSED
	class UInteractionActorComponent* InteractionActorComponent;                                  // 0x0A30   (0x0008)  
	unsigned char                                      UnknownData41_6[0x4];                                       // 0x0A38   (0x0004)  MISSED
	float                                              ProneClampAngle;                                            // 0x0A3C   (0x0004)  
	bool                                               bAllowProneRotateWhileUsingWeapon;                          // 0x0A40   (0x0001)  
	unsigned char                                      UnknownData42_6[0x6F];                                      // 0x0A41   (0x006F)  MISSED
	FVector                                            PlayerCameraStart;                                          // 0x0AB0   (0x000C)  
	FVector                                            PlayerCameraDirection;                                      // 0x0ABC   (0x000C)  
	char                                PlayerCameraStartServer[0xC];                                    // 0x0AC8   (0x000C)  
	char                              PlayerCameraDirectionServer[0xC];                                // 0x0AD4   (0x000C)  
	bool                                               ShouldUseBackpackSocketsForEquipment;                       // 0x0AE0   (0x0001)  
	unsigned char                                      UnknownData43_6[0x3];                                       // 0x0AE1   (0x0003)  MISSED
	float                                              WeaponCameraToSpecialSpeed;                                 // 0x0AE4   (0x0004)  
	float                                              WeaponCameraToRegularSpeed;                                 // 0x0AE8   (0x0004)  
	unsigned char                                      UnknownData44_6[0x3C];                                      // 0x0AEC   (0x003C)  MISSED
	float                                              MaxFallHeightForClimb;                                      // 0x0B28   (0x0004)  
	unsigned char                                      UnknownData45_6[0x8];                                       // 0x0B2C   (0x0008)  MISSED
	float                                              GrenadeBlockedThreshold;                                    // 0x0B34   (0x0004)  
	int32_t                                            LastItemDamageCauser;                                       // 0x0B38   (0x0004)  
	float                                              FlashbangMaxEffect;                                         // 0x0B3C   (0x0004)  
	float                                              ConcussionMaxEffect;                                        // 0x0B40   (0x0004)  
	unsigned char                                      UnknownData46_6[0x4];                                       // 0x0B44   (0x0004)  MISSED
	char DamagePercentageThroughMaterial[0x50];  // 0x0B48   (0x0050)  
	float                                              StaggerEffectStrength;                                      // 0x0B98   (0x0004)  
	unsigned char                                      UnknownData47_6[0x4];                                       // 0x0B9C   (0x0004)  MISSED
	float                                              StaggerEffectDuration;                                      // 0x0BA0   (0x0004)  
	float                                              StaggerDispersionMax;                                       // 0x0BA4   (0x0004)  
	float                                              AdrenalineBoostDuration;                                    // 0x0BA8   (0x0004)  
	unsigned char                                      UnknownData48_6[0x4];                                       // 0x0BAC   (0x0004)  MISSED
	FName                                              PhysicsHeadName;                                            // 0x0BB0   (0x0008)  
	bool                                               bMirrorPose;                                                // 0x0BB8   (0x0001)  
	unsigned char                                      UnknownData49_6[0x7];                                       // 0x0BB9   (0x0007)  MISSED
	TArray<class AHumanCharacter*>                     AttachedCharacters;                                         // 0x0BC0   (0x0010)  
	unsigned char                                      UnknownData50_7[0x30];                                      // 0x0BD0   (0x0030)  MISSED

};

class UKismetMathLibrary final : public UBlueprintFunctionLibrary
{
public:
	static float Abs(float A);
	static int32_t Abs_Int(int32_t A);
	static int64_t Abs_int64_t(int64_t A);
	static float Acos(float A);
	static uint8_t Add_ByteByte(uint8_t A, uint8_t B);
	static struct FDateTime Add_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static struct FDateTime Add_DateTimeTimespan(const struct FDateTime& A, const struct FTimespan& B);
	static float Add_FloatFloat(float A, float B);
	static int64_t Add_int64_tint64_t(int64_t A, int64_t B);
	static int32_t Add_IntInt(int32_t A, int32_t B);
	static struct FIntPoint Add_IntPointInt(const struct FIntPoint& A, int32_t B);
	static struct FIntPoint Add_IntPointIntPoint(const struct FIntPoint& A, const struct FIntPoint& B);
	static struct FLinearColor Add_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B);
	static struct FMatrix Add_MatrixMatrix(const struct FMatrix& A, const struct FMatrix& B);
	static struct FQuat Add_QuatQuat(const struct FQuat& A, const struct FQuat& B);
	static struct FTimespan Add_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static struct FVector2D Add_Vector2DFloat(const struct FVector2D& A, float B);
	static struct FVector2D Add_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static struct FVector4 Add_Vector4Vector4(const struct FVector4& A, const struct FVector4& B);
	static struct FVector Add_VectorFloat(const struct FVector& A, float B);
	static struct FVector Add_VectorInt(const struct FVector& A, int32_t B);
	static struct FVector Add_VectorVector(const struct FVector& A, const struct FVector& B);
	static int64_t And_int64_tint64_t(int64_t A, int64_t B);
	static int32_t And_IntInt(int32_t A, int32_t B);
	static float Asin(float A);
	static float Atan(float A);
	static float Atan2(float Y, float X);
	static uint8_t BMax(uint8_t A, uint8_t B);
	static uint8_t BMin(uint8_t A, uint8_t B);
	static bool BooleanAND(bool A, bool B);
	static bool BooleanNAND(bool A, bool B);
	static bool BooleanNOR(bool A, bool B);
	static bool BooleanOR(bool A, bool B);
	static bool BooleanXOR(bool A, bool B);
	static void BreakColor(const struct FLinearColor& InColor, float* R, float* G, float* B, float* A);
	static void BreakDateTime(const struct FDateTime& InDateTime, int32_t* Year, int32_t* Month, int32_t* Day, int32_t* Hour, int32_t* Minute, int32_t* Second, int32_t* Millisecond);
	static void BreakFrameRate(const struct FFrameRate& InFrameRate, int32_t* Numerator, int32_t* Denominator);
	static void BreakQualifiedFrameTime(const struct FQualifiedFrameTime& InFrameTime, struct FFrameNumber* Frame, struct FFrameRate* FrameRate, float* SubFrame);
	static void BreakRandomStream(const struct FRandomStream& InRandomStream, int32_t* InitialSeed);
	static void BreakRotator(const struct FRotator& InRot, float* Roll, float* Pitch, float* Yaw);
	static void BreakRotIntoAxes(const struct FRotator& InRot, struct FVector* X, struct FVector* Y, struct FVector* Z);
	static void BreakTimespan(const struct FTimespan& InTimespan, int32_t* Days, int32_t* Hours, int32_t* Minutes, int32_t* Seconds, int32_t* Milliseconds);
	static void BreakTimespan2(const struct FTimespan& InTimespan, int32_t* Days, int32_t* Hours, int32_t* Minutes, int32_t* Seconds, int32_t* FractionNano);
	static void BreakTransform(const struct FTransform& InTransform, struct FVector* Location, struct FRotator* Rotation, struct FVector* Scale);
	static void BreakVector(const struct FVector& InVec, float* X, float* Y, float* Z);
	static void BreakVector2D(const struct FVector2D& InVec, float* X, float* Y);
	static void BreakVector4(const struct FVector4& InVec, float* X, float* Y, float* Z, float* W);
	static struct FLinearColor CInterpTo(const struct FLinearColor& Current, const struct FLinearColor& Target, float DeltaTime, float InterpSpeed);
	static int32_t Clamp(int32_t Value, int32_t Min_0, int32_t Max_0);
	static float ClampAngle(float AngleDegrees, float MinAngleDegrees, float MaxAngleDegrees);
	static struct FVector2D ClampAxes2D(const struct FVector2D& A, float MinAxisVal, float MaxAxisVal);
	static float ClampAxis(float Angle);
	static int64_t Clampint64_t(int64_t Value, int64_t Min_0, int64_t Max_0);
	static struct FVector ClampVectorSize(const struct FVector& A, float Min_0, float Max_0);
	static bool ClassIsChildOf(class UObject TestClass, class UObject ParentClass);
	static struct FRotator ComposeRotators(const struct FRotator& A, const struct FRotator& B);
	static struct FTransform ComposeTransforms(const struct FTransform& A, const struct FTransform& B);
	static uint8_t Conv_BoolToByte(bool InBool);
	static float Conv_BoolToFloat(bool InBool);
	static int32_t Conv_BoolToInt(bool InBool);
	static float Conv_ByteToFloat(uint8_t InByte);
	static int32_t Conv_ByteToInt(uint8_t InByte);
	static struct FLinearColor Conv_ColorToLinearColor(const struct FColor& InColor);
	static struct FLinearColor Conv_FloatToLinearColor(float InFloat);
	static struct FVector Conv_FloatToVector(float InFloat);
	static uint8_t Conv_int64_tToByte(int64_t InInt);
	static int32_t Conv_int64_tToInt(int64_t InInt);
	static struct FVector2D Conv_IntPointToVector2D(const struct FIntPoint& InIntPoint);
	static bool Conv_IntToBool(int32_t InInt);
	static uint8_t Conv_IntToByte(int32_t InInt);
	static float Conv_IntToFloat(int32_t InInt);
	static int64_t Conv_IntToint64_t(int32_t InInt);
	static struct FIntVector Conv_IntToIntVector(int32_t InInt);
	static struct FVector Conv_IntVectorToVector(const struct FIntVector& InIntVector);
	static struct FColor Conv_LinearColorToColor(const struct FLinearColor& InLinearColor, bool InUseSRGB);
	static struct FVector Conv_LinearColorToVector(const struct FLinearColor& InLinearColor);
	static struct FRotator Conv_MatrixToRotator(const struct FMatrix& InMatrix);
	static struct FTransform Conv_MatrixToTransform(const struct FMatrix& InMatrix);
	static struct FTransform Conv_RotatorToTransform(const struct FRotator& InRotator);
	static struct FVector Conv_RotatorToVector(const struct FRotator& InRot);
	static struct FMatrix Conv_TransformToMatrix(const struct FTransform& Transform);
	static struct FIntPoint Conv_Vector2DToIntPoint(const struct FVector2D& InVector2D);
	static struct FVector Conv_Vector2DToVector(const struct FVector2D& InVector2D, float Z);
	static struct FQuat Conv_Vector4ToQuaternion(const struct FVector4& InVec);
	static struct FRotator Conv_Vector4ToRotator(const struct FVector4& InVec);
	static struct FVector Conv_Vector4ToVector(const struct FVector4& InVector4);
	static struct FLinearColor Conv_VectorToLinearColor(const struct FVector& InVec);
	static struct FQuat Conv_VectorToQuaternion(const struct FVector& InVec);
	static struct FRotator Conv_VectorToRotator(const struct FVector& InVec);
	static struct FTransform Conv_VectorToTransform(const struct FVector& InLocation);
	static struct FVector2D Conv_VectorToVector2D(const struct FVector& InVector);
	static struct FTransform ConvertTransformToRelative(const struct FTransform& Transform, const struct FTransform& ParentTransform);
	static float Cos(float A);
	static struct FVector CreateVectorFromYawPitch(float Yaw, float Pitch, float Length);
	static struct FVector Cross_VectorVector(const struct FVector& A, const struct FVector& B);
	static float CrossProduct2D(const struct FVector2D& A, const struct FVector2D& B);
	static bool DateTimeFromIsoString(const class FString& IsoString, struct FDateTime* Result);
	static bool DateTimeFromString(const class FString& DateTimeString, struct FDateTime* Result);
	static struct FDateTime DateTimeMaxValue();
	static struct FDateTime DateTimeMinValue();
	static int32_t DaysInMonth(int32_t Year, int32_t Month);
	static int32_t DaysInYear(int32_t Year);
	static float DegAcos(float A);
	static float DegAsin(float A);
	static float DegAtan(float A);
	static float DegAtan2(float Y, float X);
	static float DegCos(float A);
	static float DegreesToRadians(float A);
	static float DegSin(float A);
	static float DegTan(float A);
	static float Distance2D(const struct FVector2D& V1, const struct FVector2D& V2);
	static float DistanceSquared2D(const struct FVector2D& V1, const struct FVector2D& V2);
	static uint8_t Divide_ByteByte(uint8_t A, uint8_t B);
	static float Divide_FloatFloat(float A, float B);
	static int64_t Divide_int64_tint64_t(int64_t A, int64_t B);
	static int32_t Divide_IntInt(int32_t A, int32_t B);
	static struct FIntPoint Divide_IntPointInt(const struct FIntPoint& A, int32_t B);
	static struct FIntPoint Divide_IntPointIntPoint(const struct FIntPoint& A, const struct FIntPoint& B);
	static struct FLinearColor Divide_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B);
	static struct FTimespan Divide_TimespanFloat(const struct FTimespan& A, float Scalar);
	static struct FVector2D Divide_Vector2DFloat(const struct FVector2D& A, float B);
	static struct FVector2D Divide_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static struct FVector4 Divide_Vector4Vector4(const struct FVector4& A, const struct FVector4& B);
	static struct FVector Divide_VectorFloat(const struct FVector& A, float B);
	static struct FVector Divide_VectorInt(const struct FVector& A, int32_t B);
	static struct FVector Divide_VectorVector(const struct FVector& A, const struct FVector& B);
	static float Dot_VectorVector(const struct FVector& A, const struct FVector& B);
	static float DotProduct2D(const struct FVector2D& A, const struct FVector2D& B);
	static float DynamicWeightedMovingAverage_Float(float CurrentSample, float PreviousSample, float MaxDistance, float MinWeight, float MaxWeight);
	static struct FRotator DynamicWeightedMovingAverage_FRotator(const struct FRotator& CurrentSample, const struct FRotator& PreviousSample, float MaxDistance, float MinWeight, float MaxWeight);
	static struct FVector DynamicWeightedMovingAverage_FVector(const struct FVector& CurrentSample, const struct FVector& PreviousSample, float MaxDistance, float MinWeight, float MaxWeight);
	static float Ease(float A, float B, float Alpha, EEasingFunc EasingFunc, float BlendExp, int32_t Steps);
	static bool Equal_IntPointIntPoint(const struct FIntPoint& A, const struct FIntPoint& B);
	static bool EqualEqual_BoolBool(bool A, bool B);
	static bool EqualEqual_ByteByte(uint8_t A, uint8_t B);
	static bool EqualEqual_ClassClass(class UClass* A, class UClass* B);
	static bool EqualEqual_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static bool EqualEqual_FloatFloat(float A, float B);
	static bool EqualEqual_int64_tint64_t(int64_t A, int64_t B);
	static bool EqualEqual_IntInt(int32_t A, int32_t B);
	static bool EqualEqual_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B);
	static bool EqualEqual_MatrixMatrix(const struct FMatrix& A, const struct FMatrix& B, float Tolerance);
	static bool EqualEqual_NameName(class FName A, class FName B);
	static bool EqualEqual_ObjectObject(class UObject* A, class UObject* B);
	static bool EqualEqual_QuatQuat(const struct FQuat& A, const struct FQuat& B, float Tolerance);
	static bool EqualEqual_RotatorRotator(const struct FRotator& A, const struct FRotator& B, float ErrorTolerance);
	static bool EqualEqual_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static bool EqualEqual_TransformTransform(const struct FTransform& A, const struct FTransform& B);
	static bool EqualEqual_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B, float ErrorTolerance);
	static bool EqualEqual_Vector4Vector4(const struct FVector4& A, const struct FVector4& B, float ErrorTolerance);
	static bool EqualEqual_VectorVector(const struct FVector& A, const struct FVector& B, float ErrorTolerance);
	static bool EqualExactly_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static bool EqualExactly_Vector4Vector4(const struct FVector4& A, const struct FVector4& B);
	static bool EqualExactly_VectorVector(const struct FVector& A, const struct FVector& B);
	static float Exp(float A);
	static int32_t FCeil(float A);
	static int64_t FCeil64(float A);
	static float FClamp(float Value, float Min_0, float Max_0);
	static int32_t FFloor(float A);
	static int64_t FFloor64(float A);
	static struct FVector FindClosestPointOnLine(const struct FVector& Point, const struct FVector& LineOrigin, const struct FVector& LineDirection);
	static struct FVector FindClosestPointOnSegment(const struct FVector& Point, const struct FVector& SegmentStart, const struct FVector& SegmentEnd);
	struct FRotator FindLookAtRotation(const struct FVector& Start, const struct FVector& Target);
	static void FindNearestPointsOnLineSegments(const struct FVector& Segment1Start, const struct FVector& Segment1End, const struct FVector& Segment2Start, const struct FVector& Segment2End, struct FVector* Segment1Point, struct FVector* Segment2Point);
	static float FInterpEaseInOut(float A, float B, float Alpha, float Exponent);
	static float FInterpTo(float Current, float Target, float DeltaTime, float InterpSpeed);
	static float FInterpTo_Constant(float Current, float Target, float DeltaTime, float InterpSpeed);
	static float FixedTurn(float InCurrent, float InDesired, float InDeltaRate);
	static float FloatSpringInterp(float Current, float Target, struct FFloatSpringState& SpringState, float Stiffness, float CriticalDampingFactor, float DeltaTime, float Mass);
	static float FMax(float A, float B);
	static float FMin(float A, float B);
	static int32_t FMod(float Dividend, float Divisor, float* Remainder);
	static float Fraction(float A);
	static struct FTimespan FromDays(float Days);
	static struct FTimespan FromHours(float Hours);
	static struct FTimespan FromMilliseconds(float Milliseconds);
	static struct FTimespan FromMinutes(float Minutes);
	static struct FTimespan FromSeconds(float Seconds);
	static int32_t FTrunc(float A);
	static int64_t FTrunc64(float A);
	static struct FIntVector FTruncVector(const struct FVector& InVector);
	static float FWrap(float Value, float Min_0, float Max_0);
	static struct FVector2D GetAbs2D(const struct FVector2D& A);
	static float GetAbsMax2D(const struct FVector2D& A);
	static void GetAxes(const struct FRotator& A, struct FVector* X, struct FVector* Y, struct FVector* Z);
	static void GetAzimuthAndElevation(const struct FVector& InDirection, const struct FTransform& ReferenceFrame, float* Azimuth, float* Elevation);
	static struct FDateTime GetDate(const struct FDateTime& A);
	static int32_t GetDay(const struct FDateTime& A);
	static int32_t GetDayOfYear(const struct FDateTime& A);
	static int32_t GetDays(const struct FTimespan& A);
	static struct FVector GetDirectionUnitVector(const struct FVector& From, const struct FVector& To);
	static struct FTimespan GetDuration(const struct FTimespan& A);
	static struct FVector GetForwardVector(const struct FRotator& InRot);
	static int32_t GetHour(const struct FDateTime& A);
	static int32_t GetHour12(const struct FDateTime& A);
	static int32_t GetHours(const struct FTimespan& A);
	static float GetMax2D(const struct FVector2D& A);
	static float GetMaxElement(const struct FVector& A);
	static int32_t GetMillisecond(const struct FDateTime& A);
	static int32_t GetMilliseconds(const struct FTimespan& A);
	static float GetMin2D(const struct FVector2D& A);
	static float GetMinElement(const struct FVector& A);
	static int32_t GetMinute(const struct FDateTime& A);
	static int32_t GetMinutes(const struct FTimespan& A);
	static int32_t GetMonth(const struct FDateTime& A);
	static float GetPI();
	static float GetPointDistanceToLine(const struct FVector& Point, const struct FVector& LineOrigin, const struct FVector& LineDirection);
	static float GetPointDistanceToSegment(const struct FVector& Point, const struct FVector& SegmentStart, const struct FVector& SegmentEnd);
	static struct FVector GetReflectionVector(const struct FVector& Direction, const struct FVector& SurfaceNormal);
	static struct FVector GetRightVector(const struct FRotator& InRot);
	static struct FVector2D GetRotated2D(const struct FVector2D& A, float AngleDeg);
	static int32_t GetSecond(const struct FDateTime& A);
	static int32_t GetSeconds(const struct FTimespan& A);
	static void GetSlopeDegreeAngles(const struct FVector& MyRightYAxis, const struct FVector& FloorNormal, const struct FVector& UpVector, float* OutSlopePitchDegreeAngle, float* OutSlopeRollDegreeAngle);
	static float GetTAU();
	static struct FTimespan GetTimeOfDay(const struct FDateTime& A);
	static float GetTotalDays(const struct FTimespan& A);
	static float GetTotalHours(const struct FTimespan& A);
	static float GetTotalMilliseconds(const struct FTimespan& A);
	static float GetTotalMinutes(const struct FTimespan& A);
	static float GetTotalSeconds(const struct FTimespan& A);
	static struct FVector GetUpVector(const struct FRotator& InRot);
	static struct FVector GetVectorArrayAverage(const TArray<struct FVector>& Vectors);
	static void GetYawPitchFromVector(const struct FVector& InVec, float* Yaw, float* Pitch);
	static int32_t GetYear(const struct FDateTime& A);
	static bool Greater_ByteByte(uint8_t A, uint8_t B);
	static bool Greater_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static bool Greater_FloatFloat(float A, float B);
	static bool Greater_int64_tint64_t(int64_t A, int64_t B);
	static bool Greater_IntInt(int32_t A, int32_t B);
	static bool Greater_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static bool GreaterEqual_ByteByte(uint8_t A, uint8_t B);
	static bool GreaterEqual_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static bool GreaterEqual_FloatFloat(float A, float B);
	static bool GreaterEqual_int64_tint64_t(int64_t A, int64_t B);
	static bool GreaterEqual_IntInt(int32_t A, int32_t B);
	static bool GreaterEqual_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static struct FVector GreaterGreater_VectorRotator(const struct FVector& A, const struct FRotator& B);
	static float GridSnap_Float(float Location, float GridSize);
	static struct FLinearColor HSVToRGB(float H, float S, float V, float A);
	static void HSVToRGB_Vector(const struct FLinearColor& HSV, struct FLinearColor* RGB);
	static struct FLinearColor HSVToRGBLinear(const struct FLinearColor& HSV);
	static float Hypotenuse(float Width, float Height);
	static bool InRange_FloatFloat(float Value, float Min_0, float Max_0, bool InclusiveMin, bool InclusiveMax);
	static bool InRange_int64_tint64_t(int64_t Value, int64_t Min_0, int64_t Max_0, bool InclusiveMin, bool InclusiveMax);
	static bool InRange_IntInt(int32_t Value, int32_t Min_0, int32_t Max_0, bool InclusiveMin, bool InclusiveMax);
	static struct FIntPoint IntPoint_Down();
	static struct FIntPoint IntPoint_Left();
	static struct FIntPoint IntPoint_One();
	static struct FIntPoint IntPoint_Right();
	static struct FIntPoint IntPoint_Up();
	static struct FIntPoint IntPoint_Zero();
	static struct FVector InverseTransformDirection(const struct FTransform& T, const struct FVector& Direction);
	static struct FVector InverseTransformLocation(const struct FTransform& T, const struct FVector& Location);
	static struct FRotator InverseTransformRotation(const struct FTransform& T, const struct FRotator& Rotation);
	static struct FTransform InvertTransform(const struct FTransform& T);
	static bool IsAfternoon(const struct FDateTime& A);
	static bool IsLeapYear(int32_t Year);
	static bool IsMorning(const struct FDateTime& A);
	static bool IsNearlyZero2D(const struct FVector2D& A, float Tolerance);
	static bool IsPointInBox(const struct FVector& Point, const struct FVector& BoxOrigin, const struct FVector& BoxExtent);
	static bool IsPointInBoxWithTransform(const struct FVector& Point, const struct FTransform& BoxWorldTransform, const struct FVector& BoxExtent);
	static bool IsZero2D(const struct FVector2D& A);
	static float Lerp(float A, float B, float Alpha);
	static bool Less_ByteByte(uint8_t A, uint8_t B);
	static bool Less_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static bool Less_FloatFloat(float A, float B);
	static bool Less_int64_tint64_t(int64_t A, int64_t B);
	static bool Less_IntInt(int32_t A, int32_t B);
	static bool Less_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static bool LessEqual_ByteByte(uint8_t A, uint8_t B);
	static bool LessEqual_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static bool LessEqual_FloatFloat(float A, float B);
	static bool LessEqual_int64_tint64_t(int64_t A, int64_t B);
	static bool LessEqual_IntInt(int32_t A, int32_t B);
	static bool LessEqual_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static struct FVector LessLess_VectorRotator(const struct FVector& A, const struct FRotator& B);
	static struct FLinearColor LinearColor_Black();
	static struct FLinearColor LinearColor_Blue();
	static struct FLinearColor LinearColor_Desaturated(const struct FLinearColor& InColor, float InDesaturation);
	static float LinearColor_Distance(const struct FLinearColor& C1, const struct FLinearColor& C2);
	static float LinearColor_GetLuminance(const struct FLinearColor& InColor);
	static float LinearColor_GetMax(const struct FLinearColor& InColor);
	static float LinearColor_GetMin(const struct FLinearColor& InColor);
	static struct FLinearColor LinearColor_Gray();
	static struct FLinearColor LinearColor_Green();
	static bool LinearColor_IsNearEqual(const struct FLinearColor& A, const struct FLinearColor& B, float Tolerance);
	static struct FColor LinearColor_Quantize(const struct FLinearColor& InColor);
	static struct FColor LinearColor_QuantizeRound(const struct FLinearColor& InColor);
	static struct FLinearColor LinearColor_Red();
	static void LinearColor_Set(struct FLinearColor& InOutColor, const struct FLinearColor& InColor);
	static void LinearColor_SetFromHSV(struct FLinearColor& InOutColor, float H, float S, float V, float A);
	static void LinearColor_SetFromPow22(struct FLinearColor& InOutColor, const struct FColor& InColor);
	static void LinearColor_SetFromSRGB(struct FLinearColor& InOutColor, const struct FColor& InSRGB);
	static void LinearColor_SetRandomHue(struct FLinearColor& InOutColor);
	static void LinearColor_SetRGBA(struct FLinearColor& InOutColor, float R, float G, float B, float A);
	static void LinearColor_SetTemperature(struct FLinearColor& InOutColor, float InTemperature);
	static struct FLinearColor LinearColor_ToNewOpacity(const struct FLinearColor& InColor, float InOpacity);
	static struct FColor LinearColor_ToRGBE(const struct FLinearColor& InLinearColor);
	static struct FLinearColor LinearColor_Transparent();
	static struct FLinearColor LinearColor_White();
	static struct FLinearColor LinearColor_Yellow();
	static struct FLinearColor LinearColorLerp(const struct FLinearColor& A, const struct FLinearColor& B, float Alpha);
	static struct FLinearColor LinearColorLerpUsingHSV(const struct FLinearColor& A, const struct FLinearColor& B, float Alpha);
	static bool LinePlaneIntersection(const struct FVector& LineStart, const struct FVector& LineEnd, const struct FPlane& APlane, float* T, struct FVector* Intersection);
	static bool LinePlaneIntersection_OriginNormal(const struct FVector& LineStart, const struct FVector& LineEnd, const struct FVector& PlaneOrigin, const struct FVector& PlaneNormal, float* T, struct FVector* Intersection);
	static float Log(float A, float Base);
	static float Loge(float A);
	static struct FBox MakeBox(const struct FVector& Min_0, const struct FVector& Max_0);
	static struct FBox2D MakeBox2D(const struct FVector2D& Min_0, const struct FVector2D& Max_0);
	static struct FLinearColor MakeColor(float R, float G, float B, float A);
	static struct FDateTime MakeDateTime(int32_t Year, int32_t Month, int32_t Day, int32_t Hour, int32_t Minute, int32_t Second, int32_t Millisecond);
	static struct FFrameRate MakeFrameRate(int32_t Numerator, int32_t Denominator);
	static struct FPlane MakePlaneFromPointAndNormal(const struct FVector& Point, const struct FVector& Normal_0);
	static float MakePulsatingValue(float InCurrentTime, float InPulsesPerSecond, float InPhase);
	static struct FQualifiedFrameTime MakeQualifiedFrameTime(const struct FFrameNumber& Frame, const struct FFrameRate& FrameRate, float SubFrame);
	static struct FRandomStream MakeRandomStream(int32_t InitialSeed);
	static struct FTransform MakeRelativeTransform(const struct FTransform& A, const struct FTransform& RelativeTo);
	static struct FRotator MakeRotationFromAxes(const struct FVector& Forward, const struct FVector& Right, const struct FVector& Up);
	static struct FRotator MakeRotator(float Roll, float Pitch, float Yaw);
	static struct FRotator MakeRotFromX(const struct FVector& X);
	static struct FRotator MakeRotFromXY(const struct FVector& X, const struct FVector& Y);
	static struct FRotator MakeRotFromXZ(const struct FVector& X, const struct FVector& Z);
	static struct FRotator MakeRotFromY(const struct FVector& Y);
	static struct FRotator MakeRotFromYX(const struct FVector& Y, const struct FVector& X);
	static struct FRotator MakeRotFromYZ(const struct FVector& Y, const struct FVector& Z);
	static struct FRotator MakeRotFromZ(const struct FVector& Z);
	static struct FRotator MakeRotFromZX(const struct FVector& Z, const struct FVector& X);
	static struct FRotator MakeRotFromZY(const struct FVector& Z, const struct FVector& Y);
	static struct FTimespan MakeTimespan(int32_t Days, int32_t Hours, int32_t Minutes, int32_t Seconds, int32_t Milliseconds);
	static struct FTimespan MakeTimespan2(int32_t Days, int32_t Hours, int32_t Minutes, int32_t Seconds, int32_t FractionNano);
	static struct FTransform MakeTransform(const struct FVector& Location, const struct FRotator& Rotation, const struct FVector& Scale);
	static struct FVector MakeVector(float X, float Y, float Z);
	static struct FVector2D MakeVector2D(float X, float Y);
	static struct FVector4 MakeVector4(float X, float Y, float Z, float W);
	static float MapRangeClamped(float Value, float InRangeA, float InRangeB, float OutRangeA, float OutRangeB);
	static float MapRangeUnclamped(float Value, float InRangeA, float InRangeB, float OutRangeA, float OutRangeB);
	static struct FMatrix Matrix_ApplyScale(const struct FMatrix& M, float Scale);
	static struct FMatrix Matrix_ConcatenateTranslation(const struct FMatrix& M, const struct FVector& Translation);
	static bool Matrix_ContainsNaN(const struct FMatrix& M);
	static struct FVector Matrix_GetColumn(const struct FMatrix& M, EMatrixColumns Column);
	static float Matrix_GetDeterminant(const struct FMatrix& M);
	static bool Matrix_GetFrustumBottomPlane(const struct FMatrix& M, struct FPlane* OutPlane);
	static bool Matrix_GetFrustumFarPlane(const struct FMatrix& M, struct FPlane* OutPlane);
	static bool Matrix_GetFrustumLeftPlane(const struct FMatrix& M, struct FPlane* OutPlane);
	static bool Matrix_GetFrustumNearPlane(const struct FMatrix& M, struct FPlane* OutPlane);
	static bool Matrix_GetFrustumRightPlane(const struct FMatrix& M, struct FPlane* OutPlane);
	static bool Matrix_GetFrustumTopPlane(const struct FMatrix& M, struct FPlane* OutPlane);
	static struct FMatrix Matrix_GetInverse(const struct FMatrix& M);
	static struct FMatrix Matrix_GetMatrixWithoutScale(const struct FMatrix& M, float Tolerance);
	static float Matrix_GetMaximumAxisScale(const struct FMatrix& M);
	static struct FVector Matrix_GetOrigin(const struct FMatrix& InMatrix);
	static struct FRotator Matrix_GetRotator(const struct FMatrix& M);
	static float Matrix_GetRotDeterminant(const struct FMatrix& M);
	static void Matrix_GetScaledAxes(const struct FMatrix& M, struct FVector* X, struct FVector* Y, struct FVector* Z);
	static struct FVector Matrix_GetScaledAxis(const struct FMatrix& M, struct EAxis Axis);
	static struct FVector Matrix_GetScaleVector(const struct FMatrix& M, float Tolerance);
	static struct FMatrix Matrix_GetTransposeAdjoint(const struct FMatrix& M);
	static struct FMatrix Matrix_GetTransposed(const struct FMatrix& M);
	static void Matrix_GetUnitAxes(const struct FMatrix& M, struct FVector* X, struct FVector* Y, struct FVector* Z);
	static struct FVector Matrix_GetUnitAxis(const struct FMatrix& M, struct EAxis Axis);
	static struct FMatrix Matrix_Identity();
	static struct FVector Matrix_InverseTransformPosition(const struct FMatrix& M, const struct FVector& V);
	static struct FVector Matrix_InverseTransformVector(const struct FMatrix& M, const struct FVector& V);
	static struct FMatrix Matrix_Mirror(const struct FMatrix& M, struct EAxis MirrorAxis, struct EAxis FlipAxis);
	static void Matrix_RemoveScaling(struct FMatrix& M, float Tolerance);
	static struct FMatrix Matrix_RemoveTranslation(const struct FMatrix& M);
	static struct FMatrix Matrix_ScaleTranslation(const struct FMatrix& M, const struct FVector& Scale3D);
	static void Matrix_SetAxis(struct FMatrix& M, struct EAxis Axis, const struct FVector& AxisVector);
	static void Matrix_SetColumn(struct FMatrix& M, EMatrixColumns Column, const struct FVector& Value);
	static void Matrix_SetOrigin(struct FMatrix& M, const struct FVector& NewOrigin);
	static struct FQuat Matrix_ToQuat(const struct FMatrix& M);
	static struct FVector4 Matrix_TransformPosition(const struct FMatrix& M, const struct FVector& V);
	static struct FVector4 Matrix_TransformVector(const struct FMatrix& M, const struct FVector& V);
	static struct FVector4 Matrix_TransformVector4(const struct FMatrix& M, const struct FVector4& V);
	static int32_t Max(int32_t A, int32_t B);
	static int64_t Maxint64_t(int64_t A, int64_t B);
	static void MaxOfByteArray(const TArray<uint8_t>& ByteArray, int32_t* IndexOfMaxValue, uint8_t* MaxValue);
	static void MaxOfFloatArray(const TArray<float>& FloatArray, int32_t* IndexOfMaxValue, float* MaxValue);
	static void MaxOfIntArray(const TArray<int32_t>& IntArray, int32_t* IndexOfMaxValue, int32_t* MaxValue);
	static int32_t Min(int32_t A, int32_t B);
	static void MinimumAreaRectangle(class UObject* WorldContextObject, const TArray<struct FVector>& InVerts, const struct FVector& SampleSurfaceNormal, struct FVector* OutRectCenter, struct FRotator* OutRectRotation, float* OutSideLengthX, float* OutSideLengthY, bool bDebugDraw);
	static int64_t Minint64_t(int64_t A, int64_t B);
	static void MinOfByteArray(const TArray<uint8_t>& ByteArray, int32_t* IndexOfMinValue, uint8_t* MinValue);
	static void MinOfFloatArray(const TArray<float>& FloatArray, int32_t* IndexOfMinValue, float* MinValue);
	static void MinOfIntArray(const TArray<int32_t>& IntArray, int32_t* IndexOfMinValue, int32_t* MinValue);
	static struct FVector MirrorVectorByNormal(const struct FVector& InVect, const struct FVector& InNormal);
	static uint8_t Multiply_ByteByte(uint8_t A, uint8_t B);
	static float Multiply_FloatFloat(float A, float B);
	static int64_t Multiply_int64_tint64_t(int64_t A, int64_t B);
	static float Multiply_IntFloat(int32_t A, float B);
	static int32_t Multiply_IntInt(int32_t A, int32_t B);
	static struct FIntPoint Multiply_IntPointInt(const struct FIntPoint& A, int32_t B);
	static struct FIntPoint Multiply_IntPointIntPoint(const struct FIntPoint& A, const struct FIntPoint& B);
	static struct FLinearColor Multiply_LinearColorFloat(const struct FLinearColor& A, float B);
	static struct FLinearColor Multiply_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B);
	static struct FMatrix Multiply_MatrixFloat(const struct FMatrix& A, float B);
	static struct FMatrix Multiply_MatrixMatrix(const struct FMatrix& A, const struct FMatrix& B);
	static struct FQuat Multiply_QuatQuat(const struct FQuat& A, const struct FQuat& B);
	static struct FRotator Multiply_RotatorFloat(const struct FRotator& A, float B);
	static struct FRotator Multiply_RotatorInt(const struct FRotator& A, int32_t B);
	static struct FTimespan Multiply_TimespanFloat(const struct FTimespan& A, float Scalar);
	static struct FVector2D Multiply_Vector2DFloat(const struct FVector2D& A, float B);
	static struct FVector2D Multiply_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static struct FVector4 Multiply_Vector4Vector4(const struct FVector4& A, const struct FVector4& B);
	static struct FVector Multiply_VectorFloat(const struct FVector& A, float B);
	static struct FVector Multiply_VectorInt(const struct FVector& A, int32_t B);
	static struct FVector Multiply_VectorVector(const struct FVector& A, const struct FVector& B);
	static float MultiplyByPi(float Value);
	static float MultiplyMultiply_FloatFloat(float Base, float Exp);
	static bool NearlyEqual_FloatFloat(float A, float B, float ErrorTolerance);
	static bool NearlyEqual_TransformTransform(const struct FTransform& A, const struct FTransform& B, float LocationTolerance, float RotationTolerance, float Scale3DTolerance);
	static struct FVector2D Negated2D(const struct FVector2D& A);
	static struct FRotator NegateRotator(const struct FRotator& A);
	static struct FVector NegateVector(const struct FVector& A);
	static struct FVector Normal(const struct FVector& A, float Tolerance);
	static struct FVector2D Normal2D(const struct FVector2D& A);
	static void Normalize2D(struct FVector2D& A, float Tolerance);
	static float NormalizeAxis(float Angle);
	static struct FRotator NormalizedDeltaRotator(const struct FRotator& A, const struct FRotator& B);
	static float NormalizeToRange(float Value, float RangeMin, float RangeMax);
	static struct FVector2D NormalSafe2D(const struct FVector2D& A, float Tolerance);
	static int32_t Not_Int(int32_t A);
	static int64_t Not_int64_t(int64_t A);
	static bool Not_PreBool(bool A);
	static bool NotEqual_BoolBool(bool A, bool B);
	static bool NotEqual_ByteByte(uint8_t A, uint8_t B);
	static bool NotEqual_ClassClass(class UClass* A, class UClass* B);
	static bool NotEqual_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static bool NotEqual_FloatFloat(float A, float B);
	static bool NotEqual_int64_tint64_t(int64_t A, int64_t B);
	static bool NotEqual_IntInt(int32_t A, int32_t B);
	static bool NotEqual_IntPointIntPoint(const struct FIntPoint& A, const struct FIntPoint& B);
	static bool NotEqual_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B);
	static bool NotEqual_MatrixMatrix(const struct FMatrix& A, const struct FMatrix& B, float Tolerance);
	static bool NotEqual_NameName(class FName A, class FName B);
	static bool NotEqual_ObjectObject(class UObject* A, class UObject* B);
	static bool NotEqual_QuatQuat(const struct FQuat& A, const struct FQuat& B, float ErrorTolerance);
	static bool NotEqual_RotatorRotator(const struct FRotator& A, const struct FRotator& B, float ErrorTolerance);
	static bool NotEqual_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static bool NotEqual_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B, float ErrorTolerance);
	static bool NotEqual_Vector4Vector4(const struct FVector4& A, const struct FVector4& B, float ErrorTolerance);
	static bool NotEqual_VectorVector(const struct FVector& A, const struct FVector& B, float ErrorTolerance);
	static bool NotEqualExactly_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static bool NotEqualExactly_Vector4Vector4(const struct FVector4& A, const struct FVector4& B);
	static bool NotEqualExactly_VectorVector(const struct FVector& A, const struct FVector& B);
	static struct FDateTime Now();
	static int64_t Or_int64_tint64_t(int64_t A, int64_t B);
	static int32_t Or_IntInt(int32_t A, int32_t B);
	static uint8_t Percent_ByteByte(uint8_t A, uint8_t B);
	static float Percent_FloatFloat(float A, float B);
	static int32_t Percent_IntInt(int32_t A, int32_t B);
	static float PerlinNoise1D(const float Value);
	static bool PointsAreCoplanar(const TArray<struct FVector>& Points, float Tolerance);
	static struct FVector ProjectPointOnToPlane(const struct FVector& Point, const struct FVector& PlaneBase, const struct FVector& PlaneNormal);
	static struct FVector ProjectVectorOnToPlane(const struct FVector& V, const struct FVector& PlaneNormal);
	static struct FVector ProjectVectorOnToVector(const struct FVector& V, const struct FVector& Target);
	static float Quat_AngularDistance(const struct FQuat& A, const struct FQuat& B);
	static void Quat_EnforceShortestArcWith(struct FQuat& A, const struct FQuat& B);
	static struct FVector Quat_Euler(const struct FQuat& Q);
	static struct FQuat Quat_Exp(const struct FQuat& Q);
	static float Quat_GetAngle(const struct FQuat& Q);
	static struct FVector Quat_GetAxisX(const struct FQuat& Q);
	static struct FVector Quat_GetAxisY(const struct FQuat& Q);
	static struct FVector Quat_GetAxisZ(const struct FQuat& Q);
	static struct FVector Quat_GetRotationAxis(const struct FQuat& Q);
	static struct FQuat Quat_Identity();
	static struct FQuat Quat_Inversed(const struct FQuat& Q);
	static bool Quat_IsFinite(const struct FQuat& Q);
	static bool Quat_IsIdentity(const struct FQuat& Q, float Tolerance);
	static bool Quat_IsNonFinite(const struct FQuat& Q);
	static bool Quat_IsNormalized(const struct FQuat& Q);
	static struct FQuat Quat_Log(const struct FQuat& Q);
	static struct FQuat Quat_MakeFromEuler(const struct FVector& Euler);
	static void Quat_Normalize(struct FQuat& Q, float Tolerance);
	static struct FQuat Quat_Normalized(const struct FQuat& Q, float Tolerance);
	static struct FVector Quat_RotateVector(const struct FQuat& Q, const struct FVector& V);
	static struct FRotator Quat_Rotator(const struct FQuat& Q);
	static void Quat_SetComponents(struct FQuat& Q, float X, float Y, float Z, float W);
	static void Quat_SetFromEuler(struct FQuat& Q, const struct FVector& Euler);
	static float Quat_Size(const struct FQuat& Q);
	static float Quat_SizeSquared(const struct FQuat& Q);
	static struct FVector Quat_UnrotateVector(const struct FQuat& Q, const struct FVector& V);
	static struct FVector Quat_VectorForward(const struct FQuat& Q);
	static struct FVector Quat_VectorRight(const struct FQuat& Q);
	static struct FVector Quat_VectorUp(const struct FQuat& Q);
	static float RadiansToDegrees(float A);
	static bool RandomBool();
	static bool RandomBoolFromStream(const struct FRandomStream& Stream);
	static bool RandomBoolWithWeight(float Weight);
	static bool RandomBoolWithWeightFromStream(float Weight, const struct FRandomStream& RandomStream);
	static float RandomFloat();
	static float RandomFloatFromStream(const struct FRandomStream& Stream);
	static float RandomFloatInRange(float Min, float Max);
	static float RandomFloatInRangeFromStream(float Min, float Max, const struct FRandomStream& Stream);
	static int32_t RandomInteger(int32_t Max);
	static int64_t RandomInteger64(int64_t Max);
	static int64_t RandomInteger64InRange(int64_t Min, int64_t Max);
	static int32_t RandomIntegerFromStream(int32_t Max, const struct FRandomStream& Stream);
	static int32_t RandomIntegerInRange(int32_t Min, int32_t Max);
	static int32_t RandomIntegerInRangeFromStream(int32_t Min, int32_t Max, const struct FRandomStream& Stream);
	static struct FVector RandomPointInBoundingBox(const struct FVector& Origin, const struct FVector& BoxExtent);
	static struct FRotator RandomRotator(bool bRoll);
	static struct FRotator RandomRotatorFromStream(bool bRoll, const struct FRandomStream& Stream);
	static struct FVector RandomUnitVector();
	static struct FVector RandomUnitVectorFromStream(const struct FRandomStream& Stream);
	static struct FVector RandomUnitVectorInConeInDegrees(const struct FVector& ConeDir, float ConeHalfAngleInDegrees);
	static struct FVector RandomUnitVectorInConeInDegreesFromStream(const struct FVector& ConeDir, float ConeHalfAngleInDegrees, const struct FRandomStream& Stream);
	static struct FVector RandomUnitVectorInConeInRadians(const struct FVector& ConeDir, float ConeHalfAngleInRadians);
	static struct FVector RandomUnitVectorInConeInRadiansFromStream(const struct FVector& ConeDir, float ConeHalfAngleInRadians, const struct FRandomStream& Stream);
	static struct FVector RandomUnitVectorInEllipticalConeInDegrees(const struct FVector& ConeDir, float MaxYawInDegrees, float MaxPitchInDegrees);
	static struct FVector RandomUnitVectorInEllipticalConeInDegreesFromStream(const struct FVector& ConeDir, float MaxYawInDegrees, float MaxPitchInDegrees, const struct FRandomStream& Stream);
	static struct FVector RandomUnitVectorInEllipticalConeInRadians(const struct FVector& ConeDir, float MaxYawInRadians, float MaxPitchInRadians);
	static struct FVector RandomUnitVectorInEllipticalConeInRadiansFromStream(const struct FVector& ConeDir, float MaxYawInRadians, float MaxPitchInRadians, const struct FRandomStream& Stream);
	static struct FRotator REase(const struct FRotator& A, const struct FRotator& B, float Alpha, bool bShortestPath, EEasingFunc EasingFunc, float BlendExp, int32_t Steps);
	static void ResetFloatSpringState(struct FFloatSpringState& SpringState);
	static void ResetRandomStream(const struct FRandomStream& Stream);
	static void ResetVectorSpringState(struct FVectorSpringState& SpringState);
	static struct FLinearColor RGBLinearToHSV(const struct FLinearColor& RGB);
	static void RGBToHSV(const struct FLinearColor& InColor, float* H, float* S, float* V, float* A);
	static void RGBToHSV_Vector(const struct FLinearColor& RGB, struct FLinearColor* HSV);
	static struct FRotator RInterpTo(const struct FRotator& Current, const struct FRotator& Target, float DeltaTime, float InterpSpeed);
	static struct FRotator RInterpTo_Constant(const struct FRotator& Current, const struct FRotator& Target, float DeltaTime, float InterpSpeed);
	static struct FRotator RLerp(const struct FRotator& A, const struct FRotator& B, float Alpha, bool bShortestPath);
	static struct FVector RotateAngleAxis(const struct FVector& InVect, float AngleDeg, const struct FVector& Axis);
	static struct FRotator RotatorFromAxisAndAngle(const struct FVector& Axis, float Angle);
	static int32_t Round(float A);
	static int64_t Round64(float A);
	static float SafeDivide(float A, float B);
	static void SeedRandomStream(struct FRandomStream& Stream);
	static class UClass* SelectClass(class UClass* A, class UClass* B, bool bSelectA);
	static struct FLinearColor SelectColor(const struct FLinearColor& A, const struct FLinearColor& B, bool bPickA);
	static float SelectFloat(float A, float B, bool bPickA);
	static int32_t SelectInt(int32_t A, int32_t B, bool bPickA);
	static class UObject* SelectObject(class UObject* A, class UObject* B, bool bSelectA);
	static struct FRotator SelectRotator(const struct FRotator& A, const struct FRotator& B, bool bPickA);
	static class FString SelectString(const class FString& A, const class FString& B, bool bPickA);
	static struct FTransform SelectTransform(const struct FTransform& A, const struct FTransform& B, bool bPickA);
	static struct FVector SelectVector(const struct FVector& A, const struct FVector& B, bool bPickA);
	static void Set2D(struct FVector2D& A, float X, float Y);
	static void SetRandomStreamSeed(struct FRandomStream& Stream, int32_t NewSeed);
	static float SignOfFloat(float A);
	static int32_t SignOfInteger(int32_t A);
	static int64_t SignOfInteger64(int64_t A);
	static float Sin(float A);
	static struct FVector Spherical2DToUnitCartesian(const struct FVector2D& A);
	static float Sqrt(float A);
	static float Square(float A);
	static uint8_t Subtract_ByteByte(uint8_t A, uint8_t B);
	static struct FTimespan Subtract_DateTimeDateTime(const struct FDateTime& A, const struct FDateTime& B);
	static struct FDateTime Subtract_DateTimeTimespan(const struct FDateTime& A, const struct FTimespan& B);
	static float Subtract_FloatFloat(float A, float B);
	static int64_t Subtract_int64_tint64_t(int64_t A, int64_t B);
	static int32_t Subtract_IntInt(int32_t A, int32_t B);
	static struct FIntPoint Subtract_IntPointInt(const struct FIntPoint& A, int32_t B);
	static struct FIntPoint Subtract_IntPointIntPoint(const struct FIntPoint& A, const struct FIntPoint& B);
	static struct FLinearColor Subtract_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B);
	static struct FQuat Subtract_QuatQuat(const struct FQuat& A, const struct FQuat& B);
	static struct FTimespan Subtract_TimespanTimespan(const struct FTimespan& A, const struct FTimespan& B);
	static struct FVector2D Subtract_Vector2DFloat(const struct FVector2D& A, float B);
	static struct FVector2D Subtract_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static struct FVector4 Subtract_Vector4Vector4(const struct FVector4& A, const struct FVector4& B);
	static struct FVector Subtract_VectorFloat(const struct FVector& A, float B);
	static struct FVector Subtract_VectorInt(const struct FVector& A, int32_t B);
	static struct FVector Subtract_VectorVector(const struct FVector& A, const struct FVector& B);
	static float Tan(float A);
	static struct FTransform TEase(const struct FTransform& A, const struct FTransform& B, float Alpha, EEasingFunc EasingFunc, float BlendExp, int32_t Steps);
	static bool TimespanFromString(const class FString& TimespanString, struct FTimespan* Result);
	static struct FTimespan TimespanMaxValue();
	static struct FTimespan TimespanMinValue();
	static float TimespanRatio(const struct FTimespan& A, const struct FTimespan& B);
	static struct FTimespan TimespanZeroValue();
	static struct FTransform TInterpTo(const struct FTransform& Current, const struct FTransform& Target, float DeltaTime, float InterpSpeed);
	static struct FTransform TLerp(const struct FTransform& A, const struct FTransform& B, float Alpha, ELerpInterpolationMode InterpMode);
	static struct FDateTime Today();
	static void ToDirectionAndLength2D(const struct FVector2D& A, struct FVector2D* OutDir, float* OutLength);
	static struct FVector2D ToRounded2D(const struct FVector2D& A);
	static struct FVector2D ToSign2D(const struct FVector2D& A);
	static float Transform_Determinant(const struct FTransform& Transform);
	static struct FVector TransformDirection(const struct FTransform& T, const struct FVector& Direction);
	static struct FVector TransformLocation(const struct FTransform& T, const struct FVector& Location);
	static struct FRotator TransformRotation(const struct FTransform& T, const struct FRotator& Rotation);
	static struct FVector4 TransformVector4(const struct FMatrix& Matrix, const struct FVector4& Vec4);
	static struct FDateTime UtcNow();
	static struct FVector VEase(const struct FVector& A, const struct FVector& B, float Alpha, EEasingFunc EasingFunc, float BlendExp, int32_t Steps);
	static struct FVector2D Vector2D_One();
	static struct FVector2D Vector2D_Unit45Deg();
	static struct FVector2D Vector2D_Zero();
	static struct FVector2D Vector2DInterpTo(const struct FVector2D& Current, const struct FVector2D& Target, float DeltaTime, float InterpSpeed);
	static struct FVector2D Vector2DInterpTo_Constant(const struct FVector2D& Current, const struct FVector2D& Target, float DeltaTime, float InterpSpeed);
	static void Vector4_Assign(struct FVector4& A, const struct FVector4& InVector);
	static struct FVector4 Vector4_CrossProduct3(const struct FVector4& A, const struct FVector4& B);
	static float Vector4_DotProduct(const struct FVector4& A, const struct FVector4& B);
	static float Vector4_DotProduct3(const struct FVector4& A, const struct FVector4& B);
	static bool Vector4_IsNAN(const struct FVector4& A);
	static bool Vector4_IsNearlyZero3(const struct FVector4& A, float Tolerance);
	static bool Vector4_IsNormal3(const struct FVector4& A);
	static bool Vector4_IsUnit3(const struct FVector4& A, float SquaredLenthTolerance);
	static bool Vector4_IsZero(const struct FVector4& A);
	static struct FVector4 Vector4_MirrorByVector3(const struct FVector4& Direction, const struct FVector4& SurfaceNormal);
	static struct FVector4 Vector4_Negated(const struct FVector4& A);
	static struct FVector4 Vector4_Normal3(const struct FVector4& A, float Tolerance);
	static void Vector4_Normalize3(struct FVector4& A, float Tolerance);
	static struct FVector4 Vector4_NormalUnsafe3(const struct FVector4& A);
	static void Vector4_Set(struct FVector4& A, float X, float Y, float Z, float W);
	static float Vector4_Size(const struct FVector4& A);
	static float Vector4_Size3(const struct FVector4& A);
	static float Vector4_SizeSquared(const struct FVector4& A);
	static float Vector4_SizeSquared3(const struct FVector4& A);
	static struct FVector4 Vector4_Zero();
	static void Vector_AddBounded(struct FVector& A, const struct FVector& InAddVect, float InRadius);
	static void Vector_Assign(struct FVector& A, const struct FVector& InVector);
	static struct FVector Vector_Backward();
	static struct FVector Vector_BoundedToBox(const struct FVector& InVect, const struct FVector& InBoxMin, const struct FVector& InBoxMax);
	static struct FVector Vector_BoundedToCube(const struct FVector& InVect, float InRadius);
	static struct FVector Vector_ClampSize2D(const struct FVector& A, float Min, float Max);
	static struct FVector Vector_ClampSizeMax(const struct FVector& A, float Max);
	static struct FVector Vector_ClampSizeMax2D(const struct FVector& A, float Max);
	static struct FVector Vector_ComponentMax(const struct FVector& A, const struct FVector& B);
	static struct FVector Vector_ComponentMin(const struct FVector& A, const struct FVector& B);
	static float Vector_CosineAngle2D(const struct FVector& A, const struct FVector& B);
	static float Vector_Distance(const struct FVector& V1, const struct FVector& V2);
	static float Vector_Distance2D(const struct FVector& V1, const struct FVector& V2);
	static float Vector_Distance2DSquared(const struct FVector& V1, const struct FVector& V2);
	static float Vector_DistanceSquared(const struct FVector& V1, const struct FVector& V2);
	static struct FVector Vector_Down();
	static struct FVector Vector_Forward();
	static struct FVector Vector_GetAbs(const struct FVector& A);
	static float Vector_GetAbsMax(const struct FVector& A);
	static float Vector_GetAbsMin(const struct FVector& A);
	static struct FVector Vector_GetProjection(const struct FVector& A);
	static struct FVector Vector_GetSignVector(const struct FVector& A);
	static float Vector_HeadingAngle(const struct FVector& A);
	static bool Vector_IsNAN(const struct FVector& A);
	static bool Vector_IsNearlyZero(const struct FVector& A, float Tolerance);
	static bool Vector_IsNormal(const struct FVector& A);
	static bool Vector_IsUniform(const struct FVector& A, float Tolerance);
	static bool Vector_IsUnit(const struct FVector& A, float SquaredLenthTolerance);
	static bool Vector_IsZero(const struct FVector& A);
	static struct FVector Vector_Left();
	static struct FVector Vector_MirrorByPlane(const struct FVector& A, const struct FPlane& InPlane);
	static struct FVector Vector_Normal2D(const struct FVector& A, float Tolerance);
	static void Vector_Normalize(struct FVector& A, float Tolerance);
	static struct FVector Vector_NormalUnsafe(const struct FVector& A);
	static struct FVector Vector_One();
	static struct FVector Vector_ProjectOnToNormal(const struct FVector& V, const struct FVector& InNormal);
	static struct FVector Vector_Reciprocal(const struct FVector& A);
	static struct FVector Vector_Right();
	static void Vector_Set(struct FVector& A, float X, float Y, float Z);
	static struct FVector Vector_SnappedToGrid(const struct FVector& InVect, float InGridSize);
	static struct FVector Vector_ToDegrees(const struct FVector& A);
	static struct FVector Vector_ToRadians(const struct FVector& A);
	static struct FVector2D Vector_UnitCartesianToSpherical(const struct FVector& A);
	static void Vector_UnwindEuler(struct FVector& A);
	static struct FVector Vector_Up();
	static struct FVector Vector_Zero();
	static struct FVector VectorSpringInterp(const struct FVector& Current, const struct FVector& Target, struct FVectorSpringState& SpringState, float Stiffness, float CriticalDampingFactor, float DeltaTime, float Mass);
	struct FVector VInterpTo(FVector Current, FVector Target, float DeltaTime, float InterpSpeed);
	static struct FVector VInterpTo_Constant(const struct FVector& Current, const struct FVector& Target, float DeltaTime, float InterpSpeed);
	static struct FVector VLerp(const struct FVector& A, const struct FVector& B, float Alpha);
	static float VSize(const struct FVector& A);
	static float VSize2D(const struct FVector2D& A);
	static float VSize2DSquared(const struct FVector2D& A);
	static float VSizeSquared(const struct FVector& A);
	static float VSizeXY(const struct FVector& A);
	static float VSizeXYSquared(const struct FVector& A);
	static float WeightedMovingAverage_Float(float CurrentSample, float PreviousSample, float Weight);
	static struct FRotator WeightedMovingAverage_FRotator(const struct FRotator& CurrentSample, const struct FRotator& PreviousSample, float Weight);
	static struct FVector WeightedMovingAverage_FVector(const struct FVector& CurrentSample, const struct FVector& PreviousSample, float Weight);
	static int32_t Wrap(int32_t Value, int32_t Min, int32_t Max);
	static int64_t Xor_int64_tint64_t(int64_t A, int64_t B);
	static int32_t Xor_IntInt(int32_t A, int32_t B);
};

class UMaterialInterface : public UObject
{
public:
	unsigned char                                      UnknownData00_8[0x10];                                      // 0x0028   (0x0010)  MISSED
	class USubsurfaceProfile* SubsurfaceProfile;                                          // 0x0038   (0x0008)  
	unsigned char                                      UnknownData01_6[0x10];                                      // 0x0040   (0x0010)  MISSED
	char                LightmassSettings[0x10];                                          // 0x0050   (0x0010)  
	TArray<struct FMaterialTextureInfo>                       TextureStreamingData;                                       // 0x0060   (0x0010)  
	TArray<class UAssetUserData*>                      AssetUserData;                                              // 0x0070   (0x0010)  
	unsigned char                                      UnknownData02_7[0x8];                                       // 0x0080   (0x0008)  MISSED
};

class UMaterial : public UMaterialInterface
{
public:
	class UPhysicalMaterial* PhysMaterial;                                               // 0x0088   (0x0008)  
	class UPhysicalMaterialMask* PhysMaterialMask;                                           // 0x0090   (0x0008)  
	class UPhysicalMaterial* PhysicalMaterialMap[8];                                     // 0x0098   (0x0040)  
	char                               Metallic[0x14];                                                   // 0x00D8   (0x0014)  
	char                               Specular[0x14];                                                   // 0x00EC   (0x0014)  
	char                               Anisotropy[0x14];                                                 // 0x0100   (0x0014)  
	char                               Normal[0x14];                                                     // 0x0114   (0x0014)  
	char                               Tangent[0x14];                                                    // 0x0128   (0x0014)  
	char                                EmissiveColor[0x14];                                              // 0x013C   (0x0014)  
	EMaterialDomain                      MaterialDomain;                                             // 0x0150   (0x0001)  
	EBlendMode                            BlendMode;                                                  // 0x0151   (0x0001)  
	EDecalBlendMode                       DecalBlendMode;                                             // 0x0152   (0x0001)  
	EMaterialDecalResponse                MaterialDecalResponse;                                      // 0x0153   (0x0001)  
	EMaterialShadingModel                 ShadingModel;                                               // 0x0154   (0x0001)  
	bool                                               bCastDynamicShadowAsMasked : 1;                             // 0x0155:0 (0x0001)  
	char                         ShadingModels[0x2];                                              // 0x0156   (0x0002)  
	float                                              OpacityMaskClipValue;                                       // 0x0158   (0x0004)  
	char                               WorldPositionOffset[0x14];                                        // 0x015C   (0x0014)  
	char                               Refraction[0x14];                                                 // 0x0170   (0x0014)  
	char                           MaterialAttributes[0x18];                                         // 0x0184   (0x0018)  
	char                               PixelDepthOffset[0x14];                                           // 0x019C   (0x0014)  
	char                               RainParameters[0x14];                                             // 0x01B0   (0x0014)  
	char                         ShadingModelFromMaterialExpression[0x14];                         // 0x01C4   (0x0014)  
	bool                                               bEnableSeparateTranslucency : 1;                            // 0x01D8:0 (0x0001)  
	bool                                               bEnableResponsiveAA : 1;                                    // 0x01D8:1 (0x0001)  
	bool                                               bScreenSpaceReflections : 1;                                // 0x01D8:2 (0x0001)  
	bool                                               bContactShadows : 1;                                        // 0x01D8:3 (0x0001)  
	bool                                               TwoSided : 1;                                               // 0x01D8:4 (0x0001)  
	bool                                               DitheredLODTransition : 1;                                  // 0x01D8:5 (0x0001)  
	bool                                               DitherOpacityMask : 1;                                      // 0x01D8:6 (0x0001)  
	bool                                               bAllowNegativeEmissiveColor : 1;                            // 0x01D8:7 (0x0001)  
	ETranslucencyLightingMode             TranslucencyLightingMode;                                   // 0x01D9   (0x0001)  
	bool                                               bEnableMobileSeparateTranslucency : 1;                      // 0x01DA:0 (0x0001)  
	unsigned char                                      UnknownData00_5[0x1];                                       // 0x01DB   (0x0001)  MISSED
	int32_t                                            NumCustomizedUVs;                                           // 0x01DC   (0x0004)  
	float                                              TranslucencyDirectionalLightingIntensity;                   // 0x01E0   (0x0004)  
	float                                              TranslucentShadowDensityScale;                              // 0x01E4   (0x0004)  
	float                                              TranslucentSelfShadowDensityScale;                          // 0x01E8   (0x0004)  
	float                                              TranslucentSelfShadowSecondDensityScale;                    // 0x01EC   (0x0004)  
	float                                              TranslucentSelfShadowSecondOpacity;                         // 0x01F0   (0x0004)  
	float                                              TranslucentBackscatteringExponent;                          // 0x01F4   (0x0004)  
	FLinearColor                                       TranslucentMultipleScatteringExtinction;                    // 0x01F8   (0x0010)  
	float                                              TranslucentShadowStartOffset;                               // 0x0208   (0x0004)  
	bool                                               bDisableDepthTest : 1;                                      // 0x020C:0 (0x0001)  
	bool                                               bWriteOnlyAlpha : 1;                                        // 0x020C:1 (0x0001)  
	bool                                               bGenerateSphericalParticleNormals : 1;                      // 0x020C:2 (0x0001)  
	bool                                               bTangentSpaceNormal : 1;                                    // 0x020C:3 (0x0001)  
	bool                                               bUseEmissiveForDynamicAreaLighting : 1;                     // 0x020C:4 (0x0001)  
	bool                                               bBlockGI : 1;                                               // 0x020C:5 (0x0001)  
	bool                                               bUsedAsSpecialEngineMaterial : 1;                           // 0x020C:6 (0x0001)  
	bool                                               bUsedWithSkeletalMesh : 1;                                  // 0x020C:7 (0x0001)  
	bool                                               bUsedWithEditorCompositing : 1;                             // 0x020D:0 (0x0001)  
	bool                                               bUsedWithParticleSprites : 1;                               // 0x020D:1 (0x0001)  
	bool                                               bUsedWithBeamTrails : 1;                                    // 0x020D:2 (0x0001)  
	bool                                               bUsedWithMeshParticles : 1;                                 // 0x020D:3 (0x0001)  
	bool                                               bUsedWithNiagaraSprites : 1;                                // 0x020D:4 (0x0001)  
	bool                                               bUsedWithNiagaraRibbons : 1;                                // 0x020D:5 (0x0001)  
	bool                                               bUsedWithNiagaraMeshParticles : 1;                          // 0x020D:6 (0x0001)  
	bool                                               bUsedWithGeometryCache : 1;                                 // 0x020D:7 (0x0001)  
	bool                                               bUsedWithStaticLighting : 1;                                // 0x020E:0 (0x0001)  
	bool                                               bUsedWithMorphTargets : 1;                                  // 0x020E:1 (0x0001)  
	bool                                               bUsedWithSplineMeshes : 1;                                  // 0x020E:2 (0x0001)  
	bool                                               bUsedWithInstancedStaticMeshes : 1;                         // 0x020E:3 (0x0001)  
	bool                                               bUsedWithGeometryCollections : 1;                           // 0x020E:4 (0x0001)  
	bool                                               bUsesDistortion : 1;                                        // 0x020E:5 (0x0001)  
	bool                                               bUsedWithClothing : 1;                                      // 0x020E:6 (0x0001)  
	unsigned char                                      UnknownData01_3[0x1];                                       // 0x020F   (0x0001)  MISSED
	bool                                               bUsedWithWater : 1;                                         // 0x0210:0 (0x0001)  
	bool                                               bUsedWithHairStrands : 1;                                   // 0x0210:1 (0x0001)  
	bool                                               bUsedWithLidarPointCloud : 1;                               // 0x0210:2 (0x0001)  
	bool                                               bUsedWithVirtualHeightfieldMesh : 1;                        // 0x0210:3 (0x0001)  
	unsigned char                                      UnknownData02_3[0x3];                                       // 0x0211   (0x0003)  MISSED
	bool                                               bUsedWithUI : 1;                                            // 0x0214:0 (0x0001)  
	bool                                               bAutomaticallySetUsageInEditor : 1;                         // 0x0214:1 (0x0001)  
	bool                                               bFullyRough : 1;                                            // 0x0214:2 (0x0001)  
	bool                                               bUseFullPrecision : 1;                                      // 0x0214:3 (0x0001)  
	bool                                               bUseLightmapDirectionality : 1;                             // 0x0214:4 (0x0001)  
	bool                                               bUseAlphaToCoverage : 1;                                    // 0x0214:5 (0x0001)  
	unsigned char                                      UnknownData03_3[0x3];                                       // 0x0215   (0x0003)  MISSED
	bool                                               bForwardRenderUsePreintegratedGFForSimpleIBL : 1;           // 0x0218:0 (0x0001)  
	unsigned char                                      UnknownData04_3[0x3];                                       // 0x0219   (0x0003)  MISSED
	bool                                               bUseHQForwardReflections : 1;                               // 0x021C:0 (0x0001)  
	bool                                               bForwardBlendsSkyLightCubemaps : 1;                         // 0x021C:1 (0x0001)  
	bool                                               bUsePlanarForwardReflections : 1;                           // 0x021C:2 (0x0001)  
	bool                                               bNormalCurvatureToRoughness : 1;                            // 0x021C:3 (0x0001)  
	EMaterialTessellationMode             D3D11TessellationMode;                                      // 0x021D   (0x0001)  
	bool                                               bEnableCrackFreeDisplacement : 1;                           // 0x021E:0 (0x0001)  
	bool                                               bEnableAdaptiveTessellation : 1;                            // 0x021E:1 (0x0001)  
	bool                                               AllowTranslucentCustomDepthWrites : 1;                      // 0x021E:2 (0x0001)  
	bool                                               Wireframe : 1;                                              // 0x021E:3 (0x0001)  
	bool                                               WriteDepthToTranslucentMaterial : 1;                        // 0x021E:4 (0x0001)  
	EMaterialShadingRate                  ShadingRate;                                                // 0x021F   (0x0001)  
	bool                                               bCanMaskedBeAssumedOpaque : 1;                              // 0x0220:0 (0x0001)  
	bool                                               bIsMasked : 1;                                              // 0x0220:1 (0x0001)  
	bool                                               bIsPreviewMaterial : 1;                                     // 0x0220:2 (0x0001)  
	bool                                               bIsFunctionPreviewMaterial : 1;                             // 0x0220:3 (0x0001)  
	bool                                               bUseMaterialAttributes : 1;                                 // 0x0220:4 (0x0001)  
	bool                                               bCastRayTracedShadows : 1;                                  // 0x0220:5 (0x0001)  
	bool                                               bUseTranslucencyVertexFog : 1;                              // 0x0220:6 (0x0001)  
	bool                                               bApplyCloudFogging : 1;                                     // 0x0220:7 (0x0001)  
	bool                                               bIsSky : 1;                                                 // 0x0221:0 (0x0001)  
	bool                                               bComputeFogPerPixel : 1;                                    // 0x0221:1 (0x0001)  
	bool                                               bOutputTranslucentVelocity : 1;                             // 0x0221:2 (0x0001)  
	bool                                               bAllowDevelopmentShaderCompile : 1;                         // 0x0221:3 (0x0001)  
	bool                                               bIsMaterialEditorStatsMaterial : 1;                         // 0x0221:4 (0x0001)  
	EBlendableLocation                    BlendableLocation;                                          // 0x0222   (0x0001)  
	bool                                               BlendableOutputAlpha : 1;                                   // 0x0223:0 (0x0001)  
	bool                                               bEnableStencilTest : 1;                                     // 0x0223:1 (0x0001)  
	EMaterialStencilCompare               StencilCompare;                                             // 0x0224   (0x0001)  
	char                                               StencilRefValue;                                            // 0x0225   (0x0001)  
	ERefractionMode                       RefractionMode;                                             // 0x0226   (0x0001)  
	unsigned char                                      UnknownData05_6[0x1];                                       // 0x0227   (0x0001)  MISSED
	int32_t                                            BlendablePriority;                                          // 0x0228   (0x0004)  
	bool                                               bIsBlendable : 1;                                           // 0x022C:0 (0x0001)  
	unsigned char                                      UnknownData06_5[0x3];                                       // 0x022D   (0x0003)  MISSED
	uint32_t                                           UsageFlagWarnings;                                          // 0x0230   (0x0004)  
	float                                              RefractionDepthBias;                                        // 0x0234   (0x0004)  
	char                                              StateId[0x10];                                                    // 0x0238   (0x0010)  
	float                                              MaxDisplacement;                                            // 0x0248   (0x0004)  
	unsigned char                                      UnknownData07_6[0x34];                                      // 0x024C   (0x0034)  MISSED
	char                      CachedExpressionData[0x1D8];                                       // 0x0280   (0x01D8)  
};