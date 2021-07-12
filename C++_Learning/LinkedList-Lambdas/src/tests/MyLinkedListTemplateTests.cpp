#include <gtest/gtest.h>
#include "../MyLinkedList.h"
#include <string>

TEST(MyLinkedListTemplateTest, TestInitial) {
	MyLinkedList<int> l{};
	EXPECT_EQ(l.length, 0);
	EXPECT_EQ(l.start.get(), l.end);
	EXPECT_EQ(l.start, nullptr);
}

TEST(MyLinkedListTemplateTest, TestInsertAndPointersInt) {
	MyLinkedList<int> l{};
	l.insert(1);
	l.insert(2);
	l.insert(3);
	EXPECT_EQ(l.length, 3);
	EXPECT_EQ(l.start->value, 1);
	EXPECT_EQ(l.end->value, 3);
}

TEST(MyLinkedListTemplateTest, TestInsertRemoveInt) {
	MyLinkedList<int> l{};
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

TEST(MyLinkedListTemplateTest, TestInsertIncludesInt) {
	MyLinkedList<int> l{};
	l.insert(1);
	l.insert(2);

	EXPECT_TRUE(l.includes(1));
	EXPECT_TRUE(l.includes(2));
	EXPECT_FALSE(l.includes(3));
}

TEST(MyLinkedListTemplateTest, TestInsertAndPointersDouble) {
	MyLinkedList<double> l{};
	l.insert(1.2);
	l.insert(2.3);
	l.insert(3.4);
	EXPECT_EQ(l.length, 3);
	EXPECT_EQ(l.start->value, 1.2);
	EXPECT_EQ(l.end->value, 3.4);
}


TEST(MyLinkedListTemplateTest, TestInsertRemoveDouble) {
	MyLinkedList<double> l{};
	l.insert(1.2);
	l.insert(2.3);
	l.insert(3.4);
	bool res = l.remove(3.4);
	EXPECT_TRUE(res);
	EXPECT_EQ(l.length, 2);
	EXPECT_EQ(l.start->value, 1.2);
	EXPECT_EQ(l.end->value, 2.3);

	res = l.remove(42.42);
	EXPECT_FALSE(res);
	EXPECT_EQ(l.length, 2);
	EXPECT_EQ(l.start->value, 1.2);
	EXPECT_EQ(l.end->value, 2.3);

	l.remove(1.2);
	EXPECT_EQ(l.length, 1);
	EXPECT_EQ(l.start->value, 2.3);
	EXPECT_EQ(l.end->value, 2.3);
}

TEST(MyLinkedListTemplateTest, TestInsertIncludesDouble) {
	MyLinkedList<int> l{};
	l.insert(1.2);
	l.insert(2.3);

	EXPECT_TRUE(l.includes(1.2));
	EXPECT_TRUE(l.includes(2.3));
	EXPECT_FALSE(l.includes(3.333));
}

TEST(MyLinkedListTemplateTest, TestInsertAndPointersString) {
	MyLinkedList<std::string> l{};
	l.insert("Hello");
	l.insert("World");
	l.insert("Test");
	EXPECT_EQ(l.length, 3);
	EXPECT_EQ(l.start->value, "Hello");
	EXPECT_EQ(l.end->value, "Test");
}


TEST(MyLinkedListTemplateTest, TestInsertRemoveString) {
	MyLinkedList<std::string> l{};
	l.insert("Hello");
	l.insert("World");
	l.insert("Test");
	bool res = l.remove("Test");
	EXPECT_TRUE(res);
	EXPECT_EQ(l.length, 2);
	EXPECT_EQ(l.start->value, "Hello");
	EXPECT_EQ(l.end->value, "World");

	res = l.remove("Foobar");
	EXPECT_FALSE(res);
	EXPECT_EQ(l.length, 2);
	EXPECT_EQ(l.start->value, "Hello");
	EXPECT_EQ(l.end->value, "World");

	l.remove("Hello");
	EXPECT_EQ(l.length, 1);
	EXPECT_EQ(l.start->value, "World");
	EXPECT_EQ(l.end->value, "World");
}

TEST(MyLinkedListTemplateTest, TestInsertIncludesString) {
	MyLinkedList<std::string> l{};
	l.insert("Hello");
	l.insert("World");

	EXPECT_TRUE(l.includes("Hello"));
	EXPECT_TRUE(l.includes("World"));
	EXPECT_FALSE(l.includes("Foobar"));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}