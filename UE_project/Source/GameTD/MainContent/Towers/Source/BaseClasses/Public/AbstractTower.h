// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/TextRenderComponent.h>
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/Font.h" 

#include "../Public/AbstractProjectile.h"
#include "AbstractTower.generated.h"


UCLASS()
class AAbstractTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbstractTower();
	AAbstractTower(FString name, FString type, float DPS, float attackSpeed);
	void OnConstruction();

protected:
	float attackRadius_;
	float attackSpeed_;
	float DPS_;
	float moneyCost_;
	float timer_;
	FString statusEffect_;
	FString name_;
	FString type_;
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void setAttackRange(float newAttackRange);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void printTargetsQueue();
	void attackEnemy(FVector sendActor, FVector recieveActor);

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) ;
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	//UMaterial baseMaterial;
	USceneComponent* root_;

	AActor* activeTarget_;
	TArray<AActor*> targetsQueue_;


	UPROPERTY(EditAnywhere)
	UTextRenderComponent* infoText_;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* baseMesh_;
	UPROPERTY(EditAnywhere)
	USphereComponent* attackRadiusCollision_;
};


