// ============================================================================
// FFX.EXE — Audio System Stubs
// Generated from IDA naming: jarvis_goal
// Source: backups/phase2, wave_3, wave_14, wave_86, wave_10
// ============================================================================
#include "../include/ffx_structs.h"
#include "../include/ffx_vtables.h"

// FmodManager_ctor (0x6f9ec0)
// FmodManager constructor: zero-init, set vtable
void FmodManager_ctor(void *self) {}

// FmodManager_dtor (0x6fa050)
// FmodManager destructor
void FmodManager_dtor(void *self) {}

// FmodManager_dtorWithFree (0x6fa120)
// FmodManager destructor with HeapFree
void FmodManager_dtorWithFree(void *self) {}

// FmodManager_CreateSingleton (0x6fa190)
// Creates FmodManager global singleton
void __cdecl FmodManager_CreateSingleton(void) {}

// FmodManager_DestroySingleton (0x6fa270)
// Destroys FmodManager singleton
void __cdecl FmodManager_DestroySingleton(void) {}

// FmodManager_TickLoop (0x6fa7e0)
// FMOD event system update tick
void FmodManager_TickLoop(void *self) {}

// FmodManager_ThreadProc (0x6fa290)
// FmodManager worker thread entry point
unsigned long __stdcall FmodManager_ThreadProc(void *param) { return 0; }

// FmodManager_DispatchCallback (0x6fa8c0)
// Dispatches FMOD callbacks from worker thread
void FmodManager_DispatchCallback(void *self) {}

// FmodManager_LoadDllCallback (0x6f9da0)
// Callback for FMOD DLL loading
int FmodManager_LoadDllCallback(void *self) { return 0; }

// FmodManager_LoadDllOrFile (0x6f9ca0)
// Loads FMOD DLL or platform file
int FmodManager_LoadDllOrFile(void *self) { return 0; }

// FmodManager_FreeDll (0x6f9e00)
// Unloads FMOD DLL via FreeLibrary
void FmodManager_FreeDll(void *self) {}

// FmodManager_IsDllLoadOk (0x6f9c60)
// Checks FMOD DLL load status
int FmodManager_IsDllLoadOk(void *self) { return 0; }

// FmodManager_IsLoadState3 (0x6f9c50)
// Checks if FMOD load state == 3
int FmodManager_IsLoadState3(void *self) { return 0; }

// FmodManager_IsLoadState1or2 (0x6f9c80)
// Checks if FMOD load state is 1 or 2
int FmodManager_IsLoadState1or2(void *self) { return 0; }

// FmodManager_ReturnZero (0x6f9c40)
// Stub: always returns 0
int FmodManager_ReturnZero(void *self) { return 0; }

// FMOD_SoundSystem_Init (0x706910)
// Inits FMOD: EventSystem, stream buffer, 128 channels, file callbacks
int __cdecl FMOD_SoundSystem_Init(void) { return 0; }

// FMOD_FileSystem_CloseCallback (0x7085c0)
// FMOD file system close callback
int __cdecl FMOD_FileSystem_CloseCallback(void *handle) { return 0; }

// FMOD_FileSystem_OpenCallback (0x708600)
// FMOD file system open with arena allocator
int __cdecl FMOD_FileSystem_OpenCallback(const char *name,
                                         unsigned int *filesize,
                                         void **handle) {
  return 0;
}

// FMOD_FileSystem_ReadCallback (0x708690)
// FMOD file system read callback
int __cdecl FMOD_FileSystem_ReadCallback(void *handle, void *buffer,
                                         unsigned int sizebytes,
                                         unsigned int *bytesread) {
  return 0;
}

// FMOD_Music_FreeEventSlot (0x708810)
// Frees single FMOD music event slot (182-slot pool)
void FMOD_Music_FreeEventSlot(void *self, int slot) {}

// FMOD_Music_FreeAllEvents (0x708900)
// Frees all 182 FMOD music event slots
void FMOD_Music_FreeAllEvents(void *self) {}

