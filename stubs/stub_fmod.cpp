// ============================================================================
// FMOD Ex — Forwarding Stub
// Carrega fmodex.dll + fmod_event.dll em runtime e faz forwarding
// ============================================================================
#include <windows.h>

// Forwarding helper
static FARPROC resolve_fmod(const char *name) {
  static HMODULE h = LoadLibraryA("fmodex.dll");
  return h ? GetProcAddress(h, name) : NULL;
}
static FARPROC resolve_fmod_event(const char *name) {
  static HMODULE h = LoadLibraryA("fmod_event.dll");
  return h ? GetProcAddress(h, name) : NULL;
}

// fmodex.dll exports
#define FMOD_FORWARD(name)                                                     \
  void name() {                                                                \
    static FARPROC f = resolve_fmod(#name);                                    \
    if (f)                                                                     \
      f();                                                                     \
  }

FMOD_FORWARD(FMOD_Memory_Initialize)
FMOD_FORWARD(FMOD_Memory_GetStats)
FMOD_FORWARD(FMOD_System_Create)
FMOD_FORWARD(FMOD_System_Release)
FMOD_FORWARD(FMOD_System_Init)
FMOD_FORWARD(FMOD_System_Close)
FMOD_FORWARD(FMOD_System_PlaySound)
FMOD_FORWARD(FMOD_System_SetFileSystem)
FMOD_FORWARD(FMOD_System_CreateSound)
FMOD_FORWARD(FMOD_System_SetStreamBufferSize)
FMOD_FORWARD(FMOD_Sound_Release)
FMOD_FORWARD(FMOD_Sound_GetName)
FMOD_FORWARD(FMOD_Sound_GetNumSubSounds)
FMOD_FORWARD(FMOD_Sound_GetSubSound)
FMOD_FORWARD(FMOD_Sound_GetOpenState)
FMOD_FORWARD(FMOD_Sound_GetData)
FMOD_FORWARD(FMOD_Channel_SetVolume)
FMOD_FORWARD(FMOD_Channel_GetVolume)
FMOD_FORWARD(FMOD_Channel_SetPaused)
FMOD_FORWARD(FMOD_Channel_GetPaused)
FMOD_FORWARD(FMOD_Channel_Stop)
FMOD_FORWARD(FMOD_Channel_SetPan)
FMOD_FORWARD(FMOD_Channel_GetPan)
FMOD_FORWARD(FMOD_Channel_GetLoopCount)
FMOD_FORWARD(FMOD_Channel_SetPriority)
FMOD_FORWARD(FMOD_ChannelGroup_GetNumChannels)
FMOD_FORWARD(FMOD_ChannelGroup_GetChannel)

// fmod_event.dll exports (mangled C++ names - using ordinals or forwarding)
#define FMOD_EVENT_FORWARD(name)                                               \
  void name() {                                                                \
    static FARPROC f = resolve_fmod_event(#name);                              \
    if (f)                                                                     \
      f();                                                                     \
  }

FMOD_EVENT_FORWARD(FMOD_EventSystem_Create)
FMOD_EVENT_FORWARD(FMOD_EventSystem_Init)
FMOD_EVENT_FORWARD(FMOD_EventSystem_Release)
FMOD_EVENT_FORWARD(FMOD_EventSystem_Update)
FMOD_EVENT_FORWARD(FMOD_EventSystem_Load)
FMOD_EVENT_FORWARD(FMOD_EventSystem_Unload)
FMOD_EVENT_FORWARD(FMOD_EventSystem_GetSystemObject)

// ============================================================================
// FMOD Ex — Raw Stubs (functions not resolved via forwarding)
// ============================================================================

// FMOD_System_Update (0x94xxxx) — Processes pending FMOD operations
int __stdcall FMOD_System_Update() { return 0; }

// FMOD_Sound_GetLength (0x94xxxx) — Gets sound length in milliseconds
int __stdcall FMOD_Sound_GetLength() { return 0; }

// FMOD_Channel_IsPlaying (0x94xxxx) — Checks if a channel is currently playing
int __stdcall FMOD_Channel_IsPlaying() { return 0; }

// FMOD_Channel_GetPosition (0x94xxxx) — Gets playback position of a channel
int __stdcall FMOD_Channel_GetPosition() { return 0; }
