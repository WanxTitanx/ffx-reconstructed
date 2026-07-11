#include "ffx_phyre_texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

static int find_ascii(const unsigned char *bytes, int len, const char *needle, int start, int limit) {
    int nlen = (int)strlen(needle);
    int end = len - nlen;
    if (limit < end) end = limit;
    for (int i = start; i <= end; i++) {
        int ok = 1;
        for (int j = 0; j < nlen; j++) {
            if (bytes[i + j] != (unsigned char)needle[j]) { ok = 0; break; }
        }
        if (ok) return i;
    }
    return -1;
}

static int read_printable_token(const unsigned char *bytes, int len, int start, char *out, int outSize) {
    int off = start;
    while (off < len && bytes[off] == 0) off++;
    int n = 0;
    while (off < len && bytes[off] >= 32 && bytes[off] < 127) {
        if (n < outSize - 1) out[n++] = (char)bytes[off];
        off++;
    }
    out[n] = '\0';
    return n;
}

static int get_mip0_size(int w, int h, const char *fmt) {
    if (strcmp(fmt, "ARGB8") == 0) return w * h * 4;
    if (strcmp(fmt, "L8") == 0) return w * h;
    if (strcmp(fmt, "DXT1") == 0) return ((w + 3) / 4) * ((h + 3) / 4) * 8;
    if (strcmp(fmt, "DXT3") == 0 || strcmp(fmt, "DXT5") == 0) return ((w + 3) / 4) * ((h + 3) / 4) * 16;
    return -1;
}

static unsigned char *decode_argb8(const unsigned char *bytes, int offset, int w, int h) {
    unsigned char *rgba = (unsigned char *)malloc((size_t)w * h * 4);
    if (!rgba) return NULL;
    for (int i = 0; i < w * h; i++) {
        int src = offset + i * 4;
        int dst = i * 4;
        rgba[dst + 0] = bytes[src + 2];
        rgba[dst + 1] = bytes[src + 1];
        rgba[dst + 2] = bytes[src + 0];
        rgba[dst + 3] = bytes[src + 3];
    }
    return rgba;
}

static unsigned char *decode_l8(const unsigned char *bytes, int offset, int w, int h) {
    unsigned char *rgba = (unsigned char *)malloc((size_t)w * h * 4);
    if (!rgba) return NULL;
    for (int i = 0; i < w * h; i++) {
        unsigned char v = bytes[offset + i];
        rgba[i * 4 + 0] = v;
        rgba[i * 4 + 1] = v;
        rgba[i * 4 + 2] = v;
        rgba[i * 4 + 3] = 255;
    }
    return rgba;
}

static void decompress_dxt_color_block(const unsigned char *block, unsigned char *out) {
    unsigned short c0 = block[0] | (block[1] << 8);
    unsigned short c1 = block[2] | (block[3] << 8);
    unsigned char r[4], g[4], b[4];

    r[0] = ((c0 >> 11) & 0x1F) << 3;
    g[0] = ((c0 >> 5) & 0x3F) << 2;
    b[0] = (c0 & 0x1F) << 3;

    r[1] = ((c1 >> 11) & 0x1F) << 3;
    g[1] = ((c1 >> 5) & 0x3F) << 2;
    b[1] = (c1 & 0x1F) << 3;

    if (c0 > c1) {
        r[2] = (2 * r[0] + r[1]) / 3; g[2] = (2 * g[0] + g[1]) / 3; b[2] = (2 * b[0] + b[1]) / 3;
        r[3] = (r[0] + 2 * r[1]) / 3; g[3] = (g[0] + 2 * g[1]) / 3; b[3] = (b[0] + 2 * b[1]) / 3;
    } else {
        r[2] = (r[0] + r[1]) / 2; g[2] = (g[0] + g[1]) / 2; b[2] = (b[0] + b[1]) / 2;
        r[3] = 0; g[3] = 0; b[3] = 0;
    }

    unsigned int indices = block[4] | (block[5] << 8) | (block[6] << 16) | (block[7] << 24);
    for (int i = 0; i < 16; i++) {
        int idx = (indices >> (i * 2)) & 3;
        int x = i % 4;
        int y = i / 4;
        int dst = (y * 4 + x) * 4;
        out[dst + 0] = r[idx];
        out[dst + 1] = g[idx];
        out[dst + 2] = b[idx];
        out[dst + 3] = 255;
    }
}

