// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreateSessionWidget.generated.h"

class UTextBlock;
class UButton;
class UEditableTextBox;

UCLASS()
class OVERCOOK_API UCreateSessionWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void DecreaseLobbyPlayer();
	UFUNCTION()
	void IncreaseLobbyPlayer();
	UFUNCTION()
	void CreateLobby();
	UFUNCTION()
	void ProcessClickCancel();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTextBlock> PlayerCountBlock;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UButton> ButtonL;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UButton> ButtonR;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UButton> CancelButton;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UButton> CreateButton;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> SessionNameBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayerCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxPlayerCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseLan;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	FName NextLevelName;
};
