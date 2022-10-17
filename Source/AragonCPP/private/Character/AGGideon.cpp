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

	GideonAnimInstance->AttackA.AddDynamic(this, &AAGGideon::SpawnPimaryAttack);

	GideonAnimInstance->SkillQ.AddDynamic(this, &AAGGideon::SpawnSkillQ);

}

void AAGGideon::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GideonAnimInstance = Cast<UAGGideonAnimInstance>(GetMesh()->GetAnimInstance());
}


void AAGGideon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	SetActorRotation(MyPlayerController->LookRotation);
}

void AAGGideon::PimaryAttack()
{
	GideonAnimInstance->Play_Montage(GideonAnimInstance->Attack1Montage);
}

void AAGGideon::SpawnPimaryAttack()
{
	
	FVector PimarySpawnLocation = GetMesh()->GetSocketLocation(TEXT("Muzzle_01"));

	const FRotator PimarySpawnRotation = MyPlayerController->LookRotation;

	GetWorld()->SpawnActor<AGideonPrimaryAttack>(PimarySpawnLocation, PimarySpawnRotation);

	UGameplayStatics::SpawnEmitterAttached(PimaryAttackCast, GetMesh(), TEXT("Muzzle_01"),FVector::ZeroVector,FRotator::ZeroRotator,FVector(1.5f));
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

}

void AAGGideon::Skill1()
{
	if (GideonAnimInstance->Play_Montage(GideonAnimInstance->Skill1Montage))
	{
		UGameplayStatics::SpawnEmitterAttached(SkillQCast, GetMesh(), TEXT("Muzzle_02"), FVector::ZeroVector, FRotator::ZeroRotator, FVector(1.5f));
	}
	
}

void AAGGideon::Skill2()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill2"));
}

void AAGGideon::Skill3()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill3"));
}

