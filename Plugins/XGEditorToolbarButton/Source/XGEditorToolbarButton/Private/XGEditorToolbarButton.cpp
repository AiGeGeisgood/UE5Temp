// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGEditorToolbarButton.h"
#include "XGEditorToolbarButtonStyle.h"
#include "XGEditorToolbarButtonCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName XGEditorToolbarButtonTabName("XGEditorToolbarButton");

#define LOCTEXT_NAMESPACE "FXGEditorToolbarButtonModule"

void FXGEditorToolbarButtonModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FXGEditorToolbarButtonStyle::Initialize();
	FXGEditorToolbarButtonStyle::ReloadTextures();

	FXGEditorToolbarButtonCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FXGEditorToolbarButtonCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FXGEditorToolbarButtonModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FXGEditorToolbarButtonModule::RegisterMenus));
}

void FXGEditorToolbarButtonModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FXGEditorToolbarButtonStyle::Shutdown();

	FXGEditorToolbarButtonCommands::Unregister();
}

void FXGEditorToolbarButtonModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FXGEditorToolbarButtonModule::PluginButtonClicked()")),
							FText::FromString(TEXT("XGEditorToolbarButton.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FXGEditorToolbarButtonModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FXGEditorToolbarButtonCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FXGEditorToolbarButtonCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXGEditorToolbarButtonModule, XGEditorToolbarButton)