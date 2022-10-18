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

	/*Q ��ų�� ������ΰ�?*/
	UPROPERTY(VisibleAnywhere)
	bool CastingQSkill;

	/*E ��ų�� ������ΰ�?*/
	UPROPERTY(VisibleAnywhere)
	bool CastingESkill;

	/*R ��ų�� ������ΰ�?*/
	UPROPERTY(VisibleAnywhere)
	bool CastingRSkill;

	/*���콺�� �����ϴ°�?*/
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
