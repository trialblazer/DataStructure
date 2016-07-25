#include "Stack.h"

/*
#define DEFAULT_STACK_SIZE 10

Stack::Stack() {
    v = new int[DEFAULT_STACK_SIZE];
    if(v == NULL) {
        std::cerr << "memory allocate failure\n";
        exit(-1);
    }
    size = DEFAULT_STACK_SIZE;
    p = 0;
}

Stack::Stack(int s) {
    v = new int[s];
    if(v == NULL) {
        std::cerr << "memory allocate failure\n";
        exit(-1);
    }
    size = s;
    p = 0;
}

Stack::~Stack() {
    delete []v;
    v = NULL;
}
*/

bool Stack::push(int value) {
    return v.push(value);
}

bool Stack::empty() {
    return v.empty();
}

bool Stack::pop_back() {
    return v.pop_back();
}

int Stack::get(int index) {
    return v.get(index);
}
















