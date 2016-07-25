#include "Stack.h"

bool Stack::push(int value) {
    return v.push(value);
}

void Stack::pop() {
    v.pop_back();
}

int Stack::gettop() {
    return v.get(v.getcurrentsize()-1);
}

int Stack::get(int index) {
    return v.get(index);
}

void Stack::sort() {
    v.sort();
}
