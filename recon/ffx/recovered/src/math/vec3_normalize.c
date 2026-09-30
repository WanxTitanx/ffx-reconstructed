#include "ffx_abi.h"

/* MSVC's x86 sqrt intrinsic calls the existing _CIsqrt import thunk.
   This declaration avoids an undeclared system-header dependency. */
double FFX_CDECL sqrt(double value);
#pragma intrinsic(sqrt)

/* Original entry 0x0093d3d0, 102 bytes. The binary32 temporaries are observable:
   length and its reciprocal are rounded before the component stores.
   Zero or unordered length leaves the entire destination untouched.
   Exact in-place normalization is supported; arbitrary partial overlap is not
   part of the recovered contract. No assumption of restrict/independent arrays. */
void FFX_CDECL FFX_Math_Vec3Normalize(FfxFloat4 *destination, const FfxFloat4 *source)
{
    float length = sqrt(source->x * source->x + source->y * source->y + source->z * source->z);
    if (length > 0.0) {
        float reciprocal = 1.0 / length;
        destination->x = source->x * reciprocal;
        destination->y = reciprocal * source->y;
        destination->z = reciprocal * source->z;
        destination->w = source->w;
    }
}
