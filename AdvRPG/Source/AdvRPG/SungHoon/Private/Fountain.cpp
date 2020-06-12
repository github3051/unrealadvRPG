/*
	Copyright 2020. SungHoon Kim. All Rights Reserved.

*/
#include "../Public/Fountain.h"
//#include "Fountain.h"

// Sets default values
AFountain::AFountain()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));
	RootComponent = box;
	
	RotateSpeed = 30.0f;

	// Movement Component 활용 (﻿RotatingMovement)
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));
	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);

	/*bool bTest = false;
	
	if (ensure(btest == true))
		UE_LOG(LogBySH, Error, TEXT("TEST"));*/

	UE_LOG(LogBySH, Error, TEXT("TEST@@@"));
	//UE_LOG(LogTemp, Log, TEXT("TEST해봅니다"));
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogBySH, Warning, TEXT("BeginPlay"));
}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 제자리 회전
	AddActorLocalRotation(FRotator(RotateSpeed*DeltaTime, 0.0f, 0.0f));
}

void AFountain::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LogBySH, Warning, TEXT("EndPlay"));
	UE_LOG(LogBySH, Warning, TEXT("GetDeltaSeconds : %f"),GetWorld()->GetDeltaSeconds()); // 프레임 시간
	UE_LOG(LogBySH, Warning, TEXT("GetTimeSeconds : %f"), GetWorld()->GetTimeSeconds()); // 게임 시작후 경과시간
	UE_LOG(LogBySH, Warning, TEXT("GetRealTimeSeconds : %f"), GetWorld()->GetRealTimeSeconds()); // 현실 세계 경과시간
}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UE_LOG(LogBySH, Warning, TEXT("PostInitializeComponents"));
}

