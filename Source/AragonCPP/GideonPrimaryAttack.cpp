// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "GideonPrimaryAttack.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "AGGideon.h"

// Sets default values
AGideonPrimaryAttack::AGideonPrimaryAttack()
	:Damage(10.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));

	ACollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));

	RootComponent = ACollision;

	AParticle->SetupAttachment(ACollision);

	AProjectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/ParagonGideon/FX/Particles/Gideon/Abilities/Primary/FX/P_Gideon_Primary_Projectile.P_Gideon_Primary_Projectile'"));

	if (PS.Succeeded())
	{
		AParticle->SetTemplate(PS.Object);
	}

	ACollision->SetSphereRadius(32.f);

	AProjectile->InitialSpeed = 1500.f;

	AProjectile->ProjectileGravityScale = 0.f;

	//ACollision->OnComponentBeginOverlap.AddDynamic(this, &AGideonPrimaryAttack::MyOnComponentBeginOverlap);

	ACollision->SetCollisionProfileName(TEXT("PlayerIgnore"));

}

// Called when the game starts or when spawned
void AGideonPrimaryAttack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGideonPrimaryAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AGideonPrimaryAttack::MyOnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor ,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	UGameplayStatics::ApplyDamage(OtherActor, Damage, GetOwner()->GetInstigatorController(), this, UDamageType::StaticClass());
//}



