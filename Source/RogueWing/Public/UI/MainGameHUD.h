// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class ROGUEWING_API AMainGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMainGameHUD(const FObjectInitializer& ObjectInitializer);
	void ShowHUD();
	void HideHUD();
protected:
	TSharedPtr<class SAltitudeWidget> AltitudeWidget;
};
