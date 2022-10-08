// Fill out your copyright notice in the Description page of Project Settings.


#include "AGCharacterParent.h"


// Sets default values
AAGCharacterParent::AAGCharacterParent()
	:Hp(MaxHp)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AAGCharacterParent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAGCharacterParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAGCharacterParent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AAGCharacterParent::UpdateHp(int32 _damage)
{
	Hp -= _damage;
}



