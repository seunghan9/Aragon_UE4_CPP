// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GideonQSkill.generated.h"

UCLASS()
class ARAGONCPP_API AGideonQSkill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGideonQSkill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class USphereComponent* SphereCollision;
	
	class UParticleSystemComponent* ParticleSystem;

	class UProjectileMovementComponent* ProjectileMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
