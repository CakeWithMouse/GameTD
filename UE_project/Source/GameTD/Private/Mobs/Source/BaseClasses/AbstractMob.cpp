
// Fill out your copyright notice in the Description page of Project Settings.

#include "Mobs/Source/BaseClasses/AbstractMob.h"

// Sets default values
AAbstractMob::AAbstractMob()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//GEngine->AddOnScreenDebugMessage(1,15,FColor::Black,TEXT("HI! I am Base"));
}

// Called when the game starts or when spawned
void AAbstractMob::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbstractMob::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAbstractMob::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

