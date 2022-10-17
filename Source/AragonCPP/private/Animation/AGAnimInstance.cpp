// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AGAnimInstance.h"
UAGAnimInstance::UAGAnimInstance()
{

}

void UAGAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		Direction = CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());

		Yaw = Pawn->GetActorRotation().Yaw;
	}

}



bool UAGAnimInstance::Play_Montage(UAnimMontage* _Montage)
{
	if (!Montage_IsPlaying(_Montage))
	{
		Montage_Play(_Montage);

		return true;
	}

	return false;

}
