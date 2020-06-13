// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdvRPGGameMode.h"
#include "AdvRPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAdvRPGGameMode::AAdvRPGGameMode()
{
	// Log Test (by SungHoon)
	UE_LOG(LogBySH, Warning, TEXT("Execute GameMode Constructor!"));

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
