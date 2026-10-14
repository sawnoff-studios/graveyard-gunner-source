// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Core/Input/GGCharacterPlayerController.h"

#include "Characters/MainCharacter/GGMainCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void AGGCharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AddInputMappingContext(DefaultMappingContext, 0);

	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		ControlledCharacter->GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

void AGGCharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGGCharacterPlayerController::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AGGCharacterPlayerController::StopMove);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGGCharacterPlayerController::Look);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AGGCharacterPlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AGGCharacterPlayerController::StopJumping);

		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AGGCharacterPlayerController::StartSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AGGCharacterPlayerController::StopSprint);

		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &AGGCharacterPlayerController::ToggleCrouch);

		EnhancedInputComponent->BindAction(CameraZoomAction, ETriggerEvent::Triggered, this, &AGGCharacterPlayerController::CameraZoom);
	}
}

void AGGCharacterPlayerController::AddInputMappingContext(const UInputMappingContext* InMappingContext, int32 Priority) const
{
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InMappingContext)
			{
				Subsystem->AddMappingContext(InMappingContext, Priority);
			}
		}
	}
}

void AGGCharacterPlayerController::RemoveInputMappingContext(const UInputMappingContext* InMappingContext) const
{
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InMappingContext)
			{
				Subsystem->RemoveMappingContext(InMappingContext);
			}
		}
	}
}

void AGGCharacterPlayerController::Move(const FInputActionValue& Value)
{
	if (GetCharacter())
	{
		if (ACharacter* ControlledCharacter = GetCharacter())
		{
			ControlledCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;

			const FRotator Rotation = GetControlRotation();
			const FRotator CameraRotation(0, Rotation.Yaw, 0);

			FVector2D MovementVector = Value.Get<FVector2D>();

			const FVector ForwardDirection = FRotationMatrix(CameraRotation).GetUnitAxis(EAxis::X);
			ControlledCharacter->AddMovementInput(ForwardDirection, MovementVector.Y);

			const FVector RightDirection = FRotationMatrix(CameraRotation).GetUnitAxis(EAxis::Y);
			ControlledCharacter->AddMovementInput(RightDirection, MovementVector.X);
		}
	}
}

void AGGCharacterPlayerController::StopMove()
{
	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		ControlledCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}

void AGGCharacterPlayerController::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AGGCharacterPlayerController::Jump()
{
	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		ControlledCharacter->Jump();
	}
}

void AGGCharacterPlayerController::StopJumping()
{
	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		ControlledCharacter->StopJumping();
	}
}

void AGGCharacterPlayerController::StartSprint()
{
	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		ControlledCharacter->GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	}
}

void AGGCharacterPlayerController::StopSprint()
{
	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		ControlledCharacter->GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

void AGGCharacterPlayerController::ToggleCrouch()
{
	if (AGGMainCharacter* ControlledCharacter = CastChecked<AGGMainCharacter>(GetCharacter()))
	{
		if (ControlledCharacter->IsCrouched())
		{
			ControlledCharacter->UnCrouch();
		}
		else
		{
			ControlledCharacter->Crouch();
		}
	}
}

void AGGCharacterPlayerController::CameraZoom(const FInputActionValue& Value)
{
	if (AGGMainCharacter* ControlledCharacter = CastChecked<AGGMainCharacter>(GetCharacter()))
	{
		float ActionValue = Value.Get<float>();

		ControlledCharacter->ZoomCamera(ActionValue);
	}
}