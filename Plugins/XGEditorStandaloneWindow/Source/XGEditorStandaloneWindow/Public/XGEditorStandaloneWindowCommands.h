// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "XGEditorStandaloneWindowStyle.h"

class FXGEditorStandaloneWindowCommands : public TCommands<FXGEditorStandaloneWindowCommands>
{
public:

	FXGEditorStandaloneWindowCommands()
		: TCommands<FXGEditorStandaloneWindowCommands>(TEXT("XGEditorStandaloneWindow"), NSLOCTEXT("Contexts", "XGEditorStandaloneWindow", "XGEditorStandaloneWindow Plugin"), NAME_None, FXGEditorStandaloneWindowStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};