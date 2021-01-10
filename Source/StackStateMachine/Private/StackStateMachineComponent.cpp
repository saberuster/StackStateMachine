// Copyright saberuster. All Rights Reserved.


#include "StackStateMachineComponent.h"

// Sets default values for this component's properties
UStackStateMachineComponent::UStackStateMachineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UStackStateMachineComponent::PushState(TScriptInterface<IStackStateOwnerInterface> NewState)
{
	TScriptInterface<IStackStateOwnerInterface> OldState = CurrentState();
	if (OldState != nullptr)
	{
		OldState->HandleStateDeactivated(false);
	}
	StackStates.Push(NewState);
	NewState->HandleStateActivated(true);
}

void UStackStateMachineComponent::ReplaceState(TScriptInterface<IStackStateOwnerInterface> NewState)
{
	PopState();
	PushState(NewState);
}

TScriptInterface<IStackStateOwnerInterface> UStackStateMachineComponent::PopState()
{
	TScriptInterface<IStackStateOwnerInterface> State = StackStates.Pop();
	if (State != nullptr)
	{
		State->HandleStateDeactivated(true);
		TScriptInterface<IStackStateOwnerInterface> NewTop = CurrentState();
		if (NewTop != nullptr)
		{
			NewTop->HandleStateActivated(false);
		}
	}

	return State;
}

TScriptInterface<IStackStateOwnerInterface> UStackStateMachineComponent::CurrentState()
{
	if (StackStates.Num() > 0)
	{
		return StackStates.Last();
	}
	return nullptr;
}


// Called when the game starts
void UStackStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStackStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

