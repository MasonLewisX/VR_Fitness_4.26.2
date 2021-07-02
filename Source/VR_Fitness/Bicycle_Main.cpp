// Fill out your copyright notice in the Description page of Project Settings.


#include "Bicycle_Main.h"
#include "GameFramework/Controller.h"

// Sets default values
ABicycle_Main::ABicycle_Main()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UDPcomp = CreateDefaultSubobject<UUDPComponent>(TEXT("UDP"));
	UDPcomp->OnReceivedBytes.AddDynamic(this, &ABicycle_Main::OnMessageReceived);
	UDPcomp->Settings.ReceivePort = 3025;
	bPedal = false;
	bWheel = false;
	bIsWheelPassed = false;
	bIsWheelInitial = false;
	bIsBicycleStopped = false;
	bIsBicycleSpawned = false;
	bBicycleStopTrigger = false;
	bNotInAirTrigger = false;
	bInAirTrigger = false;
	TotalMass_c = 0.f;
	NewWheelTime_c = 0.f;
	PreviousWheelTime_c = 0.f;
	DeltaWheelTime_c = 0.f;
	WheelDiameter_c = 700.f;
	AddedSpeed_c = 0.f;
	TickCount = 0.f;
	InitialAirTime_c = 0.f;
	TimeModuloRemainder_c = 0.f;
	CoefficientOfFriction_c = 0.4f;
	DirectionalVector_c = FVector(0.f, 0.f, 0.f);
	DirectionalVector_c = FVector(0.f, 0.f, 0.f);
	ForceOfFriction_c = FVector(0.f, 0.f, 0.f);
	FrictionalAcceleration_c = FVector(0.f, 0.f, 0.f);
	FrictionalVelocity_c = FVector(0.f, 0.f, 0.f);
	BicycleVelocity_c = FVector(0.f, 0.f, 0.f);
	TerminalAirTime_c = 0.f;
	InAirDeltaTime_c = 0.f;
	InitialControllerRotation_c = FRotator();
	
	//DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	//RootComponent = DefaultSceneRoot;
	
	Bicycle = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Bicycle"));
	Bicycle->AttachTo(GetMesh());
	
	Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow1"));
	Arrow1->AttachTo(Bicycle);

	Arrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow2"));
	Arrow2->AttachTo(Bicycle);
	
	SeatPosition = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Seat Position"));
	SeatPosition->AttachTo(Bicycle);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachTo(Bicycle);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachTo(SpringArm);
	Camera->bUsePawnControlRotation = true;
	
}

// Called when the game starts or when spawned
void ABicycle_Main::BeginPlay()
{
	Super::BeginPlay();
	
	bIsBicycleSpawned = true;
	
	TotalMass_c = this->GetCharacterMovement()->Mass + UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetCharacter()->GetCharacterMovement()->Mass;

	CharacterRef_c = Cast<ACharacter_Player>(UGameplayStatics::GetPlayerPawn(this->GetWorld(), 0));

	InitialControllerRotation_c = UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetControlRotation();

	this->GetCharacterMovement()->GroundFriction = 0.f;
	this->GetCharacterMovement()->BrakingFrictionFactor = 0.f;
		
}

