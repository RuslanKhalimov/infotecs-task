#include <gtest/gtest.h>
#include "Primes.h"

TEST(Primes, unlimited_empty) {
    Primes container;
    EXPECT_EQ(container.size(), 0);
}

TEST(Primes, limited_empty) {
    Primes container(1);
    EXPECT_EQ(container.size(), 0);
}

TEST(Primes, limited_container_size) {
    Primes container(10);
    EXPECT_EQ(container.size(), 4);
}

TEST(Primes, limited_container_values) {
    Primes container(10);
    EXPECT_EQ(container[0], 2);
    EXPECT_EQ(container[1], 3);
    EXPECT_EQ(container[2], 5);
    EXPECT_EQ(container[3], 7);
}

TEST(Primes, index_out_of_range) {
    Primes container(10);
    EXPECT_THROW(container[4], std::out_of_range);
}

TEST(Primes, unlimited_container_get_by_index) {
    Primes container;
    EXPECT_EQ(container[0], 2);
}

TEST(PrimesIterator, empty) {
    Primes container;
    EXPECT_EQ(container.begin(), container.end());
}

TEST(PrimesIterator, member_access) {
    Primes container(10);
    EXPECT_EQ(*container.begin(), 2);
}

TEST(PrimesIterator, limited_container_incrementing) {
    Primes container(10);
    std::vector<uint32_t> expected_values{2, 3, 5, 7};
    std::vector<uint32_t> container_values;
    for (Primes::Iterator x = container.begin(); x != container.end(); ++x) {
        container_values.push_back(*x);
    }
    EXPECT_EQ(container_values, expected_values);
}

TEST(PrimesIterator, unlimited_container_incrementing) {
    Primes container;
    EXPECT_EQ(container.size(), 0);
    container.begin()++;
    EXPECT_GT(container.size(), 0);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
