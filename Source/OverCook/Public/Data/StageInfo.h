#pragma once

#include "CoreMinimal.h"
#include "StageInfo.generated.h"

class URecipe;

USTRUCT(BlueprintType)
struct OVERCOOK_API FStageInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UTexture> StageImage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString StageName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TObjectPtr<URecipe>> RecipeMenu;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 LastScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TimeLimit;

};