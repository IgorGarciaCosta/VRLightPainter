// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HandController.h"
#include "VRPawn.generated.h"

UCLASS()
class LIGHTPAINTER_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

	void LeftTriggerPressed() { if (LeftHandController) LeftHandController->TriggerPressed(); }
	void LeftTriggerReleased() { if (LeftHandController)LeftHandController->TriggerReleased();}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputCOmponent) override;
private:

	

	//xonfig
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AHandController> HandControllerClass;

	//components
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;

	//references
	UPROPERTY()
		AHandController* LeftHandController;
};