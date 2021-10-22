// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyObject.h"

// Sets default values
AFlyObject::AFlyObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFlyObject::BeginPlay()
{
	Super::BeginPlay();
	
	// init z
	fOrgZ = GetActorLocation().Z;

	if(GetLocalRole() == ROLE_Authority)
	{
		fMaxDist += FMath::FRandRange(-fMaxDistOffset, fMaxDistOffset);

		fMoveSpeed += FMath::FRandRange(-fSpeedOffset, fSpeedOffset);
	}
}

// Called every frame
void AFlyObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(GetLocalRole() == ROLE_Authority)
	{
		auto deltaDist = DeltaTime * fMoveSpeed;
		SetActorLocation(GetActorLocation() + FVector(0.f, 0.f, Dir * deltaDist));

		if(GetActorLocation().Z < fOrgZ - fMaxDist)
		{
			Dir = 1;
		}
		else if(GetActorLocation().Z > fOrgZ + fMaxDist)
		{
			Dir = -1;
		}
	}

}

