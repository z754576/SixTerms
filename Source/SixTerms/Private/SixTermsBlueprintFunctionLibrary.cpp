/*
Copyright 2023 (C)DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/


#include "SixTermsBlueprintFunctionLibrary.h"

#include "Subsystems/SubsystemBlueprintLibrary.h"

bool USixTermsBlueprintFunctionLibrary::SetTable_SixTerms(UObject* WorldContextObject,UDataTable* Table)
{
	USixTermsSubsystem* subsystem = GetSixTermsSubSystem(WorldContextObject);

	//check(subsystem); 空引用时崩溃
	if (subsystem)
	{
		subsystem->SetTable_SixTerms(Table);
		return true;
	}

	return false;
}

FString USixTermsBlueprintFunctionLibrary::CheckStringSixTerm(UObject* WorldContextObject,FString str)
{
	USixTermsSubsystem* subsystem = GetSixTermsSubSystem(WorldContextObject);
	if (subsystem)
	{
		return subsystem->CheckStringSixTerm(str);
	}

	return FString();
}

bool USixTermsBlueprintFunctionLibrary::SetScapegoat_SixTerm(UObject* WorldContextObject, FString s)
{
	USixTermsSubsystem* subsystem = GetSixTermsSubSystem(WorldContextObject);
	if (subsystem)
	{
		return subsystem->SetScapegoat_SixTerm(s);
	}
	return false;
}

USixTermsSubsystem* USixTermsBlueprintFunctionLibrary::GetSixTermsSubSystem(UObject* WorldContextObject)
{
	return Cast<USixTermsSubsystem>(USubsystemBlueprintLibrary::GetGameInstanceSubsystem(WorldContextObject, USixTermsSubsystem::StaticClass()));
}
