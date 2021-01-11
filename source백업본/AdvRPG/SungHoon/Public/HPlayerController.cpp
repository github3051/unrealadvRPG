// Fill out your copyright notice in the Description page of Project Settings.


#include "HPlayerController.h"

AHPlayerController::AHPlayerController()
{
	UE_LOG(LogTemp, Warning, TEXT("Execute HPlayerController Constructor!"));
}

void AHPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Execute HPlayerController BeginPlay!"));

	// 첫 시작시 뷰포트 강제 입력
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}

void AHPlayerController::PostInitializeComponents()
{
	UE_LOG(LogTemp, Error, TEXT("PostInitializeComponents Begin (AHPlayerController)"));
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Error, TEXT("PostInitializeComponents End (AHPlayerController)"));
}

void AHPlayerController::OnPossess(APawn * aPawn)
{
	UE_LOG(LogTemp, Error, TEXT("OnPossess Begin (AHPlayerController)"));
	Super::OnPossess(aPawn);
	UE_LOG(LogTemp, Error, TEXT("OnPossess End (AHPlayerController)"));
}
