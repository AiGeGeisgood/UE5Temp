// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "XGEditorToolbarButtonStyle.h"

class FXGEditorToolbarButtonCommands : public TCommands<FXGEditorToolbarButtonCommands>
{
public:

	FXGEditorToolbarButtonCommands()
		: TCommands<FXGEditorToolbarButtonCommands>(TEXT("XGEditorToolbarButton"), NSLOCTEXT("Contexts", "XGEditorToolbarButton", "XGEditorToolbarButton Plugin"), NAME_None, FXGEditorToolbarButtonStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
