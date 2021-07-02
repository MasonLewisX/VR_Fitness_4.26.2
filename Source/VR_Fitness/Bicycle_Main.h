// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <UDPComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/KismetStringLibrary.h>
#include <Kismet/KismetSystemLibrary.h>
#include <SIOJson/Public/SIOJsonObject.h>
#include <SIOJsonValue.h>
#include <CUBlueprintLibrary.h>
#include <Engine.h>
#include <VR_Fitness/Character_Player.h>
#include "GeneratedCodeHelpers.h"
#include "Bicycle_Main.generated.h"

UCLASS()
class VR_FITNESS_API ABicycle_Main : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABicycle_Main();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UDPcomponent, meta = (AllowPrivateAccess = "true"))
	class UUDPComponent* UDPcomp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float NewWheelTime_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float PreviousWheelTime_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float DeltaWheelTime_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float WheelDiameter_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float AddedSpeed_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		FVector DirectionalVector_c;

	//Km/h
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float VelocityOfBicycle_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		FRotator BicycleRotation_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float TotalMass_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float NormalForceScale_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float CoefficientOfFriction_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float ScaleOfFriction_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		FVector ForceOfFriction_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		FVector FrictionalAcceleration_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		FVector FrictionalVelocity_c;

	UFUNCTION()
		void OnMessageReceived(const TArray<uint8>& Bytes, const FString& IPAddress);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arduino")
		bool bPedal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arduino")
		bool bWheel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class USIOJsonValue* JsonValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class USIOJsonObject* JsonObject;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle")
		bool bPrevious;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle")
		bool bIsWheelPassed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float TickCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float TickDeltaTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float PlayerRotatorRoll_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float PlayerRotatorPitch_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float PlayerRotatorYaw_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsBicycleStopped;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsWheelInitial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		bool bBicycleStopTrigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		FVector BicycleVelocity_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		bool bNotInAirTrigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		bool bInAirTrigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float InitialAirTime_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		ACharacter_Player* CharacterRef_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsBicycleSpawned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		FRotator InitialControllerRotation_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float TerminalAirTime_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float InAirDeltaTime_c;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bicycle Properties", meta = (AllowPrivateAccess = "true"))
		float TimeModuloRemainder_c;

	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = BicycleStaticMesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Bicycle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* Arrow1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* Arrow2;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* SeatPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arrow, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;


private:


};
