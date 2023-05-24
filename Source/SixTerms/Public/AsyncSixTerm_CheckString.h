/*
Copyright 2022-2023 ©DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncSixTerm_CheckString.generated.h"

/**
 * 
 */
UCLASS()
class SIXTERMS_API UAsyncSixTerm_CheckString : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCheckStringPin_Result, const FString, cStr);
 
	UPROPERTY(BlueprintAssignable)
		FCheckStringPin_Result OnComplete;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "StringTool | AsyncSixTerms", WorldContext = "WorldContextObject"))
	static UAsyncSixTerm_CheckString* AsyncCheckString_SixTerm(UObject* WorldContextObject, FString str);
	
protected:
	virtual void Activate() override;

	UObject* world;
	FString aStr;

};
