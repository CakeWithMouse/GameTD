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
	{
		
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Stats")
	FString PlayerNick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Stats")
	float PayerHitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Stats")
	int Money;
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float MoveSpeed;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float Sensitivity;
	
	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void Move(FVector2D Value){};

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void LookAround(FVector2D Value){};
	

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void Jump(){};

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void Shoot(){};

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void Build(float Cost){};

	// Player events
	UFUNCTION(BlueprintCallable, Category="Player Events")
	virtual void EventDie(){};

	UFUNCTION(BlueprintCallable, Category="Player Events")
	virtual void EventLevelUp(){};

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void GetWeapon(){};

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void DropWeapon(){};

	UFUNCTION(BlueprintCallable, Category="Player Settings")
	virtual void SetSensetive(float Sensitiv){};
	
	UFUNCTION(BlueprintCallable, Category="Player Settings")
	virtual void SetMovementSpeed(float Speed){};
};
