#include <gtest/gtest.h>
#include <string.h>
#include <stdio.h>

extern "C" {
    int Phyre_PString_Append(void *this_ptr, const char *text);
    int Phyre_String_Compare(void *this_ptr, const char *other);
    int Phyre_String_Find(void *this_ptr, const char *sub, unsigned int start);
}

TEST(PhyreString, AppendConcatenates) {
    char buf[256] = "Hello";
    char *p = buf;
    int result = Phyre_PString_Append(&p, " World");
    EXPECT_EQ(result, 11);
    EXPECT_STREQ(buf, "Hello World");
}

TEST(PhyreString, AppendNullSafety) {
    char *p = nullptr;
    EXPECT_EQ(Phyre_PString_Append(&p, "test"), 0);
}

TEST(PhyreString, CompareEqual) {
    char buf[64] = "test";
    char *p = buf;
    EXPECT_EQ(Phyre_String_Compare(&p, "test"), 0);
}

TEST(PhyreString, CompareLess) {
    char buf[64] = "abc";
    char *p = buf;
    EXPECT_LT(Phyre_String_Compare(&p, "xyz"), 0);
}

TEST(PhyreString, CompareGreater) {
    char buf[64] = "xyz";
    char *p = buf;
    EXPECT_GT(Phyre_String_Compare(&p, "abc"), 0);
}

TEST(PhyreString, FindSubstring) {
    char buf[256] = "Hello World";
    char *p = buf;
    int idx = Phyre_String_Find(&p, "World", 0);
    EXPECT_EQ(idx, 6);
}

TEST(PhyreString, FindNotFound) {
    char buf[256] = "Hello World";
    char *p = buf;
    int idx = Phyre_String_Find(&p, "xyz", 0);
    EXPECT_EQ(idx, -1);
}

TEST(PhyreString, FindWithStart) {
    char buf[256] = "ab ab ab";
    char *p = buf;
    int idx = Phyre_String_Find(&p, "ab", 3);
    EXPECT_EQ(idx, 3);
}
