#pragma once
#include "engine.h"

// --------------------------------------------------
	// # Enums
	// --------------------------------------------------
	/**
	 * Enum Engine.ETextGender
	 */
enum class ETextGender : uint8_t
{
	Masculine = 0,
	Feminine = 1,
	Neuter = 2,
	MAX = 3
};

/**
 * Enum Engine.EFormatArgumentType
 */
enum class EFormatArgumentType : uint8_t
{
	Int = 0,
	UInt = 1,
	Float = 2,
	Double = 3,
	Text = 4,
	Gender = 5,
	MAX = 6
};

/**
 * Enum Engine.EEndPlayReason
 */
enum class EEndPlayReason : uint8_t
{
	Destroyed = 0,
	LevelTransition = 1,
	EndPlayInEditor = 2,
	RemovedFromWorld = 3,
	Quit = 4,
	MAX = 5
};

/**
 * Enum Engine.ETickingGroup
 */
enum class ETickingGroup : uint8_t
{
	TG_PrePhysics = 0,
	TG_StartPhysics = 1,
	TG_DuringPhysics = 2,
	TG_EndPhysics = 3,
	TG_PostPhysics = 4,
	TG_PostUpdateWork = 5,
	TG_LastDemotable = 6,
	TG_NewlySpawned = 7,
	TG_MAX = 8
};

/**
 * Enum Engine.EComponentCreationMethod
 */
enum class EComponentCreationMethod : uint8_t
{
	Native = 0,
	SimpleConstructionScript = 1,
	UserConstructionScript = 2,
	Instance = 3,
	MAX = 4
};

/**
 * Enum Engine.ETemperatureSeverityType
 */
enum class ETemperatureSeverityType : uint8_t
{
	Unknown = 0,
	Good = 1,
	Bad = 2,
	Serious = 3,
	Critical = 4,
	NumSeverities = 5,
	MAX = 6
};

/**
 * Enum Engine.EQuartzCommandQuantization
 */
enum class EQuartzCommandQuantization : uint8_t
{
	Bar = 0,
	Beat = 1,
	ThirtySecondNote = 2,
	SixteenthNote = 3,
	EighthNote = 4,
	QuarterNote = 5,
	HalfNote = 6,
	WholeNote = 7,
	DottedSixteenthNote = 8,
	DottedEighthNote = 9,
	DottedQuarterNote = 10,
	DottedHalfNote = 11,
	DottedWholeNote = 12,
	SixteenthNoteTriplet = 13,
	EighthNoteTriplet = 14,
	QuarterNoteTriplet = 15,
	HalfNoteTriplet = 16,
	Tick = 17,
	Count = 18,
	None = 19,
	MAX = 20
};

/**
 * Enum Engine.EQuartzCommandDelegateSubType
 */
enum class EQuartzCommandDelegateSubType : uint8_t
{
	CommandOnFailedToQueue = 0,
	CommandOnQueued = 1,
	CommandOnCanceled = 2,
	CommandOnAboutToStart = 3,
	CommandOnStarted = 4,
	Count = 5,
	MAX = 6
};

/**
 * Enum Engine.EAudioComponentPlayState
 */
enum class EAudioComponentPlayState : uint8_t
{
	Playing = 0,
	Stopped = 1,
	Paused = 2,
	FadingIn = 3,
	FadingOut = 4,
	Count = 5,
	MAX = 6
};

/**
 * Enum Engine.EPlaneConstraintAxisSetting
 */
enum class EPlaneConstraintAxisSetting : uint8_t
{
	Custom = 0,
	X = 1,
	Y = 2,
	Z = 3,
	UseGlobalPhysicsSetting = 4,
	MAX = 5
};

/**
 * Enum Engine.EInterpToBehaviourType
 */
enum class EInterpToBehaviourType : uint8_t
{
	OneShot = 0,
	OneShot_Reverse = 1,
	Loop_Reset = 2,
	PingPong = 3,
	MAX = 4
};

/**
 * Enum Engine.ETeleportType
 */
enum class ETeleportType : uint8_t
{
	None = 0,
	TeleportPhysics = 1,
	ResetPhysics = 2,
	MAX = 3
};

/**
 * Enum Engine.EPlatformInterfaceDataType
 */
enum class EPlatformInterfaceDataType : uint8_t
{
	PIDT_None = 0,
	PIDT_Int = 1,
	PIDT_Float = 2,
	PIDT_String = 3,
	PIDT_Object = 4,
	PIDT_Custom = 5,
	PIDT_MAX = 6
};

/**
 * Enum Engine.EMovementMode
 */
enum class EMovementMode : uint8_t
{
	MOVE_None = 0,
	MOVE_Walking = 1,
	MOVE_NavWalking = 2,
	MOVE_Falling = 3,
	MOVE_Swimming = 4,
	MOVE_Flying = 5,
	MOVE_Custom = 6,
	MOVE_MAX = 7
};

/**
 * Enum Engine.ENetworkFailure
 */
enum class ENetworkFailure : uint8_t
{
	NetDriverAlreadyExists = 0,
	NetDriverCreateFailure = 1,
	NetDriverListenFailure = 2,
	ConnectionLost = 3,
	ConnectionTimeout = 4,
	FailureReceived = 5,
	OutdatedClient = 6,
	OutdatedServer = 7,
	PendingConnectionFailure = 8,
	NetGuidMismatch = 9,
	NetChecksumMismatch = 10,
	MAX = 11
};

/**
 * Enum Engine.ETravelFailure
 */
enum class ETravelFailure : uint8_t
{
	NoLevel = 0,
	LoadMapFailure = 1,
	InvalidURL = 2,
	PackageMissing = 3,
	PackageVersion = 4,
	NoDownload = 5,
	TravelFailure = 6,
	CheatCommands = 7,
	PendingNetGameCreateFailure = 8,
	CloudSaveFailure = 9,
	ServerTravelFailure = 10,
	ClientTravelFailure = 11,
	MAX = 12
};

/**
 * Enum Engine.EScreenOrientation
 */
enum class EScreenOrientation : uint8_t
{
	Unknown = 0,
	Portrait = 1,
	PortraitUpsideDown = 2,
	LandscapeLeft = 3,
	LandscapeRight = 4,
	FaceUp = 5,
	FaceDown = 6,
	MAX = 7
};

/**
 * Enum Engine.EApplicationState
 */
enum class EApplicationState : uint8_t
{
	Unknown = 0,
	Inactive = 1,
	Background = 2,
	Active = 3,
	MAX = 4
};

/**
 * Enum Engine.EObjectTypeQuery
 */
enum class EObjectTypeQuery : uint8_t
{
	ObjectTypeQuery1 = 0,
	ObjectTypeQuery2 = 1,
	ObjectTypeQuery3 = 2,
	ObjectTypeQuery4 = 3,
	ObjectTypeQuery5 = 4,
	ObjectTypeQuery6 = 5,
	ObjectTypeQuery7 = 6,
	ObjectTypeQuery8 = 7,
	ObjectTypeQuery9 = 8,
	ObjectTypeQuery10 = 9,
	ObjectTypeQuery11 = 10,
	ObjectTypeQuery12 = 11,
	ObjectTypeQuery13 = 12,
	ObjectTypeQuery14 = 13,
	ObjectTypeQuery15 = 14,
	ObjectTypeQuery16 = 15,
	ObjectTypeQuery17 = 16,
	ObjectTypeQuery18 = 17,
	ObjectTypeQuery19 = 18,
	ObjectTypeQuery20 = 19,
	ObjectTypeQuery21 = 20,
	ObjectTypeQuery22 = 21,
	ObjectTypeQuery23 = 22,
	ObjectTypeQuery24 = 23,
	ObjectTypeQuery25 = 24,
	ObjectTypeQuery26 = 25,
	ObjectTypeQuery27 = 26,
	ObjectTypeQuery28 = 27,
	ObjectTypeQuery29 = 28,
	ObjectTypeQuery30 = 29,
	ObjectTypeQuery31 = 30,
	ObjectTypeQuery32 = 31,
	ObjectTypeQuery_MAX = 32,
	MAX = 33
};

/**
 * Enum Engine.EDrawDebugTrace
 */
enum class EDrawDebugTrace : uint8_t
{
	None = 0,
	ForOneFrame = 1,
	ForDuration = 2,
	Persistent = 3,
	MAX = 4
};

/**
 * Enum Engine.ETraceTypeQuery
 */
enum class ETraceTypeQuery : uint8_t
{
	TraceTypeQuery1 = 0,
	TraceTypeQuery2 = 1,
	TraceTypeQuery3 = 2,
	TraceTypeQuery4 = 3,
	TraceTypeQuery5 = 4,
	TraceTypeQuery6 = 5,
	TraceTypeQuery7 = 6,
	TraceTypeQuery8 = 7,
	TraceTypeQuery9 = 8,
	TraceTypeQuery10 = 9,
	TraceTypeQuery11 = 10,
	TraceTypeQuery12 = 11,
	TraceTypeQuery13 = 12,
	TraceTypeQuery14 = 13,
	TraceTypeQuery15 = 14,
	TraceTypeQuery16 = 15,
	TraceTypeQuery17 = 16,
	TraceTypeQuery18 = 17,
	TraceTypeQuery19 = 18,
	TraceTypeQuery20 = 19,
	TraceTypeQuery21 = 20,
	TraceTypeQuery22 = 21,
	TraceTypeQuery23 = 22,
	TraceTypeQuery24 = 23,
	TraceTypeQuery25 = 24,
	TraceTypeQuery26 = 25,
	TraceTypeQuery27 = 26,
	TraceTypeQuery28 = 27,
	TraceTypeQuery29 = 28,
	TraceTypeQuery30 = 29,
	TraceTypeQuery31 = 30,
	TraceTypeQuery32 = 31,
	TraceTypeQuery_MAX = 32,
	MAX = 33
};

/**
 * Enum Engine.EMoveComponentAction
 */
enum class EMoveComponentAction : uint8_t
{
	Move = 0,
	Stop = 1,
	Return = 2,
	MAX = 3
};

/**
 * Enum Engine.EQuitPreference
 */
enum class EQuitPreference : uint8_t
{
	Quit = 0,
	Background = 1,
	MAX = 2
};

/**
 * Enum Engine.EFastArraySerializerDeltaFlags
 */
enum class EFastArraySerializerDeltaFlags : uint8_t
{
	None = 0,
	HasBeenSerialized = 1,
	HasDeltaBeenRequested = 2,
	IsUsingDeltaSerialization = 3,
	MAX = 4
};

/**
 * Enum Engine.ENetRole
 */
enum class ENetRole : uint8_t
{
	ROLE_None = 0,
	ROLE_SimulatedProxy = 1,
	ROLE_AutonomousProxy = 2,
	ROLE_Authority = 3,
	ROLE_MAX = 4
};

/**
 * Enum Engine.EAttachLocation
 */
enum class EAttachLocation : uint8_t
{
	KeepRelativeOffset = 0,
	KeepWorldPosition = 1,
	SnapToTarget = 2,
	SnapToTargetIncludingScale = 3,
	MAX = 4
};

/**
 * Enum Engine.EAttachmentRule
 */
enum class EAttachmentRule : uint8_t
{
	KeepRelative = 0,
	KeepWorld = 1,
	SnapToTarget = 2,
	MAX = 3
};

/**
 * Enum Engine.EDetachmentRule
 */
enum class EDetachmentRule : uint8_t
{
	KeepRelative = 0,
	KeepWorld = 1,
	MAX = 2
};

/**
 * Enum Engine.ENetDormancy
 */
enum class ENetDormancy : uint8_t
{
	DORM_Never = 0,
	DORM_Awake = 1,
	DORM_DormantAll = 2,
	DORM_DormantPartial = 3,
	DORM_Initial = 4,
	DORM_MAX = 5
};

/**
 * Enum Engine.EAutoReceiveInput
 */
enum class EAutoReceiveInput : uint8_t
{
	Disabled = 0,
	Player0 = 1,
	Player1 = 2,
	Player2 = 3,
	Player3 = 4,
	Player4 = 5,
	Player5 = 6,
	Player6 = 7,
	Player7 = 8,
	MAX = 9
};

/**
 * Enum Engine.ESpawnActorCollisionHandlingMethod
 */
enum class ESpawnActorCollisionHandlingMethod : uint8_t
{
	Undefined = 0,
	AlwaysSpawn = 1,
	AdjustIfPossibleButAlwaysSpawn = 2,
	AdjustIfPossibleButDontSpawnIfColliding = 3,
	DontSpawnIfColliding = 4,
	MAX = 5
};

/**
 * Enum Engine.ERotatorQuantization
 */
enum class ERotatorQuantization : uint8_t
{
	ByteComponents = 0,
	ShortComponents = 1,
	MAX = 2
};

/**
 * Enum Engine.EVectorQuantization
 */
enum class EVectorQuantization : uint8_t
{
	RoundWholeNumber = 0,
	RoundOneDecimal = 1,
	RoundTwoDecimals = 2,
	MAX = 3
};

/**
 * Enum Engine.EActorUpdateOverlapsMethod
 */
enum class EActorUpdateOverlapsMethod : uint8_t
{
	UseConfigDefault = 0,
	AlwaysUpdate = 1,
	OnlyUpdateMovable = 2,
	NeverUpdate = 3,
	MAX = 4
};

/**
 * Enum Engine.EAutoPossessAI
 */
enum class EAutoPossessAI : uint8_t
{
	Disabled = 0,
	PlacedInWorld = 1,
	Spawned = 2,
	PlacedInWorldOrSpawned = 3,
	MAX = 4
};

/**
 * Enum Engine.EMouseLockMode
 */
enum class EMouseLockMode : uint8_t
{
	DoNotLock = 0,
	LockOnCapture = 1,
	LockAlways = 2,
	LockInFullscreen = 3,
	MAX = 4
};

/**
 * Enum Engine.EWindowTitleBarMode
 */
enum class EWindowTitleBarMode : uint8_t
{
	Overlay = 0,
	VerticalBox = 1,
	MAX = 2
};

/**
 * Enum Engine.EInputEvent
 */
enum class EInputEvent : uint8_t
{
	IE_Pressed = 0,
	IE_Released = 1,
	IE_Repeat = 2,
	IE_DoubleClick = 3,
	IE_Axis = 4,
	IE_MAX = 5
};

/**
 * Enum Engine.ERoundingMode
 */
enum class ERoundingMode : uint8_t
{
	HalfToEven = 0,
	HalfFromZero = 1,
	HalfToZero = 2,
	FromZero = 3,
	ToZero = 4,
	ToNegativeInfinity = 5,
	ToPositiveInfinity = 6,
	MAX = 7
};

/**
 * Enum Engine.ERelativeTransformSpace
 */
enum class ERelativeTransformSpace : uint8_t
{
	RTS_World = 0,
	RTS_Actor = 1,
	RTS_Component = 2,
	RTS_ParentBoneSpace = 3,
	RTS_MAX = 4
};

/**
 * Enum Engine.EComponentMobility
 */
enum class EComponentMobility : uint8_t
{
	Static = 0,
	Stationary = 1,
	Movable = 2,
	MAX = 3
};

/**
 * Enum Engine.EDetailMode
 */
enum class EDetailMode : uint8_t
{
	DM_Low = 0,
	DM_Medium = 1,
	DM_High = 2,
	DM_MAX = 3
};

/**
 * Enum Engine.EAlphaBlendOption
 */
enum class EAlphaBlendOption : uint8_t
{
	Linear = 0,
	Cubic = 1,
	HermiteCubic = 2,
	Sinusoidal = 3,
	QuadraticInOut = 4,
	CubicInOut = 5,
	QuarticInOut = 6,
	QuinticInOut = 7,
	CircularIn = 8,
	CircularOut = 9,
	CircularInOut = 10,
	ExpIn = 11,
	ExpOut = 12,
	ExpInOut = 13,
	Custom = 14,
	MAX = 15
};

/**
 * Enum Engine.EAnimSyncGroupScope
 */
enum class EAnimSyncGroupScope : uint8_t
{
	Local = 0,
	Component = 1,
	MAX = 2
};

/**
 * Enum Engine.EAnimGroupRole
 */
enum class EAnimGroupRole : uint8_t
{
	CanBeLeader = 0,
	AlwaysFollower = 1,
	AlwaysLeader = 2,
	TransitionLeader = 3,
	TransitionFollower = 4,
	MAX = 5
};

/**
 * Enum Engine.EPreviewAnimationBlueprintApplicationMethod
 */
enum class EPreviewAnimationBlueprintApplicationMethod : uint8_t
{
	LinkedLayers = 0,
	LinkedAnimGraph = 1,
	MAX = 2
};

/**
 * Enum Engine.AnimationKeyFormat
 */
enum class EAnimationKeyFormat : uint8_t
{
	AKF_ConstantKeyLerp = 0,
	AKF_VariableKeyLerp = 1,
	AKF_PerTrackCompression = 2,
	AKF_MAX = 3
};

/**
 * Enum Engine.ERawCurveTrackTypes
 */
enum class ERawCurveTrackTypes : uint8_t
{
	RCT_Float = 0,
	RCT_Vector = 1,
	RCT_Transform = 2,
	RCT_MAX = 3
};

/**
 * Enum Engine.EAnimAssetCurveFlags
 */
enum class EAnimAssetCurveFlags : uint8_t
{
	AACF_NONE = 0,
	AACF_DriveMorphTarget_DEPRECATED = 1,
	AACF_DriveAttribute_DEPRECATED = 2,
	AACF_Editable = 3,
	AACF_DriveMaterial_DEPRECATED = 4,
	AACF_Metadata = 5,
	AACF_DriveTrack = 6,
	AACF_Disabled = 7,
	AACF_MAX = 8
};

/**
 * Enum Engine.AnimationCompressionFormat
 */
enum class EAnimationCompressionFormat : uint8_t
{
	ACF_None = 0,
	ACF_Float96NoW = 1,
	ACF_Fixed48NoW = 2,
	ACF_IntervalFixed32NoW = 3,
	ACF_Fixed32NoW = 4,
	ACF_Float32NoW = 5,
	ACF_Identity = 6,
	ACF_MAX = 7
};

/**
 * Enum Engine.EAdditiveBasePoseType
 */
enum class EAdditiveBasePoseType : uint8_t
{
	ABPT_None = 0,
	ABPT_RefPose = 1,
	ABPT_AnimScaled = 2,
	ABPT_AnimFrame = 3,
	ABPT_MAX = 4
};

/**
 * Enum Engine.ERootMotionMode
 */
enum class ERootMotionMode : uint8_t
{
	NoRootMotionExtraction = 0,
	IgnoreRootMotion = 1,
	RootMotionFromEverything = 2,
	RootMotionFromMontagesOnly = 3,
	MAX = 4
};

