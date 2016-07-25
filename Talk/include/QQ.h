#ifndef QQ_H
#define QQ_H

#include <list>
#include <string>

using namespace std;
#define Maxcount 6

class Mess {
public:
    int getid();
    list<string>* getmessage();
private:
    int id;
    list <string> message;
};

class QQ {
public:
    bool login();
    void rigist();
    void menue();

private:
    Mess messbox[Maxcount];
};

#endif // QQ_H
