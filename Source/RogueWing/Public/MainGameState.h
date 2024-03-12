// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MainGameState.generated.h"

/**
 * 
 */
UCLASS()
class ROGUEWING_API AMainGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMainGameState();

	UPROPERTY(EditAnywhere)
	int32 RemainingEnemies;

	UPROPERTY(EditAnywhere)
	int32 CurrentDay;
};
