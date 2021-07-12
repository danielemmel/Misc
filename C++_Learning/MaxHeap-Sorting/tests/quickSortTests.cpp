//
// Created by Daniel on 02.05.2021.
//
#include <gtest/gtest.h>
#include <vector>
#include "../src/sorting/algorithms.h"
#include <algorithm>

using Vec = std::vector<int>;

TEST(quickSortTest, TestEmpty) {
    Vec v = {};
    auto v_copy = v;
    quickSort(v, true);
    quickSort(v_copy, false);
    ASSERT_TRUE(v.empty());
    ASSERT_TRUE(v_copy.empty());
}

TEST(quickSortTest, TestOneElement) {
    Vec v = {42};
    auto v_copy = v;
    quickSort(v, true);
    quickSort(v_copy, false);
    ASSERT_EQ(v.size(), 1);
    ASSERT_EQ(v_copy.size(), 1);
    EXPECT_EQ(v.front(), 42);
    EXPECT_EQ(v_copy.front(), 42);
}


TEST(quickSortTest, TestDuplicates) {
    Vec v = {5, 3, 4, 2, 1, 42, 42, 9, -33, 4, -20};
    auto v_copy = v;
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    quickSort(v, true);
    quickSort(v_copy, false);

    ASSERT_EQ(v.size(), expected.size());
    ASSERT_EQ(v_copy.size(), expected.size());

    EXPECT_TRUE(std::equal(v.begin(), v.end(), expected.begin()));
    EXPECT_FALSE(std::equal(v_copy.begin(), v_copy.end(), expected.begin()));
}

TEST(quickSortTest, TestSorted) {
    Vec v = {-4, -1, 0, 2, 6, 42, 4200, 5555};
    auto v_copy = v;
    auto expected = v;
    Vec expected_2 = {5555, 4200, 42, 6, 2, 0, -1, -4};
    quickSort(v, true);
    quickSort(v_copy, false);

    ASSERT_EQ(v.size(), expected.size());
    ASSERT_EQ(v_copy.size(), expected_2.size());

    EXPECT_TRUE(std::equal(v.begin(), v.end(), expected.begin()));
    EXPECT_TRUE(std::equal(v_copy.begin(), v_copy.end(), expected_2.begin()));
}

TEST(quickSortTest, TestSortedReverse) {
    Vec v = {4200, 333, 222, 111, 6, 4, 1, -42, -55, -222, -4444};
    auto v_copy = v;
    auto expected = v;
    Vec expected_2 = {-4444, -222, -55, -42, 1, 4, 6, 111, 222, 333, 4200};
    quickSort(v, true);
    quickSort(v_copy, false);

    ASSERT_EQ(v.size(), expected_2.size());
    ASSERT_EQ(v_copy.size(), expected.size());

    EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_2.begin()));
    EXPECT_TRUE(std::equal(v_copy.begin(), v_copy.end(), expected.begin()));
}

TEST(quickSortTest, TestOdd) {
    Vec v;
    for(int i = 0; i < 42; i++) {
        v.push_back(i % 5);
    }
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    quickSort(v, true);

    ASSERT_EQ(v.size(), expected.size());
    EXPECT_TRUE(std::equal(v.begin(), v.end(), expected.begin()));
}

TEST(quickSortTest, TestEven) {
    Vec v;
    for(int i = 0; i < 43; i++) {
        v.push_back(i % 5);
    }
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    quickSort(v, true);

    ASSERT_EQ(v.size(), expected.size());
    EXPECT_TRUE(std::equal(v.begin(), v.end(), expected.begin()));
}
