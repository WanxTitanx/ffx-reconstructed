// ============================================================================
// Steam API — Forwarding Stub
// Carrega steam_api.dll e faz forwarding
// ============================================================================
#include <windows.h>

static FARPROC resolve_steam(const char *name) {
  static HMODULE h = LoadLibraryA("steam_api.dll");
  return h ? GetProcAddress(h, name) : NULL;
}

#define STEAM_FORWARD(name)                                                    \
  void name() {                                                                \
    static FARPROC f = resolve_steam(#name);                                   \
    if (f)                                                                     \
      f();                                                                     \
  }

// Core Steam API
STEAM_FORWARD(SteamAPI_Init)
STEAM_FORWARD(SteamAPI_InitEx)
STEAM_FORWARD(SteamAPI_Shutdown)
STEAM_FORWARD(SteamAPI_RestartAppIfNecessary)
STEAM_FORWARD(SteamAPI_ReleaseCurrentThreadMemory)
STEAM_FORWARD(SteamAPI_WriteMiniDump)
STEAM_FORWARD(SteamAPI_SetMiniDumpComment)
STEAM_FORWARD(SteamAPI_IsSteamRunning)

// Callbacks
STEAM_FORWARD(SteamAPI_RegisterCallback)
STEAM_FORWARD(SteamAPI_UnregisterCallback)
STEAM_FORWARD(SteamAPI_MatchmakingKeyValuePairs_t)
// STEAM_FORWARD(SteamAPI_RunCallbacks) — replaced by int __stdcall stub below

// ============================================================================
// Steam API — Direct Stubs (int __stdcall returning 0)
// Addresses are approximated from 0x6Dxxxx range
// ============================================================================

// SteamAPI_InitSafe (0x6Dxxxx) — safe init variant
int __stdcall SteamAPI_InitSafe() { return 0; }

// SteamAPI_RunCallbacks (0x6Dxxxx) — runs pending callbacks
// CONFLICT: already defined as STEAM_FORWARD above; comment that out to use
// this stub
int __stdcall SteamAPI_RunCallbacks() { return 0; }

// SteamAPI_RegisterCallResult (0x6Dxxxx) — register call result handler
int __stdcall SteamAPI_RegisterCallResult() { return 0; }

// SteamAPI_UnregisterCallResult (0x6Dxxxx) — unregister call result handler
int __stdcall SteamAPI_UnregisterCallResult() { return 0; }

// SteamUser_GetSteamID (0x6Dxxxx) — get current user's SteamID
int __stdcall SteamUser_GetSteamID() { return 0; }

// SteamUserStats_GetStat (0x6Dxxxx) — get stat value
int __stdcall SteamUserStats_GetStat() { return 0; }

// SteamUserStats_SetStat (0x6Dxxxx) — set stat value
int __stdcall SteamUserStats_SetStat() { return 0; }

// SteamUserStats_StoreStats (0x6Dxxxx) — store stats to Steam
int __stdcall SteamUserStats_StoreStats() { return 0; }
