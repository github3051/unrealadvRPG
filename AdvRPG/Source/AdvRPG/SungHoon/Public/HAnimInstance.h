// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "../../AdvRPG.h"
#include "Animation/AnimInstance.h" // for UAnimMontage & NativeUpdateAnimation

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
	void PlayAttackMontage();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool bIsInAir;

	// only can see Blueprint editer (VisibleDefaultsOnly)
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Dodge, Meta = (AllowPrivateAccess = true))
	UAnimMontage* DodgeMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;
};