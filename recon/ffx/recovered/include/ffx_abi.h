#ifndef FFX_RECOVERED_ABI_H
#define FFX_RECOVERED_ABI_H

#define FFX_CDECL __cdecl

/* Four consecutive binary32 components observed at offsets 0, 4, 8 and 12.
   The fourth component's gameplay meaning is not inferred from this layout. */
typedef struct FfxFloat4 {
    float x;
    float y;
    float z;
    float w;
} FfxFloat4;

typedef char FfxRequirePointer32[sizeof(void *) == 4 ? 1 : -1];
typedef char FfxRequireFloat32[sizeof(float) == 4 ? 1 : -1];
typedef char FfxRequireFloat4Size[sizeof(FfxFloat4) == 16 ? 1 : -1];
#define FFX_OFFSET_OF(type, member) ((unsigned int)&(((type *)0)->member))
typedef char FfxRequireXOffset[FFX_OFFSET_OF(FfxFloat4, x) == 0 ? 1 : -1];
typedef char FfxRequireYOffset[FFX_OFFSET_OF(FfxFloat4, y) == 4 ? 1 : -1];
typedef char FfxRequireZOffset[FFX_OFFSET_OF(FfxFloat4, z) == 8 ? 1 : -1];
typedef char FfxRequireWOffset[FFX_OFFSET_OF(FfxFloat4, w) == 12 ? 1 : -1];

void FFX_CDECL FFX_Math_Vec3Normalize(FfxFloat4 *destination, const FfxFloat4 *source);

#endif
