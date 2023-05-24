/*
Copyright 2022-2023 ©DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/

#pragma once

#include "Engine/DataTable.h"
#include "SixTermsSubsystem.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SixTermsBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SIXTERMS_API USixTermsBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	* 设置敏感词基础表
	*
	* @Table 要设置Table表  结构体必须为 SixTermStruct
	* @return 是否成功
	*/
	UFUNCTION(BlueprintCallable, Category = "StringTool|SixTerms", meta = (BlueprintInternalUseOnly = "true",WorldContext = "WorldContextObject"))
		static bool SetTable_SixTerms(UObject* WorldContextObject, UDataTable* Table);

	/**
	* 对字符串检查并将敏感词替换为*
	*
	 * @str 要过滤的字符串
	 * @return 过滤后的字符串
	*/
	UFUNCTION(BlueprintCallable, Category = "StringTool|SixTerms", meta = (BlueprintInternalUseOnly = "true",WorldContext = "WorldContextObject"))
		static FString CheckStringSixTerm(UObject* WorldContextObject, FString str);

	/**
	* 设置要替换的字符,仅第一个字符有效
	*
	* @s 要替换的字符
	* @return 是否成功设置
	*/
	UFUNCTION(BlueprintCallable, Category = "StringTool|SixTerms", meta = (WorldContext = "WorldContextObject"))
		static bool SetScapegoat_SixTerm(UObject* WorldContextObject, FString s);


protected:

	static USixTermsSubsystem* GetSixTermsSubSystem(UObject* WorldContextObject);

};
