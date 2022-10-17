// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LoadComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARAGONCPP_API ULoadComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULoadComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	template< class T >
	T* MyLoadObject(const char* _Text);

		
};

template<class T>
inline T* ULoadComponent::MyLoadObject(const char* _Text)
{
	ConstructorHelpers::FObjectFinder<T> L(TEXT(_Text));
	if (L.Succeeded())
	{
		return L;
	}
}

