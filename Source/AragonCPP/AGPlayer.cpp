// Fill out your copyright notice in the Description page of Project Settings.


#include "AGPlayer.h"
#include "GameFramework\SpringArmComponent.h"
#include "Camera\CameraComponent.h"
#include "AGPlayerController.h"
#include "Kismet/KismetMathLibrary.h"

AAGPlayer::AAGPlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment((USceneComponent*)GetCapsuleComponent());

	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 1300.f;
	SpringArm->SetWorldRotation(FRotator(-60.f, 0.f, 0.f));
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bDoCollisionTest = false;
}


void AAGPlayer::BeginPlay()
{
	Super::BeginPlay();
	MyPlayerController = Cast<AAGPlayerController>(GetController());
}

void AAGPlayer::MoveLeftRight(float _Value)
{
	FRotator Temp;

	AddMovementInput(UKismetMathLibrary::GetRightVector(Temp), _Value);
}

void AAGPlayer::MoveUpDown(float _Value)
{
	FRotator Temp;

	AddMovementInput(UKismetMathLibrary::GetForwardVector(Temp), _Value);
}

void AAGPlayer::PimaryAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("Parent Attack"));
}

void AAGPlayer::Skill1()
{
	UE_LOG(LogTemp, Warning, TEXT("Parent Skill1"));
}

void AAGPlayer::Skill2()
{
	UE_LOG(LogTemp, Warning, TEXT("Parent Skill2"));
}

void AAGPlayer::Skill3()
{
	UE_LOG(LogTemp, Warning, TEXT("Parent Skill3"));
}
