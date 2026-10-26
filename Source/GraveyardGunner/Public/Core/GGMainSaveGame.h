// Copyright (c) Sawnoff Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GGMainSaveGame.generated.h"

UCLASS()
class GRAVEYARDGUNNER_API UGGMainSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Save Game")
	static UGGMainSaveGame* GetSettings();
	
	UFUNCTION(BlueprintCallable, Category = "Save Game")
	static void SaveSettings();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Controls)
	bool bInvertVerticalAim = false;

private:
	static FString MainSaveSlotName;
	static UGGMainSaveGame* SaveGame;
};
