#include "SequentialListStack.h"
#include "SequetialList.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  Stack<int> list;
  for (int i = 5; i > 0;i--) {
    list.Push(i);
  }

  EXPECT_EQ(list.Peek(), 1);
  EXPECT_EQ(list.Pop(), 1);
  list.clear();
  EXPECT_TRUE(list.IsEmpty());

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
