 // Fill out your copyright notice in the Description page of Project Settings.


#include "GameFrameWork/AGPlayerController.h"
#include "Character/AGPlayer.h"
#include "Kismet/KismetMathLibrary.h"

void AAGPlayerController::BeginPlay()
{

	Super::BeginPlay();

	SetShowMouseCursor(true);

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

	LookRotation.Yaw = (UKismetMathLibrary::FindLookAtRotation(ControlledPawn->GetActorLocation(),MouseLocation)).Yaw;

	LookRotation.Roll = 0.f;

	LookRotation.Pitch = 0.f;

}

void AAGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("MoveLeftRight"), this, &AAGPlayerController::MoveLeftRight);

	InputComponent->BindAxis(TEXT("MoveUpDown"), this, &AAGPlayerController::MoveUpDown);

	InputComponent->BindAction(TEXT("PrimaryAttack"), EInputEvent::IE_Pressed, this, &AAGPlayerController::PimaryAttack);

	InputComponent->BindAction(TEXT("SkillQ"), EInputEvent::IE_Pressed, this, &AAGPlayerController::SkillQ);

	InputComponent->BindAction(TEXT("SkillE"), EInputEvent::IE_Pressed, this, &AAGPlayerController::SkillE);

	InputComponent->BindAction(TEXT("SkillR"), EInputEvent::IE_Pressed, this, &AAGPlayerController::SkillR);
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
	ControlledPawn->PrimaryAttack();
}

void AAGPlayerController::SkillQ()
{
	ControlledPawn->SkillQ();
}

void AAGPlayerController::SkillE()
{
	ControlledPawn->SkillE();
}

void AAGPlayerController::SkillR()
{
	ControlledPawn->SkillR();
}
