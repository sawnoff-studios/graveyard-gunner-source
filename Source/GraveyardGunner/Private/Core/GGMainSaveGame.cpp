// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Core/GGMainSaveGame.h"
#include "Kismet/GameplayStatics.h"

FString UGGMainSaveGame::MainSaveSlotName = TEXT("MainSave");
UGGMainSaveGame* UGGMainSaveGame::SaveGame = nullptr;

UGGMainSaveGame* UGGMainSaveGame::GetSettings()
{
	SaveGame = Cast<UGGMainSaveGame>(UGameplayStatics::LoadGameFromSlot(MainSaveSlotName, 0));
	
	if (SaveGame == nullptr)
	{
		SaveGame = Cast<UGGMainSaveGame>(UGameplayStatics::CreateSaveGameObject(TSubclassOf<UGGMainSaveGame>()));
		
		SaveSettings();
	}
	
	return SaveGame;
}

void UGGMainSaveGame::SaveSettings()
{
	if (SaveGame == nullptr)
	{
		SaveGame = Cast<UGGMainSaveGame>(UGameplayStatics::CreateSaveGameObject(TSubclassOf<UGGMainSaveGame>()));
	}
	
	UGameplayStatics::SaveGameToSlot(SaveGame, MainSaveSlotName, 0);
}