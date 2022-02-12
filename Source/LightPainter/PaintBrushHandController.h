// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stroke.h"
#include "HandControllerBase.h"
#include "PaintBrushHandController.generated.h"

UCLASS()
class LIGHTPAINTER_API APaintBrushHandController : public AHandControllerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintBrushHandController();
	void SetHand(EControllerHand Hand) override { MotionController->SetTrackingSource(Hand); }

	void TriggerPressed() override;
	void TriggerReleased() override;

//protected:
//	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class APaintBrushHandController> HandControllerClass;

	//components
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<AStroke> StrokeClass;

	//state
	AStroke* CurrentStroke;
};
