// Fill out your copyright notice in the Description page of Project Settings.


#include "AGSavarog.h"

AAGSavarog::AAGSavarog()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> sm(TEXT("SkeletalMesh'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Meshes/Sevarog.Sevarog'"));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

}

void AAGSavarog::PimaryAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGSavarog Attack"));
}

void AAGSavarog::Skill1()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGSavarog Skill1"));
}

void AAGSavarog::Skill2()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGSavarog Skill2"));
}

void AAGSavarog::Skill3()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGSavarog Skill3"));
}
