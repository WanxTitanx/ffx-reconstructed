#pragma once
#include <windows.h>

struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGISwapChain;
struct ID3D11RenderTargetView;
struct ID3D11VertexShader;
struct ID3D11PixelShader;
struct ID3D11InputLayout;
struct ID3D11Buffer;

int  FFX_Renderer_Init(HWND hwnd, int width, int height);
void FFX_Renderer_Shutdown();
void FFX_Renderer_BeginFrame();
void FFX_Renderer_EndFrame();
void FFX_Renderer_Resize(int width, int height);
void FFX_Renderer_DrawTestTriangle();
void FFX_Renderer_ToggleFullscreen(HWND hwnd);

/* Exposed for subsystems that need the D3D11 device/context
 * (e.g. the render queue). */
struct ID3D11Device        *FFX_Renderer_GetDevice();
struct ID3D11DeviceContext *FFX_Renderer_GetContext();
int                         FFX_Renderer_GetWidth();
int                         FFX_Renderer_GetHeight();
