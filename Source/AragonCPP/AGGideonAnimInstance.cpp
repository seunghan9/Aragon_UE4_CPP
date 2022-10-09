// Fill out your copyright notice in the Description page of Project Settings.


#include "AGGideonAnimInstance.h"
#include "AGGideon.h"
UAGGideonAnimInstance::UAGGideonAnimInstance()
{
	/*Attack A Montage 历厘*/
	ConstructorHelpers::FObjectFinder<UAnimMontage>
		ATA(TEXT("AnimMontage'/Game/ParagonGideon/Characters/Heroes/Gideon/Animations/Primary_Attack_A_Medium_Montage.Primary_Attack_A_Medium_Montage'"));

	if (ATA.Succeeded())
	{
		Attack1Montage = ATA.Object;
	}

	/*Attack B Montage 历厘*/
	ConstructorHelpers::FObjectFinder<UAnimMontage>
		ATB(TEXT("AnimMontage'/Game/ParagonGideon/Characters/Heroes/Gideon/Animations/Primary_Attack_B_Medium_Montage.Primary_Attack_B_Medium_Montage'"));

	if (ATB.Succeeded())
	{
		Attack2Montage = ATB.Object;
	}

	/*Attack C Montage 历厘*/
	ConstructorHelpers::FObjectFinder<UAnimMontage>
		ATC(TEXT("AnimMontage'/Game/ParagonGideon/Characters/Heroes/Gideon/Animations/Primary_Attack_C_Medium_Montage.Primary_Attack_C_Medium_Montage'"));

	if (ATC.Succeeded())
	{
		Attack3Montage = ATC.Object;
	}

	
}

/*Attack A Notify 角青*/
void UAGGideonAnimInstance::AnimNotify_GideonAttackA()
{
	AttackA.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Notify 己傍"));
}
