//
// Created by Adam Cardenas on 12/17/16.
//

#include "gtest/gtest.h"
#include "xtra.h"


TEST(ArrayStackTest, ShouldBeEmpty) {
    xtra::ArrayStack<int> s;
    EXPECT_TRUE(s.empty());
}

