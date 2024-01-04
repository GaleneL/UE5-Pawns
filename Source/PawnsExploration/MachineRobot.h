// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MachinePawn.h"
#include "InputActionValue.h"
#include "MachineRobot.generated.h"

/**
 * 
 */
UCLASS()
class PAWNSEXPLORATION_API AMachineRobot : public AMachinePawn
{
	GENERATED_BODY()
	
public:

	AMachineRobot();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Enhance input actions and context objects
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputMappingContext* TankMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* TurnAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* FireAction;

	void Move(const FInputActionValue& Value);

	void Turn(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	// Variables to manipulate movement and rotation speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	int32 Speed = 400;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	int32 TurnRate = 100;

	APlayerController* PlayerControllerRef;
};
