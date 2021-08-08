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

	// 애니메이션 몽타주 등록
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT(
		"/Game/SungHoon/Animations/S_Countess_Skeleton_Attack_Montage.S_Countess_Skeleton_Attack_Montage"));
	

	if (ATTACK_MONTAGE.Succeeded())
	{
		// 애니메이션 몽타주 변수에 해당 몽타주 애니메이션 정보를 등록한다.
		AttackMontage = ATTACK_MONTAGE.Object;
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

void UHAnimInstance::PlayAttackMontage()
{
	UE_LOG(LogTemp, Warning, TEXT("Play Attack Montage"));
	
	// 실행중이지 않으면
	if (!Montage_IsPlaying(AttackMontage))
	{
		Montage_Play(AttackMontage,1.0f);
	}
}