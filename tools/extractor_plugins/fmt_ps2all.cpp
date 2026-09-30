#include <windows.h>
#include "ExtrDefs.h"

BOOL __stdcall Test(void *Buf) {
    DWORD sig = *(DWORD *)Buf;
    DWORD ai = *((DWORD *)Buf + 1);
    WORD *wsig = (WORD *)Buf;

    if (sig == 0x77777777) return 1;
    if (sig == 0x00000008 && (ai == 0x30 || ai == 0x20)) return 1;
    if (sig == 0x00000001) { DWORD ver = ai; return ver >= 1 && ver <= 200; }
    if (sig == 0x00000005 || sig == 0x00000007) return 1;
    if (wsig[0] == 0x4354 && wsig[1] == 0x5846) return 1;
    return 0;
}

BOOL __stdcall Load(TLoadFormatParams *Params) {
    char buf[64];
    DWORD read = 0;
    ReadFile(Params->FileHandle, buf, 64, &read, 0);
    DWORD sig = *(DWORD *)buf;

    const char *ext = "ps2";
    const char *info = "PS2 Data";
    DWORD fsize = (DWORD)Params->SourceFileSize;

    if (sig == 0x77777777) {
        DWORD size = *(DWORD *)(buf + 12);
        fsize = size ? size : fsize;
        ext = "mgrp"; info = "FFX Motion";
    }
    else if (sig == 0x00000008) {
        DWORD *p = (DWORD *)buf;
        DWORD max = 0;
        for (int i = 1; i < 8; i++)
            if (p[i] > max && p[i] < 0x100000) max = p[i];
        fsize = max ? max : 65536;
        ext = "mon"; info = "FFX Monster";
    }
    else if (sig == 0x00000001) {
        ext = "sps2"; info = "FFX Shader";
    }
    else if (sig == 0x00000005 || sig == 0x00000007) {
        ext = "btl"; info = "FFX Battle";
    }

    Params->FileSize = fsize;
    Params->FileExt = (char*)ext;
    Params->FileInfo = (char*)info;
    return 1;
}

void __stdcall About(HWND h) { MessageBox(h, "FFX PS2 Scanner v1", "About", MB_OK); }

static TPluginInfo Plugin = {
    API_VER, FT_SPECIAL, "MGR;MON;SPS;BTL", "FFX PS2", 99,
    (void*)(void(__stdcall*)(void*))Test,
    (void*)(BOOL(__stdcall*)(TLoadFormatParams*))Load,
    (void*)(void(__stdcall*)(HWND))About,
    NULL
};

extern "C" __declspec(dllexport) TPluginInfo* __stdcall GetPluginInfo(TServiceProcs *s) {
    return &Plugin;
}

BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID l) { return 1; }
