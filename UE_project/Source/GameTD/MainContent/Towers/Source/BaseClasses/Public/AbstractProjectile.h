// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "AbstractProjectile.generated.h"



UCLASS()
class GAMETD_API AAbstractProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY()
	USceneComponent* Root;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseMesh;


	FVector CurrentPosition;
	FVector EndPosition;
	AActor* TargetActor;
	// Sets default values for this actor's properties
	AAbstractProjectile();
	AAbstractProjectile(FVector StartCoord, FVector EndCoord);


protected:
	float Timer;
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
