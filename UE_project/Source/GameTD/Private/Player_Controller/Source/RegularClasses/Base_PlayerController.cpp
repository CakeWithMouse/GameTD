// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Controller/Source/RegularClasses/PlayerController/Base_PlayerController.h"
#include "Player_Controller/Source/BaseClasses/PlayerController/Abstract_PlayerController.h"

ABase_PlayerController::ABase_PlayerController()
	: ::AAbstract_PlayerController(),CharacterType(TEXT("Name"))
{
}
