// Fill out your copyright notice in the Description page of Project Settings.


#include "AGAnimInstance.h"
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

void UAGAnimInstance::PlayMontage(UAnimMontage* _Montage)
{
	if (!Montage_IsPlaying(_Montage))
	{
		PlayMontage(_Montage);
	}
}
