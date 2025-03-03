// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGBlueprintLibraryBPLibrary.h"
#include "XGBlueprintLibrary.h"

UXGBlueprintLibraryBPLibrary::UXGBlueprintLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UXGBlueprintLibraryBPLibrary::XGBlueprintLibraryTestFuntion(float Param)
{
	return Param+998.f;
}