// FMOD_Music_PlayTrack (0x7089f0)
// Starts or resumes music track by index
int FMOD_Music_PlayTrack(void *self, int track) { return 0; }

// FMOD_Music_ReadEvent (0x708af0)
// Reads music event state
int FMOD_Music_ReadEvent(void *self, int eventIdx) { return 0; }

// FMOD_Music_ClearAllEvents (0x708be0)
// Clears all 182 music event slots
void FMOD_Music_ClearAllEvents(void *self) {}

// FMOD_Music_UpdateAll (0x708f40)
// Updates all music events (volume transitions, fade)
void FMOD_Music_UpdateAll(void *self) {}

// FMOD_Music_SetAllPaused (0x7090f0)
// Pauses/resumes all music events
void FMOD_Music_SetAllPaused(void *self, int paused) {}

// FMOD_Music_StopOtherTracks (0x7092a0)
// Stops all tracks except current
void FMOD_Music_StopOtherTracks(void *self, int playingTrack) {}

// FMOD_Music_StartEvent (0x709360)
// Starts FMOD music event with callback + volume
int FMOD_Music_StartEvent(void *self, int eventIdx) { return 0; }

// FMOD_Music_SetMasterVolume (0x7094d0)
// Sets master music volume, propagates to events
void FMOD_Music_SetMasterVolume(void *self, float vol) {}

// FMOD_Music_SetEnabled (0x709610)
// Sets music enable flag with volume adjustment
void FMOD_Music_SetEnabled(void *self, int enabled) {}

// FMOD_Music_Release (0x709730)
// Releases FMOD music interface
void FMOD_Music_Release(void *self) {}

// FMOD_Music_StopTrack (0x709a90)
// Stops single track with fade callback
void FMOD_Music_StopTrack(void *self, int track) {}

// FMOD_Music_StopAll (0x709c00)
// Stops all tracks with fade
void FMOD_Music_StopAll(void *self) {}

// FMOD_Music_SwitchBank (0x709d70)
// Switches FMOD music bank group
void FMOD_Music_SwitchBank(void *self, int bankId) {}

// FMOD_Music_IsPlaying (0x709e70)
// Checks if BGM event state is playing
int FMOD_Music_IsPlaying(void *self) { return 0; }

// FMOD_Music_SetTrackVolume (0x709ec0)
// Sets volume for specific track index
void FMOD_Music_SetTrackVolume(void *self, int track, float vol) {}

// FMOD_Music_FadeOutTrack (0x709fa0)
// Fades out and stops a track
void FMOD_Music_FadeOutTrack(void *self, int track, int fadeMs) {}

// FMOD_Music_ApplyTrackVolume (0x70a010)
// Applies volume with fade calculation
void FMOD_Music_ApplyTrackVolume(void *self, int track) {}

// FMOD_Music_SetFadeParams (0x70a0e0)
// Sets fade parameters for volume transitions
void FMOD_Music_SetFadeParams(void *self, int fadeMs, float targetVol) {}

// FMOD_Voice_OnEventStopped (0x70a590)
// Voice event stop callback
void FMOD_Voice_OnEventStopped(void *self) {}

// FMOD_Voice_StopEvent (0x70a680)
// Stops voice event with retry loop
int FMOD_Voice_StopEvent(void *self, int eventIdx) { return 0; }

// FMOD_Voice_UpdateFade (0x70ade0)
// Updates voice volume fade
void FMOD_Voice_UpdateFade(void *self) {}

// FMOD_Voice_ReadEventByName (0x70aec0)
// Reads voice event by name string
int FMOD_Voice_ReadEventByName(void *self, const char *name) { return 0; }

// FMOD_Voice_Release (0x70b1a0)
// Releases FMOD voice interface (21 sub-events)
void FMOD_Voice_Release(void *self) {}

// FMOD_Voice_StartEvent (0x70b250)
// Starts voice event with callback + volume
int FMOD_Voice_StartEvent(void *self, int eventIdx) { return 0; }