static unsigned char *decode_dxt1(const unsigned char *bytes, int offset, int w, int h) {
    unsigned char *rgba = (unsigned char *)calloc((size_t)w * h * 4, 1);
    if (!rgba) return NULL;
    int blocksX = (w + 3) / 4;
    int blocksY = (h + 3) / 4;
    for (int by = 0; by < blocksY; by++) {
        for (int bx = 0; bx < blocksX; bx++) {
            const unsigned char *block = bytes + offset + (by * blocksX + bx) * 8;
            int px = bx * 4;
            int py = by * 4;
            unsigned char blockOut[4 * 4 * 4];
            decompress_dxt_color_block(block, blockOut);
            for (int y = 0; y < 4 && py + y < h; y++) {
                for (int x = 0; x < 4 && px + x < w; x++) {
                    int dst = ((py + y) * w + (px + x)) * 4;
                    int src = (y * 4 + x) * 4;
                    rgba[dst + 0] = blockOut[src + 0];
                    rgba[dst + 1] = blockOut[src + 1];
                    rgba[dst + 2] = blockOut[src + 2];
                    rgba[dst + 3] = blockOut[src + 3];
                }
            }
        }
    }
    return rgba;
}

static unsigned char *decode_dxt5(const unsigned char *bytes, int offset, int w, int h) {
    unsigned char *rgba = (unsigned char *)calloc((size_t)w * h * 4, 1);
    if (!rgba) return NULL;
    int blocksX = (w + 3) / 4;
    int blocksY = (h + 3) / 4;
    for (int by = 0; by < blocksY; by++) {
        for (int bx = 0; bx < blocksX; bx++) {
            const unsigned char *block = bytes + offset + (by * blocksX + bx) * 16;
            unsigned char a0 = block[0], a1 = block[1];
            unsigned long long aIdx = (unsigned long long)block[2] | ((unsigned long long)block[3] << 8) | ((unsigned long long)block[4] << 16) | ((unsigned long long)block[5] << 24) | ((unsigned long long)block[6] << 32) | ((unsigned long long)block[7] << 40);
            unsigned char alpha[8];
            alpha[0] = a0; alpha[1] = a1;
            if (a0 > a1) {
                alpha[2] = (6 * a0 + a1) / 7; alpha[3] = (5 * a0 + 2 * a1) / 7;
                alpha[4] = (4 * a0 + 3 * a1) / 7; alpha[5] = (3 * a0 + 4 * a1) / 7;
                alpha[6] = (2 * a0 + 5 * a1) / 7; alpha[7] = (a0 + 6 * a1) / 7;
            } else {
                alpha[2] = (4 * a0 + a1) / 5; alpha[3] = (3 * a0 + 2 * a1) / 5;
                alpha[4] = (2 * a0 + 3 * a1) / 5; alpha[5] = (a0 + 4 * a1) / 5;
                alpha[6] = 0; alpha[7] = 255;
            }
            unsigned char colorBlock[8];
            memcpy(colorBlock, block + 8, 8);
            unsigned char blockOut[4 * 4 * 4];
            decompress_dxt_color_block(colorBlock, blockOut);
            int px = bx * 4;
            int py = by * 4;
            for (int y = 0; y < 4 && py + y < h; y++) {
                for (int x = 0; x < 4 && px + x < w; x++) {
                    int dst = ((py + y) * w + (px + x)) * 4;
                    int src = (y * 4 + x) * 4;
                    int aIdx3 = (aIdx >> ((y * 4 + x) * 3)) & 7;
                    rgba[dst + 0] = blockOut[src + 0];
                    rgba[dst + 1] = blockOut[src + 1];
                    rgba[dst + 2] = blockOut[src + 2];
                    rgba[dst + 3] = alpha[aIdx3];
                }
            }
        }
    }
    return rgba;
}

