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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		int GenericIndex=0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		AActor* ResponsibleActorInScene=nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Generic System")
		UDataTable* DataSet=nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		bool IsUsingCSV;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Generic System")
	FString DataSetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		bool IsAlreadyPercentage=false;

	UFUNCTION(BlueprintImplementableEvent)
		void OnDataSetChanged();

public:
	// Sets default values for this actor's properties
	AGenericSystem(); 
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Generic System",meta=(HideInDetailPanel))
		int GenericIteratorLength=0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic System")
		TSubclassOf<AActor> GenericClass;

private:
	UDataTable* CreateRunTimeDT();
	void RemoveGraphActors() const;
	
};