// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BattleSystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARAGONCPP_API UBattleSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBattleSystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	float GetHp();

	UFUNCTION()
	float GetMaxHp();

	UFUNCTION()
	float GetHpRatio();

	UFUNCTION()
	void SetHp(const float& FCurrentHp);

	UFUNCTION()
	void SetMaxHp(const float& FMaxHp);

	UFUNCTION()
	float GetDamage();

	UFUNCTION()
	void SetDamage(const float& FDamage);
private:
	UPROPERTY(VisibleAnywhere, Category= Battle , meta = (AllowPrivateAccess = true))
	float Hp;

	UPROPERTY(VisibleAnywhere, Category= Battle , meta = (AllowPrivateAccess = true))
	float MaxHp;

	UPROPERTY(VisibleAnywhere, Category= Battle , meta = (AllowPrivateAccess = true))
	float Damage;
	
};
