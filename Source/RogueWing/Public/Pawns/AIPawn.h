// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlanePawn.h"
#include "AIPawn.generated.h"

UCLASS()
class ROGUEWING_API AAIPawn : public APlanePawn
{
	GENERATED_BODY()

private:
    class UCameraComponent* Camera;

public:
    AAIPawn();

    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

    UFUNCTION()
    void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

    UPROPERTY()
    double MaxRange;

};
