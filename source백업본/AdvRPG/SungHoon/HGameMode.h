// Fill out your copyright notice in the Description page of Project Settings.
/*
	Notice : ���� ��ġ�� �̰͸� �ۿ� ��������. ��� ����
	Copyright 2020. SungHoon Kim. All Rights Reserved.
*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HGameMode.generated.h"


UCLASS()
class ADVRPG_API AHGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHGameMode();

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;

};
