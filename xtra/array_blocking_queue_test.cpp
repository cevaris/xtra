//
// Created by Adam Cardenas on 12/17/16.
//

#include "gtest/gtest.h"
#include "xtra.h"


TEST(ArrayBlockingQueueTest, ShouldBeEmpty) {
    xtra::ArrayCircularQueue<int, 10> s;
    EXPECT_TRUE(s.is_empty());
}

TEST(ArrayBlockingQueueTest, TestInitCapacity) {
    xtra::ArrayCircularQueue<int, 10> s;
    EXPECT_EQ(s.size(), 0);
}

TEST(ArrayBlockingQueueTest, TestAdd) {
    xtra::ArrayCircularQueue<int, 10> s;
    EXPECT_EQ(s.is_empty(), true);
    EXPECT_EQ(s.add(5), true);
    EXPECT_EQ(s.is_empty(), false);
    EXPECT_EQ(s.size(), 1);
}
