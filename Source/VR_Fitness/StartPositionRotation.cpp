// Fill out your copyright notice in the Description page of Project Settings.


#include "StartPositionRotation.h"

// Sets default values
AStartPositionRotation::AStartPositionRotation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStartPositionRotation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStartPositionRotation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

