#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

class ListNode {
public:
    ListNode * next;
    ListNode * previous;
    int value;
};

class List {
public:
    class Iterator {
    public:
        Iterator() {
            node = 0;
        }
        Iterator(ListNode* n) {
            node = n;
        }
        int operator*() {
            return node->value;
        }
        void operator++() {
            node = node->next;
        }
        void operator--() {
            node = node->previous;
        }
        bool operator==(Iterator it) {
            return it.node == node;
        }
        bool operator!=(Iterator it) {
            return it.node != node;
        }
    private:
        ListNode *node;
    };

public:
    List();
    ~List();
    bool push_back(int value);
    bool push_front(int value);
    bool pop_back();
    bool pop_front();
    int get(int index);
    ListNode * search(int value);
    bool remove(int index);

    //////////////////////////////
    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();

private:
    ListNode * head;
    ListNode * tail;
    int total;
};

#endif // LIST_H_INCLUDED
