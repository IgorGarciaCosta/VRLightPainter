// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "ActionBar.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UActionBar : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UButton* AddBtn;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UButton* DeleteBtn;

private:
	UFUNCTION()
	void AddBtnClicked();
	UFUNCTION()
	void DeleteBtnClicked();
};
