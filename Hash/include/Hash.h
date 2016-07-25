#ifndef HASH_H
#define HASH_H

#define DEFAULTSIZE 100
#define MAXPRIME 97

enum state {active, deleted, empty};

class Hash {
public:
    Hash(int=DEFAULTSIZE, int=MAXPRIME);
    ~Hash();
    bool insert(const int&);
    bool remove(const int&);
    bool search(const int&, int&);
    void makempty();
    int getsize() {return currentsize;}
    bool isfull() {return currentsize == maxsize;}

private:
    int findpos(const int&);

public:
    int *ht;
    state* inf;

private:
    int divitor;

    int currentsize;
    int maxsize;
};

#endif // HASH_H
