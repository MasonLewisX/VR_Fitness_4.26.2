// Fill out your copyright notice in the Description page of Project Settings.


#include "Rowboat_Main.h"

// Sets default values
ARowboat_Main::ARowboat_Main()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARowboat_Main::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARowboat_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARowboat_Main::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

