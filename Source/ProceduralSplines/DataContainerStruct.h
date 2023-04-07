// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "DataContainerStruct.generated.h"

UCLASS()
class PROCEDURALSPLINES_API ADataContainerStruct : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADataContainerStruct();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

USTRUCT(BlueprintType)
struct FDummyDataStruct : public FTableRowBase
{
	GENERATED_BODY()

	//~ The following member variable will be accessible by Blueprint Graphs:
	// This is the tooltip for our test variable.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test Variables")
	float OutVariable = 0;
};