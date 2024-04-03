// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interface/ABCharacterItemInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABCharacterItemInterface_generated_h
#error "ABCharacterItemInterface.generated.h already included, missing '#pragma once' in ABCharacterItemInterface.h"
#endif
#define ARENABATTLE_ABCharacterItemInterface_generated_h

#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_SPARSE_DATA
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ARENABATTLE_API UABCharacterItemInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARENABATTLE_API UABCharacterItemInterface(UABCharacterItemInterface&&); \
	ARENABATTLE_API UABCharacterItemInterface(const UABCharacterItemInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ARENABATTLE_API, UABCharacterItemInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABCharacterItemInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABCharacterItemInterface) \
	ARENABATTLE_API virtual ~UABCharacterItemInterface();


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUABCharacterItemInterface(); \
	friend struct Z_Construct_UClass_UABCharacterItemInterface_Statics; \
public: \
	DECLARE_CLASS(UABCharacterItemInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/ArenaBattle"), ARENABATTLE_API) \
	DECLARE_SERIALIZER(UABCharacterItemInterface)


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IABCharacterItemInterface() {} \
public: \
	typedef UABCharacterItemInterface UClassType; \
	typedef IABCharacterItemInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_10_PROLOG
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_SPARSE_DATA \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class UABCharacterItemInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterItemInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS