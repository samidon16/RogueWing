// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
DECLARE_DELEGATE_RetVal(float, FOnGetFloat)
class ROGUEWING_API SAltitudeWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAltitudeWidget)
		{} //
		SLATE_ARGUMENT(TWeakObjectPtr<class AMainGameHUD>, OwningHUD)
		//SLATE_ARGUMENT(FOnGetFloat, OnGetAltitude)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	/*
	virtual int32 OnPaint
	(
		const FPaintArgs& Args,
		const FGeometry& AllottedGeometry,
		const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements,
		int32 LayerId,
		const FWidgetStyle& InWidgetStyle,
		bool bParentEnabled
	) const;
	*/

protected:
	FOnGetFloat OnGetAltitude;

	TWeakObjectPtr<class AMainGameHUD> OwningHUD;
};
