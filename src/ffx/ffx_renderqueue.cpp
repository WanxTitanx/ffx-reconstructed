/* ===========================================================================
 * ffx_renderqueue.cpp — Deferred Quad Batching for D3D11
 *
 * Accumulates 2D quads (colored quads; texturing to come later) and flushes
 * them in a single DrawIndexed call.  Uses the device/context created by
 * ffx_renderer.cpp.  Shaders are compiled at runtime from inline HLSL via
 * d3dcompiler_47.dll (loaded via GetProcAddress — no static link).
 * ===========================================================================*/

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include <d3d11.h>        /* ID3D11Device, ID3D11DeviceContext, … */
#include <d3dcompiler.h>  /* ID3DBlob */

#include "ffx_renderqueue.h"
#include "ffx_renderer.h"

#include <stdlib.h>       /* malloc, free */
#include <string.h>       /* memset */
#include <stdint.h>
#include <stdio.h>        /* fopen, fprintf, fclose */

/* ---- D3DCompile function-pointer typedef ------------------------------- */

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

/* ---- static globals ---------------------------------------------------- */

static HMODULE            g_d3dCompilerModule = NULL;
static D3DCompile_t       g_D3DCompile        = NULL;

static ID3D11Device       *g_device  = NULL;
static ID3D11DeviceContext *g_context = NULL;

static ID3D11Buffer       *g_vertexBuffer   = NULL;
static ID3D11Buffer       *g_indexBuffer    = NULL;
static ID3D11Buffer       *g_constantBuffer = NULL;
static ID3D11VertexShader *g_vertexShader   = NULL;
static ID3D11PixelShader  *g_pixelShader    = NULL;
static ID3D11PixelShader  *g_pixelShaderTex = NULL;
static ID3D11SamplerState *g_sampler        = NULL;
static ID3D11InputLayout  *g_inputLayout    = NULL;
static ID3D11RasterizerState *g_rasterState = NULL;
static ID3D11BlendState      *g_blendState  = NULL;
static ID3D11DepthStencilState *g_depthState = NULL;

static FFXVertex2D  g_quadQueue[FFX_MAX_QUADS * FFX_VERTICES_PER_QUAD];
static void        *g_quadSRVs[FFX_MAX_QUADS]; /* ID3D11ShaderResourceView* per quad, NULL = solid color */
static int          g_quadCount = 0;

static int g_backbufferWidth  = 1280;
static int g_backbufferHeight = 720;

/* ---- inline HLSL shaders ----------------------------------------------- */

/*
 * Vertex shader — transforms 2D screen-space positions through an ortho
 * projection matrix stored in constant buffer b0.
 */
static const char g_quadVS[] =
    "cbuffer ProjectionCB : register(b0) {\n"
    "    float4x4 ProjectionMatrix;\n"
    "};\n"
    "struct VSInput {\n"
    "    float3 pos   : POSITION;\n"
    "    float2 uv    : TEXCOORD;\n"
    "    float4 color : COLOR;\n"
    "};\n"
    "struct VSOutput {\n"
    "    float4 pos   : SV_Position;\n"
    "    float2 uv    : TEXCOORD;\n"
    "    float4 color : COLOR;\n"
    "};\n"
    "VSOutput main(VSInput input) {\n"
    "    VSOutput output;\n"
    "    output.pos   = mul(float4(input.pos, 1.0), ProjectionMatrix);\n"
    "    output.uv    = input.uv;\n"
    "    output.color = input.color;\n"
    "    return output;\n"
    "}\n";

/* Pixel shader — solid color (no texture). */
static const char g_quadPS[] =
    "struct PSInput {\n"
    "    float4 pos   : SV_Position;\n"
    "    float2 uv    : TEXCOORD;\n"
    "    float4 color : COLOR;\n"
    "};\n"
    "float4 main(PSInput input) : SV_Target {\n"
    "    return input.color;\n"
    "}\n";

/* Pixel shader — textured: sample from t0, modulate by vertex color. */
static const char g_quadTexPS[] =
    "Texture2D tex : register(t0);\n"
    "SamplerState samp : register(s0);\n"
    "struct PSInput {\n"
    "    float4 pos   : SV_Position;\n"
    "    float2 uv    : TEXCOORD;\n"
    "    float4 color : COLOR;\n"
    "};\n"
    "float4 main(PSInput input) : SV_Target {\n"
    "    float4 t = tex.Sample(samp, input.uv);\n"
    "    return t * input.color;\n"
    "}\n";

