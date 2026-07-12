#include "ffx_ttf_font.h"
#include "ffx_texture.h"
#include "ffx_renderqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

static stbtt_fontinfo g_font;
static unsigned char *g_fontData = NULL;
static int g_fontLoaded = 0;
static int g_atlasWidth = 1024;
static int g_atlasHeight = 1024;
static int g_fontSize = 32;
static float g_fontScale = 0;
static float g_fontAscent = 0;
static float g_fontDescent = 0;
static float g_fontLineGap = 0;

typedef struct {
    float x0, y0, x1, y1;
    float advance;
    int w, h;
    int xoff, yoff;
} GlyphInfo;

static GlyphInfo g_glyphs[96];

int FFX_TTFFont_Init(const char *ttfPath, int fontSize)
{
    FILE *f = fopen(ttfPath, "rb");
    if (!f) return 0;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    g_fontData = (unsigned char *)malloc(size);
    if (!g_fontData) { fclose(f); return 0; }
    fread(g_fontData, 1, size, f);
    fclose(f);

    if (!stbtt_InitFont(&g_font, g_fontData, stbtt_GetFontOffsetForIndex(g_fontData, 0)))
        return 0;

    g_fontSize = fontSize;
    g_fontScale = stbtt_ScaleForPixelHeight(&g_font, fontSize);
    stbtt_GetFontVMetrics(&g_font, (int *)&g_fontAscent, (int *)&g_fontDescent, (int *)&g_fontLineGap);
    g_fontAscent *= g_fontScale;
    g_fontDescent *= g_fontScale;
    g_fontLineGap *= g_fontScale;

    unsigned char *atlas = (unsigned char *)calloc(g_atlasWidth * g_atlasHeight * 4, 1);
    if (!atlas) return 0;

    FILE *tlog = fopen("ffx_ttf_init.log", "w");
    int x = 0, y = 0, rowH = 0;
    for (int i = 0; i < 96; i++) {
        int c = i + 32;
        int w, h, xoff, yoff;
        unsigned char *bitmap = stbtt_GetCodepointBitmap(&g_font, 0, g_fontScale, c, &w, &h, &xoff, &yoff);
        if (tlog) fprintf(tlog, "[%d] char=%c w=%d h=%d xoff=%d yoff=%d\n", i, c, w, h, xoff, yoff);
        if (w > 0 && h > 0) {
            if (x + w > g_atlasWidth) { x = 0; y += rowH; rowH = 0; }
            if (y + h > g_atlasHeight) break;

            for (int py = 0; py < h; py++) {
                for (int px = 0; px < w; px++) {
                    int idx = ((y + py) * g_atlasWidth + (x + px)) * 4;
                    unsigned char v = bitmap[py * w + px];
                    atlas[idx + 0] = v;
                    atlas[idx + 1] = v;
                    atlas[idx + 2] = v;
                    atlas[idx + 3] = v;
                }
            }

            g_glyphs[i].x0 = (float)x / g_atlasWidth;
            g_glyphs[i].y0 = (float)y / g_atlasHeight;
            g_glyphs[i].x1 = (float)(x + w) / g_atlasWidth;
            g_glyphs[i].y1 = (float)(y + h) / g_atlasHeight;
            g_glyphs[i].w = w;
            g_glyphs[i].h = h;
            g_glyphs[i].xoff = xoff;
            g_glyphs[i].yoff = yoff;
            int advance = 0, lsb = 0;
            stbtt_GetCodepointHMetrics(&g_font, c, &advance, &lsb);
            g_glyphs[i].advance = advance * g_fontScale;

            x += w + 1;
            if (h > rowH) rowH = h;
        } else {
            g_glyphs[i].w = 0;
            g_glyphs[i].h = 0;
            int advance = 0, lsb = 0;
            stbtt_GetCodepointHMetrics(&g_font, c, &advance, &lsb);
            g_glyphs[i].advance = advance * g_fontScale;
        }
        stbtt_FreeBitmap(bitmap, g_fontData);
    }

    if (tlog) { fprintf(tlog, "Atlas size: %dx%d\n", g_atlasWidth, g_atlasHeight); fclose(tlog); }
    int texId = FFX_Texture_CreateFromMemory(atlas, g_atlasWidth, g_atlasHeight, 4, "ttf_atlas");
    free(atlas);
    g_fontLoaded = texId;
    FILE *dlog = fopen("C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\ffx_ttf_debug.log", "w");
    if (dlog) { fprintf(dlog, "TTFFont_Init: texId=%d g_fontLoaded=%d\n", texId, g_fontLoaded); fclose(dlog); }
    return texId;
}

void *FFX_TTFFont_GetAtlasSRV(void)
{
    if (!g_fontLoaded) return NULL;
    return FFX_Texture_GetSRV("ttf_atlas");
}

void FFX_TTFFont_DrawText(const char *text, float x, float y, float scale, uint32_t color, void *fontSRV)
{
    if (!text || !fontSRV || !g_fontLoaded) return;

    float cx = x;
    float cy = y + g_fontAscent * scale;
    int i = 0;
    while (text[i]) {
        unsigned char c = (unsigned char)text[i];
        if (c >= 32 && c < 128) {
            GlyphInfo *g = &g_glyphs[c - 32];
            if (g->w > 0 && g->h > 0) {
                float w = g->w * scale;
                float h = g->h * scale;
                float gx = cx + g->xoff * scale;
                float gy = cy + g->yoff * scale;
                FFX_RenderQueue_PushQuadTex(gx, gy, w, h,
                                           g->x0, g->y0, g->x1, g->y1,
                                           color, color, color, color, fontSRV);
            } else {
                FILE *log = fopen("ffx_ttf.log", "a");
                if (log) { fprintf(log, "[TTF] Missing glyph for char %d (%c)\n", c, c); fclose(log); }
            }
            cx += g->advance * scale;
        }
        i++;
    }
}
