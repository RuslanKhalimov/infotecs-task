#include <gtest/gtest.h>

#include "SpecialPrimes.h"

TEST(SuperPrimes, limited_test) {
    SuperPrimes container(100);
    std::vector<uint32_t> expected {3, 5, 11, 17, 31, 41, 59, 67, 83};
    EXPECT_EQ(container.size(), expected.size());
    for (int i = 0; i < container.size(); ++i) {
        EXPECT_EQ(container[i], expected[i]);
    }
}

TEST(SuperPrimes, unlimited_test_Test) {
    SuperPrimes container;
    EXPECT_EQ(container[10], 127);
}

TEST(SophieGermainPrimes, limited_test) {
    SophieGermainPrimes container(100);
    std::vector<uint32_t> expected {2, 3, 5, 11, 23, 29, 41, 53, 83, 89};
    EXPECT_EQ(container.size(), expected.size());
    for (int i = 0; i < container.size(); ++i) {
        EXPECT_EQ(container[i], expected[i]);
    }
}

TEST(SophieGeraminPrimes, unlimited_test_Test) {
    SophieGermainPrimes container;
    EXPECT_EQ(container[10], 113);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
