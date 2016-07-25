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

//多线程调用的方法只有一个指针型的参数，有时候需要多个参数，所以定义一个结构，参数作为结构的字段
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
            cout<<"接收数据失败!\n";
            receiveStruct->isconnect = false;
            _endthread();//终止当前线程
        }
        buf[bytes]='\0';
        cout<<"客户端说："<<buf<<endl;
    }
}

void SendMsg(SOCKET &clientSocket)
{
    char buf[2048];
    while(1)
    {
        cout<<"服务器说：";
        gets(buf);
        if(send(clientSocket,buf,strlen(buf),0)==SOCKET_ERROR)
        {
            cout<<"发送数据失败！"<<endl;
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
    struct hostent *phe = gethostbyname(host_name); //从主机名数据库中得到对应的“IP”
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
        cout<<"创建套接字失败！";
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
        cout<<"套接字绑定到端口失败！端口:"<<port;
        Sleep(3000);
        exit(-1);
    }
    if(listen(serverSocket,SOMAXCONN)==SOCKET_ERROR)
    {
        cout<<"侦听失败！";
        Sleep(3000);
        exit(-1);
    }
    struct in_addr addr = getHostName(); //返回本地主机的标准主机名
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
        struct sockaddr_in clientAddress;//用来和客户端通信的套接字地址
        memset(&clientAddress,0,sizeof(clientAddress));//初始化存放客户端信息的内存
        int addrlen =sizeof(clientAddress);
        if((receive_connect->clientsocket=accept(receive_connect->serversocket,(sockaddr*)&clientAddress,&addrlen))==INVALID_SOCKET)
        {
            cout<<"接受客户端连接失败！";
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
        cout<<"套接字初始化失败!";
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
            _beginthread(receive,0,&receiveStruct);//传递给线程的参数列表，无参数时为NULL
            if (!(receiveStruct.isconnect)) {
                cout << bf << " break line!" << endl;
                goto loop1;
            }
            SendMsg(clientSocket);//发送数据
        }
    }
    goto loop1;
    closesocket(clientSocket);
    closesocket(serverSocket);
    //清理套接字占用的资源
    WSACleanup();
    return 0;
}

















