#include <iostream>

#include "SequetialList.h"

int main(int argc, char **argv) {
  SequentialList<int> list(5);

  for (int i = 0; i < 10; i++) {
    list.insert(i + 1);
  }
  list.traversal();

  return 0;
}
