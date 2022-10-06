// Fill out your copyright notice in the Description page of Project Settings.


#include "AGPlayer.h"
#include "GameFramework\SpringArmComponent.h"
#include "Camera\CameraComponent.h"
AAGPlayer::AAGPlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment((USceneComponent*)GetCapsuleComponent());

	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 1300.f;
	SpringArm->SetWorldRotation(FRotator(-60.f, 0.f, 0.f));

}

void AAGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &AAGPlayer::MoveLeftRight);

	PlayerInputComponent->BindAxis(TEXT("MoveUpDown"), this, &AAGPlayer::MoveUpDown);

	PlayerInputComponent->BindAction(TEXT("PrimaryAttack"), EInputEvent::IE_Pressed, this,&AAGPlayer::PimaryAttack);

	PlayerInputComponent->BindAction(TEXT("Skill1"), EInputEvent::IE_Pressed, this, &AAGPlayer::Skill1);

	PlayerInputComponent->BindAction(TEXT("Skill2"), EInputEvent::IE_Pressed, this, &AAGPlayer::Skill2);

	PlayerInputComponent->BindAction(TEXT("Skill3"), EInputEvent::IE_Pressed, this, &AAGPlayer::Skill3);

}

void AAGPlayer::MoveLeftRight(float _Value)
{
	AddMovementInput(GetActorRightVector(), _Value);
}

void AAGPlayer::MoveUpDown(float _Value)
{
	AddMovementInput(GetActorForwardVector(), _Value);
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
