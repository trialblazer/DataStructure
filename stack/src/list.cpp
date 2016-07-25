#include "../include/List.h"

#include <iostream>
#include <cstdlib>

List::List() {
    // ListNode * head = NULL;
    // ListNode * tail = NULL;
    head = NULL;
    tail = NULL;
    total=0;
}

List::~List() {
    while(head != NULL) {
        ListNode * pointer = head;
        head = head->next;
        delete pointer;
    }
    head = NULL;
    tail = NULL;
}

bool List::push_back(int value) {
    ListNode * p = new ListNode;
    if(p) {
        total++;
        p->value = value;
        p->next = NULL;
        if (head == NULL && tail == NULL) {
            p->previous = NULL;
            head = p;
            tail = p;
        } else {
            p->previous = tail;
            tail->next = p;
            tail = p;
        }
        return true;
    }
    return false;
}

bool List::push_front(int value) {
    ListNode * p = new ListNode;
    if(p) {
        p->value = value;
        total++;
        if (head == NULL && tail == NULL) {
            p->next = NULL;
            p->previous = NULL;
            head = p;
            tail = p;
        } else {
            p->next = head;
            p->previous = NULL;
            head->previous = p;
            head = p;
        }
        return true;
    }
    return false;
}

bool List::pop_back() {
    if(tail == NULL && head == NULL)
        return false;
    if(tail == head && head != NULL) {
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        ListNode * pointer;
        pointer = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete pointer;
        pointer = NULL;
    }
    total--;
    return true;
}

bool List::pop_front() {
    if (head == NULL && tail == NULL)
        return false;
    if (tail == head && head != NULL) {
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        ListNode * pointer;
        pointer = head;
        head = head->next;
        head->previous = NULL;
        delete(pointer);
        pointer = NULL;
    }
    total--;
    return true;
}

ListNode* List::search(int value) {
    ListNode * pointer = head;
    while(pointer != NULL) {
        if(pointer->value ==  value) {
            break;
        }
        pointer=pointer->next;
    }
    return pointer;
}

int List::get(int index) {
     if(index<=0 || index>total) {
        std::cout << "out of size, error!!" << std::endl;
        exit(-1);
    }
    ListNode * pointer = head;
    int i = 0;
    while(pointer != NULL) {
        i++;
        if(i ==  index) {
            return pointer->value;
        }
        pointer=pointer->next;
    }
}

bool List::remove(int index) {
    if(index<=0 || index>total) {
        std::cout << "out of size, error!!" << std::endl;
        return false;
    }

    if (index == 1) {
        pop_front();
    } else if (index == total) {
        pop_back();
    } else {
        ListNode * pointer;
        pointer = head;
        int i = 0;
        // while(i++) {
        while(++i) {
            if(i == index)
                break;
            pointer=pointer->next;
        }
        (pointer->previous)->next = pointer->next;
        (pointer->next)->previous = pointer->previous;
        delete pointer;
        pointer = NULL;
        total--;
    }
    return true;
}

List::Iterator List::begin() {
    return Iterator(head);
}

List::Iterator List::end() {
    return Iterator();
}

List::Iterator List::rbegin() {
    return Iterator(tail);
}

List::Iterator List::rend() {
    return Iterator();
}
