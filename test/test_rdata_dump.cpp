#include <gtest/gtest.h>
#include "rdata_dump.h"

TEST(RdataDump, SampleSizeIs256Bytes) {
    EXPECT_EQ(sizeof(g_ffx_rdata_sample), 256u);
}

TEST(RdataDump, FirstFourBytesAreZero) {
    EXPECT_EQ(g_ffx_rdata_sample[0], 0);
    EXPECT_EQ(g_ffx_rdata_sample[1], 0);
    EXPECT_EQ(g_ffx_rdata_sample[2], 0);
    EXPECT_EQ(g_ffx_rdata_sample[3], 0);
}

TEST(RdataDump, RdataSizeConstantIsCorrect) {
    EXPECT_EQ(FFX_RDATA_SIZE, 0xFD740u);
}

TEST(RdataDump, RdataStartConstantIsCorrect) {
    EXPECT_EQ(FFX_RDATA_START, 0xB0C8C0u);
}
