// Fill out your copyright notice in the Description page of Project Settings.


#include "UIPointerHandControllerBase.h"
#include "InputCoreTypes.h"



AUIPointerHandControllerBase::AUIPointerHandControllerBase() {
	Pointer = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Pointer"));
	Pointer->SetupAttachment(GetRootComponent());
}


void AUIPointerHandControllerBase::TriggerPressed() {
	Pointer->PressPointerKey(EKeys::LeftMouseButton);
}

void AUIPointerHandControllerBase::TriggerReleased() {
	Pointer->ReleasePointerKey(EKeys::LeftMouseButton);

}