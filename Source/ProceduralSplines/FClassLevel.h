#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FClassLevel.generated.h"

USTRUCT(BlueprintType)
struct FClassLevel : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 XP = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString HD;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 THAC0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 SD;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 SW;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 SP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 SB;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 SS;
};