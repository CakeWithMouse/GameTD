// Fill out your copyright notice in the Description page of Project Settings.

#include "GameTD/MainContent/Player_Controller/Source/BaseClasses/Public/PlayerController/Abstract_PlayerController.h"



AAbstract_PlayerController::AAbstract_PlayerController(FString Name,float HP,int StartMoney)
	:PlayerNick(Name),Money(StartMoney),PlayerHitPoints(HP)
{
	
}