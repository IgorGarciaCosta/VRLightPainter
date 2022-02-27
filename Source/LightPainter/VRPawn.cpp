// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "PaintBrushHandController.h"
#include "Engine/Engine.h"
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


// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	

	LeftHandController = GetWorld()->SpawnActor<AHandControllerBase>(HandControllerClass);
	if (LeftHandController != nullptr)
	{
		LeftHandController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		LeftHandController->SetHand(EControllerHand::Left);
		LeftHandController->SetOwner(this); // FIX for Unreal version 4.22
	}
	/*UPainterSaveGame* Painting =UPainterSaveGame::Create();
	Painting->Save();*/
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("LeftTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::LeftTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("LeftTrigger"), EInputEvent::IE_Released, this, &AVRPawn::LeftTriggerReleased);

	PlayerInputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Released, this, &AVRPawn::Save);

}

void AVRPawn::Save()
{
	auto GameMode = Cast<APaintingGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode) return;

	GameMode->Save();
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("WidgetMap"));


}