// Called every frame
void ABicycle_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickDeltaTime = DeltaTime;
	//PrimaryActorTick.bCanEverTick = true;
	
	GEngine->AddOnScreenDebugMessage(-1, 0.002f, FColor::Orange, UKismetStringLibrary::Conv_FloatToString(UDPcomp->Settings.ReceivePort));

	

	// 일단 주석처리. 가속 시 무한대로 발산함. 그리고 마찰 브레이크 없음. 자전거 브레이크 시 감속 기능도 넣어야됨.
	/*
	CharacterRef_c->CameraBasic_c->SetRelativeRotation(FRotator::FRotator(UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetControlRotation().Pitch, (UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetControlRotation().Yaw - InitialControllerRotation_c.Yaw), 0.f));
	
	DirectionalVector_c = UKismetMathLibrary::GetDirectionUnitVector(Arrow1->K2_GetComponentLocation(), Arrow2->K2_GetComponentLocation());

	if (!bIsBicycleStopped)
	{
		this->GetMovementComponent()->Velocity = FVector((DirectionalVector_c.X, DirectionalVector_c.Y, (this->GetVelocity().Z + GetCharacterMovement()->GetGravityZ() * UGameplayStatics::GetWorldDeltaSeconds(this->GetWorld()))));

		if (this->GetMovementComponent()->IsFalling())
		{
			NormalForceScale_c = 0.f;

			if (bNotInAirTrigger)
			{
				bNotInAirTrigger = false;

				InitialAirTime_c = UKismetSystemLibrary::GetGameTimeInSeconds(this->GetWorld());

				bInAirTrigger = true;
			}
		}
		else 
		{
			NormalForceScale_c = UKismetMathLibrary::Abs(this->GetCharacterMovement()->GetGravityZ()) * this->GetCharacterMovement()->Mass + CharacterRef_c->GetCharacterMovement()->Mass;

			ScaleOfFriction_c = CoefficientOfFriction_c * NormalForceScale_c;
			ForceOfFriction_c = UKismetMathLibrary::MakeVector(ScaleOfFriction_c * DirectionalVector_c.X, ScaleOfFriction_c * DirectionalVector_c.Y, ScaleOfFriction_c * DirectionalVector_c.Z);
			FrictionalAcceleration_c = ForceOfFriction_c / TotalMass_c;
			FrictionalVelocity_c = FrictionalAcceleration_c / UGameplayStatics::GetWorldDeltaSeconds(this->GetWorld());

			this->LaunchCharacter(FrictionalVelocity_c, false, false);


			if (!bIsBicycleStopped)
			{
				if (this->GetVelocity().Size() <= 100.f)
				{
					this->GetMovementComponent()->Velocity = FVector::FVector(this->GetVelocity() + FrictionalVelocity_c);

					bIsBicycleStopped = true;
				}
				else
				{
					this->LaunchCharacter(FrictionalVelocity_c, false, false);
				}
			}

			if (bInAirTrigger)
			{
				bInAirTrigger = false;

				TerminalAirTime_c = UKismetSystemLibrary::GetGameTimeInSeconds(this->GetWorld());
				
				InAirDeltaTime_c = TerminalAirTime_c - InitialAirTime_c;

				bNotInAirTrigger = true;
			}

		}
	}

	CharacterRef_c->SetActorLocation(SeatPosition->K2_GetComponentLocation());
	CharacterRef_c->SetActorRotation(UKismetMathLibrary::MakeRotFromX(DirectionalVector_c));

	UKismetMathLibrary::FMod(UKismetSystemLibrary::GetGameTimeInSeconds(this->GetWorld()), 1.f, TimeModuloRemainder_c);
	if (TimeModuloRemainder_c <= UGameplayStatics::GetWorldDeltaSeconds(this->GetWorld()))
	{
		VelocityOfBicycle_c = this->GetVelocity().Size() * 0.01f * 0.001f * 3600.f;
	}
	*/

	/*    여기는 없애도 되는 코드
	if (this->GetCharacterMovement()->IsFalling())
	{
		NormalForceScale_c = 0.f;
	}
	else
	{
		NormalForceScale_c = UKismetMathLibrary::Abs(this->GetCharacterMovement()->GetGravityZ()) * this->GetCharacterMovement()->Mass + UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetCharacter()->GetCharacterMovement()->Mass;

		

		
	}*/
	/*
	//BicycleRotation_c = UKismetMathLibrary::MakeRotator(0.f, 0.f, UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetControlRotation().Yaw);
	UKismetMathLibrary::BreakRotator(UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetControlRotation(), PlayerRotatorRoll_c, PlayerRotatorPitch_c, PlayerRotatorYaw_c);
	BicycleRotation_c = UKismetMathLibrary::MakeRotator(0.f, 0.f, PlayerRotatorYaw_c);

	this->SetActorRotation(BicycleRotation_c, ETeleportType::None);
	UGameplayStatics::GetPlayerController(this->GetWorld(), 0)->GetCharacter()->SetActorLocation(SeatPosition->GetComponentLocation());
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if ((UKismetSystemLibrary::GetGameTimeInSeconds(this->GetWorld()) - PreviousWheelTime_c) / DeltaWheelTime_c > 3.f)
	{
		if (bBicycleStopTrigger)
		{
			bIsBicycleStopped = true;
			
			this->GetMovementComponent()->Velocity = FVector(0.f, 0.f, 0.f);

			this->LaunchCharacter(FVector(0.f, 0.f, 0.f), false, false);
		}
	}
	*/
}

