/*#include "Struct_List.h"

List_Institute::List_Institute() {
    head = NULL;
    size = 0;
}

List_Institute::~List_Institute() {
    struct Institute * pointer;
    while(head != NULL) {
        pointer = head;
        head = head->next;
        delete pointer;
    }
    head = NULL;
    pointer = NULL;
}

bool List_Institute::isempty() {
    if (head == NULL)
        return true;
    return false;
}

void List_Institute::push_back(struct Institute *add) {
    struct Institute *pointer = head;
    while(pointer->next != NULL)
        pointer = pointer->next;
    pointer->next = add;
    size++;
}


bool List_Institute::pop_back() {
    if (isempty()) {
        printf("empty List!!\n");
        return false;
    }

    struct Institute *pointer = head;
    struct Institute *tem = pointer->next;
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
*/
