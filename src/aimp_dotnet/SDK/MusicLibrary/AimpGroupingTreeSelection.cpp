// ----------------------------------------------------
// 
// AIMP DotNet SDK
// 
// Copyright (c) 2014 - 2019 Evgeniy Bogdan
// https://github.com/martin211/aimp_dotnet
// 
// Mail: mail4evgeniy@gmail.com
// 
// ----------------------------------------------------

#include "Stdafx.h"
#include "AimpGroupingTreeSelection.h"

using namespace AIMP::SDK;

AimpGroupingTreeSelection::AimpGroupingTreeSelection(IAIMPMLGroupingTreeSelection* aimpObject) : AimpObject(aimpObject)
{
}

int AimpGroupingTreeSelection::GetCount()
{
    return InternalAimpObject->GetCount();
}

ActionResultType AimpGroupingTreeSelection::GetValue(int index, System::String^% fieldName, System::Object^% value)
{
    IAIMPString* str = nullptr;
    VARIANT val;

    fieldName = nullptr;
    value = nullptr;

    const ActionResultType result = CheckResult(InternalAimpObject->GetValue(index, &str, &val));

    try
    {
        if (result == ActionResultType::OK)
        {
            if (str != nullptr)
            {
                fieldName = AimpConverter::ToManagedString(str);
            }

            value = AimpConverter::FromVaiant(&val);
        }
    }
    finally
    {
        if (str != nullptr)
        {
            str->Release();
            str = nullptr;
        }
    }

    return result;
}
