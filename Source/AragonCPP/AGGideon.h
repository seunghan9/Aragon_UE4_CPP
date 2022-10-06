// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGPlayer.h"
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

protected:
	virtual void PimaryAttack() override;
	virtual void Skill1() override;
	virtual void Skill2() override;
	virtual void Skill3() override;
};
