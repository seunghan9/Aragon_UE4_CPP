// Fill out your copyright notice in the Description page of Project Settings.


#include "AGGideon.h"
#include "AGGideonAnimInstance.h"
#include "AGPlayerController.h"
#include "GideonPrimaryAttack.h"
#include "Kismet/GameplayStatics.h" 

AAGGideon::AAGGideon()
{
	/*Gideon 메시 불러오기*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh> sm(TEXT("SkeletalMesh'/Game/ParagonGideon/Characters/Heroes/Gideon/Meshes/Gideon.Gideon'"));

	/*Gideon 메시 위치 설정*/
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	/*Gideon 메시 넣기*/
	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

	ConstructorHelpers::FObjectFinder<UParticleSystemComponent> PSAC(TEXT("
		
		
		
		
		
		
		
		'"));
	
}

void AAGGideon::BeginPlay()
{
	Super::BeginPlay();

	GideonAnimInstance->AttackA.AddDynamic(this, &AAGGideon::SpawnPimaryAttack);
}

void AAGGideon::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GideonAnimInstance = Cast<UAGGideonAnimInstance>(GetMesh()->GetAnimInstance());
}


void AAGGideon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	SetActorRotation(MyPlayerController->LookRotation);
}

void AAGGideon::PimaryAttack()
{
	GideonAnimInstance->Play_Montage(GideonAnimInstance->Attack1Montage);
}

void AAGGideon::SpawnPimaryAttack()
{
	
	FVector PimarySpawnLocation = GetMesh()->GetSocketLocation(TEXT("Muzzle_01"));

	UGameplayStatics::SpawnEmitterAttached()

	const FRotator PimarySpawnRotation = MyPlayerController->LookRotation;

	GetWorld()->SpawnActor<AGideonPrimaryAttack>(PimarySpawnLocation, PimarySpawnRotation);
}

void AAGGideon::Skill1()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill1"));
}

void AAGGideon::Skill2()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill2"));
}

void AAGGideon::Skill3()
{
	UE_LOG(LogTemp, Warning, TEXT("Gideon Skill3"));
}

