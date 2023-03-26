// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	AGenericSystem(); 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		int GenericIndex=0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		AActor* ResponsibleActorInScene=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Generic System")
		UDataTable* DataSet=nullptr;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Generic System",meta=(EditConditionHides))
		int GenericIteratorLength=0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		TSubclassOf<AActor> GenericClass;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetDataTable(UDataTable* dataTable)
	{
		DataSet = dataTable;
	}
};