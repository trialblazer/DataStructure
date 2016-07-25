#ifndef CLIENT_H
#define CLIENT_H

#include "Server.h"

class Client {
public:
    void menue();

private:
    Server console;
    void user_menue(int id);        ///主菜单
    void group_menue(int id);      ///组菜单
    void mess_menue(int id);       ///会话菜单
    void friend_menue(int id);     ///全部好友菜单
    void my_menue(int id);         ///我的应用菜单
};

#endif // CLIENT_H
