#include "ffx_renderer.h"

/* ---------------------------------------------------------------------------
 * D3D11 via LoadLibrary / GetProcAddress -- no static link to d3d11.lib
 * ---------------------------------------------------------------------------
 * We include the SDK headers for type/interface definitions only.
 * All entry points are resolved at runtime so the binary has no import
 * table dependency on d3d11.dll or d3dcompiler_47.dll.
 * -------------------------------------------------------------------------*/

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include <d3d11.h>      /* ID3D11Device, ID3D11DeviceContext, D3D11_INPUT_ELEMENT_DESC, etc. */
#include <dxgi.h>        /* DXGI_SWAP_CHAIN_DESC, IDXGISwapChain, DXGI_FORMAT_* */

#include <stdlib.h>      /* malloc, free */
#include <string.h>      /* strlen, strcpy_s */

/* ---- function-pointer typedefs ----------------------------------------- */

typedef HRESULT(WINAPI *D3D11CreateDeviceAndSwapChain_t)(
    IDXGIAdapter          *pAdapter,
    D3D_DRIVER_TYPE        DriverType,
    HMODULE                Software,
    UINT                   Flags,
    const D3D_FEATURE_LEVEL *pFeatureLevels,
    UINT                   FeatureLevels,
    UINT                   SDKVersion,
    const DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
    IDXGISwapChain        **ppSwapChain,
    ID3D11Device          **ppDevice,
    D3D_FEATURE_LEVEL      *pFeatureLevel,
    ID3D11DeviceContext    **ppImmediateContext);

typedef HRESULT(WINAPI *D3DCompile_t)(
    const void            *pSrcData,
    SIZE_T                 SrcDataSize,
    const char            *pFileName,
    const D3D_SHADER_MACRO *pDefines,
    ID3DInclude           *pInclude,
    const char            *pEntrypoint,
    const char            *pTarget,
    UINT                   Flags1,
    UINT                   Flags2,
    ID3DBlob             **ppCode,
    ID3DBlob             **ppErrorMsgs);

/* ---- module / function-pointer globals --------------------------------- */

static HMODULE                       g_d3d11Module          = NULL;
static HMODULE                       g_d3dCompilerModule    = NULL;
static D3D11CreateDeviceAndSwapChain_t g_D3D11CreateDeviceAndSwapChain = NULL;
static D3DCompile_t                   g_D3DCompile          = NULL;

/* ---- D3D11 object globals ---------------------------------------------- */

static ID3D11Device         *g_device            = NULL;
static ID3D11DeviceContext   *g_context          = NULL;
static IDXGISwapChain       *g_swapChain         = NULL;
static ID3D11RenderTargetView *g_renderTargetView = NULL;

static ID3D11VertexShader   *g_vertexShader      = NULL;
static ID3D11PixelShader    *g_pixelShader       = NULL;
static ID3D11InputLayout    *g_inputLayout       = NULL;
static ID3D11Buffer         *g_triangleVB        = NULL;

static int g_backbufferWidth  = 1280;
static int g_backbufferHeight = 720;
static int g_fullscreen       = 0;

/* ---------------------------------------------------------------------------
 * Inline HLSL shaders
 * -------------------------------------------------------------------------*/

static const char g_vsHLSL[] =
    "struct VSInput {\n"
    "    float3 pos   : POSITION;\n"
    "    float4 color : COLOR;\n"
    "};\n"
    "struct VSOutput {\n"
    "    float4 pos   : SV_Position;\n"
    "    float4 color : COLOR;\n"
    "};\n"
    "VSOutput main(VSInput input) {\n"
    "    VSOutput output;\n"
    "    output.pos   = float4(input.pos, 1.0);\n"
    "    output.color = input.color;\n"
    "    return output;\n"
    "}\n";

static const char g_psHLSL[] =
    "struct PSInput {\n"
    "    float4 pos   : SV_Position;\n"
    "    float4 color : COLOR;\n"
    "};\n"
    "float4 main(PSInput input) : SV_Target {\n"
    "    return input.color;\n"
    "}\n";

