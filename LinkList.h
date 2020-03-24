#include <iostream>

template <typename T>
class Link {
 private:
  struct Node {
    T data;
    Node *next;
  };
  Node *head;

 public:
  Link() : head(nullptr) {}
  ~Link() {
    Node *p = head;
    for (; p != nullptr;) {
      Node *t = p;
      p = p->next;
      delete[] t;
    }
  }
  void insert(T data) {
    Node *node = new Node();
    node->data = data;
    node->next = head;
    head = node;
  }
  void traversal(std::function<void(T)> visit) {
    for (Node *node = head; node != nullptr; node = node -> next) {
      visit(node -> data);
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