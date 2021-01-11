// Fill out your copyright notice in the Description page of Project Settings.


#include "HAnimInstance.h"
#include "GameFramework/Character.h" // for ACharacter
#include "GameFramework/PawnMovementComponent.h" // for GetMovementComponent

UHAnimInstance::UHAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	bIsInAir = false;

	// Added Dodge Montage
	static ConstructorHelpers::FObjectFinder<UAnimMontage> DODGE_MONTAGE(TEXT(
		"/Game/SungHoon/Animations/HDodgeForward_Montage.HDodgeForward_Montage"));
	
	if (DODGE_MONTAGE.Succeeded())
	{
		DodgeMontage = DODGE_MONTAGE.Object;
	}
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

void UHAnimInstance::PlayDodgeMontage()
{
	UE_LOG(LogTemp, Warning, TEXT("Play Dodge Montage"));
	
	if (!bIsInAir && !Montage_IsPlaying(DodgeMontage))
	{
		Montage_Play(DodgeMontage, 1.0f);
	}
}