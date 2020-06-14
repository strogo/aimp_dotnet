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

#pragma once

template<class TAimpObject>
public ref class AimpObject
{
protected:
    AimpObject() {}

    [System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
    TAimpObject *_aimpObject;
public:
    AimpObject(TAimpObject *aimpObject) : _aimpObject(aimpObject)
    {
        AimpMemoryManager::getInstance().AddObject(this->GetHashCode(), aimpObject);
    }

    !AimpObject()
    {
        FreeResources();
        AimpMemoryManager::getInstance().Release(this->GetHashCode());
    }

    ~AimpObject()
    {
        this->!AimpObject();
    }
protected:
    ActionResultType CheckResult(HRESULT result)
    {
        return Utils::CheckResult(result);
    }

    virtual void FreeResources()
    {
        
    }
internal:
    property TAimpObject *InternalAimpObject
    {
        TAimpObject *get()
        {
            return _aimpObject;
        }
    }
};
