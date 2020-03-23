#include <iostream>
#include "SequetialList.h"
#include "gtest/gtest.h"


TEST(Suite1, Test1)
{
    int N = 8;
    SequentialList<int> list(N);
    SequentialList<int> list1(N);

    //test insert
    for (int i = 0; i < N; i++) {
        list.insert(0, i + 1);
    }
    
    for (int i = 0;i < N; i++) {
        list1.insert(i, i + 1);
    }
    
    int n = 0;
    for (int d : list) {
        n++;
    }
    EXPECT_EQ(n, N);
    n = 0;
    for (int d : list1) {
        n++;
    }
    EXPECT_EQ(n, N);

    //test get
    EXPECT_EQ(list.get(0), 8);
    EXPECT_EQ(list.get(1), 7);
    //test set
    EXPECT_EQ(list.set(0, 5), true);
    EXPECT_EQ(list.get(0), 5);

    //test remove
    EXPECT_EQ(list.remove(2), 6);
    //test removeall
    for (int d : list) {
        std::cout << d << std::endl;
    }
    //std::cout << list.removeAll(5) << std::endl;
    EXPECT_EQ(list.removeAll(1), 1);

}


int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}