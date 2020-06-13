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
	
	// BOX라는 해쉬값을 넣어서 객체생성 (new = CreateDefaultSubobject)
	box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));
	RootComponent = box;
	
	RotateSpeed = 30.0f;

	// Movement Component 활용 (﻿RotatingMovement)
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));
	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);

	/// Assertion test
	/*bool bTest = false;
	
	if (ensure(btest == true))
		UE_LOG(LogBySH, Error, TEXT("TEST"));*/
	///

	/// Log test
	UE_LOG(LogBySH, Error, TEXT("LogBySH, Execute AFountain's Constructor"));
	UE_LOG(LogTemp, Error, TEXT("LogTemp, Execute AFountain's Constructor"));
}

void AFountain::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	UE_LOG(LogBySH, Error, TEXT("Execute AFountain's PreInitializeComponents!"));
}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UE_LOG(LogBySH, Error, TEXT("Execute AFountain's PostInitializeComponents!"));
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();
	
	/// Log Test
	// UE_LOG
	UE_LOG(LogBySH, Error, TEXT("Execute AFountain's BeginPlay"));
	// FString 으로 UE_LOG 찍어보기
	const FString tempString = FString::Printf(TEXT("Printf test : %d"), 1004);
	UE_LOG(LogBySH, Warning, TEXT("%s"),*tempString);
	///
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
	UE_LOG(LogBySH, Error, TEXT("Execute AFountain's EndPlay"));

	/// TimeManager test
	UE_LOG(LogBySH, Warning, TEXT("GetDeltaSeconds : %f"),GetWorld()->GetDeltaSeconds()); // 프레임 시간
	UE_LOG(LogBySH, Warning, TEXT("GetTimeSeconds : %f"), GetWorld()->GetTimeSeconds()); // 게임 시작후 경과시간
	UE_LOG(LogBySH, Warning, TEXT("GetRealTimeSeconds : %f"), GetWorld()->GetRealTimeSeconds()); // 현실 세계 경과시간
	///
}