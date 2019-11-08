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
#include "AimpServiceAlbumArt.h"

using namespace AIMP::SDK;

AimpServiceAlbumArt::AimpServiceAlbumArt(ManagedAimpCore^ core) : BaseAimpService<IAIMPServiceAlbumArt>(core)
{
}

AimpServiceAlbumArt::~AimpServiceAlbumArt()
{
    delete _findCallback;
}

bool AimpServiceAlbumArt::FindInFiles::get()
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            int val = 0;
            prop->GetValueAsInt32(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_FILES, &val);
            return val != 0;
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }

    return false;
}

void AimpServiceAlbumArt::FindInFiles::set(bool value)
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            prop->SetValueAsInt32(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_FILES, value);
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }
}

bool AimpServiceAlbumArt::FindInInternet::get()
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            int val = 0;
            prop->GetValueAsInt32(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_INTERNET, &val);
            return val != 0;
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }

    return false;
}

void AimpServiceAlbumArt::FindInInternet::set(bool value)
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            prop->SetValueAsInt32(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_INTERNET, value ? 1 : 0);
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }
}

array<String^>^ AimpServiceAlbumArt::FileMasks::get()
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            IAIMPString* str;
            prop->GetValueAsObject(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_FILES_MASKS, IID_IAIMPString, reinterpret_cast<void**>(&str));
            String^ result = gcnew String(str->GetData());
            ReleaseObject(str);
            return result->Split(gcnew array<WCHAR>{';'});
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }

    return nullptr;
}

void AimpServiceAlbumArt::FileMasks::set(array<String^>^ val)
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            auto str = String::Empty;
            for (auto i = 0; i < val->Length; i++)
            {
                str += val[i] + ";";
            }

            auto s = AimpConverter::ToAimpString(str);
            prop->SetValueAsObject(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_FILES_MASKS, s);
            ReleaseObject(s);
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }
}

array<String^>^ AimpServiceAlbumArt::FileExtensions::get()
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            IAIMPString* str;
            prop->GetValueAsObject(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_FILES_EXTS, IID_IAIMPString,
                                   reinterpret_cast<void**>(&str));
            auto result = gcnew String(str->GetData());
            ReleaseObject(str);
            return result->Split(gcnew array<WCHAR>{';'});
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }

    return nullptr;
}

void AimpServiceAlbumArt::FileExtensions::set(array<System::String^>^ val)
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            auto str = String::Empty;
            for (auto i = 0; i < val->Length; i++)
            {
                str += val[i] + ";";
            }

            auto s = AimpConverter::ToAimpString(str);
            prop->SetValueAsObject(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_FILES_EXTS, s);
            ReleaseObject(s);
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }
}

int AimpServiceAlbumArt::MaxFileSize::get()
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            int val = 0;
            prop->GetValueAsInt32(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_INTERNET_MAX_FILE_SIZE, &val);
            return val > 0;
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }

    return 0;
}

void AimpServiceAlbumArt::MaxFileSize::set(int value)
{
    IAIMPServiceAlbumArt* service = GetAimpService();
    IAIMPPropertyList* prop = nullptr;

    try
    {
        if (service != nullptr)
        {
            service->QueryInterface(IID_IAIMPPropertyList, reinterpret_cast<void**>(&prop));
            prop->SetValueAsInt32(AIMP_SERVICE_ALBUMART_PROPID_FIND_IN_INTERNET, value);
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(prop);
    }
}

void AimpServiceAlbumArt::OnAlbumArtReceive(IAIMPImage* image, IAIMPImageContainer* image_container, void* user_data)
{
    AimpGetAlbumArtEventArgs^ args = gcnew AimpGetAlbumArtEventArgs();
    if (image == nullptr && image_container == nullptr)
    {
        Completed(this, args);
        return;
    }

    if (image_container != nullptr && image == nullptr)
    {
        args->CoverImage = AimpConverter::ToManagedBitmap(image_container);
    }
    else if (image != nullptr)
    {
        args->CoverImage = AimpConverter::ToManagedBitmap(image);
    }

    Completed(this, args);
}

IntPtr AimpServiceAlbumArt::GetImage(String^ fileUrl, String^ artist, String^ album, AimpFindCovertArtType flags, Object^ userData)
{
    void* taskId;
    _findCallback = gcnew OnFindCoverCallback(this, &AIMP::AimpServiceAlbumArt::OnAlbumArtReceive);
    IntPtr thunk = Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(_findCallback);
    auto sFileUrl = AimpConverter::ToAimpString(fileUrl);
    auto sArtist = AimpConverter::ToAimpString(artist);
    auto sAlbum = AimpConverter::ToAimpString(album);

    IAIMPServiceAlbumArt* service = GetAimpService();
    try
    {
        if (service != nullptr)
        {
            service->Get(
                sFileUrl,
                sArtist,
                sAlbum,
                DWORD(flags),
                static_cast<TAIMPServiceAlbumArtReceiveProc(_stdcall *)>(thunk.ToPointer()),
                reinterpret_cast<void*>(&userData), &taskId);

            return IntPtr(taskId);
        }
    }
    finally
    {
        ReleaseObject(service);
        ReleaseObject(sFileUrl);
        ReleaseObject(sAlbum);
        ReleaseObject(sArtist);
    }

    return IntPtr::Zero;
}

IntPtr AimpServiceAlbumArt::GetImage(IAimpFileInfo^ fileInfo, AimpFindCovertArtType flags, Object^ userData)
{
    void* taskId = nullptr;
    _findCallback = gcnew OnFindCoverCallback(this, &AIMP::AimpServiceAlbumArt::OnAlbumArtReceive);
    IntPtr thunk = System::Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(_findCallback);
    //AimpFileInfo^ fi = static_cast<AimpFileInfo^>(fileInfo);

    IAIMPServiceAlbumArt* service = GetAimpService();
    try
    {
        if (service != nullptr)
        {
            service->Get2(
                static_cast<AimpFileInfo^>(fileInfo)->InternalAimpObject,
                DWORD(flags),
                static_cast<TAIMPServiceAlbumArtReceiveProc(_stdcall *)>(thunk.ToPointer()),
                reinterpret_cast<void*>(&userData),
                &taskId);

            return IntPtr(taskId);
        }
    }
    finally
    {
        ReleaseObject(service);
    }

    return IntPtr::Zero;
}

void AimpServiceAlbumArt::Cancel(IntPtr taskId, AimpFindCovertArtType flags)
{
    if (taskId != IntPtr::Zero)
    {
        IAIMPServiceAlbumArt* service = GetAimpService();
        try
        {
            if (service != nullptr)
            {
                service->Cancel(static_cast<void*>(taskId), DWORD(flags));
            }
        }
        finally
        {
            ReleaseObject(service);
        }
    }
}

IAIMPServiceAlbumArt* AimpServiceAlbumArt::GetAimpService()
{
    IAIMPServiceAlbumArt* service = nullptr;
    GetService(IID_IAIMPServiceAlbumArt, &service);
    return service;
}