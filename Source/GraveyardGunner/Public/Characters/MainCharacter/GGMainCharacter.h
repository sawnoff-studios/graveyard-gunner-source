// Copyright (c) Sawnoff Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Character.h"
#include "GGMainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UBoxComponent;
class UTimelineComponent;

UCLASS()
class GRAVEYARDGUNNER_API AGGMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGGMainCharacter();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTimelineComponent> CameraZoomTimeline;

	UPROPERTY(EditAnywhere, Category = Camera)
	TObjectPtr<UCurveFloat> CameraZoomCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float MinZoomLevel = 120;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float MaxZoomLevel = 300;
	
	float ZoomValue;

protected:
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	void ZoomCamera(float ZoomValue);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	bool bIsAiming = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	bool bIsZoomFinished = true;
	
	UFUNCTION()
	void OnCameraZoomTimelineUpdate(float TimelineAlpha);

	UFUNCTION()
	void OnCameraZoomTimelineFinished();
	
private:
	FOnTimelineFloat CameraZoomTimelineUpdate;
	FOnTimelineEventStatic CameraZoomTimelineFinished;
};