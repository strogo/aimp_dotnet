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

#include "stdafx.h"
#include "AimpAction.h"
#include "AimpServiceActionManager.h"

AimpServiceActionManager::AimpServiceActionManager(ManagedAimpCore^ core) : BaseAimpService<IAIMPServiceActionManager>(core)
{
}

AimpActionResult<IAimpAction^>^ AimpServiceActionManager::GetById(String^ id)
{
    auto res = ActionResultType::Fail;
    IAIMPServiceActionManager* service = GetAimpService();
    IAimpAction^ action = nullptr;
    AimpActionResult<IAimpAction^>^ result = nullptr;

    try
    {
        if (service != nullptr)
        {
            IAIMPAction* resAction = nullptr;
            IAIMPString* strId = AimpConverter::ToAimpString(id);
            const auto res = CheckResult(service->GetByID(strId, &resAction));
            if (res != ActionResultType::OK)
            {
                action = gcnew AimpAction(resAction);
            }

            strId->Release();
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return gcnew AimpActionResult<IAimpAction^>(res, action);
}

int AimpServiceActionManager::MakeHotkey(ModifierKeys modifiers, unsigned int key)
{
    IAIMPServiceActionManager* service = GetAimpService();

    try
    {
        if (service != nullptr)
        {
            return service->MakeHotkey(DWORD(modifiers), key);
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return 0;
}

AimpActionResult^ AimpServiceActionManager::Register(IAimpAction^ action)
{
    return GetResult(_core->GetAimpCore()->RegisterExtension(IID_IAIMPServiceActionManager,
                                                               static_cast<AimpAction^>(action)->InternalAimpObject));
}

AimpActionResult^ AimpServiceActionManager::Register(Generic::ICollection<IAimpAction^>^ actions)
{
    ActionResultType result = ActionResultType::Fail;

    for each (IAimpAction^ item in actions)
    {
        const auto res = Register(item);

        if (res->ResultType != ActionResultType::OK)
        {
            return GetResult(result);
        }
    }

    return GetResult(result);
}

IAimpAction^ AimpServiceActionManager::CreateAction()
{
    IAIMPAction* action = nullptr;
    if (_core->CreateAction(&action) == ActionResultType::OK && action != nullptr)
    {
        return gcnew AimpAction(action);
    }

    return nullptr;
}

IAIMPServiceActionManager* AimpServiceActionManager::GetAimpService()
{
    IAIMPServiceActionManager* service = nullptr;
    GetService(IID_IAIMPServiceActionManager, &service);
    return service;
}
