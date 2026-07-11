#pragma once
#include <stdint.h>

typedef struct FFXPhyreTexture {
    int width;
    int height;
    int channels;
    unsigned char *rgba;
    char format[8];
    int bufferStart;
    int mip0Bytes;
    int mipped;
} FFXPhyreTexture;

FFXPhyreTexture *FFX_PhyreTexture_Load(const char *filePath);
void FFX_PhyreTexture_Free(FFXPhyreTexture *tex);