/* ---- vertex data for the test triangle --------------------------------- */

typedef struct {
    float pos[3];
    float color[4];
} TestVertex;

static const TestVertex g_triangleVerts[3] = {
    {  0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },  /* top     – red    */
    {  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f },  /* bottom  – green  */
    { -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },  /* left    – blue   */
};

/* ---- internal helpers -------------------------------------------------- */

static int LoadD3D11(void)
{
    g_d3d11Module = LoadLibraryA("d3d11.dll");
    if (!g_d3d11Module)
        return 0;

    g_D3D11CreateDeviceAndSwapChain = (D3D11CreateDeviceAndSwapChain_t)
        GetProcAddress(g_d3d11Module, "D3D11CreateDeviceAndSwapChain");
    if (!g_D3D11CreateDeviceAndSwapChain)
        return 0;

    return 1;
}

static int LoadD3DCompiler(void)
{
    g_d3dCompilerModule = LoadLibraryA("d3dcompiler_47.dll");
    if (!g_d3dCompilerModule)
        return 0;

    g_D3DCompile = (D3DCompile_t)
        GetProcAddress(g_d3dCompilerModule, "D3DCompile");
    if (!g_D3DCompile)
        return 0;

    return 1;
}

/* Compile a vertex shader from HLSL source.  Returns 1 on success. */
static int CompileVertexShader(const char *src, SIZE_T srcLen,
                               ID3DBlob **ppCode, ID3DBlob **ppErrors)
{
    HRESULT hr = g_D3DCompile(src, srcLen, "ffx_vs.hlsl",
                              NULL, NULL, "main", "vs_4_0",
                              0, 0, ppCode, ppErrors);
    return SUCCEEDED(hr) ? 1 : 0;
}

/* Compile a pixel shader from HLSL source.  Returns 1 on success. */
static int CompilePixelShader(const char *src, SIZE_T srcLen,
                              ID3DBlob **ppCode, ID3DBlob **ppErrors)
{
    HRESULT hr = g_D3DCompile(src, srcLen, "ffx_ps.hlsl",
                              NULL, NULL, "main", "ps_4_0",
                              0, 0, ppCode, ppErrors);
    return SUCCEEDED(hr) ? 1 : 0;
}

static int CreateShaders(void)
{
    ID3DBlob *vsCode   = NULL;
    ID3DBlob *psCode   = NULL;
    ID3DBlob *vsErrors = NULL;
    ID3DBlob *psErrors = NULL;
    int       result   = 0;

    /* ---- compile vertex shader ---- */
    if (!CompileVertexShader(g_vsHLSL, strlen(g_vsHLSL), &vsCode, &vsErrors))
        goto cleanup;

    /* ---- compile pixel shader ---- */
    if (!CompilePixelShader(g_psHLSL, strlen(g_psHLSL), &psCode, &psErrors))
        goto cleanup;

    /* ---- create VS ---- */
    if (FAILED(g_device->CreateVertexShader(
            vsCode->GetBufferPointer(),
            vsCode->GetBufferSize(),
            NULL, &g_vertexShader)))
        goto cleanup;

    /* ---- create PS ---- */
    if (FAILED(g_device->CreatePixelShader(
            psCode->GetBufferPointer(),
            psCode->GetBufferSize(),
            NULL, &g_pixelShader)))
        goto cleanup;

    /* ---- input layout ---- */
    D3D11_INPUT_ELEMENT_DESC layoutDesc[2] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
          D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT,
          D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    if (FAILED(g_device->CreateInputLayout(
            layoutDesc, 2,
            vsCode->GetBufferPointer(),
            vsCode->GetBufferSize(),
            &g_inputLayout)))
        goto cleanup;

    result = 1;

cleanup:
    if (vsCode)   vsCode->Release();
    if (psCode)   psCode->Release();
    if (vsErrors) vsErrors->Release();
    if (psErrors) psErrors->Release();
    return result;
}

