// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGrid.h"
#include "Engine/Engine.h"

void UPaintingGrid::AddPainting()
{
	if (PaintingGrid) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("												GRID NAME: %s"), *PaintingGrid->GetName()));
	}
}