// Called to bind functionality to input
void ABicycle_Main::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	
	//PlayerInputComponent->BindKey(FKey::, EInputEvent::IE_Pressed, this, &ABicycle_Main::OnMessageReceived);
	//InputComponent->Bind
}


void ABicycle_Main::OnMessageReceived(const TArray<uint8>& Bytes, const FString& IPAddress)
{
	//GEngine->AddOnScreenDebugMessage(2, 3.0f, FColor::Magenta, UKismetStringLibrary::Conv_ByteToString(Bytes));

	//TickCount += 1/(115200 * TickDeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, UKismetStringLibrary::Conv_FloatToString(TickCount));

	//if (TickCount >= 1)
	//{
	
		JsonValue = Cast<USIOJsonValue>(USIOJsonValue::ValueFromJsonString(this, UCUBlueprintLibrary::Conv_BytesToString(Bytes)));
	
		JsonObject = JsonValue->AsObject();
	
		if (!JsonObject->GetBoolField("Wheel") && !JsonObject->GetBoolField("Wheel") != bPrevious)
		{

			bPrevious = true;

			bIsWheelPassed = false;

			NewWheelTime_c = UKismetSystemLibrary::GetGameTimeInSeconds(this->GetWorld());
			DeltaWheelTime_c = NewWheelTime_c - PreviousWheelTime_c;
			PreviousWheelTime_c = NewWheelTime_c;

			bIsWheelPassed = false;

			bIsWheelInitial = false;

			if (!bIsWheelInitial)
			{
				AddedSpeed_c = WheelDiameter_c / 10 / 2 * UKismetMathLibrary::MultiplyByPi(2.f) / DeltaWheelTime_c;

				if (AddedSpeed_c > this->GetVelocity().Size())
				{
					AddedSpeed_c = AddedSpeed_c - this->GetVelocity().Size();
					BicycleVelocity_c = FVector(DirectionalVector_c.X * AddedSpeed_c, DirectionalVector_c.Y * AddedSpeed_c, DirectionalVector_c.Z * AddedSpeed_c);
					
					bIsBicycleStopped = false;
					this->LaunchCharacter(BicycleVelocity_c, false, false);
					
					bBicycleStopTrigger = true;
					
				}
				else
				{
					AddedSpeed_c = UKismetMathLibrary::Abs(AddedSpeed_c - this->GetVelocity().Size());
					BicycleVelocity_c = FVector((DirectionalVector_c * (-1.f)).X * AddedSpeed_c, (DirectionalVector_c * (-1.f)).Y * AddedSpeed_c, (DirectionalVector_c * (-1.f)).Z * AddedSpeed_c);

					bIsBicycleStopped = false;
					this->LaunchCharacter(BicycleVelocity_c, false, false);

					bBicycleStopTrigger = true;
					
				}
		
				//this->LaunchCharacter(FVector::FVector(AddedSpeed_c * DirectionalVector_c.X, AddedSpeed_c * DirectionalVector_c.Y, DirectionalVector_c.Z), false, false);
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, UKismetStringLibrary::Conv_BoolToString(!JsonObject->GetBoolField("Wheel")));
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, UKismetStringLibrary::Conv_FloatToString(GetVelocity().Size()));
						
			}

			if (JsonObject->GetBoolField("Wheel"))
			{
				bPrevious = false;
			}
	
			GEngine->AddOnScreenDebugMessage(-1, 0.002f, FColor::Red, UKismetStringLibrary::Conv_BoolToString(bWheel));

			TickCount = 0;
		
		}
	//}
		
}