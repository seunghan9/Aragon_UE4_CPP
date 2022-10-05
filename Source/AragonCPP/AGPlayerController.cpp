// Fill out your copyright notice in the Description page of Project Settings.


#include "AGPlayerController.h"


void AAGPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FHitResult hit;

	if (GetHitResultUnderCursor(ECC_Visibility, false, hit))
	{
		MouseLocation = hit.Location;
	}

}
