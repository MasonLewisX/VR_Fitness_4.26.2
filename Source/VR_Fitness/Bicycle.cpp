// Fill out your copyright notice in the Description page of Project Settings.


#include "Bicycle.h"

#include "GameFramework/Controller.h"

// Sets default values
ABicycle::ABicycle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABicycle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABicycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABicycle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



}

