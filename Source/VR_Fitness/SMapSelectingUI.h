// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine.h>
#include <VR_Fitness/PlayerHUD.h>
#include <VR_Fitness/PC_Player.h>
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VR_FITNESS_API SMapSelectingUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMapSelectingUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class APlayerHUD>, OwningHUD)
	SLATE_END_ARGS()


public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; };

	// The HUD that created this widget
	TWeakObjectPtr<class APlayerHUD> OwningHUD;

	UPROPERTY(BlueprintReadOnly, Category = "MapSelectingUI")
		APlayerController* PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "MapSelectingUI")
	FVector2D Resolution_FHD;

	FReply OnClickUSA() const;
	FReply OnClickAustralia() const;
	FReply OnClickIceland() const;
	FReply OnClickEXIT() const;

	
};
