// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Characters/MainCharacter/GGMainCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

AGGMainCharacter::AGGMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	CameraZoomTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("CameraZoomTimeline"));
}

void AGGMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->ViewPitchMin = -30;
	UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->ViewPitchMax = 30;
	
	if (CameraZoomCurve)
	{
		CameraZoomTimelineUpdate.BindUFunction(this, FName("OnCameraZoomTimelineUpdate"));
		CameraZoomTimelineFinished.BindUFunction(this, FName("OnCameraZoomTimelineFinished"));
		
		CameraZoomTimeline->AddInterpFloat(CameraZoomCurve, CameraZoomTimelineUpdate);
		CameraZoomTimeline->SetTimelineFinishedFunc(CameraZoomTimelineFinished);
		CameraZoomTimeline->SetLooping(false);
	}
}

void AGGMainCharacter::ZoomCamera(float ActionValue)
{
	if (!bIsAiming && bIsZoomFinished)
	{
		bIsZoomFinished = false;
		
		ZoomValue = ActionValue;

		CameraZoomTimeline->SetTimelineLength(0.3f);
		CameraZoomTimeline->PlayFromStart();
	}
}

void AGGMainCharacter::OnCameraZoomTimelineUpdate(float TimelineAlpha)
{
	float TargetArmLength = CameraBoom->TargetArmLength;
	float DesiredArmLength = TargetArmLength - ZoomValue;
	
	float ClampedAlpha = FMath::Clamp(DesiredArmLength, MinZoomLevel, MaxZoomLevel);
	float LerpValue = FMath::Lerp(TargetArmLength, ClampedAlpha, TimelineAlpha);
	
	CameraBoom->TargetArmLength = LerpValue;
}

void AGGMainCharacter::OnCameraZoomTimelineFinished()
{
	bIsZoomFinished = true;
}
