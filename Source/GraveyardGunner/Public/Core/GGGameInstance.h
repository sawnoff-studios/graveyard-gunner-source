// Copyright (c) Sawnoff Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GRAVEYARDGUNNER_API UGGGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category = "Development")
	static bool IsRunningInEditor();
};
