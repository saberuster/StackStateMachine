// Copyright saberuster. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StackStateMachineComponent.h"
#include "StackStateWidgetComponent.generated.h"

class UStackStatefulWidget;


UCLASS( ClassGroup=(UserInterface), meta=(BlueprintSpawnableComponent) )
class UISTACKSTATEMACHINE_API UStackStateWidgetComponent : public UStackStateMachineComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStackStateWidgetComponent();

	UFUNCTION(BlueprintCallable)
	void PushWidget(UStackStatefulWidget* Widget);

	UFUNCTION(BlueprintCallable)
	void ReplaceWidget(UStackStatefulWidget* Widget);

	UFUNCTION(BlueprintCallable)
	UStackStatefulWidget* PopWidget();

	UFUNCTION(BlueprintCallable)
	UStackStatefulWidget* CurrentWidget();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
