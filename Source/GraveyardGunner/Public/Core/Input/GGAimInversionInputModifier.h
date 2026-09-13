// Copyright (c) Sawnoff Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputModifiers.h"
#include "GGAimInversionInputModifier.generated.h"

UCLASS(NotBlueprintable, MinimalAPI, meta = (DisplayName = "Aim Inversion Setting"))
class UGGAimInversionInputModifier : public UInputModifier
{
	GENERATED_BODY()
	
protected:
	virtual FInputActionValue ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime) override;
};
