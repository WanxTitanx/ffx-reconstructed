#include <windows.h>
#include "ExtrDefs.h"
BOOL __stdcall Test(void *Buf) {
    WORD *w = (WORD *)Buf;
    return w[0] == 0x4354 && w[1] == 0x5846;  // "FTCX"
}
BOOL __stdcall Load(TLoadFormatParams *P) {
    P->FileSize = (DWORD)P->SourceFileSize; P->FileExt = "ftc"; P->FileInfo = "FFX Font Cache"; return 1;
}
void __stdcall About(HWND h) { MessageBox(h, "FFX FTC Plugin", "About", MB_OK); }
static TPluginInfo P = { API_VER, FT_GRAPHICS, "FTC", "FFX FTC", 95,
    (void*)(void(__stdcall*)(void*))Test, (void*)(BOOL(__stdcall*)(TLoadFormatParams*))Load,
    (void*)(void(__stdcall*)(HWND))About, NULL };
extern "C" __declspec(dllexport) TPluginInfo* __stdcall GetPluginInfo(TServiceProcs *s) { return &P; }
BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID l) { return 1; }
