/*
Copyright 2022-2023 ©DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "Engine/DataTable.h"

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SixTermsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class SIXTERMS_API USixTermsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }

	virtual void Initialize(FSubsystemCollectionBase& Collection)override;

	virtual void Deinitialize()override;

	/**
	 * 设置敏感词基础表
	 *
	 * @Table 要设置Table表  结构体必须为 SixTermStruct
	 * @return 是否成功
	 */
	UFUNCTION(BlueprintCallable, Category = "StringTool|SixTerms")
		bool SetTable_SixTerms(UDataTable* Table);
	
	/**
	 * 对字符串检查并将敏感词替换为Scapegoat 默认替换为*
	 *
	 * @str 要过滤的字符串
	 * @return 过滤后的字符串
	 */
	UFUNCTION(BlueprintCallable, Category = "StringTool|SixTerms")
		FString CheckStringSixTerm(FString str);

	/**
	* 设置要替换的字符,仅第一个字符有效
	*
	* @s 要替换的字符
	* @return 是否成功设置
	*/
	UFUNCTION(BlueprintCallable, Category = "StringTool|SixTerms")
		bool SetScapegoat_SixTerm(FString s);

protected:
	TArray<FString> sixTerms;
	TMap<FString, TArray<FString>> mapSixTerm;

	FString scapegoat = FString("*");
}; 


USTRUCT(BlueprintType)
struct SIXTERMS_API FSixTermStruct :public FTableRowBase
{
	GENERATED_BODY()
public:

	// 使用UPROPERTY修饰符可以更方便的在蓝图中设置
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mantra")
		int ID = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mantra")
		FString Term = "";
};