/**
 * Enum Engine.ERootMotionRootLock
 */
enum class ERootMotionRootLock : uint8_t
{
	RefPose = 0,
	AnimFirstFrame = 1,
	Zero = 2,
	MAX = 3
};

/**
 * Enum Engine.EMontagePlayReturnType
 */
enum class EMontagePlayReturnType : uint8_t
{
	MontageLength = 0,
	Duration = 1,
	MAX = 2
};

/**
 * Enum Engine.EDrawDebugItemType
 */
enum class EDrawDebugItemType : uint8_t
{
	DirectionalArrow = 0,
	Sphere = 1,
	Line = 2,
	OnScreenMessage = 3,
	CoordinateSystem = 4,
	MAX = 5
};

/**
 * Enum Engine.EAnimLinkMethod
 */
enum class EAnimLinkMethod : uint8_t
{
	Absolute = 0,
	Relative = 1,
	Proportional = 2,
	MAX = 3
};

/**
 * Enum Engine.EMontageSubStepResult
 */
enum class EMontageSubStepResult : uint8_t
{
	Moved = 0,
	NotMoved = 1,
	InvalidSection = 2,
	InvalidMontage = 3,
	MAX = 4
};

/**
 * Enum Engine.EAnimNotifyEventType
 */
enum class EAnimNotifyEventType : uint8_t
{
	Begin = 0,
	End = 1,
	MAX = 2
};

/**
 * Enum Engine.EInertializationSpace
 */
enum class EInertializationSpace : uint8_t
{
	Default = 0,
	WorldSpace = 1,
	WorldRotation = 2,
	MAX = 3
};

/**
 * Enum Engine.EInertializationBoneState
 */
enum class EInertializationBoneState : uint8_t
{
	Invalid = 0,
	Valid = 1,
	Excluded = 2,
	MAX = 3
};

/**
 * Enum Engine.EInertializationState
 */
enum class EInertializationState : uint8_t
{
	Inactive = 0,
	Pending = 1,
	Active = 2,
	MAX = 3
};

/**
 * Enum Engine.EEvaluatorMode
 */
enum class EEvaluatorMode : uint8_t
{
	EM_Standard = 0,
	EM_Freeze = 1,
	EM_DelayedFreeze = 2,
	EM_MAX = 3
};

/**
 * Enum Engine.EEvaluatorDataSource
 */
enum class EEvaluatorDataSource : uint8_t
{
	EDS_SourcePose = 0,
	EDS_DestinationPose = 1,
	EDS_MAX = 2
};

/**
 * Enum Engine.EPostCopyOperation
 */
enum class EPostCopyOperation : uint8_t
{
	None = 0,
	LogicalNegateBool = 1,
	MAX = 2
};

/**
 * Enum Engine.EPinHidingMode
 */
enum class EPinHidingMode : uint8_t
{
	NeverAsPin = 0,
	PinHiddenByDefault = 1,
	PinShownByDefault = 2,
	AlwaysAsPin = 3,
	MAX = 4
};

/**
 * Enum Engine.AnimPhysCollisionType
 */
enum class EAnimPhysCollisionType : uint8_t
{
	AnimPhysCollisionTypeCoM = 0,
	AnimPhysCollisionTypeCustomSphere = 1,
	AnimPhysCollisionTypeInnerSphere = 2,
	AnimPhysCollisionTypeOuterSphere = 3,
	AnimPhysCollisionTypeAnimPhysCollisionType_MAX = 4
};

/**
 * Enum Engine.AnimPhysTwistAxis
 */
enum class EAnimPhysTwistAxis : uint8_t
{
	AnimPhysTwistAxisAxisX = 0,
	AnimPhysTwistAxisAxisY = 1,
	AnimPhysTwistAxisAxisZ = 2,
	AnimPhysTwistAxisAnimPhysTwistAxis_MAX = 3
};

/**
 * Enum Engine.ETypeAdvanceAnim
 */
enum class ETypeAdvanceAnim : uint8_t
{
	ETAA_Default = 0,
	ETAA_Finished = 1,
	ETAA_Looped = 2,
	ETAA_MAX = 3
};

/**
 * Enum Engine.ETransitionLogicType
 */
enum class ETransitionLogicType : uint8_t
{
	TLT_StandardBlend = 0,
	TLT_Inertialization = 1,
	TLT_Custom = 2,
	TLT_MAX = 3
};

/**
 * Enum Engine.ETransitionBlendMode
 */
enum class ETransitionBlendMode : uint8_t
{
	TBM_Linear = 0,
	TBM_Cubic = 1,
	TBM_MAX = 2
};

/**
 * Enum Engine.EComponentType
 */
enum class EComponentType : uint8_t
{
	None = 0,
	TranslationX = 1,
	TranslationY = 2,
	TranslationZ = 3,
	RotationX = 4,
	RotationY = 5,
	RotationZ = 6,
	Scale = 7,
	ScaleX = 8,
	ScaleY = 9,
	ScaleZ = 10,
	MAX = 11
};

/**
 * Enum Engine.EAxisOption
 */
enum class EAxisOption : uint8_t
{
	X = 0,
	Y = 1,
	Z = 2,
	X_Neg = 3,
	Y_Neg = 4,
	Z_Neg = 5,
	Custom = 6,
	MAX = 7
};

/**
 * Enum Engine.EAnimInterpolationType
 */
enum class EAnimInterpolationType : uint8_t
{
	Linear = 0,
	Step = 1,
	MAX = 2
};

/**
 * Enum Engine.ECurveBlendOption
 */
enum class ECurveBlendOption : uint8_t
{
	Override = 0,
	DoNotOverride = 1,
	NormalizeByWeight = 2,
	BlendByWeight = 3,
	UseBasePose = 4,
	UseMaxValue = 5,
	UseMinValue = 6,
	MAX = 7
};

/**
 * Enum Engine.EAdditiveAnimationType
 */
enum class EAdditiveAnimationType : uint8_t
{
	AAT_None = 0,
	AAT_LocalSpaceBase = 1,
	AAT_RotationOffsetMeshSpace = 2,
	AAT_MAX = 3
};

/**
 * Enum Engine.ENotifyFilterType
 */
enum class ENotifyFilterType : uint8_t
{
	NoFiltering = 0,
	LOD = 1,
	MAX = 2
};

/**
 * Enum Engine.EMontageNotifyTickType
 */
enum class EMontageNotifyTickType : uint8_t
{
	Queued = 0,
	BranchingPoint = 1,
	MAX = 2
};

/**
 * Enum Engine.EBoneRotationSource
 */
enum class EBoneRotationSource : uint8_t
{
	BRS_KeepComponentSpaceRotation = 0,
	BRS_KeepLocalSpaceRotation = 1,
	BRS_CopyFromTarget = 2,
	BRS_MAX = 3
};

/**
 * Enum Engine.EBoneControlSpace
 */
enum class EBoneControlSpace : uint8_t
{
	BCS_WorldSpace = 0,
	BCS_ComponentSpace = 1,
	BCS_ParentBoneSpace = 2,
	BCS_BoneSpace = 3,
	BCS_MAX = 4
};

/**
 * Enum Engine.EBoneAxis
 */
enum class EBoneAxis : uint8_t
{
	BA_X = 0,
	BA_Y = 1,
	BA_Z = 2,
	BA_MAX = 3
};

/**
 * Enum Engine.EPrimaryAssetCookRule
 */
enum class EPrimaryAssetCookRule : uint8_t
{
	Unknown = 0,
	NeverCook = 1,
	DevelopmentCook = 2,
	DevelopmentAlwaysCook = 3,
	AlwaysCook = 4,
	MAX = 5
};

/**
 * Enum Engine.ENaturalSoundFalloffMode
 */
enum class ENaturalSoundFalloffMode : uint8_t
{
	Continues = 0,
	Silent = 1,
	Hold = 2,
	MAX = 3
};

/**
 * Enum Engine.EAttenuationShape
 */
enum class EAttenuationShape : uint8_t
{
	Sphere = 0,
	Capsule = 1,
	Box = 2,
	Cone = 3,
	MAX = 4
};

/**
 * Enum Engine.EAttenuationDistanceModel
 */
enum class EAttenuationDistanceModel : uint8_t
{
	Linear = 0,
	Logarithmic = 1,
	Inverse = 2,
	LogReverse = 3,
	NaturalSound = 4,
	Custom = 5,
	MAX = 6
};

/**
 * Enum Engine.EAudioBusChannels
 */
enum class EAudioBusChannels : uint8_t
{
	Mono = 0,
	Stereo = 1,
	MAX = 2
};

/**
 * Enum Engine.EAudioFaderCurve
 */
enum class EAudioFaderCurve : uint8_t
{
	Linear = 0,
	Logarithmic = 1,
	SCurve = 2,
	Sin = 3,
	Count = 4,
	MAX = 5
};

/**
 * Enum Engine.EAudioOutputTarget
 */
enum class EAudioOutputTarget : uint8_t
{
	Speaker = 0,
	Controller = 1,
	ControllerFallbackToSpeaker = 2,
	MAX = 3
};

/**
 * Enum Engine.EMonoChannelUpmixMethod
 */
enum class EMonoChannelUpmixMethod : uint8_t
{
	Linear = 0,
	EqualPower = 1,
	FullVolume = 2,
	MAX = 3
};

/**
 * Enum Engine.EPanningMethod
 */
enum class EPanningMethod : uint8_t
{
	Linear = 0,
	EqualPower = 1,
	MAX = 2
};

/**
 * Enum Engine.EVoiceSampleRate
 */
enum class EVoiceSampleRate : uint8_t
{
	Low16000Hz = 0,
	Normal24000Hz = 1,
	MAX = 2
};

/**
 * Enum Engine.EAudioVolumeLocationState
 */
enum class EAudioVolumeLocationState : uint8_t
{
	InsideTheVolume = 0,
	OutsideTheVolume = 1,
	MAX = 2
};

/**
 * Enum Engine.EBlendableLocation
 */
enum class EBlendableLocation : uint8_t
{
	BL_AfterTonemapping = 0,
	BL_BeforeTonemapping = 1,
	BL_BeforeTranslucency = 2,
	BL_ReplacingTonemapper = 3,
	BL_SSRInput = 4,
	BL_MAX = 5
};

/**
 * Enum Engine.ENotifyTriggerMode
 */
enum class ENotifyTriggerMode : uint8_t
{
	AllAnimations = 0,
	HighestWeightedAnimation = 1,
	None = 2,
	MAX = 3
};

/**
 * Enum Engine.EBlendSpaceAxis
 */
enum class EBlendSpaceAxis : uint8_t
{
	BSA_None = 0,
	BSA_X = 1,
	BSA_Y = 2,
	BSA_Max = 3
};

/**
 * Enum Engine.EBlueprintNativizationFlag
 */
enum class EBlueprintNativizationFlag : uint8_t
{
	Disabled = 0,
	Dependency = 1,
	ExplicitlyEnabled = 2,
	MAX = 3
};

/**
 * Enum Engine.EBlueprintCompileMode
 */
enum class EBlueprintCompileMode : uint8_t
{
	Default = 0,
	Development = 1,
	FinalRelease = 2,
	MAX = 3
};

/**
 * Enum Engine.EBlueprintType
 */
enum class EBlueprintType : uint8_t
{
	BPTYPE_Normal = 0,
	BPTYPE_Const = 1,
	BPTYPE_MacroLibrary = 2,
	BPTYPE_Interface = 3,
	BPTYPE_LevelScript = 4,
	BPTYPE_FunctionLibrary = 5,
	BPTYPE_MAX = 6
};

/**
 * Enum Engine.EBlueprintStatus
 */
enum class EBlueprintStatus : uint8_t
{
	BS_Unknown = 0,
	BS_Dirty = 1,
	BS_Error = 2,
	BS_UpToDate = 3,
	BS_BeingCreated = 4,
	BS_UpToDateWithWarnings = 5,
	BS_MAX = 6
};

/**
 * Enum Engine.EDOFMode
 */
enum class EDOFMode : uint8_t
{
	Default = 0,
	SixDOF = 1,
	YZPlane = 2,
	XZPlane = 3,
	XYPlane = 4,
	CustomPlane = 5,
	None = 6,
	MAX = 7
};

/**
 * Enum Engine.EBrushType
 */
enum class EBrushType : uint8_t
{
	Brush_Default = 0,
	Brush_Add = 1,
	Brush_Subtract = 2,
	Brush_MAX = 3
};

/**
 * Enum Engine.ECsgOper
 */
enum class ECsgOper : uint8_t
{
	CSG_Active = 0,
	CSG_Add = 1,
	CSG_Subtract = 2,
	CSG_Intersect = 3,
	CSG_Deintersect = 4,
	CSG_None = 5,
	CSG_MAX = 6
};

/**
 * Enum Engine.ECameraShakeDurationType
 */
enum class ECameraShakeDurationType : uint8_t
{
	Fixed = 0,
	Infinite = 1,
	Custom = 2,
	MAX = 3
};

/**
 * Enum Engine.ECameraShakeUpdateResultFlags
 */
enum class ECameraShakeUpdateResultFlags : uint8_t
{
	ApplyAsAbsolute = 0,
	SkipAutoScale = 1,
	SkipAutoPlaySpace = 2,
	Default = 3,
	MAX = 4
};

/**
 * Enum Engine.ECameraShakeAttenuation
 */
enum class ECameraShakeAttenuation : uint8_t
{
	Linear = 0,
	Quadratic = 1,
	MAX = 2
};

/**
 * Enum Engine.ECameraAlphaBlendMode
 */
enum class ECameraAlphaBlendMode : uint8_t
{
	CABM_Linear = 0,
	CABM_Cubic = 1,
	CABM_MAX = 2
};

/**
 * Enum Engine.ECameraShakePlaySpace
 */
enum class ECameraShakePlaySpace : uint8_t
{
	CameraLocal = 0,
	World = 1,
	UserDefined = 2,
	MAX = 3
};

/**
 * Enum Engine.ECameraProjectionMode
 */
enum class ECameraProjectionMode : uint8_t
{
	Perspective = 0,
	Orthographic = 1,
	MAX = 2
};

/**
 * Enum Engine.ECloudStorageDelegate
 */
enum class ECloudStorageDelegate : uint8_t
{
	CSD_KeyValueReadComplete = 0,
	CSD_KeyValueWriteComplete = 1,
	CSD_ValueChanged = 2,
	CSD_DocumentQueryComplete = 3,
	CSD_DocumentReadComplete = 4,
	CSD_DocumentWriteComplete = 5,
	CSD_DocumentConflictDetected = 6,
	CSD_MAX = 7
};

/**
 * Enum Engine.EAngularDriveMode
 */
enum class EAngularDriveMode : uint8_t
{
	SLERP = 0,
	TwistAndSwing = 1,
	MAX = 2
};

/**
 * Enum Engine.ECurveTableMode
 */
enum class ECurveTableMode : uint8_t
{
	Empty = 0,
	SimpleCurves = 1,
	RichCurves = 2,
	MAX = 3
};

/**
 * Enum Engine.ECustomAttributeBlendType
 */
enum class ECustomAttributeBlendType : uint8_t
{
	Override = 0,
	Blend = 1,
	MAX = 2
};

/**
 * Enum Engine.FDataDrivenCVarType
 */
enum class EFDataDrivenCVarType : uint8_t
{
	FDataDrivenCVarTypeCVarFloat = 0,
	FDataDrivenCVarTypeCVarInt = 1,
	FDataDrivenCVarTypeCVarBool = 2,
	FDataDrivenCVarTypeFDataDrivenCVarType_MAX = 3
};

/**
 * Enum Engine.EEvaluateCurveTableResult
 */
enum class EEvaluateCurveTableResult : uint8_t
{
	RowFound = 0,
	RowNotFound = 1,
	MAX = 2
};

/**
 * Enum Engine.EGrammaticalNumber
 */
enum class EGrammaticalNumber : uint8_t
{
	Singular = 0,
	Plural = 1,
	MAX = 2
};

/**
 * Enum Engine.EGrammaticalGender
 */
enum class EGrammaticalGender : uint8_t
{
	Neuter = 0,
	Masculine = 1,
	Feminine = 2,
	Mixed = 3,
	MAX = 4
};

/**
 * Enum Engine.DistributionParamMode
 */
enum class EDistributionParamMode : uint8_t
{
	DPM_Normal = 0,
	DPM_Abs = 1,
	DPM_Direct = 2,
	DPM_MAX = 3
};

/**
 * Enum Engine.EDistributionVectorMirrorFlags
 */
enum class EDistributionVectorMirrorFlags : uint8_t
{
	EDVMF_Same = 0,
	EDVMF_Different = 1,
	EDVMF_Mirror = 2,
	EDVMF_MAX = 3
};

/**
 * Enum Engine.EDistributionVectorLockFlags
 */
enum class EDistributionVectorLockFlags : uint8_t
{
	EDVLF_None = 0,
	EDVLF_XY = 1,
	EDVLF_XZ = 2,
	EDVLF_YZ = 3,
	EDVLF_XYZ = 4,
	EDVLF_MAX = 5
};

/**
 * Enum Engine.ENodeEnabledState
 */
enum class ENodeEnabledState : uint8_t
{
	Enabled = 0,
	Disabled = 1,
	DevelopmentOnly = 2,
	MAX = 3
};

/**
 * Enum Engine.ENodeAdvancedPins
 */
enum class ENodeAdvancedPins : uint8_t
{
	NoPins = 0,
	Shown = 1,
	Hidden = 2,
	MAX = 3
};

/**
 * Enum Engine.ENodeTitleType
 */
enum class ENodeTitleType : uint8_t
{
	FullTitle = 0,
	ListView = 1,
	EditableTitle = 2,
	MenuTitle = 3,
	MAX_TitleTypes = 4,
	MAX = 5
};

/**
 * Enum Engine.EPinContainerType
 */
enum class EPinContainerType : uint8_t
{
	None = 0,
	Array = 1,
	Set = 2,
	Map = 3,
	MAX = 4
};

/**
 * Enum Engine.EEdGraphPinDirection
 */
enum class EEdGraphPinDirection : uint8_t
{
	EGPD_Input = 0,
	EGPD_Output = 1,
	EGPD_MAX = 2
};

/**
 * Enum Engine.EBlueprintPinStyleType
 */
enum class EBlueprintPinStyleType : uint8_t
{
	BPST_Original = 0,
	BPST_VariantA = 1,
	BPST_MAX = 2
};

/**
 * Enum Engine.ECanCreateConnectionResponse
 */
