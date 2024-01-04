// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "MachinePawn.generated.h"

/**
 * 
 */
UCLASS()
class PAWNSEXPLORATION_API AMachinePawn : public ABasePawn
{
	GENERATED_BODY()

public:
	AMachinePawn();

protected:
	virtual void BeginPlay() override;
	void RotateTurret(FVector LookAtTarget);
	void Fire();

private:
	// Static mesh of the part of the pawn that shoots
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	// Transform origin from which the projectiles will spawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
};
