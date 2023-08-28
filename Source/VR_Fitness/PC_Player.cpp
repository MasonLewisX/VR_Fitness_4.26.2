// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_Player.h"

APC_Player::APC_Player()
{
	//m_ActorSpawnParameters.
	//m_UClass->

	//static ConstructorHelpers::FObjectFinder<UBlueprint> m_ObjectBluprint(TEXT("Blueprint'/Game/Blueprints/Bicycle_Main_BP.Bicycle_Main_BP_C'"));
	eventSpawnPlayer.AddDynamic(this, &APC_Player::SpawnPlayer_C);
	eventSetHandleInitial.AddDynamic(this, &APC_Player::SetHandleInitial_C);
	eventOpenUSA.AddDynamic(this, &APC_Player::OpenUSA_C);
	eventOpenAustralia.AddDynamic(this, &APC_Player::OpenAustralia_C);
	eventOpenIceland.AddDynamic(this, &APC_Player::OpenIceland_C);
	//bEnableMouseOverEvents = true;
	bEnableClickEvents = true;
	m_BicycleSpawnTransform.SetComponents(FQuat(0, 0, 0, 0), FVector(0, 0, 0), FVector(1, 1, 1));

	UDP_Handle_C = CreateDefaultSubobject<UUDPComponent>(TEXT("UDP"));
	UDP_Handle_C->OnReceivedBytes.AddDynamic(this, &APC_Player::OnReceivedBytes_Handle);
	UDP_Handle_C->Settings.ReceivePort = 3026;
	
	//eventSetPlayerPosition.AddDynamic(this, &APC_Player::SetPlayerPosition_C);
	
	bIsBicycleSpawned = false;

	HandleRotationDegree_c = 0.f;

}


void APC_Player::BeginPlay()
{
	Super::BeginPlay();

	//APlayerHUD* playerHUD = Cast<APlayerHUD>(this->GetHUD());

	//GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(playerHUD->WidgetContainer, SWeakWidget).PossiblyNullContent(playerHUD->MapSelectingUI.ToSharedRef()));

	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	//UKismetSystemLibrary::Delay(GetWorld(), 5.f, m_LatentActionInfo);

	//TSubclassOf<class AActor> m_Bicycle_Main_BP;

	//static ConstructorHelpers::FObjectFinder<UBlueprint> m_BluprintObject(TEXT("Blueprint'/Game/Blueprints/Bicycle_Main_BP'"));
	//static ConstructorHelpers::FObjectFinder<UBlueprint> m_BluprintObject(TEXT("/Game/Blueprints/Bicycle_Main_BP"));
	//EngineUtils::FindOrLoadAssetsByPath(TEXT("/Game/UI/Artwork/Weapons/ComboImages"), MeshAssets, EngineUtils::ATL_Regular);
	/*
	if (m_BluprintObject.Object)
	{
		m_Bicycle_Main_BP = (UClass*)m_BluprintObject.Object->GeneratedClass;
	}

	m_Bicycle_Main_BP.GetDefaultObject();
	Cast<AActor>(m_Bicycle_Main_BP.GetDefaultObject());
	//m_BicycleSpawnTransform.
	*/
	//GetWorld()->SpawnActor<AActor>(m_Bicycle_Main_BP.GetDefaultObject(), m_BicycleSpawnTransform, m_ActorSpawnParameters);






	}


void APC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}



void APC_Player::SpawnPlayer_C()
{

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), FoundedPlayerStarts);

	FActorSpawnParameters wofijew;
	
	SpawnActorLocation = FoundedPlayerStarts[0]->GetActorLocation();

	transform = UKismetMathLibrary::MakeTransform(FoundedPlayerStarts[0]->GetActorLocation(), FoundedPlayerStarts[0]->GetActorRotation()/*UKismetMathLibrary::MakeRotFromX(FoundedPlayerStarts[0]->GetActorLocation())*/, FVector(1.f, 1.f, 1.f));
	
	Bicycle_Main = this->GetWorld()->SpawnActor<ABicycle_Main>(ABicycle_Main::StaticClass(), transform, wofijew);
		//UWorld::SpawnActor<ABicycle_Main>(ABicycle_Main::StaticClass(), transform, wofijew);

	Bicycle_Main->SetActorLocation(SpawnActorLocation, false, 0, ETeleportType::None);

	Bicycle_Main->SpawnDefaultController();

	bIsBicycleSpawned = true;

	this->bShowMouseCursor = false;

	this->SetControlRotation(FoundedPlayerStarts[0]->GetActorRotation());

}


void APC_Player::OnReceivedBytes_Handle(const TArray<uint8>& Bytes, const FString& IPAddress)
{
	JsonValue = Cast<USIOJsonValue>(USIOJsonValue::ValueFromJsonString(this, UCUBlueprintLibrary::Conv_BytesToString(Bytes)));

	JsonObject = JsonValue->AsObject();

	if (JsonObject->GetNumberField("qx") && JsonObject->GetNumberField("qy") && JsonObject->GetNumberField("qz") && JsonObject->GetNumberField("qw"))
	{
		FQuat Quat_Handle = FQuat::FQuat(JsonObject->GetNumberField("qx"), JsonObject->GetNumberField("qy"), JsonObject->GetNumberField("qz"), JsonObject->GetNumberField("qw"));

		FRotator Rot_Handle = UKismetMathLibrary::Quat_Rotator(Quat_Handle);

		Handle_Yaw = Rot_Handle.Yaw;

	
		if (bIsBicycleSpawned)
		{
			HandleRotationDegree_c = (Handle_Yaw - InitialGyroRotation_c) * (-1.f);

			if (Bicycle_Main->bIsBicycleStopped)
			{
				CurrentHandleRotationDegree_c = Handle_Yaw;

				if (UKismetMathLibrary::Abs(CurrentHandleRotationDegree_c - PreviousHandleRotationDegree_c) > 0.15)
				{
					PreviousHandleRotationDegree_c = CurrentHandleRotationDegree_c;
					
					Bicycle_Main->BicycleRotation_c = UKismetMathLibrary::MakeRotator(0.f, 0.f, Bicycle_Main->GetActorRotation().Yaw + UKismetMathLibrary::Sin(HandleRotationDegree_c));

					Bicycle_Main->SetActorRotation(Bicycle_Main->BicycleRotation_c);
				}
			}
			else
			{
				Bicycle_Main->BicycleRotation_c = UKismetMathLibrary::MakeRotator(0.f, 0.f, Bicycle_Main->GetActorRotation().Yaw + UKismetMathLibrary::Sin(HandleRotationDegree_c));

				Bicycle_Main->SetActorRotation(Bicycle_Main->BicycleRotation_c);
			}

		}


	}
	
	
	//GEngine->AddOnScreenDebugMessage(-1, 0.002f, FColor::Red, UKismetStringLibrary::Conv_BoolToString(bWheel));

}



void APC_Player::SetHandleInitial_C()
{
	InitialGyroRotation_c = Handle_Yaw;

	bIsHandleInitialSet = true;

	RotationBicycleInitial = Bicycle_Main->GetActorRotation();

	//UGameplayStatics::GetAllActorsofClass(GetWorld(), )



}

void APC_Player::OpenUSA_C()
{
	//GEngine->GameViewport->AddViewportWidgetContent(;
	
	//m_LoadingUSA->CreateAccessibleWidget();

}

void APC_Player::OpenAustralia_C()
{

}

void APC_Player::OpenIceland_C()
{

}



/*
void APC_Player::SetPlayerPosition_C()
{
	UGameplayStatics::GetAllActorsOfClass(this->GetWorld(), );
}
*/