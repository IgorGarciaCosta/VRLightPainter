// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "PaintingGridCard.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UPaintingGridCard : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetPaintingName(FString PaintingName);

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UTextBlock* SlotName;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UButton* CardButton;


private:
	UFUNCTION()
		void CardButtonClicked();


	//state
	FString PaintingName;
	
};
