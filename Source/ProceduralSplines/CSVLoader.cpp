// Fill out your copyright notice in the Description page of Project Settings.


#include "CSVLoader.h"

CSVLoader::CSVLoader()
{
}

CSVLoader::~CSVLoader()
{
}

TArray<FString> CSVLoader::GetCSVFile(FString Path)
{
	TArray<FString> Lines;
	FString CsvFile = FPaths::ProjectContentDir() + Path;
	if (FPaths::FileExists(CsvFile))
	{
		UE_LOG(LogTemp, Log, TEXT("File %s exists"), *CsvFile);		
		FFileHelper::LoadANSITextFileToStrings(*CsvFile, NULL, Lines);
	}

	return Lines;
}