#include <gtest/gtest.h>
#include <stdint.h>
#include <cstring>

extern "C" void Phyre_PClassDescriptor_Init(void* desc);

struct PhyrePClassDescriptorTest {
    uint8_t raw[0x94];
};

TEST(PhyrePClassDescriptor, InitZerosAllFields) {
    PhyrePClassDescriptorTest desc;
    std::memset(desc.raw, 0xFF, sizeof(desc.raw));

    Phyre_PClassDescriptor_Init(&desc);

    for (size_t i = 0; i < sizeof(desc.raw); i++) {
        EXPECT_EQ(desc.raw[i], 0) << "byte " << i << " nao foi zerado";
    }
}

TEST(PhyrePClassDescriptor, InitIsIdempotent) {
    PhyrePClassDescriptorTest desc1, desc2;
    std::memset(desc1.raw, 0xAA, sizeof(desc1.raw));
    std::memset(desc2.raw, 0xBB, sizeof(desc2.raw));

    Phyre_PClassDescriptor_Init(&desc1);
    Phyre_PClassDescriptor_Init(&desc2);

    EXPECT_EQ(std::memcmp(desc1.raw, desc2.raw, sizeof(desc1.raw)), 0);
}
