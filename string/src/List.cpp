#include "List.h"

template <class T> List<T>::~List()
{
    //dtor
}

template <class T> bool ListNode<T>::insert(ListNode<T>* position, T value) {
    ListNode add(value);
    add.prior = position;
    position->next = &add;
    position = &add;
}
