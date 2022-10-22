// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Character.h"
#include "AGCharacterParent.generated.h"


UCLASS()
class ARAGONCPP_API AAGCharacterParent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAGCharacterParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
	virtual void OnDead();
	
	UPROPERTY(VisibleAnywhere)
	class UBattleSystemComponent* BattleSystem;
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Attack)
	bool bIsAttack;

protected:

};