/* ---- helpers ----------------------------------------------------------- */

/* Pack 4 floats [0..1] into a uint32_t suitable for R8G8B8A8_UNORM.
 *
 * Memory order (little-endian): byte[0]=R, byte[1]=G, byte[2]=B, byte[3]=A,
 * which is exactly what D3D11 R8G8B8A8_UNORM expects. */
static uint32_t packColor(float r, float g, float b, float a)
{
    uint32_t ri = (uint32_t)(r * 255.0f) & 0xFF;
    uint32_t gi = (uint32_t)(g * 255.0f) & 0xFF;
    uint32_t bi = (uint32_t)(b * 255.0f) & 0xFF;
    uint32_t ai = (uint32_t)(a * 255.0f) & 0xFF;
    return (ai << 24) | (bi << 16) | (gi << 8) | ri;
}

/* Linearly interpolate two ARGB-packed colors by factor t [0..1]. */
static uint32_t lerpColor(uint32_t c1, uint32_t c2, float t)
{
    float invT = 1.0f - t;
    uint32_t a = (uint32_t)(((c1 >> 24) & 0xFF) * invT + ((c2 >> 24) & 0xFF) * t);
    uint32_t r = (uint32_t)(((c1 >> 16) & 0xFF) * invT + ((c2 >> 16) & 0xFF) * t);
    uint32_t g = (uint32_t)(((c1 >>  8) & 0xFF) * invT + ((c2 >>  8) & 0xFF) * t);
    uint32_t b = (uint32_t)(((c1 >>  0) & 0xFF) * invT + ((c2 >>  0) & 0xFF) * t);
    return (a << 24) | (r << 16) | (g << 8) | b;
}

/* ---- shader compilation helpers ---------------------------------------- */

static int LoadD3DCompiler(void)
{
    if (g_d3dCompilerModule)
        return 1;  /* already loaded */

    g_d3dCompilerModule = LoadLibraryA("d3dcompiler_47.dll");
    if (!g_d3dCompilerModule)
        return 0;

    g_D3DCompile = (D3DCompile_t)
        GetProcAddress(g_d3dCompilerModule, "D3DCompile");
    if (!g_D3DCompile) {
        FreeLibrary(g_d3dCompilerModule);
        g_d3dCompilerModule = NULL;
        return 0;
    }
    return 1;
}

static int CompileVertexShader(const char *src, SIZE_T srcLen,
                               ID3DBlob **ppCode, ID3DBlob **ppErrors)
{
    HRESULT hr = g_D3DCompile(src, srcLen, "ffx_quad_vs.hlsl",
                              NULL, NULL, "main", "vs_4_0",
                              0, 0, ppCode, ppErrors);
    return SUCCEEDED(hr) ? 1 : 0;
}

static int CompilePixelShader(const char *src, SIZE_T srcLen,
                              ID3DBlob **ppCode, ID3DBlob **ppErrors)
{
    HRESULT hr = g_D3DCompile(src, srcLen, "ffx_quad_ps.hlsl",
                              NULL, NULL, "main", "ps_4_0",
                              0, 0, ppCode, ppErrors);
    return SUCCEEDED(hr) ? 1 : 0;
}

/* ---- resource creation ------------------------------------------------- */

