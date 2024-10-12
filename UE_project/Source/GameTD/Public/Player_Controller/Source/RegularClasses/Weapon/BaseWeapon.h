// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player_Controller/Source/BaseClasses/Weapon/AbstractWeapon.h"
#include "BaseWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GAMETD_API ABaseWeapon : public AAbstractWeapon
{
	GENERATED_BODY()
	
public:
	void DoShoot() override;
};
