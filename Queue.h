#ifndef LINKLISTSTACK_H_
#define LINKLISTSTACK_H_

#include "LinkList.h"

template <typename T>
class Queue : protected Link<T> {
 public:
  T Pop() {
    T data = Link<T>::get(size() - 1);
    Link<T>::remove(0);
    return data;
  }
  void Push(T data) { Link<T>::insert(size(), data); }
  T Peek() { return Link<T>::get(0); }
  void clear() {
    if (IsEmpty()) exit(1);
    for (int i = size(); i > 0; i--) {
      Pop();
    }
  }
  bool IsEmpty() { return 0 == size(); }
  int size() { return Link<T>::getsize(); }
};
#endif