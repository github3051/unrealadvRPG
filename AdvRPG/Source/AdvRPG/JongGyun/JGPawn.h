// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "EngineMinimal.h"
#include "../AdvRPG.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "JGPawn.generated.h"



UCLASS()
class ADVRPG_API AJGPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AJGPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = Collision)
	UFloatingPawnMovement* Movement;

	UPROPERTY(VisibleAnywhere, Category = Collision)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);

};
