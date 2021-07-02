// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine.h>
#include <VR_Fitness/PlayerHUD.h>
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VR_FITNESS_API SLoadingUSA : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLoadingUSA)
	{}
	//SLATE_ARGUMENT(TWeakObjectPtr<class APlayerHUD>, LoadingUSA_HUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; };

	// The HUD that created this widget
	//TWeakObjectPtr<class APlayerHUD> LoadingUSA_HUD;

};
