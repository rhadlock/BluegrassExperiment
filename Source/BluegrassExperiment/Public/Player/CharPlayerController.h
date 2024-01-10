// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharPlayerController.generated.h"


class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class BLUEGRASSEXPERIMENT_API ACharPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
		//make constrctor
		ACharPlayerController();

	protected:
		virtual void BeginPlay() override;
		virtual void SetupInputComponent() override;

	private:
		UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputMappingContext> CharInputContext;

		UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> MoveAction;

		void Move(const FInputActionValue& InputActionValue);
};
