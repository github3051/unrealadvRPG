// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVRPG_AdvRPGCharacter_generated_h
#error "AdvRPGCharacter.generated.h already included, missing '#pragma once' in AdvRPGCharacter.h"
#endif
#define ADVRPG_AdvRPGCharacter_generated_h

#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_SPARSE_DATA
#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_RPC_WRAPPERS
#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAdvRPGCharacter(); \
	friend struct Z_Construct_UClass_AAdvRPGCharacter_Statics; \
public: \
	DECLARE_CLASS(AAdvRPGCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvRPG"), NO_API) \
	DECLARE_SERIALIZER(AAdvRPGCharacter)


#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAAdvRPGCharacter(); \
	friend struct Z_Construct_UClass_AAdvRPGCharacter_Statics; \
public: \
	DECLARE_CLASS(AAdvRPGCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvRPG"), NO_API) \
	DECLARE_SERIALIZER(AAdvRPGCharacter)


#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAdvRPGCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAdvRPGCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAdvRPGCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAdvRPGCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAdvRPGCharacter(AAdvRPGCharacter&&); \
	NO_API AAdvRPGCharacter(const AAdvRPGCharacter&); \
public:


#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAdvRPGCharacter(AAdvRPGCharacter&&); \
	NO_API AAdvRPGCharacter(const AAdvRPGCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAdvRPGCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAdvRPGCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAdvRPGCharacter)


#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AAdvRPGCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AAdvRPGCharacter, FollowCamera); }


#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_9_PROLOG
#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_SPARSE_DATA \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_RPC_WRAPPERS \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_INCLASS \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_SPARSE_DATA \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_INCLASS_NO_PURE_DECLS \
	AdvRPG_Source_AdvRPG_AdvRPGCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVRPG_API UClass* StaticClass<class AAdvRPGCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdvRPG_Source_AdvRPG_AdvRPGCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
