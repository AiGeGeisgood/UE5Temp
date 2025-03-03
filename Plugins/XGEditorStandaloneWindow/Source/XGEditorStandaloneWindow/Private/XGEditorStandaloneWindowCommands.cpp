// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGEditorStandaloneWindowCommands.h"

#define LOCTEXT_NAMESPACE "FXGEditorStandaloneWindowModule"

void FXGEditorStandaloneWindowCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "XGEditorStandaloneWindow", "Bring up XGEditorStandaloneWindow window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
