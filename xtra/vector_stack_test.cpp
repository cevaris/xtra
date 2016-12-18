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
    std::vector<int> test_values = {1, 2, 3};

    xtra::VectorStack<int> s(test_values);
    EXPECT_FALSE(s.empty());
}

TEST(VectorStackTest, PopWithEmpty) {
    xtra::VectorStack<int> s;
    EXPECT_THROW(s.pop(), xtra::EmptyStackException);
}



