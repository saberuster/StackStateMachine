// Copyright saberuster. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "UObject/Interface.h"
#include "StackStateOwnerInterface.generated.h"

class UStackStateMachineComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UStackStateOwnerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STACKSTATEMACHINE_API IStackStateOwnerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual UStackStateMachineComponent* GetStackStateMachineComponent() const PURE_VIRTUAL(IStackStateOwnerInterface::GetStackStateMachineComponent, return nullptr;); 

	virtual void HandleStateActivated(bool bFirstTime) {}
	virtual void HandleStateDeactivated(bool bPopOut) {}
	
};
