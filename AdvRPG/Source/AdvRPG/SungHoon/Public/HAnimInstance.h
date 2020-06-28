// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/Character.h" // for ACharacter
#include "GameFramework/PawnMovementComponent.h" // for GetMovementComponent

#include "HAnimInstance.generated.h"


UCLASS()
class ADVRPG_API UHAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UHAnimInstance();

	// Called every frame (same tick) // Animation/AnimInstance.h
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// HCharacter.cpp 에서 호출예정
	void PlayDodgeMontage();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool bIsInAir;

	// only can see Blueprint editer (VisibleDefaultsOnly)
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Dodge, Meta = (AllowPrivateAccess = true))
	UAnimMontage* DodgeMontage;
};