﻿// ----------------------------------------------------
// 
// AIMP DotNet SDK
// 
// Copyright (c) 2014 - 2019 Evgeniy Bogdan
// https://github.com/martin211/aimp_dotnet
// 
// Mail: mail4evgeniy@gmail.com
// 
// ----------------------------------------------------

namespace AIMP.SDK.FileManager.Commands
{
    public interface IAimpFileSystemCommandOpenFileFolder : IAimpFileSystemCustomFileCommand
    {
        AimpActionResult CanProcess(string file);

        AimpActionResult Process(string file);
    }
}