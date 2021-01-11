// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdvRPG.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, AdvRPG, "AdvRPG" );

// Sunghoon's Log
DEFINE_LOG_CATEGORY(LogBySH);

// JongGyun's Log
DEFINE_LOG_CATEGORY(LogByJG);


// �� �Լ��� ȣ��� �Լ��� �̸��� ������ ��ũ�η� Stringȭ ��Ŵ
#define LogByJG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__)+TEXT(")"))

// ���� ����� �̿��Ͽ� �ڵ尡 ����ִ� ���� �̸��� �Լ�, �׸��� ���� ������ �߰���. �α׸� ����� �Լ��� ���� ������ �ľ��� �� ����.
// ���ڷ� �ϳ��ۿ� ���� �ʱ� ������ �ڼ��� ������ �� �� ����. ex) LogByJG_S(Warning);
#define LogByJG_S(Verbosity) UE_LOG(AdvRPG, Verbosity, TEXT("%s"), *LogByJG_CALLINFO)

//���� LogByJG_S ������ ���� ���ڿ��� �߰� ������ �������ִ� �α�. _S�� ���� ������ �ľ� �����ϴٸ�, ���⿡���� �� �ڿ� �߰� ������ �־ �α� ����������� ���� �ʿ��� �������� �˾Ƴ� �� ����.
#define LogByJG(Verbosity, Format, ...) UE_LOG(AdvRPG, Verbosity, TEXT("%s%s"), *LogBYJG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))