#ifndef FFX_TTFFONT_H
#define FFX_TTFFONT_H

#include <stdint.h>

int FFX_TTFFont_Init(const char *ttfPath, int fontSize);
void FFX_TTFFont_DrawText(const char *text, float x, float y, float scale, uint32_t color, void *fontSRV);
void *FFX_TTFFont_GetAtlasSRV(void);

#endif
