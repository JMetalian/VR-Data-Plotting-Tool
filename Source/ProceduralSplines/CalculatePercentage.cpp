// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculatePercentage.h"
#include "DataContainerStruct.h"

// Sets default values for this component's properties
UCalculatePercentage::UCalculatePercentage()
{
	PrimaryComponentTick.bCanEverTick = true;
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

void UCalculatePercentage::CalculateTotalDataSum(UDataTable* DataSet)
{
	if(DataSet==nullptr)
	{
		return;
	}
	TArray<FName> rowNames=DataSet->GetRowNames();
	
	for (auto rowName : rowNames)
	{
		TotalDataSum += DataSet->FindRow<FDummyDataStruct>(rowName, "")->OutVariable;
	}
}

float UCalculatePercentage::CalculateDataPercentage(float dataPoint=0.0f)
{
	return (dataPoint*10.0f)/TotalDataSum;
}