// FMOD_Voice_SetMasterVolume (0x70b3a0)
// Sets voice master volume
void FMOD_Voice_SetMasterVolume(void *self, float vol) {}

// FMOD_Voice_SetPaused (0x70b420)
// Sets voice pause state
void FMOD_Voice_SetPaused(void *self, int paused) {}

// FMOD_Voice_SetPausedChecked (0x70b460)
// Sets paused with state verification
void FMOD_Voice_SetPausedChecked(void *self, int paused) {}

// FMOD_Voice_ReadData (0x70b520)
// Reads voice data from FMOD event
int FMOD_Voice_ReadData(void *self, void *buf, int size) { return 0; }

// FMOD_Voice_ReleaseAllEvents (0x70b570)
// Releases 21 sub-events + main event
void FMOD_Voice_ReleaseAllEvents(void *self) {}

// FMOD_Voice_ResetState (0x70b660)
// Resets voice state flags
void FMOD_Voice_ResetState(void *self) {}

// FMOD_Voice_PrepareEvent (0x70b6b0)
// Prepares voice event with timing
int FMOD_Voice_PrepareEvent(void *self, int eventIdx) { return 0; }

// FMOD_Voice_StopWithCleanup (0x70b7a0)
// Stops voice with proper cleanup
void FMOD_Voice_StopWithCleanup(void *self, int eventIdx) {}

// FMOD_Voice_UpdateTiming (0x70b840)
// Updates voice timing and volume transitions
void FMOD_Voice_UpdateTiming(void *self) {}

// FMOD_Voice_ApplyVolume (0x70b8e0)
// Applies volume to voice event
void FMOD_Voice_ApplyVolume(void *self) {}

// FFX_FmodVoice_Ctor (0x70c0a0)
// FFX_FmodVoice constructor: pools, mutex, event array
void FFX_FmodVoice_Ctor(void *self) {}

// FFX_FmodVoice_Dtor (0x70c580)
// FFX_FmodVoice destructor: release events, free pools
void FFX_FmodVoice_Dtor(void *self) {}

// FFX_FmodVoice_LoadVoiceProject (0x70a720)
// Loads FMOD voice project (.fev)
int FFX_FmodVoice_LoadVoiceProject(int projId) { return 0; }

// FFX_FmodVoice_InitBattleVoiceProject (0x70ab20)
// Inits separate battle voice project
int FFX_FmodVoice_InitBattleVoiceProject(void) { return 0; }

// FFX_FmodVoice_LoadMapperData (0x70ac80)
// Loads voice event name-to-ID mapping
int FFX_FmodVoice_LoadMapperData(void *self, const void *data) { return 0; }

// FFX_FmodVoice_UpdateEventState (0x70ade0)
// Updates voice event state machine
void FFX_FmodVoice_UpdateEventState(void *self) {}

// FFX_FmodVoice_ReadEventData (0x70aec0)
// Reads and processes voice event data buffer
int FFX_FmodVoice_ReadEventData(void *self, int eventIdx) { return 0; }

// FFX_FmodVoice_UpdatePlayback (0x70b250)
// Updates voice playback: position, volume, state
void FFX_FmodVoice_UpdatePlayback(void *self) {}

// FFX_FmodVoice_ClampVolume (0x70b3a0)
// Clamps voice volume to 0.0-1.0
float FFX_FmodVoice_ClampVolume(void *self, float vol) { return 0.0f; }

// FFX_FmodVoice_SetPlaybackMode (0x70b420)
// Sets voice mode (0=off, 1-4=modes)
void FFX_FmodVoice_SetPlaybackMode(void *self, int mode) {}

// FFX_FmodVoice_SetPaused (0x70b460)
// Sets voice paused state on FMOD event
void FFX_FmodVoice_SetPaused(void *self, int paused) {}

// FFX_FmodVoice_ApplyVolume (0x70b520)
// Applies volume to voice FMOD event
void FFX_FmodVoice_ApplyVolume(void *self) {}

