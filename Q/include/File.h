#ifndef FILE_H
#define FILE_H

#include <string.h>
#include <string>
using namespace std;

class User {
public:
    string account;
    string passwords;
    string name;
    char ipStr[20];

    User(string a, string p, string n, char* ip):account(a), passwords(p), name(n) {
        memset(ipStr,0,sizeof(ipStr));
        strcpy(ipStr, ip);
    }
};

class Mess {
public:
    User user;
    char mess[256];
};

class File {
public:
    File();
    ~File() {};
    FILE* get_file() {return fp;}
    bool write(string);
    bool read(string);
    void look();

private:
    FILE *fp;
};

#endif // FILE_H
