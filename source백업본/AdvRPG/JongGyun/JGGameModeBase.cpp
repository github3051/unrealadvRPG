// Fill out your copyright notice in the Description page of Project Settings.


#include "JGGameModeBase.h"
#include "JGPawn.h"
#include "JGPlayerController.h"

AJGGameModeBase::AJGGameModeBase()
{
	//DefaultPawnClass = AJGPawn::StaticClass();
	//PlayerControllerClass = AJGPlayerController::StaticClass();

	//�������Ʈ�� ���۵� ���� ������ ���� �̷��� ������
	//static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT(====== = ���====== = ));
	//if (BP_PAWN_C.Succeeded())
	//{
	//	DefaultPawnClass = BP_PAWN_C.Class
	//}
	
}

void AJGGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	//LogByJG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	//LogByJG(Warning, TEXT("PostLogin End"));

}