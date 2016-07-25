/*#include "Astring.h"
#include <iostream>
#include <stdlib.h>


Astring::Astring(int sz) {
    maxsize = sz;
    ch = new char[maxsize+1];
    if (ch == NULL) {
        std::cerr << "Memory allocation failure!\n";
        eixt(1);
    }
    ch[0] = '\0';
    curlength = 0;
}

Astring::Astring(char* init) {
    int len = strlen(init);
    maxsize = len>maxsize? len:maxsize;
    ch = new char[maxsize+1];
    if (ch == NULL) {
        std::cerr << "Memory allocation failure!\n";
        eixt(1);
    }
    ch[0] = '\0';
    strcpy(ch, init);
    curlength = len;
}

Astring::Astring(const Astring& ob) {
    maxsize = ob.maxsize;
    curlength = ob.curlength;
    //ch = new char[maxsize];
    ch = new char[maxsize+1];
    if (ch == NULl) {
        std::cerr << "Memory allocation failure!\n";
        eixt(1);
    }
    strcpy(ch, ob.ch);
}

Astring::Astring& operator () (int pos, int len) {
    if (len - pos < 1 || curlength == 1)
        return NULL;

}



*/







































