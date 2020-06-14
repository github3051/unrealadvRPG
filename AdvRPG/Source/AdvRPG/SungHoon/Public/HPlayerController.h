// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HPlayerController.generated.h"

/**
 * Copyright 2020. SungHoon Kim, All Rights Reserved.
 */
UCLASS()
class ADVRPG_API AHPlayerController : public APlayerController
{
	GENERATED_BODY()

	AHPlayerController();
protected:
	virtual void BeginPlay() override;

public:
	// Event function
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override; // 4.22 이전에는 Possess였음
};
