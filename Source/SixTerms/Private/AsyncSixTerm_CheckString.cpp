/*
Copyright 2022-2023 ©DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/


#include "AsyncSixTerm_CheckString.h"

#include "SixTermsBlueprintFunctionLibrary.h"

UAsyncSixTerm_CheckString* UAsyncSixTerm_CheckString::AsyncCheckString_SixTerm(UObject* WorldContextObject, FString str)
{
	UAsyncSixTerm_CheckString* Action = NewObject<UAsyncSixTerm_CheckString>();
	Action->world = WorldContextObject;
	Action->aStr = str;
	return Action;
}

void UAsyncSixTerm_CheckString::Activate()
{
	//ENamedThreads::AnyThread
	AsyncTask(ENamedThreads::GameThread, [this]() {
		FString s = USixTermsBlueprintFunctionLibrary::CheckStringSixTerm(this->world, this->aStr);
		this->OnComplete.Broadcast(s);
		});
}
