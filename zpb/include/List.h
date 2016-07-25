#ifndef LIST_H
#define LIST_H

class List_Node {
public:
    int value;
    List_Node *next;
};

class List {
public:
    List();
    ~List();
    bool empty();
    bool push_back(int value);
    bool push_front(int value);
    bool pop_back();
    bool pop_front();
    void prin();

private:
    List_Node * head;
    int size;
};

#endif // LIST_H