static int CreateShaders(void)
{
    ID3DBlob *vsCode     = NULL;
    ID3DBlob *psCode     = NULL;
    ID3DBlob *psTexCode  = NULL;
    ID3DBlob *vsErrors   = NULL;
    ID3DBlob *psErrors   = NULL;
    ID3DBlob *psTexErrors = NULL;
    int       result     = 0;

    /* Compile vertex shader */
    if (!CompileVertexShader(g_quadVS, strlen(g_quadVS), &vsCode, &vsErrors))
        goto cleanup;

    /* Compile solid-color pixel shader */
    if (!CompilePixelShader(g_quadPS, strlen(g_quadPS), &psCode, &psErrors))
        goto cleanup;

    /* Compile textured pixel shader */
    if (!CompilePixelShader(g_quadTexPS, strlen(g_quadTexPS), &psTexCode, &psTexErrors))
        goto cleanup;

    /* Create VS */
    if (FAILED(g_device->CreateVertexShader(
            vsCode->GetBufferPointer(),
            vsCode->GetBufferSize(),
            NULL, &g_vertexShader)))
        goto cleanup;

    /* Create solid-color PS */
    if (FAILED(g_device->CreatePixelShader(
            psCode->GetBufferPointer(),
            psCode->GetBufferSize(),
            NULL, &g_pixelShader)))
        goto cleanup;

    /* Create textured PS */
    if (FAILED(g_device->CreatePixelShader(
            psTexCode->GetBufferPointer(),
            psTexCode->GetBufferSize(),
            NULL, &g_pixelShaderTex)))
        goto cleanup;

    /* Input layout:
     *   POSITION — R32G32B32_FLOAT (12 bytes) — matches FFXVertex2D.x/.y/.z
     *   TEXCOORD — R32G32_FLOAT     ( 8 bytes)
     *   COLOR    — R8G8B8A8_UNORM   ( 4 bytes)
     *   total stride = 24 bytes */
    D3D11_INPUT_ELEMENT_DESC layoutDesc[3] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
          D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, D3D11_APPEND_ALIGNED_ELEMENT,
          D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R8G8B8A8_UNORM,  0, D3D11_APPEND_ALIGNED_ELEMENT,
          D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    if (FAILED(g_device->CreateInputLayout(
            layoutDesc, 3,
            vsCode->GetBufferPointer(),
            vsCode->GetBufferSize(),
            &g_inputLayout)))
        goto cleanup;

    result = 1;

cleanup:
    if (vsCode)      vsCode->Release();
    if (psCode)      psCode->Release();
    if (psTexCode)   psTexCode->Release();
    if (vsErrors)    vsErrors->Release();
    if (psErrors)    psErrors->Release();
    if (psTexErrors) psTexErrors->Release();
    return result;
}

static int CreateSampler(void)
{
    D3D11_SAMPLER_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.Filter         = D3D11_FILTER_MIN_MAG_MIP_POINT;
    sd.AddressU       = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV       = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW       = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.MaxLOD         = D3D11_FLOAT32_MAX;

    HRESULT hr = g_device->CreateSamplerState(&sd, &g_sampler);
    return SUCCEEDED(hr) ? 1 : 0;
}

static int CreateVertexBuffer(void)
{
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.ByteWidth      = FFX_MAX_VERTICES * sizeof(FFXVertex2D);
    bd.Usage          = D3D11_USAGE_DYNAMIC;
    bd.BindFlags      = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    HRESULT hr = g_device->CreateBuffer(&bd, NULL, &g_vertexBuffer);
    return SUCCEEDED(hr) ? 1 : 0;
}

static int CreateIndexBuffer(void)
{
    /* Precompute indices for FFX_MAX_QUADS quads.
     * For quad i:  (i*4+0, i*4+1, i*4+2,  i*4+2, i*4+1, i*4+3)
     * Winding order: TL, TR, BL  —  BL, TR, BR  (counter-clockwise). */
    uint32_t *indices = (uint32_t *)malloc(FFX_MAX_INDICES * sizeof(uint32_t));
    if (!indices)
        return 0;

    for (int i = 0; i < FFX_MAX_QUADS; i++) {
        uint32_t base  = (uint32_t)i * 4;
        int      dst   = i * 6;
        indices[dst + 0] = base + 0;
        indices[dst + 1] = base + 1;
        indices[dst + 2] = base + 2;
        indices[dst + 3] = base + 2;
        indices[dst + 4] = base + 1;
        indices[dst + 5] = base + 3;
    }

    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.ByteWidth      = FFX_MAX_INDICES * sizeof(uint32_t);
    bd.Usage          = D3D11_USAGE_IMMUTABLE;
    bd.BindFlags      = D3D11_BIND_INDEX_BUFFER;

    D3D11_SUBRESOURCE_DATA srd;
    ZeroMemory(&srd, sizeof(srd));
    srd.pSysMem = indices;

    HRESULT hr = g_device->CreateBuffer(&bd, &srd, &g_indexBuffer);

    free(indices);
    return SUCCEEDED(hr) ? 1 : 0;
}

