// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "FountainJG.generated.h"


UCLASS()
class ADVRPG_API AFountainJG : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountainJG();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent *Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent *Splash;

	UPROPERTY(EditAnywhere, Category = ID)
	int32 ID;

	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	float RotateSpeed;

};
