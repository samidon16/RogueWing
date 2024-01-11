// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class ROGUEWING_API SMainMenuButtonWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuButtonWidget)
		{} //
		SLATE_ARGUMENT(FText, LabelText)
		SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwningHUD)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void SetText(FText NewText);

protected:
	FText Text;

	FSlateFontInfo Font;

	TSharedPtr<STextBlock> TextBlock;

	TWeakObjectPtr<class AMainMenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };

	FReply StartGame() const;
};