static int CreateConstantBuffer(void)
{
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.ByteWidth      = 16 * sizeof(float);
    bd.Usage          = D3D11_USAGE_DYNAMIC;
    bd.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    HRESULT hr = g_device->CreateBuffer(&bd, NULL, &g_constantBuffer);
    return SUCCEEDED(hr) ? 1 : 0;
}

/* ---- public API -------------------------------------------------------- */

int FFX_RenderQueue_Init(void)
{
    FILE *log = fopen("ffx_debug.log", "a");
    if (log) fprintf(log, "[RQ] Init start\n");

    g_device  = FFX_Renderer_GetDevice();
    g_context = FFX_Renderer_GetContext();
    if (!g_device || !g_context) {
        if (log) { fprintf(log, "[RQ] FAIL: no device/context\n"); fclose(log); }
        return 0;
    }
    if (log) fprintf(log, "[RQ] device=%p context=%p\n", g_device, g_context);

    g_backbufferWidth  = FFX_Renderer_GetWidth();
    g_backbufferHeight = FFX_Renderer_GetHeight();
    if (log) fprintf(log, "[RQ] backbuffer %dx%d\n", g_backbufferWidth, g_backbufferHeight);

    if (!LoadD3DCompiler()) {
        if (log) { fprintf(log, "[RQ] FAIL: d3dcompiler_47.dll not found\n"); fclose(log); }
        return 0;
    }
    if (log) fprintf(log, "[RQ] d3dcompiler loaded OK\n");

    if (!CreateVertexBuffer()) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateVertexBuffer\n"); fclose(log); }
        return 0;
    }
    if (!CreateIndexBuffer()) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateIndexBuffer\n"); fclose(log); }
        return 0;
    }
    if (!CreateConstantBuffer()) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateConstantBuffer\n"); fclose(log); }
        return 0;
    }
    if (!CreateShaders()) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateShaders\n"); fclose(log); }
        return 0;
    }
    if (log) fprintf(log, "[RQ] shaders compiled OK\n");

    if (!CreateSampler()) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateSampler\n"); fclose(log); }
        return 0;
    }

    D3D11_RASTERIZER_DESC rd;
    ZeroMemory(&rd, sizeof(rd));
    rd.FillMode = D3D11_FILL_SOLID;
    rd.CullMode = D3D11_CULL_NONE;
    rd.ScissorEnable = FALSE;
    rd.DepthClipEnable = FALSE;
    if (FAILED(g_device->CreateRasterizerState(&rd, &g_rasterState))) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateRasterizerState\n"); fclose(log); }
        return 0;
    }

    D3D11_BLEND_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.RenderTarget[0].BlendEnable = TRUE;
    bd.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    bd.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    bd.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    bd.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    bd.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    bd.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    bd.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    if (FAILED(g_device->CreateBlendState(&bd, &g_blendState))) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateBlendState\n"); fclose(log); }
        return 0;
    }

    D3D11_DEPTH_STENCIL_DESC dsd;
    ZeroMemory(&dsd, sizeof(dsd));
    dsd.DepthEnable = FALSE;
    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
    dsd.DepthFunc = D3D11_COMPARISON_ALWAYS;
    dsd.StencilEnable = FALSE;
    if (FAILED(g_device->CreateDepthStencilState(&dsd, &g_depthState))) {
        if (log) { fprintf(log, "[RQ] FAIL: CreateDepthStencilState\n"); fclose(log); }
        return 0;
    }

    if (log) { fprintf(log, "[RQ] Init ALL OK\n"); fclose(log); }

    g_quadCount = 0;
    ZeroMemory(g_quadSRVs, sizeof(g_quadSRVs));
    return 1;
}

