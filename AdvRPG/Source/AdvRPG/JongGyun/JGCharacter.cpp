// Fill out your copyright notice in the Description page of Project Settings.


#include "JGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "JGAnimInstance.h"

// Sets default values
AJGCharacter::AJGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM_Countess(TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
	if (SM_Countess.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM_Countess.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> Countess_Anim(TEXT("/Game/JongGyun/Animation/JGAnim_BP.JGAnim_BP"));
	if (Countess_Anim.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(Countess_Anim.Class);
	}

	//SetControlMode(0);
	//SetControlMode(EControlMode::DIABLO);

	//ArmLengthSpeed = 3.0f;
	//ArmRotationSpeed = 10.0f;
	GetCharacterMovement()->JumpZVelocity = 800.0f;
}

// Called when the game starts or when spawned
void AJGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

//void AJGCharacter::SetControlMode(int32 ControlMode)
//{
//	if (ControlMode == 0)
//	{
//		SpringArm->TargetArmLength = 450.0f;
//		SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
//		SpringArm->bUsePawnControlRotation = true;
//		SpringArm->bInheritPitch = true;
//		SpringArm->bInheritRoll = true;
//		SpringArm->bInheritYaw = true;
//		SpringArm->bDoCollisionTest = true;
//		bUseControllerRotationYaw = false;
//
//		GetCharacterMovement()->bOrientRotationToMovement = true;
//		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
//	}
//}

//void AJGCharacter::SetControlMode(EControlMode NewControlMode)
//{
//	CurrentControlMode = NewControlMode;
//
//	switch (CurrentControlMode)
//	{
//	case EControlMode::GTA:
//		//SpringArm->TargetArmLength = 450.0f;
//		//SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
//		SpringArm->bUsePawnControlRotation = true;
//		SpringArm->bInheritPitch = true;
//		SpringArm->bInheritRoll = true;
//		SpringArm->bInheritYaw = true;
//		SpringArm->bDoCollisionTest = true;
//		bUseControllerRotationYaw = false;
//
//		GetCharacterMovement()->bOrientRotationToMovement = true;
//		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
//
//		GetCharacterMovement()->bUseControllerDesiredRotation = false;
//
//		ArmLengthTo = 450.0f;
//
//		break;
//
//	case EControlMode::DIABLO:
//		//SpringArm->TargetArmLength = 800.0f;
//		//SpringArm->SetRelativeRotation(FRotator(-45.0f,0.0f,0.0f));
//		SpringArm->bUsePawnControlRotation = false;
//		SpringArm->bInheritPitch = false;
//		SpringArm->bInheritRoll = false;
//		SpringArm->bInheritYaw = false;
//		SpringArm->bDoCollisionTest = false;
//		bUseControllerRotationYaw = true;
//
//		GetCharacterMovement()->bOrientRotationToMovement = false;
//		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
//
//		GetCharacterMovement()->bUseControllerDesiredRotation = true;
//
//		ArmLengthTo = 800.0f;
//		ArmRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
//
//		break;
//
//	}
//}


// Called every frame
void AJGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);

	//switch (CurrentControlMode)
	//{
	//case EControlMode::DIABLO:
	//	//SpringArm->RelativeRotation = FMath::RInterpTo(SpringArm->RelativeRotation, ArmRotationTo, DeltaTime, ArmRotationSpeed); 변경전
	//	FRotator TmpRo = FMath::RInterpTo(SpringArm->GetRelativeRotation(), ArmRotationTo, DeltaTime, ArmRotationSpeed);
	//	SpringArm->SetRelativeRotation(TmpRo);	//이 두 줄이 변경 후
	//	break;
	//}


	//switch (CurrentControlMode)
	//{
	//case EControlMode::DIABLO:
	//	if (DirectionToMove.SizeSquared() > 0.0f)
	//	{
	//		GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
	//		AddMovementInput(DirectionToMove);
	//	}
	//	break;
	//}




}

// Called to bind functionality to input
void AJGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AJGCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AJGCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AJGCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AJGCharacter::Turn);

//	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AJGCharacter::ViewChange);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AJGCharacter::Jump);

}

void AJGCharacter::UpDown(float NewAxisValue)
{
	//Log
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
	//AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);

	/*switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
		break;

	case EControlMode::DIABLO:
		DirectionToMove.X = NewAxisValue;
		break;
	}*/

}

void AJGCharacter::LeftRight(float NewAxisValue)
{
	//Log
	AddMovementInput(GetActorRightVector(), NewAxisValue);
	//AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);

	//switch (CurrentControlMode)
	//{
	//case EControlMode::GTA:
	//	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
	//	break;

	//case EControlMode::DIABLO:
	//	DirectionToMove.Y = NewAxisValue;
	//	break;
	//}
}

void AJGCharacter::LookUp(float NewAxisValue)
{
	//Log
	AddControllerPitchInput(NewAxisValue);
	/*switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddControllerPitchInput(NewAxisValue);
		break;

	}*/
}

void AJGCharacter::Turn(float NewAxisValue)
{
	//Log
	AddControllerYawInput(NewAxisValue);

	/*switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddControllerYawInput(NewAxisValue);
		break;
	}*/
}

//void AJGCharacter::ViewChange()
//{
//	switch (CurrentControlMode)
//	{
//	case EControlMode::GTA:
//		GetController()->SetControlRotation(GetActorRotation());
//		SetControlMode(EControlMode::DIABLO);
//		break;
//
//	case EControlMode::DIABLO:
//		//GetController()->SetControlRotation(SpringArm->RelativeRotation); 변경 전
//		GetController()->SetControlRotation(SpringArm->GetRelativeRotation());  //변경 후
//		SetControlMode(EControlMode::GTA);
//		break;
//	}
//}