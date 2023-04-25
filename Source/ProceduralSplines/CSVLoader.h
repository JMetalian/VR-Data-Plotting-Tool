// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PROCEDURALSPLINES_API CSVLoader
{
public:
	CSVLoader();
	~CSVLoader();

	static TArray<FString> GetCSVFile(FString Path);
};
