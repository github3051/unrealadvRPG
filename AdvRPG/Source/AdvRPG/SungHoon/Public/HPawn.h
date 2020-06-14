// Fill out your copyright notice in the Description page of Project Settings.

/*

	Copyright 2020. SungHoon Kim, All Rights Reserved.
*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h" // for Pawn Movement Component
#include "GameFramework/SpringArmComponent.h" // for USpringArmComponent
#include "Camera/CameraComponent.h" // for UCameraComponent
#include "Components/CapsuleComponent.h" // for CapsuleComponent 루트 컴포넌트 부착
#include "HPawn.generated.h"

UCLASS()
class ADVRPG_API AHPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Test Event Function
	virtual void PostInitializeComponents();
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// 이득우 Chapter 5, 폰의 제작과 조작
	UPROPERTY(VisibleAnywhere, Category = TEST)
		UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere, Category = TEST)
		USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, Category = TEST)
		UFloatingPawnMovement* Movement;
	UPROPERTY(VisibleAnywhere, Category = TEST)
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = TEST)
		UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
};
