// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGAnimInstance.h"
#include "AGPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARAGONCPP_API UAGPlayerAnimInstance : public UAGAnimInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* Attack1Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* Attack2Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* Attack3Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* Skill1Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* Skill2Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* Skill3Montage;
};
