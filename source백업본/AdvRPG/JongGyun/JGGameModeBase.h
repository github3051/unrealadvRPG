// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AdvRPG/AdvRPG.h"
#include "GameFramework/GameModeBase.h"
#include "JGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ADVRPG_API AJGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AJGGameModeBase();

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
};
