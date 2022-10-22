// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AGGideon.h"

#include "BattleSystemComponent.h"
#include "Animation/AGGideonAnimInstance.h"
#include "GameFrameWork/AGPlayerController.h"
#include "Actor/GideonPrimaryAttack.h"
#include "Actor/GideonQSkill.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/KismetMathLibrary.h"

AAGGideon::AAGGideon()
{
	
	ConstructorHelpers::FObjectFinder<USkeletalMesh> sm(TEXT("SkeletalMesh'/Game/ParagonGideon/Characters/Heroes/Gideon/Meshes/Gideon.Gideon'"));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	
	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/ParagonGideon/FX/Particles/Gideon/Abilities/Primary/FX/P_Primary_Cast.P_Primary_Cast'"));

	if (PS.Succeeded())
	{
		PrimaryAttackCast = PS.Object;
	}

	ConstructorHelpers::FObjectFinder<UParticleSystem> SQC(TEXT("ParticleSystem'/Game/ParagonGideon/FX/Particles/Gideon/Abilities/ProjectileMeteor/FX/P_Gideon_RMB_CastPortal.P_Gideon_RMB_CastPortal'"));

	if (SQC.Succeeded())
	{
		SkillQCast = SQC.Object;
	}

	ConstructorHelpers::FObjectFinder<UParticleSystem> SQCP(TEXT("ParticleSystem'/Game/ParagonGideon/FX/Particles/Gideon/Abilities/ProjectileMeteor/FX/P_Gideon_RMB_Portal.P_Gideon_RMB_Portal'"));

	if (SQCP.Succeeded())
	{
		SkillQCastPortal = SQCP.Object;
	}

	
	BattleSystem->SetMaxHp(80.f);
	BattleSystem->SetHp(BattleSystem->GetMaxHp());
}

void AAGGideon::BeginPlay()
{
	Super::BeginPlay();

	GideonAnimInstance->PrimaryAttack.AddDynamic(this, &AAGGideon::SpawnPrimaryAttack);

	GideonAnimInstance->SkillQ.AddDynamic(this, &AAGGideon::SpawnSkillQ);

	GideonAnimInstance->SaveAttack.AddDynamic(this, &AAGGideon::SaveAttack);

	GideonAnimInstance->ResetAttack.AddDynamic(this, &AAGGideon::ResetAttack);

}

void AAGGideon::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GideonAnimInstance = Cast<UAGGideonAnimInstance>(GetMesh()->GetAnimInstance());
}


void AAGGideon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(IsValid(MyPlayerController))
	{
		if (SetLookRotate)
		{
			SetActorRotation(MyPlayerController->LookRotation);
		}
	}
	
	
}



void AAGGideon::PrimaryAttack()
{
	if (!bIsAttack && !CastingQSkill && !CastingESkill && !CastingRSkill)
	{
		CurrentPrimaryAttackCombo = PrimaryAttackCombo::PrimaryAttackA;
		bIsAttack = true;

		if(!GideonAnimInstance->Play_Montage(GideonAnimInstance->Attack1Montage))
		{
			ResetAttack();
		}
	}
	else
	{
		bSaveAttack = true;
	}
}

void AAGGideon::SaveAttack()
{
	if (bSaveAttack)
	{
		bSaveAttack = false;
		switch (CurrentPrimaryAttackCombo)
		{
		case PrimaryAttackCombo::PrimaryAttackA:
			if (!GideonAnimInstance->Play_Montage(GideonAnimInstance->Attack2Montage))
			{
				ResetAttack();
			}
			CurrentPrimaryAttackCombo = PrimaryAttackCombo::PrimaryAttackB;
			break;
		case PrimaryAttackCombo::PrimaryAttackB:
			if (!GideonAnimInstance->Play_Montage(GideonAnimInstance->Attack3Montage))
			{
				ResetAttack();
			}
			CurrentPrimaryAttackCombo = PrimaryAttackCombo::PrimaryAttackC;
			break;
		case PrimaryAttackCombo::PrimaryAttackC:
			if (!GideonAnimInstance->Play_Montage(GideonAnimInstance->Attack1Montage))
			{
				ResetAttack();
			}
			CurrentPrimaryAttackCombo = PrimaryAttackCombo::PrimaryAttackA;
			break;
		}
	}
}

void AAGGideon::ResetAttack()
{
	CurrentPrimaryAttackCombo = PrimaryAttackCombo::PrimaryAttackNone;
	bIsAttack = false;
	bSaveAttack = false;
}
void AAGGideon::SpawnPrimaryAttack()
{
	FVector PrimarySpawnLocation;

	if (CurrentPrimaryAttackCombo == PrimaryAttackCombo::PrimaryAttackA || CurrentPrimaryAttackCombo == PrimaryAttackCombo::PrimaryAttackC)
	{
		PrimarySpawnLocation = GetMesh()->GetSocketLocation(TEXT("Muzzle_01"));
		UGameplayStatics::SpawnEmitterAttached(PrimaryAttackCast, GetMesh(), TEXT("Muzzle_01"), FVector::ZeroVector, FRotator::ZeroRotator, FVector(1.2f));
	}
	else
	{
		PrimarySpawnLocation = GetMesh()->GetSocketLocation(TEXT("Muzzle_02"));
		UGameplayStatics::SpawnEmitterAttached(PrimaryAttackCast, GetMesh(), TEXT("Muzzle_02"), FVector::ZeroVector, FRotator::ZeroRotator, FVector(1.2f));
	}

	FRotator PrimarySpawnRotation = MyPlayerController->LookRotation;

	FActorSpawnParameters a;
	a.Owner = MyPlayerController;
	GetWorld()->SpawnActor<AGideonPrimaryAttack>(PrimarySpawnLocation, PrimarySpawnRotation,a);

}

void AAGGideon::SpawnSkillQ()
{

	const FRotator SkillQSpawnRotation = MyPlayerController->LookRotation;

	FVector SkillQSpawnLocation = GetMesh()->GetSocketLocation(TEXT("Muzzle_02"));

	if (UKismetMathLibrary::GetForwardVector(SkillQSpawnRotation).X > 0)
	{
		SkillQSpawnLocation.X += -250.f;
	}

	SkillQSpawnLocation.Y += 0.f;
	SkillQSpawnLocation.Z += 250.f;

	GetWorld()->SpawnActor<AGideonQSkill>(SkillQSpawnLocation, SkillQSpawnRotation);

	FTransform SpawnSkillQPortalTransform;
	SpawnSkillQPortalTransform.SetLocation(SkillQSpawnLocation);
	SpawnSkillQPortalTransform.SetRotation(static_cast<FQuat>(SkillQSpawnRotation));
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),SkillQCastPortal, SpawnSkillQPortalTransform);

	ResetAttack();
	CastingQSkill = false;
}

void AAGGideon::SkillQ()
{
	if (GideonAnimInstance->Play_Montage(GideonAnimInstance->Skill1Montage))
	{
		UGameplayStatics::SpawnEmitterAttached(SkillQCast, GetMesh(), TEXT("Muzzle_02"), FVector::ZeroVector, FRotator::ZeroRotator, FVector(1.5f));
	}
	CastingQSkill = true;
}

void AAGGideon::SkillE()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill2"));
}

void AAGGideon::SkillR()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill3"));
}

