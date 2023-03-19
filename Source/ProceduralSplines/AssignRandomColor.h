
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AssignRandomColor.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROCEDURALSPLINES_API UAssignRandomColor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAssignRandomColor();

	AActor* Owner = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random Color Material")
	UMaterialInterface* MainMaterial;
	
private:
	void ColorizeBarrel();
};
