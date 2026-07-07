#include <stdint.h>
#include <string.h>

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
