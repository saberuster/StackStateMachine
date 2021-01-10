// Copyright saberuster. All Rights Reserved.


#include "StackStatefulWidget.h"

void UStackStatefulWidget::HandleStateActivated(bool bFirstTime)
{
	AddToViewport();
}

void UStackStatefulWidget::HandleStateDeactivated(bool bPopOut)
{
	RemoveFromViewport();
}
