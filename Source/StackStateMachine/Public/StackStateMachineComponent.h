// Copyright saberuster. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "StackStateOwnerInterface.h"
#include "Components/ActorComponent.h"
#include "StackStateMachineComponent.generated.h"


UCLASS( ClassGroup=(StateMachine), meta=(BlueprintSpawnableComponent) )
class STACKSTATEMACHINE_API UStackStateMachineComponent : public UActorComponent, public IStackStateOwnerInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStackStateMachineComponent();

	void PushState(TScriptInterface<IStackStateOwnerInterface> NewState);
	void ReplaceState(TScriptInterface<IStackStateOwnerInterface> NewState);
	TScriptInterface<IStackStateOwnerInterface> PopState();
	TScriptInterface<IStackStateOwnerInterface> CurrentState();


	virtual UStackStateMachineComponent* GetStackStateMachineComponent() const override { return const_cast<UStackStateMachineComponent*>(this); }
protected:
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY()
	TArray<TScriptInterface<IStackStateOwnerInterface>> StackStates;

};
