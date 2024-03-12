// Fill out your copyright notice in the Description page of Project Settings.


#include "SAltitudeWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SAltitudeWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = false;

	//OnGetAltitude = InArgs._OnGetAltitude;
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
						.Text(FText::FromString("Start Game"))
				]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

/*
int32 OnPaint(
	const FPaintArgs& Args,
	const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect,
	FSlateWindowElementList& OutDrawElements,
	int32 LayerId,
	const FWidgetStyle& InWidgetStyle,
	bool bParentEnabled
)
{
	return SCompoundWidget::OnPaint(AllottedGeometry, MyClippingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}
*/
