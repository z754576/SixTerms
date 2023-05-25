/*
Copyright 2023 (C)DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/


#pragma once

#include "Engine/DataTable.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncSixTerms_SetTable.generated.h"

/**
 * 
 */
UCLASS()
class SIXTERMS_API UAsyncSixTerms_SetTable : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetTablePin_Result, const bool, success);

		UPROPERTY(BlueprintAssignable)
			FSetTablePin_Result OnComplete;

		/**
		* 设置敏感词基础表
		*
		* @Table 要设置Table表  结构体必须为 SixTermStruct
		* @return 是否成功
		*/
		UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true", Category = "StringTool | AsyncSixTerms", WorldContext = "WorldContextObject"))
		static UAsyncSixTerms_SetTable* AsyncSetTable_SixTerms(UObject* WorldContextObject, UDataTable* Table);

protected:

	virtual void Activate() override;

	UObject* world;
	UDataTable* aTable;
};
