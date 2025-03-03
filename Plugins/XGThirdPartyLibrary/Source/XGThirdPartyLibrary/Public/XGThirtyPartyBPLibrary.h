
#pragma once
#include "CoreMinimal.h"

#include "XGThirtyPartyBPLibrary.generated.h"


UCLASS()
class UXGThirtyPartyBPLibrary : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "XGThirtyPartyTest", Keywords = "XGBlueprintLibrary sample test "), Category = "XG")
	static int32 XGThirtyPartyTest(int32 InA,int32 InB);
};
