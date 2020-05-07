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
using System;
using System.Collections;
using System.Collections.Generic;
using AIMP.SDK;
using AIMP.SDK.MusicLibrary;
using AIMP.SDK.MusicLibrary.DataFilter;
using AIMP.SDK.MusicLibrary.DataStorage;
using AIMP.SDK.Playlist;
using AIMP.SDK.Threading;

namespace AIMP.DotNet.MusicLibrary.Preimage
{
    public class TestMediaLibraryPreimage : IAimpPlaylistPreimageDataProvider, IAimpMusicLibraryPlaylistPreimage
    {
        private readonly MediaLibraryPreimageFactory _factory;

        public TestMediaLibraryPreimage(MediaLibraryPreimageFactory factory)
        {
            _factory = factory;
            _factory.Preimages.Add(this);
            AutoSync = true;
            AutoSyncOnStartup = true;
        }

        public string FactoryId
        {
            get
            {
                string id;
                _factory.GetId(out id);
                return id;
            }
        }

        public bool AutoSync { get; set; }

        public bool AutoSyncOnStartup { get; set; }

        public bool HasDialog => true;

        public string SortTemplate => string.Empty;

        public ActionResultType ConfigLoad(IAimpStream stream)
        {
            return ActionResultType.OK;
        }

        public ActionResultType ConfigSave(IAimpStream stream)
        {
            return ActionResultType.OK;
        }

        public ActionResultType ExecuteDialog(IntPtr ownerHandle)
        {
            return ActionResultType.OK;
        }

        public void Initialize(IAimpPlaylistPreimageListener listener)
        {
            
        }

        public void FinalizeObject()
        {
            
        }

        public ActionResultType GetFilter(out IAimpDataFieldFilter filter)
        {
            filter = null;
            return ActionResultType.OK;
        }

        public ActionResultType GetStorage(out IAimpDataStorage storage)
        {
            storage = null;
            return ActionResultType.OK;
        }

        public ActionResultType GetFiles(IAimpTaskOwner owner, out int preimageFlags, out IList dataList)
        {
            preimageFlags = 0;
            dataList = new List<string>
            {
                Environment.GetFolderPath(Environment.SpecialFolder.MyMusic)
            };

            return ActionResultType.OK;
        }
    }
}