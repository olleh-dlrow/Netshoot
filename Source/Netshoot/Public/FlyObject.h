// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyObject.generated.h"

UCLASS()
class NETSHOOT_API AFlyObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlyObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	// UMovementComponent* MoveComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlyObject")
	float fMoveSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlyObject")
	float fSpeedOffset = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlyObject")
	float fMaxDist = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlyObject")
	float fMaxDistOffset = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FlyObject")
	float fOrgZ;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FlyObject")
	int Dir = -1;
};
