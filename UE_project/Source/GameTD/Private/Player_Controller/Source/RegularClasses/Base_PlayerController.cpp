// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Controller/Source/RegularClasses/PlayerController/Base_PlayerController.h"
#include "Player_Controller/Source/BaseClasses/PlayerController/Abstract_PlayerController.h"

void ABase_PlayerController::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}
void ABase_PlayerController::Move(FVector2D Value)
{
	APawn* ControlledPawn = GetPawn();
	if(!IsValid(ControlledPawn))
	{
		return;
	}
	FVector ViewLocation;
	FRotator ViewRotation;

	GetPlayerViewPoint(ViewLocation,ViewRotation);

	const FVector ForwardVector = ViewRotation.Vector();
	const FVector RightVector = FRotationMatrix(ViewRotation).GetScaledAxis(EAxis::Y);

	FVector Buffer = ForwardVector * Value.X + RightVector * Value.Y;
	Buffer.Z = 0;
	const FVector NewDirection = (Buffer).GetSafeNormal();
	
	ControlledPawn->AddMovementInput(NewDirection,1.0f);
}
void ABase_PlayerController::Build(float Cost)
{
	GEngine->AddOnScreenDebugMessage(54,2,FColor::Emerald,TEXT("Build new Tower"));
}

void ABase_PlayerController::LookAround(FVector2D Value)
{
	APawn* ControlledPawn = GetPawn();
	if(!IsValid(ControlledPawn))
	{
		return;
	}

	if(Value.X != 0.0f)
	{
		ControlledPawn->AddControllerYawInput(Value.X * GetMouseSensitivity());
	}

	if(Value.Y != 0.0f)
	{
		ControlledPawn->AddControllerPitchInput(Value.Y * GetMouseSensitivity());
	}

}

void ABase_PlayerController::LookUp(FVector2D Value)
{
	Super::LookUp(Value);
}

void ABase_PlayerController::SetMovementSpeed(float Speed)
{
	if(Speed == 0)
	{
		return;
	}
	this->MoveSpeed = Speed;
}

float ABase_PlayerController::GetMoveSpeed()
{
	return this->MoveSpeed;
}

void ABase_PlayerController::SetMouseSensitivity(float NewSensitivity)
{
	this->Sensitivity = NewSensitivity;
}

float ABase_PlayerController::GetMouseSensitivity()
{
	return this->Sensitivity;
}


void ABase_PlayerController::Jump()
{
}

void ABase_PlayerController::Shoot()
{
	GEngine->AddOnScreenDebugMessage(1,10,FColor::Black,TEXT("HelloDaer"),false);
	//Weapon.DoShoot();
}

void ABase_PlayerController::EventDie()
{
}

void ABase_PlayerController::EventLevelUp()
{
}

void ABase_PlayerController::GetWeapon()
{
}

void ABase_PlayerController::DropWeapon()
{
}
