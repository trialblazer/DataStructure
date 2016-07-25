#include "List.h"
#include <iostream>
using std::cerr;

template<class T>
List<T>::List() {
    head = tail = new List_Node<T>;
}

template<class T>
List<T>::~List() {
    clear();
}

template<class T>
List_Node<T>* List<T>::getlink(int index) {
    if (index<=0 || index>getcount()) {
        cerr << "wrong position!\n";
        return NULL;
    }
    List_Node<T>* current = head;
    while (index--) {
        current = current->getlink();
    }
    return current->getlink();
}


template<class T>
List_Node<T>* List<T>::getprior(int index) {
    if (index<=1 || index>getcount()) {
        cerr << "wrong position!\n";
        return NULL;
    }
    List_Node<T>* current = head->getlink();
    while (--index) {
        current = current->getprior();
    }
    return current;
}

template <class T>
int List<T>::getcount() {
    List_Node<T>* current = head;
    int count = 0;
    while (current->getlink() != NULL) {
        count++;
        current = current->getlink();
    }
    return count;
}

template<class T>
void List<T>::clear() {
    while (getcount()) {
        removetail();
    }
}

template <class T>
bool List<T>::addtail(T value) {
    List_Node<T>* add = new List_Node<T>(value);
    if (add == NULL) {
        cerr << "memory allocate failure!!\n";
        return false;
    }
    add->setprior(tail);
    tail->setlink(add);
    tail = add;
}
template <class T>
bool List<T>::removetail() {
    return removeat(getcount());
}

template <class T>
bool List<T>::addat(T value, int index) {
    if (index<0 || index>getcount()) {
        cerr << "wrong position!\n";
        return false;
    }
    List_Node<T>* current = head;
    while (index--) {
        current = current->getlink();
    }
    List_Node<T>* add = new List_Node<T>*(value);
    add->setprior(current);
    current->setlink(add);
    tail =  add;
    return true;
}

template <class T>
bool List<T>::removeat(int index) {
    if (index<0 || index>getcount()) {
        cerr << "wrong position!\n";
        return false;
    }
    List_Node<T>* current = head;
    while (index--) {
        current = current->getlink();
    }
    current->setprior(NULL);
    delete current;
    return true;
}








