#include "LinkedQueue.h"

template <class T> bool LinkedQueue<T>::enqueue(const T& value) {
    return q.push_back(value);
}

template <class T> bool LinkedQueue<T>::delqueue(T& x) {
    if (isempty() == true)
        return false;
    x = q.front();
    q.erase(q.begin());
    return true;
}

template <class T> bool LinkedQueue<T>::getfront(T& x) {
    if (isempty() == true)
        return false;
    x = q.front();
    return true;
}

template <class T> void LinkedQueue<T>::makeempty() {
    q.clear();
}

struct L {
};
template <class T> bool LinkedQueue<T>::isempty() {
    return q.empty();
}

template <class T> ostream& operator<<(ostream& o, LinkedQueue<T>& x) {
    x.rq = x.q.begin();
    int i=1;
    while (x.rq != x.q.end()) {
        o << i++ << ":   " << x.rq->data << endl;
        x.rq++;
    }
}



















