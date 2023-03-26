// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericSystem.h"

#include "DataTableCreator.h"


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
	//create instance of data table creator

	
}

// Called every frame
void AGenericSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

