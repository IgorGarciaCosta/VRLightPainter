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

	RefreshSlots();
}

void APaintingPicker::ToggleDeleteMode()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "------------------ToggleDeleteMode");
	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;
	PaintingGridWidget->ClearPaintings();
}

// Called when the game starts or when spawned
void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	UActionBar* ActionBardWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBardWidget) {
		ActionBardWidget->SetParentPicker(this);
	}
	RefreshSlots();
}

void APaintingPicker::RefreshSlots()
{
	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;

	PaintingGridWidget->ClearPaintings();

	int32 Index = 0;
	for (FString Slot_Name : UPainterSaveGameIndex::Load()->GetSlotNames()) {
		/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Paintign name: %s"), *Slot_Name));*/
		PaintingGridWidget->AddPainting(Index, Slot_Name);
		++Index;
	}
}



