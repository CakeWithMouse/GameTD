// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player_Controller/Source/BaseClasses/PlayerController/Abstract_PlayerController.h"
#include "Player_Controller/Source/RegularClasses/Weapon/BaseWeapon.h"
#include "Base_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ABase_PlayerController : public AAbstract_PlayerController
{
	GENERATED_BODY()

public:
	void OnConstruction(const FTransform& Transform) override;
private:
	void SetSensetive(float Sensitiv) override;
	void SetMovementSpeed(float Speed) override;
public:
	//ABase_PlayerController(FString Name,float HP,int Money);
	ABase_PlayerController();

	FString CharacterType;


	void Move(FVector2D Value) override;

	void LookAround(FVector2D Value) override;

	void Build(float Cost) override;
	
	void Jump() override;

	void Shoot() override;

	// Player events
	void EventDie() override;

	void EventLevelUp() override;

	void GetWeapon() override;

	void DropWeapon() override;

	//ABaseWeapon Weapon;
};
