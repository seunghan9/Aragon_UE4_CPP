// Fill out your copyright notice in the Description page of Project Settings.


#include "AGGideon.h"
AAGGideon::AAGGideon()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> sm(TEXT("SkeletalMesh'/Game/ParagonGideon/Characters/Heroes/Gideon/Meshes/Gideon.Gideon'"));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

}

void AAGGideon::PimaryAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Attack"));
}

void AAGGideon::Skill1()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill1"));
}

void AAGGideon::Skill2()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill2"));
}

void AAGGideon::Skill3()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill3"));
}

