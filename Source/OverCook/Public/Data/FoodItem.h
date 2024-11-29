// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FoodItem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class OVERCOOK_API UFoodItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UStaticMesh> DefultMesh;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UStaticMesh> SlicedMesh;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UStaticMesh> OnPlateMesh;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UMaterial> Icon;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UTexture> UiIcon;


};
