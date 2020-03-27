#include "SequentialListStack.h"
#include "Match.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(Suite1, Test1) {
  std::string text = "{[({})]}}";
  std::string text2 = "{[({})]}";
  Match match;
  EXPECT_FALSE(match.BracketMatch(text));
  EXPECT_FALSE(match.BracketMatch(text2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
