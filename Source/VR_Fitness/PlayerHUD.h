// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine.h>
//#include <Widgets/Layout/SConstraintCanvas.h>
#include <VR_Fitness/SMapSelectingUI.h>
#include <VR_Fitness/SLoadingUSA.h>
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class VR_FITNESS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:

	void OpenMapSelectingUI();

	void CloseMapSelectingUI();

	void OpenLoadingUSA();

	void OpenLoadingAustralia();

	void OpenLoadingIceland();

	void CloseLoadingUSA();

	void CloseLoadingAustralia();

	void CloseLoadingIceland();

	void OpenUSA();

	void OpenAustralia();

	void OpenIceland();

	FLatentActionInfo LatentActionInfo_USA;
	FLatentActionInfo LatentActionInfo_Australia;
	FLatentActionInfo LatentActionInfo_Iceland;

	TArray<FName> USALevelLoadNameList_C;
	TArray<FName> AustraliaLevelLoadNameList_C;
	TArray<FName> IcelandLevelLoadNameList_C;

	FString LoadedLevelName_C;

protected:

	virtual void BeginPlay() override;

	TSharedPtr<class SMapSelectingUI> MapSelectingUI;
	TSharedPtr<class SWidget> WidgetContainer;

	TSharedPtr<class SLoadingUSA> LoadingUSA;
	//TSharedPtr<class SWidget> WidgetContainer;

private:



	
};