void FFX_RenderQueue_Shutdown(void)
{
    if (g_depthState)       { g_depthState->Release();        g_depthState       = NULL; }
    if (g_blendState)       { g_blendState->Release();        g_blendState      = NULL; }
    if (g_rasterState)     { g_rasterState->Release();      g_rasterState     = NULL; }
    if (g_sampler)         { g_sampler->Release();          g_sampler         = NULL; }
    if (g_pixelShaderTex)  { g_pixelShaderTex->Release();   g_pixelShaderTex  = NULL; }
    if (g_inputLayout)     { g_inputLayout->Release();      g_inputLayout     = NULL; }
    if (g_pixelShader)     { g_pixelShader->Release();      g_pixelShader     = NULL; }
    if (g_vertexShader)    { g_vertexShader->Release();     g_vertexShader    = NULL; }
    if (g_constantBuffer)  { g_constantBuffer->Release();   g_constantBuffer  = NULL; }
    if (g_indexBuffer)     { g_indexBuffer->Release();      g_indexBuffer     = NULL; }
    if (g_vertexBuffer)    { g_vertexBuffer->Release();     g_vertexBuffer    = NULL; }

    if (g_d3dCompilerModule) {
        FreeLibrary(g_d3dCompilerModule);
        g_d3dCompilerModule = NULL;
    }

    g_device  = NULL;
    g_context = NULL;
    g_quadCount = 0;
    ZeroMemory(g_quadSRVs, sizeof(g_quadSRVs));
}

void FFX_RenderQueue_PushRect(float x, float y, float w, float h,
                              uint32_t colorTop, uint32_t colorBot)
{
    if (g_quadCount >= FFX_MAX_QUADS)
        return;

    int base = g_quadCount * 4;
    g_quadSRVs[g_quadCount] = NULL;  /* solid color */
    g_quadCount++;

    float x1 = x;
    float y1 = y;
    float x2 = x + w;
    float y2 = y + h;

    /* TL */ g_quadQueue[base + 0].x = x1;  g_quadQueue[base + 0].y = y1;  g_quadQueue[base + 0].z = 0.0f;
             g_quadQueue[base + 0].u = 0.0f; g_quadQueue[base + 0].v = 0.0f;
             g_quadQueue[base + 0].color = colorTop;

    /* TR */ g_quadQueue[base + 1].x = x2;  g_quadQueue[base + 1].y = y1;  g_quadQueue[base + 1].z = 0.0f;
             g_quadQueue[base + 1].u = 1.0f; g_quadQueue[base + 1].v = 0.0f;
             g_quadQueue[base + 1].color = colorTop;

    /* BL */ g_quadQueue[base + 2].x = x1;  g_quadQueue[base + 2].y = y2;  g_quadQueue[base + 2].z = 0.0f;
             g_quadQueue[base + 2].u = 0.0f; g_quadQueue[base + 2].v = 1.0f;
             g_quadQueue[base + 2].color = colorBot;

    /* BR */ g_quadQueue[base + 3].x = x2;  g_quadQueue[base + 3].y = y2;  g_quadQueue[base + 3].z = 0.0f;
             g_quadQueue[base + 3].u = 1.0f; g_quadQueue[base + 3].v = 1.0f;
             g_quadQueue[base + 3].color = colorBot;
}

void FFX_RenderQueue_PushQuad(float x, float y, float w, float h,
                              float u0, float v0, float u1, float v1,
                              uint32_t c0, uint32_t c1,
                              uint32_t c2, uint32_t c3)
{
    if (g_quadCount >= FFX_MAX_QUADS)
        return;

    int base = g_quadCount * 4;
    g_quadSRVs[g_quadCount] = NULL;  /* solid color */
    g_quadCount++;

    float x1 = x;
    float y1 = y;
    float x2 = x + w;
    float y2 = y + h;

    /* TL */ g_quadQueue[base + 0].x = x1;  g_quadQueue[base + 0].y = y1;  g_quadQueue[base + 0].z = 0.0f;
             g_quadQueue[base + 0].u = u0;   g_quadQueue[base + 0].v = v0;
             g_quadQueue[base + 0].color = c0;

    /* TR */ g_quadQueue[base + 1].x = x2;  g_quadQueue[base + 1].y = y1;  g_quadQueue[base + 1].z = 0.0f;
             g_quadQueue[base + 1].u = u1;   g_quadQueue[base + 1].v = v0;
             g_quadQueue[base + 1].color = c1;

    /* BL */ g_quadQueue[base + 2].x = x1;  g_quadQueue[base + 2].y = y2;  g_quadQueue[base + 2].z = 0.0f;
             g_quadQueue[base + 2].u = u0;   g_quadQueue[base + 2].v = v1;
             g_quadQueue[base + 2].color = c2;

    /* BR */ g_quadQueue[base + 3].x = x2;  g_quadQueue[base + 3].y = y2;  g_quadQueue[base + 3].z = 0.0f;
             g_quadQueue[base + 3].u = u1;   g_quadQueue[base + 3].v = v1;
             g_quadQueue[base + 3].color = c3;
}

