// Copyright saberuster. All Rights Reserved.


#include "StackStateWidgetComponent.h"

#include "StackStatefulWidget.h"

// Sets default values for this component's properties
UStackStateWidgetComponent::UStackStateWidgetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UStackStateWidgetComponent::PushWidget(UStackStatefulWidget* Widget)
{
	PushState(Widget);
}

UStackStatefulWidget* UStackStateWidgetComponent::PopWidget()
{
	UStackStatefulWidget* PopWidget = Cast<UStackStatefulWidget>(PopState().GetObject());
	return PopWidget;
}

void UStackStateWidgetComponent::ReplaceWidget(UStackStatefulWidget* Widget)
{
	ReplaceState(Widget);
}

UStackStatefulWidget* UStackStateWidgetComponent::CurrentWidget()
{
	return Cast<UStackStatefulWidget>(CurrentState().GetObject());
}


// Called when the game starts
void UStackStateWidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStackStateWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