static int CreateTriangle(void)
{
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.ByteWidth      = sizeof(g_triangleVerts);
    bd.Usage          = D3D11_USAGE_DEFAULT;
    bd.BindFlags      = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA srd;
    ZeroMemory(&srd, sizeof(srd));
    srd.pSysMem = g_triangleVerts;

    HRESULT hr = g_device->CreateBuffer(&bd, &srd, &g_triangleVB);
    return SUCCEEDED(hr) ? 1 : 0;
}

/* ---- public API -------------------------------------------------------- */

int FFX_Renderer_Init(HWND hwnd, int width, int height)
{
    if (!LoadD3D11())
        return 0;

    if (!LoadD3DCompiler())
        return 0;

    /* ---- describe swap chain ---- */
    DXGI_SWAP_CHAIN_DESC scd;
    ZeroMemory(&scd, sizeof(scd));
    scd.BufferCount                        = 2;
    scd.BufferDesc.Width                   = (UINT)width;
    scd.BufferDesc.Height                  = (UINT)height;
    scd.BufferDesc.Format                  = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator   = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferUsage                        = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow                       = hwnd;
    scd.SampleDesc.Count                   = 1;
    scd.SampleDesc.Quality                 = 0;
    scd.Windowed                           = TRUE;
    scd.SwapEffect                         = DXGI_SWAP_EFFECT_DISCARD;

    D3D_FEATURE_LEVEL level  = D3D_FEATURE_LEVEL_11_0;
    D3D_FEATURE_LEVEL outLev;

    HRESULT hr = g_D3D11CreateDeviceAndSwapChain(
        NULL,                              /* adapter            */
        D3D_DRIVER_TYPE_HARDWARE,          /* driver type        */
        NULL,                              /* software module    */
        D3D11_CREATE_DEVICE_DEBUG |
        D3D11_CREATE_DEVICE_BGRA_SUPPORT,  /* flags              */
        &level, 1,                         /* feature levels     */
        D3D11_SDK_VERSION,                 /* SDK version        */
        &scd,                              /* swap chain desc    */
        &g_swapChain,                      /* out: swap chain    */
        &g_device,                         /* out: device        */
        &outLev,                           /* out: feature level */
        &g_context);                       /* out: context       */

    if (FAILED(hr))
        return 0;

    /* ---- create render-target view ---- */
    ID3D11Texture2D *backBuffer = NULL;
    hr = g_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
                                (void**)&backBuffer);
    if (FAILED(hr))
        return 0;

    hr = g_device->CreateRenderTargetView(backBuffer, NULL,
                                          &g_renderTargetView);
    backBuffer->Release();
    if (FAILED(hr))
        return 0;

    g_backbufferWidth  = width;
    g_backbufferHeight = height;

    /* ---- compile shaders ---- */
    if (!CreateShaders())
        return 0;

    /* ---- create triangle ---- */
    if (!CreateTriangle())
        return 0;

    return 1;
}

void FFX_Renderer_Shutdown(void)
{
    if (g_triangleVB)      { g_triangleVB->Release();      g_triangleVB      = NULL; }
    if (g_inputLayout)     { g_inputLayout->Release();     g_inputLayout     = NULL; }
    if (g_pixelShader)     { g_pixelShader->Release();     g_pixelShader     = NULL; }
    if (g_vertexShader)    { g_vertexShader->Release();    g_vertexShader    = NULL; }
    if (g_renderTargetView){ g_renderTargetView->Release();g_renderTargetView= NULL; }
    if (g_swapChain)       { g_swapChain->Release();       g_swapChain       = NULL; }

    if (g_context)         { g_context->Release();         g_context         = NULL; }
    if (g_device)          { g_device->Release();          g_device          = NULL; }

    if (g_d3dCompilerModule) { FreeLibrary(g_d3dCompilerModule); g_d3dCompilerModule = NULL; }
    if (g_d3d11Module)       { FreeLibrary(g_d3d11Module);       g_d3d11Module       = NULL; }

    g_D3D11CreateDeviceAndSwapChain = NULL;
    g_D3DCompile                    = NULL;
}