void FFX_RenderQueue_PushQuadTex(float x, float y, float w, float h,
                                 float u0, float v0, float u1, float v1,
                                 uint32_t c0, uint32_t c1,
                                 uint32_t c2, uint32_t c3,
                                 void *srv)
{
    if (g_quadCount >= FFX_MAX_QUADS)
        return;

    int base = g_quadCount * 4;
    g_quadSRVs[g_quadCount] = srv;
    g_quadCount++;

    float x1 = x;
    float y1 = y;
    float x2 = x + w;
    float y2 = y + h;

    /* TL */ g_quadQueue[base + 0].x = x1;  g_quadQueue[base + 0].y = y1;  g_quadQueue[base + 0].z = 0.0f;
             g_quadQueue[base + 0].u = u0;   g_quadQueue[base + 0].v = v0;
             g_quadQueue[base + 0].color = c0;

    /* TR */ g_quadQueue[base + 1].x = x2;  g_quadQueue[base + 1].y = y1;  g_quadQueue[base + 1].z = 0.0f;
             g_quadQueue[base + 1].u = u1;   g_quadQueue[base + 1].v = v0;
             g_quadQueue[base + 1].color = c1;

    /* BL */ g_quadQueue[base + 2].x = x1;  g_quadQueue[base + 2].y = y2;  g_quadQueue[base + 2].z = 0.0f;
             g_quadQueue[base + 2].u = u0;   g_quadQueue[base + 2].v = v1;
             g_quadQueue[base + 2].color = c2;

    /* BR */ g_quadQueue[base + 3].x = x2;  g_quadQueue[base + 3].y = y2;  g_quadQueue[base + 3].z = 0.0f;
             g_quadQueue[base + 3].u = u1;   g_quadQueue[base + 3].v = v1;
             g_quadQueue[base + 3].color = c3;
}

void FFX_RenderQueue_DrawText(const char *text, float x, float y, float scale,
                              uint32_t color, void *fontSRV,
                              int fontCols, int fontRows, int charW, int charH)
{
    if (!text || !fontSRV)
        return;

    FILE *log = fopen("ffx_text.log", "a");
    if (log) { fprintf(log, "[Text] '%s' at (%.0f,%.0f) scale=%.1f cols=%d rows=%d cw=%d ch=%d srv=%p\n", text, x, y, scale, fontCols, fontRows, charW, charH, fontSRV); fclose(log); }

    float glyphW = (float)charW * scale;
    float glyphH = (float)charH * scale;
    float texCellW = 1.0f / (float)fontCols;
    float texCellH = 1.0f / (float)fontRows;

    int i = 0;
    float cx = x;
    while (text[i]) {
        unsigned char ch = (unsigned char)text[i];
        int idx = ch - 0x20;
        if (idx >= 0 && idx < fontCols * fontRows) {
            int col = idx % fontCols;
            int row = idx / fontCols;
            float u0 = col * texCellW;
            float v0 = row * texCellH;
            float u1 = u0 + texCellW;
            float v1 = v0 + texCellH;
            FFX_RenderQueue_PushQuadTex(cx, y, glyphW, glyphH,
                                       u0, v0, u1, v1,
                                       color, color, color, color, fontSRV);
        }
        cx += glyphW;
        i++;
    }
}

