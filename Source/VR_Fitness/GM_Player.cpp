// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Player.h"

AGM_Player::AGM_Player()
{
	// Set Default pawn class to our Blueprint Character
	static ConstructorHelpers::FClassFinder<APawn> PlayerCharacter_Finder(TEXT("/Game/Blueprints/BP_MotionCharacter"));
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerController_Finder(TEXT("/Game/Blueprints/PC_Player_BP"));
	
	if (PlayerCharacter_Finder.Class != NULL)
	{
		DefaultPawnClass = PlayerCharacter_Finder.Class;
	}

	if (PlayerController_Finder.Class != NULL)
	{
		PlayerControllerClass = PlayerController_Finder.Class;//APC_Player::StaticClass();
	}
	
	if (APlayerHUD::StaticClass() != NULL)
	{
		HUDClass = APlayerHUD::StaticClass();
	}
	
}