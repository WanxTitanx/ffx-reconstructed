#pragma once
#include <stdint.h>

#define FFX_MAX_TEXTURES 256
#define FFX_MAX_ATLASES  FFX_MAX_TEXTURES

typedef struct FFXTexture {
    void *srv;           // ID3D11ShaderResourceView*
    int width, height;
    int channels;
    char name[64];
} FFXTexture;

int  FFX_Texture_Init(void);
void FFX_Texture_Shutdown(void);
int  FFX_Texture_Load(const char *filePath, const char *name);
int  FFX_Texture_LoadPhyre(const char *filePath, const char *name);
int  FFX_Texture_CreateFromMemory(const unsigned char *data, int w, int h, int channels, const char *name);
void *FFX_Texture_GetSRV(const char *name); // returns ID3D11ShaderResourceView*

// ---- Atlas registry -------------------------------------------------------
// Maps an atlas ID to a named texture slot so the menu drawing functions
// can look up the correct ID3D11ShaderResourceView by logical atlas id.
int   FFX_Texture_RegisterAtlas(int atlasId, const char *name);
int   FFX_Texture_ResolveAtlas(int atlasId);           // returns slot index or -1
void *FFX_Texture_GetAtlasSRV(int atlasId);            // returns SRV or NULL
