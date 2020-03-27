#include "LinkListStack.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(Suite1, Test1) {
  Stack<int> list;
  for (int i = 0; i < 5;i++) {
    list.Push(i + 1);
  }
  EXPECT_EQ(list.size(), 5);
  EXPECT_EQ(list.Peek(), 5);
  EXPECT_EQ(list.Pop(), 5);
  list.clear();
  EXPECT_EQ(list.size(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
