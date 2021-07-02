// Fill out your copyright notice in the Description page of Project Settings.


#include "SMapSelectingUI.h"
#include "SlateOptMacros.h"

//#define LOCTEXT_NAMESPACE "MainMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMapSelectingUI::Construct(const FArguments& InArgs)
{
	
	OwningHUD = InArgs._OwningHUD;
	//const FText TitleText = LOCTEXT("aoifjeiofjwiofj");
	Resolution_FHD = FVector2D::FVector2D(1920.0, 1080.0);
	PlayerController = OwningHUD->PlayerOwner;

	
	FString ImagePath_Str_USA = FPaths::ProjectContentDir() / TEXT("UMG/MapLoading/USA/T_MainMenuScreen.jpg");
	FString ImagePath_Str_Australia = FPaths::ProjectContentDir() / TEXT("UMG/MapLoading/Australia/MapSelect_Australia.uasset");
	FString ImagePath_Str_Iceland = FPaths::ProjectContentDir() / TEXT("UMG/MapLoading/Iceland/MapSelect_Snowy.uasset");

	FName ImagePath_USA = FName(*ImagePath_Str_USA);
	FName ImagePath_Australia = FName(*ImagePath_Str_Australia);
	FName ImagePath_Iceland = FName(*ImagePath_Str_Iceland);
	
	ChildSlot
		[
			// Populate the widget
			SNew(SCanvas)
				+ SCanvas::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Size(Resolution_FHD)
				[
					SNew(SImage).ColorAndOpacity(FColor::Black)
					//SNew(STextBlock)
					//.Text("fjioewjfiowfiowfj")
				]

				+ SCanvas::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				/*.Position(FVector2D::FVector2D(-675.779968, -202.4216))
				.Size(FVector2D::FVector2D(1351.559937, 404.843201))*/
					.Position(FVector2D::FVector2D(Resolution_FHD.X/2, Resolution_FHD.Y/2))
					.Size(FVector2D::FVector2D(1351.559937f, 404.843201f))
				[		
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.FillHeight(0.2f)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.FillWidth(1.f)
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.FillWidth(1.f)
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(STextBlock)
								//.ShadowColorAndOpacity(FLinearColor::Black)
								.Justification(ETextJustify::Center)
								.ColorAndOpacity(FLinearColor::White)
								//.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo(GEngine->GetLargeFont(), 34))
								.Font(FSlateFontInfo(GEngine->GetLargeFont(), 36))
								.Text(FText::FromString(FString("USA")))
							]
							
							+ SHorizontalBox::Slot()
							.FillWidth(1.f)
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(STextBlock)
								.Justification(ETextJustify::Center)
								//.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::White)
								//.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo(GEngine->GetLargeFont(), 34))
								.Text(FText::FromString(FString("Australia")))
							]

							+ SHorizontalBox::Slot()
							.FillWidth(1.f)
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(STextBlock)
								.Justification(ETextJustify::Center)
								//.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::White)
								//.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo(GEngine->GetLargeFont(), 34))
								.Text(FText::FromString(FString("Iceland")))
							]
						]
					]

					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillHeight(1.f)
						[
							SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
									[
										SNew(SButton)
											.HAlign(HAlign_Fill)
											.VAlign(VAlign_Fill)
											.OnClicked(this, &SMapSelectingUI::OnClickUSA)
											[
												SNew(SImage).Image(new FSlateImageBrush(ImagePath_USA, FVector2D(128, 128)))
											]
									]

								+ SHorizontalBox::Slot()
									[
										SNew(SButton)
											.HAlign(HAlign_Fill)
											.VAlign(VAlign_Fill)
											.OnClicked(this, &SMapSelectingUI::OnClickAustralia)
											[
												SNew(SImage).Image(new FSlateImageBrush(ImagePath_Australia, FVector2D(128, 128)))
											]
									]

								+ SHorizontalBox::Slot()
									[
										SNew(SButton)
											.HAlign(HAlign_Fill)
											.VAlign(VAlign_Fill)
											.OnClicked(this, &SMapSelectingUI::OnClickIceland)
											[
												SNew(SImage).Image(new FSlateImageBrush(ImagePath_Iceland, FVector2D(128, 128)))
											]
									]
								
						]
					
				]

				+ SCanvas::Slot()
					.Position(FVector2D::FVector2D(1624.f, 956.f))
					.Size(FVector2D::FVector2D(232.132126f, 84.054054f))
					[
						SNew(SButton)//.Content()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.OnClicked(this, &SMapSelectingUI::OnClickEXIT)
						[
							SNew(STextBlock)
							//.ShadowColorAndOpacity(FLinearColor::Black)
							.Justification(ETextJustify::Center)
							.ColorAndOpacity(FLinearColor::Black)
							//.ShadowOffset(FIntPoint(-1, 1))
							.Font(FSlateFontInfo(GEngine->GetLargeFont()/*"Roboto"*/, 34))
							.Text(FText::FromString(FString("EXIT")))
						]
						
					
					]
						
		
		];
	
}


FReply SMapSelectingUI::OnClickUSA() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->CloseMapSelectingUI();
		OwningHUD->OpenLoadingUSA();
	}

	return FReply::Handled();
}

FReply SMapSelectingUI::OnClickAustralia() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->CloseMapSelectingUI();
		OwningHUD->OpenLoadingAustralia();
	}

	return FReply::Handled();
}

FReply SMapSelectingUI::OnClickIceland() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->CloseMapSelectingUI();
		OwningHUD->OpenLoadingIceland();
	}

	return FReply::Handled();
}

FReply SMapSelectingUI::OnClickEXIT() const
{
	UKismetSystemLibrary::QuitGame(PlayerController->GetWorld(), PlayerController, EQuitPreference::Quit, false);

	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

//#undef LOCTEXT_NAMESPACE