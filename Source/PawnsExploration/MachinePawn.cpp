// Fill out your copyright notice in the Description page of Project Settings.


#include "MachinePawn.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

AMachinePawn::AMachinePawn()
{

	// Initialize components
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("Turret Mesh");
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>("Projectile Spawn Point");
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void AMachinePawn::BeginPlay()
{
	Super::BeginPlay();
}

void AMachinePawn::RotateTurret(FVector LookAtTarget)
{
	/*
	Rotates the TurretMesh to the direction of LookAtTarget
	LookAtTarget: Position of the target where the actor should be rotated to.
	*/

	// Get the vector and rotator between current turret mesh pawn to the target position
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	// Set the rotation of the mesh with interpolation to avoid too fast rotations
	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(),
			LookAtRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this),
			RotationRate
		)
	);
}

void AMachinePawn::Fire()
{
	/*
	Draw debug sphere from the weapong mesh when input action IA_Fire is started
	*/

	DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(), 20, 10, FColor::Red, false, 3.f);
}