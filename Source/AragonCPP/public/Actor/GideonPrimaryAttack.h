// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GideonPrimaryAttack.generated.h"

UCLASS()
class ARAGONCPP_API AGideonPrimaryAttack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGideonPrimaryAttack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float Damage;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* AParticle;

	UPROPERTY(EditAnywhere)
	class USphereComponent* ACollision;

	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* AProjectile;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* PrimaryAttackCast;


	//UFUNCTION()
	//void MyOnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
