// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DataContainerStruct.generated.h"


USTRUCT(BlueprintType)
struct FDataContainerStruct : public FTableRowBase
{
	GENERATED_BODY()

	//~ The following member variable will be accessible by Blueprint Graphs:
	// This is the tooltip for our test variable.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test Variables")
	int32 ParticipationValues = 0;

	

	// //~ The following member variable will be not accessible by Blueprint Graphs:
	// int32 NativeOnlyMemberVariable;
	//
	// /**~
	// * This UObject pointer is not accessible to Blueprint Graphs, but
	// * is visible to UE4's reflection, smart pointer, and garbage collection
	// * systems.
	// */
	// UPROPERTY()
	// UObject* SafeObjectPointer;
};
