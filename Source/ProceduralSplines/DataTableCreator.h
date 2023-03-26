// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "DataTableCreator.generated.h"

UCLASS()
class PROCEDURALSPLINES_API ADataTableCreator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADataTableCreator();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UDataTable* runTimeDataTable=nullptr;

};