#ifndef LIST_BOOK_H
#define LIST_BOOK_H

#include "Stuct.h"

struct List_Book {
    List_Book();
    ~List_Book();
    bool isempty();
    void push_back(BookNode* add);
    void push_front(BookNode* add);
    bool pop_back();
    bool pop_front();

    BookNode *head;
    int size;
};

struct List_Student {
    List_Student();
    ~List_Student();
    bool isempty();
    void push_back(BookNode* add);
    void push_front(BookNode* add);
    bool pop_back();
    bool pop_front();

    Operator *head;
    int size;
};


#endif // LIST_BOOK_H
