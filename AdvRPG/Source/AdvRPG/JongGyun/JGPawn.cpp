// Fill out your copyright notice in the Description page of Project Settings.


#include "JGPawn.h"

// Sets default values
AJGPawn::AJGPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f),FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM_Countess(TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
	if (SM_Countess.Succeeded())
	{
		Mesh->SetSkeletalMesh(SM_Countess.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> Countess_Anim(TEXT("/Game/JongGyun/Animation/JGAnim_BP.JGAnim_BP"));
	if (Countess_Anim.Succeeded())
	{
		Mesh->SetAnimInstanceClass(Countess_Anim.Class);
	}

}

// Called when the game starts or when spawned
void AJGPawn::BeginPlay()
{
	Super::BeginPlay();
	//Mesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	//UAnimationAsset* AnimAsset = LoadObject<UAnimationAsset>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Fwd.Jog_Fwd"));
	//if (AnimAsset != nullptr)
	//{
	//	Mesh->PlayAnimation(AnimAsset, true);
	//}
	
}

// Called every frame
void AJGPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJGPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AJGPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}


// Called to bind functionality to input
void AJGPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("HUpDown"), this, &AJGPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("HLeftRight"), this, &AJGPawn::LeftRight);

}

void AJGPawn::UpDown(float NewAxisValue)
{
	//Log
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AJGPawn::LeftRight(float NewAxisValue)
{
	//Log
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}
