// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"

#include "FountainJG.h"

// Sets default values
AFountainJG::AFountainJG()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LIGHT"));
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SPLASH"));
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));

	RootComponent = Body;
	Water->SetupAttachment(Body);
	Light->SetupAttachment(Body);
	Splash->SetupAttachment(Body);



	Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
	Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
	Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));

	ConstructorHelpers::FObjectFinder<UStaticMesh>SM_BODY(TEXT("/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid"));

	if (SM_BODY.Succeeded())
	{
		Body->SetStaticMesh(SM_BODY.Object);
	}

	RotateSpeed = 30.0f;
	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);
}

// Called when the game starts or when spawned
void AFountainJG::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFountainJG::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
}

