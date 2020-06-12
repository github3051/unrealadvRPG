// Fill out your copyright notice in the Description page of Project Settings.

/*

	Copyright 2020. SungHoon Kim. All Rights Reserved.
*/

#pragma once

//#include "../AdvRPG.h"
#include "CoreMinimal.h"
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