void FFX_Renderer_BeginFrame(void)
{
    if (!g_context || !g_renderTargetView)
        return;

    float clearColor[4] = { 0.0f, 0.0f, 0.1f, 1.0f };
    g_context->OMSetRenderTargets(1, &g_renderTargetView, NULL);

    D3D11_VIEWPORT vp;
    vp.TopLeftX = 0.0f;
    vp.TopLeftY = 0.0f;
    vp.Width    = (FLOAT)g_backbufferWidth;
    vp.Height   = (FLOAT)g_backbufferHeight;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    g_context->RSSetViewports(1, &vp);

    g_context->ClearRenderTargetView(g_renderTargetView, clearColor);
}

void FFX_Renderer_EndFrame(void)
{
    if (g_swapChain)
        g_swapChain->Present(1, 0);
}

void FFX_Renderer_Resize(int width, int height)
{
    if (g_renderTargetView)
    {
        g_renderTargetView->Release();
        g_renderTargetView = NULL;
    }

    if (g_swapChain)
    {
        HRESULT hr = g_swapChain->ResizeBuffers(0, (UINT)width, (UINT)height,
                                                DXGI_FORMAT_UNKNOWN, 0);
        if (FAILED(hr))
            return;

        ID3D11Texture2D *backBuffer = NULL;
        hr = g_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
                                    (void**)&backBuffer);
        if (FAILED(hr) || !backBuffer)
            return;

        hr = g_device->CreateRenderTargetView(backBuffer, NULL,
                                              &g_renderTargetView);
        backBuffer->Release();
        if (FAILED(hr))
            return;
    }

    g_backbufferWidth  = width;
    g_backbufferHeight = height;
}

void FFX_Renderer_DrawTestTriangle(void)
{
    if (!g_context || !g_triangleVB || !g_inputLayout ||
        !g_vertexShader || !g_pixelShader)
        return;

    UINT stride = sizeof(TestVertex);
    UINT offset = 0;

    g_context->IASetInputLayout(g_inputLayout);
    g_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    g_context->IASetVertexBuffers(0, 1, &g_triangleVB, &stride, &offset);

    g_context->VSSetShader(g_vertexShader, NULL, 0);
    g_context->PSSetShader(g_pixelShader, NULL, 0);

    g_context->Draw(3, 0);
}

/* ---- fullscreen toggle ------------------------------------------------- */

void FFX_Renderer_ToggleFullscreen(HWND hwnd) {
    if (!g_swapChain) return;
    g_fullscreen = !g_fullscreen;
    if (g_fullscreen) {
        SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP);
        SetWindowPos(hwnd, HWND_TOP, 0, 0,
                     GetSystemMetrics(SM_CXSCREEN),
                     GetSystemMetrics(SM_CYSCREEN),
                     SWP_FRAMECHANGED);
        g_swapChain->SetFullscreenState(TRUE, NULL);
    } else {
        SetWindowLongPtr(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
        SetWindowPos(hwnd, HWND_TOP, 100, 100, 1280, 720,
                     SWP_FRAMECHANGED);
        g_swapChain->SetFullscreenState(FALSE, NULL);
    }
}

/* ---- getters for subsystems -------------------------------------------- */

ID3D11Device *FFX_Renderer_GetDevice(void)
{
    return g_device;
}

ID3D11DeviceContext *FFX_Renderer_GetContext(void)
{
    return g_context;
}

int FFX_Renderer_GetWidth(void)
{
    return g_backbufferWidth;
}

int FFX_Renderer_GetHeight(void)
{
    return g_backbufferHeight;
}
