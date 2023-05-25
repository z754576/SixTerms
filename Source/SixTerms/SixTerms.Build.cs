/*
Copyright 2023 (C)DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/


using UnrealBuildTool;

public class SixTerms : ModuleRules
{
	public SixTerms(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
    }
}