// FFX_FmodVoice_ReleaseAllVoiceEvents (0x70b570)
// Releases all 21 voice sub-events
void FFX_FmodVoice_ReleaseAllVoiceEvents(void *self) {}

// FFX_FmodVoice_StartEventWithCallback (0x70b6b0)
// Starts voice event with callback
int FFX_FmodVoice_StartEventWithCallback(void *self, int eventIdx) { return 0; }

// FFX_FmodVoice_StopEvent (0x70b7a0)
// Stops voice event
void FFX_FmodVoice_StopEvent(void *self, int eventIdx) {}

// FFX_FmodVoice_ProcessTimeoutEvent (0x70b840)
// Auto-stops voice after timeout
void FFX_FmodVoice_ProcessTimeoutEvent(void *self) {}

// FFX_FmodVoice_SetEventVolume (0x70b8e0)
// Sets specific voice event volume
void FFX_FmodVoice_SetEventVolume(void *self, int eventIdx, float vol) {}

// FFX_FmodVoice_FadeVolume (0x70b970)
// Fades voice volume over time
void FFX_FmodVoice_FadeVolume(void *self, float targetVol, int durMs) {}

// FFX_FmodVoice_LoadFsbBank (0x70e3b0)
// Loads FSB bank file
int FFX_FmodVoice_LoadFsbBank(const char *path) { return 0; }

// FFX_FmodVoice_SetChannelVolume (0x70e4e0)
// Sets voice channel volume (stereo balance)
void FFX_FmodVoice_SetChannelVolume(void *self, int ch, float vol) {}

// FFX_FmodVoice_ReleaseSound (0x70e530)
// Releases FMOD sound object
void FFX_FmodVoice_ReleaseSound(void *self) {}

// FFX_FmodVoice_PlaySound (0x70e560)
// Plays FMOD one-shot sound
int FFX_FmodVoice_PlaySound(void *self, int soundIdx) { return 0; }

// FFX_FmodVoice_VolumeIntToFloat (0x70eb00)
// Converts int volume (0-255) to float (0.0-1.0)
float FFX_FmodVoice_VolumeIntToFloat(int vol) { return 0.0f; }

// FFX_FmodSfx_CheckSequenceReady (0x70c8b0)
// Checks if SFX sequence is ready
int FFX_FmodSfx_CheckSequenceReady(void *self, int seqId) { return 0; }

// FFX_FmodSfx_DispatchSequenceEvents (0x70c9d0)
// Dispatches SFX sequence events
void FFX_FmodSfx_DispatchSequenceEvents(void *self, int seqId) {}

// FFX_FmodSfx_LoadSfxProjectById (0x70cff0)
// Loads SFX project (.fev) by ID
int FFX_FmodSfx_LoadSfxProjectById(int projId) { return 0; }

// FFX_FmodSfx_SetVolumePropagate (0x70d5e0)
// Sets volume, propagates to active SFX
void FFX_FmodSfx_SetVolumePropagate(void *self, float vol) {}

// FFX_FmodVoice_ClearAllSfxProjects (0x70d860)
// Clears all loaded SFX projects
void FFX_FmodVoice_ClearAllSfxProjects(void *self) {}

// FFX_FmodSfx_ShutdownAllEvents (0x70db70)
// Shuts down all SFX events
void FFX_FmodSfx_ShutdownAllEvents(void *self) {}

// FFX_FmodSfx_ReloadSfxProjects (0x70dc90)
// Reloads all SFX projects
void FFX_FmodSfx_ReloadSfxProjects(void *self) {}

// FFX_FmodSfx_UnloadProjectsByMask (0x70ddf0)
// Unloads SFX projects by mask
void FFX_FmodSfx_UnloadProjectsByMask(void *self, int mask) {}

// FFX_FmodSfx_UpdateSfxEvents (0x70dfa0)
// Updates active SFX events (pos, vol, state)
void FFX_FmodSfx_UpdateSfxEvents(void *self) {}

