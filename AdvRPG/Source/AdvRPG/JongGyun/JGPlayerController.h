// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ADVRPG_API AJGPlayerController : public APlayerController
{
	GENERATED_BODY()
	AJGPlayerController();

public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override;

protected:
	virtual void BeginPlay() override;
};
