// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PC_Main.h"
#include <Engine.h>
#include <VR_Fitness/Bicycle_Main.h>
#include <VR_Fitness/SMapSelectingUI.h>
#include <VR_Fitness/SLoadingUSA.h>
//#include <Kismet/KismetMathLibrary.h>
//#include <Kismet/KismetSystemLibrary.h>
//#include <Kismet/KismetStringLibrary.h>
#include <UDPComponent.h>
#include <SIOJson/Public/SIOJsonObject.h>
#include <SIOJsonValue.h>
#include <CUBlueprintLibrary.h>
#include <VR_Fitness/PlayerHUD.h>
#include "GeneratedCodeHelpers.h"
#include "PC_Player.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpawnPlayer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetHandleInitial);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenUSA);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenAustralia);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenIceland);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetPlayerPosition);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams();

/**
 * 
 */
UCLASS()
class VR_FITNESS_API APC_Player : public APC_Main
{
	GENERATED_BODY()


public:

	APC_Player();
	
protected:

	virtual void BeginPlay() override;


public:

	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UDPcomponent, meta = (AllowPrivateAccess = "true"))
		class UUDPComponent* UDP_Handle_C;

	UPROPERTY(BlueprintAssignable, Category = "Calling Event")
		FSpawnPlayer eventSpawnPlayer;

	UPROPERTY(BlueprintAssignable, Category = "UDP Handle")
		FSetHandleInitial eventSetHandleInitial;

	UPROPERTY(BlueprintAssignable, Category = "Open Level")
		FOpenUSA eventOpenUSA;

	UPROPERTY(BlueprintAssignable, Category = "Open Level")
		FOpenAustralia eventOpenAustralia;

	UPROPERTY(BlueprintAssignable, Category = "Open Level")
		FOpenIceland eventOpenIceland;

	//UPROPERTY(BlueprintAssignable, Category = "Custom Event")
	//	FSetPlayerPosition eventSetPlayerPosition;

	UFUNCTION()
		void SpawnPlayer_C();

	UFUNCTION()
		void SetHandleInitial_C();

	UFUNCTION()
		void OpenUSA_C();

	UFUNCTION()
		void OpenAustralia_C();

	UFUNCTION()
		void OpenIceland_C();

	//UFUNCTION()
	//	void SetPlayerPosition_C();
	
	UFUNCTION()
		void OnReceivedBytes_Handle(const TArray<uint8>& Bytes, const FString& IPAddress);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class USIOJsonValue* JsonValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class USIOJsonObject* JsonObject;

	UPROPERTY(BlueprintReadOnly, Category = "SpawnPlayer")
		class ABicycle_Main* Bicycle_Main;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UDP Handle", meta = (AllowPrivateAccess = "true"))
		float Handle_Yaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UDP Handle", meta = (AllowPrivateAccess = "true"))
		float InitialGyroRotation_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UDP Handle", meta = (AllowPrivateAccess = "true"))
		float HandleRotationDegree_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UDP Handle", meta = (AllowPrivateAccess = "true"))
		float PreviousHandleRotationDegree_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UDP Handle", meta = (AllowPrivateAccess = "true"))
		float CurrentHandleRotationDegree_c;

	UPROPERTY(BlueprintReadOnly, Category = "SpawnPlayer")
		TArray<AActor*> FoundedPlayerStarts;

	UPROPERTY(BlueprintReadOnly, Category = "SpawnPlayer")
	FTransform transform;

	UPROPERTY(BlueprintReadOnly, Category = "SpawnPlayer")
	FVector SpawnActorLocation;

	UPROPERTY(BlueprintReadOnly, Category = "SpawnPlayer")
		bool bIsBicycleSpawned;

	UPROPERTY(BlueprintReadOnly, Category = "UDP Handle")
		bool bIsHandleInitialSet;

	UPROPERTY(BlueprintReadOnly, Category = "UDP Handle")
		FRotator RotationBicycleInitial;

	UPROPERTY(BlueprintReadOnly, Category = "Set Player Position")
		TArray<AActor*> FoundedXXXXXXXXX;

//	UPROPERTY(BlueprintReadOnly, Category = "Set Player Position")
//		SLoadingUSA* m_LoadingUSA;

private:

	FLatentActionInfo m_LatentActionInfo;

	FActorSpawnParameters m_ActorSpawnParameters;

	FTransform m_BicycleSpawnTransform;

	UClass* m_UClass;



};
