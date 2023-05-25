/*
Copyright 2023 (C)DMD, Inc. All Rights Reserved.
Unauthorized copying, selling or distribution of this software is strictly prohibited.
*/


#include "SixTermsSubsystem.h"

#include "Kismet/KismetStringLibrary.h"

void USixTermsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void USixTermsSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool USixTermsSubsystem::SetTable_SixTerms(UDataTable* Table)
{
	if (Table && Table->RowStruct == FSixTermStruct::StaticStruct())
	{
		for (auto& Row : Table->GetRowMap())
		{
			auto RowName = Row.Key;
			FSixTermStruct* RowData = reinterpret_cast<FSixTermStruct*> (Row.Value);
			sixTerms.AddUnique(RowData->Term);
			FString Io = RowData->Term.Left(1);
			FString Il = "";
			if (RowData->Term.Len() > 0)
			{
				Il = RowData->Term.RightChop(1);
			}

			TArray<FString> mapItems;
			if (mapSixTerm.Contains(Io))
			{
				mapItems = mapSixTerm[Io];
			}
			mapItems.AddUnique(Il);

			mapSixTerm.Add(Io, mapItems);
		}
		return true;
	}

	return false;
}

FString USixTermsSubsystem::CheckStringSixTerm(FString str)
{
	TArray<FString> strItems;
	strItems = UKismetStringLibrary::GetCharacterArrayFromString(str);
	FString _str = str;

	for (int i = 0; i < strItems.Num(); i++)
	{
		FString s = strItems[i];
		if (mapSixTerm.Contains(s))
		{
			TArray<FString> terms = mapSixTerm[s];

			for (auto& var : terms) 
			{
				FString cs = s + var;
				if (UKismetStringLibrary::Contains(_str, cs))
				{
					FString x;
					for (int j = 0; j < cs.Len(); j++)
					{
						x += scapegoat;
					}
					_str = UKismetStringLibrary::Replace(_str, cs, x, ESearchCase::IgnoreCase);
				}
			}
		}
	}
	return _str;
}

bool USixTermsSubsystem::SetScapegoat_SixTerm(FString s)
{
	if (s.Len() > 0)
	{
		scapegoat = s.Left(1);
		return true;
	}
	return false;
}
