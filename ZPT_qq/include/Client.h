#ifndef CLIENT_H
#define CLIENT_H

#include "Server.h"

class Client {
public:
    void menue();

private:
    Server console;
    void user_menue(int id);        ///���˵�
    void group_menue(int id);      ///��˵�
    void mess_menue(int id);       ///�Ự�˵�
    void friend_menue(int id);     ///ȫ�����Ѳ˵�
    void my_menue(int id);         ///�ҵ�Ӧ�ò˵�
};

#endif // CLIENT_H
