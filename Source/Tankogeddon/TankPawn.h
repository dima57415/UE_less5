// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MachinePawn.h"
#include "DamageTaker.h"
#include "TankPawn.generated.h"


class UStaticMeshComponent;
class ACannon;

UCLASS()
class TANKOGEDDON_API ATankPawn : public AMachinePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();

	virtual void Tick(float DeltaTime) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveAll(float DeltaTime);
	void RotateRight(float Value);

protected:
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Rotation")
	float TurretRotationInterpolationKey = 0.1f;


	UPROPERTY()
	class ATankPlayerController* TankController;

	float targetForwardAxisValue = 0.0f;
	float targetRightAxisValue = 0.0f;
	float targetRotationRight = 0.0f;
};
