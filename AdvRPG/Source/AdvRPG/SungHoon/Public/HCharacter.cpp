// Fill out your copyright notice in the Description page of Project Settings.

#include "HCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "HAnimInstance.h"

// Sets default values
AHCharacter::AHCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Execute AHCharacter Constructor!"));

	// 객체 생성
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	// character가 이미 갖고 있는 캡슐에 붙이기.
	SpringArm->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	// set up values
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	// Added Mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> COUNTESS(TEXT(
		"/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
	if (COUNTESS.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(COUNTESS.Object);
	}

	// Added Animation to Mesh
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	/*static ConstructorHelpers::FClassFinder<UAnimInstance> COUNTESS_ANIM(TEXT(
		"/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint.Countess_AnimBlueprint_C"));*/
		// Found Anim Instance object
	static ConstructorHelpers::FClassFinder<UAnimInstance> COUNTESS_ANIM(TEXT(
		"/Game/SungHoon/Animations/HAnimBlueprint.HAnimBlueprint_C"));
	if (COUNTESS_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(COUNTESS_ANIM.Class);
	}

	// Modified Jump Speed
	GetCharacterMovement()->JumpZVelocity = 550.0f;

}

// Called when the game starts or when spawned
void AHCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Execute AHCharacter BeginPlay!"));
}

// Called every frame
void AHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("HUpDown"), this, &AHCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("HLeftRight"), this, &AHCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AHCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AHCharacter::Turn);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AHCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Dodge"), EInputEvent::IE_Pressed, this, &AHCharacter::Dodge);

	// combo attack
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AHCharacter::Attack);
	
}


void AHCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	HAnim = Cast<UHAnimInstance>(GetMesh()->GetAnimInstance());
	//HAnim->OnMontageEnded.
	HAnim->OnMontageEnded.Add();
	auto temp = Cast<UHAnimInstance>(GetMesh()->GetAnimInstance());
	//temp->OnMontageEnded.Add(this, &AHCharacter::OnAttackMontageEnded);
	UE_LOG(LogTemp, Warning, TEXT("PostInitializeComponent for AHCharacter, AddDynamic"));
}

void AHCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AHCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

void AHCharacter::LookUp(float NewAxisValue)
{
	// 위아래 회전은 Y축기준 회전
	AddControllerPitchInput(NewAxisValue);
}

void AHCharacter::Turn(float NewAxisValue)
{
	// 좌우 회전은 Z축 기준 회전
	AddControllerYawInput(NewAxisValue);
}

void AHCharacter::Dodge()
{
	UE_LOG(LogTemp, Warning, TEXT("Dodge"));
	auto AnimInstance = Cast<UHAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance == nullptr) return;
	AnimInstance->PlayDodgeMontage();
}

void AHCharacter::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack!!!"));

	/*auto AnimInstance = Cast<UHAnimInstance>(GetMesh()->GetAnimInstance());
	if (nullptr == AnimInstance) return;
	AnimInstance->PlayAttackMontage();*/

	// 이미 실행중이면 그냥 리턴
	if (IsAttacking) return;

	//UHAnim

}


void AHCharacter::OnAttackMontageEnded(UAnimMontage * Montage, bool bInterrupted)
{
	UE_LOG(LogTemp, Warning, TEXT("IsAttacking = false!"));
	IsAttacking = false;
}