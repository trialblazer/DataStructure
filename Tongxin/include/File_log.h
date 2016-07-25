#ifndef FILE_LOG_H
#define FILE_LOG_H

#include <list>
#include <windows.h>
#include <string>

#define MaxClient 200
using namespace std;

class Basic_inform {
public:

    char account[9];
    char ip[30];
    bool isOnline;

public:
    Basic_inform() {
        isOnline = false;
        memset(ip, 0, sizeof(ip));
        memset(account, 0, sizeof(account));
    }
    ~Basic_inform() {}
};

class Major {
public:

    string name;
    int class_num;
public:
    Major() {
        name = "";
        class_num = 0;
    }
    ~Major() {}
};

class Insitute {
public:
    string inst_name;
    list<Major> major;

public:
    Insitute():inst_name("") {}
    ~Insitute() {}
};

class User {
public:
    string passwords;
    Basic_inform inform;
    unsigned short Class;
    string institute;
    string major;

    User() {
        Class = 0;
        institute = "";
        major = "";
    }
    ~User() {}

};

class File_log {
public:
    File_log();
    ~File_log();
    User* find_(char account[9]);       ///检查用户文件中是否有账号为account的用户
    bool login(char* a, string p);      ///用于检查用户登陆
    bool add_user();                    ///向文件User.txt中添加新用户

    bool add_client(Basic_inform new_); ///向在线用户链表中添加新用户
    bool remove_client(string ip);      ///在在线用户链表中删除iP的用户
    bool check(string account);         ///检查账号account是否已经登陆

    void prin_news();    ///新闻
    void prin_secret();  ///秘密墙

    void receive(string ip);    ///接受用户各种响应
    void send(string ip);       ///发送消息
    void send_all(int i);       ///根据用户要求更新页面

public:
    bool CreateAndListen(int nPort); ///创建套节字，并设置为监听状态，准备接受客户的连接
    void CloseAllSocket();           ///关闭所有套接字
    bool AddClient(SOCKET s);        /// 向客户连接列表中添加一个客户
	void RemoveClient(SOCKET s);     /// 从客户连接列表中移处一个客户

public:
    string GetDate(const char*format);

    ///用于检测：
public:
    void printf_();  ///打印所有用户

private:
    User user;
    User* puser;

    SOCKET serverSocket;   ///监听套接字
    SOCKET clientsocket[MaxClient];
    int current_size;

    list<Basic_inform> Client_list;     ///在线用户列表
    list<Basic_inform> Secret_client;   ///匿名聊天列表

private:
    void init_servers();            ///初始化服务器
    in_addr getHostName(void);      ///获取本机IP
    SOCKET ReceiveConnect(SOCKET &serverSocket, char bf[]);     ///接收客户端连接

    typedef struct _receiveStruct {
        SOCKET *Socket;
        _receiveStruct(SOCKET *_socket):Socket(_socket) {}
    } ReceiveStruct;
};


/// _beginthread(receive,0,&receiveStruct);//启动一个接收数据的线程
///SendMsg(clientSocket,fileLog);//发送数据

#endif // FILE_LOG_H
