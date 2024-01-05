// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MachinePawn.h"
#include "MachineTower.generated.h"

/**
 * 
 */
UCLASS()
class PAWNSEXPLORATION_API AMachineTower : public AMachinePawn
{
	GENERATED_BODY()
	
public:

	virtual void Tick(float DeltaTime) override;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	class AMachineRobot* MachineRobot;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	float FireRange = 200;

	FTimerHandle FireRateTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Fire")
	float FireRate = 2.f;

	void CheckFireCondition();

	bool InFireRange();
};
