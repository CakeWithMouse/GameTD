// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AbstractProjectile.h"

// Sets default values

AAbstractProjectile::AAbstractProjectile() {
	PrimaryActorTick.bCanEverTick = true;

	root_ = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root_;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	baseMesh->SetStaticMesh(FindObject<UStaticMesh>(ANY_PACKAGE, TEXT("Sphere")));
	baseMesh->SetRelativeScale3D(FVector(0.05, 0.05, 0.05));
	baseMesh->SetupAttachment(root_);

	/*currentPosition_ = senderPosition_;
	endPosition_ = recieveActor_;*/

	timer_ = 0.0f;
};

AAbstractProjectile::AAbstractProjectile(FVector startCoord, FVector endCoord)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root_ = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root_;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	baseMesh->SetStaticMesh(FindObject<UStaticMesh>(ANY_PACKAGE, TEXT("Sphere")));
	baseMesh->SetupAttachment(root_);

	/*currentPosition_ = startCoord;
	endPosition_ = endCoord;*/
	timer_ = 0.0f;
}

// Called when the game starts or when spawned
void AAbstractProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbstractProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	endPosition_ = targetActor_->GetActorLocation();

	timer_ += DeltaTime;
	if (timer_ >= 0.0f) {
		//todo: Построить кривую движения

		if (currentPosition_.X == endPosition_.X && currentPosition_.Y == endPosition_.Y && currentPosition_.Z == endPosition_.Z) {
			this->Destroy();
		}

		if (currentPosition_.X != endPosition_.X) {
			if (currentPosition_.X < endPosition_.X) {
				currentPosition_.X++;
			}
			else {
				currentPosition_.X--;
			}
		}
		
		if (currentPosition_.Y != endPosition_.Y) {
			if (currentPosition_.Y < endPosition_.Y) {
				currentPosition_.Y++;
			}
			else {
				currentPosition_.Y--;
			}
		}

		if (currentPosition_.Z != endPosition_.Z) {
			if (currentPosition_.Z < endPosition_.Z) {
				currentPosition_.Z++;
			}
			else {
				currentPosition_.Z--;
			}
		}
		
		root_->SetRelativeLocation(currentPosition_);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("X Coord: %f"), currentPosition_.X));
		timer_ = 0;
	}


}


