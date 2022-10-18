// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARAGONCPP_API AAGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupInputComponent() override;


	void MoveLeftRight(float _Value);

	void MoveUpDown(float _Value);

	void PimaryAttack();

	void SkillQ();

	void SkillE();

	void SkillR();



	UPROPERTY()
	FVector MouseLocation;

	UPROPERTY()
	FRotator LookRotation;

	UPROPERTY(EditAnywhere)
	class AAGPlayer* ControlledPawn;
};
