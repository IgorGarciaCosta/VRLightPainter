// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGrid.h"
#include "Engine/Engine.h"
#include "Components/SizeBox.h"

void UPaintingGrid::AddPainting()
{
	if (!PaintingGrid) return;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("												GRID NAME: %s"), *PaintingGrid->GetName()));
	UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), GridCardClass);
	if (!NewWidget) return;

	USizeBox* CardContrainer = Cast<USizeBox>(PaintingGrid->GetChildAt(0));
	if (!CardContrainer) return;
	CardContrainer->AddChild(NewWidget);

}
