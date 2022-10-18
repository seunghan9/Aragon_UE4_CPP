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

	/*�⺻���� ��������Ʈ ����*/
	FDelegateName PrimaryAttack;

	FDelegateName SaveAttack;

	FDelegateName ResetAttack;

	/*��ų Q ��������Ʈ ����*/
	FDelegateName SkillQ;

private:

	/*Attack Notify ����*/
	UFUNCTION()
	void AnimNotify_GideonAttack();

	/*Skill Q Notify ����*/
	UFUNCTION()
	void AnimNotify_GideonSkillQ();

	/*�޺� ����*/
	UFUNCTION()
	void AnimNotify_SaveAttack();

	/*�޺� ����*/
	UFUNCTION()
	void AnimNotify_ResetCombo();

};
