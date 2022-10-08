 // Fill out your copyright notice in the Description page of Project Settings.


#include "AGPlayerController.h"
#include "AGPlayer.h"

void AAGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledPawn = Cast<AAGPlayer>(GetPawn());
}

void AAGPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FHitResult hit;

	if (GetHitResultUnderCursor(ECC_Visibility, false, hit))
	{
		MouseLocation = hit.Location;
	}
}

void AAGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("MoveLeftRight"), this, &AAGPlayerController::MoveLeftRight);

	InputComponent->BindAxis(TEXT("MoveUpDown"), this, &AAGPlayerController::MoveUpDown);

	InputComponent->BindAction(TEXT("PrimaryAttack"), EInputEvent::IE_Pressed, this, &AAGPlayerController::PimaryAttack);

	InputComponent->BindAction(TEXT("Skill1"), EInputEvent::IE_Pressed, this, &AAGPlayerController::Skill1);

	InputComponent->BindAction(TEXT("Skill2"), EInputEvent::IE_Pressed, this, &AAGPlayerController::Skill2);

	InputComponent->BindAction(TEXT("Skill3"), EInputEvent::IE_Pressed, this, &AAGPlayerController::Skill3);
}

void AAGPlayerController::MoveLeftRight(float _Value)
{
	ControlledPawn->MoveLeftRight(_Value);
}

void AAGPlayerController::MoveUpDown(float _Value)
{
	ControlledPawn->MoveUpDown(_Value);
}

void AAGPlayerController::PimaryAttack()
{
	ControlledPawn->PimaryAttack();
}

void AAGPlayerController::Skill1()
{
	ControlledPawn->Skill1();
}

void AAGPlayerController::Skill2()
{
	ControlledPawn->Skill2();
}

void AAGPlayerController::Skill3()
{
	ControlledPawn->Skill3();
}
