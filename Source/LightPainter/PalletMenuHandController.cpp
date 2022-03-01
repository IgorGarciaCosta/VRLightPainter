// Fill out your copyright notice in the Description page of Project Settings.


#include "PalletMenuHandController.h"

APalletMenuHandController::APalletMenuHandController()
{
	PalletMenu = CreateDefaultSubobject<UWidgetComponent>("PalletMenu");
	PalletMenu->SetupAttachment(GetRootComponent());
}
