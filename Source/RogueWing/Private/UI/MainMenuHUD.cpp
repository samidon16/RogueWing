// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuHUD.h"
#include "UI/SMainMenuButtonWidget.h"
#include "PlayerPawn.h"
#include "Widgets/SViewport.h"
#include "MainGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

AMainMenuHUD::AMainMenuHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowMenu();
}

void AMainMenuHUD::OnStartButtonClicked()
{
	HideMenu();
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainMap"), false, "?Game=/Script/RogueWing.MainLevelGameMode");
}

void AMainMenuHUD::OnQuitButtonClicked()
{
	FGenericPlatformMisc::RequestExit(false);
}

void AMainMenuHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		MainMenu = SNew(SMainMenuButtonWidget)
			.OwningHUD(this);

		GEngine->GameViewport->AddViewportWidgetContent(MainMenu.ToSharedRef());
	}
}

void AMainMenuHUD::HideMenu()
{
	if (GEngine && GEngine->GameViewport && MainMenu.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MainMenu.ToSharedRef());
	}
}
