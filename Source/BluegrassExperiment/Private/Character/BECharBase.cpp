// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BECharBase.h"

// Sets default values
ABECharBase::ABECharBase()
{
	PrimaryActorTick.bCanEverTick = false;

	r_Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("r_Weapon");
	l_Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("l_Weapon");
	r_Weapon->SetupAttachment(GetMesh(), "r_WeaponHandSocket");
	l_Weapon->SetupAttachment(GetMesh(), "l_WeaponHandSocket");
	r_Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	l_Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ABECharBase::BeginPlay()
{
	Super::BeginPlay();
	
}

