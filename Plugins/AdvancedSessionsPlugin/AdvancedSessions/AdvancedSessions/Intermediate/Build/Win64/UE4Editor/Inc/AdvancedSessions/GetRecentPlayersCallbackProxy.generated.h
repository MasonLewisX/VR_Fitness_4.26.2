// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FBPOnlineRecentPlayer;
class UObject;
struct FBPUniqueNetId;
class UGetRecentPlayersCallbackProxy;
#ifdef ADVANCEDSESSIONS_GetRecentPlayersCallbackProxy_generated_h
#error "GetRecentPlayersCallbackProxy.generated.h already included, missing '#pragma once' in GetRecentPlayersCallbackProxy.h"
#endif
#define ADVANCEDSESSIONS_GetRecentPlayersCallbackProxy_generated_h

#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_10_DELEGATE \
struct _Script_AdvancedSessions_eventBlueprintGetRecentPlayersDelegate_Parms \
{ \
	TArray<FBPOnlineRecentPlayer> Results; \
}; \
static inline void FBlueprintGetRecentPlayersDelegate_DelegateWrapper(const FMulticastScriptDelegate& BlueprintGetRecentPlayersDelegate, TArray<FBPOnlineRecentPlayer> const& Results) \
{ \
	_Script_AdvancedSessions_eventBlueprintGetRecentPlayersDelegate_Parms Parms; \
	Parms.Results=Results; \
	BlueprintGetRecentPlayersDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_SPARSE_DATA
#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAndStoreRecentPlayersList);


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAndStoreRecentPlayersList);


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGetRecentPlayersCallbackProxy(); \
	friend struct Z_Construct_UClass_UGetRecentPlayersCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UGetRecentPlayersCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UGetRecentPlayersCallbackProxy)


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUGetRecentPlayersCallbackProxy(); \
	friend struct Z_Construct_UClass_UGetRecentPlayersCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UGetRecentPlayersCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UGetRecentPlayersCallbackProxy)


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGetRecentPlayersCallbackProxy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UGetRecentPlayersCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGetRecentPlayersCallbackProxy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(UGetRecentPlayersCallbackProxy&&); \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const UGetRecentPlayersCallbackProxy&); \
public:


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(UGetRecentPlayersCallbackProxy&&); \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const UGetRecentPlayersCallbackProxy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UGetRecentPlayersCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGetRecentPlayersCallbackProxy); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGetRecentPlayersCallbackProxy)


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_PRIVATE_PROPERTY_OFFSET
#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_12_PROLOG
#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_PRIVATE_PROPERTY_OFFSET \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_SPARSE_DATA \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_PRIVATE_PROPERTY_OFFSET \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_SPARSE_DATA \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS_NO_PURE_DECLS \
	VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GetRecentPlayersCallbackProxy."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDSESSIONS_API UClass* StaticClass<class UGetRecentPlayersCallbackProxy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID VR_Fitness_4_26_2_Plugins_AdvancedSessionsPlugin_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
