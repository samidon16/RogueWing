// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuHUD.h"
#include "UI/SMainMenuButtonWidget.h"
#include "Widgets/SViewport.h"
#include <Kismet/GameplayStatics.h>
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
	UGameplayStatics::OpenLevel(GetWorld(), "MainLevel");
	HideMenu();
}

void AMainMenuHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		StartGameButton = SNew(SMainMenuButtonWidget)
			.OwningHUD(this)
			.LabelText(NSLOCTEXT("Example", "OhNo", "Hello world"));
		GEngine->GameViewport->AddViewportWidgetContent(StartGameButton.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMainMenuHUD::HideMenu()
{
	if (GEngine && GEngine->GameViewport && StartGameButton.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(StartGameButton.ToSharedRef());
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = false;
		PlayerOwner->SetInputMode(FInputModeGameOnly());
	}
}