// FFX_FmodSfx_SetPausedAll (0x70f1e0)
// Pauses/resumes all SFX events
void FFX_FmodSfx_SetPausedAll(void *self, int paused) {}

// FFX_FmodSfx_SetVolumeAll (0x70f220)
// Sets volume for all SFX events
void FFX_FmodSfx_SetVolumeAll(void *self, float vol) {}

// FFX_FmodSfx_StartEventsFromSequence (0x70f3f0)
// Starts SFX events from a sequence
void FFX_FmodSfx_StartEventsFromSequence(void *self, int seqId) {}

// FFX_SoundCmd_CreateLoopRequest (0x710860)
// Creates loop sound command request
int FFX_SoundCmd_CreateLoopRequest(int soundId, int loopCount) { return 0; }

// FFX_SoundCmd_AllocAndInsertRequest (0x710c80)
// Alloc + inserts sound command into queue
int FFX_SoundCmd_AllocAndInsertRequest(int cmdType, int param) { return 0; }

// FFX_Sound_FmodSystemRelease (0xaf0850)
// Releases FMOD sound system (COMDAT)
void __cdecl FFX_Sound_FmodSystemRelease(void) {}

// FFX_Sound_FmodMemoryAlloc (0xaee420)
// Allocates via FMOD memory pool
void *__cdecl FFX_Sound_FmodMemoryAlloc(unsigned int size) { return 0; }

// FFX_Sound_FmodMemoryGetStats (0xaef810)
// Gets FMOD memory allocation stats
int __cdecl FFX_Sound_FmodMemoryGetStats(int *alloc, int *used) { return 0; }

// FFX_Sound_FmodResultCheck_structural (0xaea7b0)
// Checks FMOD result code (COMDAT)
void __cdecl FFX_Sound_FmodResultCheck_structural(int result) {}

// FFX_Sound_FmodMusicSetVolume (0xafb490)
// Sets FMOD music volume (COMDAT)
void __cdecl FFX_Sound_FmodMusicSetVolume(float vol) {}

// FFX_Sound_FmodSfxOneShot (0xaf7930)
// Plays one-shot SFX (fire-and-forget)
void __cdecl FFX_Sound_FmodSfxOneShot(int sfxId) {}

// FFX_Sound_FmodSfxOneShot3D_candidate (0xaf7cb0)
// Plays 3D-positioned one-shot SFX
void __cdecl FFX_Sound_FmodSfxOneShot3D_candidate(int sfxId, float x, float y,
                                                  float z) {}

// FFX_Sound_FmodSfxStopById (0xaf5810)
// Stops SFX by instance ID
void __cdecl FFX_Sound_FmodSfxStopById(int sfxId) {}

// FFX_Sound_FmodSfxPlayById (0xaf5950)
// Plays SFX by ID
void __cdecl FFX_Sound_FmodSfxPlayById(int sfxId) {}

// FFX_Sound_FmodSfxSetMasterVolume (0xaf50d0)
// Sets SFX master volume
void __cdecl FFX_Sound_FmodSfxSetMasterVolume(float vol) {}

// FFX_Sound_FmodSfxStopAll (0xaf5010)
// Stops all active SFX
void __cdecl FFX_Sound_FmodSfxStopAll(void) {}

// FFX_Sound_FmodSfxSetPanById (0xaf3e70)
// Sets SFX pan by instance ID
void __cdecl FFX_Sound_FmodSfxSetPanById(int sfxId, float pan) {}

// FFX_Sound_FmodSfxSetVolumeById (0xaf5750)
// Sets SFX volume by instance ID
void __cdecl FFX_Sound_FmodSfxSetVolumeById(int sfxId, float vol) {}

// FFX_Sound_FmodSfxPlaySyncFromField (0xaf5650)
// Plays SFX from field script sync
void __cdecl FFX_Sound_FmodSfxPlaySyncFromField(int sfxId) {}

// FFX_Sound_FmodSfxPauseById (0xaf40b0)
// Pauses SFX by instance ID
void __cdecl FFX_Sound_FmodSfxPauseById(int sfxId) {}

