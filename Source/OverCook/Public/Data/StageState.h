#pragma once

#include "StageState.generated.h"

UENUM(BlueprintType)
enum EStageState : uint8
{
	Ready		UMETA(DisplayName = "Ready"),
	Play		UMETA(DisplayName = "Play"),
	ScoreBoard	UMETA(DisplayName = "ScoreBoard")

};