enum class ECanCreateConnectionResponse : uint8_t
{
	CONNECT_RESPONSE_MAKE = 0,
	CONNECT_RESPONSE_DISALLOW = 1,
	CONNECT_RESPONSE_BREAK_OTHERS_A = 2,
	CONNECT_RESPONSE_BREAK_OTHERS_B = 3,
	CONNECT_RESPONSE_BREAK_OTHERS_AB = 4,
	CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE = 5,
	CONNECT_RESPONSE_MAX = 6
};

/**
 * Enum Engine.EGraphType
 */
enum class EGraphType : uint8_t
{
	GT_Function = 0,
	GT_Ubergraph = 1,
	GT_Macro = 2,
	GT_Animation = 3,
	GT_StateMachine = 4,
	GT_MAX = 5
};

/**
 * Enum Engine.ETransitionType
 */
enum class ETransitionType : uint8_t
{
	None = 0,
	Paused = 1,
	Loading = 2,
	Saving = 3,
	Connecting = 4,
	Precaching = 5,
	WaitingToConnect = 6,
	MAX = 7
};

/**
 * Enum Engine.EFullyLoadPackageType
 */
enum class EFullyLoadPackageType : uint8_t
{
	FULLYLOAD_Map = 0,
	FULLYLOAD_Game_PreLoadClass = 1,
	FULLYLOAD_Game_PostLoadClass = 2,
	FULLYLOAD_Always = 3,
	FULLYLOAD_Mutator = 4,
	FULLYLOAD_MAX = 5
};

/**
 * Enum Engine.EViewModeIndex
 */
enum class EViewModeIndex : uint8_t
{
	VMI_BrushWireframe = 0,
	VMI_Wireframe = 1,
	VMI_Unlit = 2,
	VMI_Lit = 3,
	VMI_Lit_DetailLighting = 4,
	VMI_LightingOnly = 5,
	VMI_LightComplexity = 6,
	VMI_ShaderComplexity = 7,
	VMI_LightmapDensity = 8,
	VMI_LitLightmapDensity = 9,
	VMI_ReflectionOverride = 10,
	VMI_VisualizeBuffer = 11,
	VMI_StationaryLightOverlap = 12,
	VMI_CollisionPawn = 13,
	VMI_CollisionVisibility = 14,
	VMI_LODColoration = 15,
	VMI_QuadOverdraw = 16,
	VMI_PrimitiveDistanceAccuracy = 17,
	VMI_MeshUVDensityAccuracy = 18,
	VMI_ShaderComplexityWithQuadOverdraw = 19,
	VMI_HLODColoration = 20,
	VMI_GroupLODColoration = 21,
	VMI_MaterialTextureScaleAccuracy = 22,
	VMI_RequiredTextureResolution = 23,
	VMI_PathTracing = 24,
	VMI_RayTracingDebug = 25,
	VMI_Max = 26,
	VMI_Unknown = 27
};

/**
 * Enum Engine.EDemoPlayFailure
 */
enum class EDemoPlayFailure : uint8_t
{
	Generic = 0,
	DemoNotFound = 1,
	Corrupt = 2,
	InvalidVersion = 3,
	InitBase = 4,
	GameSpecificHeader = 5,
	ReplayStreamerInternal = 6,
	LoadMap = 7,
	Serialization = 8,
	MAX = 9
};

/**
 * Enum Engine.ETravelType
 */
enum class ETravelType : uint8_t
{
	TRAVEL_Absolute = 0,
	TRAVEL_Partial = 1,
	TRAVEL_Relative = 2,
	TRAVEL_MAX = 3
};

/**
 * Enum Engine.ENetworkLagState
 */
enum class ENetworkLagState : uint8_t
{
	NotLagging = 0,
	Lagging = 1,
	MAX = 2
};

/**
 * Enum Engine.EMouseCaptureMode
 */
enum class EMouseCaptureMode : uint8_t
{
	NoCapture = 0,
	CapturePermanently = 1,
	CapturePermanently_IncludingInitialMouseDown = 2,
	CaptureDuringMouseDown = 3,
	CaptureDuringRightMouseDown = 4,
	MAX = 5
};

/**
 * Enum Engine.ECustomTimeStepSynchronizationState
 */
enum class ECustomTimeStepSynchronizationState : uint8_t
{
	Closed = 0,
	Error = 1,
	Synchronized = 2,
	Synchronizing = 3,
	MAX = 4
};

/**
 * Enum Engine.EMeshBufferAccess
 */
enum class EMeshBufferAccess : uint8_t
{
	Default = 0,
	ForceCPUAndGPU = 1,
	MAX = 2
};

/**
 * Enum Engine.EComponentSocketType
 */
enum class EComponentSocketType : uint8_t
{
	Invalid = 0,
	Bone = 1,
	Socket = 2,
	MAX = 3
};

/**
 * Enum Engine.EPhysicalMaterialMaskColor
 */
enum class EPhysicalMaterialMaskColor : uint8_t
{
	Red = 0,
	Green = 1,
	Blue = 2,
	Cyan = 3,
	Magenta = 4,
	Yellow = 5,
	White = 6,
	Black = 7,
	MAX = 8
};

/**
 * Enum Engine.EWalkableSlopeBehavior
 */
enum class EWalkableSlopeBehavior : uint8_t
{
	WalkableSlope_Default = 0,
	WalkableSlope_Increase = 1,
	WalkableSlope_Decrease = 2,
	WalkableSlope_Unwalkable = 3,
	WalkableSlope_Max = 4
};

/**
 * Enum Engine.EUpdateRateShiftBucket
 */
enum class EUpdateRateShiftBucket : uint8_t
{
	ShiftBucket0 = 0,
	ShiftBucket1 = 1,
	ShiftBucket2 = 2,
	ShiftBucket3 = 3,
	ShiftBucket4 = 4,
	ShiftBucket5 = 5,
	ShiftBucketMax = 6,
	MAX = 7
};

/**
 * Enum Engine.EShadowMapFlags
 */
enum class EShadowMapFlags : uint8_t
{
	SMF_None = 0,
	SMF_Streamed = 1,
	SMF_MAX = 2
};

/**
 * Enum Engine.ELightMapPaddingType
 */
enum class ELightMapPaddingType : uint8_t
{
	LMPT_NormalPadding = 0,
	LMPT_PrePadding = 1,
	LMPT_NoPadding = 2,
	LMPT_MAX = 3
};

/**
 * Enum Engine.ECollisionEnabled
 */
enum class ECollisionEnabled : uint8_t
{
	NoCollision = 0,
	QueryOnly = 1,
	PhysicsOnly = 2,
	QueryAndPhysics = 3,
	MAX = 4
};

/**
 * Enum Engine.ETimelineSigType
 */
enum class ETimelineSigType : uint8_t
{
	ETS_EventSignature = 0,
	ETS_FloatSignature = 1,
	ETS_VectorSignature = 2,
	ETS_LinearColorSignature = 3,
	ETS_InvalidSignature = 4,
	ETS_MAX = 5
};

/**
 * Enum Engine.EFilterInterpolationType
 */
enum class EFilterInterpolationType : uint8_t
{
	BSIT_Average = 0,
	BSIT_Linear = 1,
	BSIT_Cubic = 2,
	BSIT_MAX = 3
};

/**
 * Enum Engine.ECollisionResponse
 */
enum class ECollisionResponse : uint8_t
{
	ECR_Ignore = 0,
	ECR_Overlap = 1,
	ECR_Block = 2,
	ECR_MAX = 3
};

/**
 * Enum Engine.EOverlapFilterOption
 */
enum class EOverlapFilterOption : uint8_t
{
	OverlapFilter_All = 0,
	OverlapFilter_DynamicOnly = 1,
	OverlapFilter_StaticOnly = 2,
	OverlapFilter_MAX = 3
};

/**
 * Enum Engine.ECollisionChannel
 */
enum class ECollisionChannel : uint8_t
{
	ECC_WorldStatic = 0,
	ECC_WorldDynamic = 1,
	ECC_Pawn = 2,
	ECC_Visibility = 3,
	ECC_Camera = 4,
	ECC_PhysicsBody = 5,
	ECC_Vehicle = 6,
	ECC_Destructible = 7,
	ECC_EngineTraceChannel1 = 8,
	ECC_EngineTraceChannel2 = 9,
	ECC_EngineTraceChannel3 = 10,
	ECC_EngineTraceChannel4 = 11,
	ECC_EngineTraceChannel5 = 12,
	ECC_EngineTraceChannel6 = 13,
	ECC_GameTraceChannel1 = 14,
	ECC_GameTraceChannel2 = 15,
	ECC_GameTraceChannel3 = 16,
	ECC_GameTraceChannel4 = 17,
	ECC_GameTraceChannel5 = 18,
	ECC_GameTraceChannel6 = 19,
	ECC_GameTraceChannel7 = 20,
	ECC_GameTraceChannel8 = 21,
	ECC_GameTraceChannel9 = 22,
	ECC_GameTraceChannel10 = 23,
	ECC_GameTraceChannel11 = 24,
	ECC_GameTraceChannel12 = 25,
	ECC_GameTraceChannel13 = 26,
	ECC_GameTraceChannel14 = 27,
	ECC_GameTraceChannel15 = 28,
	ECC_GameTraceChannel16 = 29,
	ECC_GameTraceChannel17 = 30,
	ECC_GameTraceChannel18 = 31,
	ECC_OverlapAll_Deprecated = 32,
	ECC_MAX = 33
};

/**
 * Enum Engine.ENetworkSmoothingMode
 */
enum class ENetworkSmoothingMode : uint8_t
{
	Disabled = 0,
	Linear = 1,
	Exponential = 2,
	Replay = 3,
	MAX = 4
};

/**
 * Enum Engine.ELightingBuildQuality
 */
enum class ELightingBuildQuality : uint8_t
{
	Quality_Preview = 0,
	Quality_Medium = 1,
	Quality_High = 2,
	Quality_Production = 3,
	Quality_MAX = 4
};

/**
 * Enum Engine.EMaterialShadingRate
 */
enum class EMaterialShadingRate : uint8_t
{
	MSR_1x1 = 0,
	MSR_2x1 = 1,
	MSR_1x2 = 2,
	MSR_2x2 = 3,
	MSR_4x2 = 4,
	MSR_2x4 = 5,
	MSR_4x4 = 6,
	MSR_Count = 7,
	MSR_MAX = 8
};

/**
 * Enum Engine.EMaterialStencilCompare
 */
enum class EMaterialStencilCompare : uint8_t
{
	MSC_Less = 0,
	MSC_LessEqual = 1,
	MSC_Greater = 2,
	MSC_GreaterEqual = 3,
	MSC_Equal = 4,
	MSC_NotEqual = 5,
	MSC_Never = 6,
	MSC_Always = 7,
	MSC_Count = 8,
	MSC_MAX = 9
};

/**
 * Enum Engine.EMaterialSamplerType
 */
enum class EMaterialSamplerType : uint8_t
{
	SAMPLERTYPE_Color = 0,
	SAMPLERTYPE_Grayscale = 1,
	SAMPLERTYPE_Alpha = 2,
	SAMPLERTYPE_Normal = 3,
	SAMPLERTYPE_Masks = 4,
	SAMPLERTYPE_DistanceFieldFont = 5,
	SAMPLERTYPE_LinearColor = 6,
	SAMPLERTYPE_LinearGrayscale = 7,
	SAMPLERTYPE_Data = 8,
	SAMPLERTYPE_External = 9,
	SAMPLERTYPE_VirtualColor = 10,
	SAMPLERTYPE_VirtualGrayscale = 11,
	SAMPLERTYPE_VirtualAlpha = 12,
	SAMPLERTYPE_VirtualNormal = 13,
	SAMPLERTYPE_VirtualMasks = 14,
	SAMPLERTYPE_VirtualLinearColor = 15,
	SAMPLERTYPE_VirtualLinearGrayscale = 16,
	SAMPLERTYPE_MAX = 17
};

/**
 * Enum Engine.EMaterialTessellationMode
 */
enum class EMaterialTessellationMode : uint8_t
{
	MTM_NoTessellation = 0,
	MTM_FlatTessellation = 1,
	MTM_PNTriangles = 2,
	MTM_MAX = 3
};

/**
 * Enum Engine.EMaterialShadingModel
 */
enum class EMaterialShadingModel : uint8_t
{
	MSM_Unlit = 0,
	MSM_DefaultLit = 1,
	MSM_Subsurface = 2,
	MSM_PreintegratedSkin = 3,
	MSM_ClearCoat = 4,
	MSM_SubsurfaceProfile = 5,
	MSM_TwoSidedFoliage = 6,
	MSM_Hair = 7,
	MSM_Cloth = 8,
	MSM_Eye = 9,
	MSM_SingleLayerWater = 10,
	MSM_ThinTranslucent = 11,
	MSM_NUM = 12,
	MSM_FromMaterialExpression = 13,
	MSM_MAX = 14
};

/**
 * Enum Engine.EParticleCollisionMode
 */
enum class EParticleCollisionMode : uint8_t
{
	SceneDepth = 0,
	DistanceField = 1,
	MAX = 2
};

/**
 * Enum Engine.ETrailWidthMode
 */
enum class ETrailWidthMode : uint8_t
{
	FromCentre = 0,
	FromFirst = 1,
	FromSecond = 2,
	MAX = 3
};

/**
 * Enum Engine.EGBufferFormat
 */
enum class EGBufferFormat : uint8_t
{
	Force8BitsPerChannel = 0,
	Default = 1,
	HighPrecisionNormals = 2,
	Force16BitsPerChannel = 3,
	MAX = 4
};

/**
 * Enum Engine.ESceneCaptureCompositeMode
 */
enum class ESceneCaptureCompositeMode : uint8_t
{
	SCCM_Overwrite = 0,
	SCCM_Additive = 1,
	SCCM_Composite = 2,
	SCCM_MAX = 3
};

/**
 * Enum Engine.ESceneCaptureSource
 */
enum class ESceneCaptureSource : uint8_t
{
	SCS_SceneColorHDR = 0,
	SCS_SceneColorHDRNoAlpha = 1,
	SCS_FinalColorLDR = 2,
	SCS_SceneColorSceneDepth = 3,
	SCS_SceneDepth = 4,
	SCS_DeviceDepth = 5,
	SCS_Normal = 6,
	SCS_BaseColor = 7,
	SCS_FinalColorHDR = 8,
	SCS_FinalToneCurveHDR = 9,
	SCS_MAX = 10
};

/**
 * Enum Engine.ETranslucentSortPolicy
 */
enum class ETranslucentSortPolicy : uint8_t
{
	SortByDistance = 0,
	SortByProjectedZ = 1,
	SortAlongAxis = 2,
	MAX = 3
};

/**
 * Enum Engine.ERefractionMode
 */
enum class ERefractionMode : uint8_t
{
	RM_IndexOfRefraction = 0,
	RM_PixelNormalOffset = 1,
	RM_MAX = 2
};

/**
 * Enum Engine.ETranslucencyLightingMode
 */
enum class ETranslucencyLightingMode : uint8_t
{
	TLM_VolumetricNonDirectional = 0,
	TLM_VolumetricDirectional = 1,
	TLM_VolumetricPerVertexNonDirectional = 2,
	TLM_VolumetricPerVertexDirectional = 3,
	TLM_Surface = 4,
	TLM_SurfacePerPixelLighting = 5,
	TLM_MAX = 6
};

/**
 * Enum Engine.ESamplerSourceMode
 */
enum class ESamplerSourceMode : uint8_t
{
	SSM_FromTextureAsset = 0,
	SSM_Wrap_WorldGroupSettings = 1,
	SSM_Clamp_WorldGroupSettings = 2,
	SSM_MAX = 3
};

/**
 * Enum Engine.EBlendMode
 */
enum class EBlendMode : uint8_t
{
	BLEND_Opaque = 0,
	BLEND_Masked = 1,
	BLEND_Translucent = 2,
	BLEND_Additive = 3,
	BLEND_Modulate = 4,
	BLEND_AlphaComposite = 5,
	BLEND_AlphaHoldout = 6,
	BLEND_MAX = 7
};

/**
 * Enum Engine.EOcclusionCombineMode
 */
enum class EOcclusionCombineMode : uint8_t
{
	OCM_Minimum = 0,
	OCM_Multiply = 1,
	OCM_MAX = 2
};

/**
 * Enum Engine.ELightmapType
 */
enum class ELightmapType : uint8_t
{
	Default = 0,
	ForceSurface = 1,
	ForceVolumetric = 2,
	MAX = 3
};

/**
 * Enum Engine.EIndirectLightingCacheQuality
 */
enum class EIndirectLightingCacheQuality : uint8_t
{
	ILCQ_Off = 0,
	ILCQ_Point = 1,
	ILCQ_Volume = 2,
	ILCQ_MAX = 3
};

/**
 * Enum Engine.ESceneDepthPriorityGroup
 */
enum class ESceneDepthPriorityGroup : uint8_t
{
	SDPG_World = 0,
	SDPG_Foreground = 1,
	SDPG_MAX = 2
};

/**
 * Enum Engine.EAspectRatioAxisConstraint
 */
enum class EAspectRatioAxisConstraint : uint8_t
{
	AspectRatio_MaintainYFOV = 0,
	AspectRatio_MaintainXFOV = 1,
	AspectRatio_MajorAxisFOV = 2,
	AspectRatio_MAX = 3
};

/**
 * Enum Engine.EFontCacheType
 */
enum class EFontCacheType : uint8_t
{
	Offline = 0,
	Runtime = 1,
	MAX = 2
};

/**
 * Enum Engine.EFontImportCharacterSet
 */
enum class EFontImportCharacterSet : uint8_t
{
	FontICS_Default = 0,
	FontICS_Ansi = 1,
	FontICS_Symbol = 2,
	FontICS_MAX = 3
};

/**
 * Enum Engine.EStandbyType
 */
enum class EStandbyType : uint8_t
{
	STDBY_Rx = 0,
	STDBY_Tx = 1,
	STDBY_BadPing = 2,
	STDBY_MAX = 3
};

/**
 * Enum Engine.ESuggestProjVelocityTraceOption
 */
enum class ESuggestProjVelocityTraceOption : uint8_t
{
	DoNotTrace = 0,
	TraceFullPath = 1,
	OnlyTraceWhileAscending = 2,
	MAX = 3
};

/**
 * Enum Engine.EWindowMode
 */
enum class EWindowMode : uint8_t
{
	Fullscreen = 0,
	WindowedFullscreen = 1,
	Windowed = 2,
	MAX = 3
};

/**
 * Enum Engine.EHitProxyPriority
 */
enum class EHitProxyPriority : uint8_t
{
	HPP_World = 0,
	HPP_Wireframe = 1,
	HPP_Foreground = 2,
	HPP_UI = 3,
	HPP_MAX = 4
};

/**
 * Enum Engine.EImportanceWeight
 */
