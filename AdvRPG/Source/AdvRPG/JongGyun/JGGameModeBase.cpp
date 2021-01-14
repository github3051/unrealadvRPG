// Fill out your copyright notice in the Description page of Project Settings.


#include "JGGameModeBase.h"
#include "JGPawn.h"
#include "JGCharacter.h"
#include "JGPlayerController.h"

AJGGameModeBase::AJGGameModeBase()
{
	//DefaultPawnClass = AJGPawn::StaticClass();
	DefaultPawnClass = AJGCharacter::StaticClass();
	PlayerControllerClass = AJGPlayerController::StaticClass();
}

void AJGGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}