#include "LinkList.h"
#include "gtest/gtest.h"

// test insert
TEST(Suite1, Test1) {
  Link<int> list;
  Link<int> list2;
  const int N = 5;

  for (int i = 0; i < N; i++) {
    list.insert(0, i + 1);
  }
  for (int i = 0; i < N; i++) {
    list2.insert(0, i + 1);
  }

  int n = N;
  for (int d : list) {
    EXPECT_EQ(d, n);
    n--;
  }
  EXPECT_EQ(n, 0);
  n = N;
  for (int d : list2) {
    EXPECT_EQ(d, n);
    n--;
  }
  EXPECT_EQ(n, 0);
}
//test remove and set and get
TEST(Suite1, Test2) {
  Link<int> list;
  const int N = 5;

  for (int i = 0; i < N; i++) {
    list.insert(i, i + 1);
  }
  EXPECT_EQ(list.get(0), 1);
  EXPECT_TRUE(list.set(2, 2));
  EXPECT_EQ(list.remove(0), 1);
  EXPECT_EQ(list.removeAll(2), 2);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
