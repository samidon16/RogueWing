// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainGameHUD.h"
#include "UI/SAltitudeWidget.h"

AMainGameHUD::AMainGameHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void AMainGameHUD::ShowHUD()
{

	if (GEngine && GEngine->GameViewport)
	{
		AltitudeWidget = SNew(SAltitudeWidget)
			.OwningHUD(this);
		//.OnGetAltitude(FOnGetFloat::CreateUObject(PlayerPawn, &APlayerPawn::GetAltitude));

		GEngine->GameViewport->AddViewportWidgetContent(AltitudeWidget.ToSharedRef());
		UE_LOG(LogTemp, Warning, TEXT("Hello World"));
	}
}

void AMainGameHUD::HideHUD()
{
	if (GEngine && GEngine->GameViewport && AltitudeWidget.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(AltitudeWidget.ToSharedRef());
	}
}
