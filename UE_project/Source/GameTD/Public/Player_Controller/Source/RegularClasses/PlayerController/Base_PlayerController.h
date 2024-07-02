// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameTD/MainContent/Player_Controller/Source/BaseClasses/Public/PlayerController/Abstract_PlayerController.h"
#include "Base_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ABase_PlayerController : public AAbstract_PlayerController
{
	GENERATED_BODY()
public:
	//ABase_PlayerController(FString Name,float HP,int Money);
	ABase_PlayerController();
	
	FString CharacterType;
	
};



