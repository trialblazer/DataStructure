#ifndef LIST_H
#define LIST_H

struct ListNode {
	int value;
	struct ListNode* next;
	struct ListNode* prev;
};

class List {
public:
	List();
	~List();
	bool push_back(int value);
	bool push_front(int balue);
	void pop_back();
	void pop_front();
	int search(int value);
	void destory();
	int get(int index);
	void sort();
	void prin_back();
	void prin_front();

private:
	ListNode *head;
	ListNode *tail;
	int size;
};

#endif // LIST_H
