// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HandControllerBase.h"
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
	void PaginateRightAxisInput(float AxisValue);
	void UpdateCurrentPage(int32 offset);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputCOmponent) override;
private:

	

	//config
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AHandControllerBase> LeftHandControllerClass;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AHandControllerBase> RightHandControllerClass;
	UPROPERTY(EditDefaultsOnly)
		float PaginationThumstickThreshold = 0.9;

	//components
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;

	//references
	UPROPERTY()
		AHandControllerBase* LeftHandController;

	UPROPERTY()
		AHandControllerBase* RightHandController;

	int32 LastPaginationOffset = 0;

};
