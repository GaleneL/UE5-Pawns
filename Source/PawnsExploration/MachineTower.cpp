// Fill out your copyright notice in the Description page of Project Settings.


#include "MachineTower.h"
#include "MachineRobot.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void AMachineTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find the distance to the Tank
	if (InFireRange())
	{
		// If it is in range, rotate turret toward tank
		RotateTurret(MachineRobot->GetActorLocation());
	}

}

void AMachineTower::BeginPlay()
{
	Super::BeginPlay();

	MachineRobot = Cast<AMachineRobot>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AMachineTower::CheckFireCondition, FireRate, true);
}

void AMachineTower::CheckFireCondition()
{
	// Find the distance to the Tank
	if (InFireRange())
	{
		Fire();
	}
}

bool AMachineTower::InFireRange()
{
	// Find the distance to the Tank
	if (MachineRobot)
	{
		float Distance = FVector::Dist(GetActorLocation(), MachineRobot->GetActorLocation());
		// Check to see if the tank is in range
		if (Distance < FireRange)
		{
			return true;
		}
	}

	return false;
}

