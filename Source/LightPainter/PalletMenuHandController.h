// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"
#include "Components/WidgetComponent.h"
#include "PalletMenuHandController.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API APalletMenuHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	APalletMenuHandController();

private:
	//components
	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* PalletMenu;
	
};
