// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Character/AGPlayer.h"
#include "AGGideon.generated.h"

/**
 * 
 */
UCLASS()
class ARAGONCPP_API AAGGideon : public AAGPlayer
{
	GENERATED_BODY()
public:
	AAGGideon();
	
	UFUNCTION()
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnPimaryAttack();

	UFUNCTION()
	void SpawnSkillQ();
	


protected:

	// Called when the game starts or when spawned

	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	class UAGGideonAnimInstance* GideonAnimInstance;

	class UParticleSystem* PimaryAttackCast;

	class UParticleSystem* SkillQCast;

	class UParticleSystem* SkillQCastPortal;
protected:


	UFUNCTION()
	virtual void PimaryAttack() override;

	UFUNCTION()
	virtual void Skill1() override;

	UFUNCTION()
	virtual void Skill2() override;

	UFUNCTION()
	virtual void Skill3() override;

};