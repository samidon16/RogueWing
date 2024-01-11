// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class ROGUEWING_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMainMenuHUD(const FObjectInitializer& ObjectInitializer);
	void OnStartButtonClicked();
	void ShowMenu();
	void HideMenu();
protected:
	virtual void BeginPlay() override;

	TSharedPtr<class SMainMenuButtonWidget> StartGameButton;
};