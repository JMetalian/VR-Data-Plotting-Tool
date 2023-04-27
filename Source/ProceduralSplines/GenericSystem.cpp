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
		DataSet = CreateRunTimeDT();;
		percentageCalculator->CalculateTotalDataSum(DataSet);
	}
	else
	{
		percentageCalculator->CalculateTotalDataSum(DataSet);
	}
}

UDataTable* AGenericSystem::CreateRunTimeDT()
{
	UClass* dataTableClasss = UDataTable::StaticClass();
	UDataTable* runTimeDataTable = NewObject<UDataTable>(this, dataTableClasss, FName(TEXT("RunTimeTable"))); 
	runTimeDataTable->RowStruct = FDummyDataStruct::StaticStruct(); 

	//Write down the "Will be used CSV file name e.g "MyCSV" in editor. No extension needed.
	//The file should be created under Content -> /DataFolder/ however, you can change the path. 
	FString path = "/DataFolder/";
	TArray<FString> CSVLines = CSVLoader::GetCSVFile(path.Append(DataSetName).Append(".csv"));

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
		rowType.OutVariable = FCString::Atoi(*stringArray[1].TrimQuotes());

		// Add the row to DT.
		runTimeDataTable->AddRow(FName(*stringArray[0]), rowType);
	}
	return runTimeDataTable;
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