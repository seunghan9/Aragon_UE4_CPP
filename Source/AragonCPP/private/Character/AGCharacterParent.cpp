// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleSystemComponent.h"
#include "Character/AGCharacterParent.h"


// Sets default values
AAGCharacterParent::AAGCharacterParent()
{
	bIsAttack = false;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BattleSystem = CreateDefaultSubobject<UBattleSystemComponent>(TEXT("BATTLESYSTEM"));
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

float AAGCharacterParent::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	BattleSystem->SetHp(BattleSystem->GetHp() - DamageAmount);
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void AAGCharacterParent::OnDead()
{
}





