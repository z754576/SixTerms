/*
Copyright 2022-2023 ©DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/


#include "AsyncSixTerms_SetTable.h"

#include "SixTermsBlueprintFunctionLibrary.h"

UAsyncSixTerms_SetTable* UAsyncSixTerms_SetTable::AsyncSetTable_SixTerms(UObject* WorldContextObject,UDataTable* Table)
{
    UAsyncSixTerms_SetTable* Action = NewObject<UAsyncSixTerms_SetTable>();
    Action->world = WorldContextObject;
    Action->aTable = Table;

    return Action;
}

void UAsyncSixTerms_SetTable::Activate()
{
    //上万行写入占用极高  不能使用游戏线程HameTherad
    AsyncTask(ENamedThreads::AnyThread, [this]() {
        
        bool success = USixTermsBlueprintFunctionLibrary::SetTable_SixTerms(this->world, this->aTable);
        this->OnComplete.Broadcast(success);
        });

}
