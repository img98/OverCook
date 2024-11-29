#pragma once

#include "CoreMinimal.h"
#include "Data/FoodState.h"
#include "Ingredient.generated.h"

USTRUCT(BlueprintType)
struct OVERCOOK_API FIngredient
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<EFoodState> State;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Amount;

};
