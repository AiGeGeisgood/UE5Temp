// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGEditorToolbarButtonCommands.h"

#define LOCTEXT_NAMESPACE "FXGEditorToolbarButtonModule"

void FXGEditorToolbarButtonCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "XGEditorToolbarButton", "Execute XGEditorToolbarButton action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
