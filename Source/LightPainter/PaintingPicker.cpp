// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingPicker.h"
#include "PaintingGrid.h"
#include "ActionBar.h"
#include "Engine/Engine.h"
#include "PainterSaveGame.h"
#include "PainterSaveGameIndex.h"

// Sets default values
APaintingPicker::APaintingPicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>("PaintingGrid");
	PaintingGrid->SetupAttachment(GetRootComponent());
	ActionBar = CreateDefaultSubobject<UWidgetComponent>("ActionBar");
	ActionBar->SetupAttachment(GetRootComponent());
}

void APaintingPicker::AddPainting()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "------------------AddPainting");
	UPainterSaveGame::Create();

	Refresh();
}

void APaintingPicker::ToggleDeleteMode()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "------------------ToggleDeleteMode");
	if (!GetPaintingGrid()) return;
	GetPaintingGrid()->ClearPaintings();
}

void APaintingPicker::UpdateCurrentPage(int32 offset)
{
	CurrentPage = FMath::Clamp(CurrentPage+offset, 0, GetNumberOfPages()-1);
	Refresh();
}

// Called when the game starts or when spawned
void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	UActionBar* ActionBardWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBardWidget) {
		ActionBardWidget->SetParentPicker(this);
	}
	Refresh();
}

void APaintingPicker::RefreshSlots()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("------------------NUMBER OF PAGES: %d"), GetNumberOfPages()));

	if (!GetPaintingGrid()) return;

	

	GetPaintingGrid()->ClearPaintings();

	int32 Index = 0;
	for (FString Slot_Name : UPainterSaveGameIndex::Load()->GetSlotNames()) {
		/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Paintign name: %s"), *Slot_Name));*/
		GetPaintingGrid()->AddPainting(Index, Slot_Name);
		++Index;
	}
}

void APaintingPicker::RefreshDots()
{
	if (!GetPaintingGrid()) return;
	GetPaintingGrid()->ClearDots();
	for (int32 i = 0; i < GetNumberOfPages(); i++) {
		GetPaintingGrid()->AddPaginationDot(CurrentPage==i);
	}
}

int32 APaintingPicker::GetNumberOfPages() const
{
	if (!GetPaintingGrid()) return 0;

	int32 TotalNumberOfSlots = UPainterSaveGameIndex::Load()->GetSlotNames().Num();
	int32 SlotsPerPage = GetPaintingGrid()->GetNumberOfSlots();
	return FMath::CeilToInt ((float) TotalNumberOfSlots/ SlotsPerPage);
}



