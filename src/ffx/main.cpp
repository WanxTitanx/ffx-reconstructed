// FFX Reconstructed — Entry Point
// Original: 0x9493c7 (start)
#undef UNICODE
#undef _UNICODE
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <cstdint>

#include "ffx_input.h"
#include "ffx_renderqueue.h"
#include "ffx_texture.h"
#include "ffx_menu.h"

// Input state
static FFXInputState g_input;

// Menu root (extern from ffx_menu.cpp)
extern struct FFXMenuObject *g_EscMenuRoot;

// ============================================================================
// PhyreEngine + FFX init function prototypes
// ============================================================================
int HeapArena_GlobalBootInit(int heapSize);
float *Phyre_PApplication_Constructor(float *app);
int FFX_Engine_InitApplication(int app, int a2, int a3);
int Phyre_Application_SetWindowTitle(int *app, const char *title);
int FFX_Dbg_LogPrintf(int level, const char *fmt, ...);
int FFX_Debug_RedirectStdoutToFile();
int *GetGlobalSystemContext();
int Phyre_Property_SetValue231(float *app, int value);

// ============================================================================
// Renderer forward declarations (implemented in separate .cpp)
// ============================================================================
int FFX_Renderer_Init(HWND hwnd, int w, int h);
void FFX_Renderer_Shutdown();
void FFX_Renderer_BeginFrame();
void FFX_Renderer_EndFrame();
void FFX_Renderer_Resize(int width, int height);
void FFX_Renderer_DrawTestTriangle();
void FFX_Renderer_ToggleFullscreen(HWND hwnd);

// Render queue — deferred quad batching
int  FFX_RenderQueue_Init();
void FFX_RenderQueue_Shutdown();
void FFX_RenderQueue_Flush();
void FFX_RenderQueue_Resize(int width, int height);

// FFXApplication vtable placeholder (at 0xb3fe68 no original)
static const int vtable_FFXApplication[32] = {0};

// FFX_Engine_InitApplication (0x42f8d0)
// Inicializa subsistemas FFX: storage, encoding, save, FMOD, PS3, async Q
int FFX_Engine_InitApplication(int app, int a2, int a3) {
    FFX_Dbg_LogPrintf(10, "SKS: initApplication begin\n");
    FFX_Menu2D_LoadTextures();
    FFX_Dbg_LogPrintf(10, "SKS: fiosInitialize finished\n");
    return 1;
}

// Boot: inicializa singleton FFXApplication
static int FFX_Boot_Init(float *app) {
    Phyre_PApplication_Constructor(app);
    Phyre_Property_SetValue231(app, 101);

    int *ctx = (int *)GetGlobalSystemContext();
    if (ctx) {
        ctx[155] = 1280;
        ctx[156] = 720;
        ctx[163] = 2;
    }

    FFX_Debug_RedirectStdoutToFile();
    return 1;
}

