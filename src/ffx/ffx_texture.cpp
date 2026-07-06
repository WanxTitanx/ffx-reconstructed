/* ===========================================================================
 * ffx_texture.cpp -- D3D11 Texture Manager
 *
 * Loads image files (PNG, JPG, BMP, TGA, etc. via stb_image) into
 * ID3D11ShaderResourceView objects, cached by name for the render queue.
 * ===========================================================================*/

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include <d3d11.h>

#include "ffx_texture.h"
#include "ffx_renderer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb/stb_image.h"

#include <string.h>
#include <stdio.h>

/* ---- globals ------------------------------------------------------------ */

static FFXTexture g_textures[FFX_MAX_TEXTURES];
static int        g_textureCount = 0;

/* ---- internal helpers -------------------------------------------------- */

static int FindSlot(const char *name)
{
    for (int i = 0; i < g_textureCount; i++) {
        if (strcmp(g_textures[i].name, name) == 0)
            return i;
    }
    return -1;
}

static int FindFreeSlot(void)
{
    if (g_textureCount < FFX_MAX_TEXTURES)
        return g_textureCount++;
    /* Search for an empty name slot (should not happen in normal use). */
    for (int i = 0; i < FFX_MAX_TEXTURES; i++) {
        if (g_textures[i].name[0] == '\0')
            return i;
    }
    return -1;
}

/* ---- public API -------------------------------------------------------- */

int FFX_Texture_Init(void)
{
    ZeroMemory(g_textures, sizeof(g_textures));
    g_textureCount = 0;
    return 1;
}

void FFX_Texture_Shutdown(void)
{
    for (int i = 0; i < FFX_MAX_TEXTURES; i++) {
        if (g_textures[i].srv) {
            ((ID3D11ShaderResourceView *)g_textures[i].srv)->Release();
            g_textures[i].srv = NULL;
        }
    }
    ZeroMemory(g_textures, sizeof(g_textures));
    g_textureCount = 0;
}

int FFX_Texture_Load(const char *filePath, const char *name)
{
    if (!filePath || !name)
        return 0;

    int w, h, channels;
    unsigned char *data = stbi_load(filePath, &w, &h, &channels, 4);
    if (!data)
        return 0;

    int result = FFX_Texture_CreateFromMemory(data, w, h, 4, name);
    stbi_image_free(data);
    return result;
}

int FFX_Texture_CreateFromMemory(const unsigned char *data,
                                 int w, int h, int channels,
                                 const char *name)
{
    if (!data || !name || w <= 0 || h <= 0)
        return 0;

    if (channels < 3 || channels > 4)
        return 0;  /* we only handle 3- or 4-channel source data */

    ID3D11Device *device = (ID3D11Device *)FFX_Renderer_GetDevice();
    if (!device)
        return 0;

    /* Build a 4-channel RGBA buffer if the source is 3-channel. */
    unsigned char *rgba = NULL;
    const unsigned char *pixels = data;

    if (channels == 3) {
        rgba = (unsigned char *)malloc((size_t)w * h * 4);
        if (!rgba)
            return 0;
        for (int i = 0; i < w * h; i++) {
            rgba[i * 4 + 0] = data[i * 3 + 0];
            rgba[i * 4 + 1] = data[i * 3 + 1];
            rgba[i * 4 + 2] = data[i * 3 + 2];
            rgba[i * 4 + 3] = 255;
        }
        pixels = rgba;
    }

    D3D11_TEXTURE2D_DESC td;
    ZeroMemory(&td, sizeof(td));
    td.Width            = (UINT)w;
    td.Height           = (UINT)h;
    td.MipLevels        = 1;
    td.ArraySize        = 1;
    td.Format           = DXGI_FORMAT_R8G8B8A8_UNORM;
    td.SampleDesc.Count = 1;
    td.Usage            = D3D11_USAGE_DEFAULT;
    td.BindFlags        = D3D11_BIND_SHADER_RESOURCE;

    D3D11_SUBRESOURCE_DATA srd;
    ZeroMemory(&srd, sizeof(srd));
    srd.pSysMem          = pixels;
    srd.SysMemPitch      = (UINT)(w * 4);

    ID3D11Texture2D *texture = NULL;
    HRESULT hr = device->CreateTexture2D(&td, &srd, &texture);
    if (rgba)
        free(rgba);

    if (FAILED(hr) || !texture)
        return 0;

    ID3D11ShaderResourceView *srv = NULL;
    hr = device->CreateShaderResourceView(texture, NULL, &srv);
    texture->Release();  /* SRV holds a reference */

    if (FAILED(hr) || !srv)
        return 0;

    int slot = FindFreeSlot();
    if (slot < 0) {
        srv->Release();
        return 0;
    }

    g_textures[slot].srv      = srv;
    g_textures[slot].width    = w;
    g_textures[slot].height   = h;
    g_textures[slot].channels = 4;
    strncpy(g_textures[slot].name, name, sizeof(g_textures[slot].name) - 1);
    g_textures[slot].name[sizeof(g_textures[slot].name) - 1] = '\0';

    return 1;
}

void *FFX_Texture_GetSRV(const char *name)
{
    if (!name)
        return NULL;
    int slot = FindSlot(name);
    if (slot < 0)
        return NULL;
    return g_textures[slot].srv;
}

/* ---- atlas registry ----------------------------------------------------- */

typedef struct {
    int   atlasId;
    char  name[64];
} AtlasEntry;

static AtlasEntry g_atlases[FFX_MAX_ATLASES];
static int        g_atlasCount = 0;

int FFX_Texture_RegisterAtlas(int atlasId, const char *name)
{
    if (!name || g_atlasCount >= FFX_MAX_ATLASES)
        return 0;

    g_atlases[g_atlasCount].atlasId = atlasId;
    strncpy(g_atlases[g_atlasCount].name, name, sizeof(g_atlases[g_atlasCount].name) - 1);
    g_atlases[g_atlasCount].name[sizeof(g_atlases[g_atlasCount].name) - 1] = '\0';
    g_atlasCount++;
    return 1;
}

int FFX_Texture_ResolveAtlas(int atlasId)
{
    for (int i = 0; i < g_atlasCount; i++) {
        if (g_atlases[i].atlasId == atlasId)
            return i;
    }
    return -1;
}

void *FFX_Texture_GetAtlasSRV(int atlasId)
{
    for (int i = 0; i < g_atlasCount; i++) {
        if (g_atlases[i].atlasId == atlasId)
            return FFX_Texture_GetSRV(g_atlases[i].name);
    }
    return NULL;
}
