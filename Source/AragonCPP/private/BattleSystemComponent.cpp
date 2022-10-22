// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleSystemComponent.h"

// Sets default values for this component's properties
UBattleSystemComponent::UBattleSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	bWantsInitializeComponent = true;
	// ...
}


// Called when the game starts
void UBattleSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

float UBattleSystemComponent::GetHp()
{
	return Hp;
}

float UBattleSystemComponent::GetMaxHp()
{
	return MaxHp;
}

float UBattleSystemComponent::GetHpRatio()
{
	return Hp/MaxHp;
}

void UBattleSystemComponent::SetHp(const float& FCurrentHp)
{
	Hp = FCurrentHp;
	if( Hp < 0)
	{
		Hp = 0;
	}
	UE_LOG(LogTemp, Log, TEXT("HP : %f"), Hp);
}

void UBattleSystemComponent::SetMaxHp(const float& FMaxHp)
{
	MaxHp = FMaxHp;
}

float UBattleSystemComponent::GetDamage()
{
	return Damage;
}

void UBattleSystemComponent::SetDamage(const float& FDamage)
{
	Damage = FDamage;
}

