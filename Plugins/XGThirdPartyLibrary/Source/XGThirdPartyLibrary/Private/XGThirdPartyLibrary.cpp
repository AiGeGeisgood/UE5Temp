// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGThirdPartyLibrary.h"
#include "Misc/MessageDialog.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "XGThirdPartyLibraryLibrary/ExampleLibrary.h"

#define LOCTEXT_NAMESPACE "FXGThirdPartyLibraryModule"

void FXGThirdPartyLibraryModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("XGThirdPartyLibrary")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;

#if PLATFORM_WINDOWS

	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/XGThirdPartyLibraryLibrary/Win64/ExampleLibrary.dll"));

#endif 

	ExampleLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (ExampleLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
		ExampleLibraryFunction();
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}




}

void FXGThirdPartyLibraryModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	ExampleLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXGThirdPartyLibraryModule, XGThirdPartyLibrary)
