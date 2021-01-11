// Fill out your copyright notice in the Description page of Project Settings.


#include "HGameMode.h"
#include "Public/HPawn.h" // for default Pawn class
#include "Public/HPlayerController.h" // for PlayerController
 
#include "Public/HCharacter.h"

AHGameMode::AHGameMode()
{
	// set (defalut) pawn class for HPawn made Hoon
	//DefaultPawnClass = AHPawn::StaticClass();
	DefaultPawnClass = AHCharacter::StaticClass();

#pragma region Used BP Character Method
	/*static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT(
		"/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter_C"));
	if (BP_PAWN_C.Succeeded())
		DefaultPawnClass = BP_PAWN_C.Class;*/
#pragma endregion
		
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
