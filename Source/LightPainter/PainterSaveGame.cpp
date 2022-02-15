// Fill out your copyright notice in the Description page of Project Settings.


#include "PainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Stroke.h"
#include "Misc/Guid.h"
#include "PainterSaveGameIndex.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"

UPainterSaveGame* UPainterSaveGame::Create()
{
    UPainterSaveGame* NewSaveGame = Cast<UPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
    NewSaveGame->SlotName=FGuid::NewGuid().ToString();
    if(!NewSaveGame->Save()) return nullptr;

    UPainterSaveGameIndex* Index = UPainterSaveGameIndex::Load();
    Index->AddSaveGame(NewSaveGame);
    Index->Save();
    return NewSaveGame;
    
}

bool UPainterSaveGame::Save()
{
    for (FString Slot_Name : UPainterSaveGameIndex::Load()->GetSlotNames()) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Paintign name: %s"), *Slot_Name));
        SlotName = Slot_Name;
    }

    return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
    
}

UPainterSaveGame* UPainterSaveGame::Load(FString SlotName)
{
     return Cast<UPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
}

void UPainterSaveGame::SerializeFromWorld(UWorld* World)
{
    //clear array
    //iterate through all strokes
    //serialize
    //store class type

    Strokes.Empty();
    for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr) {
        Strokes.Add(StrokeItr->SerializaToStruct());
    }
}

void UPainterSaveGame::DesirializeToWorld(UWorld* World)
{
    //clear wordl
    //for all strokes
    //spawn stroke of that type
    ClearWorld(World);
    for (FStrokeState StrokeState : Strokes) {
        AStroke::SpawnAndDeserializeFromStruct(World, StrokeState);
    }
    
}

void UPainterSaveGame::ClearWorld(UWorld* World)
{
    
    for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr) {
        StrokeItr->Destroy();

    }
}
