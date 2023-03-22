
#include "AssignRandomColor.h"

#include "Kismet/KismetMathLibrary.h"


UAssignRandomColor::UAssignRandomColor()
{
	PrimaryComponentTick.bCanEverTick = true;
}
// Called when the game starts
void UAssignRandomColor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	ColorizeBarrel();
}
void UAssignRandomColor::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAssignRandomColor::ColorizeBarrel()
{
	auto mesh = Owner->FindComponentByClass<UStaticMeshComponent>();
	if (mesh!= nullptr)
	{
		auto dynamicMaterialInstance=mesh->CreateDynamicMaterialInstance(0, MainMaterial);
		
		//Create a	random color
		FLinearColor randomColor=FLinearColor(UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f),
		                              UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f),
		                              UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f));
		
		dynamicMaterialInstance->SetVectorParameterValue("Color", randomColor);
		
	}
}




