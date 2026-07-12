// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Core/Weapons/Ranged/GGWeaponBase.h"

// Sets default values
AGGWeaponBase::AGGWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGGWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGGWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AGGWeaponBase::LineTraceByChannelWithPhysicalMaterial(
	FHitResult& OutHit,
	const FVector& Start,
	const FVector& End,
	ECollisionChannel TraceChannel)
{
	FCollisionQueryParams QueryParams(FName(TEXT("WeaponTrace")), true, this);
	
	QueryParams.bTraceComplex = true;
	QueryParams.bReturnPhysicalMaterial = true;
	QueryParams.AddIgnoredActor(this);
	
	return GetWorld()->LineTraceSingleByChannel(
		OutHit,
		Start,
		End,
		TraceChannel,
		QueryParams
	);
}
