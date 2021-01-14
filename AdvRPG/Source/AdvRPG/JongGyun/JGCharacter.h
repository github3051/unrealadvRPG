// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "EngineMinimal.h"
#include "../AdvRPG.h"
#include "GameFramework/Character.h"
#include "JGCharacter.generated.h"

UCLASS()
class ADVRPG_API AJGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//void SetControlMode(int32 ControlMode);

	enum class EControlMode
	{
		GTA,
		DIABLO
	};

	//void SetControlMode(EControlMode NewControlMode);
	//EControlMode CurrentControlMode = EControlMode::GTA;
	//FVector DirectionToMove = FVector::ZeroVector;

	//float ArmLengthTo = 0.0f;
	//FRotator ArmRotationTo = FRotator::ZeroRotator;
	//float ArmLengthSpeed = 0.0f;
	//float ArmRotationSpeed = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);

	//void ViewChange();
};
