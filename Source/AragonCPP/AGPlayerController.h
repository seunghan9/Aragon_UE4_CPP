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
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	FVector MouseLocation;
};
