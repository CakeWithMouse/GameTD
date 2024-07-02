// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/TextRenderComponent.h>
#include "Components/InstancedStaticMeshComponent.h"
#include "AbstractTower.generated.h"

UCLASS()
class AAbstractTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbstractTower();
	AAbstractTower(FString name, FString type, double DPS, double attackSpeed);

protected:
	double attackRange_;
	double attackSpeed_;
	double DPS_;
	double moneyCost_;
	FString statusEffect_;
	FString name_;
	FString type_;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	//UMaterial baseMaterial;
	USceneComponent* Root;
	UTextRenderComponent* infoText;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* baseMesh;
};
