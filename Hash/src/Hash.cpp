#include "Hash.h"
#include <stdlib.h>

Hash::Hash(int s, int dt) {
    maxsize = s;
    ht = new int[maxsize];
    inf = new state[maxsize];
    if (ht == NULL || inf == NULL)
        exit(1);
    for (int i=0; i<maxsize; i++)
        inf[i] = empty;
    currentsize = 0;
    divitor = dt;
}

Hash::~Hash() {
    delete ht;
    delete inf;
}

int Hash::findpos(const int& value) {
    int pos = value%divitor;
    int temp = pos;
    do {
        if (inf[temp] == empty || inf[temp] == active && ht[temp] == value)
            return temp;
        temp = (temp+1)%divitor;
    } while (pos != temp);
    return temp;
}

bool Hash::insert(const int& value) {
    int pos = findpos(value);
    if (inf[pos] == empty) {
        ht[pos] = value;
        inf[pos] = active;
        currentsize++;
        return true;
    }
    return false;

}

bool Hash::remove(const int& value) {
    int pos = findpos(value);
    if (inf[pos] == active &&  ht[pos] == value) {
        inf[pos] = deleted;
        currentsize--;
        return true;
    }
    return false;
}

bool Hash::search(const int& value, int &pos) {
    int temp = findpos(value);
    if (inf[temp] == active && ht[temp] == value) {
        pos = temp;
        return true;
    }
    return false;
}

void Hash::makempty() {
    for (int i=0; i<maxsize; i++)
        inf[i] = empty;
    currentsize = 0;
}







































