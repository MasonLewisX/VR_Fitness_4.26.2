// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Player.h"

// Sets default values
ACharacter_Player::ACharacter_Player()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionCharacter_c = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerCharacter"));
	MotionCharacter_c->AttachTo(RootComponent);
	MotionCharacter_c->SetVisibility(false);

	SpringArm_c = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm_c->AttachTo(MotionCharacter_c);

	CameraBasic_c = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraBasic"));
	CameraBasic_c->AttachTo(SpringArm_c);

	CameraThird_c = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraThird"));
	CameraThird_c->AttachTo(SpringArm_c);

}

// Called when the game starts or when spawned
void ACharacter_Player::BeginPlay()
{
	Super::BeginPlay();

	//UHeadMountedDisplayFunctionLibrary::GetHMDWornState()

	//switch (GEngine->XRSystem->GetHMDDevice()->GetHMDWornState())
	//{
	//case EHMDWornState::Worn:
	//	//UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Eye);
	//	
	//	break;

	//case EHMDWornState::NotWorn:
	//	//UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Eye);

	//	break;

	//case EHMDWornState::Unknown:
	//	//UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Eye);

	//	break;


	//default:
	//	//UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Eye);
	//	break;
	//}
		
}

// Called every frame
void ACharacter_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

