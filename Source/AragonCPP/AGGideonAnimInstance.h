// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGPlayerAnimInstance.h"
#include "AGGideonAnimInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateName);

/**
 * 
 */
UCLASS()
class ARAGONCPP_API UAGGideonAnimInstance : public UAGPlayerAnimInstance
{
	GENERATED_BODY()

public:
	UAGGideonAnimInstance();
	FDelegateName AttackA;
private:

	/*Attack A Notify ½ÇÇà*/
	UFUNCTION()
	void AnimNotify_GideonAttackA();

};
