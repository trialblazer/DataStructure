#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;
/*
template <class T> class ListNode {
public:
    ListNode():Link(NULL), Prior(NULL) {}
    ListNode(T value):Link(NULL), Prior(NULL), data(value) {}
    ListNode<T>* getlink();
    ListNode<T>* getprior();
    void setlink(ListNode<T>* newlink);
    void setprior(ListNode<T>* newprior);
    T& getdata();

private:
    ListNode<T>* Link;
    ListNode<T>* Prior;
    T data;
};
template <class T1> class List {
public:
    List();
    ~List();
    bool addtail(T1 value);
    bool removetail();
    bool addat(int index, T1 value);
    bool removeat(int index);
    bool isempty();
    void removeall();
    int getcount();
    ListNode<T1>* gethead();
    ListNode<T1>* gettail();
    ListNode<T1>* getlink(int index);
    void settail(ListNode<T1>* newtail);
    T1& getat(int index);
    T1& operator[] (int index);

private:
    ListNode<T1>* getpoint(int index);
    ListNode<T1>* head;
    ListNode<T1>* tail;
};
template <class T2> class Iterator {
private:
    ListNode<T2>* cur;

public:
    Iterator():cur(NULL) {}
    Iterator(ListNode<T2>* link):cur(link) {}
    T2 operator ++();
    T2 operator --();
    T2 operator ++(int);
    T2 operator --(int);
    bool operator ==(ListNode<T2>*);
    void operator +=(ListNode<T2>*);
    bool operator !=(ListNode<T2>*);
    ostream& operator <<(ostream& a);
    ListNode<T2>* getcur();
    void operator = (ListNode<T2>* point);
};

template <class T2> ListNode<T2>* Iterator<T2>::getcur() {
    return cur;
}
template <class T2> T2 Iterator<T2>::operator ++() {
    cur = cur->getlink();
    return getcur()->getdata();
}
template <class T2> T2 Iterator<T2>::operator ++(int) {
    T2 tmpt = cur->getdata();
    cur = cur->getlink();
    return tmpt;
}
template <class T2> T2 Iterator<T2>::operator --() {
    cur = cur->getprior();
    return cur->getdata();
}
template <class T2> T2 Iterator<T2>::operator --(int) {
    T2 tmpt = cur->getdata();
    cur = cur->getprior();
    return tmpt;
}
template <class T2> ostream& Iterator<T2>::operator <<(ostream& a) {
    a << cur->getdata();
    return a;
}
template <class T2> bool Iterator<T2>::operator ==(ListNode<T2>*point) {
    return cur == point;
}
template <class T2> void Iterator<T2>::operator +=(ListNode<T2>* point) {
    cur->getdata() += point->getdata();
}
template <class T2> bool Iterator<T2>::operator !=(ListNode<T2>*point) {
    return cur->getdata() != point->getdata();
}
template <class T2> void Iterator<T2>::operator = (ListNode<T2>*point) {
    cur->getdata() = point->getdata();
}

template <class T> ListNode<T>* ListNode<T>::getlink() {
    return Link;
}
template <class T> ListNode<T>* ListNode<T>::getprior() {
    return Prior;
}
template <class T> void ListNode<T>::setlink(ListNode<T>* newlink) {
    Link = newlink;
}
template <class T> void ListNode<T>::setprior(ListNode<T>* newprior) {
    Prior = newprior;
}
template <class T> T& ListNode<T>::getdata() {
    return data;
}

template <class T1> List<T1>::List() {
    head = tail = new ListNode<T1>;
    if (head == NULL) {
        cerr << "Memory allocate failure!!" << endl;
        exit(1);
    }
}
template <class T1> List<T1>::~List() {
    removeall();
    delete head;
}
template <class T1> ListNode<T1>* List<T1>::getpoint(int index) {
    if (index<0 || index>getcount()) {
        cout << "Wrong position!" << endl;
        return NULL;
    }
    ListNode<T1>* current = head;
    while (index--)
        current = current->getlink();
    return current;
}
template <class T1> bool List<T1>::addtail(T1 value) {
    ListNode<T1>* add = new ListNode<T1>(value);
    if (add == NULL) {
        cerr << "Memory allocate failure!" << endl;
        return false;
    }
    tail->setlink(add);
    add->setprior(tail);
    tail = tail->getlink();
}
template <class T1> bool List<T1>::removetail() {
    return removeat(getcount());
}
template <class T1> bool List<T1>::addat(int index, T1 value) {
    ListNode<T1>* add = new ListNode<T1>(value);
    if (add == NULL) {
        cerr << "Memeory allocate failure!" << endl;
        return false;
    }
    ListNode<T1>* tmpt = getpoint(index);
    if (tmpt) {
        add->setlink(tmpt->getlink());
        tmpt->setprior(add);
        tmpt->setlink(add);
        add->setprior(tmpt);
        return true;
    }
    return false;
}
template <class T1> bool List<T1>::removeat(int index) {
    ListNode<T1>* tmpt = getpoint(index);
    if (index == 0 || tmpt == NULL)
        return false;

    if (tmpt->getlink() == NULL) {
        tail = tail->getprior();
        tail->setlink(NULL);
    } else {
        tmpt->getprior()->setlink(tmpt->getlink());
        tmpt->getlink()->setprior(tmpt->getprior());
    }
    delete tmpt;
    return true;
}
template <class T1> bool List<T1>::isempty() {
    return head==tail;
}
template <class T1> void List<T1>::removeall() {
    int tmpt = getcount();
    while (tmpt--)
        removetail();
}
template <class T1> int List<T1>::getcount() {
    ListNode<T1>* current = head;
    int count = 0;
    while (current->getlink()) {
        count++;
        current = current->getlink();
    }
    return count;
}
template <class T1> ListNode<T1>* List<T1>::gethead() {
    return head;
}
template <class T1> ListNode<T1>* List<T1>::gettail() {
    return tail;
}
template <class T1> void List<T1>::settail(ListNode<T1>* newtail) {
    tail = newtail;
}
template <class T1> T1& List<T1>::getat(int index) {
    ListNode<T1>* tmpt = getpoint(index);
    if (tmpt)
        return tmpt->getdata();
    return -1234;
}
template <class T1> T1& List<T1>::operator[] (int index) {
    ListNode<T1>* tmpt = getpoint(index);
    if (tmpt)
        return tmpt->getdata();
    else
        return tail->getdata();
}

int main() {
    List<int> a;
    Iterator<int> ra;
    ra = a.gethead();
    List<string> b;
    for (int i=0; i<10; i++)
        a.addtail(i);
    for (int i=10; i<20; i++)
        a.addat(i-10, i);
    //for (int i=1; i<=a.getcount(); i++)
    //    cout << a[i] << "  ";
    while (ra != a.gettail()) {
        cout << ra.getcur() << "  ";
    }
    cout << endl;

    b.addtail("nihaoma");
    b.addtail("nishishei");
    b.addtail("zhaopengtao");
    for (int i=1; i<=b.getcount(); i++)
        cout << b[i] << "  ";
    cout << endl;
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int n;
	struct Node *ahead;
	struct Node *next;
} Node;

Node *create (int N);
Node *sreach (Node *head, int P);
Node *deletes (Node *head, int M);
int main (void) {
	int N, M, P;
	scanf ("%d, %d, %d", &N, &M, &P);
	Node *head;
	return 0;
}
Node *create (int N) {
	int n = 1;
	Node *head, *tail, *s;
	head = (Node*)malloc (sizeof (Node));
	head->n = n;
	tail = head;
	while (n ++ < N) {
		s = (Node*)malloc (sizeof (Node));
		s->n = n;
		tail->next = s;
		s->ahead = tail;
		tail = s;
	}
	tail->next = head;
	head->ahead = tail;
	return head;
}
Node *sreach (Node *head, int P) {
	while (head->n != P) {
		head = head->next;
	}
	return head;
}
Node *deletes (Node *head, int M) {
	int n = 1;
	Node *temp = head;
	while (n < M) {
		temp = temp->next;
		n ++;
	}
	temp->next->ahead = temp->ahead;
	temp->ahead->next = temp->next;
	printf ("%d ", temp->n);
	head = temp->next;
	free (temp);
	return head;
}










