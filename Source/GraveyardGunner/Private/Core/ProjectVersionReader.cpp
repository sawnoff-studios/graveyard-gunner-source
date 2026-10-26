// Copyright (c) Sawnoff Studios. All rights reserved.


#include "Core/ProjectVersionReader.h"

FString UProjectVersionReader::GetProjectVersion()
{
	FString ProjectVersion;

	GConfig->GetString(
	  TEXT("/Script/EngineSettings.GeneralProjectSettings"),
	  TEXT("ProjectVersion"),
	  ProjectVersion,
	  GGameIni
	);

	return ProjectVersion;
}
