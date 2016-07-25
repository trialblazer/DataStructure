/// #include "stdafx.h"

#include <windows.h>
#include <process.h>
#include <iostream>
#include <stdio.h>
#include "FileLog.h"
#include "Client.h"
#include <ctime>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

//���̵߳��õķ���ֻ��һ��ָ���͵Ĳ�������ʱ����Ҫ������������Զ���һ���ṹ��������Ϊ�ṹ���ֶ�
typedef struct _receiveStruct
{
    SOCKET *Socket;
    bool isconnect;
    _receiveStruct(SOCKET *_socket, bool bo):Socket(_socket), isconnect(bo) {}
} ReceiveStruct;

string GetDate(const char*format)
{
    time_t tm;
    struct tm *now;
    char timebuf[20];
    time(&tm);
    now=localtime(&tm);
    strftime(timebuf,sizeof(timebuf)/sizeof(char),format,now);
    return string(timebuf);
}

void receive(PVOID param)
{
    ReceiveStruct* receiveStruct=(ReceiveStruct*)param;
    char buf[2048];
    int bytes;
    while(1)
    {
        if((bytes=recv(*receiveStruct->Socket,buf,sizeof(buf),0))==SOCKET_ERROR)
        {
            cout<<"��������ʧ��!\n";
            receiveStruct->isconnect = false;
            _endthread();//��ֹ��ǰ�߳�
        }
        buf[bytes]='\0';
        cout<<"�ͻ���˵��"<<buf<<endl;
    }
}

void SendMsg(SOCKET &clientSocket)
{
    char buf[2048];
    while(1)
    {
        cout<<"������˵��";
        gets(buf);
        if(send(clientSocket,buf,strlen(buf),0)==SOCKET_ERROR)
        {
            cout<<"��������ʧ�ܣ�"<<endl;
            Sleep(3000);
            exit(-1);
        }
    }
}

in_addr getHostName()
{
    char host_name[255];
    if (gethostname(host_name, sizeof(host_name)) == SOCKET_ERROR)
    {
        cout<<"Error %d when getting local host name."<<WSAGetLastError();
        Sleep(3000);
        exit(-1);
    }
    struct hostent *phe = gethostbyname(host_name); //�����������ݿ��еõ���Ӧ�ġ�IP��
    if (phe ==0)
    {
        cout<<"Yow! Bad host lookup.";
        Sleep(3000);
        exit(-1);
    }
    struct in_addr addr;
    memcpy(&addr, phe->h_addr_list[0], sizeof(struct in_addr));
    return addr;
}

SOCKET StartServer(void)
{
    SOCKET serverSocket;
    if((serverSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==INVALID_SOCKET)
    {
        cout<<"�����׽���ʧ�ܣ�";
        Sleep(3000);
        exit(-1);
    }
    short port=1986;
    struct sockaddr_in serverAddress;
    memset(&serverAddress,0,sizeof(sockaddr_in));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(port);

    if(bind(serverSocket,(sockaddr*)&serverAddress,sizeof(serverAddress))==SOCKET_ERROR)
    {
        cout<<"�׽��ְ󶨵��˿�ʧ�ܣ��˿�:"<<port;
        Sleep(3000);
        exit(-1);
    }
    if(listen(serverSocket,SOMAXCONN)==SOCKET_ERROR)
    {
        cout<<"����ʧ�ܣ�";
        Sleep(3000);
        exit(-1);
    }
    struct in_addr addr = getHostName(); //���ر��������ı�׼������
    cout<<"Server "<<inet_ntoa(addr)<<" : "<<port<<" is listening......"<<endl;
    return serverSocket;
}

typedef struct Receive_connect
{
    SOCKET serversocket;
    SOCKET clientsocket;
    char bf[100];
    bool is_connect;
    Receive_connect(SOCKET& s, SOCKET& ps, char* b, bool p):serversocket(s), clientsocket(ps), is_connect(p)
    {
        strcpy(bf, b);
    }
} Receive_connect;

void ReceiveConnect(PVOID parm)
{
    while(1)
    {
        Receive_connect* receive_connect = (Receive_connect*)parm;
        receive_connect->is_connect = false;
        struct sockaddr_in clientAddress;//�����Ϳͻ���ͨ�ŵ��׽��ֵ�ַ
        memset(&clientAddress,0,sizeof(clientAddress));//��ʼ����ſͻ�����Ϣ���ڴ�
        int addrlen =sizeof(clientAddress);
        if((receive_connect->clientsocket=accept(receive_connect->serversocket,(sockaddr*)&clientAddress,&addrlen))==INVALID_SOCKET)
        {
            cout<<"���ܿͻ�������ʧ�ܣ�";
            Sleep(3000);
            exit(-1);
        }
        strcpy(receive_connect->bf, inet_ntoa(clientAddress.sin_addr));
        cout<<"\nservers Accept connection from "<<receive_connect->bf<<endl;
        receive_connect->is_connect = true;
    }
}





int main(int argc, char* argv[])
{
    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
    {
        cout<<"�׽��ֳ�ʼ��ʧ��!";
        Sleep(3000);
        exit(-1);
    }
    char bf[100];
    SOCKET serverSocket=StartServer();
    SOCKET clientSocket;
    bool is_connect = false;

    Receive_connect receive_connect(serverSocket, clientSocket, bf, is_connect);
    _beginthread(ReceiveConnect, 0, &receive_connect);
loop1:if (receive_connect.is_connect) {
        cout << "client ip: " << bf << endl;
        while(1) {
            bool isconnect = true;
            ReceiveStruct receiveStruct(&clientSocket, isconnect);
            cout << "client ip: " << bf << endl;
            _beginthread(receive,0,&receiveStruct);//���ݸ��̵߳Ĳ����б��޲���ʱΪNULL
            if (!(receiveStruct.isconnect)) {
                cout << bf << " break line!" << endl;
                goto loop1;
            }
            SendMsg(clientSocket);//��������
        }
    }
    goto loop1;
    closesocket(clientSocket);
    closesocket(serverSocket);
    //�����׽���ռ�õ���Դ
    WSACleanup();
    return 0;
}

















