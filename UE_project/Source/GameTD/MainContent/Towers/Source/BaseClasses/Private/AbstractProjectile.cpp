// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AbstractProjectile.h"

// Sets default values

AAbstractProjectile::AAbstractProjectile() {
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetStaticMesh(FindObject<UStaticMesh>(ANY_PACKAGE, TEXT("Sphere")));
	BaseMesh->SetRelativeScale3D(FVector(0.05, 0.05, 0.05));
	BaseMesh->SetupAttachment(Root);

	/*currentPosition_ = senderPosition_;
	endPosition_ = recieveActor_;*/

	Timer = 0.0f;
};

AAbstractProjectile::AAbstractProjectile(FVector startCoord, FVector endCoord)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetStaticMesh(FindObject<UStaticMesh>(ANY_PACKAGE, TEXT("Sphere")));
	BaseMesh->SetupAttachment(Root);

	/*currentPosition_ = startCoord;
	endPosition_ = endCoord;*/
	Timer = 0.0f;
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
	EndPosition = TargetActor->GetActorLocation();

	Timer += DeltaTime;
	if (Timer >= 0.0f) {
		//todo: Построить кривую движения

		if (CurrentPosition.X == EndPosition.X && CurrentPosition.Y == EndPosition.Y && CurrentPosition.Z == EndPosition.Z) {
			this->Destroy();
		}

		if (CurrentPosition.X != EndPosition.X) {
			if (CurrentPosition.X < EndPosition.X) {
				++CurrentPosition.X;
			}
			else {
				--CurrentPosition.X;
			}
		}
		
		if (CurrentPosition.Y != EndPosition.Y) {
			if (CurrentPosition.Y < EndPosition.Y) {
				++CurrentPosition.Y;
			}
			else {
				--CurrentPosition.Y;
			}
		}

		if (CurrentPosition.Z != EndPosition.Z) {
			if (CurrentPosition.Z < EndPosition.Z) {
				++CurrentPosition.Z;
			}
			else {
				--CurrentPosition.Z;
			}
		}
		
		Root->SetRelativeLocation(CurrentPosition);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("X Coord: %f"), currentPosition_.X));
		Timer = 0;
	}


}


