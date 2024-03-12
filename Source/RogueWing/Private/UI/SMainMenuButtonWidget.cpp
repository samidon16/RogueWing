// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMainMenuButtonWidget.h"
#include "SlateOptMacros.h"
#include <Kismet/GameplayStatics.h>
#include "UI/MainMenuHUD.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMainMenuButtonWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	StartText = FText::FromString("Start Game");
	QuitText = FText::FromString("Quit Game");
	OwningHUD = InArgs._OwningHUD;
	SetColorAndOpacity(FLinearColor::Red);

	ChildSlot
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Bottom)
				[
				SNew(SButton)
					.ContentPadding(20)
					.OnClicked(this, &SMainMenuButtonWidget::StartGame)
					.Text(StartText)
				]
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				[
				SNew(SButton)
					.ContentPadding(20)
					.OnClicked(this, &SMainMenuButtonWidget::QuitGame)
					.Text(QuitText)
				]
		];
}

FReply SMainMenuButtonWidget::StartGame() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->OnStartButtonClicked();
	}
	return FReply::Handled();
}

FReply SMainMenuButtonWidget::QuitGame() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->OnQuitButtonClicked();
	}
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