enum class EImportanceWeight : uint8_t
{
	Luminance = 0,
	Red = 1,
	Green = 2,
	Blue = 3,
	Alpha = 4,
	MAX = 5
};

/**
 * Enum Engine.EAdManagerDelegate
 */
enum class EAdManagerDelegate : uint8_t
{
	AMD_ClickedBanner = 0,
	AMD_UserClosedAd = 1,
	AMD_MAX = 2
};

/**
 * Enum Engine.EControllerAnalogStick
 */
enum class EControllerAnalogStick : uint8_t
{
	CAS_LeftStick = 0,
	CAS_RightStick = 1,
	CAS_MAX = 2
};

/**
 * Enum Engine.EAnimAlphaInputType
 */
enum class EAnimAlphaInputType : uint8_t
{
	Float = 0,
	Bool = 1,
	Curve = 2,
	MAX = 3
};

/**
 * Enum Engine.ETrackActiveCondition
 */
enum class ETrackActiveCondition : uint8_t
{
	ETAC_Always = 0,
	ETAC_GoreEnabled = 1,
	ETAC_GoreDisabled = 2,
	ETAC_MAX = 3
};

/**
 * Enum Engine.EInterpTrackMoveRotMode
 */
enum class EInterpTrackMoveRotMode : uint8_t
{
	IMR_Keyframed = 0,
	IMR_LookAtGroup = 1,
	IMR_Ignore = 2,
	IMR_MAX = 3
};

/**
 * Enum Engine.EInterpMoveAxis
 */
enum class EInterpMoveAxis : uint8_t
{
	AXIS_TranslationX = 0,
	AXIS_TranslationY = 1,
	AXIS_TranslationZ = 2,
	AXIS_RotationX = 3,
	AXIS_RotationY = 4,
	AXIS_RotationZ = 5,
	AXIS_MAX = 6
};

/**
 * Enum Engine.ETrackToggleAction
 */
enum class ETrackToggleAction : uint8_t
{
	ETTA_Off = 0,
	ETTA_On = 1,
	ETTA_Toggle = 2,
	ETTA_Trigger = 3,
	ETTA_MAX = 4
};

/**
 * Enum Engine.EVisibilityTrackCondition
 */
enum class EVisibilityTrackCondition : uint8_t
{
	EVTC_Always = 0,
	EVTC_GoreEnabled = 1,
	EVTC_GoreDisabled = 2,
	EVTC_MAX = 3
};

/**
 * Enum Engine.EVisibilityTrackAction
 */
enum class EVisibilityTrackAction : uint8_t
{
	EVTA_Hide = 0,
	EVTA_Show = 1,
	EVTA_Toggle = 2,
	EVTA_MAX = 3
};

/**
 * Enum Engine.ESlateGesture
 */
enum class ESlateGesture : uint8_t
{
	None = 0,
	Scroll = 1,
	Magnify = 2,
	Swipe = 3,
	Rotate = 4,
	LongPress = 5,
	MAX = 6
};

/**
 * Enum Engine.EMIDCreationFlags
 */
enum class EMIDCreationFlags : uint8_t
{
	None = 0,
	Transient = 1,
	MAX = 2
};

/**
 * Enum Engine.EMatrixColumns
 */
enum class EMatrixColumns : uint8_t
{
	First = 0,
	Second = 1,
	Third = 2,
	Fourth = 3,
	MAX = 4
};

/**
 * Enum Engine.ELerpInterpolationMode
 */
enum class ELerpInterpolationMode : uint8_t
{
	QuatInterp = 0,
	EulerInterp = 1,
	DualQuatInterp = 2,
	MAX = 3
};

/**
 * Enum Engine.EEasingFunc
 */
enum class EEasingFunc : uint8_t
{
	Linear = 0,
	Step = 1,
	SinusoidalIn = 2,
	SinusoidalOut = 3,
	SinusoidalInOut = 4,
	EaseIn = 5,
	EaseOut = 6,
	EaseInOut = 7,
	ExpoIn = 8,
	ExpoOut = 9,
	ExpoInOut = 10,
	CircularIn = 11,
	CircularOut = 12,
	CircularInOut = 13,
	MAX = 14
};

/**
 * Enum Engine.EStreamingVolumeUsage
 */
enum class EStreamingVolumeUsage : uint8_t
{
	SVB_Loading = 0,
	SVB_LoadingAndVisibility = 1,
	SVB_VisibilityBlockingOnLoad = 2,
	SVB_BlockingOnLoad = 3,
	SVB_LoadingNotVisible = 4,
	SVB_MAX = 5
};

/**
 * Enum Engine.ESyncOption
 */
enum class ESyncOption : uint8_t
{
	Drive = 0,
	Passive = 1,
	Disabled = 2,
	MAX = 3
};

/**
 * Enum Engine.EMaterialDecalResponse
 */
enum class EMaterialDecalResponse : uint8_t
{
	MDR_None = 0,
	MDR_ColorNormalRoughness = 1,
	MDR_Color = 2,
	MDR_ColorNormal = 3,
	MDR_ColorRoughness = 4,
	MDR_Normal = 5,
	MDR_NormalRoughness = 6,
	MDR_Roughness = 7,
	MDR_MAX = 8
};

/**
 * Enum Engine.EDecalBlendMode
 */
enum class EDecalBlendMode : uint8_t
{
	DBM_Translucent = 0,
	DBM_Stain = 1,
	DBM_Normal = 2,
	DBM_Emissive = 3,
	DBM_DBuffer_ColorNormalRoughness = 4,
	DBM_DBuffer_Color = 5,
	DBM_DBuffer_ColorNormal = 6,
	DBM_DBuffer_ColorRoughness = 7,
	DBM_DBuffer_Normal = 8,
	DBM_DBuffer_NormalRoughness = 9,
	DBM_DBuffer_Roughness = 10,
	DBM_DBuffer_Emissive = 11,
	DBM_DBuffer_AlphaComposite = 12,
	DBM_DBuffer_EmissiveAlphaComposite = 13,
	DBM_Volumetric_DistanceFunction = 14,
	DBM_AlphaComposite = 15,
	DBM_AmbientOcclusion = 16,
	DBM_MAX = 17
};

/**
 * Enum Engine.ETextureColorChannel
 */
enum class ETextureColorChannel : uint8_t
{
	TCC_Red = 0,
	TCC_Green = 1,
	TCC_Blue = 2,
	TCC_Alpha = 3,
	TCC_MAX = 4
};

/**
 * Enum Engine.EMaterialAttributeBlend
 */
enum class EMaterialAttributeBlend : uint8_t
{
	Blend = 0,
	UseA = 1,
	UseB = 2,
	MAX = 3
};

/**
 * Enum Engine.EChannelMaskParameterColor
 */
enum class EChannelMaskParameterColor : uint8_t
{
	Red = 0,
	Green = 1,
	Blue = 2,
	Alpha = 3,
	MAX = 4
};

/**
 * Enum Engine.EClampMode
 */
enum class EClampMode : uint8_t
{
	CMODE_Clamp = 0,
	CMODE_ClampMin = 1,
	CMODE_ClampMax = 2,
	CMODE_MAX = 3
};

/**
 * Enum Engine.ECustomMaterialOutputType
 */
enum class ECustomMaterialOutputType : uint8_t
{
	CMOT_Float1 = 0,
	CMOT_Float2 = 1,
	CMOT_Float3 = 2,
	CMOT_Float4 = 3,
	CMOT_MaterialAttributes = 4,
	CMOT_MAX = 5
};

/**
 * Enum Engine.EDepthOfFieldFunctionValue
 */
enum class EDepthOfFieldFunctionValue : uint8_t
{
	TDOF_NearAndFarMask = 0,
	TDOF_NearMask = 1,
	TDOF_FarMask = 2,
	TDOF_CircleOfConfusionRadius = 3,
	TDOF_MAX = 4
};

/**
 * Enum Engine.EFunctionInputType
 */
enum class EFunctionInputType : uint8_t
{
	FunctionInput_Scalar = 0,
	FunctionInput_Vector2 = 1,
	FunctionInput_Vector3 = 2,
	FunctionInput_Vector4 = 3,
	FunctionInput_Texture2D = 4,
	FunctionInput_TextureCube = 5,
	FunctionInput_Texture2DArray = 6,
	FunctionInput_VolumeTexture = 7,
	FunctionInput_StaticBool = 8,
	FunctionInput_MaterialAttributes = 9,
	FunctionInput_TextureExternal = 10,
	FunctionInput_MAX = 11
};

/**
 * Enum Engine.ENoiseFunction
 */
enum class ENoiseFunction : uint8_t
{
	NOISEFUNCTION_SimplexTex = 0,
	NOISEFUNCTION_GradientTex = 1,
	NOISEFUNCTION_GradientTex3D = 2,
	NOISEFUNCTION_GradientALU = 3,
	NOISEFUNCTION_ValueALU = 4,
	NOISEFUNCTION_VoronoiALU = 5,
	NOISEFUNCTION_MAX = 6
};

/**
 * Enum Engine.ERuntimeVirtualTextureTextureAddressMode
 */
enum class ERuntimeVirtualTextureTextureAddressMode : uint8_t
{
	RVTTA_Clamp = 0,
	RVTTA_Wrap = 1,
	RVTTA_MAX = 2
};

/**
 * Enum Engine.ERuntimeVirtualTextureMipValueMode
 */
enum class ERuntimeVirtualTextureMipValueMode : uint8_t
{
	RVTMVM_None = 0,
	RVTMVM_MipLevel = 1,
	RVTMVM_MipBias = 2,
	RVTMVM_MAX = 3
};

/**
 * Enum Engine.EMaterialSceneAttributeInputMode
 */
enum class EMaterialSceneAttributeInputMode : uint8_t
{
	Coordinates = 0,
	OffsetFraction = 1,
	MAX = 2
};

/**
 * Enum Engine.ESpeedTreeLODType
 */
enum class ESpeedTreeLODType : uint8_t
{
	STLOD_Pop = 0,
	STLOD_Smooth = 1,
	STLOD_MAX = 2
};

/**
 * Enum Engine.ESpeedTreeWindType
 */
enum class ESpeedTreeWindType : uint8_t
{
	STW_None = 0,
	STW_Fastest = 1,
	STW_Fast = 2,
	STW_Better = 3,
	STW_Best = 4,
	STW_Palm = 5,
	STW_BestPlus = 6,
	STW_MAX = 7
};

/**
 * Enum Engine.ESpeedTreeGeometryType
 */
enum class ESpeedTreeGeometryType : uint8_t
{
	STG_Branch = 0,
	STG_Frond = 1,
	STG_Leaf = 2,
	STG_FacingLeaf = 3,
	STG_Billboard = 4,
	STG_MAX = 5
};

/**
 * Enum Engine.EMaterialExposedTextureProperty
 */
enum class EMaterialExposedTextureProperty : uint8_t
{
	TMTM_TextureSize = 0,
	TMTM_TexelSize = 1,
	TMTM_MAX = 2
};

/**
 * Enum Engine.ETextureMipValueMode
 */
enum class ETextureMipValueMode : uint8_t
{
	TMVM_None = 0,
	TMVM_MipLevel = 1,
	TMVM_MipBias = 2,
	TMVM_Derivative = 3,
	TMVM_MAX = 4
};

/**
 * Enum Engine.EMaterialVectorCoordTransform
 */
enum class EMaterialVectorCoordTransform : uint8_t
{
	TRANSFORM_Tangent = 0,
	TRANSFORM_Local = 1,
	TRANSFORM_World = 2,
	TRANSFORM_View = 3,
	TRANSFORM_Camera = 4,
	TRANSFORM_ParticleWorld = 5,
	TRANSFORM_MAX = 6
};

/**
 * Enum Engine.EMaterialVectorCoordTransformSource
 */
enum class EMaterialVectorCoordTransformSource : uint8_t
{
	TRANSFORMSOURCE_Tangent = 0,
	TRANSFORMSOURCE_Local = 1,
	TRANSFORMSOURCE_World = 2,
	TRANSFORMSOURCE_View = 3,
	TRANSFORMSOURCE_Camera = 4,
	TRANSFORMSOURCE_ParticleWorld = 5,
	TRANSFORMSOURCE_MAX = 6
};

/**
 * Enum Engine.EMaterialPositionTransformSource
 */
enum class EMaterialPositionTransformSource : uint8_t
{
	TRANSFORMPOSSOURCE_Local = 0,
	TRANSFORMPOSSOURCE_World = 1,
	TRANSFORMPOSSOURCE_TranslatedWorld = 2,
	TRANSFORMPOSSOURCE_View = 3,
	TRANSFORMPOSSOURCE_Camera = 4,
	TRANSFORMPOSSOURCE_Particle = 5,
	TRANSFORMPOSSOURCE_MAX = 6
};

/**
 * Enum Engine.EVectorNoiseFunction
 */
enum class EVectorNoiseFunction : uint8_t
{
	VNF_CellnoiseALU = 0,
	VNF_VectorALU = 1,
	VNF_GradientALU = 2,
	VNF_CurlALU = 3,
	VNF_VoronoiALU = 4,
	VNF_MAX = 5
};

/**
 * Enum Engine.EMaterialExposedViewProperty
 */
enum class EMaterialExposedViewProperty : uint8_t
{
	MEVP_BufferSize = 0,
	MEVP_FieldOfView = 1,
	MEVP_TanHalfFieldOfView = 2,
	MEVP_ViewSize = 3,
	MEVP_WorldSpaceViewPosition = 4,
	MEVP_WorldSpaceCameraPosition = 5,
	MEVP_ViewportOffset = 6,
	MEVP_TemporalSampleCount = 7,
	MEVP_TemporalSampleIndex = 8,
	MEVP_TemporalSampleOffset = 9,
	MEVP_RuntimeVirtualTextureOutputLevel = 10,
	MEVP_RuntimeVirtualTextureOutputDerivative = 11,
	MEVP_PreExposure = 12,
	MEVP_RuntimeVirtualTextureMaxLevel = 13,
	MEVP_MAX = 14
};

/**
 * Enum Engine.EWorldPositionIncludedOffsets
 */
enum class EWorldPositionIncludedOffsets : uint8_t
{
	WPT_Default = 0,
	WPT_ExcludeAllShaderOffsets = 1,
	WPT_CameraRelative = 2,
	WPT_CameraRelativeNoOffsets = 3,
	WPT_MAX = 4
};

/**
 * Enum Engine.EMaterialFunctionUsage
 */
enum class EMaterialFunctionUsage : uint8_t
{
	Default = 0,
	MaterialLayer = 1,
	MaterialLayerBlend = 2,
	MAX = 3
};

/**
 * Enum Engine.EMaterialUsage
 */
enum class EMaterialUsage : uint8_t
{
	MATUSAGE_SkeletalMesh = 0,
	MATUSAGE_ParticleSprites = 1,
	MATUSAGE_BeamTrails = 2,
	MATUSAGE_MeshParticles = 3,
	MATUSAGE_StaticLighting = 4,
	MATUSAGE_MorphTargets = 5,
	MATUSAGE_SplineMesh = 6,
	MATUSAGE_InstancedStaticMeshes = 7,
	MATUSAGE_GeometryCollections = 8,
	MATUSAGE_Clothing = 9,
	MATUSAGE_NiagaraSprites = 10,
	MATUSAGE_NiagaraRibbons = 11,
	MATUSAGE_NiagaraMeshParticles = 12,
	MATUSAGE_GeometryCache = 13,
	MATUSAGE_Water = 14,
	MATUSAGE_HairStrands = 15,
	MATUSAGE_LidarPointCloud = 16,
	MATUSAGE_VirtualHeightfieldMesh = 17,
	MATUSAGE_MAX = 18
};

/**
 * Enum Engine.EMaterialLayerLinkState
 */
enum class EMaterialLayerLinkState : uint8_t
{
	Uninitialized = 0,
	LinkedToParent = 1,
	UnlinkedFromParent = 2,
	NotFromParent = 3,
	MAX = 4
};

/**
 * Enum Engine.EMaterialParameterAssociation
 */
enum class EMaterialParameterAssociation : uint8_t
{
	LayerParameter = 0,
	BlendParameter = 1,
	GlobalParameter = 2,
	MAX = 3
};

/**
 * Enum Engine.EMaterialMergeType
 */
enum class EMaterialMergeType : uint8_t
{
	MaterialMergeType_Default = 0,
	MaterialMergeType_Simplygon = 1,
	MaterialMergeType_MAX = 2
};

/**
 * Enum Engine.ETextureSizingType
 */
enum class ETextureSizingType : uint8_t
{
	TextureSizingType_UseSingleTextureSize = 0,
	TextureSizingType_UseAutomaticBiasedSizes = 1,
	TextureSizingType_UseManualOverrideTextureSize = 2,
	TextureSizingType_UseSimplygonAutomaticSizing = 3,
	TextureSizingType_MAX = 4
};

/**
 * Enum Engine.ESceneTextureId
 */
enum class ESceneTextureId : uint8_t
{
	PPI_SceneColor = 0,
	PPI_SceneDepth = 1,
	PPI_DiffuseColor = 2,
	PPI_SpecularColor = 3,
	PPI_SubsurfaceColor = 4,
	PPI_BaseColor = 5,
	PPI_Specular = 6,
	PPI_Metallic = 7,
	PPI_WorldNormal = 8,
	PPI_SeparateTranslucency = 9,
	PPI_Opacity = 10,
	PPI_Roughness = 11,
	PPI_MaterialAO = 12,
	PPI_CustomDepth = 13,
	PPI_PostProcessInput0 = 14,
	PPI_PostProcessInput1 = 15,
	PPI_PostProcessInput2 = 16,
	PPI_PostProcessInput3 = 17,
	PPI_PostProcessInput4 = 18,
	PPI_PostProcessInput5 = 19,
	PPI_PostProcessInput6 = 20,
	PPI_DecalMask = 21,
	PPI_ShadingModelColor = 22,
	PPI_ShadingModelID = 23,
	PPI_AmbientOcclusion = 24,
	PPI_CustomStencil = 25,
	PPI_StoredBaseColor = 26,
	PPI_StoredSpecular = 27,
	PPI_Velocity = 28,
	PPI_WorldTangent = 29,
	PPI_Anisotropy = 30,
	PPI_MAX = 31
};

/**
 * Enum Engine.EMaterialDomain
 */
enum class EMaterialDomain : uint8_t
{
	MD_Surface = 0,
	MD_DeferredDecal = 1,
	MD_LightFunction = 2,
	MD_Volume = 3,
	MD_PostProcess = 4,
	MD_UI = 5,
	MD_RuntimeVirtualTexture = 6,
	MD_MAX = 7
};

/**
 * Enum Engine.EMeshInstancingReplacementMethod
 */
