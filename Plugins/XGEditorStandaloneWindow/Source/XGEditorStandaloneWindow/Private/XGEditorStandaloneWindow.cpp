// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGEditorStandaloneWindow.h"
#include "XGEditorStandaloneWindowStyle.h"
#include "XGEditorStandaloneWindowCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName XGEditorStandaloneWindowTabName("XGEditorStandaloneWindow");

#define LOCTEXT_NAMESPACE "FXGEditorStandaloneWindowModule"

void FXGEditorStandaloneWindowModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FXGEditorStandaloneWindowStyle::Initialize();
	FXGEditorStandaloneWindowStyle::ReloadTextures();

	FXGEditorStandaloneWindowCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FXGEditorStandaloneWindowCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FXGEditorStandaloneWindowModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FXGEditorStandaloneWindowModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(XGEditorStandaloneWindowTabName, FOnSpawnTab::CreateRaw(this, &FXGEditorStandaloneWindowModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FXGEditorStandaloneWindowTabTitle", "XGEditorStandaloneWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FXGEditorStandaloneWindowModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FXGEditorStandaloneWindowStyle::Shutdown();

	FXGEditorStandaloneWindowCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(XGEditorStandaloneWindowTabName);
}

TSharedRef<SDockTab> FXGEditorStandaloneWindowModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FXGEditorStandaloneWindowModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("XGEditorStandaloneWindow.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FXGEditorStandaloneWindowModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(XGEditorStandaloneWindowTabName);
}

void FXGEditorStandaloneWindowModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FXGEditorStandaloneWindowCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FXGEditorStandaloneWindowCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXGEditorStandaloneWindowModule, XGEditorStandaloneWindow)