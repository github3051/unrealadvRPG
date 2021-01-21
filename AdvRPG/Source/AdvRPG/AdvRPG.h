// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

// Sunghoon's log
DECLARE_LOG_CATEGORY_EXTERN(LogBySH, Log, All);


DECLARE_LOG_CATEGORY_EXTERN(LogByJG, Log, All);
#define JGLOG_CALLINFO (FString(__FUNCTION__)+ TEXT("(") + FString::FromInt(__LINE__) + TEXT(")") ))
#define JGLOG_S(Verbosity) UE_LOG(AdvRPG, Verbosity, TEXT("%s"), *JGLOG_CALLINFO)
#define JGLOG(Verbosity, Format, ...) UE_LOG(AdvRPG, Verbosity, TEXT("%s%s"), *JGLOG_CALLINFO, *FString::Printf(Format,##__VA_ARGS__))
#define JGCHECK(Expr, ...) {if(!(Expr)){JGLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;}}