enum class EMeshInstancingReplacementMethod : uint8_t
{
	RemoveOriginalActors = 0,
	KeepOriginalActorsAsEditorOnly = 1,
	MAX = 2
};

/**
 * Enum Engine.EUVOutput
 */
enum class EUVOutput : uint8_t
{
	DoNotOutputChannel = 0,
	OutputChannel = 1,
	MAX = 2
};

/**
 * Enum Engine.EMeshMergeType
 */
enum class EMeshMergeType : uint8_t
{
	MeshMergeType_Default = 0,
	MeshMergeType_MergeActor = 1,
	MeshMergeType_MAX = 2
};

/**
 * Enum Engine.EMeshLODSelectionType
 */
enum class EMeshLODSelectionType : uint8_t
{
	AllLODs = 0,
	SpecificLOD = 1,
	CalculateLOD = 2,
	LowestDetailLOD = 3,
	MAX = 4
};

/**
 * Enum Engine.EProxyNormalComputationMethod
 */
enum class EProxyNormalComputationMethod : uint8_t
{
	AngleWeighted = 0,
	AreaWeighted = 1,
	EqualWeighted = 2,
	MAX = 3
};

/**
 * Enum Engine.ELandscapeCullingPrecision
 */
enum class ELandscapeCullingPrecision : uint8_t
{
	High = 0,
	Medium = 1,
	Low = 2,
	MAX = 3
};

/**
 * Enum Engine.EStaticMeshReductionTerimationCriterion
 */
enum class EStaticMeshReductionTerimationCriterion : uint8_t
{
	Triangles = 0,
	Vertices = 1,
	Any = 2,
	MAX = 3
};

/**
 * Enum Engine.EMeshFeatureImportance
 */
enum class EMeshFeatureImportance : uint8_t
{
	Off = 0,
	Lowest = 1,
	Low = 2,
	Normal = 3,
	High = 4,
	Highest = 5,
	MAX = 6
};

/**
 * Enum Engine.EVertexPaintAxis
 */
enum class EVertexPaintAxis : uint8_t
{
	X = 0,
	Y = 1,
	Z = 2,
	MAX = 3
};

/**
 * Enum Engine.EMicroTransactionResult
 */
enum class EMicroTransactionResult : uint8_t
{
	MTR_Succeeded = 0,
	MTR_Failed = 1,
	MTR_Canceled = 2,
	MTR_RestoredFromServer = 3,
	MTR_MAX = 4
};

/**
 * Enum Engine.EMicroTransactionDelegate
 */
enum class EMicroTransactionDelegate : uint8_t
{
	MTD_PurchaseQueryComplete = 0,
	MTD_PurchaseComplete = 1,
	MTD_MAX = 2
};

/**
 * Enum Engine.FNavigationSystemRunMode
 */
enum class EFNavigationSystemRunMode : uint8_t
{
	FNavigationSystemRunModeInvalidMode = 0,
	FNavigationSystemRunModeGameMode = 1,
	FNavigationSystemRunModeEditorMode = 2,
	FNavigationSystemRunModeSimulationMode = 3,
	FNavigationSystemRunModePIEMode = 4,
	FNavigationSystemRunModeInferFromWorldMode = 5,
	FNavigationSystemRunModeFNavigationSystemRunMode_MAX = 6
};

/**
 * Enum Engine.ENavigationQueryResult
 */
enum class ENavigationQueryResult : uint8_t
{
	Invalid = 0,
	Error = 1,
	Fail = 2,
	Success = 3,
	MAX = 4
};

/**
 * Enum Engine.ENavPathEvent
 */
enum class ENavPathEvent : uint8_t
{
	Cleared = 0,
	NewPath = 1,
	UpdatedDueToGoalMoved = 2,
	UpdatedDueToNavigationChanged = 3,
	Invalidated = 4,
	RePathFailed = 5,
	MetaPathUpdate = 6,
	Custom = 7,
	MAX = 8
};

/**
 * Enum Engine.ENavDataGatheringModeConfig
 */
enum class ENavDataGatheringModeConfig : uint8_t
{
	Invalid = 0,
	Instant = 1,
	Lazy = 2,
	MAX = 3
};

/**
 * Enum Engine.ENavDataGatheringMode
 */
enum class ENavDataGatheringMode : uint8_t
{
	Default = 0,
	Instant = 1,
	Lazy = 2,
	MAX = 3
};

/**
 * Enum Engine.ENavigationOptionFlag
 */
enum class ENavigationOptionFlag : uint8_t
{
	Default = 0,
	Enable = 1,
	Disable = 2,
	MAX = 3
};

/**
 * Enum Engine.ENavLinkDirection
 */
enum class ENavLinkDirection : uint8_t
{
	BothWays = 0,
	LeftToRight = 1,
	RightToLeft = 2,
	MAX = 3
};

/**
 * Enum Engine.EEmitterRenderMode
 */
enum class EEmitterRenderMode : uint8_t
{
	ERM_Normal = 0,
	ERM_Point = 1,
	ERM_Cross = 2,
	ERM_LightsOnly = 3,
	ERM_None = 4,
	ERM_MAX = 5
};

/**
 * Enum Engine.EParticleSubUVInterpMethod
 */
enum class EParticleSubUVInterpMethod : uint8_t
{
	PSUVIM_None = 0,
	PSUVIM_Linear = 1,
	PSUVIM_Linear_Blend = 2,
	PSUVIM_Random = 3,
	PSUVIM_Random_Blend = 4,
	PSUVIM_MAX = 5
};

/**
 * Enum Engine.EParticleBurstMethod
 */
enum class EParticleBurstMethod : uint8_t
{
	EPBM_Instant = 0,
	EPBM_Interpolated = 1,
	EPBM_MAX = 2
};

/**
 * Enum Engine.EParticleSystemInsignificanceReaction
 */
enum class EParticleSystemInsignificanceReaction : uint8_t
{
	Auto = 0,
	Complete = 1,
	DisableTick = 2,
	DisableTickAndKill = 3,
	Num = 4,
	MAX = 5
};

/**
 * Enum Engine.EParticleSignificanceLevel
 */
enum class EParticleSignificanceLevel : uint8_t
{
	Low = 0,
	Medium = 1,
	High = 2,
	Critical = 3,
	Num = 4,
	MAX = 5
};

/**
 * Enum Engine.EParticleDetailMode
 */
enum class EParticleDetailMode : uint8_t
{
	PDM_Low = 0,
	PDM_Medium = 1,
	PDM_High = 2,
	PDM_MAX = 3
};

/**
 * Enum Engine.EParticleSourceSelectionMethod
 */
enum class EParticleSourceSelectionMethod : uint8_t
{
	EPSSM_Random = 0,
	EPSSM_Sequential = 1,
	EPSSM_MAX = 2
};

/**
 * Enum Engine.EModuleType
 */
enum class EModuleType : uint8_t
{
	EPMT_General = 0,
	EPMT_TypeData = 1,
	EPMT_Beam = 2,
	EPMT_Trail = 3,
	EPMT_Spawn = 4,
	EPMT_Required = 5,
	EPMT_Event = 6,
	EPMT_Light = 7,
	EPMT_SubUV = 8,
	EPMT_MAX = 9
};

/**
 * Enum Engine.EAttractorParticleSelectionMethod
 */
enum class EAttractorParticleSelectionMethod : uint8_t
{
	EAPSM_Random = 0,
	EAPSM_Sequential = 1,
	EAPSM_MAX = 2
};

/**
 * Enum Engine.Beam2SourceTargetTangentMethod
 */
enum class EBeam2SourceTargetTangentMethod : uint8_t
{
	PEB2STTM_Direct = 0,
	PEB2STTM_UserSet = 1,
	PEB2STTM_Distribution = 2,
	PEB2STTM_Emitter = 3,
	PEB2STTM_MAX = 4
};

/**
 * Enum Engine.Beam2SourceTargetMethod
 */
enum class EBeam2SourceTargetMethod : uint8_t
{
	PEB2STM_Default = 0,
	PEB2STM_UserSet = 1,
	PEB2STM_Emitter = 2,
	PEB2STM_Particle = 3,
	PEB2STM_Actor = 4,
	PEB2STM_MAX = 5
};

/**
 * Enum Engine.BeamModifierType
 */
enum class EBeamModifierType : uint8_t
{
	PEB2MT_Source = 0,
	PEB2MT_Target = 1,
	PEB2MT_MAX = 2
};

/**
 * Enum Engine.EParticleCameraOffsetUpdateMethod
 */
enum class EParticleCameraOffsetUpdateMethod : uint8_t
{
	EPCOUM_DirectSet = 0,
	EPCOUM_Additive = 1,
	EPCOUM_Scalar = 2,
	EPCOUM_MAX = 3
};

/**
 * Enum Engine.EParticleCollisionComplete
 */
enum class EParticleCollisionComplete : uint8_t
{
	EPCC_Kill = 0,
	EPCC_Freeze = 1,
	EPCC_HaltCollisions = 2,
	EPCC_FreezeTranslation = 3,
	EPCC_FreezeRotation = 4,
	EPCC_FreezeMovement = 5,
	EPCC_MAX = 6
};

/**
 * Enum Engine.EParticleCollisionResponse
 */
enum class EParticleCollisionResponse : uint8_t
{
	Bounce = 0,
	Stop = 1,
	Kill = 2,
	MAX = 3
};

/**
 * Enum Engine.ELocationBoneSocketSelectionMethod
 */
enum class ELocationBoneSocketSelectionMethod : uint8_t
{
	BONESOCKETSEL_Sequential = 0,
	BONESOCKETSEL_Random = 1,
	BONESOCKETSEL_MAX = 2
};

/**
 * Enum Engine.ELocationBoneSocketSource
 */
enum class ELocationBoneSocketSource : uint8_t
{
	BONESOCKETSOURCE_Bones = 0,
	BONESOCKETSOURCE_Sockets = 1,
	BONESOCKETSOURCE_MAX = 2
};

/**
 * Enum Engine.ELocationEmitterSelectionMethod
 */
enum class ELocationEmitterSelectionMethod : uint8_t
{
	ELESM_Random = 0,
	ELESM_Sequential = 1,
	ELESM_MAX = 2
};

/**
 * Enum Engine.CylinderHeightAxis
 */
enum class ECylinderHeightAxis : uint8_t
{
	PMLPC_HEIGHTAXIS_X = 0,
	PMLPC_HEIGHTAXIS_Y = 1,
	PMLPC_HEIGHTAXIS_Z = 2,
	PMLPC_HEIGHTAXIS_MAX = 3
};

/**
 * Enum Engine.ELocationSkelVertSurfaceSource
 */
enum class ELocationSkelVertSurfaceSource : uint8_t
{
	VERTSURFACESOURCE_Vert = 0,
	VERTSURFACESOURCE_Surface = 1,
	VERTSURFACESOURCE_MAX = 2
};

/**
 * Enum Engine.EOrbitChainMode
 */
enum class EOrbitChainMode : uint8_t
{
	EOChainMode_Add = 0,
	EOChainMode_Scale = 1,
	EOChainMode_Link = 2,
	EOChainMode_MAX = 3
};

/**
 * Enum Engine.EParticleAxisLock
 */
enum class EParticleAxisLock : uint8_t
{
	EPAL_NONE = 0,
	EPAL_X = 1,
	EPAL_Y = 2,
	EPAL_Z = 3,
	EPAL_NEGATIVE_X = 4,
	EPAL_NEGATIVE_Y = 5,
	EPAL_NEGATIVE_Z = 6,
	EPAL_ROTATE_X = 7,
	EPAL_ROTATE_Y = 8,
	EPAL_ROTATE_Z = 9,
	EPAL_MAX = 10
};

/**
 * Enum Engine.EEmitterDynamicParameterValue
 */
enum class EEmitterDynamicParameterValue : uint8_t
{
	EDPV_UserSet = 0,
	EDPV_AutoSet = 1,
	EDPV_VelocityX = 2,
	EDPV_VelocityY = 3,
	EDPV_VelocityZ = 4,
	EDPV_VelocityMag = 5,
	EDPV_MAX = 6
};

/**
 * Enum Engine.EEmitterNormalsMode
 */
enum class EEmitterNormalsMode : uint8_t
{
	ENM_CameraFacing = 0,
	ENM_Spherical = 1,
	ENM_Cylindrical = 2,
	ENM_MAX = 3
};

/**
 * Enum Engine.EParticleSortMode
 */
enum class EParticleSortMode : uint8_t
{
	PSORTMODE_None = 0,
	PSORTMODE_ViewProjDepth = 1,
	PSORTMODE_DistanceToView = 2,
	PSORTMODE_Age_OldestFirst = 3,
	PSORTMODE_Age_NewestFirst = 4,
	PSORTMODE_MAX = 5
};

/**
 * Enum Engine.EParticleUVFlipMode
 */
enum class EParticleUVFlipMode : uint8_t
{
	None = 0,
	FlipUV = 1,
	FlipUOnly = 2,
	FlipVOnly = 3,
	RandomFlipUV = 4,
	RandomFlipUOnly = 5,
	RandomFlipVOnly = 6,
	RandomFlipUVIndependent = 7,
	MAX = 8
};

/**
 * Enum Engine.ETrail2SourceMethod
 */
enum class ETrail2SourceMethod : uint8_t
{
	PET2SRCM_Default = 0,
	PET2SRCM_Particle = 1,
	PET2SRCM_Actor = 2,
	PET2SRCM_MAX = 3
};

/**
 * Enum Engine.EBeamTaperMethod
 */
enum class EBeamTaperMethod : uint8_t
{
	PEBTM_None = 0,
	PEBTM_Full = 1,
	PEBTM_Partial = 2,
	PEBTM_MAX = 3
};

/**
 * Enum Engine.EBeam2Method
 */
enum class EBeam2Method : uint8_t
{
	PEB2M_Distance = 0,
	PEB2M_Target = 1,
	PEB2M_Branch = 2,
	PEB2M_MAX = 3
};

/**
 * Enum Engine.EMeshCameraFacingOptions
 */
enum class EMeshCameraFacingOptions : uint8_t
{
	XAxisFacing_NoUp = 0,
	XAxisFacing_ZUp = 1,
	XAxisFacing_NegativeZUp = 2,
	XAxisFacing_YUp = 3,
	XAxisFacing_NegativeYUp = 4,
	LockedAxis_ZAxisFacing = 5,
	LockedAxis_NegativeZAxisFacing = 6,
	LockedAxis_YAxisFacing = 7,
	LockedAxis_NegativeYAxisFacing = 8,
	VelocityAligned_ZAxisFacing = 9,
	VelocityAligned_NegativeZAxisFacing = 10,
	VelocityAligned_YAxisFacing = 11,
	VelocityAligned_NegativeYAxisFacing = 12,
	MAX = 13
};

/**
 * Enum Engine.EMeshCameraFacingUpAxis
 */
enum class EMeshCameraFacingUpAxis : uint8_t
{
	CameraFacing_NoneUP = 0,
	CameraFacing_ZUp = 1,
	CameraFacing_NegativeZUp = 2,
	CameraFacing_YUp = 3,
	CameraFacing_NegativeYUp = 4,
	CameraFacing_MAX = 5
};

/**
 * Enum Engine.EMeshScreenAlignment
 */
enum class EMeshScreenAlignment : uint8_t
{
	PSMA_MeshFaceCameraWithRoll = 0,
	PSMA_MeshFaceCameraWithSpin = 1,
	PSMA_MeshFaceCameraWithLockedAxis = 2,
	PSMA_MAX = 3
};

/**
 * Enum Engine.ETrailsRenderAxisOption
 */
enum class ETrailsRenderAxisOption : uint8_t
{
	Trails_CameraUp = 0,
	Trails_SourceUp = 1,
	Trails_WorldUp = 2,
	Trails_MAX = 3
};

/**
 * Enum Engine.EParticleScreenAlignment
 */
enum class EParticleScreenAlignment : uint8_t
{
	PSA_FacingCameraPosition = 0,
	PSA_Square = 1,
	PSA_Rectangle = 2,
	PSA_Velocity = 3,
	PSA_AwayFromCenter = 4,
	PSA_TypeSpecific = 5,
	PSA_FacingCameraDistanceBlend = 6,
	PSA_MAX = 7
};

/**
 * Enum Engine.EParticleSystemOcclusionBoundsMethod
 */
enum class EParticleSystemOcclusionBoundsMethod : uint8_t
{
	EPSOBM_None = 0,
	EPSOBM_ParticleBounds = 1,
	EPSOBM_CustomBounds = 2,
	EPSOBM_MAX = 3
};

/**
 * Enum Engine.ParticleSystemLODMethod
 */
enum class EParticleSystemLODMethod : uint8_t
{
	PARTICLESYSTEMLODMETHOD_Automatic = 0,
	PARTICLESYSTEMLODMETHOD_DirectSet = 1,
	PARTICLESYSTEMLODMETHOD_ActivateAutomatic = 2,
	PARTICLESYSTEMLODMETHOD_MAX = 3
};

/**
 * Enum Engine.EParticleSystemUpdateMode
 */
enum class EParticleSystemUpdateMode : uint8_t
{
	EPSUM_RealTime = 0,
	EPSUM_FixedTime = 1,
	EPSUM_MAX = 2
};

/**
 * Enum Engine.EParticleEventType
 */
enum class EParticleEventType : uint8_t
{
	EPET_Any = 0,
	EPET_Spawn = 1,
	EPET_Death = 2,
	EPET_Collision = 3,
	EPET_Burst = 4,
	EPET_Blueprint = 5,
	EPET_MAX = 6
};

/**
 * Enum Engine.ParticleReplayState
 */
enum class EParticleReplayState : uint8_t
{
	PRS_Disabled = 0,
	PRS_Capturing = 1,
	PRS_Replaying = 2,
	PRS_MAX = 3
};

/**
 * Enum Engine.EParticleSysParamType
 */
enum class EParticleSysParamType : uint8_t
{
	PSPT_None = 0,
	PSPT_Scalar = 1,
	PSPT_ScalarRand = 2,
	PSPT_Vector = 3,
	PSPT_VectorRand = 4,
	PSPT_Color = 5,
	PSPT_Actor = 6,
	PSPT_Material = 7,
	PSPT_VectorUnitRand = 8,
	PSPT_MAX = 9
};

/**
 * Enum Engine.EPhysicsAssetSolverType
 */
enum class EPhysicsAssetSolverType : uint8_t
{
	RBAN = 0,
	World = 1,
	MAX = 2
};

/**
 * Enum Engine.ESettingsLockedAxis
 */
enum class ESettingsLockedAxis : uint8_t
{
	None = 0,
	X = 1,
	Y = 2,
	Z = 3,
	Invalid = 4,
	MAX = 5
};