// FFX_Sound_FmodSfxResumeById (0xaf4230)
// Resumes SFX by instance ID
void __cdecl FFX_Sound_FmodSfxResumeById(int sfxId) {}

// FFX_Sound_FmodSfxIsPlayingById (0xaf43b0)
// Checks if SFX instance is playing
int __cdecl FFX_Sound_FmodSfxIsPlayingById(int sfxId) { return 0; }

// FFX_Sound_FmodSfxSetVolumeByBank_structural (0xaf3ab0)
// Sets volume for SFX bank (COMDAT)
void __cdecl FFX_Sound_FmodSfxSetVolumeByBank_structural(int bankId,
                                                         float vol) {}

// FFX_Sound_FmodSfxSetPanByBank_structural (0xaf3c30)
// Sets pan for SFX bank (COMDAT)
void __cdecl FFX_Sound_FmodSfxSetPanByBank_structural(int bankId, float pan) {}

// FFX_Sound_FmodSfxPreloadBankByMusicFtp_structural (0xaf1a10)
// Preloads SFX bank by FTP path (COMDAT)
void __cdecl FFX_Sound_FmodSfxPreloadBankByMusicFtp_structural(int bankId) {}

// FFX_Sound_QueueSoundEffect (0x81e520)
// Queues SPU sound effect
void __cdecl FFX_Sound_QueueSoundEffect(int soundId, int volL, int volR) {}

// FFX_Sound_PitchDirectWrapper (0x81e590)
// Direct SPU pitch setter
void __cdecl FFX_Sound_PitchDirectWrapper(int ch, int pitch) {}

// FFX_Sound_InitSystem (0x8773a0)
// Inits SPU sound system
void __cdecl FFX_Sound_InitSystem(void) {}

// FFX_Sound_UpdateViewMatrix (0x8773f0)
// Updates 3D listener position
void __cdecl FFX_Sound_UpdateViewMatrix(void *viewMtx) {}

// FFX_Sound_SpuSystemInit (0x8864b0)
// Inits legacy SPU2 system
void __cdecl FFX_Sound_SpuSystemInit(void) {}

// FFX_Sound_SpuPlayMusicSlot (0x886610)
// Plays SPU music slot
void __cdecl FFX_Sound_SpuPlayMusicSlot(int slot) {}

// FFX_Sound_SpuStopMusicAndFlush (0x8868c0)
// Stops SPU music, flushes buffer
void __cdecl FFX_Sound_SpuStopMusicAndFlush(void) {}

// FFX_Sound_SpuSetMasterVol (0x886e40)
// Sets SPU master volume
void __cdecl FFX_Sound_SpuSetMasterVol(int vol) {}

// FFX_Sound_SpuPlaySfxOnChannel (0x886db0)
// Plays SFX on specific SPU channel
void __cdecl FFX_Sound_SpuPlaySfxOnChannel(int ch, int soundId) {}

// FFX_Sound_SpuSetChannelVol (0x886d50)
// Sets SPU channel volume (L/R)
void __cdecl FFX_Sound_SpuSetChannelVol(int ch, int volL, int volR) {}

// FFX_Sound_SpuSetChannelPan (0x886ef0)
// Sets SPU channel pan
void __cdecl FFX_Sound_SpuSetChannelPan(int ch, int pan) {}

// FFX_Sound_SpuProcessIdleTick (0x886f80)
// SPU idle tick processing
void __cdecl FFX_Sound_SpuProcessIdleTick(void) {}

// FFX_Sound_SpuPauseChannel (0x886c80)
// Pauses SPU channel
void __cdecl FFX_Sound_SpuPauseChannel(int ch) {}

// FFX_Sound_SpuUnpauseChannel (0x886cb0)
// Unpauses SPU channel
void __cdecl FFX_Sound_SpuUnpauseChannel(int ch) {}

// FFX_Sound_SpuStopMusic (0x886a50)
// Stops SPU music
void __cdecl FFX_Sound_SpuStopMusic(void) {}

