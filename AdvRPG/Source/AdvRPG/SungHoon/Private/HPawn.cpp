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
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	
	// FloatingPawnMovement 사용할 예정. (중력 적용x)
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	Movement->MaxSpeed = 1500.0f;

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

	// Mesh에 애니메이션 등록
	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	// 애니메이션 블루프린트 클래스 정보 가져옴
	static ConstructorHelpers::FClassFinder<UAnimInstance> TEMP_ANIM(TEXT(
		"/Game/SungHoon/Animations/HAnimBlueprint.HAnimBlueprint_C"));
	if (TEMP_ANIM.Succeeded())
		Mesh->SetAnimInstanceClass(TEMP_ANIM.Class); // Mesh의 애님 인스턴스에 BP 클래스 정보 지정.
	
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

