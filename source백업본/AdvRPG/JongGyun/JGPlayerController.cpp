// Fill out your copyright notice in the Description page of Project Settings.


#include "JGPlayerController.h"
#include "JGPawn.h"
#include "JGGameModeBase.h"

void AJGPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
//	LogByJG_S(Warning);
}

//void AJGPlayerController::Possess(APawn* aPawn)
//{
//	//ABLOG_S(Warning);
//	Super::Possess(aPawn);
//}

AJGGameModeBase::AJGGameModeBase()
{
	//DefaultPawnClass = AJGPawn::StaticClass();
	//PlayerControllerClass = AJGPlayerController::StaticClass();
}
