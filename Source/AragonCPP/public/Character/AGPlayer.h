// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character\AGCharacterParent.h"
#include "AGPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARAGONCPP_API AAGPlayer : public AAGCharacterParent
{
	GENERATED_BODY()
public:
	AAGPlayer();

	virtual void BeginPlay() override;
protected:

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class AAGPlayerController* MyPlayerController;

	/*Q 스킬을 사용중인가?*/
	UPROPERTY(VisibleAnywhere)
	bool CastingQSkill;

	/*E 스킬을 사용중인가?*/
	UPROPERTY(VisibleAnywhere)
	bool CastingESkill;

	/*R 스킬을 사용중인가?*/
	UPROPERTY(VisibleAnywhere)
	bool CastingRSkill;

	/*마우스를 봐야하는가?*/
	UPROPERTY(VisibleAnywhere)
	bool SetLookRotate;

public:
	
	void MoveLeftRight(float _Value);
	
	void MoveUpDown(float _Value);
	
	virtual void PimaryAttack();
	
	virtual void SkillQ();
	
	virtual void SkillE();

	virtual void SkillR();

};
