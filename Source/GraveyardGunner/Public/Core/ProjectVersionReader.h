// Copyright (c) Sawnoff Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProjectVersionReader.generated.h"

/**
 * 
 */
UCLASS()
class GRAVEYARDGUNNER_API UProjectVersionReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure)
	static FString GetProjectVersion();
};