/**
 * Enum Engine.ESettingsDOF
 */
enum class ESettingsDOF : uint8_t
{
	Full3D = 0,
	YZPlane = 1,
	XZPlane = 2,
	XYPlane = 3,
	MAX = 4
};

/**
 * Enum Engine.EViewTargetBlendFunction
 */
enum class EViewTargetBlendFunction : uint8_t
{
	VTBlend_Linear = 0,
	VTBlend_Cubic = 1,
	VTBlend_EaseIn = 2,
	VTBlend_EaseOut = 3,
	VTBlend_EaseInOut = 4,
	VTBlend_PreBlended = 5,
	VTBlend_MAX = 6
};

/**
 * Enum Engine.EDynamicForceFeedbackAction
 */
enum class EDynamicForceFeedbackAction : uint8_t
{
	Start = 0,
	Update = 1,
	Stop = 2,
	MAX = 3
};

/**
 * Enum Engine.ERendererStencilMask
 */
enum class ERendererStencilMask : uint8_t
{
	ERSM_Default = 0,
	ERSM = 1,
	ERSM01 = 2,
	ERSM02 = 3,
	ERSM03 = 4,
	ERSM04 = 5,
	ERSM05 = 6,
	ERSM06 = 7,
	ERSM07 = 8,
	ERSM08 = 9,
	ERSM_MAX = 10
};

/**
 * Enum Engine.EHasCustomNavigableGeometry
 */
enum class EHasCustomNavigableGeometry : uint8_t
{
	No = 0,
	Yes = 1,
	EvenIfNotCollidable = 2,
	DontExport = 3,
	MAX = 4
};

/**
 * Enum Engine.ECanBeCharacterBase
 */
enum class ECanBeCharacterBase : uint8_t
{
	ECB_No = 0,
	ECB_Yes = 1,
	ECB_Owner = 2,
	ECB_MAX = 3
};

/**
 * Enum Engine.EQuarztQuantizationReference
 */
enum class EQuarztQuantizationReference : uint8_t
{
	BarRelative = 0,
	TransportRelative = 1,
	CurrentTimeRelative = 2,
	Count = 3,
	MAX = 4
};

/**
 * Enum Engine.EQuartzDelegateType
 */
enum class EQuartzDelegateType : uint8_t
{
	MetronomeTick = 0,
	CommandEvent = 1,
	Count = 2,
	MAX = 3
};

/**
 * Enum Engine.EQuartzTimeSignatureQuantization
 */
enum class EQuartzTimeSignatureQuantization : uint8_t
{
	HalfNote = 0,
	QuarterNote = 1,
	EighthNote = 2,
	SixteenthNote = 3,
	ThirtySecondNote = 4,
	Count = 5,
	MAX = 6
};

/**
 * Enum Engine.ERichCurveExtrapolation
 */
enum class ERichCurveExtrapolation : uint8_t
{
	RCCE_Cycle = 0,
	RCCE_CycleWithOffset = 1,
	RCCE_Oscillate = 2,
	RCCE_Linear = 3,
	RCCE_Constant = 4,
	RCCE_None = 5,
	RCCE_MAX = 6
};

/**
 * Enum Engine.ERichCurveInterpMode
 */
enum class ERichCurveInterpMode : uint8_t
{
	RCIM_Linear = 0,
	RCIM_Constant = 1,
	RCIM_Cubic = 2,
	RCIM_None = 3,
	RCIM_MAX = 4
};

/**
 * Enum Engine.EMobileReflectionCompression
 */
enum class EMobileReflectionCompression : uint8_t
{
	Default = 0,
	On = 1,
	Off = 2,
	MAX = 3
};

/**
 * Enum Engine.EReflectionSourceType
 */
enum class EReflectionSourceType : uint8_t
{
	CapturedScene = 0,
	SpecifiedCubemap = 1,
	MAX = 2
};

/**
 * Enum Engine.EFixedFoveationLevels
 */
enum class EFixedFoveationLevels : uint8_t
{
	Disabled = 0,
	Low = 1,
	Medium = 2,
	High = 3,
	MAX = 4
};

/**
 * Enum Engine.EDefaultBackBufferPixelFormat
 */
enum class EDefaultBackBufferPixelFormat : uint8_t
{
	DBBPF_B8G8R8A8 = 0,
	DBBPF_A16B16G16R16_DEPRECATED = 1,
	DBBPF_FloatRGB_DEPRECATED = 2,
	DBBPF_FloatRGBA = 3,
	DBBPF_A2B10G10R10 = 4,
	DBBPF_MAX = 5
};

/**
 * Enum Engine.EAutoExposureMethodUI
 */
enum class EAutoExposureMethodUI : uint8_t
{
	AEM_Histogram = 0,
	AEM_Basic = 1,
	AEM_Manual = 2,
	AEM_MAX = 3
};

/**
 * Enum Engine.EAlphaChannelMode
 */
enum class EAlphaChannelMode : uint8_t
{
	Disabled = 0,
	LinearColorSpaceOnly = 1,
	AllowThroughTonemapper = 2,
	MAX = 3
};

/**
 * Enum Engine.EEarlyZPass
 */
enum class EEarlyZPass : uint8_t
{
	None = 0,
	OpaqueOnly = 1,
	OpaqueAndMasked = 2,
	Auto = 3,
	MAX = 4
};

/**
 * Enum Engine.ECustomDepthStencil
 */
enum class ECustomDepthStencil : uint8_t
{
	Disabled = 0,
	Enabled = 1,
	EnabledOnDemand = 2,
	EnabledWithStencil = 3,
	MAX = 4
};

/**
 * Enum Engine.EMobileMSAASampleCount
 */
enum class EMobileMSAASampleCount : uint8_t
{
	One = 0,
	Two = 1,
	Four = 2,
	Eight = 3,
	MAX = 4
};

/**
 * Enum Engine.ECompositingSampleCount
 */
enum class ECompositingSampleCount : uint8_t
{
	One = 0,
	Two = 1,
	Four = 2,
	Eight = 3,
	MAX = 4
};

/**
 * Enum Engine.EClearSceneOptions
 */
enum class EClearSceneOptions : uint8_t
{
	NoClear = 0,
	HardwareClear = 1,
	QuadAtMaxZ = 2,
	MAX = 3
};

/**
 * Enum Engine.EReporterLineStyle
 */
enum class EReporterLineStyle : uint8_t
{
	Line = 0,
	Dash = 1,
	MAX = 2
};

/**
 * Enum Engine.ELegendPosition
 */
enum class ELegendPosition : uint8_t
{
	Outside = 0,
	Inside = 1,
	MAX = 2
};

/**
 * Enum Engine.EGraphDataStyle
 */
enum class EGraphDataStyle : uint8_t
{
	Lines = 0,
	Filled = 1,
	MAX = 2
};

/**
 * Enum Engine.EGraphAxisStyle
 */
enum class EGraphAxisStyle : uint8_t
{
	Lines = 0,
	Notches = 1,
	Grid = 2,
	MAX = 3
};

/**
 * Enum Engine.ReverbPreset
 */
enum class EReverbPreset : uint8_t
{
	REVERB_Default = 0,
	REVERB_Bathroom = 1,
	REVERB_StoneRoom = 2,
	REVERB_Auditorium = 3,
	REVERB_ConcertHall = 4,
	REVERB_Cave = 5,
	REVERB_Hallway = 6,
	REVERB_StoneCorridor = 7,
	REVERB_Alley = 8,
	REVERB_Forest = 9,
	REVERB_City = 10,
	REVERB_Mountains = 11,
	REVERB_Quarry = 12,
	REVERB_Plain = 13,
	REVERB_ParkingLot = 14,
	REVERB_SewerPipe = 15,
	REVERB_Underwater = 16,
	REVERB_SmallRoom = 17,
	REVERB_MediumRoom = 18,
	REVERB_LargeRoom = 19,
	REVERB_MediumHall = 20,
	REVERB_LargeHall = 21,
	REVERB_Plate = 22,
	REVERB_MAX = 23
};

/**
 * Enum Engine.ERichCurveKeyTimeCompressionFormat
 */
enum class ERichCurveKeyTimeCompressionFormat : uint8_t
{
	RCKTCF_uint16 = 0,
	RCKTCF_float32 = 1,
	RCKTCF_MAX = 2
};

/**
 * Enum Engine.ERichCurveCompressionFormat
 */
enum class ERichCurveCompressionFormat : uint8_t
{
	RCCF_Empty = 0,
	RCCF_Constant = 1,
	RCCF_Linear = 2,
	RCCF_Cubic = 3,
	RCCF_Mixed = 4,
	RCCF_Weighted = 5,
	RCCF_MAX = 6
};

/**
 * Enum Engine.ERichCurveTangentWeightMode
 */
enum class ERichCurveTangentWeightMode : uint8_t
{
	RCTWM_WeightedNone = 0,
	RCTWM_WeightedArrive = 1,
	RCTWM_WeightedLeave = 2,
	RCTWM_WeightedBoth = 3,
	RCTWM_MAX = 4
};

/**
 * Enum Engine.ERichCurveTangentMode
 */
enum class ERichCurveTangentMode : uint8_t
{
	RCTM_Auto = 0,
	RCTM_User = 1,
	RCTM_Break = 2,
	RCTM_None = 3,
	RCTM_MAX = 4
};

/**
 * Enum Engine.EConstraintTransform
 */
enum class EConstraintTransform : uint8_t
{
	Absolute = 0,
	Relative = 1,
	MAX = 2
};

/**
 * Enum Engine.EControlConstraint
 */
enum class EControlConstraint : uint8_t
{
	Orientation = 0,
	Translation = 1,
	MAX = 2
};

/**
 * Enum Engine.ERootMotionFinishVelocityMode
 */
enum class ERootMotionFinishVelocityMode : uint8_t
{
	MaintainLastRootMotionVelocity = 0,
	SetVelocity = 1,
	ClampVelocity = 2,
	MAX = 3
};

/**
 * Enum Engine.ERootMotionSourceSettingsFlags
 */
enum class ERootMotionSourceSettingsFlags : uint8_t
{
	UseSensitiveLiftoffCheck = 0,
	DisablePartialEndTick = 1,
	IgnoreZAccumulate = 2,
	MAX = 3
};

/**
 * Enum Engine.ERootMotionSourceStatusFlags
 */
enum class ERootMotionSourceStatusFlags : uint8_t
{
	Prepared = 0,
	Finished = 1,
	MarkedForRemoval = 2,
	MAX = 3
};

/**
 * Enum Engine.ERootMotionAccumulateMode
 */
enum class ERootMotionAccumulateMode : uint8_t
{
	Override = 0,
	Additive = 1,
	MAX = 2
};

/**
 * Enum Engine.ERuntimeVirtualTextureMainPassType
 */
enum class ERuntimeVirtualTextureMainPassType : uint8_t
{
	Never = 0,
	Exclusive = 1,
	Always = 2,
	MAX = 3
};

/**
 * Enum Engine.ERuntimeVirtualTextureMaterialType
 */
enum class ERuntimeVirtualTextureMaterialType : uint8_t
{
	BaseColor = 0,
	BaseColor_Normal_DEPRECATED = 1,
	BaseColor_Normal_Specular = 2,
	BaseColor_Normal_Specular_YCoCg = 3,
	BaseColor_Normal_Specular_Mask_YCoCg = 4,
	WorldHeight = 5,
	Count = 6,
	MAX = 7
};

/**
 * Enum Engine.EMobilePixelProjectedReflectionQuality
 */
enum class EMobilePixelProjectedReflectionQuality : uint8_t
{
	Disabled = 0,
	BestPerformance = 1,
	BetterQuality = 2,
	BestQuality = 3,
	MAX = 4
};

/**
 * Enum Engine.EMobilePlanarReflectionMode
 */
enum class EMobilePlanarReflectionMode : uint8_t
{
	Usual = 0,
	MobilePPRExclusive = 1,
	MobilePPR = 2,
	MAX = 3
};

/**
 * Enum Engine.EReflectedAndRefractedRayTracedShadows
 */
enum class EReflectedAndRefractedRayTracedShadows : uint8_t
{
	Disabled = 0,
	Hard_shadows = 1,
	Area_shadows = 2,
	MAX = 3
};

/**
 * Enum Engine.ERayTracingGlobalIlluminationType
 */
enum class ERayTracingGlobalIlluminationType : uint8_t
{
	Disabled = 0,
	BruteForce = 1,
	FinalGather = 2,
	MAX = 3
};

/**
 * Enum Engine.ETranslucencyType
 */
enum class ETranslucencyType : uint8_t
{
	Raster = 0,
	RayTracing = 1,
	MAX = 2
};

/**
 * Enum Engine.EReflectionsType
 */
enum class EReflectionsType : uint8_t
{
	ScreenSpace = 0,
	RayTracing = 1,
	MAX = 2
};

/**
 * Enum Engine.ELightUnits
 */
enum class ELightUnits : uint8_t
{
	Unitless = 0,
	Candelas = 1,
	Lumens = 2,
	MAX = 3
};

/**
 * Enum Engine.ETemperatureMethod
 */
enum class ETemperatureMethod : uint8_t
{
	TEMP_WhiteBalance = 0,
	TEMP_ColorTemperature = 1,
	TEMP_MAX = 2
};

/**
 * Enum Engine.EBloomMethod
 */
enum class EBloomMethod : uint8_t
{
	BM_SOG = 0,
	BM_FFT = 1,
	BM_MAX = 2
};

/**
 * Enum Engine.EAutoExposureMethod
 */
enum class EAutoExposureMethod : uint8_t
{
	AEM_Histogram = 0,
	AEM_Basic = 1,
	AEM_Manual = 2,
	AEM_MAX = 3
};

/**
 * Enum Engine.EAntiAliasingMethod
 */
enum class EAntiAliasingMethod : uint8_t
{
	AAM_None = 0,
	AAM_FXAA = 1,
	AAM_TemporalAA = 2,
	AAM_MSAA = 3,
	AAM_MAX = 4
};

/**
 * Enum Engine.EDepthOfFieldMethod
 */
enum class EDepthOfFieldMethod : uint8_t
{
	DOFM_BokehDOF = 0,
	DOFM_Gaussian = 1,
	DOFM_CircleDOF = 2,
	DOFM_MAX = 3
};

/**
 * Enum Engine.ESceneCapturePrimitiveRenderMode
 */
enum class ESceneCapturePrimitiveRenderMode : uint8_t
{
	PRM_LegacySceneCapture = 0,
	PRM_RenderScenePrimitives = 1,
	PRM_UseShowOnlyList = 2,
	PRM_MAX = 3
};

/**
 * Enum Engine.EMaterialProperty
 */
enum class EMaterialProperty : uint8_t
{
	MP_EmissiveColor = 0,
	MP_Opacity = 1,
	MP_OpacityMask = 2,
	MP_DiffuseColor = 3,
	MP_SpecularColor = 4,
	MP_BaseColor = 5,
	MP_Metallic = 6,
	MP_Specular = 7,
	MP_Roughness = 8,
	MP_Anisotropy = 9,
	MP_Normal = 10,
	MP_Tangent = 11,
	MP_WorldPositionOffset = 12,
	MP_WorldDisplacement = 13,
	MP_TessellationMultiplier = 14,
	MP_SubsurfaceColor = 15,
	MP_CustomData0 = 16,
	MP_CustomData1 = 17,
	MP_AmbientOcclusion = 18,
	MP_Refraction = 19,
	MP_CustomizedUVs0 = 20,
	MP_CustomizedUVs1 = 21,
	MP_CustomizedUVs2 = 22,
	MP_CustomizedUVs3 = 23,
	MP_CustomizedUVs4 = 24,
	MP_CustomizedUVs5 = 25,
	MP_CustomizedUVs6 = 26,
	MP_CustomizedUVs7 = 27,
	MP_PixelDepthOffset = 28,
	MP_ShadingModel = 29,
	MP_MaterialAttributes = 30,
	MP_CustomOutput = 31,
	MP_MAX = 32
};

/**
 * Enum Engine.ESkinCacheDefaultBehavior
 */
enum class ESkinCacheDefaultBehavior : uint8_t
{
	Exclusive = 0,
	Inclusive = 1,
	MAX = 2
};

/**
 * Enum Engine.ESkinCacheUsage
 */
enum class ESkinCacheUsage : uint8_t
{
	Auto = 0,
	Disabled = 1,
	Enabled = 2,
	MAX = 3
};

/**
 * Enum Engine.EPhysicsTransformUpdateMode
 */
enum class EPhysicsTransformUpdateMode : uint8_t
{
	SimulationUpatesComponentTransform = 0,
	ComponentTransformIsKinematic = 1,
	MAX = 2
};

/**
 * Enum Engine.EAnimationMode
 */
enum class EAnimationMode : uint8_t
{
	AnimationBlueprint = 0,
	AnimationSingleNode = 1,
	AnimationCustomMode = 2,
	MAX = 3
};

/**
 * Enum Engine.EKinematicBonesUpdateToPhysics
 */
enum class EKinematicBonesUpdateToPhysics : uint8_t
{
	SkipSimulatingBones = 0,
	SkipAllBones = 1,
	MAX = 2
};

/**
 * Enum Engine.ECustomBoneAttributeLookup
 */
enum class ECustomBoneAttributeLookup : uint8_t
{
	BoneOnly = 0,
	ImmediateParent = 1,
	ParentHierarchy = 2,
	MAX = 3
};

/**
 * Enum Engine.EAnimCurveType
 */
enum class EAnimCurveType : uint8_t
{
	AttributeCurve = 0,
	MaterialCurve = 1,
	MorphTargetCurve = 2,
	MaxAnimCurveType = 3,
	MAX = 4
};

/**
 * Enum Engine.ESkeletalMeshSkinningImportVersions
 */
enum class ESkeletalMeshSkinningImportVersions : uint8_t
{
	Before_Versionning = 0,
	SkeletalMeshBuildRefactor = 1,
	VersionPlusOne = 2,
	LatestVersion = 3,
	MAX = 4
};

/**
 * Enum Engine.ESkeletalMeshGeoImportVersions
 */
enum class ESkeletalMeshGeoImportVersions : uint8_t
{
	Before_Versionning = 0,
	SkeletalMeshBuildRefactor = 1,
	VersionPlusOne = 2,
	LatestVersion = 3,
	MAX = 4
};

/**
 * Enum Engine.EBoneFilterActionOption
 */
enum class EBoneFilterActionOption : uint8_t
{
	Remove = 0,
	Keep = 1,
	Invalid = 2,
	MAX = 3
};

/**
 * Enum Engine.SkeletalMeshOptimizationImportance
 */
