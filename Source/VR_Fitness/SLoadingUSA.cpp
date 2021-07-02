// Fill out your copyright notice in the Description page of Project Settings.


#include "SLoadingUSA.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLoadingUSA::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		// Populate the widget
		SNew(SCanvas)
		+ SCanvas::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		//.Size(Resolution_FHD)
		[
			SNew(SImage).ColorAndOpacity(FColor::Black)
			//SNew(STextBlock)
			//.Text("fjioewjfiowfiowfj")
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
