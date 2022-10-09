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



private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	float Direction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawn, Meta = (AllowPrivateAccess = true))
	float Yaw;

public:
	void Play_Montage(UAnimMontage* _Montage);
};
