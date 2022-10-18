// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character\AGPlayer.h"
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
	virtual void SkillQ() override;
	virtual void SkillE() override;
	virtual void SkillR() override;
};
