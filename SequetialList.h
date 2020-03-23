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

  bool insert(T data) {
    if (size < length) {
      arr[size++] = data;
      return true;
    }
    return false;
  }

  void traversal(const std::function<void(const T &)> &visit) {
    for (int i = 0; i < size; i++) visit(*arr + i);
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