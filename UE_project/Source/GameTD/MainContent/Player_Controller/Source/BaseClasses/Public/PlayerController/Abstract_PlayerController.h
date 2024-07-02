// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Abstract_PlayerController.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GAMETD_API AAbstract_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAbstract_PlayerController(FString Name,float HP,int Money);

	FString PlayerNick;
	float PlayerHitPoints;
	int Money;
protected:
	virtual void MoveForward(const float Value){};
	virtual void MoveRight(const float Value){};
	virtual void Jump(){};
	virtual void Shoot(){};
	
	virtual void EventDie(){};
	virtual void EventLevelUp(){};
	virtual void GetWeapon(){};
	virtual void DropWeapon(){};
};
