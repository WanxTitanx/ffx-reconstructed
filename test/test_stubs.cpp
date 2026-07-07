#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

extern "C" uint16_t FFX_Save_Crc16Ccitt(const uint8_t* data, size_t len) {
    if (!data || len == 0) return 0xFFFF;
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < len; i++) {
        crc ^= (uint16_t)data[i] << 8;
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000)
                crc = (uint16_t)((crc << 1) ^ 0x1021);
            else
                crc = (uint16_t)(crc << 1);
        }
    }
    return crc;
}

extern "C" void Phyre_PClassDescriptor_Init(void* desc) {
    if (desc) {
        memset(desc, 0, 0x94);
    }
}

extern "C" int FFX_Battle_ComputeEffectiveHp(int base, int debuff, int shield) {
    int effective = base - debuff + shield;
    if (effective < 0) effective = 0;
    return effective;
}

extern "C" int Phyre_PString_Append(void *this_ptr, const char *text) {
    if (!this_ptr || !text) return 0;
    char *str = *(char**)this_ptr;
    if (!str) return 0;
    int curLen = (int)strlen(str);
    int addLen = (int)strlen(text);
    memcpy(str + curLen, text, addLen + 1);
    return curLen + addLen;
}

extern "C" int Phyre_String_Compare(void *this_ptr, const char *other) {
    if (!this_ptr || !other) return -1;
    const char *str = *(const char**)this_ptr;
    if (!str) return -1;
    return strcmp(str, other);
}

extern "C" int Phyre_String_Find(void *this_ptr, const char *sub, unsigned int start) {
    if (!this_ptr || !sub) return -1;
    const char *str = *(const char**)this_ptr;
    if (!str) return -1;
    int len = (int)strlen(str);
    if ((int)start >= len) return -1;
    const char *found = strstr(str + start, sub);
    if (!found) return -1;
    return (int)(found - str);
}
