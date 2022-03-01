// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetTouchingComponent.h"
#include "Engine/Engine.h"

void UWidgetTouchingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsOverInteractableWidget() && !bIsClicked) {
		PressPointerKey(EKeys::LeftMouseButton);
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "------------------------------CLICKED");
		bIsClicked = true;
	}
	else if (!IsOverInteractableWidget() && bIsClicked) {
		ReleasePointerKey(EKeys::LeftMouseButton);
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "------------------------------RELEASED");
		bIsClicked = false;
	}
}
