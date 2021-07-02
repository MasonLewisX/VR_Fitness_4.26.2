// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	MapSelectingUI = SNew(SMapSelectingUI).OwningHUD(this);

	this->OpenMapSelectingUI();

	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x3_y3"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x3_y2"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x3_y1"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x3_y0"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x2_y3"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x2_y2"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x2_y1"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x2_y0"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x1_y3"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x1_y2"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x1_y1"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x1_y0"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x0_y3"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x0_y2"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x0_y1"));
	USALevelLoadNameList_C.Add(FName::FName("Battle_Royale_Map_a_x0_y0"));
	USALevelLoadNameList_C.Add(FName::FName("BattleRoyale_Map_a"));

	AustraliaLevelLoadNameList_C.Add(FName::FName("RuralAustralia_Example_01"));

	IcelandLevelLoadNameList_C.Add(FName::FName("Showcase_snowy"));


	LoadedLevelName_C = TEXT("");

		//if (MapSelectingUI && WidgetContainer)
		//{
			
			//LoadingUSA = SNew(SLoadingUSA).LoadingUSA_HUD(this);

		//}

	
	
}


void APlayerHUD::OpenMapSelectingUI()
{
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget).PossiblyNullContent(MapSelectingUI.ToSharedRef()));
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
	}
}

void APlayerHUD::CloseMapSelectingUI()
{
	if (GEngine && GEngine->GameViewport && WidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());
	}
}


void APlayerHUD::OpenLoadingUSA()
{
	if (GEngine && GEngine->GameViewport)
	{
		this->CloseMapSelectingUI();
		this->OpenUSA();
	}
}

void APlayerHUD::OpenLoadingAustralia()
{
	if (GEngine && GEngine->GameViewport)
	{
		this->CloseMapSelectingUI();
		this->OpenAustralia();
	}
}

void APlayerHUD::OpenLoadingIceland()
{
	if (GEngine && GEngine->GameViewport)
	{
		this->CloseMapSelectingUI();
		this->OpenIceland();
	}
}

void APlayerHUD::CloseLoadingUSA()
{
	if (GEngine && GEngine->GameViewport)
	{

	}
}

void APlayerHUD::CloseLoadingAustralia()
{
	if (GEngine && GEngine->GameViewport)
	{

	}
}

void APlayerHUD::CloseLoadingIceland()
{
	if (GEngine && GEngine->GameViewport)
	{

	}
}

void APlayerHUD::OpenUSA()
{
	GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());
	for (int USALevelLoadIndex_C = 0; USALevelLoadIndex_C < USALevelLoadNameList_C.Num(); USALevelLoadIndex_C++)
	{//Cast<APC_Player>(UGameplayStatics::GetPlayerController())->
		UGameplayStatics::LoadStreamLevel(GetWorld(), USALevelLoadNameList_C[USALevelLoadIndex_C], true, false, LatentActionInfo_USA);
	}

	CloseLoadingUSA();

	//WidgetContainer 말고 MainPlayUI
	GEngine->GameViewport->AddViewportWidgetContent(WidgetContainer.ToSharedRef());

	Cast<APC_Player>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SpawnPlayer_C();

	LoadedLevelName_C = TEXT("USA");

	Cast<APC_Player>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SetHandleInitial_C();
	
}

void APlayerHUD::OpenAustralia()
{
	GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());

	UGameplayStatics::LoadStreamLevel(GetWorld(), AustraliaLevelLoadNameList_C[0], true, false, LatentActionInfo_Australia);


	CloseLoadingAustralia();

	//WidgetContainer 말고 MainPlayUI
	GEngine->GameViewport->AddViewportWidgetContent(WidgetContainer.ToSharedRef());

	Cast<APC_Player>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SpawnPlayer_C();

	LoadedLevelName_C = TEXT("Australia");

	Cast<APC_Player>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SetHandleInitial_C();
}

void APlayerHUD::OpenIceland()
{
	GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());

	UGameplayStatics::LoadStreamLevel(GetWorld(), IcelandLevelLoadNameList_C[0], true, false, LatentActionInfo_Iceland);


	CloseLoadingIceland();

	//WidgetContainer 말고 MainPlayUI
	GEngine->GameViewport->AddViewportWidgetContent(WidgetContainer.ToSharedRef());

	Cast<APC_Player>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SpawnPlayer_C();

	LoadedLevelName_C = TEXT("Iceland");

	Cast<APC_Player>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SetHandleInitial_C();
}