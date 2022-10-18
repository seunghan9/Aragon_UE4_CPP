// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation\AGPlayerAnimInstance.h"
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

	/*기본공격 델리게이트 생성*/
	FDelegateName PrimaryAttack;

	FDelegateName SaveAttack;

	FDelegateName ResetAttack;

	/*스킬 Q 델리게이트 생성*/
	FDelegateName SkillQ;

private:

	/*Attack Notify 실행*/
	UFUNCTION()
	void AnimNotify_GideonAttack();

	/*Skill Q Notify 실행*/
	UFUNCTION()
	void AnimNotify_GideonSkillQ();

	/*콤보 공격*/
	UFUNCTION()
	void AnimNotify_SaveAttack();

	/*콤보 리셋*/
	UFUNCTION()
	void AnimNotify_ResetCombo();

};
