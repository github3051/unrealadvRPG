// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdvRPG.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, AdvRPG, "AdvRPG" );

// Sunghoon's Log
DEFINE_LOG_CATEGORY(LogBySH);

// JongGyun's Log
DEFINE_LOG_CATEGORY(LogByJG);


// 이 함수가 호출된 함수의 이름과 라인을 매크로로 String화 시킴
#define LogByJG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__)+TEXT(")"))

// 위의 기능을 이용하여 코드가 들어있는 파일 이름과 함수, 그리고 라인 정보를 추가함. 로그를 사용한 함수의 실행 시점을 파악할 때 유용.
// 인자로 하나밖에 받지 않기 때문에 자세한 내용을 알 순 없음. ex) LogByJG_S(Warning);
#define LogByJG_S(Verbosity) UE_LOG(AdvRPG, Verbosity, TEXT("%s"), *LogByJG_CALLINFO)

//위의 LogByJG_S 정보에 형식 문자열로 추가 정보를 지정해주는 로그. _S가 실행 시점만 파악 가능하다면, 여기에서는 그 뒤에 추가 정보를 넣어서 로그 실행시점에서 내가 필요한 정보들을 알아낼 수 있음.
#define LogByJG(Verbosity, Format, ...) UE_LOG(AdvRPG, Verbosity, TEXT("%s%s"), *LogBYJG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))