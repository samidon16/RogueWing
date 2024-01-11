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
	
public:
	AMainLevelGameMode(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
};
