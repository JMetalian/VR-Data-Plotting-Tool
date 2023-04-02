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
