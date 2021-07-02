// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VR_FITNESS_API SShowingLogoUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SShowingLogoUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class APlayerHUD>, OwningHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; };

	// The HUD that created this widget
	TWeakObjectPtr<class APlayerHUD> OwningHUD;


	//FReply OnPlayClicked() const;
	//FReply OnQuitClicked() const;

	

};
