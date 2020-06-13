// Fill out your copyright notice in the Description page of Project Settings.

/*

	Copyright 2020. SungHoon Kim, All Rights Reserved.
*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HPawn.generated.h"

UCLASS()
class ADVRPG_API AHPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Event Function
	virtual void PostInitializeComponents();
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
