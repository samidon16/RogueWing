// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlanePawn.generated.h"

UCLASS()
class ROGUEWING_API APlanePawn : public APawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float LastShotTime;
	float FirePeriod = .5;
	float MaxAngularVelocity = 100;

public:	
	APlanePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

	UPROPERTY()
	class UPlayerPawnMovementComponent* OurMovementComponent;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditAnywhere)
	float LinearDamping;

	UPROPERTY(EditAnywhere)
	float AngularDamping;

	void Accelerate(float Value);
	void Turn(float Value);
	void Shoot(float Value);
	void Boost(float Value);
	void Roll();

};
