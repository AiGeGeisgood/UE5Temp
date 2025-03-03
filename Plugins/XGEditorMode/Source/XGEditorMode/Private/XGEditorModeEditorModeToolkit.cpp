// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGEditorModeEditorModeToolkit.h"
#include "XGEditorModeEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "XGEditorModeEditorModeToolkit"

FXGEditorModeEditorModeToolkit::FXGEditorModeEditorModeToolkit()
{
}

void FXGEditorModeEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FXGEditorModeEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FXGEditorModeEditorModeToolkit::GetToolkitFName() const
{
	return FName("XGEditorModeEditorMode");
}

FText FXGEditorModeEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "XGEditorModeEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
