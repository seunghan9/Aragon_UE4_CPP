// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AGGideon.h"
#include "Animation/AGGideonAnimInstance.h"
#include "GameFrameWork/AGPlayerController.h"
#include "Actor/GideonPrimaryAttack.h"
#include "Actor/GideonQSkill.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/KismetMathLibrary.h"

AAGGideon::AAGGideon()
{
	/*Gideon 메시 불러오기*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh> sm(TEXT("SkeletalMesh'/Game/ParagonGideon/Characters/Heroes/Gideon/Meshes/Gideon.Gideon'"));

	/*Gideon 메시 위치 설정*/
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	/*Gideon 메시 넣기*/
	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/ParagonGideon/FX/Particles/Gideon/Abilities/Primary/FX/P_Primary_Cast.P_Primary_Cast'"));

	if (PS.Succeeded())
	{
		PimaryAttackCast = PS.Object;
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

}

void AAGGideon::BeginPlay()
{
	Super::BeginPlay();

	GideonAnimInstance->PrimaryAttack.AddDynamic(this, &AAGGideon::SpawnPimaryAttack);

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

	if (SetLookRotate)
	{
		SetActorRotation(MyPlayerController->LookRotation);
	}
	
}

void AAGGideon::PimaryAttack()
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
	UE_LOG(LogTemp, Warning, TEXT("ResetAttack"));

}
void AAGGideon::SpawnPimaryAttack()
{
	FVector PimarySpawnLocation;

	if (CurrentPrimaryAttackCombo == PrimaryAttackCombo::PrimaryAttackA || CurrentPrimaryAttackCombo == PrimaryAttackCombo::PrimaryAttackC)
	{
		PimarySpawnLocation = GetMesh()->GetSocketLocation(TEXT("Muzzle_01"));
		UGameplayStatics::SpawnEmitterAttached(PimaryAttackCast, GetMesh(), TEXT("Muzzle_01"), FVector::ZeroVector, FRotator::ZeroRotator, FVector(1.2f));
	}
	else
	{
		PimarySpawnLocation = GetMesh()->GetSocketLocation(TEXT("Muzzle_02"));
		UGameplayStatics::SpawnEmitterAttached(PimaryAttackCast, GetMesh(), TEXT("Muzzle_02"), FVector::ZeroVector, FRotator::ZeroRotator, FVector(1.2f));
	}

	FRotator PimarySpawnRotation = MyPlayerController->LookRotation;

	GetWorld()->SpawnActor<AGideonPrimaryAttack>(PimarySpawnLocation, PimarySpawnRotation);

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

	FTransform SpawnSkillQPortalTranceform;
	SpawnSkillQPortalTranceform.SetLocation(SkillQSpawnLocation);
	SpawnSkillQPortalTranceform.SetRotation((FQuat)SkillQSpawnRotation);
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),SkillQCastPortal, SpawnSkillQPortalTranceform);

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

