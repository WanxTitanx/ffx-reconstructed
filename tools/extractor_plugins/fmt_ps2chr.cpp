#include <windows.h>
#include "ExtrDefs.h"

BOOL __stdcall Test(void *Buf) {
    DWORD v = *(DWORD *)((DWORD *)Buf + 1);
    return *(DWORD *)Buf == 0x00000000 && v == 0x0b000000;  // bone count=11
}

BOOL __stdcall Load(TLoadFormatParams *Params) {
    Params->FileSize = (DWORD)Params->SourceFileSize;
    Params->FileExt = "chr";
    Params->FileInfo = "FFX Character Model";
    return 1;
}

void __stdcall About(HWND h) { MessageBox(h, "FFX CHR Plugin", "About", MB_OK); }

static TPluginInfo Plugin = { API_VER, FT_SPECIAL, "CHR", "FFX CHR", 90,
    (void*)(void(__stdcall*)(void*))Test,
    (void*)(BOOL(__stdcall*)(TLoadFormatParams*))Load,
    (void*)(void(__stdcall*)(HWND))About, NULL };

extern "C" __declspec(dllexport) TPluginInfo* __stdcall GetPluginInfo(TServiceProcs *s) { return &Plugin; }
BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID l) { return 1; }
