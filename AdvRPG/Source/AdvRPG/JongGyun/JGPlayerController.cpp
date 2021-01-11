// Fill out your copyright notice in the Description page of Project Settings.


#include "JGPlayerController.h"

void AJGPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AJGPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
}

void AJGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}