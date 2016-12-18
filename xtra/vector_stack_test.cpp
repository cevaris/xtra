//
// Created by Adam Cardenas on 12/17/16.
//

#include "gtest/gtest.h"
#include "xtra.h"


TEST(VectorStackTest, ShouldBeEmpty) {
    xtra::VectorStack<int> s;
    EXPECT_TRUE(s.empty());
}

TEST(VectorStackTest, InitWithVector) {
    std::vector<int> test_data = {1, 2, 3};

    xtra::VectorStack<int> s(test_data);
    EXPECT_FALSE(s.empty());
}

TEST(VectorStackTest, InitWithEmptyVector) {
    std::vector<int> test_data;

    xtra::VectorStack<int> s(test_data);
    EXPECT_TRUE(s.empty());
}

TEST(VectorStackTest, SizeCorrectly) {
    std::vector<int> test_data = {1, 2, 3};

    xtra::VectorStack<int> s(test_data);
    EXPECT_EQ(s.size(), test_data.size());
}


TEST(VectorStackTest, HandleEmptyIterator) {
    xtra::VectorStack<int> s;
    EXPECT_THROW(s.peek(), xtra::EmptyStackException);
    EXPECT_THROW(s.pop(), xtra::EmptyStackException);

    int does_not_exist = 1;
    EXPECT_EQ(s.search(does_not_exist), -1);
}

TEST(VectorStackTest, PeekCorrectly) {
    std::vector<int> test_data = {1, 2, 3};
    xtra::VectorStack<int> s(test_data);

    EXPECT_EQ(s.peek(), 3);
    // test peek does not pop head element
    EXPECT_EQ(s.peek(), 3);
}

TEST(VectorStackTest, PopCorrectly) {
    std::vector<int> test_data = {1, 2, 3};
    xtra::VectorStack<int> s(test_data);

    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
    EXPECT_THROW(s.pop(), xtra::EmptyStackException);
}

TEST(VectorStackTest, SearchCorrectly) {
    std::vector<int> test_data = {1, 2, 3};
    xtra::VectorStack<int> s(test_data);

    // search result is 1-based
    EXPECT_EQ(s.search(1), 3);
    EXPECT_EQ(s.search(2), 2);
    EXPECT_EQ(s.search(3), 1);

    // not found
    EXPECT_EQ(s.search(4), -1);
}

TEST(VectorStackTest, PushPeekSearchPopCorrectly) {
    xtra::VectorStack<int> s;

    EXPECT_EQ(s.push(1), 1);
    EXPECT_EQ(s.push(2), 2);

    EXPECT_EQ(s.peek(), 2);
    EXPECT_EQ(s.peek(), 2);

    EXPECT_EQ(s.search(1), 2);

    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
    EXPECT_THROW(s.pop(), xtra::EmptyStackException);
}



