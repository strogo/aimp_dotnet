﻿// ----------------------------------------------------
// 
// AIMP DotNet SDK
// 
// Copyright (c) 2014 - 2020 Evgeniy Bogdan
// https://github.com/martin211/aimp_dotnet
// 
// Mail: mail4evgeniy@gmail.com
// 
// ----------------------------------------------------

using AIMP.SDK.Playlist;
using NUnit.Framework;

namespace Aimp.TestRunner.UnitTests.Playback
{
    [TestFixture]
    public class AimpPlaybackQueueServiceTests : AimpIntegrationTest
    {
        [Test]
        public void GetNextTrack_ReturnItem()
        {
            ExecuteInMainThread(() =>
            {
                var createPlaylistResult = Player.ServicePlaylistManager.CreatePlaylistFromFile(PlaylistPath, true);
                var item = Player.ServicePlaybackQueue.GetNextTrack();
                AssertOKResult(item.ResultType, "Cannot get next track from playback queue");
                this.NotNull(item.Result);

                createPlaylistResult.Result.Close(PlaylistCloseFlag.ForceRemove);
            });
        }

        [Test]
        public void GetPrevTrack_ReturnItem()
        {
            ExecuteInMainThread(() =>
            {
                var createPlaylistResult = Player.ServicePlaylistManager.CreatePlaylistFromFile(PlaylistPath, true);
                var item = Player.ServicePlaybackQueue.GetPrevTrack();
                AssertOKResult(item.ResultType, "Cannot get prev track from playback queue");
                this.NotNull(item.Result);

                createPlaylistResult.Result.Close(PlaylistCloseFlag.ForceRemove);
            });
        }
    }
}