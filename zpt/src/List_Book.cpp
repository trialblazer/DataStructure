#include<stdio.h>
#include "List_Book.h"

List_Book::List_Book() {
    head = NULL;
    size = 0;
}

List_Book::~List_Book() {
    BookNode * pointer;
    while(head != NULL) {
        pointer = head;
        head = head->next;
        delete pointer;
    }
    head = NULL;
    pointer = NULL;
}

bool List_Book::isempty() {
    if (head == NULL)
        return true;
    return false;
}

void List_Book::push_back(BookNode *add) {
    BookNode *pointer = head;
    while(pointer->next != NULL)
        pointer = pointer->next;
    pointer->next = add;
    size++;
}

void List_Book::push_front(BookNode* add) {
    add->next = head;
    head = add;
    size++;
}

bool List_Book::pop_back() {
    if (isempty()) {
        printf("empty List!!\n");
        return false;
    }

    BookNode *pointer = head;
    BookNode *tem = pointer->next;
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

bool List_Book::pop_front() {
    if (isempty()) {
        printf("empty List!!\n");
        return false;
    }
    BookNode *pointer = head->next;
    delete head;
    head = pointer;
    size--;
    return true;
}

