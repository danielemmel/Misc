//
// Created by Daniel on 02.05.2021.
//

#include <gtest/gtest.h>
#include <vector>
#include "../src/heap/maxHeapInt.h"
#include <limits>

using Vec = std::vector<int>;

TEST(IntHeapTest, TestInsertEmpty) {
    maxHeap heap;
    bool res = heap.insert(Vec{});
    EXPECT_TRUE(res);
    EXPECT_TRUE(heap.extract().empty());
}

TEST(IntHeapTest, TestInsertExistant) {
    maxHeap heap;
    bool res = heap.insert(Vec{1, 2, 3, 4});
    EXPECT_TRUE(res);
    res = heap.insert(Vec{1, 2, 3, 4});
    EXPECT_FALSE(res);
    res = heap.insert(Vec{3, 4, 1, 2});
    EXPECT_FALSE(res);
    auto vec = Vec{1, 2, 3, 4};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(IntHeapTest, TestInsertInitial) {
    maxHeap heap;
    bool res = heap.insert(Vec{5, 6, 5});
    EXPECT_TRUE(res);
    auto vec = Vec{5, 6, 5};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(IntHeapTest, TestInsertSumOverflow) {
    maxHeap heap;
    ASSERT_FALSE(heap.insert(Vec{std::numeric_limits<int>::max(), 1}));
}

TEST(IntHeapTest, TestInsertSumUnderflow) {
    maxHeap heap;
    ASSERT_FALSE(heap.insert(Vec{std::numeric_limits<int>::min(), -1}));
}

TEST(IntHeapTest, TestExtractEmpty) {
    maxHeap heap;
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(IntHeapTest, TestExtractLast) {
    maxHeap heap;
    heap.insert(Vec{42});
    auto v = heap.extract();
    ASSERT_EQ(v, Vec{42});
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(IntHeapTest, TestDeleteExisting) {
    maxHeap heap;
    heap.insert(Vec{42});
    ASSERT_TRUE(heap.remove(Vec{42}));
}

TEST(IntHeapTest, TestDeleteNonExisting) {
    maxHeap heap;
    heap.insert(Vec{42});
    ASSERT_FALSE(heap.remove(Vec{43}));
}

TEST(IntHeapTest, TestDeleteOverflowVector) {
    maxHeap heap;
    heap.insert(Vec{42});
    ASSERT_FALSE(heap.remove(Vec{std::numeric_limits<int>::max(), 1}));
}

TEST(IntHeapTest, TestDeleteUnderflowVector) {
    maxHeap heap;
    heap.insert(Vec{42});
    ASSERT_FALSE(heap.remove(Vec{std::numeric_limits<int>::min(), -1}));
}

TEST(IntHeapTest, TestDeleteSameSum) {
    maxHeap heap;
    heap.insert(Vec{42});
    heap.insert(Vec{20, 22});
    ASSERT_TRUE(heap.remove(Vec{20, 22}));
    ASSERT_EQ(heap.extract(), Vec{42});
}