#ifndef SEQUENTIALLIST_H_
#define SEQUENTIALLIST_H_

#include <functional>
#include <iostream>

template <typename T>

class SequentialList {
 private:
  T *arr;
  int length, size;

 public:
  SequentialList(int len = 10) : arr(new T[len]), length(len), size(0) {}

  ~SequentialList() { delete[] arr; }

  bool IsEmpty() { return 0 == size; }

  T get(int index) {
    if (index >= size || index < 0) exit(1);
    return arr[index];
  }

  bool set(int index, T data) {
    if (index >= size || index < 0) exit(1);
    arr[index] = data;
    return true;
  }

  void insert(int index, T data) {
    if (size >= length) exit(1);
    for (int i = size; i > index; i--) arr[i] = arr[i - 1];
    arr[index] = data;
    size++;
  }

  T remove(int index) {
    if (index >= size || index < 0 || IsEmpty()) exit(1);

    int tmp = arr[index];
    for (int i = index; i < size; i++) {
      arr[i] = arr[i + 1];
    }
    size--;
    return tmp;
  }

  int removeAll(T data) {
    int count = 0;
    if (IsEmpty()) exit(1);
    for (int i = 0; i < size; i++) {
      if (arr[i] == 1) {
        remove(i);
        i--;
        count++;
      }
    }
    return count;
  }

  int contains(T data) {
    int count = 0;
    for (int i = 0; i < size; i++)
      if (arr[i] == data) count++;
    return count;
  }
  void traversal(const std::function<void(const T &)> &visit) {
    for (int i = 0; i < size; i++) visit(*arr + i);
  }
  int getsize() {
    return size;
  }
  class iterator {
   private:
    T *node;

   public:
    explicit iterator(T *node) : node(node) {}
    iterator &operator++() {
      node++;
      return *this;
    }
    iterator operator++(int) {
      iterator retval = *this;
      ++(*this);
      return retval;
    }
    bool operator==(iterator other) const { return node == other.node; }
    bool operator!=(iterator other) const { return !(node == other.node); }
    T operator*() const { return *node; }
  };
  iterator begin() { return iterator(arr); }
  iterator end() { return iterator(arr + size); }
};

#endif