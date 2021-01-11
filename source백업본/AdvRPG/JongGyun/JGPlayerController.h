// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AdvRPG/AdvRPG.h"
#include "GameFramework/PlayerController.h"
#include "JGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ADVRPG_API AJGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void PostInitializeComponents() override;
	//virtual void Possess(APawn* aPawn) override;
};
