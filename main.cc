#include <iostream>
#include "SequetialList.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1)
{
    int N = 8;
    SequentialList<int> list(N);

    for (int i = 0; i < N; i++) {
        list.insert(i + 1);
    }

    int n = 0;
    for (int d : list) {
        n++;
        EXPECT_EQ(d, n);
    }
    EXPECT_EQ(n, N);

    EXPECT_EQ(list.insert(n + 1), false);
}


int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}