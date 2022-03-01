// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGrid.h"
#include "Engine/Engine.h"
#include "Components/SizeBox.h"

void UPaintingGrid::AddPainting(int32 PaintingIndex, FString PaintingName)
{
	if (!PaintingGrid) return;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("												GRID NAME: %s"), *PaintingGrid->GetName()));
	UPaintingGridCard* NewWidget = CreateWidget<UPaintingGridCard>(GetWorld(), GridCardClass);
	if (!NewWidget) return;

	NewWidget->SetPaintingName(PaintingName);

	USizeBox* CardContrainer = Cast<USizeBox>(PaintingGrid->GetChildAt(PaintingIndex));
	if (!CardContrainer) return;
	CardContrainer->AddChild(NewWidget);

}

void UPaintingGrid::AddPaginationDot(bool Active)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("												GRID NAME: %s"), *PaintingGrid->GetName()));

	if (!PaginationDots) return;

	auto Dot = CreateWidget<UPaginationDot>(GetWorld(), PaginationDotClass);
	if (!Dot) return;

	PaginationDots->AddChild(Dot);
}

void UPaintingGrid::ClearPaintings()
{
	for (int32 i = 0; i < PaintingGrid->GetChildrenCount(); i++) {
		USizeBox* CardContrainer = Cast<USizeBox>(PaintingGrid->GetChildAt(i));
		if (!CardContrainer) continue;
		CardContrainer->ClearChildren();
	}
}
