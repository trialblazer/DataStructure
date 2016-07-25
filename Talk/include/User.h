#ifndef USER_H
#define USER_H

#include <list>
#include <map>
#include <string>
using namespace std;

class User {
public:
    void setid(int);
    int getid();
    void setname(string&);
    string& getname();
    void setpasswords(string&);
    string getpasswords();
    void settruename(string&);
    string gettruename();

    bool addfriend();
    bool removefriend();

    bool addgroup();
    bool removegroup();

    void sendmessage();
    string getmessage();

private:
    string ID;
    string truename;
    string name;
    string passwords;

    //map <string ID, list <string> GROUP_NAME> Friends;
   // map <string GROUP_NAME, list <string> ID> Groups;
    //map <string ID, list <string>messages> Messagebox;

    map <string, list <string> > Friends;
    map <string, list <string> > Groups;
    map <string, list <string> > Messagebox;
};

#endif // USER_H
