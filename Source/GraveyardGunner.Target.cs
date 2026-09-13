// Copyright (c) 2025 Sawnoff Studios. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GraveyardGunnerTarget : TargetRules
{
	public GraveyardGunnerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "GraveyardGunner" } );
	}
}
