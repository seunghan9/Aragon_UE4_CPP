// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGPlayer.h"
#include "AGSavarog.generated.h"

/**
 * 
 */
UCLASS()
class ARAGONCPP_API AAGSavarog : public AAGPlayer
{
	GENERATED_BODY()
public:
	AAGSavarog();
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION()
	virtual void PimaryAttack() override;
	virtual void Skill1() override;
	virtual void Skill2() override;
	virtual void Skill3() override;
};
