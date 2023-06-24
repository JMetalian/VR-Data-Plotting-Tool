// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "CalculatePercentage.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROCEDURALSPLINES_API UCalculatePercentage : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCalculatePercentage();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	// UFUNCTION(BlueprintCallable, Category = "Calculate Total Data Sum")
	void CalculateTotalDataSum(UDataTable* DataSet);
	
	// UFUNCTION(BlueprintCallable, Category = "Calculate Total Data Sum")
	void CalculateTotalDataSum(const TMap<FName,float>& DataMap);
	
	UFUNCTION(BlueprintCallable, Category = "Calculate Percentage of Datas")
	float CalculateDataPercentage(float dataPoint);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Total Data Sum")
	float TotalDataSum=0.0f;
};
