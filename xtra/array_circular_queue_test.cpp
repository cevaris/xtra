//
// Created by Adam Cardenas on 12/17/16.
//

#include <queue>
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

TEST(ArrayCircularQueueTest, ShouldBeCorrectSize) {
    int result;
    const int COUNT = 3;

    xtra::ArrayCircularQueue<int, COUNT> s;
    for (int i = 0; i < COUNT; i++) {
        EXPECT_EQ(s.size(), i);
        s.add(i);
    }
}


TEST(ArrayCircularQueueTest, ShouldClear) {
    const int COUNT = 3;

    xtra::ArrayCircularQueue<int, COUNT> s;
    for (int i = 0; i < COUNT; i++) {
        s.add(i);
    }

    EXPECT_FALSE(s.is_empty());
    s.clear();
    EXPECT_TRUE(s.is_empty());
}

TEST(ArrayCircularQueueTest, ShouldPeek) {
    const int COUNT = 3;

    xtra::ArrayCircularQueue<int, COUNT> s;
    for (int i = 0; i < COUNT; i++) {
        s.add(i);
    }

    for (int i = 0; i < COUNT; i++) {
        int j;
        s.peek(j);
        // should always return first element
        EXPECT_EQ(j, 0);
    }
}

TEST(ArrayCircularQueueTest, ShouldCycle) {
    int result;

    xtra::ArrayCircularQueue<int, 3> s;
    for (int i = 0; i < 3; i++) {
        s.add(i);
    }

    // current state: [0, 1, 2]
    s.pop(result);
    EXPECT_EQ(result, 0);
    s.pop(result);
    EXPECT_EQ(result, 1);

    // current state: [2]
    s.add(3);
    s.add(4);

    // current state: [2, 3, 4]
    s.pop(result);
    EXPECT_EQ(result, 2);
    s.pop(result);
    EXPECT_EQ(result, 3);
    s.pop(result);
    EXPECT_EQ(result, 4);


    // test cycles multiple times
    xtra::ArrayCircularQueue<int, 3> x;
    for (int i = 0; i < 5; i++) {
        // insert data
        for (int j = 0; j < 3; j++) {
            x.add(j);
        }
        // pop data in FIFO order
        for (int j = 0; j < 3; j++) {
            x.pop(result);
            EXPECT_EQ(result, j);
        }
        EXPECT_TRUE(x.is_empty());
    }
}

