#pragma once
#include <windows.h>
#include <stdint.h>

#define FFX_MAX_QUADS 2048
#define FFX_VERTICES_PER_QUAD 4
#define FFX_INDICES_PER_QUAD 6
#define FFX_MAX_VERTICES (FFX_MAX_QUADS * FFX_VERTICES_PER_QUAD)
#define FFX_MAX_INDICES (FFX_MAX_QUADS * FFX_INDICES_PER_QUAD)

typedef struct FFXVertex2D {
    float x, y, z;
    float u, v;
    uint32_t color;
} FFXVertex2D;

int  FFX_RenderQueue_Init();
void FFX_RenderQueue_Shutdown();
void FFX_RenderQueue_PushRect(float x, float y, float w, float h, uint32_t colorTop, uint32_t colorBot);
void FFX_RenderQueue_PushQuad(float x, float y, float w, float h, float u0, float v0, float u1, float v1, uint32_t c0, uint32_t c1, uint32_t c2, uint32_t c3);
void FFX_RenderQueue_PushQuadTex(float x, float y, float w, float h, float u0, float v0, float u1, float v1, uint32_t c0, uint32_t c1, uint32_t c2, uint32_t c3, void *srv);
void FFX_RenderQueue_Flush();
void FFX_RenderQueue_Resize(int width, int height);
void FFX_RenderQueue_Clear();
void FFX_RenderQueue_UpdatePlasma(float time);
void FFX_RenderQueue_DrawText(const char *text, float x, float y, float scale, uint32_t color, void *fontSRV, int fontCols, int fontRows, int charW, int charH);
