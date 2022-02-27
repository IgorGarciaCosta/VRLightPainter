// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "PainterSaveGame.h"



void APaintingGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("--------------------------------------------SLOT NAME: %s"), *SlotName));

}

void APaintingGameMode::BeginPlay()
{
	Super::BeginPlay();

	UPainterSaveGame* Painting = UPainterSaveGame::Load(SlotName);
	if (Painting) {
		Painting->DesirializeToWorld(GetWorld());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("------------------------------------------------------PAINTING STATE: %s"), *Painting->GetState()));
		UStereoLayerFunctionLibrary::HideSplashScreen();
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("------------------------------------------------------GAME SLOT NOT FOUND: %s"), *SlotName));

	}


}
