#include "List.h"

#include<iostream>
#include<stdlib.h>

List::List() {
	head = NULL;
	tail = NULL;
	size = 0;
}

List::~List() {
	destory();
}

bool List::push_back(int value) {
	if (head == NULL) {
		head = new ListNode;
		if (head == NULL) {
			std::cerr << "Memory allocate failure!!\n" ;
			exit(1);
		}
		head->value = value;
		/// head->next = tail;
		tail = head; //
		head->next = tail;
		head->prev = tail;
		tail->next = head;
		tail->prev = head;
	} else {
		ListNode* pointer = new ListNode;
		if (pointer == NULL)
			return false;
		pointer->value = value;
		tail->next = pointer;
		pointer->prev = tail;
		/// tail = pointer;
		pointer->next = head;
		head->prev = pointer;
		tail = pointer;
		pointer = NULL;
	}
	size++;
	return true;
}

bool List::push_front(int value) {
	if (head == NULL) {
		head = new ListNode;
		if (head == NULL) {
			std::cerr << "Memory allocate failure!!\n" ;
			exit(1);
		}
		head->value = value;
		/// head->next = tail;
		tail = head;
		head->next = tail; //
		head->prev = tail;
		tail->next = head;
		tail->prev = head;
	} else {
		ListNode *pointer = new ListNode;
		if (pointer == NULL)
			return false;
		pointer->value = value;
		pointer->next = head;
		head->prev = pointer;
		pointer->prev = tail;//
		tail->next = pointer;//
		head = pointer;
		pointer = NULL;
	}
	size++;
	return true;
}

void List::pop_back() {
	if (size == 1) {
		delete head;
		head = NULL;
		tail == NULL;
	}
	if (size>1) {
		ListNode* pointer = tail;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		delete pointer;
		pointer = NULL;
	}
	size--;
}

void List::pop_front() {
	if (size == 1) {
		delete head;
		head = NULL;
		tail == NULL;
	}
	if (size>1) {
		ListNode* pointer = head;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		delete pointer;
		pointer = NULL;
	}
	size--;
}

//找到的话，则返回查找的次数，否则返回-1.
int List::search(int value) {
	ListNode* pointer = head;
	int i = 1;
	while (i++ <= size) {
		if (pointer->value == value)
			return i-1;
        pointer = pointer->next;
	}
	return -1;
}

//返回第index个数，否则返回-1.
int List::get(int index) {
	if (index < 1 || index > size) {
		std::cerr << "index error!!\n";
		return -1;
	}
	int count = 1;
	ListNode* pointer = head;
	while (1) {
		if (index == count++)
			return pointer->value;
		pointer = pointer->next;
	}
}

//删除所有结点.
void List::destory() {
	/// int count = 0;
	/// while (count < size){
	/// 	pop_front();
    /// count++;
    /// }
    while(size > 0) {
        pop_back();
    }
}


void List::sort() {
    if (size == 1)
        return;
    for (int i=0; i<size; i++) {
        ListNode *pointer = head;
        for (int j=0; j<size-i; j++) {
            if (pointer->value > pointer->next->value) {
                int tmpt = pointer->value;
                pointer->value = pointer->next->value;
                pointer->next->value = tmpt;
            }
            pointer = pointer->next;
        }
    }
}


void List::prin_front() {
    if (head == NULL)
        return;
    ListNode *pointer = head;
    int i = size;
    while (i-- > 0) {
        std::cout << pointer->value << "  ";
        pointer = pointer->next;
    }
    pointer = NULL;
}


void List::prin_back(){
    if (head == NULL)
        return;
    ListNode *pointer = tail;
    int i = size;
    while (i-- > 0) {
        std::cout << pointer->value << "  ";
        pointer = pointer->prev;
    }
    pointer = NULL;
}










