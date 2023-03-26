#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FClassLevel.generated.h"

USTRUCT(BlueprintType)
struct FClassLevel : public FTableRowBase
{
	GENERATED_BODY();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 OutVariable = 0;
};
