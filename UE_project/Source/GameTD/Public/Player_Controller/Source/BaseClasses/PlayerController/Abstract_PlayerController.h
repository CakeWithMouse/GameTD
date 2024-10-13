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
	
protected:
	UPROPERTY(EditAnywhere, Category="Player|Stats")
	float PayerHitPoints;

	UPROPERTY(EditAnywhere, Category="Player|Stats")
	float PayerMaxHitPoints;

	UPROPERTY(EditAnywhere, Category="Player|Stats")
	int Money;

	UPROPERTY(EditAnywhere, Category="Player|Stats")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, Category="Player|Stats")
	float Sensitivity;

	UPROPERTY(EditAnywhere, Category="Player|Stats")
	float BaseDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player|Stats")
	FString PlayerNick;

public:
	//Player Reduce Stats
	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void ReduceMoney(float Value){};
	
	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void ReduceHitPoints(float Value){};
	
	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void ReduceMoveSpeed(float Value){};
	
	//Player Add Stats
	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void AddMoney(float Value){};
	
	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void AddMoveSpeed(float Value){};

	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void AddHitPoints(float Value){};
	
	//Player Set Stats
	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void SetMovementSpeed(float Value){};
	
	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void SetMoney(float Value){};

	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void SetPayerHitPoints(float Value){};

	UFUNCTION(BlueprintCallable, Category="Player|Stats")
	virtual void SetHitPoints(FVector2D Value){};

	//Player Actions
	UFUNCTION(BlueprintCallable, Category="Player|Actions")
	virtual void LookAround(FVector2D Value){};

	UFUNCTION(BlueprintCallable, Category="Player|Actions")
	virtual void LookUp(FVector2D Value){};

	UFUNCTION(BlueprintCallable, Category="Player Actions")
	virtual void Move(FVector2D Value){};
	
	UFUNCTION(BlueprintCallable, Category="Player|Actions")
	virtual void Jump(){};

	UFUNCTION(BlueprintCallable, Category="Player|Actions")
	virtual void Shoot(){};

	UFUNCTION(BlueprintCallable, Category="Player|Actions")
	virtual void Build(float Cost){};

	UFUNCTION(BlueprintCallable, Category="Player|Actions")
	virtual void GetWeapon(){};

	UFUNCTION(BlueprintCallable, Category="Player|Actions")
	virtual void DropWeapon(){};

	// Player events
	UFUNCTION(BlueprintCallable, Category="Player|Events")
	virtual void EventDie(){};

	UFUNCTION(BlueprintCallable, Category="Player|Events")
	virtual void EventLevelUp(){};

	UFUNCTION(BlueprintCallable, Category="Player|Events")
	virtual void GetDamage(){};

	UFUNCTION(BlueprintCallable, Category="Player|Events")
	virtual void GetHealing(){};
	
	// Player Settings
	UFUNCTION(BlueprintCallable, Category="Player|Settings")
	virtual void SetMouseSensitivity(float NewSensitivity){};

	UFUNCTION(BlueprintCallable, Category="Player|Settings")
	virtual float GetMouseSensitivity(){return 0.0f;};

	UFUNCTION(BlueprintCallable, Category="Player|Settings")
	virtual float GetMoveSpeed(){return 0.0f;};
};
