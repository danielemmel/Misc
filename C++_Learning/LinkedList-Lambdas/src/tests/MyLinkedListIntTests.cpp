#include <gtest/gtest.h>
#include "../MyLinkedListInt.h"

TEST(MyLinkedListIntTest, TestInitial) {
	MyLinkedListInt l{};
	EXPECT_EQ(l.length, 0);
	EXPECT_EQ(l.start.get(), l.end);
	EXPECT_EQ(l.start, nullptr);
}

TEST(MyLinkedListIntTest, TestInsertAndPointers) {
	MyLinkedListInt l{};
	l.insert(1);
	l.insert(2);
	l.insert(3);
	EXPECT_EQ(l.length, 3);
	EXPECT_EQ(l.start -> value, 1);
	EXPECT_EQ(l.end -> value, 3);
}

TEST(MyLinkedListIntTest, TestInsertRemove) {
	MyLinkedListInt l{};
	l.insert(1);
	l.insert(2);
	l.insert(3);
	bool res = l.remove(3);
	EXPECT_TRUE(res);
	EXPECT_EQ(l.length, 2);
	EXPECT_EQ(l.start->value, 1);
	EXPECT_EQ(l.end->value, 2);

	res = l.remove(42);
	EXPECT_FALSE(res);
	EXPECT_EQ(l.length, 2);
	EXPECT_EQ(l.start->value, 1);
	EXPECT_EQ(l.end->value, 2);

	l.remove(1);
	EXPECT_EQ(l.length, 1);
	EXPECT_EQ(l.start->value, 2);
	EXPECT_EQ(l.end->value, 2);
}

TEST(MyLinkedListIntTest, TestInsertIncludes) {
	MyLinkedListInt l{};
	l.insert(1);
	l.insert(2);
	
	EXPECT_TRUE(l.includes(1));
	EXPECT_TRUE(l.includes(2));
	EXPECT_FALSE(l.includes(3));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}