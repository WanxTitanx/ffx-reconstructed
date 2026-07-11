// ============================================================================
// FFX.EXE — Iggy Player (Scaleform) API Stubs
// Module: iggy_w32
// ============================================================================
#include <windows.h>
#include <stdlib.h>

// Iggy player uses __stdcall with decorated names (@n = total param bytes).
// These are the FFX import names; we alias them via EXPORTS or link-time
// resolution. The prototypes below use undecorated WINAPI calling convention.

// Stub for iggy_w32::_IggyPlayerCreateFromMemory@12
int WINAPI stub_IggyPlayerCreateFromMemory(void *buffer, int size,
                                           void **pplayer) {
  if (pplayer)
    *pplayer = NULL;
  return -1; // Stub: fail (no Iggy runtime)
}

// Stub for iggy_w32::_IggyPlayerProperties@4
int WINAPI stub_IggyPlayerProperties(void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerInitializeAndTickRS@4
int WINAPI stub_IggyPlayerInitializeAndTickRS(void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerReadyToTick@4
int WINAPI stub_IggyPlayerReadyToTick(void *player) {
  return 0; // Stub: return 0 (not ready)
}

// Stub for iggy_w32::_IggyPlayerTickRS@4
int WINAPI stub_IggyPlayerTickRS(void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerPlay@4
int WINAPI stub_IggyPlayerPlay(void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerGotoFrameRS@12
int WINAPI stub_IggyPlayerGotoFrameRS(void *player, int frameNum, int unk) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerGetBackgroundColor@8
int WINAPI stub_IggyPlayerGetBackgroundColor(void *player, int *color) {
  if (color)
    *color = 0;
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerSetDisplaySize@12
int WINAPI stub_IggyPlayerSetDisplaySize(void *player, int w, int h) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerDraw@4
int WINAPI stub_IggyPlayerDraw(void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyInit@4
int WINAPI stub_IggyInit(void *params) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyShutdown@0
int WINAPI stub_IggyShutdown() {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggySetWarningCallback@8
int WINAPI stub_IggySetWarningCallback(void *callback, void *userData) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggySetTraceCallbackUTF8@8
int WINAPI stub_IggySetTraceCallbackUTF8(void *callback, void *userData) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerDestroy@4
int WINAPI stub_IggyPlayerDestroy(void *player) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyPlayerCallbackResultPath@4
int WINAPI stub_IggyPlayerCallbackResultPath(void *path) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValueSetStringUTF8RS@20
int WINAPI stub_IggyValueSetStringUTF8RS(void *value, const char *str, int len,
                                         void *player, int unk) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValueRefFree@8
int WINAPI stub_IggyValueRefFree(void *ref, void *player) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyValueRefCreateArray@8
int WINAPI stub_IggyValueRefCreateArray(void *ref, void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValueRefFromTempRef@12
int WINAPI stub_IggyValueRefFromTempRef(void *dest, void *src, void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValuePathFromRef@12
int WINAPI stub_IggyValuePathFromRef(void *path, void *ref, void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValuePathMakeArrayRef@12
int WINAPI stub_IggyValuePathMakeArrayRef(void *path, void *ref, void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValuePathSetArrayIndex@8
int WINAPI stub_IggyValuePathSetArrayIndex(void *path, int index) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValueGetS32RS@16
int WINAPI stub_IggyValueGetS32RS(void *value, int *out, void *player,
                                  int unk) {
  if (out)
    *out = 0;
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggySetAS3ExternalFunctionCallbackUTF8@8
int WINAPI stub_IggySetAS3ExternalFunctionCallbackUTF8(void *callback,
                                                       void *userData) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyMakeEventNone@4
int WINAPI stub_IggyMakeEventNone(void *eventOut) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyMakeEventMouseMove@12
int WINAPI stub_IggyMakeEventMouseMove(void *eventOut, int x, int y) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyMakeEventMouseButton@8
int WINAPI stub_IggyMakeEventMouseButton(void *eventOut, int button) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyMakeEventMouseWheel@8
int WINAPI stub_IggyMakeEventMouseWheel(void *eventOut, int delta) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyPlayerCreateFastNameUTF8@12
int WINAPI stub_IggyPlayerCreateFastNameUTF8(const char *name, int unk1,
                                             int unk2) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerCallFunctionRS@20
int WINAPI stub_IggyPlayerCallFunctionRS(void *player, void *path, void *args,
                                         void *ret, int unk) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyValueGetStringUTF8RS@24
int WINAPI stub_IggyValueGetStringUTF8RS(void *value, char *buf, int bufSize,
                                         void *player, int *outLen, int unk) {
  if (buf && bufSize > 0)
    buf[0] = '\0';
  if (outLen)
    *outLen = 0;
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerDispatchEventRS@12
int WINAPI stub_IggyPlayerDispatchEventRS(void *player, void *event, int unk) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyAudioUseDirectSound@0
int WINAPI stub_IggyAudioUseDirectSound() {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyAudioInstallMP3Decoder@0
int WINAPI stub_IggyAudioInstallMP3Decoder() {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggySetGDraw@4
int WINAPI stub_IggySetGDraw(void *gdraw) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyGDrawMallocAnnotated@12
void *WINAPI stub_IggyGDrawMallocAnnotated(int size, const char *annotation,
                                           int flags) {
  return malloc(size); // Stub: allocate via malloc
}

// Stub for iggy_w32::_IggyGDrawFree@4
int WINAPI stub_IggyGDrawFree(void *ptr) {
  free(ptr); // Stub: free via free()
  return 0;
}

// Stub for iggy_w32::IggyGDrawSendWarning
void WINAPI stub_IggyGDrawSendWarning(const char *message) {
  // Stub: discard warning
  OutputDebugStringA("IggyGDrawSendWarning: ");
  OutputDebugStringA(message ? message : "");
  OutputDebugStringA("\n");
}

// Stub for iggy_w32::_IggyDiscardVertexBufferCallback@8
int WINAPI stub_IggyDiscardVertexBufferCallback(void *callback,
                                                void *userData) {
  return 0; // Stub: no-op
}

// Stub for iggy_w32::_IggyPlayerCreateFromFileAndPlay@8
int WINAPI stub_IggyPlayerCreateFromFileAndPlay(const char *filename,
                                                void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerLoad@8
// Loads a media file/URL into the Iggy player
int WINAPI stub_IggyPlayerLoad(void *player, const char *url) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerUnload@4
// Unloads the current media from the Iggy player
int WINAPI stub_IggyPlayerUnload(void *player) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerGetStatus@4
// Returns the playback status (e.g. 0=stopped, 1=playing, 2=paused, 3=loading)
int WINAPI stub_IggyPlayerGetStatus(void *player) {
  return 0; // Stub: return 0 (stopped)
}

// Stub for iggy_w32::_IggyPlayerSetVolume@8
// Sets the playback volume (0.0f – 1.0f)
int WINAPI stub_IggyPlayerSetVolume(void *player, float volume) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerGetDuration@8
// Gets the total duration of the loaded media in milliseconds
int WINAPI stub_IggyPlayerGetDuration(void *player, int *durationMs) {
  if (durationMs)
    *durationMs = 0;
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerGetPosition@8
// Gets the current playback position in milliseconds
int WINAPI stub_IggyPlayerGetPosition(void *player, int *positionMs) {
  if (positionMs)
    *positionMs = 0;
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerSetPosition@8
// Seeks to the specified position in milliseconds
int WINAPI stub_IggyPlayerSetPosition(void *player, int positionMs) {
  return -1; // Stub: fail
}

// Stub for iggy_w32::_IggyPlayerPause@4
// Pauses playback
int WINAPI stub_IggyPlayerPause(void *player) {
  return -1; // Stub: fail
}
