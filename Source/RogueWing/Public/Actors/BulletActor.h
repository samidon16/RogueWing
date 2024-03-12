// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class ROGUEWING_API ABulletActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int32 NumbBounces;

public:	
	// Called every frame
	ABulletActor();
	virtual void Tick(float DeltaTime) override;

	class UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	class UProjectileMovementComponent* ProjectileComponent;

	const float LifeSpan = 2;

	const int32 MaxBounces = 1;

	const float Scale = 1.5;

};
