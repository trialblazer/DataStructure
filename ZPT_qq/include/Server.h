#ifndef SERVER_H
#define SERVER_H

#include <list>
#include <map>
#include <string>

using namespace std;

typedef struct Date {
    int year;
    int month;
    int day;
}Dates;

class information {
public:
    void print();
    string getpasswords();
    void setpassowords(string);

    int ID;
    string name;
    int state;
    string signature;
    int sex;
    Dates birthday;

private:
    string passwords;
};

struct friend_list {
    list <int > Friend;
    list <int >::iterator friend_id_itor;
    string truename;
}Friend_list;

struct Message {
    list <string> oldmess;
    list <string>::iterator old_mess_itor;
    list <string> newmess;
    list <string>::iterator new_mess_itor;
}Messages;

struct Group {
    map <string, list<int >group_list> group;
    list <int>::iterator group_id_itor;
    map <string, list <int> >::iterator group_list_itor;
}groups;

class Server {
public:
    Server();
    int receivemessage(char choice, int id);
    void receivemessage(int from, int to, string mess);

private:
    int login();
    void rigist();
    void show_group(int id);
    void show_mess(int id);

    map <int id, information inform>Users;
    map <int, information>::iterator user_itor;

    map <int id, Friend_list friends>Friends;
    map <int , Friend_list>::iterator friend_itor;

    map <int id, Messages mess> Messagebox;
    map <int, Messages>::iterator mess_itor;

    map <int id, groups group_list>Groups;
    map <int, groups>::iterator group_itor;
};

#endif // SERVER_H