enum class ESkeletalMeshOptimizationImportance : uint8_t
{
	SMOI_Off = 0,
	SMOI_Lowest = 1,
	SMOI_Low = 2,
	SMOI_Normal = 3,
	SMOI_High = 4,
	SMOI_Highest = 5,
	SMOI_MAX = 6
};

/**
 * Enum Engine.SkeletalMeshOptimizationType
 */
enum class ESkeletalMeshOptimizationType : uint8_t
{
	SMOT_NumOfTriangles = 0,
	SMOT_MaxDeviation = 1,
	SMOT_TriangleOrDeviation = 2,
	SMOT_MAX = 3
};

/**
 * Enum Engine.SkeletalMeshTerminationCriterion
 */
enum class ESkeletalMeshTerminationCriterion : uint8_t
{
	SMTC_NumOfTriangles = 0,
	SMTC_NumOfVerts = 1,
	SMTC_TriangleOrVert = 2,
	SMTC_AbsNumOfTriangles = 3,
	SMTC_AbsNumOfVerts = 4,
	SMTC_AbsTriangleOrVert = 5,
	SMTC_MAX = 6
};

/**
 * Enum Engine.EBoneTranslationRetargetingMode
 */
enum class EBoneTranslationRetargetingMode : uint8_t
{
	Animation = 0,
	Skeleton = 1,
	AnimationScaled = 2,
	AnimationRelative = 3,
	OrientAndScale = 4,
	MAX = 5
};

/**
 * Enum Engine.EVertexOffsetUsageType
 */
enum class EVertexOffsetUsageType : uint8_t
{
	None = 0,
	PreSkinningOffset = 1,
	PostSkinningOffset = 2,
	MAX = 3
};

/**
 * Enum Engine.EBoneSpaces
 */
enum class EBoneSpaces : uint8_t
{
	WorldSpace = 0,
	ComponentSpace = 1,
	MAX = 2
};

/**
 * Enum Engine.EVisibilityBasedAnimTickOption
 */
enum class EVisibilityBasedAnimTickOption : uint8_t
{
	AlwaysTickPoseAndRefreshBones = 0,
	AlwaysTickPose = 1,
	OnlyTickMontagesWhenNotRendered = 2,
	OnlyTickPoseWhenRendered = 3,
	MAX = 4
};

/**
 * Enum Engine.EPhysBodyOp
 */
enum class EPhysBodyOp : uint8_t
{
	PBO_None = 0,
	PBO_Term = 1,
	PBO_MAX = 2
};

/**
 * Enum Engine.EBoneVisibilityStatus
 */
enum class EBoneVisibilityStatus : uint8_t
{
	BVS_HiddenByParent = 0,
	BVS_Visible = 1,
	BVS_ExplicitlyHidden = 2,
	BVS_MAX = 3
};

/**
 * Enum Engine.ESkyAtmosphereTransformMode
 */
enum class ESkyAtmosphereTransformMode : uint8_t
{
	PlanetTopAtAbsoluteWorldOrigin = 0,
	PlanetTopAtComponentTransform = 1,
	PlanetCenterAtComponentTransform = 2,
	MAX = 3
};

/**
 * Enum Engine.ESkyLightSourceType
 */
enum class ESkyLightSourceType : uint8_t
{
	SLS_CapturedScene = 0,
	SLS_SpecifiedCubemap = 1,
	SLS_MAX = 2
};

/**
 * Enum Engine.EPriorityAttenuationMethod
 */
enum class EPriorityAttenuationMethod : uint8_t
{
	Linear = 0,
	CustomCurve = 1,
	Manual = 2,
	MAX = 3
};

/**
 * Enum Engine.ESubmixSendMethod
 */
enum class ESubmixSendMethod : uint8_t
{
	Linear = 0,
	CustomCurve = 1,
	Manual = 2,
	MAX = 3
};

/**
 * Enum Engine.EReverbSendMethod
 */
enum class EReverbSendMethod : uint8_t
{
	Linear = 0,
	CustomCurve = 1,
	Manual = 2,
	MAX = 3
};

/**
 * Enum Engine.EAirAbsorptionMethod
 */
enum class EAirAbsorptionMethod : uint8_t
{
	Linear = 0,
	CustomCurve = 1,
	MAX = 2
};

/**
 * Enum Engine.ESoundSpatializationAlgorithm
 */
enum class ESoundSpatializationAlgorithm : uint8_t
{
	SPATIALIZATION_Default = 0,
	SPATIALIZATION_HRTF = 1,
	SPATIALIZATION_MAX = 2
};

/**
 * Enum Engine.ESoundDistanceCalc
 */
enum class ESoundDistanceCalc : uint8_t
{
	SOUNDDISTANCE_Normal = 0,
	SOUNDDISTANCE_InfiniteXYPlane = 1,
	SOUNDDISTANCE_InfiniteXZPlane = 2,
	SOUNDDISTANCE_InfiniteYZPlane = 3,
	SOUNDDISTANCE_MAX = 4
};

/**
 * Enum Engine.EVirtualizationMode
 */
enum class EVirtualizationMode : uint8_t
{
	Disabled = 0,
	PlayWhenSilent = 1,
	Restart = 2,
	MAX = 3
};

/**
 * Enum Engine.EConcurrencyVolumeScaleMode
 */
enum class EConcurrencyVolumeScaleMode : uint8_t
{
	Default = 0,
	Distance = 1,
	Priority = 2,
	MAX = 3
};

/**
 * Enum Engine.EMaxConcurrentResolutionRule
 */
enum class EMaxConcurrentResolutionRule : uint8_t
{
	PreventNew = 0,
	StopOldest = 1,
	StopFarthestThenPreventNew = 2,
	StopFarthestThenOldest = 3,
	StopLowestPriority = 4,
	StopQuietest = 5,
	StopLowestPriorityThenPreventNew = 6,
	Count = 7,
	MAX = 8
};

/**
 * Enum Engine.ESoundGroup
 */
enum class ESoundGroup : uint8_t
{
	SOUNDGROUP_Default = 0,
	SOUNDGROUP_Effects = 1,
	SOUNDGROUP_UI = 2,
	SOUNDGROUP_Music = 3,
	SOUNDGROUP_Voice = 4,
	SOUNDGROUP_GameSoundGroup1 = 5,
	SOUNDGROUP_GameSoundGroup2 = 6,
	SOUNDGROUP_GameSoundGroup3 = 7,
	SOUNDGROUP_GameSoundGroup4 = 8,
	SOUNDGROUP_GameSoundGroup5 = 9,
	SOUNDGROUP_GameSoundGroup6 = 10,
	SOUNDGROUP_GameSoundGroup7 = 11,
	SOUNDGROUP_GameSoundGroup8 = 12,
	SOUNDGROUP_GameSoundGroup9 = 13,
	SOUNDGROUP_GameSoundGroup10 = 14,
	SOUNDGROUP_GameSoundGroup11 = 15,
	SOUNDGROUP_GameSoundGroup12 = 16,
	SOUNDGROUP_GameSoundGroup13 = 17,
	SOUNDGROUP_GameSoundGroup14 = 18,
	SOUNDGROUP_GameSoundGroup15 = 19,
	SOUNDGROUP_GameSoundGroup16 = 20,
	SOUNDGROUP_GameSoundGroup17 = 21,
	SOUNDGROUP_GameSoundGroup18 = 22,
	SOUNDGROUP_GameSoundGroup19 = 23,
	SOUNDGROUP_GameSoundGroup20 = 24,
	SOUNDGROUP_MAX = 25
};

/**
 * Enum Engine.EModulationRouting
 */
enum class EModulationRouting : uint8_t
{
	Disable = 0,
	Inherit = 1,
	Override = 2,
	MAX = 3
};

/**
 * Enum Engine.ModulationParamMode
 */
enum class EModulationParamMode : uint8_t
{
	MPM_Normal = 0,
	MPM_Abs = 1,
	MPM_Direct = 2,
	MPM_MAX = 3
};

/**
 * Enum Engine.ESourceBusChannels
 */
enum class ESourceBusChannels : uint8_t
{
	Mono = 0,
	Stereo = 1,
	MAX = 2
};

/**
 * Enum Engine.ESourceBusSendLevelControlMethod
 */
enum class ESourceBusSendLevelControlMethod : uint8_t
{
	Linear = 0,
	CustomCurve = 1,
	Manual = 2,
	MAX = 3
};

/**
 * Enum Engine.EGainParamMode
 */
enum class EGainParamMode : uint8_t
{
	Linear = 0,
	Decibels = 1,
	MAX = 2
};

/**
 * Enum Engine.EAudioSpectrumType
 */
enum class EAudioSpectrumType : uint8_t
{
	MagnitudeSpectrum = 0,
	PowerSpectrum = 1,
	Decibel = 2,
	MAX = 3
};

/**
 * Enum Engine.EFFTWindowType
 */
enum class EFFTWindowType : uint8_t
{
	None = 0,
	Hamming = 1,
	Hann = 2,
	Blackman = 3,
	MAX = 4
};

/**
 * Enum Engine.EFFTPeakInterpolationMethod
 */
enum class EFFTPeakInterpolationMethod : uint8_t
{
	NearestNeighbor = 0,
	Linear = 1,
	Quadratic = 2,
	ConstantQ = 3,
	MAX = 4
};

/**
 * Enum Engine.EFFTSize
 */
enum class EFFTSize : uint8_t
{
	DefaultSize = 0,
	Min = 1,
	Small = 2,
	Medium = 3,
	Large = 4,
	VeryLarge = 5,
	Max = 6
};

/**
 * Enum Engine.ESubmixSendStage
 */
enum class ESubmixSendStage : uint8_t
{
	PostDistanceAttenuation = 0,
	PreDistanceAttenuation = 1,
	MAX = 2
};

/**
 * Enum Engine.ESendLevelControlMethod
 */
enum class ESendLevelControlMethod : uint8_t
{
	Linear = 0,
	CustomCurve = 1,
	Manual = 2,
	MAX = 3
};

/**
 * Enum Engine.EAudioRecordingExportType
 */
enum class EAudioRecordingExportType : uint8_t
{
	SoundWave = 0,
	WavFile = 1,
	MAX = 2
};

/**
 * Enum Engine.EAudioSpectrumBandPresetType
 */
enum class EAudioSpectrumBandPresetType : uint8_t
{
	KickDrum = 0,
	SnareDrum = 1,
	Voice = 2,
	Cymbals = 3,
	MAX = 4
};

/**
 * Enum Engine.ESoundWaveFFTSize
 */
enum class ESoundWaveFFTSize : uint8_t
{
	VerySmall = 0,
	Small = 1,
	Medium = 2,
	Large = 3,
	VeryLarge = 4,
	MAX = 5
};

/**
 * Enum Engine.EDecompressionType
 */
enum class EDecompressionType : uint8_t
{
	DTYPE_Setup = 0,
	DTYPE_Invalid = 1,
	DTYPE_Preview = 2,
	DTYPE_Native = 3,
	DTYPE_RealTime = 4,
	DTYPE_Procedural = 5,
	DTYPE_Xenon = 6,
	DTYPE_Streaming = 7,
	DTYPE_MAX = 8
};

/**
 * Enum Engine.ESoundWaveLoadingBehavior
 */
enum class ESoundWaveLoadingBehavior : uint8_t
{
	Inherited = 0,
	RetainOnLoad = 1,
	PrimeOnLoad = 2,
	LoadOnDemand = 3,
	ForceInline = 4,
	Uninitialized = 5,
	MAX = 6
};

/**
 * Enum Engine.ESplineCoordinateSpace
 */
enum class ESplineCoordinateSpace : uint8_t
{
	Local = 0,
	World = 1,
	MAX = 2
};

/**
 * Enum Engine.ESplinePointType
 */
enum class ESplinePointType : uint8_t
{
	Linear = 0,
	Curve = 1,
	Constant = 2,
	CurveClamped = 3,
	CurveCustomTangent = 4,
	MAX = 5
};

/**
 * Enum Engine.ESplineMeshAxis
 */
enum class ESplineMeshAxis : uint8_t
{
	X = 0,
	Y = 1,
	Z = 2,
	MAX = 3
};

/**
 * Enum Engine.EOptimizationType
 */
enum class EOptimizationType : uint8_t
{
	OT_NumOfTriangles = 0,
	OT_MaxDeviation = 1,
	OT_MAX = 2
};

/**
 * Enum Engine.EImportanceLevel
 */
enum class EImportanceLevel : uint8_t
{
	IL_Off = 0,
	IL_Lowest = 1,
	IL_Low = 2,
	IL_Normal = 3,
	IL_High = 4,
	IL_Highest = 5,
	TEMP_BROKEN2 = 6,
	MAX = 7
};

/**
 * Enum Engine.ENormalMode
 */
enum class ENormalMode : uint8_t
{
	NM_PreserveSmoothingGroups = 0,
	NM_RecalculateNormals = 1,
	NM_RecalculateNormalsSmooth = 2,
	NM_RecalculateNormalsHard = 3,
	TEMP_BROKEN = 4,
	MAX = 5
};

/**
 * Enum Engine.EStereoLayerShape
 */
enum class EStereoLayerShape : uint8_t
{
	SLSH_QuadLayer = 0,
	SLSH_CylinderLayer = 1,
	SLSH_CubemapLayer = 2,
	SLSH_EquirectLayer = 3,
	SLSH_MAX = 4
};

/**
 * Enum Engine.EStereoLayerType
 */
enum class EStereoLayerType : uint8_t
{
	SLT_WorldLocked = 0,
	SLT_TrackerLocked = 1,
	SLT_FaceLocked = 2,
	SLT_MAX = 3
};

/**
 * Enum Engine.EOpacitySourceMode
 */
enum class EOpacitySourceMode : uint8_t
{
	OSM_Alpha = 0,
	OSM_ColorBrightness = 1,
	OSM_RedChannel = 2,
	OSM_GreenChannel = 3,
	OSM_BlueChannel = 4,
	OSM_MAX = 5
};

/**
 * Enum Engine.ESubUVBoundingVertexCount
 */
enum class ESubUVBoundingVertexCount : uint8_t
{
	BVC_FourVertices = 0,
	BVC_EightVertices = 1,
	BVC_MAX = 2
};

/**
 * Enum Engine.EVerticalTextAligment
 */
enum class EVerticalTextAligment : uint8_t
{
	EVRTA_TextTop = 0,
	EVRTA_TextCenter = 1,
	EVRTA_TextBottom = 2,
	EVRTA_QuadTop = 3,
	EVRTA_MAX = 4
};

/**
 * Enum Engine.EHorizTextAligment
 */
enum class EHorizTextAligment : uint8_t
{
	EHTA_Left = 0,
	EHTA_Center = 1,
	EHTA_Right = 2,
	EHTA_MAX = 3
};

/**
 * Enum Engine.ETextureCompressionQuality
 */
enum class ETextureCompressionQuality : uint8_t
{
	TCQ_Default = 0,
	TCQ_Lowest = 1,
	TCQ_Low = 2,
	TCQ_Medium = 3,
	TCQ_High = 4,
	TCQ_Highest = 5,
	TCQ_MAX = 6
};

/**
 * Enum Engine.ETextureSourceFormat
 */
enum class ETextureSourceFormat : uint8_t
{
	TSF_Invalid = 0,
	TSF_G8 = 1,
	TSF_BGRA8 = 2,
	TSF_BGRE8 = 3,
	TSF_RGBA16 = 4,
	TSF_RGBA16F = 5,
	TSF_RGBA8 = 6,
	TSF_RGBE8 = 7,
	TSF_G16 = 8,
	TSF_MAX = 9
};

/**
 * Enum Engine.ETextureSourceArtType
 */
enum class ETextureSourceArtType : uint8_t
{
	TSAT_Uncompressed = 0,
	TSAT_PNGCompressed = 1,
	TSAT_DDSFile = 2,
	TSAT_MAX = 3
};

/**
 * Enum Engine.ETextureMipCount
 */
enum class ETextureMipCount : uint8_t
{
	TMC_ResidentMips = 0,
	TMC_AllMips = 1,
	TMC_AllMipsBiased = 2,
	TMC_MAX = 3
};

/**
 * Enum Engine.ECompositeTextureMode
 */
enum class ECompositeTextureMode : uint8_t
{
	CTM_Disabled = 0,
	CTM_NormalRoughnessToRed = 1,
	CTM_NormalRoughnessToGreen = 2,
	CTM_NormalRoughnessToBlue = 3,
	CTM_NormalRoughnessToAlpha = 4,
	CTM_MAX = 5
};

/**
 * Enum Engine.TextureAddress
 */
enum class ETextureAddress : uint8_t
{
	TA_Wrap = 0,
	TA_Clamp = 1,
	TA_Mirror = 2,
	TA_MAX = 3
};

/**
 * Enum Engine.TextureFilter
 */
enum class ETextureFilter : uint8_t
{
	TF_Nearest = 0,
	TF_Bilinear = 1,
	TF_Trilinear = 2,
	TF_Default = 3,
	TF_MAX = 4
};

/**
 * Enum Engine.TextureCompressionSettings
 */
enum class ETextureCompressionSettings : uint8_t
{
	TC_Default = 0,
	TC_Normalmap = 1,
	TC_Masks = 2,
	TC_Grayscale = 3,
	TC_Displacementmap = 4,
	TC_VectorDisplacementmap = 5,
	TC_HDR = 6,
	TC_EditorIcon = 7,
	TC_Alpha = 8,
	TC_DistanceFieldFont = 9,
	TC_HDR_Compressed = 10,
	TC_BC7 = 11,
	TC_HalfFloat = 12,
	TC_EncodedReflectionCapture = 13,
	TC_MAX = 14
};

/**
 * Enum Engine.ETextureLossyCompressionAmount
 */
enum class ETextureLossyCompressionAmount : uint8_t
{
	TLCA_Default = 0,
	TLCA_None = 1,
	TLCA_Lowest = 2,
	TLCA_Low = 3,
	TLCA_Medium = 4,
	TLCA_High = 5,
	TLCA_Highest = 6,
	TLCA_MAX = 7
};

/**
 * Enum Engine.ETextureDownscaleOptions
 */
enum class ETextureDownscaleOptions : uint8_t
{
	Default = 0,
	Unfiltered = 1,
	SimpleAverage = 2,
	Sharpen0 = 3,
	Sharpen1 = 4,
	Sharpen2 = 5,
	Sharpen3 = 6,
	Sharpen4 = 7,
	Sharpen5 = 8,
	Sharpen6 = 9,
	Sharpen7 = 10,
	Sharpen8 = 11,
	Sharpen9 = 12,
	Sharpen10 = 13,
	MAX = 14
};

/**
 * Enum Engine.ETextureMipLoadOptions
 */
enum class ETextureMipLoadOptions : uint8_t
{
	Default = 0,
	AllMips = 1,
	OnlyFirstMip = 2,
	MAX = 3
};

