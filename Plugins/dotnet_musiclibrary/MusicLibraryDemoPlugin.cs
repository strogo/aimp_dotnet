﻿using System;
using AIMP.SDK;
using AIMP.SDK.MusicLibrary.DataStorage;
using AIMP.SDK.MusicLibrary.Presets;

namespace dotnet_musiclibrary
{
    [AimpPlugin("MusicLibraryDemoPlugin", "Martin", "1.0.0", AimpPluginType = AimpPluginType.Addons, FullDescription = "MusicLibrary demo plugin")]
    public class MusicLibraryDemoPlugin : AimpPlugin
    {
        public override void Initialize()
        {
            IAimpDataStorage storage;
            //IAimpGroupingPresets presets;
            if (Player.ServiceMusicLibrary.GetActiveStorage(out storage) == AimpActionResult.Ok)
            {
                System.Diagnostics.Debug.WriteLine($"{nameof(storage.Id)}:{storage.Id}\t{nameof(storage.Caption)}:{storage.Caption}");

                if (storage.GroupingPreset != null)
                {
                    System.Diagnostics.Debug.WriteLine($"{nameof(storage.GroupingPreset.Id)}:{storage.GroupingPreset.Id}\t{nameof(storage.GroupingPreset.Name)}:{storage.GroupingPreset.Name}");
                }
            }


            var demoPlugin = new DemoMusicLibrary();
            Player.Core.RegisterExtension(demoPlugin);
        }

        public override void Dispose()
        {
            
        }
    }
}
