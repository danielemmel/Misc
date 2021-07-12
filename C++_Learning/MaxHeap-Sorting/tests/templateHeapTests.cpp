//
// Created by Daniel on 02.05.2021.
//
//
// Created by Daniel on 02.05.2021.
//

#include <gtest/gtest.h>
#include <vector>
#include "../src/heap/maxHeap.h"
#include <limits>

using VecInt = std::vector<int>;
using VecDouble = std::vector<double>;
using VecUnsignedInt = std::vector<unsigned int>;

TEST(TemplateHeapTest, TestInsertEmptyInt) {
    maxHeap<int> heap;
    bool res = heap.insert(VecInt{});
    EXPECT_TRUE(res);
    EXPECT_TRUE(heap.extract().empty());
}

TEST(TemplateHeapTest, TestInsertExistantInt) {
    maxHeap<int> heap;
    bool res = heap.insert(VecInt{1, 2, 3, 4});
    EXPECT_TRUE(res);
    res = heap.insert(VecInt{1, 2, 3, 4});
    EXPECT_FALSE(res);
    res = heap.insert(VecInt{3, 4, 1, 2});
    EXPECT_FALSE(res);
    auto vec = VecInt{1, 2, 3, 4};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(TemplateHeapTest, TestInsertInitialInt) {
    maxHeap<int> heap;
    bool res = heap.insert(VecInt{5, 6, 5});
    EXPECT_TRUE(res);
    auto vec = VecInt{5, 6, 5};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(TemplateHeapTest, TestInsertSumOverflowInt) {
    maxHeap<int> heap;
    ASSERT_FALSE(heap.insert(VecInt{std::numeric_limits<int>::max(), 1}));
}

TEST(TemplateHeapTest, TestInsertSumUnderflowInt) {
    maxHeap<int> heap;
    ASSERT_FALSE(heap.insert(VecInt{std::numeric_limits<int>::min(), -1}));
}

TEST(TemplateHeapTest, TestExtractEmptyInt) {
    maxHeap<int> heap;
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(TemplateHeapTest, TestExtractLastInt) {
    maxHeap<int> heap;
    heap.insert(VecInt{42});
    auto v = heap.extract();
    ASSERT_EQ(v, VecInt{42});
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(TemplateHeapTest, TestDeleteExistingInt) {
    maxHeap<int> heap;
    heap.insert(VecInt{42});
    ASSERT_TRUE(heap.remove(VecInt{42}));
}

TEST(TemplateHeapTest, TestDeleteNonExistingInt) {
    maxHeap<int> heap;
    heap.insert(VecInt{42});
    ASSERT_FALSE(heap.remove(VecInt{43}));
}

TEST(TemplateHeapTest, TestDeleteOverflowVectorInt) {
    maxHeap<int> heap;
    heap.insert(VecInt{42});
    ASSERT_FALSE(heap.remove(VecInt{std::numeric_limits<int>::max(), 1}));
}

TEST(TemplateHeapTest, TestDeleteUnderflowVectorInt) {
    maxHeap<int> heap;
    heap.insert(VecInt{42});
    ASSERT_FALSE(heap.remove(VecInt{std::numeric_limits<int>::min(), -1}));
}

TEST(TemplateHeapTest, TestDeleteSameSumInt) {
    maxHeap<int> heap;
    heap.insert(VecInt{42});
    heap.insert(VecInt{20, 22});
    ASSERT_TRUE(heap.remove(VecInt{20, 22}));
    ASSERT_EQ(heap.extract(), VecInt{42});
}

TEST(TemplateHeapTest, TestInsertEmptyDouble) {
    maxHeap<double> heap;
    bool res = heap.insert(VecDouble{});
    EXPECT_TRUE(res);
    EXPECT_TRUE(heap.extract().empty());
}

TEST(TemplateHeapTest, TestInsertExistantDouble) {
    maxHeap<double> heap;
    bool res = heap.insert(VecDouble{1.2, 2.3, 3.4, 4.5});
    EXPECT_TRUE(res);
    res = heap.insert(VecDouble{1.2, 2.3, 3.4, 4.5});
    EXPECT_FALSE(res);
    res = heap.insert(VecDouble{3.4, 4.5, 1.2, 2.3});
    EXPECT_FALSE(res);
    auto vec = VecDouble{1.2, 2.3, 3.4, 4.5};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(TemplateHeapTest, TestInsertInitialDouble) {
    maxHeap<double> heap;
    bool res = heap.insert(VecDouble{5.5, 6.6, 5.5});
    EXPECT_TRUE(res);
    auto vec = VecDouble{5.5, 6.6, 5.5};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(TemplateHeapTest, TestExtractEmptyDouble) {
    maxHeap<double> heap;
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(TemplateHeapTest, TestExtractLastDouble) {
    maxHeap<double> heap;
    heap.insert(VecDouble{42.42});
    auto v = heap.extract();
    ASSERT_EQ(v, VecDouble{42.42});
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(TemplateHeapTest, TestDeleteExistingDouble) {
    maxHeap<double> heap;
    heap.insert(VecDouble{42.42});
    ASSERT_TRUE(heap.remove(VecDouble{42.42}));
}

TEST(TemplateHeapTest, TestDeleteNonExistingDouble) {
    maxHeap<double> heap;
    heap.insert(VecDouble{42.42});
    ASSERT_FALSE(heap.remove(VecDouble{43.43}));
}

TEST(TemplateHeapTest, TestDeleteSameSumDouble) {
    maxHeap<double> heap;
    heap.insert(VecDouble{42.3});
    heap.insert(VecDouble{20.2, 22.1});
    ASSERT_TRUE(heap.remove(VecDouble{20.2, 22.1}));
    ASSERT_EQ(heap.extract(), VecDouble{42.3});
}


TEST(TemplateHeapTest, TestInsertEmptyUnsignedInt) {
    maxHeap<unsigned int> heap;
    bool res = heap.insert(VecUnsignedInt{});
    EXPECT_TRUE(res);
    EXPECT_TRUE(heap.extract().empty());
}

TEST(TemplateHeapTest, TestInsertExistantUnsignedInt) {
    maxHeap<unsigned int> heap;
    bool res = heap.insert(VecUnsignedInt{1, 2, 3, 4});
    EXPECT_TRUE(res);
    res = heap.insert(VecUnsignedInt{1, 2, 3, 4});
    EXPECT_FALSE(res);
    res = heap.insert(VecUnsignedInt{3, 4, 1, 2});
    EXPECT_FALSE(res);
    auto vec = VecUnsignedInt{1, 2, 3, 4};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(TemplateHeapTest, TestInsertInitialUnsignedInt) {
    maxHeap<unsigned int> heap;
    bool res = heap.insert(VecUnsignedInt{5, 6, 5});
    EXPECT_TRUE(res);
    auto vec = VecUnsignedInt{5, 6, 5};
    EXPECT_EQ(heap.extract(), vec);
}

TEST(TemplateHeapTest, TestExtractEmptyUnsignedInt) {
    maxHeap<unsigned int> heap;
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(TemplateHeapTest, TestExtractLastUnsignedInt) {
    maxHeap<unsigned int> heap;
    heap.insert(VecUnsignedInt{42});
    auto v = heap.extract();
    ASSERT_EQ(v, VecUnsignedInt{42});
    ASSERT_THROW(heap.extract(), std::out_of_range);
}

TEST(TemplateHeapTest, TestDeleteExistingUnsignedInt) {
    maxHeap<unsigned int> heap;
    heap.insert(VecUnsignedInt{42});
    ASSERT_TRUE(heap.remove(VecUnsignedInt{42}));
}

TEST(TemplateHeapTest, TestDeleteNonExistingUnsignedInt) {
    maxHeap<unsigned int> heap;
    heap.insert(VecUnsignedInt{42});
    ASSERT_FALSE(heap.remove(VecUnsignedInt{43}));
}

TEST(TemplateHeapTest, TestDeleteSameSumUnsignedInt) {
    maxHeap<unsigned int> heap;
    heap.insert(VecUnsignedInt{42});
    heap.insert(VecUnsignedInt{20, 22});
    ASSERT_TRUE(heap.remove(VecUnsignedInt{20, 22}));
    ASSERT_EQ(heap.extract(), VecUnsignedInt{42});
}

TEST(TemplateHeapTest, TestInsertSumOverflowUnsignedInt) {
    maxHeap<unsigned int> heap;
    ASSERT_FALSE(heap.insert(VecUnsignedInt{std::numeric_limits<unsigned int>::max(), 1}));
}