// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;

public class XGThirdPartyLibraryLibrary : ModuleRules
{

    private void CopyDllToPluginBinaries(string InFilePath, ReadOnlyTargetRules Target)
	{
        string TargetDirectory = Path.GetFullPath(Path.Combine(PluginDirectory, "Binaries/ThirdParty", "XGThirdPartyLibraryLibrary", "Win64"));

        string FileName = Path.GetFileName(InFilePath);

        Console.WriteLine("--SourcFilePath:" + InFilePath);

        Console.WriteLine("--TargetDirectory:" + TargetDirectory + "--FileName:" + FileName);

        if (!Directory.Exists(TargetDirectory))
        {
            Directory.CreateDirectory(TargetDirectory);
        }

        string TargetFilePath = Path.Combine(TargetDirectory, FileName);

        if (!File.Exists(TargetFilePath))
        {
            File.Copy(InFilePath, TargetFilePath, true);
        }


        // Ensure that the DLL is staged along with the executable
        RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/XGThirdPartyLibraryLibrary/Win64/ExampleLibrary.dll");

    }





    public XGThirdPartyLibraryLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		PublicSystemIncludePaths.Add("$(ModuleDir)/Public");

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "ExampleLibrary.lib"));

  
			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("ExampleLibrary.dll");

			CopyDllToPluginBinaries(Path.Combine(ModuleDirectory, "x64", "Release", "ExampleLibrary.dll"), Target);


        }

	}
}
