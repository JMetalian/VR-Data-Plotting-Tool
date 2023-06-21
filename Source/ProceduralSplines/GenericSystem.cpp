// Fill out your copyright notice in the Description page of Project Settings.

#include "GenericSystem.h"
#include "CalculatePercentage.h"
#include "CSVLoader.h"
#include "DataContainerStruct.h"


// Sets default values	
AGenericSystem::AGenericSystem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
 
// Called when the game starts or when spawned
void AGenericSystem::BeginPlay()
{
	Super::BeginPlay();
	
	// TESTING PURPOSES FOR DATA MAP
	if(IsDataMapUsed)
	{
		DataMap.Add("G", 0.6f);
		DataMap.Add("H", 0.7f);
		DataMap.Add("I", 0.8f);
		DataMap.Add("J", 0.9f);
	}
	///////////////////////////////
}

// Called every frame
void AGenericSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGenericSystem::DataSetCreation()
{
	auto percentageCalculator = FindComponentByClass<UCalculatePercentage>();
	
	if(IsCSVTypeUsed)
	{
		Data_Table = CreateRunTimeDT();;
		percentageCalculator->CalculateTotalDataSum(Data_Table);
	}
	else
	{
		percentageCalculator->CalculateTotalDataSum(Data_Table);
	}
}


UDataTable* AGenericSystem::CreateRunTimeDT()
{
	UClass* dataTableClasss = UDataTable::StaticClass();
	UDataTable* runTimeDataTable = NewObject<UDataTable>(this, dataTableClasss, FName(TEXT("RunTimeTable"))); 
	runTimeDataTable->RowStruct = FDummyDataStruct::StaticStruct(); 
	
	//The file should be created under Content -> /DataFolder/ however, you can change the path. 
	FString path = CSVDataPath;
	TArray<FString> CSVLines = CSVLoader::GetCSVFile(path.Append(CSVDataSetName).Append(".csv"));

	FDummyDataStruct rowType; //Set the type of row we are going to use

	//Iterate the csv lines and populate the row with the values from the csv
	for (int i = 1; i < CSVLines.Num(); i++)
	{
		FString aString = CSVLines[i];
		TArray<FString> stringArray = {};
		aString.ParseIntoArray(stringArray, TEXT(","), false);
		if (stringArray.Num() == 0){continue;}
		FString LineLabel = stringArray[0];
		if ((LineLabel.Len() == 0)  || LineLabel.StartsWith("\";") || LineLabel.StartsWith(";"))
		{
			//Skip quotation or lines with no label.
			continue;	
		}
		//Extra quotation marks are removed.
		rowType.OutVariable = FCString::Atof(*stringArray[1].TrimQuotes());

		// Add the row to DT.
		runTimeDataTable->AddRow(FName(*stringArray[0]), rowType);
	}
	return runTimeDataTable;
}

TMap<FName,float> AGenericSystem::CreateGraphFromDataMap(const TMap<FName, float>& DataMap)
{
	TMap<FName, float> GraphDataMap = {};
	GraphDataMap=DataMap;
	return GraphDataMap;
}


//Destroy actors under ResponsibleActorInScene 
void AGenericSystem::RemoveGraphActors() const
{
	TArray<AActor*> childrenActors;
	ResponsibleActorInScene->GetAttachedActors(childrenActors);
	for (AActor* Child : childrenActors)
	{
		Child->Destroy();
	}
}