﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "GenericSystem.generated.h"

UCLASS()
class PROCEDURALSPLINES_API AGenericSystem : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		int GenericIndex=0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Specific Settings")
		AActor* ResponsibleActorInScene=nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Set Settings")
		bool IsAlreadyPercentage=false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Set Settings")
		bool IsCSVTypeUsed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Set Settings")
		FString CSVDataSetName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Data Set Settings")
		UDataTable* Data_Table=nullptr;
	
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Set Settings")
	// 	FString DataTableTypeSetName;

public:
	// Sets default values for this actor's properties
	AGenericSystem();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Generic System",meta=(HideInDetailPanel))
		int GenericIteratorLength=0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		TSubclassOf<AActor> GenericClass;

	//Test Purpose
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		AActor* TestingInputActor=nullptr;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Generic System")
	void DataSetCreation();
	
	//Use it before creating a new graph actors
	UFUNCTION(BlueprintCallable, Category = "Generic System")
	void RemoveGraphActors() const;
	
private:
	UDataTable* CreateRunTimeDT();

	UDataTable* GetDataTableFromFolder();
	
	
};