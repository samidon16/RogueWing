// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMainMenuButtonWidget.h"
#include "SlateOptMacros.h"
#include <Kismet/GameplayStatics.h>
#include "UI/MainMenuHUD.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMainMenuButtonWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	Text = InArgs._LabelText;
	OwningHUD = InArgs._OwningHUD;
	SetColorAndOpacity(FLinearColor::Red);
	ChildSlot
		[
			SNew(SBox)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
				SNew(SButton)
					.ContentPadding(20)
					.OnClicked(this, &SMainMenuButtonWidget::StartGame)
					.Text(FText::FromString("Start Game"))
				]
		];
}

void SMainMenuButtonWidget::SetText(FText NewText)
{
	Text = NewText;
	TextBlock->SetText(Text);
}

FReply SMainMenuButtonWidget::StartGame() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->OnStartButtonClicked();
	}
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
