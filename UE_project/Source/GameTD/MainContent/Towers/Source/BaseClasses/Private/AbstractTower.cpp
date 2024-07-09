// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AbstractTower.h"



// Sets default values
AAbstractTower::AAbstractTower() {
	PrimaryActorTick.bCanEverTick = true;

	//Default settings
	attackRadius_ = 100.0f;
	name_ = "Sample";
	type_ = "Range";
	DPS_ = 100.00f;
	attackSpeed_ = 20.00f;
	timer_ = 0.0f;
	activeTarget_ = nullptr;


	root_ = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root_;

	baseMesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	baseMesh_->SetupAttachment(root_);

	infoText_ = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Info Text"));
	infoText_->SetTextRenderColor(FColor::Black);
	infoText_->SetHorizontalAlignment(EHTA_Center);
	infoText_->SetVerticalAlignment(EVRTA_TextTop);
	infoText_->WorldSize *= 0.5;

	FString text = FString::Printf(TEXT("Name: %s\nType: %s\nDPS: %.1f\nAPS: %.1f"), *name_, *type_, DPS_, attackSpeed_);
	infoText_->SetText(FText::FromString(text));

	FVector TextOffset(0.0f, 0.0f, baseMesh_->Bounds.BoxExtent.Z + 140.0f);
	infoText_->AddRelativeLocation(TextOffset);
	infoText_->SetupAttachment(baseMesh_);


	attackRadiusCollision_ = CreateDefaultSubobject<USphereComponent>(TEXT("Attack radius"));
	attackRadiusCollision_->SetupAttachment(baseMesh_);
	attackRadiusCollision_->SetSphereRadius(attackRadius_);


	attackRadiusCollision_->OnComponentBeginOverlap.AddDynamic(this, &AAbstractTower::OnBeginOverlap);
	attackRadiusCollision_->OnComponentEndOverlap.AddDynamic(this, &AAbstractTower::OnEndOverlap);

};

AAbstractTower::AAbstractTower(FString name, FString type, float DPS, float attackSpeed) : name_(name), type_(type), DPS_(DPS), attackSpeed_(attackSpeed)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	root_ = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root_;

	baseMesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	baseMesh_->SetupAttachment(root_);

	infoText_ = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Info Text"));
	infoText_->SetTextRenderColor(FColor::Black);
	infoText_->SetHorizontalAlignment(EHTA_Center);
	infoText_->SetVerticalAlignment(EVRTA_TextTop);
	

	FString text = FString::Printf(TEXT("Name: %s\nType: %s\nDPS: %.1f\nAPS: %.1f"), *name, *type, DPS, attackSpeed);
	infoText_->SetText(FText::FromString(text));

	FVector TextOffset(0.0f, 0.0f, baseMesh_->Bounds.BoxExtent.Z + 130.0f);
	infoText_->AddRelativeLocation(TextOffset);

	infoText_->SetupAttachment(baseMesh_);

}

void AAbstractTower::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor->IsA<APawn>())
	{
		if (!targetsQueue_.Contains(OtherActor))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Pawn in radius"));
			targetsQueue_.Add(OtherActor);
			printTargetsQueue();
			if (!activeTarget_)
			{
				activeTarget_ = OtherActor;
			}
		}
	}
}

void AAbstractTower::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{
	if (OtherActor != this && OtherActor->IsA<APawn>())
	{
		targetsQueue_.Remove(OtherActor);
		printTargetsQueue();
		if (activeTarget_ == OtherActor)
		{
			if (targetsQueue_.Num() > 0)
			{
				activeTarget_ = targetsQueue_[0];
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Pawn out of radius"));
				activeTarget_ = nullptr;
			}
		}
	}
}

void AAbstractTower::printTargetsQueue()
{
	// Вывод содержимого targetsQueue_
	FString queueString = TEXT("Targets Queue: ");
	for (AActor* target : targetsQueue_)
	{
		queueString += target->GetName() + TEXT(",\n");
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, queueString);
}

void AAbstractTower::attackEnemy(FVector sendActor, FVector recieveActor){
	UWorld* World = GetWorld();
	AAbstractProjectile* projectile = World->SpawnActor<AAbstractProjectile>(AAbstractProjectile::StaticClass(), sendActor, FRotator::ZeroRotator);

	if (projectile)
	{
		projectile->currentPosition_ = sendActor;
		//projectile->endPosition_ = recieveActor;
		projectile->targetActor_ = activeTarget_;
	}
}

void AAbstractTower::OnConstruction() {

}

// Called when the game starts or when spawned
void AAbstractTower::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAbstractTower::setAttackRange(float newAttackRange){
	attackRadius_ = newAttackRange;
	attackRadiusCollision_->SetSphereRadius(attackRadius_);
}

// Called every frame
void AAbstractTower::Tick(float DeltaTime)
{
	
	timer_ += DeltaTime;

	Super::Tick(DeltaTime);


	if (timer_ >= 60 / attackSpeed_) {
		if (activeTarget_) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Attack"));
			attackEnemy(baseMesh_->GetComponentLocation(), activeTarget_->GetActorLocation());
		}
		
		timer_ = 0;
	}

}

