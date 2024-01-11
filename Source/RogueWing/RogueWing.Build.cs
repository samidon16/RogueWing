// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class RogueWing : ModuleRules
{
	public RogueWing(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
        IncludeSubdirectoriesInIncludePaths();

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
    private void IncludeSubdirectoriesInIncludePaths()
    {
        AddDirectoriesRecursive(ModuleDirectory);
    }

    private void AddDirectoriesRecursive(string DirectoryPathToSearch)
    {
        foreach (string DirectoryPath in Directory.GetDirectories(DirectoryPathToSearch))
        {
            PublicIncludePaths.Add(DirectoryPath);
            AddDirectoriesRecursive(DirectoryPath);
        }
    }
}
