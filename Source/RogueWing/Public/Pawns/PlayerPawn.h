// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlanePawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class ROGUEWING_API APlayerPawn : public APlanePawn
{
	GENERATED_BODY()

private:
    class UCameraComponent* Camera;

public:
    APlayerPawn();

    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;

    UFUNCTION()
    void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

    UFUNCTION()
    float GetAltitude() const;

};
