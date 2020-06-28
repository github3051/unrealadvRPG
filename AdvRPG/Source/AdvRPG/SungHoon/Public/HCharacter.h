// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "HCharacter.generated.h"

UCLASS()
class ADVRPG_API AHCharacter : public ACharacter
{
	GENERATED_BODY()

/// Member Functions
public:
	// Sets default values for this character's properties
	AHCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);

/// Member Variables

	// ※ coding standard : public 변수는 m을 붙이지 않는다.
public:
	// Added Hoon
	UPROPERTY(VisibleAnywhere, Category = CAMERA)
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = CAMERA)
		UCameraComponent* Camera;

};
