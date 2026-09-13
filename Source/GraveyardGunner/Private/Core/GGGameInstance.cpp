// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Core/GGGameInstance.h"

bool UGGGameInstance::IsRunningInEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}
