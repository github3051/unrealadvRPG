// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../AdvRPG.h"
#include "Animation/AnimInstance.h"
#include "JGAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ADVRPG_API UJGAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UJGAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

};
