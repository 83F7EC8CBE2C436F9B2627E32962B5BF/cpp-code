#ifndef SEQUENTIALLISTSTACK_H_
#define SEQUENTIALLISTSTACK_H_

#include "SequetialList.h"

template <typename T>
class Stack : protected SequentialList<T>
{
public:
    Stack() {}
    ~Stack(){}
    T Pop() {
        T data = SequentialList<T>::get(size() - 1);
        SequentialList<T>::remove(size() - 1);
        return data;
    }
    void Push(T data) {
        SequentialList<T>::insert(size(), data);
    }
    T Peek() {
        return SequentialList<T>::get(size() - 1);
    }
    void clear() {
        if (IsEmpty()) exit(1);
        for (int i = size(); i > 0;i--) {
            Pop();
        }
    }
    bool IsEmpty() {
        return 0 == SequentialList<T>::getsize();
    }
    int size() {
        return SequentialList<T>::getsize();
    }
};


#endif