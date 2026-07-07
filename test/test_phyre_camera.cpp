#include <gtest/gtest.h>
#include <string.h>
#include "../../src/include/ffx_structs.h"

TEST(PhyrePCamera, StructSizeIs208Bytes) {
    EXPECT_EQ(sizeof(PhyrePCamera), 208u);
}

TEST(PhyrePCamera, ViewMatrixStartsAtOffset4) {
    PhyrePCamera cam;
    memset(&cam, 0, sizeof(cam));
    cam.mViewMatrix[0] = 1.0f;
    cam.mViewMatrix[11] = 1.0f;
    unsigned char *bytes = (unsigned char*)&cam;
    EXPECT_EQ(bytes[4 + 0 * 4], 0x00);
    EXPECT_EQ(bytes[4 + 11 * 4 + 3], 0x3F);
}

TEST(PhyrePCamera, ProjectionMatrixStartsAtOffset0x34) {
    PhyrePCamera cam;
    memset(&cam, 0, sizeof(cam));
    cam.mProjectionMatrix[15] = 1.0f;
    unsigned char *bytes = (unsigned char*)&cam;
    EXPECT_EQ(bytes[0x34 + 15 * 4], 0x00);
    EXPECT_EQ(bytes[0x34 + 15 * 4 + 3], 0x3F);
}

TEST(PhyrePCamera, NearFarPlaneAtExpectedOffsets) {
    PhyrePCamera cam;
    memset(&cam, 0, sizeof(cam));
    cam.m_nearPlane = 0.1f;
    cam.m_farPlane = 10000.0f;
    EXPECT_FLOAT_EQ(cam.m_nearPlane, 0.1f);
    EXPECT_FLOAT_EQ(cam.m_farPlane, 10000.0f);
}

TEST(PhyrePCamera, FlagsAtOffset0xB4) {
    PhyrePCamera cam;
    memset(&cam, 0, sizeof(cam));
    cam.m_flags = 0x42;
    unsigned char *bytes = (unsigned char*)&cam;
    EXPECT_EQ(bytes[0xB4], 0x42);
}

TEST(PhyrePCamera, ViewProjectionAfterProjection) {
    PhyrePCamera cam;
    memset(&cam, 0, sizeof(cam));
    cam.mProjectionMatrix[0] = 2.0f;
    cam.mViewProjectionMatrix[0] = 4.0f;
    EXPECT_FLOAT_EQ(cam.mProjectionMatrix[0], 2.0f);
    EXPECT_FLOAT_EQ(cam.mViewProjectionMatrix[0], 4.0f);
    EXPECT_EQ((size_t)&cam.mViewProjectionMatrix[0] - (size_t)&cam.mProjectionMatrix[0], 64u);
}