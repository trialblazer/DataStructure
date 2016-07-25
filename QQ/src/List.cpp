#include "List.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;


List::List() {
    head = NULL;
    total = 0;
}

List::~List() {
    for (int i=0; i<total; i++) {
        Node *pointer = head;
        head = head->next;
        delete pointer;
    }
    head = NULL;
}


bool List::insert(char c[], char a[]) {
    int datanum=1;
    if (head == NULL) {
        head = new Node;
        if (head == NULL)
            return false;
        head->index = datanum;
        head->next = NULL;
        strcpy(head->p.account, c);
        strcpy(head->p.name, a);
        total++;
        return true;
    }
    datanum++;
    Node *pointer, *newnode;
    pointer = head;
    while (pointer->next != NULL)
        pointer = pointer->next;
    newnode = new Node;
    if (newnode == NULL) {
        newnode = NULL;
        pointer = NULL;
        return false;
    }
    newnode->index = datanum;
    strcpy(newnode->p.account, c);
    strcpy(head->p.name, a);
    newnode->next = NULL;
    pointer->next = newnode;
    total++;
    newnode = NULL;
    pointer = NULL;
    return true;
}

int List::getsize() {
    Node *pointer = head;
    int size = 0;
    while (pointer != NULL) {
        if (pointer->p.isfriend != 0)
            size++;
        pointer = pointer->next;
    }
    return size;
}


Person* List::find(int index) {
    if (index<=0 || index>total)
        return NULL;
    Node *pointer = head;
    for (int i=0; i<total; i++) {
        if (pointer->index == index && pointer->p.isfriend != 0)
            return &(pointer->p);
        pointer = pointer->next;
    }
}


Person* List::find(char c[]) {
    Node *pointer = head;
    if (pointer != NULL) {
        for (int i=0; i<total; i++) {
            if (strcmp(pointer->p.account, c) == 0)
                return &(pointer->p);
            pointer = pointer->next;
        }
    }
    return NULL;
}

char* List::getname(char c[]) {
    Node *pointer = head;
    while (pointer != NULL) {
        if (strcmp(c, pointer->p.account) == 0) {
            if (strcmp(pointer->p.truename, "") != 0)
                return pointer->p.truename;
            if (strcmp(pointer->p.name, "") != 0)
                return pointer->p.name;
            return c;
        }
        pointer = pointer->next;
    }
}



void List::print() {
    Node *pointer = head;
    while (pointer != NULL) {
        if (pointer->p.isfriend != 0) {
            //if (!pointer->p.tn_isempty())
             //   cout << pointer->index << "  :  " << pointer->p.truename << endl;
            //else
                cout << pointer->index << "  :  " << pointer->p.name << endl;
        }
        pointer = pointer->next;
    }
}




