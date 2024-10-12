// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Controller/Source/BaseClasses/Weapon/AbstractWeapon.h"

// Sets default values
AAbstractWeapon::AAbstractWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbstractWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbstractWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

