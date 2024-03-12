// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainLevelGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ROGUEWING_API AMainLevelGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	AMainLevelGameMode(const FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	int32 GetCurrentDay();

	UFUNCTION()
	void SetCurrentDay(int32 NewDay);

	UFUNCTION()
	int32 GetRemainingEnemies();

	UFUNCTION()
	void SetRemainingEnemies(int32 NewRemainingEnemies);

};
