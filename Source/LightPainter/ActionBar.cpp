// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionBar.h"
#include "Engine/Engine.h"


bool UActionBar::Initialize()
{
	if (!Super::Initialize()) return false;
	if(!AddBtn) return false;
	if (!DeleteBtn) return false;

	AddBtn->OnClicked.AddDynamic(this, &UActionBar::AddBtnClicked);
	DeleteBtn->OnClicked.AddDynamic(this, &UActionBar::DeleteBtnClicked);
	return true;
}

void UActionBar::AddBtnClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "------------------ADDBTN CLICKED");
	if (ParentPicker) {
		ParentPicker->AddPainting();
	}
}

void UActionBar::DeleteBtnClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "------------------DELETEBTN CLICKED");
	if (ParentPicker) {
		ParentPicker->ToggleDeleteMode();
	}
}
