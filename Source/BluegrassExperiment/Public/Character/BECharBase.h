// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BECharBase.generated.h"

UCLASS(ABSTRACT)
class BLUEGRASSEXPERIMENT_API ABECharBase : public ACharacter
{
	GENERATED_BODY()

public:
	ABECharBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "r_Weapon")
	TObjectPtr<USkeletalMeshComponent> r_Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "l_Weapon")
	TObjectPtr<USkeletalMeshComponent> l_Weapon;
};
