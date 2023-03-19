// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculatePercentage.h"
#include "DataContainerStruct.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UCalculatePercentage::UCalculatePercentage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UCalculatePercentage::BeginPlay()
{
	Super::BeginPlay();
	
}


void UCalculatePercentage::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UCalculatePercentage::CalculateTotalDataSum(UDataTable* DataSet)
{
	float totalSum = 0.0f;
	TArray<FName> rowNames=DataSet->GetRowNames();
	
	for (auto rowName : rowNames)
	{
		totalSum += DataSet->FindRow<FDummyDataStruct>(rowName, "")->OutVariable;
	}
	
	return totalSum;
}

float UCalculatePercentage::CalculateDataPercentage(float dataPoint=0.0f, float totalDataSum=1.0f)
{
		return (dataPoint*10.0f)/totalDataSum;
}
