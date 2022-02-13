// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingPicker.h"
#include "PaintingGrid.h"

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

// Called when the game starts or when spawned
void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();
	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;
	PaintingGridWidget->AddPainting();
}



