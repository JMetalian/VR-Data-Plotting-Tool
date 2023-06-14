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
		Data_Table = CreateRunTimeDT();;
		percentageCalculator->CalculateTotalDataSum(Data_Table);
	}
	else
	{
		percentageCalculator->CalculateTotalDataSum(Data_Table);
	}
}


UDataTable* AGenericSystem::GetDataTableFromFolder()
{
	// //Create UDataTable variable, read the file from folder and return it.
	UDataTable* DataTable = NewObject<UDataTable>();
	// FString path = "/DataFolder/DataTableType/";
	//
	// FString file = FPaths::ProjectConfigDir();
	// file.Append(DataTableTypeSetName);
	//
	// IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	//
	//
	// FString FileContent;
	// // Always first check if the file that you want to manipulate exist.
	// if (FileManager.FileExists(*file))
	// {
	//
	// 	
	// 	// // We use the LoadFileToString to load the file into
	// 	// if(FFileHelper::LoadFileToString(FileContent,*file,FFileHelper::EHashOptions::None))
	// 	// {
	// 	// 	// UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *FileContent);
	// 	// }
	// 	// else
	// 	// {
	// 	// 	UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
	// 	// }
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
	// 	UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"),*file);
	// }

	

	return DataTable;
}
	


UDataTable* AGenericSystem::CreateRunTimeDT()
{
	UClass* dataTableClasss = UDataTable::StaticClass();
	UDataTable* runTimeDataTable = NewObject<UDataTable>(this, dataTableClasss, FName(TEXT("RunTimeTable"))); 
	runTimeDataTable->RowStruct = FDummyDataStruct::StaticStruct(); 

	//Write down the "Will be used CSV file name e.g "MyCSV" in editor. No extension needed.
	//The file should be created under Content -> /DataFolder/ however, you can change the path. 
	FString path = "/DataFolder/CSVType/";
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