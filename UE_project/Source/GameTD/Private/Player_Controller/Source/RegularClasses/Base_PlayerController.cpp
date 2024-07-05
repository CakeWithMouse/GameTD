// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Controller/Source/RegularClasses/PlayerController/Base_PlayerController.h"
#include "Player_Controller/Source/BaseClasses/PlayerController/Abstract_PlayerController.h"

void ABase_PlayerController::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

ABase_PlayerController::ABase_PlayerController()
	: ::AAbstract_PlayerController(), CharacterType(TEXT("Name"))
{
	//'Weapon = NewObject<ABaseWeapon>();
}
void ABase_PlayerController::Move(FVector2D Value)
{
	APawn* ControlledPawn = GetPawn();
	if(!IsValid(ControlledPawn))
	{
		return;
	}

	if(Value.X != 0.0f)
	{
		ControlledPawn->AddMovementInput(FVector::ForwardVector,Value.X * MoveSpeed);
	}

	if(Value.Y != 0.0f)
	{
		ControlledPawn->AddMovementInput(FVector::RightVector,Value.Y * MoveSpeed);
	}
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
		ControlledPawn->AddControllerYawInput(Value.X * Sensitivity);
	}

	if(Value.Y != 0.0f)
	{
		ControlledPawn->AddControllerPitchInput(Value.Y * Sensitivity);
	}

}

void ABase_PlayerController::SetSensetive(float Sensitiv)
{
	if(Sensitiv == 0)
	{
		return;
	}
	this->Sensitivity = Sensitiv;
}
void ABase_PlayerController::SetMovementSpeed(float Speed)
{
	if(Speed == 0)
	{
		return;
	}
	this->MoveSpeed = Speed;
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