// ============================================================================
// Janela
// ============================================================================
static HWND g_window = NULL;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE: {
        if (wParam != SIZE_MINIMIZED) {
            int w = LOWORD(lParam);
            int h = HIWORD(lParam);
            FFX_Renderer_Resize(w, h);
            FFX_RenderQueue_Resize(w, h);
        }
        return 0;
    }
    case WM_KEYDOWN: {
        if (wParam == VK_F11) {
            FFX_Renderer_ToggleFullscreen(hwnd);
        }
        return 0;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

static HWND CreateMainWindow(HINSTANCE hInstance) {
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "FFX_Window";

    if (!RegisterClassEx(&wc))
        return NULL;

    HWND hwnd = CreateWindowEx(0, "FFX_Window", "FINAL FANTASY X",
                               WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                               800, 600, NULL, NULL, hInstance, NULL);
    if (hwnd) {
        ShowWindow(hwnd, SW_SHOWDEFAULT);
        UpdateWindow(hwnd);
    }
    return hwnd;
}

// ============================================================================
// Game loop globals
// ============================================================================
static bool g_running = true;
static LARGE_INTEGER g_freq = {0};
static LARGE_INTEGER g_lastTime = {0};

// ============================================================================
// Entry point
// ============================================================================

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    // 1. Inicializa heap do jogo (64MB)
    if (!HeapArena_GlobalBootInit(64 * 1024 * 1024))
        return 0;

    // 2. Cria janela
    g_window = CreateMainWindow(hInstance);
    if (!g_window)
        return 0;

    // 3. Inicializa FFX singleton (~1KB no stack)
    float appBuffer[256];
    memset(appBuffer, 0, sizeof(appBuffer));
    FFX_Boot_Init(appBuffer);

    // 4. Inicializa subsistemas FFX
    FFX_Engine_InitApplication((int)(intptr_t)appBuffer, 0, 0);

    // 5. Inicializa renderer
    if (!FFX_Renderer_Init(g_window, 1280, 720)) {
        MessageBoxA(g_window, "Failed to initialize D3D11 renderer.", "FFX Reconstructed", MB_ICONERROR);
        return 1;
    }

    // 5b. Inicializa render queue (deferred quad batching — usa device/context do renderer)
    if (!FFX_RenderQueue_Init()) {
        MessageBoxA(g_window, "Failed to initialize render queue.", "FFX Reconstructed", MB_ICONERROR);
        return 1;
    }

    // 5c. Inicializa input state
    FFX_Input_Init(&g_input);

    // 6. Inicializa timer do game loop
    QueryPerformanceFrequency(&g_freq);
    QueryPerformanceCounter(&g_lastTime);

    // 7. Game loop com frame timing
    MSG msg = {0};
    while (g_running) {
        // Processa todas as mensagens Windows pendentes
        msg = MSG();
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) { g_running = false; break; }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        if (!g_running) break;

        // Calcula deltaTime em segundos
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        float dt = (float)(now.QuadPart - g_lastTime.QuadPart) / (float)g_freq.QuadPart;
        g_lastTime = now;
        if (dt > 0.05f) dt = 0.05f;  // clamp para evitar spiral of death

        // Poll input
        FFX_Input_Poll(&g_input);
        if (FFX_Input_WasKeyPressed(&g_input, VK_ESCAPE)) {
            if (g_EscMenuRoot && g_EscMenuRoot->activeFlag) {
                g_EscMenuRoot->activeFlag = 0;
            } else {
                g_running = false;
            }
        }

        // Toggle menu with M key
        if (g_input.keysPressed['M']) {
            if (!g_EscMenuRoot) {
                FFX_EscMenu_Init();
            }
            g_EscMenuRoot->activeFlag = !g_EscMenuRoot->activeFlag;
            g_EscMenuRoot->selectedRow = 0;
        }

        // Game update placeholder
        // FFX_Engine_Update(dt);

        // Process menu input if active
        if (g_EscMenuRoot && g_EscMenuRoot->activeFlag) {
            FFX_EscMenu_ProcessInput();
        }

        // ---- FPS counter ----
        static int    fpsFrameCount = 0;
        static float  fpsTimeAccum  = 0;
        static char   fpsText[32]   = "FPS: 0";
        fpsFrameCount++;
        fpsTimeAccum += dt;
        if (fpsTimeAccum >= 1.0f) {
            sprintf(fpsText, "FPS: %d", fpsFrameCount);
            fpsFrameCount = 0;
            fpsTimeAccum -= 1.0f;
        }

        // Render frame
        FFX_Renderer_BeginFrame();

        // Draw menu if active (full game area)
        if (g_EscMenuRoot && g_EscMenuRoot->activeFlag) {
            // Dark background overlay
            FFX_RenderQueue_PushRect(0, 0, 512, 416, 0xCC000010, 0xCC05000A);

            // Title bar
            FFX_RenderQueue_PushRect(0, 0, 512, 32, 0xFF1A2A3A, 0xFF0A1A2A);

            // Menu items
            float y = 50.0f;
            for (int i = 0; i < g_EscMenuRoot->totalRows && i < 15; i++) {
                uint32_t bgColor = (i == g_EscMenuRoot->selectedRow) ? 0x332A9D8F : 0x22000000;
                FFX_RenderQueue_PushRect(20, y, 472, 28, bgColor, bgColor);
                if (i == g_EscMenuRoot->selectedRow)
                    FFX_RenderQueue_PushRect(18, y, 4, 28, 0xFF2A9D8F, 0xFF2A9D8F);
                y += 32.0f;
            }
        } else {
            // Test background rect (only when menu is closed)
            FFX_RenderQueue_PushRect(10, 10, 1260, 700, 0x1A2A3AFF, 0x0A0F14FF);
            FFX_Renderer_DrawTestTriangle();
        }

        // Draw FPS bar (top-left corner, width proportional to frame time)
        float fpsPct = (dt > 0) ? (1.0f / 60.0f) / dt : 1.0f;
        if (fpsPct > 1.0f) fpsPct = 1.0f;
        uint32_t fpsColor = (fpsPct > 0.8f)  ? 0x00FF00FF
                          : (fpsPct > 0.5f)  ? 0xFFFF00FF
                          :                     0xFF0000FF;
        FFX_RenderQueue_PushRect(10, 10, 100 * fpsPct, 8, fpsColor, 0xFFFFFFFF);

        FFX_RenderQueue_Flush();
        FFX_Renderer_EndFrame();
    }

    // 8. Shutdown
    FFX_RenderQueue_Shutdown();
    FFX_Renderer_Shutdown();

    return (int)msg.wParam;
}

// CRT entry point — use standard main with console subsystem for debugging
#ifndef _MSC_VER
// For clang/gcc: use main instead of WinMain
int main() {
    return WinMain(GetModuleHandleA(NULL), NULL, GetCommandLineA(), SW_SHOWDEFAULT);
}
#else
void WinMainCRTStartup() {
    WinMain(GetModuleHandleA(NULL), NULL, GetCommandLineA(), SW_SHOWDEFAULT);
}
#endif
