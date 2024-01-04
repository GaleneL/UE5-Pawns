// Fill out your copyright notice in the Description page of Project Settings.


#include "MachineRobot.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

AMachineRobot::AMachineRobot()
{
	// Initialize and attach components
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
}

void AMachineRobot::BeginPlay()
{
	Super::BeginPlay();

	// Add maping context to enhanced input system
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(TankMappingContext, 0);
		}

	}

	// GetPlayerController
	PlayerControllerRef = Cast<APlayerController>(GetController());
}

// Called every frame
void AMachineRobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Draw a debug sphere in the world where the mouse cursor is pointing
	if (PlayerControllerRef)
	{
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
		HitResult.GetActor();

		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10, 10, FColor::Red, false, -1.f);
		RotateTurret(HitResult.ImpactPoint);
	}
}

void AMachineRobot::Move(const FInputActionValue& Value)
{
	/*
	This method helps to move forward and backward the actor by the input action IA_Move
	*/

	const float CurrentValue = Value.Get<float>();
	if (CurrentValue)
	{
		FVector DeltaLocation(0.f);
		DeltaLocation.X = CurrentValue * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;

		AddActorLocalOffset(DeltaLocation, true);
	}
}

void AMachineRobot::Turn(const FInputActionValue& Value)
{
	/*
	This method adds rotation to the actor by the input action IA_Turn
	*/

	const float CurrentValue = Value.Get<float>();
	if (CurrentValue)
	{
		FRotator DeltaRotation = FRotator::ZeroRotator;
		DeltaRotation.Yaw = CurrentValue * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;

		AddActorLocalRotation(DeltaRotation, true);
	}
}

// Called to bind functionality to input
void AMachineRobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMachineRobot::Move);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AMachineRobot::Turn);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AMachineRobot::Fire);
	}
}