static unsigned char *decode_dxt3(const unsigned char *bytes, int offset, int w, int h) {
    unsigned char *rgba = (unsigned char *)calloc((size_t)w * h * 4, 1);
    if (!rgba) return NULL;
    int blocksX = (w + 3) / 4;
    int blocksY = (h + 3) / 4;
    for (int by = 0; by < blocksY; by++) {
        for (int bx = 0; bx < blocksX; bx++) {
            const unsigned char *block = bytes + offset + (by * blocksX + bx) * 16;
            unsigned char colorBlock[8];
            memcpy(colorBlock, block + 8, 8);
            unsigned char blockOut[4 * 4 * 4];
            decompress_dxt_color_block(colorBlock, blockOut);
            int px = bx * 4;
            int py = by * 4;
            for (int y = 0; y < 4 && py + y < h; y++) {
                for (int x = 0; x < 4 && px + x < w; x++) {
                    int dst = ((py + y) * w + (px + x)) * 4;
                    int src = (y * 4 + x) * 4;
                    int aIdx4 = y * 4 + x;
                    unsigned short a4 = block[aIdx4 / 2];
                    unsigned char a = (aIdx4 % 2 == 0) ? (a4 & 0x0F) : ((a4 >> 4) & 0x0F);
                    a = (a << 4) | a;
                    rgba[dst + 0] = blockOut[src + 0];
                    rgba[dst + 1] = blockOut[src + 1];
                    rgba[dst + 2] = blockOut[src + 2];
                    rgba[dst + 3] = a;
                }
            }
        }
    }
    return rgba;
}

FFXPhyreTexture *FFX_PhyreTexture_Load(const char *filePath) {
    FILE *f = fopen(filePath, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (len < 128) { fclose(f); return NULL; }
    unsigned char *bytes = (unsigned char *)malloc(len);
    if (!bytes) { fclose(f); return NULL; }
    fread(bytes, 1, len, f);
    fclose(f);

    if (memcmp(bytes, "RYHPT", 5) != 0) { free(bytes); return NULL; }

    int pidx = -1;
    char format[8] = {0};
    int scanLimit = len < 16384 ? (int)len : 16384;
    for (int off = 0; off < scanLimit;) {
        int hit = find_ascii(bytes, (int)len, "PTexture2D", off, scanLimit);
        if (hit < 0) break;
        read_printable_token(bytes, (int)len, hit + 10, format, sizeof(format));
        if (strcmp(format, "ARGB8") == 0 || strcmp(format, "DXT1") == 0 ||
            strcmp(format, "DXT3") == 0 || strcmp(format, "DXT5") == 0 ||
            strcmp(format, "L8") == 0) {
            pidx = hit;
            break;
        }
        off = hit + 1;
    }

    if (pidx < 0) { free(bytes); return NULL; }

    int width  = (int)(bytes[pidx - 88] | (bytes[pidx - 87] << 8) | (bytes[pidx - 86] << 16) | (bytes[pidx - 85] << 24));
    int height = (int)(bytes[pidx - 84] | (bytes[pidx - 83] << 8) | (bytes[pidx - 82] << 16) | (bytes[pidx - 81] << 24));
    if (width < 1 || width > 8192 || height < 1 || height > 8192) { free(bytes); return NULL; }

    int formatLen = (int)strlen(format);
    int bufferStart = pidx + 11 + formatLen + 38;
    int mip0Bytes = get_mip0_size(width, height, format);
    if (bufferStart < 0 || bufferStart + mip0Bytes > len) { free(bytes); return NULL; }

    unsigned char *rgba = NULL;
    if (strcmp(format, "ARGB8") == 0) rgba = decode_argb8(bytes, bufferStart, width, height);
    else if (strcmp(format, "L8") == 0) rgba = decode_l8(bytes, bufferStart, width, height);
    else if (strcmp(format, "DXT1") == 0) rgba = decode_dxt1(bytes, bufferStart, width, height);
    else if (strcmp(format, "DXT3") == 0) rgba = decode_dxt3(bytes, bufferStart, width, height);
    else if (strcmp(format, "DXT5") == 0) rgba = decode_dxt5(bytes, bufferStart, width, height);

    free(bytes);
    if (!rgba) return NULL;

    FFXPhyreTexture *tex = (FFXPhyreTexture *)malloc(sizeof(FFXPhyreTexture));
    if (!tex) { free(rgba); return NULL; }
    tex->width = width;
    tex->height = height;
    tex->channels = 4;
    tex->rgba = rgba;
    strncpy(tex->format, format, sizeof(tex->format) - 1);
    tex->format[sizeof(tex->format) - 1] = '\0';
    tex->bufferStart = bufferStart;
    tex->mip0Bytes = mip0Bytes;
    tex->mipped = (len - bufferStart > mip0Bytes + 16) ? 1 : 0;
    return tex;
}

void FFX_PhyreTexture_Free(FFXPhyreTexture *tex) {
    if (!tex) return;
    if (tex->rgba) free(tex->rgba);
    free(tex);
}
