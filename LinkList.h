#include <functional>
#include <iostream>

template <typename T>
class Link {
 private:
  struct Node {
    T data;
    Node *next;
  };
  Node *head;
  Node *tail;
  int size;

 public:
  Link() : head(nullptr), tail(nullptr), size(0) {}
  ~Link() {
    Node *p = head;
    for (; p != nullptr;) {
      Node *t = p;
      p = p->next;
      delete[] t;
    }
  }
  bool IsEmpty() { return 0 == size; }

  T get(int index) {
    if (index > size || index < 0) exit(1);
    Node *p = head;
    for (int i = 0; i < index; i++) {
      p = p->next;
    }
    return p->data;
  }

  bool set(int index, T data) {
    if (index > size || index < 0) exit(1);
    Node *p = head;
    for (int i = 0; i < index; i++) {
      p = p->next;
    }
    p->data = data;

    return true;
  }
  void insert(int index, T data) {
    if (index < 0 || index > size) exit(1);
    Node *NewNode = new Node();
    NewNode->data = data;
    if (0 == index) {
      NewNode->next = head;
      head = NewNode;
      size++;
    } else {
      Node *p = head;
      for (int i = 0; i < index - 1; i++) p = p->next;
      NewNode->next = p->next;
      p->next = NewNode;
      size++;
    }
    Node *p = head;
    while (p->next != nullptr) {
      p = p->next;
    }
    tail = p;
  }
  T remove(int index) {
    if (index < 0 || index > size) exit(1);
    Node *p = head;
    if (0 == index) {
      T data = head->data;
      head = head->next;
      free(p);
      size--;
      return data;
    }
    for (int i = 0; i < index - 1; i++) p = p->next;
    Node *q = p->next;
    T data = q->data;
    p->next = q->next;
    free(q);
    size--;
    return data;
  }

  int removeAll(T const &data) {
    int count = 0;
    int i = 0;
    while (i < size - 1) {
      if (data == get(i)) {
        remove(i);
        i = 0;
        count++;
      } else {
        i++;
      }
    }
    return count;
  }
  int contains(T data) {
    int count = 0;
    for (int i = 0; i < size; i++) {
      if (data == get(i)) count++;
    }
    return count;
  }
  void traversal(std::function<void(T)> visit) {
    for (Node *node = head; node != nullptr; node = node->next) {
      visit(node->data);
    }
  }
  class iterator {
    Node *node;

   public:
    explicit iterator(Node *node) : node(node) {}
    iterator &operator++() {
      node = node->next;
      return *this;
    }
    iterator operator++(int) {
      iterator retval = *this;
      ++(*this);
      return retval;
    }
    bool operator==(iterator other) const { return node == other.node; }
    bool operator!=(iterator other) const { return !(*this == other); }
    T operator*() const { return node->data; }
  };
  iterator begin() { return iterator(head); }
  iterator end() { return iterator(nullptr); }
};