// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGCharacterParent.h"
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

public:
	
	void MoveLeftRight(float _Value);
	
	void MoveUpDown(float _Value);
	
	virtual void PimaryAttack();
	
	virtual void Skill1();
	
	virtual void Skill2();

	virtual void Skill3();

};
