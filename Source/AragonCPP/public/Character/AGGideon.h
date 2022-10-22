// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Character/AGPlayer.h"
#include "AGGideon.generated.h"

enum class PrimaryAttackCombo
{
	PrimaryAttackNone,
	PrimaryAttackA,
	PrimaryAttackB,
	PrimaryAttackC
};
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
	void SpawnPrimaryAttack();

	UFUNCTION()
	void SpawnSkillQ();

	UFUNCTION()
	void SaveAttack();

	UFUNCTION()
	void ResetAttack();


protected:

	// Called when the game starts or when spawned

	virtual void BeginPlay() override;
	
	virtual void PostInitializeComponents() override;

	UPROPERTY()
	class UAGGideonAnimInstance* GideonAnimInstance;

	UPROPERTY()
	class UParticleSystem* PrimaryAttackCast;

	UPROPERTY()
	class UParticleSystem* SkillQCast;

	UPROPERTY()
	class UParticleSystem* SkillQCastPortal;


	PrimaryAttackCombo CurrentPrimaryAttackCombo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bSaveAttack;

	
protected:

	UFUNCTION()
	virtual void PrimaryAttack() override;

	UFUNCTION()
	virtual void SkillQ() override;

	UFUNCTION()
	virtual void SkillE() override;

	UFUNCTION()
	virtual void SkillR() override;

};
