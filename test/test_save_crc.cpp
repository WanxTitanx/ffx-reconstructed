#include <gtest/gtest.h>
#include <stdint.h>
#include <cstring>

extern "C" uint16_t FFX_Save_Crc16Ccitt(const uint8_t* data, size_t len);

TEST(SaveCrc, KnownVector_AllZeros_1024) {
    uint8_t buf[1024];
    std::memset(buf, 0, sizeof(buf));
    EXPECT_EQ(FFX_Save_Crc16Ccitt(buf, sizeof(buf)), 0xB76F);
}

TEST(SaveCrc, KnownVector_Sequential256) {
    uint8_t buf[256];
    for (int i = 0; i < 256; i++) buf[i] = (uint8_t)i;
    EXPECT_EQ(FFX_Save_Crc16Ccitt(buf, sizeof(buf)), 0x3FBD);
}

TEST(SaveCrc, KnownVector_CheckStringValue) {
    const char* str = "123456789";
    EXPECT_EQ(FFX_Save_Crc16Ccitt((const uint8_t*)str, 9), 0x29B1);
}
