#ifndef SEQUENTIALLIST_H_
#define SEQUENTIALLIST_H_

#include <iostream>

template <typename T>

class SequentialList {
 private:
  T *arr;
  int length, size;

 public:
  SequentialList(int len = 10) : arr(new T[len]), length(len), size(0) {}

  ~SequentialList() { delete[] arr; }

  bool insert(T data) {
    if (size < length) {
      arr[size++] = data;
      return true;
    }
    return false;
  }

  void const traversal() {
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << std::endl;
    }
  }
};

#endif
