// Fill out your copyright notice in the Description page of Project Settings.


#include "HAnimInstance.h"

UHAnimInstance::UHAnimInstance()
{
	mCurrentPawnSpeed = 0.0f;
}

void UHAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// 현재 애니메이션을 실행하고 있는 폰의 객체를 가져옴
	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		mCurrentPawnSpeed = Pawn->GetVelocity().Size();
	}
}
