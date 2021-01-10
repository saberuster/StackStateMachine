// Copyright saberuster. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "StackStateOwnerInterface.h"
#include "Blueprint/UserWidget.h"
#include "StackStatefulWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class UISTACKSTATEMACHINE_API UStackStatefulWidget : public UUserWidget, public IStackStateOwnerInterface
{
	GENERATED_BODY()

public:

	virtual void HandleStateActivated(bool bFirstTime) override;
	virtual void HandleStateDeactivated(bool bPopOut) override;
};
