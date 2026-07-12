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
#include "ffx_phyre_texture.h"
#include "ffx_ttf_font.h"
#include "ffx_fmv_player.h"
#include "ffx_menu2d.h"
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
        1280, 720, NULL, NULL, hInstance, NULL);
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

    // 5d. Inicializa texture manager e carrega assets
    FFX_Texture_Init();
    const char *gameData = "data";
    char texPath[512];
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\ffx_bg.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "ffx_bg");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\copyright_nagi.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "copyright");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\meswin.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "meswin");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\menu_new.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "menu_new");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\icon.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "icon");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\pause.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "pause");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\face_ply.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "face_ply");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\d3d11\\face_smn.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "face_smn");
    for (int i = 0; i < 70; i++) {
        char name[32];
        snprintf(name, sizeof(name), "water_%02d", i);
        snprintf(texPath, sizeof(texPath), "%s\\menu\\titl\\d3d11\\water_%02d.dds.phyre", gameData, i);
        FFX_Texture_LoadPhyre(texPath, name);
    }
    snprintf(texPath, sizeof(texPath), "%s\\menu\\xfont1208\\d3d11\\font_0_0.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "font_0_0");
    snprintf(texPath, sizeof(texPath), "%s\\menu\\loading\\d3d11\\loadingbg.dds.phyre", gameData);
    FFX_Texture_LoadPhyre(texPath, "loadingbg");

    FFX_TTFFont_Init("C:\\Windows\\Fonts\\arial.ttf", 24);

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

        // 0=black, 1=square_logo, 2=second_logo, 3=intro_fmv, 4=title, 5=loading, 6=menu
        static int screenState = 4;
        static float stateTimer = 0.0f;
        static int sel = 0;
        static float blinkTimer = 0.0f;
        static float waterAnimTimer = 0.0f;
        static int waterFrame = 0;
        static float fadeAlpha = 0.0f;

        /* FFX internal render resolution: 512x416 (scaled from 1920x1080).
           The real FFX.exe renders all menu elements at 512x416 and scales up.
           ScaleX: 1920 → 512 (divide by 3.75), ScaleY: 1080 → 416 (divide by 2.596).
           Color system: 128 = normal brightness, 0 = black, 255 = double brightness. */
        blinkTimer += dt;
        waterAnimTimer += dt;
        if (waterAnimTimer >= 1.0f / 30.0f) {
            waterAnimTimer = 0.0f;
            waterFrame = (waterFrame + 1) % 70;
        }

        stateTimer += dt;

        if (screenState == 1 || screenState == 2) {
            FFX_FMV_NextFrame();
        }

        const float bootDurations[] = {1.0f, 8.0f, 6.0f, 0.5f, 0.0f, 0.0f, 0.0f};
        if (screenState < 4 && stateTimer >= bootDurations[screenState]) {
            screenState++;
            stateTimer = 0.0f;
            fadeAlpha = 1.0f;
            if (screenState == 1) {
                char fmvPath[512];
                snprintf(fmvPath, sizeof(fmvPath), "%s\\movie\\opl_us.webm", gameData);
                FFX_FMV_Load(fmvPath);
            } else if (screenState == 2) {
                char fmvPath[512];
                snprintf(fmvPath, sizeof(fmvPath), "%s\\movie\\opk_us.webm", gameData);
                FFX_FMV_Load(fmvPath);
            } else if (screenState == 3) {
                FFX_FMV_Shutdown();
            }
        }
        if (fadeAlpha > 0.0f) {
            fadeAlpha -= dt * 2.0f;
            if (fadeAlpha < 0.0f) fadeAlpha = 0.0f;
        }

        if (screenState == 4) {
            if (g_input.keysPressed[VK_UP] && sel > 0) sel--;
            if (g_input.keysPressed[VK_DOWN] && sel < 3) sel++;
            if (g_input.keysPressed[VK_RETURN] || g_input.keysPressed[VK_SPACE]) {
                screenState = 5;
                stateTimer = 0.0f;
            }
        } else if (screenState == 5) {
            if (stateTimer >= 2.0f) {
                screenState = 6;
                stateTimer = 0.0f;
                sel = 0;
            }
        } else if (screenState == 6) {
            if (g_input.keysPressed[VK_UP] && sel > 0) sel--;
            if (g_input.keysPressed[VK_DOWN] && sel < 4) sel++;
            if (g_input.keysPressed[VK_ESCAPE]) {
                screenState = 4;
                sel = 0;
            }
        }

        FFX_Renderer_BeginFrame();

        if (screenState == 0) {
            FFX_RenderQueue_PushRect(0, 0, 1280, 720, 0xFF000000, 0xFF000000);
        } else if (screenState == 1) {
            void *fmvSRV = FFX_FMV_GetFrameSRV();
            if (fmvSRV) {
                FFX_RenderQueue_PushQuadTex(0, 0, 1280, 720, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, fmvSRV);
            } else {
                FFX_RenderQueue_PushRect(0, 0, 1280, 720, 0xFF000000, 0xFF000000);
            }
        } else if (screenState == 2) {
            void *fmvSRV = FFX_FMV_GetFrameSRV();
            if (fmvSRV) {
                FFX_RenderQueue_PushQuadTex(0, 0, 1280, 720, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, fmvSRV);
            } else {
                FFX_RenderQueue_PushRect(0, 0, 1280, 720, 0xFF000000, 0xFF000000);
            }
        } else if (screenState == 3) {
            FFX_RenderQueue_PushRect(0, 0, 1280, 720, 0xFF000000, 0xFF000000);
            float introPct = stateTimer / 0.5f;
            if (introPct > 1.0f) introPct = 1.0f;
            FFX_RenderQueue_PushRect(0, 350, 1280 * introPct, 2, 0xFF2A9D8F, 0xFF2A9D8F);
        } else if (screenState == 4) {
            void *bgSRV = FFX_Texture_GetSRV("ffx_bg");
            if (bgSRV) {
                FFX_RenderQueue_PushQuadTex(0, 0, 1280, 720, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, bgSRV);
            }

            char waterName[32];
            snprintf(waterName, sizeof(waterName), "water_%02d", waterFrame);
            void *waterSRV = FFX_Texture_GetSRV(waterName);
            if (waterSRV) {
                FFX_RenderQueue_PushQuadTex(0, 0, 1280, 720, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, waterSRV);
            }

            void *copySRV = FFX_Texture_GetSRV("copyright");
            if (copySRV) {
                FFX_RenderQueue_PushQuadTex(340, 600, 600, 80, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, copySRV);
            }

            void *fontSRV = FFX_TTFFont_GetAtlasSRV();
            if (fontSRV) {
                FFX_TTFFont_DrawText("FINAL FANTASY X", 380, 150, 2.0f, 0xFFCCCCCC, fontSRV);
            }
            const char *titleItems[] = {"NEW GAME", "LOAD GAME", "OPTIONS", "CREDITS"};
            float btnY = 350;
            for (int i = 0; i < 4; i++) {
                uint32_t bg = (i == sel) ? 0x802A9D8F : 0x40000000;
                FFX_RenderQueue_PushRect(440, btnY, 400, 40, bg, bg);
                if (i == sel) {
                    FFX_RenderQueue_PushRect(436, btnY, 4, 40, 0xFF2A9D8F, 0xFF2A9D8F);
                    FFX_RenderQueue_PushRect(836, btnY, 4, 40, 0xFF2A9D8F, 0xFF2A9D8F);
                }
                btnY += 50;
            }
            btnY = 350;
            for (int i = 0; i < 4; i++) {
                if (fontSRV) {
                    uint32_t tc = (i == sel) ? 0xFFFFFF00 : 0xFFFFFFFF;
                    FFX_TTFFont_DrawText(titleItems[i], 460, btnY + 6, 1.5f, tc, fontSRV);
                }
                btnY += 50;
            }
        } else if (screenState == 5) {
            void *loadSRV = FFX_Texture_GetSRV("loadingbg");
            if (loadSRV) {
                FFX_RenderQueue_PushQuadTex(0, 0, 1280, 720, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, loadSRV);
            } else {
                FFX_RenderQueue_PushRect(0, 0, 1280, 720, 0xFF000000, 0xFF000000);
            }
            float pct = stateTimer / 2.0f;
            if (pct > 1.0f) pct = 1.0f;
            FFX_RenderQueue_PushRect(440, 360, 400, 16, 0x30000000, 0x30000000);
            FFX_RenderQueue_PushRect(440, 360, (int)(400 * pct), 16, 0xFF2A9D8F, 0xFF2A9D8F);
        } else if (screenState == 6) {
            void *bgSRV = FFX_Texture_GetSRV("ffx_bg");
            if (bgSRV) {
                FFX_RenderQueue_PushQuadTex(0, 0, 1280, 720, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, bgSRV);
            } else {
                FFX_RenderQueue_PushRect(0, 0, 1280, 720, 0xFF0A0A1A, 0xFF05050F);
            }

            void *meswinSRV = FFX_Texture_GetSRV("meswin");
            if (meswinSRV) {
                FFX_RenderQueue_PushQuadTex(200, 100, 880, 520, 0, 0, 1, 1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, meswinSRV);
            } else {
                FFX_RenderQueue_PushRect(200, 100, 880, 520, 0xCC0A0A1A, 0xCC05050F);
            }

            const char *menuItems[] = {"ITEMS", "ABILITIES", "EQUIPMENT", "STATUS", "FORMATION"};
            float btnY = 150;
            void *fontSRV2 = FFX_Texture_GetSRV("font_0_0");
            for (int i = 0; i < 5; i++) {
                uint32_t bg = (i == sel) ? 0x802A9D8F : 0x40000000;
                FFX_RenderQueue_PushRect(240, btnY, 800, 40, bg, bg);
                if (i == sel) {
                    FFX_RenderQueue_PushRect(236, btnY, 4, 40, 0xFF2A9D8F, 0xFF2A9D8F);
                    FFX_RenderQueue_PushRect(1036, btnY, 4, 40, 0xFF2A9D8F, 0xFF2A9D8F);
                }
                if (fontSRV2) {
                    uint32_t tc = (i == sel) ? 0xFFFFD700 : 0xFFFFFFFF;
                    FFX_RenderQueue_DrawText(menuItems[i], 260, btnY + 8, 2.0f, tc, fontSRV2, 16, 16, 8, 16);
                }
                btnY += 50;
            }

            if (blinkTimer < 0.6f) {
                FFX_RenderQueue_PushRect(240, 150 + sel * 50, 800, 2, 0xFF2A9D8F, 0xFF2A9D8F);
            } else if (blinkTimer > 1.2f) {
                blinkTimer = 0.0f;
            }
        }

        if (fadeAlpha > 0.0f) {
            uint8_t a = (uint8_t)(fadeAlpha * 255.0f);
            uint32_t fade = (a << 24) | 0x00000000;
            FFX_RenderQueue_PushRect(0, 0, 1280, 720, fade, fade);
        }

        float fpsPct = (dt > 0) ? (1.0f / 60.0f) / dt : 1.0f;
        if (fpsPct > 1.0f) fpsPct = 1.0f;
        uint32_t fpsColor = (fpsPct > 0.8f)  ? 0x00FF00FF
                          : (fpsPct > 0.5f)  ? 0xFFFF00FF
                          :                     0xFF0000FF;
        FFX_RenderQueue_PushRect(10, 10, 200 * fpsPct, 12, fpsColor, fpsColor);

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
