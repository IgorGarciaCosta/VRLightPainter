// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "Stroke.h"
#include "HandController.generated.h"

UCLASS()
class LIGHTPAINTER_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandController();
	void SetHand(EControllerHand Hand) { MotionController->SetTrackingSource(Hand); }

	void TriggerPressed();
	void TriggerReleased();

//protected:
//	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AHandController> HandControllerClass;

	//components
	UPROPERTY(VisibleAnywhere)
		UMotionControllerComponent* MotionController;
	UPROPERTY(VisibleAnywhere)
		UMotionControllerComponent* LeftController;
	UPROPERTY(VisibleAnywhere)
		UMotionControllerComponent* RightController;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AStroke> StrokeClass;

	//state
	AStroke* CurrentStroke;
};
