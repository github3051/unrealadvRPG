// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "EngineMinimal.h"
//#include "CoreMinimal.h"
#include "../../AdvRPG.h"
#include "GameFramework/SpringArmComponent.h" // for USpringArmComponent
#include "Camera/CameraComponent.h" // for UCameraComponent
#include "GameFramework/Character.h" // for SetupPlayerInputComponent

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

	// ��Ÿ�� ����� ���� ��������Ʈ �Լ� ����.
	virtual void PostInitializeComponents() override;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);

	void Dodge();
	void Attack();

	/// Member Variables
	// �� coding standard : public ������ m�� ������ �ʴ´�.
public:
	// Added Hoon
	UPROPERTY(VisibleAnywhere, Category = CAMERA)
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = CAMERA)
		UCameraComponent* Camera;
	
	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;

	UPROPERTY()
		class UHAnimInstance* HAnim;

};
