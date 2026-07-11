#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ffx_phyre_texture.h"
int main(int argc, char *argv[]) {
    if (argc < 3) { printf("Usage: decode_phyre <input.dds.phyre> <output.tga>\n"); return 1; }
    FFXPhyreTexture *tex = FFX_PhyreTexture_Load(argv[1]);
    if (!tex) { printf("Failed to decode %s\n", argv[1]); return 1; }
    printf("Decoded: %dx%d %s (bufferStart=%d, mip0Bytes=%d, mipped=%d)\n",
           tex->width, tex->height, tex->format, tex->bufferStart, tex->mip0Bytes, tex->mipped);
    FILE *f = fopen(argv[2], "wb");
    if (!f) { printf("Cannot open output\n"); return 1; }
    unsigned char tgaHeader[18] = {0};
    tgaHeader[2] = 2;
    tgaHeader[12] = tex->width & 0xFF;
    tgaHeader[13] = (tex->width >> 8) & 0xFF;
    tgaHeader[14] = tex->height & 0xFF;
    tgaHeader[15] = (tex->height >> 8) & 0xFF;
    tgaHeader[16] = 32;
    tgaHeader[17] = 0x20;
    fwrite(tgaHeader, 1, 18, f);
    for (int i = 0; i < tex->width * tex->height; i++) {
        unsigned char *px = &tex->rgba[i * 4];
        unsigned char bgra[4] = { px[2], px[1], px[0], px[3] };
        fwrite(bgra, 1, 4, f);
    }
    fclose(f);
    printf("Saved TGA: %s\n", argv[2]);
    FFX_PhyreTexture_Free(tex);
    return 0;
}
