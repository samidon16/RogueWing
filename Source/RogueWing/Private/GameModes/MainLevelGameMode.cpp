// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevelGameMode.h"
#include "MainMenuHUD.h"
#include "Camera/CameraComponent.h"
#include "MainPlayerController.h"
#include "GameFramework/PlayerStart.h"
#include "PlayerPawn.h"
#include "AIPawn.h"
#include "DomeActor.h"
#include "OceanActor.h"
#include "MainGameState.h"
#include "Kismet/GameplayStatics.h"
#include "math.h"
#include "MainGameHUD.h"

AMainLevelGameMode::AMainLevelGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = AMainPlayerController::StaticClass();
	DefaultPawnClass = APlayerPawn::StaticClass();
	GameStateClass = AMainGameState::StaticClass();
	HUDClass = AMainGameHUD::StaticClass();
}

void AMainLevelGameMode::BeginPlay()
{
	Super::BeginPlay();
	GEngine->GameViewport->GetWorld()->SpawnActor<ADomeActor>(FVector(0, 0, 0), FRotator(0, 0, 0));
	GEngine->GameViewport->GetWorld()->SpawnActor<AOceanActor>(FVector(0, 0, 0), FRotator(0, 0, 0));

	SetCurrentDay(1);
}

int32 AMainLevelGameMode::GetCurrentDay()
{
	return GetGameState<AMainGameState>()->CurrentDay;
}

void AMainLevelGameMode::SetCurrentDay(int32 NewDay)
{
	GetGameState<AMainGameState>()->CurrentDay = NewDay;
	SetRemainingEnemies(NewDay);
	int32 EnemieCount = GetRemainingEnemies();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GEngine->GameViewport->GetWorld(), 0);
	if (PlayerPawn)
	{
		for (int i = 0; i < EnemieCount; i++)
		{
			FVector PlayerLocation = PlayerPawn->GetActorLocation();
			if (i % 2 == 0)
			{
				GEngine->GameViewport->GetWorld()->SpawnActor<AAIPawn>(FVector(0, PlayerLocation.Y - 10000 - i * 1000, PlayerLocation.Z + i * 1000), FRotator(0, 0, 0));
			}
			else
			{
				GEngine->GameViewport->GetWorld()->SpawnActor<AAIPawn>(FVector(0, PlayerLocation.Y + 10000 + i * 1000, PlayerLocation.Z + 4000 + i * 1000), FRotator(0, 0, 0));
			}
		}
	}
}

int32 AMainLevelGameMode::GetRemainingEnemies()
{
	return GetGameState<AMainGameState>()->RemainingEnemies;
}

void AMainLevelGameMode::SetRemainingEnemies(int32 NewRemainingEnemies)
{
	GetGameState<AMainGameState>()->RemainingEnemies = NewRemainingEnemies;

	if (NewRemainingEnemies <= 0)
	{
		SetCurrentDay(GetCurrentDay() + 1);
	}
}

