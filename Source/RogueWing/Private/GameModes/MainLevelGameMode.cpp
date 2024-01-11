// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/MainLevelGameMode.h"
#include "UI/MainMenuHUD.h"
#include "Pawns/PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "MainPlayerController.h"

AMainLevelGameMode::AMainLevelGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DefaultPawnClass = APlayerPawn::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
	//HUDClass = AMainMenuHUD::StaticClass();
}

void AMainLevelGameMode::BeginPlay()
{
	Super::BeginPlay();
}

