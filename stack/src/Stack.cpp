#include "../include/stack.h"

#include <iostream>

Stack::Stack() {
    p = 0;
}

bool Stack::empty() {
    if(p == 0)
        return true;
    return false;
}

bool Stack::push(int value) {
    v.push_back(value);
    p++;
}

int Stack::top() {
    if(empty()) {
        std::cout << "the stack is empty, error!!" << std::endl;
        return -1;
    }
    return v.get(p-1);
}

bool Stack::pop() {
      if(empty()) {
        std::cout << "the stack is empty, error!!" << std::endl;
        return false;
    }
    p--;
    return true;
}
