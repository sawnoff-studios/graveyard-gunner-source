// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Core/Placeables/Pickups/Weapons/GGWeaponPickupBase.h"

// Sets default values
AGGWeaponPickupBase::AGGWeaponPickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGGWeaponPickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGWeaponPickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

