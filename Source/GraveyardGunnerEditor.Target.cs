// Copyright (c) 2025 Sawnoff Studios. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GraveyardGunnerEditorTarget : TargetRules
{
	public GraveyardGunnerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "GraveyardGunner" } );
	}
}
