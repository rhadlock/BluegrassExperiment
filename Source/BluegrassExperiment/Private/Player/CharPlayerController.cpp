// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CharPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ACharPlayerController::ACharPlayerController()
{
	bReplicates = true;
}

void ACharPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(CharInputContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check (Subsystem);
	Subsystem->AddMappingContext(CharInputContext, 0);

}

void ACharPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACharPlayerController::Move);

}
/// <summary>
/// Handle movement input for the controlled pawn.
/// Extract 2D movement input and Yaw rotation component for movement calculations.
/// Apply movement input along the forward and right axes of the controlled pawn.
/// Assumes the controlled pawn is of type APawn.
/// </summary>
/// <param name="InputValue"></param>
void ACharPlayerController::Move(const FInputActionValue& InputValue)
{
	const FVector2D MoveVector = InputValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MoveVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, MoveVector.X);
	}
}
