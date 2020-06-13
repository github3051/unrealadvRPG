// Fill out your copyright notice in the Description page of Project Settings.

/*

	Copyright 2020. SungHoon Kim. All Rights Reserved.
*/

#pragma once

#include "../../AdvRPG.h"
//#include "CoreMinimal.h"
#include "GameFramework/RotatingMovementComponent.h" // for Movement Component
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()
class ADVRPG_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// for test
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;
	virtual void PreInitializeComponents() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *box;

	// memeber variables
private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	float RotateSpeed;

	// Movement Component
	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

};
