// Fill out your copyright notice in the Description page of Project Settings.


#include "PainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Stroke.h"
#include "EngineUtils.h"

UPainterSaveGame* UPainterSaveGame::Create()
{
    USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
    return Cast<UPainterSaveGame>(NewSaveGame);
    
}

bool UPainterSaveGame::Save()
{
    return UGameplayStatics::SaveGameToSlot(this, TEXT("test"), 0);
    
}

UPainterSaveGame* UPainterSaveGame::Load()
{
     return Cast<UPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("test"), 0));
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
