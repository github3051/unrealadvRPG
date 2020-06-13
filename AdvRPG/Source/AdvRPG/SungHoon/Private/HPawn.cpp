// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/HPawn.h"

// Sets default values
AHPawn::AHPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("Execute AHPawn Constructor!"));
}

// Called when the game starts or when spawned
void AHPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHPawn::PostInitializeComponents()
{
	UE_LOG(LogTemp, Error, TEXT("PostInitializeComponents Begin (AHPawn)"));
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Error, TEXT("PostInitializeComponents End (AHPawn)"));
}

void AHPawn::PossessedBy(AController * NewController)
{
	UE_LOG(LogTemp, Error, TEXT("PossessedBy Begin (AHPawn)"));
	Super::PossessedBy(NewController);
	UE_LOG(LogTemp, Error, TEXT("PossessedBy End (AHPawn)"));
}

// Called to bind functionality to input
void AHPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

