//
// Created by Adam Cardenas on 12/17/16.
//

#include "gtest/gtest.h"
#include "xtra.h"


TEST(ArrayCircularQueueTest, ShouldBeEmpty) {
    xtra::ArrayCircularQueue<int, 10> s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_TRUE(s.is_empty());
}

TEST(ArrayCircularQueueTest, ShouldAddToCapacity) {
    xtra::ArrayCircularQueue<int, 10> s;

    for (int i = 0; i < 10; i++)
        s.add(i);

    // over capacity
    EXPECT_THROW(s.add(11), xtra::IllegalStateException);
}


TEST(ArrayCircularQueueTest, ShouldCycle) {
    xtra::ArrayCircularQueue<int, 3> s;
    for (int i = 0; i < 3; i++) {
        s.add(i);
    }

    // current state: [0, 1, 2]
    EXPECT_EQ(s.pop(), 0);
    EXPECT_EQ(s.pop(), 1);

    // current state: [2]
    s.add(3);
    s.add(4);

    // current state: [2, 3, 4]
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 4);
}

