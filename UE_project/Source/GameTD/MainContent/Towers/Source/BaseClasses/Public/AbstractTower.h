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
	float AttackRadius;
	float AttackSpeed;
	float DamagePerSecond;
	float MoneyCost;
	float Timer;
	FString StatusEffect;
	FString Name;
	FString Type;
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SetAttackRange(float newAttackRange);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void PrintTargetsQueue();
	void AttackEnemy(FVector sendActor, FVector recieveActor);

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) ;
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	//UMaterial baseMaterial;
	USceneComponent* Root;

	AActor* ActiveTarget;
	TArray<AActor*> TargetsQueue;


	UPROPERTY(EditAnywhere)
	UTextRenderComponent* InfoText;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(EditAnywhere)
	USphereComponent* AttackRadiusCollision;
};


