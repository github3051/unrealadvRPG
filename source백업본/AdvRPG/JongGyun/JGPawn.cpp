// Fill out your copyright notice in the Description page of Project Settings.


#include "JGPawn.h"

// Sets default values
AJGPawn::AJGPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJGPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJGPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJGPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//ABLOG_S(Warning);
}

//void AJGPawn::PossessedBy(AController* NewController)
//{
//	//ABLOG_S(Warning);
//	Super::PossessedBy(NewController);
//}

// Called to bind functionality to input
void AJGPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

