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
    User* find_(char account[9]);       ///����û��ļ����Ƿ����˺�Ϊaccount���û�
    bool login(char* a, string p);      ///���ڼ���û���½
    bool add_user();                    ///���ļ�User.txt��������û�

    bool add_client(Basic_inform new_); ///�������û�������������û�
    bool remove_client(string ip);      ///�������û�������ɾ��iP���û�
    bool check(string account);         ///����˺�account�Ƿ��Ѿ���½

    void prin_news();    ///����
    void prin_secret();  ///����ǽ

    void receive(string ip);    ///�����û�������Ӧ
    void send(string ip);       ///������Ϣ
    void send_all(int i);       ///�����û�Ҫ�����ҳ��

public:
    bool CreateAndListen(int nPort); ///�����׽��֣�������Ϊ����״̬��׼�����ܿͻ�������
    void CloseAllSocket();           ///�ر������׽���
    bool AddClient(SOCKET s);        /// ��ͻ������б������һ���ͻ�
	void RemoveClient(SOCKET s);     /// �ӿͻ������б����ƴ�һ���ͻ�

public:
    string GetDate(const char*format);

    ///���ڼ�⣺
public:
    void printf_();  ///��ӡ�����û�

private:
    User user;
    User* puser;

    SOCKET serverSocket;   ///�����׽���
    SOCKET clientsocket[MaxClient];
    int current_size;

    list<Basic_inform> Client_list;     ///�����û��б�
    list<Basic_inform> Secret_client;   ///���������б�

private:
    void init_servers();            ///��ʼ��������
    in_addr getHostName(void);      ///��ȡ����IP
    SOCKET ReceiveConnect(SOCKET &serverSocket, char bf[]);     ///���տͻ�������

    typedef struct _receiveStruct {
        SOCKET *Socket;
        _receiveStruct(SOCKET *_socket):Socket(_socket) {}
    } ReceiveStruct;
};


/// _beginthread(receive,0,&receiveStruct);//����һ���������ݵ��߳�
///SendMsg(clientSocket,fileLog);//��������

#endif // FILE_LOG_H