// FFX_Sound_SpuSetMuteAll (0x8875a0)
// Mutes/unmutes all SPU channels
void __cdecl FFX_Sound_SpuSetMuteAll(int muted) {}

// FFX_Sound_SpuFlushAndSyncAll (0x887b40)
// Flushes all SPU buffers
void __cdecl FFX_Sound_SpuFlushAndSyncAll(void) {}

// ============================================================================
// NÍVEL 2-B: FMOD AUDIO EXPANSION — High-level FmodManager API stubs
// ============================================================================

// FmodManager_Init (0x6fa8d0)
// Initializes FMOD system: create EventSystem, set 128 channels, load master
// bank
int FmodManager_Init(void *self) { return 0; }

// FmodManager_Update (0x6fa940)
// Per-frame FMOD update: pump callbacks, update listener, sync events
void FmodManager_Update(void *self) {}

// FmodManager_LoadBank (0x6fa9b0)
// Loads FMOD bank file by path, returns bank handle
int FmodManager_LoadBank(void *self, const char *bankPath) { return 0; }

// FmodManager_UnloadBank (0x6faa20)
// Unloads previously loaded FMOD bank by handle
void FmodManager_UnloadBank(void *self, int bankHandle) {}

// FmodManager_PlayEvent (0x6faa80)
// Plays a named FMOD event (music/sfx/voice) by GUID or path
int FmodManager_PlayEvent(void *self, const char *eventPath) { return 0; }

// FmodManager_StopEvent (0x6faae0)
// Stops a playing event by instance ID
void FmodManager_StopEvent(void *self, int eventId) {}

// FmodManager_SetEventParameter (0x6fab40)
// Sets a named parameter on a running event instance
void FmodManager_SetEventParameter(void *self, int eventId,
                                   const char *paramName, float value) {}

// FmodManager_SetMasterVolume (0x6faba0)
// Sets master bus volume (all categories)
void FmodManager_SetMasterVolume(void *self, float vol) {}

// FmodManager_SetMusicVolume (0x6fac00)
// Sets music category volume only
void FmodManager_SetMusicVolume(void *self, float vol) {}

// FmodManager_SetSfxVolume (0x6fac60)
// Sets SFX category volume only
void FmodManager_SetSfxVolume(void *self, float vol) {}

// FmodManager_GetMusicNameFromId (0x6facc0)
// Returns BGM name string from music track ID
const char *FmodManager_GetMusicNameFromId(void *self, int musicId) {
  return 0;
}

// FmodManager_GetMusicIdFromIndex (0x6fad20)
// Returns music track ID from sequential index
int FmodManager_GetMusicIdFromIndex(void *self, int index) { return 0; }

// FmodManager_SetMusicById (0x6fad80)
// Starts BGM by music track ID, stops previous
void FmodManager_SetMusicById(void *self, int musicId) {}

// FmodManager_FadeMusic (0x6fade0)
// Crossfades to new BGM over specified duration
void FmodManager_FadeMusic(void *self, int musicId, int fadeMs) {}

// FmodManager_StopAll (0x6fae40)
// Stops all active events (music + sfx + voice)
void FmodManager_StopAll(void *self) {}

// FmodManager_PauseAll (0x6faea0)
// Pauses all active audio events
void FmodManager_PauseAll(void *self) {}

// FmodManager_ResumeAll (0x6faf00)
// Resumes all paused audio events
void FmodManager_ResumeAll(void *self) {}

// FmodManager_SetReverb (0x6faf60)
// Sets global reverb preset or parameters
void FmodManager_SetReverb(void *self, int reverbPreset, float mix) {}

// FmodManager_SetListenerPosition (0x6fafc0)
// Sets FMOD 3D listener position from field/view matrix
void FmodManager_SetListenerPosition(void *self, float x, float y, float z) {}

// FmodManager_UpdateListener (0x6fb020)
// Updates listener position, velocity, orientation from camera
void FmodManager_UpdateListener(void *self, const void *camMtx) {}

