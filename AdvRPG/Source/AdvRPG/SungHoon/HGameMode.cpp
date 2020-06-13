// Fill out your copyright notice in the Description page of Project Settings.


#include "HGameMode.h"
#include "Public/HPawn.h" // for default Pawn class
#include "Public/HPlayerController.h" // for PlayerController

AHGameMode::AHGameMode()
{
	// set (defalut) pawn class for HPawn made Hoon
	DefaultPawnClass = AHPawn::StaticClass();
	// set Player controller made Hoon
	PlayerControllerClass = AHPlayerController::StaticClass();
	// test log
	UE_LOG(LogTemp, Warning, TEXT("Execute HGameMode Constructor!"));


}

void AHGameMode::PostLogin(APlayerController * NewPlayer)
{
	UE_LOG(LogTemp, Error, TEXT("PostLogin Begin (GameMode)"));
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Error, TEXT("PostLogin End (GameMode)"));
}
