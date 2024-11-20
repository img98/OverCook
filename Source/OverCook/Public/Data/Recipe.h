// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/Ingredient.h"
#include "Recipe.generated.h"

class UFoodItem;

UCLASS(BlueprintType, Blueprintable)
class OVERCOOK_API URecipe : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Compare(TMap<UFoodItem*, FIngredient> InIngredient, bool& Equal);

	UFUNCTION(BlueprintCallable)
	void CompareIngredinets(FIngredient A, FIngredient B, bool& Equal);
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TMap<UFoodItem*, FIngredient> Ingredient;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 Score;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UTexture> FoodUI;

	
};
