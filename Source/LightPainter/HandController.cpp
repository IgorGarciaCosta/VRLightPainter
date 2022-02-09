// Fill out your copyright notice in the Description page of Project Settings.


#include "HandController.h"
#include "Engine/World.h"

// Sets default values
AHandController::AHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//MotionController = CreateDefaultSubobject<UMotionControllerComponent>("MotionController");
	//SetRootComponent(MotionController);
	//MotionController->SetTrackingSource(EControllerHand::Left);
	//MotionController->SetShowDeviceModel(true);
	//MotionController->SetOwner(this);
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>("MotionController");
	SetRootComponent(MotionController);
}

void AHandController::TriggerPressed()
{
	AStroke* Stroke = GetWorld()->SpawnActor<AStroke>(StrokeClass);
	Stroke->SetActorLocation(GetActorLocation());
}

void AHandController::TriggerReleased()
{
}

//// Called when the game starts or when spawned
void AHandController::BeginPlay()
{

	Super::BeginPlay();
	
}
//
//// Called every frame
//void AHandController::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

