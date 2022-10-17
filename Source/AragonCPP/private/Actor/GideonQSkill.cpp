// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GideonQSkill.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AGideonQSkill::AGideonQSkill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	ParticleSystem->SetupAttachment(SphereCollision);

	RootComponent = SphereCollision;

	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->InitialSpeed = 1000.f;

	ConstructorHelpers::FObjectFinder<UParticleSystem> PSC(TEXT("ParticleSystem'/Game/ParagonGideon/FX/Particles/Gideon/Abilities/ProjectileMeteor/FX/P_Gideon_RMB_Proj.P_Gideon_RMB_Proj'"));

	if (PSC.Succeeded())
	{
		ParticleSystem->SetTemplate(PSC.Object);
	}
}

// Called when the game starts or when spawned
void AGideonQSkill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGideonQSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