/**
 * Enum Engine.ETextureSamplerFilter
 */
enum class ETextureSamplerFilter : uint8_t
{
	Point = 0,
	Bilinear = 1,
	Trilinear = 2,
	AnisotropicPoint = 3,
	AnisotropicLinear = 4,
	MAX = 5
};

/**
 * Enum Engine.ETexturePowerOfTwoSetting
 */
enum class ETexturePowerOfTwoSetting : uint8_t
{
	None = 0,
	PadToPowerOfTwo = 1,
	PadToSquarePowerOfTwo = 2,
	StretchToPowerOfTwo = 3,
	StretchToSquarePowerOfTwo = 4,
	MAX = 5
};

/**
 * Enum Engine.TextureMipGenSettings
 */
enum class ETextureMipGenSettings : uint8_t
{
	TMGS_FromTextureGroup = 0,
	TMGS_SimpleAverage = 1,
	TMGS_Sharpen0 = 2,
	TMGS_Sharpen1 = 3,
	TMGS_Sharpen2 = 4,
	TMGS_Sharpen3 = 5,
	TMGS_Sharpen4 = 6,
	TMGS_Sharpen5 = 7,
	TMGS_Sharpen6 = 8,
	TMGS_Sharpen7 = 9,
	TMGS_Sharpen8 = 10,
	TMGS_Sharpen9 = 11,
	TMGS_Sharpen10 = 12,
	TMGS_NoMipmaps = 13,
	TMGS_LeaveExistingMips = 14,
	TMGS_Blur1 = 15,
	TMGS_Blur2 = 16,
	TMGS_Blur3 = 17,
	TMGS_Blur4 = 18,
	TMGS_Blur5 = 19,
	TMGS_Unfiltered = 20,
	TMGS_MAX = 21
};

/**
 * Enum Engine.TextureGroup
 */
enum class ETextureGroup : uint8_t
{
	TEXTUREGROUP_World = 0,
	TEXTUREGROUP_WorldNormalMap = 1,
	TEXTUREGROUP_WorldSpecular = 2,
	TEXTUREGROUP_Character = 3,
	TEXTUREGROUP_CharacterNormalMap = 4,
	TEXTUREGROUP_CharacterSpecular = 5,
	TEXTUREGROUP_Weapon = 6,
	TEXTUREGROUP_WeaponNormalMap = 7,
	TEXTUREGROUP_WeaponSpecular = 8,
	TEXTUREGROUP_Vehicle = 9,
	TEXTUREGROUP_VehicleNormalMap = 10,
	TEXTUREGROUP_VehicleSpecular = 11,
	TEXTUREGROUP_Cinematic = 12,
	TEXTUREGROUP_Effects = 13,
	TEXTUREGROUP_EffectsNotFiltered = 14,
	TEXTUREGROUP_Skybox = 15,
	TEXTUREGROUP_UI = 16,
	TEXTUREGROUP_Lightmap = 17,
	TEXTUREGROUP_RenderTarget = 18,
	TEXTUREGROUP_MobileFlattened = 19,
	TEXTUREGROUP_ProcBuilding_Face = 20,
	TEXTUREGROUP_ProcBuilding_LightMap = 21,
	TEXTUREGROUP_Shadowmap = 22,
	TEXTUREGROUP_ColorLookupTable = 23,
	TEXTUREGROUP_Terrain_Heightmap = 24,
	TEXTUREGROUP_Terrain_Weightmap = 25,
	TEXTUREGROUP_Bokeh = 26,
	TEXTUREGROUP_IESLightProfile = 27,
	TEXTUREGROUP_Pixels2D = 28,
	TEXTUREGROUP_HierarchicalLOD = 29,
	TEXTUREGROUP_Impostor = 30,
	TEXTUREGROUP_ImpostorNormalDepth = 31,
	TEXTUREGROUP_8BitData = 32,
	TEXTUREGROUP_16BitData = 33,
	TEXTUREGROUP_Project01 = 34,
	TEXTUREGROUP_Project02 = 35,
	TEXTUREGROUP_Project03 = 36,
	TEXTUREGROUP_Project04 = 37,
	TEXTUREGROUP_Project05 = 38,
	TEXTUREGROUP_Project06 = 39,
	TEXTUREGROUP_Project07 = 40,
	TEXTUREGROUP_Project08 = 41,
	TEXTUREGROUP_Project09 = 42,
	TEXTUREGROUP_Project10 = 43,
	TEXTUREGROUP_Project11 = 44,
	TEXTUREGROUP_Project12 = 45,
	TEXTUREGROUP_Project13 = 46,
	TEXTUREGROUP_Project14 = 47,
	TEXTUREGROUP_Project15 = 48,
	TEXTUREGROUP_MAX = 49
};

/**
 * Enum Engine.ETextureRenderTargetFormat
 */
enum class ETextureRenderTargetFormat : uint8_t
{
	RTF_R8 = 0,
	RTF_RG8 = 1,
	RTF_RGBA8 = 2,
	RTF_RGBA8_SRGB = 3,
	RTF_R16f = 4,
	RTF_RG16f = 5,
	RTF_RGBA16f = 6,
	RTF_R32f = 7,
	RTF_RG32f = 8,
	RTF_RGBA32f = 9,
	RTF_RGB10A2 = 10,
	RTF_MAX = 11
};

/**
 * Enum Engine.ETimecodeProviderSynchronizationState
 */
enum class ETimecodeProviderSynchronizationState : uint8_t
{
	Closed = 0,
	Error = 1,
	Synchronized = 2,
	Synchronizing = 3,
	MAX = 4
};

/**
 * Enum Engine.ETimelineDirection
 */
enum class ETimelineDirection : uint8_t
{
	Forward = 0,
	Backward = 1,
	MAX = 2
};

/**
 * Enum Engine.ETimelineLengthMode
 */
enum class ETimelineLengthMode : uint8_t
{
	TL_TimelineLength = 0,
	TL_LastKeyFrame = 1,
	TL_MAX = 2
};

/**
 * Enum Engine.ETimeStretchCurveMapping
 */
enum class ETimeStretchCurveMapping : uint8_t
{
	T_Original = 0,
	T_TargetMin = 1,
	T_TargetMax = 2,
	MAX = 3
};

/**
 * Enum Engine.ETwitterIntegrationDelegate
 */
enum class ETwitterIntegrationDelegate : uint8_t
{
	TID_AuthorizeComplete = 0,
	TID_TweetUIComplete = 1,
	TID_RequestComplete = 2,
	TID_MAX = 3
};

/**
 * Enum Engine.ETwitterRequestMethod
 */
enum class ETwitterRequestMethod : uint8_t
{
	TRM_Get = 0,
	TRM_Post = 1,
	TRM_Delete = 2,
	TRM_MAX = 3
};

/**
 * Enum Engine.EUserDefinedStructureStatus
 */
enum class EUserDefinedStructureStatus : uint8_t
{
	UDSS_UpToDate = 0,
	UDSS_Dirty = 1,
	UDSS_Error = 2,
	UDSS_Duplicate = 3,
	UDSS_MAX = 4
};

/**
 * Enum Engine.EUIScalingRule
 */
enum class EUIScalingRule : uint8_t
{
	ShortestSide = 0,
	LongestSide = 1,
	Horizontal = 2,
	Vertical = 3,
	ScaleToFit = 4,
	Custom = 5,
	MAX = 6
};

/**
 * Enum Engine.ERenderFocusRule
 */
enum class ERenderFocusRule : uint8_t
{
	Always = 0,
	NonPointer = 1,
	NavigationOnly = 2,
	Never = 3,
	MAX = 4
};

/**
 * Enum Engine.EVectorFieldConstructionOp
 */
enum class EVectorFieldConstructionOp : uint8_t
{
	VFCO_Extrude = 0,
	VFCO_Revolve = 1,
	VFCO_MAX = 2
};

/**
 * Enum Engine.EWindSourceType
 */
enum class EWindSourceType : uint8_t
{
	Directional = 0,
	Point = 1,
	MAX = 2
};

/**
 * Enum Engine.EPSCPoolMethod
 */
enum class EPSCPoolMethod : uint8_t
{
	None = 0,
	AutoRelease = 1,
	ManualRelease = 2,
	ManualRelease_OnComplete = 3,
	FreeInPool = 4,
	MAX = 5
};

/**
 * Enum Engine.EVolumeLightingMethod
 */
enum class EVolumeLightingMethod : uint8_t
{
	VLM_VolumetricLightmap = 0,
	VLM_SparseVolumeLightingSamples = 1,
	VLM_MAX = 2
};

/**
 * Enum Engine.EVisibilityAggressiveness
 */
enum class EVisibilityAggressiveness : uint8_t
{
	VIS_LeastAggressive = 0,
	VIS_ModeratelyAggressive = 1,
	VIS_MostAggressive = 2,
	VIS_Max = 3
};

enum class EPhysicalSurface : uint8_t
{
	SurfaceType_Default = 0,
	SurfaceType1 = 1,
	SurfaceType2 = 2,
	SurfaceType3 = 3,
	SurfaceType4 = 4,
	SurfaceType5 = 5,
	SurfaceType6 = 6,
	SurfaceType7 = 7,
	SurfaceType8 = 8,
	SurfaceType9 = 9,
	SurfaceType10 = 10,
	SurfaceType11 = 11,
	SurfaceType12 = 12,
	SurfaceType13 = 13,
	SurfaceType14 = 14,
	SurfaceType15 = 15,
	SurfaceType16 = 16,
	SurfaceType17 = 17,
	SurfaceType18 = 18,
	SurfaceType19 = 19,
	SurfaceType20 = 20,
	SurfaceType21 = 21,
	SurfaceType22 = 22,
	SurfaceType23 = 23,
	SurfaceType24 = 24,
	SurfaceType25 = 25,
	SurfaceType26 = 26,
	SurfaceType27 = 27,
	SurfaceType28 = 28,
	SurfaceType29 = 29,
	SurfaceType30 = 30,
	SurfaceType31 = 31,
	SurfaceType32 = 32,
	SurfaceType33 = 33,
	SurfaceType34 = 34,
	SurfaceType35 = 35,
	SurfaceType36 = 36,
	SurfaceType37 = 37,
	SurfaceType38 = 38,
	SurfaceType39 = 39,
	SurfaceType40 = 40,
	SurfaceType41 = 41,
	SurfaceType42 = 42,
	SurfaceType43 = 43,
	SurfaceType44 = 44,
	SurfaceType45 = 45,
	SurfaceType46 = 46,
	SurfaceType47 = 47,
	SurfaceType48 = 48,
	SurfaceType49 = 49,
	SurfaceType50 = 50,
	SurfaceType51 = 51,
	SurfaceType52 = 52,
	SurfaceType53 = 53,
	SurfaceType54 = 54,
	SurfaceType55 = 55,
	SurfaceType56 = 56,
	SurfaceType57 = 57,
	SurfaceType58 = 58,
	SurfaceType59 = 59,
	SurfaceType60 = 60,
	SurfaceType61 = 61,
	SurfaceType62 = 62,
	SurfaceType_Max = 63,
	MAX = 64
};

enum class ETouchIndex : uint8_t
{
	ETouchIndex__Touch1 = 0,
	ETouchIndex__Touch2 = 1,
	ETouchIndex__Touch3 = 2,
	ETouchIndex__Touch4 = 3,
	ETouchIndex__Touch5 = 4,
	ETouchIndex__Touch6 = 5,
	ETouchIndex__Touch7 = 6,
	ETouchIndex__Touch8 = 7,
	ETouchIndex__Touch9 = 8,
	ETouchIndex__Touch10 = 9,
	ETouchIndex__CursorPointerIndex = 10,
	ETouchIndex__MAX_TOUCHES = 11
};

enum class EControllerHand : uint8_t
{
	EControllerHand__Left = 0,
	EControllerHand__Right = 1,
	EControllerHand__AnyHand = 2,
	EControllerHand__Pad = 3,
	EControllerHand__ExternalCamera = 4,
	EControllerHand__Gun = 5,
	EControllerHand__HMD = 6,
	EControllerHand__Special = 7,
	EControllerHand__Special9 = 8,
	EControllerHand__Special10 = 9,
	EControllerHand__Special11 = 10,
	EControllerHand__Special12 = 11,
	EControllerHand__Special13 = 12,
	EControllerHand__Special14 = 13,
	EControllerHand__Special15 = 14,
	EControllerHand__Special16 = 15,
	EControllerHand__Special17 = 16,
	EControllerHand__Special18 = 17,
	EControllerHand__ControllerHand_Count = 18
};

enum class EMouseCursor : uint8_t
{
	EMouseCursor__None = 0,
	EMouseCursor__Default = 1,
	EMouseCursor__TextEditBeam = 2,
	EMouseCursor__ResizeLeftRight = 3,
	EMouseCursor__ResizeUpDown = 4,
	EMouseCursor__ResizeSouthEast = 5,
	EMouseCursor__ResizeSouthWest = 6,
	EMouseCursor__CardinalCross = 7,
	EMouseCursor__Crosshairs = 8,
	EMouseCursor__Hand = 9,
	EMouseCursor__GrabHand = 10,
	EMouseCursor__GrabHandClosed = 11,
	EMouseCursor__SlashedCircle = 12,
	EMouseCursor__EyeDropper = 13
};

enum Bones {
	Root = 0,
	Hips = 1,
	Spine = 2,
	jigglebone_6 = 3,
	jigglebone_7 = 4,
	jigglebone_8 = 5,
	jigglebone_9 = 6,
	Spine1 = 7,
	Spine2 = 8,
	Spine3 = 9,
	Spine4 = 10,
	jigglebone_1 = 11,
	jigglebone_2 = 12,
	jigglebone_3 = 13,
	jigglebone_4 = 14,
	jigglebone_5 = 15,
	Neck = 16,
	Neck1 = 17,
	Neck2 = 18,
	Head = 19,
	jigglebone_22 = 20,
	jigglebone_23 = 21,
	LeftShoulder = 22,
	LeftArm = 23,
	LeftArmRoll = 24,
	jigglebone_18 = 25,
	jigglebone_19 = 26,
	LeftForeArm = 27,
	LeftForeArmRoll = 28,
	LeftHand = 29,
	LeftHandThumb1 = 30,
	LeftHandThumb2 = 31,
	LeftHandThumb3 = 32,
	LeftHandThumb4 = 33,
	LeftHandIndex = 34,
	LeftHandIndex1 = 35,
	LeftHandIndex2 = 36,
	LeftHandIndex3 = 37,
	LeftHandIndex4 = 38,
	LeftHandMiddle = 39,
	LeftHandMiddle1 = 40,
	LeftHandMiddle2 = 41,
	LeftHandMiddle3 = 42,
	LeftHandMiddle4 = 43,
	LeftHandRing = 44,
	LeftHandRing1 = 45,
	LeftHandRing2 = 46,
	LeftHandRing3 = 47,
	LeftHandRing4 = 48,
	LeftHandPinky = 49,
	LeftHandPinky1 = 50,
	LeftHandPinky2 = 51,
	LeftHandPinky3 = 52,
	LeftHandPinky4 = 53,
	Left_weapon = 54,
	LeftForeArm_s = 55,
	RightShoulder = 56,
	RightArm = 57,
	RightArmRoll = 58,
	jigglebone_20 = 59,
	jigglebone_21 = 60,
	RightForeArm = 61,
	RightForeArmRoll = 62,
	RightHand = 63,
	RightHandThumb1 = 64,
	RightHandThumb2 = 65,
	RightHandThumb3 = 66,
	RightHandThumb4 = 67,
	RightHandIndex = 68,
	RightHandIndex1 = 69,
	RightHandIndex2 = 70,
	RightHandIndex3 = 71,
	RightHandIndex4 = 72,
	RightHandMiddle = 73,
	RightHandMiddle1 = 74,
	RightHandMiddle2 = 75,
	RightHandMiddle3 = 76,
	RightHandMiddle4 = 77,
	RightHandRing = 78,
	RightHandRing1 = 79,
	RightHandRing2 = 80,
	RightHandRing3 = 81,
	RightHandRing4 = 82,
	RightHandPinky = 83,
	RightHandPinky1 = 84,
	RightHandPinky2 = 85,
	RightHandPinky3 = 86,
	RightHandPinky4 = 87,
	Right_weapon = 88,
	RightForeArm_s = 89,
	back_left_attachpoint = 90,
	back_right_attachpoint = 91,
	hip_left_attachpoint = 92,
	hip_right_attachpoint = 93,
	RightUpleg = 94,
	RightUpLegRoll = 95,
	jigglebone_24 = 96,
	jigglebone_25 = 97,
	RightLeg = 98,
	RightLegRoll = 99,
	jigglebone_26 = 100,
	jigglebone_27 = 101,
	RightFoot = 102,
	RightToeBase = 103,
	RightLeg_s = 104,
	LeftUpLeg = 105,
	LeftUpLegRoll = 106,
	jigglebone_12 = 107,
	jigglebone_13 = 108,
	LeftLeg = 109,
	LeftLegRoll = 110,
	jigglebone_14 = 111,
	jigglebone_15 = 112,
	LeftFoot = 113,
	LeftToeBase = 114,
	LeftLeg_s = 115,
	RightUpLeg_s = 116,
	LeftUpLeg_s = 117,
	VB_Right_Holder = 118,
	VB_IK_HandRoot = 119,
	VB_IK_RightHand = 120,
	VB_Gun_LeftHand = 121,
	VB_IK_LeftHand = 122,
	VB_IK_FootRoot = 123,
	VB_IK_RightFoot = 124,
	VB_IK_LeftFoot = 125,
	VB_RightLegJoint = 126,
	VB_LeftLegJoint = 127,
	VB_LeftJoint = 128,
	VB_Gun_RightHand = 129,
	VB_RightJoint = 130,
	VB_Left_Holder = 131,
	VB_AimTarget = 132
};

inline std::vector<std::pair<int, int>> Connections = {
	{Neck, Head},
	{Spine4, Neck},
	{Spine3, Spine4},
	{Spine2, Spine3},
	{Spine1, Spine2},
	{Spine, Spine1},
	{Hips, Spine},
	{RightShoulder, Spine4},
	{RightArm, RightShoulder},
	{RightForeArm, RightArm},
	{RightHand, RightForeArm},
	{LeftShoulder, Spine4},
	{LeftArm, LeftShoulder},
	{LeftForeArm, LeftArm},
	{LeftHand, LeftForeArm},
	{RightUpleg, Hips},  
	{RightLeg, RightUpleg},
	{RightFoot, RightLeg},
	{LeftUpLeg, Hips},   
	{LeftLeg, LeftUpLeg},
	{LeftFoot, LeftLeg}
};

