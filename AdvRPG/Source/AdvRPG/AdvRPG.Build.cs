// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AdvRPG : ModuleRules
{
	public AdvRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
