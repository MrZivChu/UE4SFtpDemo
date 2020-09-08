// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestSftp : ModuleRules
{
	public TestSftp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "ApplicationCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            string SourceDirectory = ModuleDirectory + "/JNI/";
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", SourceDirectory + "/UEJNI_APL.xml");
        }
    }
}
