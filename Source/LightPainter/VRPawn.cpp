// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"
#include "PaintingPicker.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "PaintBrushHandController.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "PainterSaveGame.h"
#include "PaintingGameMode.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	VRRoot = CreateDefaultSubobject<USceneComponent>("VRRoot");
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(VRRoot);
}

void AVRPawn::PaginateRightAxisInput(float AxisValue)
{
	int32 PaginationOffset = 0;
	PaginationOffset += AxisValue>PaginationThumstickThreshold ? 1 : 0;
	PaginationOffset += AxisValue < -PaginationThumstickThreshold ? -1 : 0;

	if (PaginationOffset != LastPaginationOffset && PaginationOffset!=0) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Paintign name: %d"), PaginationOffset));
		UpdateCurrentPage(PaginationOffset);
	}
	LastPaginationOffset = PaginationOffset;
	
}

void AVRPawn::UpdateCurrentPage(int32 offset)
{
	for (TActorIterator<APaintingPicker>PaintingPickerItr(GetWorld()); PaintingPickerItr; ++PaintingPickerItr) {//iterates over every PaintingPicker in the world
		PaintingPickerItr->UpdateCurrentPage(offset);
	}
}


// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	
	LeftHandController = GetWorld()->SpawnActor<AHandControllerBase>(LeftHandControllerClass);
	RightHandController = GetWorld()->SpawnActor<AHandControllerBase>(RightHandControllerClass);

	if (LeftHandController != nullptr)
	{
		LeftHandController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		LeftHandController->SetHand(EControllerHand::Left);
		LeftHandController->SetOwner(this); // FIX for Unreal version 4.22 and above
	}

	if (RightHandController != nullptr)
	{
		RightHandController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		RightHandController->SetHand(EControllerHand::Right);
		RightHandController->SetOwner(this); // FIX for Unreal version 4.22  and above
	}
	/*UPainterSaveGame* Painting =UPainterSaveGame::Create();
	Painting->Save();*/
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);//
	PlayerInputComponent->BindAction(TEXT("LeftTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::LeftTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("LeftTrigger"), EInputEvent::IE_Released, this, &AVRPawn::LeftTriggerReleased);

	PlayerInputComponent->BindAxis(TEXT("PaginateRight"), this, &AVRPawn::PaginateRightAxisInput);

}







