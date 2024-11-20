#pragma once

#include "FoodState.generated.h"

UENUM(BlueprintType)
enum EFoodState : uint8
{
	Raw		UMETA(DisplayName = "Raw"),
	Sliced	UMETA(DisplayName = "Sliced"),
	OnPlate UMETA(DisplayName = "OnPlate")

};