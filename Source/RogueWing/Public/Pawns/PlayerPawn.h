// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PlayerPawn.generated.h"

UCLASS()
class ROGUEWING_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    APlayerPawn();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InInputComponent) override;

    UPROPERTY()
    class UPlayerPawnMovementComponent* OurMovementComponent;

    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* SkeletalMeshComponent;

    virtual UPawnMovementComponent* GetMovementComponent() const override;

    void Accelerate();
};
