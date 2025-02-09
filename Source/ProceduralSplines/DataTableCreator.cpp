﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "DataTableCreator.h"
#include "CSVLoader.h"
#include "DataContainerStruct.h"
#include "FClassLevel.h"
#include "GenericSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADataTableCreator::ADataTableCreator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// UClass* DataTableClass = UDataTable::StaticClass(); // get a reference to the type of object we are going to use, in this case the basic DataTable, but you can have your own
	// runTimeDataTable = NewObject<UDataTable>(this, DataTableClass, FName(TEXT("WorkingTable"))); // create a new data table object
	// runTimeDataTable->RowStruct = FDummyDataStruct::StaticStruct(); // set what kind of row structure we are going to use for our table, we assume that you included the example row structure here
	//
	// //TODO Find a way to get the dataset dynamically
	// TArray<FString> CSVLines = CSVLoader::GetCSVFile("/DataFolder/dummy.csv"); // assuming you follow our example, load the csv as an array of strings
	//
	// FClassLevel Row; // set the type of row we are going to use
	//
	// // iterate the csv lines and populate the row with the values from the csv
	// for (int i = 1; i < CSVLines.Num(); i++)
	// {
	// 	FString aString = CSVLines[i];
	// 	TArray<FString> stringArray = {};
	// 	aString.ParseIntoArray(stringArray, TEXT(","), false);
	// 	if (stringArray.Num() == 0){continue;}
	// 	FString LineLabel = stringArray[0];
	// 	if ((LineLabel.Len() == 0)  || LineLabel.StartsWith("\";") || LineLabel.StartsWith(";"))
	// 	{
	// 		continue;	// Skip comments or lines with no label
	// 	}
	// 	
	// 	//Extra quotation marks are removed.
	// 	Row.OutVariable = FCString::Atoi(*stringArray[1].TrimQuotes());
	//
	// 	// Add the row to DT
	// 	runTimeDataTable->AddRow(FName(*stringArray[0]), Row);
	// }

	// //Testing Purposes
	// FString DesiredRowName = "Dec"; // row name that we are looking for
	// FDummyDataStruct* Result = runTimeDataTable->FindRow<FDummyDataStruct>(*DesiredRowName, *DesiredRowName, true);
	// //


}


// Called when the game starts or when spawned
void ADataTableCreator::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADataTableCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}