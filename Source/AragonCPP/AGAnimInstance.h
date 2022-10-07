// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AGAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARAGONCPP_API UAGAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:

	UAGAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;



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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn)
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn)
	float Direction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn)
	float Yaw;

protected:
	void PlayMontage(UAnimMontage* _Montage);
};