// ============================================================================
// NÍVEL 2-C: FFX AUDIO CONTEXT + SPATIAL — Listener, light, decode
// ============================================================================

// FFX_AudioListenerContext_Update (0x6fb100)
// Updates audio listener context from camera: position, velocity, forward/up
// vectors
void FFX_AudioListenerContext_Update(void *self, const void *camMtx) {}

// FFX_AudioLight_SetVolume (0x6fb170)
// Sets volume multiplier for an audio light (positioned ambient emitter)
void FFX_AudioLight_SetVolume(void *self, int lightIdx, float vol) {}

// FFX_AudioLight_SetColor (0x6fb1e0)
// Sets color (filter) for an audio light; maps RGB to frequency band
// multipliers
void FFX_AudioLight_SetColor(void *self, int lightIdx, float r, float g,
                             float b) {}

// FFX_AudioLight_SetTypeById (0x6fb250)
// Sets audio light type by enum ID (point, cone, ambient, directional)
void FFX_AudioLight_SetTypeById(void *self, int lightIdx, int typeId) {}

// FFX_AudioLight_UpdateShadeCoeffs (0x6fb2c0)
// Recomputes occlusion/shade coefficients for all audio lights against geometry
void FFX_AudioLight_UpdateShadeCoeffs(void *self) {}

// FFX_AudioLight_UpdateFieldMapLights (0x6fb330)
// Synchronises audio light positions/state from field map lighting data
void FFX_AudioLight_UpdateFieldMapLights(void *self) {}

// FFX_Audio_DecodeSamples (0x6fb3a0)
// Decodes a block of compressed audio samples (VAG/ADPCM) to PCM output buffer
int FFX_Audio_DecodeSamples(const void *inBuf, void *outBuf, int numSamples) {
  return 0;
}

// FFX_Audio_SpatialNodeDecodeProcess (0x6fb410)
// Processes spatial audio node: decode + apply 3D position + output to channel
// mix
void FFX_Audio_SpatialNodeDecodeProcess(void *self) {}

// FFX_Sound_SetGlobalAndExec (0x6fb480)
// Sets a named global sound variable and executes its side effects (volume,
// mute, switch)
void __cdecl FFX_Sound_SetGlobalAndExec(const char *varName, float value) {}

// FFX_Sound_ManageBattleAudioBySlot (0x6fb4f0)
// Manages battle audio state per slot: fanfare, low-HP beep, victory, game-over
void __cdecl FFX_Sound_ManageBattleAudioBySlot(int slot, int state) {}

// ============================================================================
// NÍVEL 2-D: FFX HIGH-LEVEL SOUND API — Simplified control stubs
// ============================================================================

// FFX_Sound_PlayBGM (0x6F6000)
// Plays background music by track ID
int FFX_Sound_PlayBGM(void *self) { return 0; }

// FFX_Sound_StopBGM (0x6F6010)
// Stops background music playback
int FFX_Sound_StopBGM(void *self) { return 0; }

// FFX_Sound_PlaySFX (0x6F6020)
// Plays a sound effect by SFX ID
int FFX_Sound_PlaySFX(void *self) { return 0; }

// FFX_Sound_StopSFX (0x6F6030)
// Stops a playing sound effect by SFX ID
int FFX_Sound_StopSFX(void *self) { return 0; }

// FFX_Sound_SetMasterVolume (0x6F6040)
// Sets master volume for all audio categories
int FFX_Sound_SetMasterVolume(void *self) { return 0; }

// FFX_Sound_SetBGMVolume (0x6F6050)
// Sets volume for background music category only
int FFX_Sound_SetBGMVolume(void *self) { return 0; }

// FFX_Sound_SetSFXVolume (0x6F6060)
// Sets volume for sound effects category only
int FFX_Sound_SetSFXVolume(void *self) { return 0; }

// FFX_Sound_LoadBank (0x6F6070)
// Loads an audio bank file by path, returns bank handle
int FFX_Sound_LoadBank(void *self) { return 0; }
