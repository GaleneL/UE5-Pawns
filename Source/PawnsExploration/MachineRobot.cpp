// Fill out your copyright notice in the Description page of Project Settings.


#include "MachineRobot.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

void AMachineRobot::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AMachineRobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMachineRobot::Move(const FInputActionValue& Value)
{

}

void AMachineRobot::Turn(const FInputActionValue& Value)
{

}