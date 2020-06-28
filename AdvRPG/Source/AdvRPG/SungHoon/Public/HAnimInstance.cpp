// Fill out your copyright notice in the Description page of Project Settings.


#include "HAnimInstance.h"

UHAnimInstance::UHAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	bIsInAir = false;
}

void UHAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// 현재 애니메이션을 실행하고 있는 폰의 객체를 가져옴
	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();

		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			bIsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}
