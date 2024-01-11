// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/MainMenuGameMode.h"
#include "UI/MainMenuHUD.h"
#include "Pawns/MainMenuPawn.h"
#include "Camera/CameraComponent.h"
#include "MainPlayerController.h"

AMainMenuGameMode::AMainMenuGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DefaultPawnClass = AMainMenuPawn::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
	HUDClass = AMainMenuHUD::StaticClass();
}

void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
}

