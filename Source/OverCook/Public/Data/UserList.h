#pragma once

#include "CoreMinimal.h"
#include "UserList.generated.h"

USTRUCT(BlueprintType)
struct OVERCOOK_API FUserList
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString UserName;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	TObjectPtr<APlayerController> UserController;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Connected;


};