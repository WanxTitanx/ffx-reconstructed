#include "ffx_fmv_player.h"
#include "ffx_texture.h"
#include "ffx_renderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <mfapi.h>
#include <mfreadwrite.h>
#include <mfidl.h>
#include <wrl/client.h>

using Microsoft::WRL::ComPtr;

#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mfreadwrite.lib")
#pragma comment(lib, "mfuuid.lib")

static ComPtr<IMFSourceReader> g_reader;
static ComPtr<ID3D11Texture2D> g_videoTexture;
static ComPtr<ID3D11ShaderResourceView> g_videoSRV;
static int g_width = 0;
static int g_height = 0;
static int g_initialized = 0;

int FFX_FMV_Init(void)
{
    HRESULT hr = MFStartup(MF_VERSION);
    if (FAILED(hr)) return 0;
    g_initialized = 1;
    return 1;
}

int FFX_FMV_Load(const char *webmPath)
{
    if (!g_initialized) FFX_FMV_Init();

    wchar_t wpath[1024];
    MultiByteToWideChar(CP_UTF8, 0, webmPath, -1, wpath, 1024);

    ComPtr<IMFAttributes> attrs;
    MFCreateAttributes(&attrs, 1);

    HRESULT hr = MFCreateSourceReaderFromURL(wpath, attrs.Get(), &g_reader);
    if (FAILED(hr)) return 0;

    ComPtr<IMFMediaType> outputType;
    MFCreateMediaType(&outputType);
    outputType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
    outputType->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_RGB32);

    hr = g_reader->SetCurrentMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM, nullptr, outputType.Get());
    if (FAILED(hr)) return 0;

    ComPtr<IMFMediaType> actualType;
    g_reader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM, &actualType);
    MFGetAttributeSize(actualType.Get(), MF_MT_FRAME_SIZE, (UINT32*)&g_width, (UINT32*)&g_height);

    ID3D11Device *device = (ID3D11Device *)FFX_Renderer_GetDevice();
    if (!device) return 0;

    D3D11_TEXTURE2D_DESC td = {};
    td.Width = g_width;
    td.Height = g_height;
    td.MipLevels = 1;
    td.ArraySize = 1;
    td.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    td.SampleDesc.Count = 1;
    td.Usage = D3D11_USAGE_DYNAMIC;
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    td.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    hr = device->CreateTexture2D(&td, nullptr, &g_videoTexture);
    if (FAILED(hr)) return 0;

    hr = device->CreateShaderResourceView(g_videoTexture.Get(), nullptr, &g_videoSRV);
    if (FAILED(hr)) return 0;

    return 1;
}

int FFX_FMV_NextFrame(void)
{
    if (!g_reader || !g_videoTexture) return 0;

    DWORD streamFlags = 0;
    LONGLONG timestamp = 0;
    ComPtr<IMFSample> sample;

    HRESULT hr = g_reader->ReadSample(
        MF_SOURCE_READER_FIRST_VIDEO_STREAM,
        0, nullptr, &streamFlags, &timestamp, &sample
    );

    if (FAILED(hr)) return 0;
    if (streamFlags & MF_SOURCE_READERF_ENDOFSTREAM) return 0;
    if (!sample) return 1;

    ComPtr<IMFMediaBuffer> buffer;
    hr = sample->ConvertToContiguousBuffer(&buffer);
    if (FAILED(hr)) return 0;

    BYTE *data = nullptr;
    DWORD maxLen = 0, curLen = 0;
    hr = buffer->Lock(&data, &maxLen, &curLen);
    if (FAILED(hr)) return 0;

    ID3D11DeviceContext *ctx = (ID3D11DeviceContext *)FFX_Renderer_GetContext();
    if (ctx) {
        D3D11_MAPPED_SUBRESOURCE mapped = {};
        hr = ctx->Map(g_videoTexture.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
        if (SUCCEEDED(hr)) {
            int srcPitch = g_width * 4;
            for (int y = 0; y < g_height; y++) {
                memcpy(
                    (BYTE *)mapped.pData + y * mapped.RowPitch,
                    data + (g_height - 1 - y) * srcPitch,
                    srcPitch
                );
            }
            ctx->Unmap(g_videoTexture.Get(), 0);
        }
    }

    buffer->Unlock();
    return 1;
}

void *FFX_FMV_GetFrameSRV(void)
{
    return g_videoSRV.Get();
}

int FFX_FMV_GetWidth(void) { return g_width; }
int FFX_FMV_GetHeight(void) { return g_height; }

void FFX_FMV_Shutdown(void)
{
    g_reader.Reset();
    g_videoTexture.Reset();
    g_videoSRV.Reset();
    if (g_initialized) {
        MFShutdown();
        g_initialized = 0;
    }
}
