#include<iostream>
#include "List.h"

#define DEFAULT_LIST_SIZE 30

List::List() {
    head = NULL;
    size = 0;
}

List::~List() {
    List_Node * pointer;
    while(head != NULL) {
        pointer = head;
        head = head->next;
        delete pointer;
    }
    head = NULL;
    pointer = NULL;
}

bool List::empty() {
    if (size == 0)
        return true;
    return false;
}

bool List::push_back(int value) {
    List_Node *tem;
    List_Node *pointer;
    if (empty()) {
        head = new List_Node;
        if (head == NULL)
            return false;
        head->value = value;
        head->next = NULL;
    } else {
        pointer = head;
        while(pointer->next != NULL)
            pointer = pointer->next;
        tem = new List_Node;
        if (tem == NULL)
            return false;

        tem->value = value;
        tem->next = NULL;
        pointer->next = tem;
    }
    size++;
    //tem = NULL;
    //pointer = NULL;
    return true;
}

bool List::push_front(int value) {
    List_Node *tem = new List_Node;
    if (tem == NULL)
        return false;
    tem->value = value;
    tem->next = head;
    head = tem;
    size++;
    return true;
}

bool List::pop_back() {
    if (empty()) {
        std::cerr << "empty List!!\n";
        return false;
    }

    List_Node *pointer = head;
    List_Node *tem = pointer->next;
    if (tem != NULL) {
        while (tem->next != NULL) {
            tem = tem->next;
            pointer = pointer->next;
        }
        pointer->next = NULL;
        delete tem;
        tem = NULL;
    } else {
        delete head;
        pointer = NULL;
        head = NULL;
    }
    size--;
    return true;
}

bool List::pop_front() {
    if (empty()) {
        std::cerr << "empty List!!\n";
        return false;
    }

    List_Node * pointer;
    pointer = head->next;
    delete head;
    head = pointer;
    size--;
    return true;
}

void List::prin() {
    List_Node *pointer = head;
    while(pointer != NULL) {
        std::cout << pointer->value << "    ";
        pointer = pointer->next;
    }
    std::cout << std::endl;
}
