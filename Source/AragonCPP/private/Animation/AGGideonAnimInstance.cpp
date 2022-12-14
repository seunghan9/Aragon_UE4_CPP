// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AGGideonAnimInstance.h"
#include "Character/AGGideon.h"
UAGGideonAnimInstance::UAGGideonAnimInstance()
{
	/*Attack A Montage 저장*/
	ConstructorHelpers::FObjectFinder<UAnimMontage>
		ATA(TEXT("AnimMontage'/Game/ParagonGideon/Characters/Heroes/Gideon/Animations/Primary_Attack_A_Medium_Montage.Primary_Attack_A_Medium_Montage'"));

	if (ATA.Succeeded())
	{
		Attack1Montage = ATA.Object;
	}

	/*Attack B Montage 저장*/
	ConstructorHelpers::FObjectFinder<UAnimMontage>
		ATB(TEXT("AnimMontage'/Game/ParagonGideon/Characters/Heroes/Gideon/Animations/Primary_Attack_B_Medium_Montage.Primary_Attack_B_Medium_Montage'"));

	if (ATB.Succeeded())
	{
		Attack2Montage = ATB.Object;
	}

	/*Attack C Montage 저장*/
	ConstructorHelpers::FObjectFinder<UAnimMontage>
		ATC(TEXT("AnimMontage'/Game/ParagonGideon/Characters/Heroes/Gideon/Animations/Primary_Attack_C_Medium_Montage.Primary_Attack_C_Medium_Montage'"));

	if (ATC.Succeeded())
	{
		Attack3Montage = ATC.Object;
	}

	/*SkillQ Montage 저장*/
	ConstructorHelpers::FObjectFinder<UAnimMontage>
		QS(TEXT("AnimMontage'/Game/ParagonGideon/Characters/Heroes/Gideon/Animations/MT_RMB_Intro.MT_RMB_Intro'"));

	if (QS.Succeeded())
	{
		Skill1Montage = QS.Object;
	}

}

void UAGGideonAnimInstance::AnimNotify_GideonAttack()
{
	PrimaryAttack.Broadcast();
}

void UAGGideonAnimInstance::AnimNotify_GideonSkillQ()
{
	SkillQ.Broadcast();
}

void UAGGideonAnimInstance::AnimNotify_SaveAttack()
{
	SaveAttack.Broadcast();
}

void UAGGideonAnimInstance::AnimNotify_ResetCombo()
{
	ResetAttack.Broadcast();
}
