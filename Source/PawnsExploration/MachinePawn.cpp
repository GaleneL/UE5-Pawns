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
	// Get the vector and rotator between current turret mesh pawn to the target position
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	// Set the rotation of the mesh
	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(),
			LookAtRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this),
			5.f
		)
	);
}

void AMachinePawn::Fire()
{
	DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(), 10, 10, FColor::Red, false, 3.f);
}