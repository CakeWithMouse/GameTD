// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AbstractTower.h"



// Sets default values
AAbstractTower::AAbstractTower() {
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	baseMesh->SetupAttachment(Root);

	infoText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Info Text"));
	infoText->SetTextRenderColor(FColor::Black);
	infoText->SetHorizontalAlignment(EHTA_Center);
	infoText->SetVerticalAlignment(EVRTA_TextTop);

	FVector TextOffset(0.0f, 0.0f, baseMesh->Bounds.BoxExtent.Z + 130.0f);
	infoText->AddRelativeLocation(TextOffset);

	infoText->SetupAttachment(baseMesh);

};

AAbstractTower::AAbstractTower(FString name, FString type, double DPS, double attackSpeed) : name_(name), type_(type), DPS_(DPS), attackSpeed_(attackSpeed)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	baseMesh->SetupAttachment(Root);

	infoText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Info Text"));
	infoText->SetTextRenderColor(FColor::Black);
	infoText->SetHorizontalAlignment(EHTA_Center);
	infoText->SetVerticalAlignment(EVRTA_TextTop);
	

	FString text = FString::Printf(TEXT("Name: %s\nType: %s\nDPS: %.1f\nAPS: %.1f"), *name, *type, DPS, attackSpeed);
	infoText->SetText(FText::FromString(text));

	FVector TextOffset(0.0f, 0.0f, baseMesh->Bounds.BoxExtent.Z + 130.0f);
	infoText->AddRelativeLocation(TextOffset);

	infoText->SetupAttachment(baseMesh);

}

// Called when the game starts or when spawned
void AAbstractTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbstractTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

