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
	AAbstract_PlayerController()
		:playerNick(TEXT("DefaultPlayer")),money(0),playerHitPoints(100.0f)
	{
		
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Stats")
	FString playerNick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Stats")
	float playerHitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Stats")
	int money;
protected:
	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void MoveForward(float Value);

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void MoveRight(float Value);

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void Jump();

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void Shoot();

	// Player events
	UFUNCTION(BlueprintCallable, Category="Player Events")
	virtual void EventDie();

	UFUNCTION(BlueprintCallable, Category="Player Events")
	virtual void EventLevelUp();

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void GetWeapon();

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void DropWeapon();
};
