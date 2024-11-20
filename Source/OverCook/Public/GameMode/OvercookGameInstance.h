// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Data/StageInfo.h"
#include "OvercookGameInstance.generated.h"

UCLASS()
class OVERCOOK_API UOvercookGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UOvercookGameInstance();
	~UOvercookGameInstance();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FStageInfo StageInfo;

};
