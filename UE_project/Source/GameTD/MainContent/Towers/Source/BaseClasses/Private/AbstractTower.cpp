// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AbstractTower.h"



// Sets default values
AAbstractTower::AAbstractTower() {
	PrimaryActorTick.bCanEverTick = true;

	//Default settings
	AttackRadius = 100.0f;
	Name = "Sample";
	Type = "Range";
	DamagePerSecond = 100.00f;
	AttackSpeed = 20.00f;
	Timer = 0.0f;
	ActiveTarget = nullptr;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BaseMesh->SetupAttachment(Root);

	InfoText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Info Text"));
	InfoText->SetTextRenderColor(FColor::Black);
	InfoText->SetHorizontalAlignment(EHTA_Center);
	InfoText->SetVerticalAlignment(EVRTA_TextTop);
	InfoText->WorldSize *= 0.5;

	FString text = FString::Printf(TEXT("Name: %s\nType: %s\nDPS: %.1f\nAPS: %.1f"), *Name, *Type, DamagePerSecond, AttackSpeed);
	InfoText->SetText(FText::FromString(text));

	FVector TextOffset(0.0f, 0.0f, BaseMesh->Bounds.BoxExtent.Z + 140.0f);
	InfoText->AddRelativeLocation(TextOffset);
	InfoText->SetupAttachment(BaseMesh);


	AttackRadiusCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Attack radius"));
	AttackRadiusCollision->SetupAttachment(BaseMesh);
	AttackRadiusCollision->SetSphereRadius(AttackRadius);


	AttackRadiusCollision->OnComponentBeginOverlap.AddDynamic(this, &AAbstractTower::OnBeginOverlap);
	AttackRadiusCollision->OnComponentEndOverlap.AddDynamic(this, &AAbstractTower::OnEndOverlap);

};

AAbstractTower::AAbstractTower(FString name, FString type, float DPS, float attackSpeed) : Name(name), Type(type), DamagePerSecond(DPS), AttackSpeed(attackSpeed)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BaseMesh->SetupAttachment(Root);

	InfoText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Info Text"));
	InfoText->SetTextRenderColor(FColor::Black);
	InfoText->SetHorizontalAlignment(EHTA_Center);
	InfoText->SetVerticalAlignment(EVRTA_TextTop);
	

	FString text = FString::Printf(TEXT("Name: %s\nType: %s\nDPS: %.1f\nAPS: %.1f"), *name, *type, DPS, attackSpeed);
	InfoText->SetText(FText::FromString(text));

	FVector TextOffset(0.0f, 0.0f, BaseMesh->Bounds.BoxExtent.Z + 130.0f);
	InfoText->AddRelativeLocation(TextOffset);

	InfoText->SetupAttachment(BaseMesh);

}

void AAbstractTower::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor->IsA<APawn>())
	{
		if (!TargetsQueue.Contains(OtherActor))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Pawn in radius"));
			TargetsQueue.Add(OtherActor);
			PrintTargetsQueue();
			if (!ActiveTarget)
			{
				ActiveTarget = OtherActor;
			}
		}
	}
}

void AAbstractTower::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{
	if (OtherActor != this && OtherActor->IsA<APawn>())
	{
		TargetsQueue.Remove(OtherActor);
		PrintTargetsQueue();
		if (ActiveTarget == OtherActor)
		{
			if (TargetsQueue.Num() > 0)
			{
				ActiveTarget = TargetsQueue[0];
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Pawn out of radius"));
				ActiveTarget = nullptr;
			}
		}
	}
}

void AAbstractTower::PrintTargetsQueue()
{
	// Вывод содержимого targetsQueue_
	FString QueueString = TEXT("Targets Queue: ");
	for (AActor* target : TargetsQueue)
	{
		QueueString += target->GetName() + TEXT(",\n");
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, QueueString);
}

void AAbstractTower::AttackEnemy(FVector sendActor, FVector recieveActor){
	UWorld* World = GetWorld();
	AAbstractProjectile* projectile = World->SpawnActor<AAbstractProjectile>(AAbstractProjectile::StaticClass(), sendActor, FRotator::ZeroRotator);

	if (projectile)
	{
		projectile->CurrentPosition = sendActor;
		//projectile->endPosition_ = recieveActor;
		projectile->TargetActor = ActiveTarget;
	}
}

void AAbstractTower::OnConstruction() {

}

// Called when the game starts or when spawned
void AAbstractTower::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAbstractTower::SetAttackRange(float newAttackRange){
	AttackRadius = newAttackRange;
	AttackRadiusCollision->SetSphereRadius(AttackRadius);
}

// Called every frame
void AAbstractTower::Tick(float DeltaTime)
{
	
	Timer += DeltaTime;

	Super::Tick(DeltaTime);


	if (Timer >= 60 / AttackSpeed) {
		if (ActiveTarget) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Attack"));
			AttackEnemy(BaseMesh->GetComponentLocation(), ActiveTarget->GetActorLocation());
		}
		
		Timer = 0;
	}

}

