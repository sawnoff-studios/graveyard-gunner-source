// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Core/Input/GGAimInversionInputModifier.h"

#include "EnhancedPlayerInput.h"
#include "Core/GGMainSaveGame.h"

FInputActionValue UGGAimInversionInputModifier::ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime)
{
	UGGMainSaveGame* SaveGame = UGGMainSaveGame::GetSettings();

	FVector NewValue = CurrentValue.Get<FVector>();

	if (SaveGame->bInvertVerticalAim)
	{
		NewValue.Y *= -1.0f;
	}

	return NewValue;
}