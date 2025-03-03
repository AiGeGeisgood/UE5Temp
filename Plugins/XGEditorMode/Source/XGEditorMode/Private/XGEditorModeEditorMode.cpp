// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGEditorModeEditorMode.h"
#include "XGEditorModeEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "XGEditorModeEditorModeCommands.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/XGEditorModeSimpleTool.h"
#include "Tools/XGEditorModeInteractiveTool.h"

// step 2: register a ToolBuilder in FXGEditorModeEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "XGEditorModeEditorMode"

const FEditorModeID UXGEditorModeEditorMode::EM_XGEditorModeEditorModeId = TEXT("EM_XGEditorModeEditorMode");

FString UXGEditorModeEditorMode::SimpleToolName = TEXT("XGEditorMode_ActorInfoTool");
FString UXGEditorModeEditorMode::InteractiveToolName = TEXT("XGEditorMode_MeasureDistanceTool");


UXGEditorModeEditorMode::UXGEditorModeEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UXGEditorModeEditorMode::EM_XGEditorModeEditorModeId,
		LOCTEXT("ModeName", "XGEditorMode"),
		FSlateIcon(),
		true);
}


UXGEditorModeEditorMode::~UXGEditorModeEditorMode()
{
}


void UXGEditorModeEditorMode::ActorSelectionChangeNotify()
{
}

void UXGEditorModeEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FXGEditorModeEditorModeCommands& SampleToolCommands = FXGEditorModeEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UXGEditorModeSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UXGEditorModeInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UXGEditorModeEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FXGEditorModeEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UXGEditorModeEditorMode::GetModeCommands() const
{
	return FXGEditorModeEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
