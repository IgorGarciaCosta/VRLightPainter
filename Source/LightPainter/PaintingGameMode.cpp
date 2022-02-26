// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"


void APaintingGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("--------------------------------------------SLOT NAME: %s"), *SlotName));

}
