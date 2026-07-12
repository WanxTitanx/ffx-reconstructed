#ifndef FFX_MENU2D_H
#define FFX_MENU2D_H

#include <stdint.h>

static inline float FFX_Menu2D_ScaleX(float v) { return v * 512.0f / 1920.0f; }
static inline float FFX_Menu2D_ScaleY(float v) { return v * 416.0f / 1080.0f; }

static inline float FFX_Menu2D_UnscaleX(float v) { return v * 1920.0f / 512.0f; }
static inline float FFX_Menu2D_UnscaleY(float v) { return v * 1080.0f / 416.0f; }

#define FFX_INTERNAL_W 512
#define FFX_INTERNAL_H 416

#define FFX_COLOR_NORMAL 0x80
#define FFX_COLOR_BRIGHT 0xFF
#define FFX_COLOR_BLACK  0x00

#define FFX_RGBA(r,g,b,a) (((uint32_t)(a)<<24)|((uint32_t)(r)<<16)|((uint32_t)(g)<<8)|(uint32_t)(b))

#define FFX_ATLAS_MESWIN  15872
#define FFX_ATLAS_ICON    15808
#define FFX_ATLAS_FFX_BG  16002
#define FFX_ATLAS_BATTLE  16128

#endif
