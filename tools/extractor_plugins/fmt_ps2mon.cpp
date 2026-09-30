#include <windows.h>
#include "..\..\ExtrasExtras\FFXINTERNATIONAL\extractor\extractor\Sdk\Api\Inc\ExtrDefs.h"

BOOL __stdcall Test(void *Buf) {
    // Monster data: starts with 0x08000000, then file pointers
    DWORD sig = *(DWORD *)Buf;
    DWORD aiPtr = *(DWORD *)((DWORD)Buf + 4);
    return sig == 0x00000008 && aiPtr == 0x30;
}

BOOL __stdcall Load(TLoadFormatParams *Params) {
    char buf[2048];
    DWORD read;
    ReadFile(Params->FileHandle, buf, 2048, &read, 0);

    // Estimate size from file pointers
    DWORD *ptrs = (DWORD *)(buf + 4);
    DWORD maxPtr = 0;
    for (int i = 0; i < 7; i++) {
        if (ptrs[i] > maxPtr && ptrs[i] < 1024*1024)
            maxPtr = ptrs[i];
    }

    Params->FileSize = maxPtr > 0 ? maxPtr : 2048;
    Params->FileExt = "mon";
    Params->FileInfo = "FFX Monster Data";
    return 1;
}

void __stdcall About(HWND Handle) {
    MessageBox(Handle, "FFX PS2 Monster File Plugin", "About", MB_OK);
}

TPluginInfo Plugin = { API_VER, FT_SPECIAL, "MON", "FFX Monster", 90, Test, Load, About, NULL };

extern "C" __declspec(dllexport) TPluginInfo* __stdcall GetPluginInfo(TServiceProcs *ServiceProcs) {
    return &Plugin;
}

BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID l) { return 1; }
