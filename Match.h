#ifndef MATCH_H_
#define MATCH_H_

#include <string>

#include "SequentialListStack.h"

class Match {
 private:
  Stack<char> list;
  bool match(char c) {
    if (c == ')') return !(list.Peek() == ')');
    if (c == '{') return !(list.Peek() == '}');
    if (c == '[') return !(list.Peek() == ']');
    return true;
  }

 public:
  bool BracketMatch(const std::string text) {
    char c;
    int i = 0;
    while (text[i]) {
      c = text[i];
      if ('(' == c || '[' == c || '{' == c)
        list.Push(c);
      else {
        if (list.IsEmpty() || match(c)) return false;
        list.Pop();
      }
      i++;
    }
    if (!list.IsEmpty()) return false;
    return true;
  }
};

#endif
