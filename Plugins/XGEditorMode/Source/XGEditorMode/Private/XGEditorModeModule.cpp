// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGEditorModeModule.h"
#include "XGEditorModeEditorModeCommands.h"

#define LOCTEXT_NAMESPACE "XGEditorModeModule"

void FXGEditorModeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FXGEditorModeEditorModeCommands::Register();
}

void FXGEditorModeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FXGEditorModeEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FXGEditorModeModule, XGEditorModeEditorMode)