void FFX_RenderQueue_Flush(void)
{
    if (g_quadCount == 0)
        return;
    if (!g_context || !g_vertexBuffer || !g_indexBuffer ||
        !g_vertexShader || !g_pixelShader || !g_inputLayout || !g_constantBuffer)
        return;

    FILE *log = fopen("C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\ffx_flush.log", "a");
    if (log) fprintf(log, "[Flush] quads=%d stride=%d\n", g_quadCount, (int)sizeof(FFXVertex2D));

    /* ---- map vertex buffer and copy queued vertices ---- */
    D3D11_MAPPED_SUBRESOURCE mapped;
    HRESULT hr = g_context->Map(g_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
    if (FAILED(hr))
        return;

    memcpy(mapped.pData, g_quadQueue, g_quadCount * 4 * sizeof(FFXVertex2D));
    g_context->Unmap(g_vertexBuffer, 0);

    /* ---- build orthographic projection matrix ---- */
    /* Screen-space (0,0 = top-left) to clip-space (-1..1).
     * Column-major float array for HLSL float4x4:
     *   2/w   0    0  0
     *   0   -2/h   0  0
     *   0    0     1  0
     *  -1    1     0  1   */
    float w = (float)g_backbufferWidth;
    float h = (float)g_backbufferHeight;
    float proj[16] = {
        2.0f / w,  0.0f,       0.0f, 0.0f,
        0.0f,     -2.0f / h,   0.0f, 0.0f,
        0.0f,      0.0f,       1.0f, 0.0f,
       -1.0f,      1.0f,       0.0f, 1.0f
    };
    float projT[16];
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            projT[r * 4 + c] = proj[c * 4 + r];

    D3D11_MAPPED_SUBRESOURCE cbMapped;
    if (SUCCEEDED(g_context->Map(g_constantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &cbMapped))) {
        memcpy(cbMapped.pData, projT, sizeof(projT));
        g_context->Unmap(g_constantBuffer, 0);
    }

    /* ---- IA stage ---- */
    UINT stride = sizeof(FFXVertex2D);
    UINT offset = 0;
    g_context->IASetInputLayout(g_inputLayout);
    g_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    g_context->IASetVertexBuffers(0, 1, &g_vertexBuffer, &stride, &offset);
    g_context->IASetIndexBuffer(g_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

    if (g_rasterState)
        g_context->RSSetState(g_rasterState);
    g_context->OMSetBlendState(g_blendState, NULL, 0xFFFFFFFF);
    g_context->OMSetDepthStencilState(g_depthState, 0);

    g_context->VSSetShader(g_vertexShader, NULL, 0);
    g_context->VSSetConstantBuffers(0, 1, &g_constantBuffer);

    /* ---- PS stage: draw all quads in a single batch ---- */
    /* Simplified: no batch sorting, draw all quads at once.
       Each quad's SRV is stored in g_quadSRVs but we can only bind one SRV
       at a time. For mixed textured/solid quads, we draw them in order. */
    int batchStart = 0;
    while (batchStart < g_quadCount) {
        void *currentSRV = g_quadSRVs[batchStart];
        int batchEnd = batchStart + 1;
        while (batchEnd < g_quadCount && g_quadSRVs[batchEnd] == currentSRV)
            batchEnd++;
        int batchSize = batchEnd - batchStart;

        if (currentSRV) {
            if (g_pixelShaderTex) {
                ID3D11ShaderResourceView *srv = (ID3D11ShaderResourceView *)currentSRV;
                g_context->PSSetShader(g_pixelShaderTex, NULL, 0);
                g_context->PSSetShaderResources(0, 1, &srv);
                if (g_sampler) g_context->PSSetSamplers(0, 1, &g_sampler);
            }
        } else {
            g_context->PSSetShader(g_pixelShader, NULL, 0);
            ID3D11ShaderResourceView *nullSRV = NULL;
            g_context->PSSetShaderResources(0, 1, &nullSRV);
        }

        g_context->DrawIndexed((UINT)batchSize * 6,
                               (UINT)batchStart * 6,
                               (UINT)batchStart * 4);

        batchStart = batchEnd;
    }

    if (log) { fprintf(log, "[Flush] done quads=%d\n", g_quadCount); fclose(log); }

    g_quadCount = 0;
    ZeroMemory(g_quadSRVs, sizeof(g_quadSRVs));
}

void FFX_RenderQueue_Resize(int width, int height)
{
    g_backbufferWidth  = width;
    g_backbufferHeight = height;
}

static float g_plasmaTime = 0.0f;

void FFX_RenderQueue_UpdatePlasma(float time)
{
    g_plasmaTime = time;
}

void FFX_RenderQueue_Clear(void)
{
    g_quadCount = 0;
}
