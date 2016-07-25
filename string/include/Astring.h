#ifndef ASTRING_H
#define ASTRING_H

#define DEFAULTSTRINGSIZE 20

class Astring {
public:
    Astring():length(DEFAULTSTRINGSIZE);
    Astring(int sz = DEFAULTSTRINGSIZE);
    Astring(char *init);
    Astring(const Astring& ob);
    ~Astring() {delete []ch;}

    int size()const {return length;}
    bool operator == (Astring& ob)const {return strcmp(ch, ob.ch) == 0;}
    bool operator != (Astring& ob)const {return strcmp(ch, ob.ch) != 0;}
    Astring& operator = (Astring& ob);
    Astring& operator += (Astring& ob);
    bool operator >(Astring& ob);
    bool operator <(Astring& ob);
    char& operator [](int i);

    int find(char* object)const;
    int compare(char* );
    int compare(Astring ob);

private:
    unsigned int length;
    char *ch;
};

#endif // ASTRING_H
