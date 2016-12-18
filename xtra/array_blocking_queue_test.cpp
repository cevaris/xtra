//
// Created by Adam Cardenas on 12/17/16.
//

#include "gtest/gtest.h"
#include "xtra.h"


TEST(ArrayBlockingQueueTest, ShouldBeEmpty) {
    xtra::ArrayBlockingQueue<int> s;
    EXPECT_TRUE(s.is_empty());
}
