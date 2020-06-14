// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/HPawn.h"

// Sets default values
AHPawn::AHPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Execute AHPawn Constructor!"));

	// new assigned
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	// Inherited Object
	RootComponent = Capsule; // Needed #include "Components/CapsuleComponent.h"
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm); // Camera attach SpringArm
	
	// Set components
	Capsule->SetCapsuleHalfHeight(140.0f);
	Capsule->SetCapsuleRadius(36.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f; // 400cm = 4m
	SpringArm->SetRelativeRotation(FRotator(-15.0f,0.0f,0.0f));

	// 메시 등록
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> TEMP(TEXT(
		"/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin"));
	if (TEMP.Succeeded())
		Mesh->SetSkeletalMesh(TEMP.Object);
}

// Called when the game starts or when spawned
void AHPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Execute AHPawn BeginPlay!"));
}

// Called every frame
void AHPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHPawn::PostInitializeComponents()
{
	UE_LOG(LogTemp, Error, TEXT("PostInitializeComponents Begin (AHPawn)"));
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Error, TEXT("PostInitializeComponents End (AHPawn)"));
}

void AHPawn::PossessedBy(AController * NewController)
{
	UE_LOG(LogTemp, Error, TEXT("PossessedBy Begin (AHPawn)"));
	Super::PossessedBy(NewController);
	UE_LOG(LogTemp, Error, TEXT("PossessedBy End (AHPawn)"));
}

// Called to bind functionality to input
void AHPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UE_LOG(LogTemp, Warning, TEXT("Execute AHPawn SetupPlayerInputComponent!"));

	PlayerInputComponent->BindAxis(TEXT("HUpDown"), this, &AHPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("HLeftRight"), this, &AHPawn::LeftRight);
}

void AHPawn::UpDown(float NewAxisValue)
{
	//UE_LOG(LogTemp, Warning, TEXT("UpDown : %f"), NewAxisValue);
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AHPawn::LeftRight(float NewAxisValue)
{
	//UE_LOG(LogTemp, Warning, TEXT("LeftRight : %f"), NewAxisValue);
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

