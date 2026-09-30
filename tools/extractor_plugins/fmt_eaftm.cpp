#include <windows.h>
#include "ExtrDefs.h"

// EAF data extractor: grabs any non-empty block bigger than 256 bytes
// with recognizable structure (not random noise)

BOOL __stdcall Test(void *Buf) {
    DWORD *dw = (DWORD *)Buf;
    DWORD zeroC = 0, ffC = 0, patC = 0;

    // Check first 32 dwords for patterns
    for (int i = 0; i < 32 && i < 512/4; i++) {
        if (dw[i] == 0) zeroC++;
        if (dw[i] == 0xFFFFFFFF) ffC++;
        if (dw[i] == 0x77777777 || dw[i] == 0x77777777) patC++;
        if (dw[i] == 0x00000008 || dw[i] == 0x00000001) patC++;
        if (dw[i] == 0x00000005 || dw[i] == 0x00000007) patC++;
    }

    // Accept if less than 50% zeros and not all FFs
    return zeroC < 16 && ffC < 28;
}

BOOL __stdcall Load(TLoadFormatParams *P) {
    char buf[32];
    DWORD read;
    ReadFile(P->FileHandle, buf, 32, &read, 0);
    DWORD sig = *(DWORD *)buf;

    // Estimate size: use either known patterns or 1MB chunks
    DWORD size = 1048576; // default 1MB

    if (sig == 0x77777777) size = 262144; // MGRP ~256K average
    else if (sig == 0x00000008) size = 65536; // MONSTER ~64K
    else if (sig == 0x00000005 || sig == 0x00000007) size = 131072; // BATTLE ~128K
    else if (sig == 0x00000001) size = 524288; // SPS2 ~512K

    P->FileSize = size < (DWORD)P->SourceFileSize ? size : (DWORD)P->SourceFileSize;
    P->FileExt = "raw";
    P->FileInfo = "EXTRACT ALL FUCKING THING MOTHERFUCKER";
    return 1;
}

void __stdcall About(HWND h) { MessageBox(h, "EAFTM v1.0", "About", MB_OK); }

static TPluginInfo Plugin = { API_VER, FT_SPECIAL, "EAF", "EAFTM", 1,
    (void*)(void(__stdcall*)(void*))Test,
    (void*)(BOOL(__stdcall*)(TLoadFormatParams*))Load,
    (void*)(void(__stdcall*)(HWND))About, NULL };

extern "C" __declspec(dllexport) TPluginInfo* __stdcall GetPluginInfo(TServiceProcs *s) { return &Plugin; }
BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID l) { return 1; }
