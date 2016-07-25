/// #include "stdafx.h"

#include <windows.h>
#include <process.h>
#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;
#pragma comment(lib,"ws2_32.lib")

//多线程调用的方法只有一个指针型的参数，有时候需要多个参数，所以定义一个结构，参数作为结构的字段
typedef struct _receiveStruct
{
    SOCKET *Socket;
    _receiveStruct(SOCKET *_socket):Socket(_socket) {}
} ReceiveStruct;


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
            _endthread();
        }
        buf[bytes]='\0';
        cout<<"客户端说："<<buf<<endl;
    }
}


in_addr getHostName(void)
{
    char host_name[255];
    if (gethostname(host_name, sizeof(host_name)) == SOCKET_ERROR)
    {
        cout<<"Error %d when getting local host name."<<WSAGetLastError();
        Sleep(3000);
        exit(-1);
    }
    struct hostent *phe = gethostbyname(host_name);
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
    struct in_addr addr = getHostName();
    cout<<"Server "<<inet_ntoa(addr)<<" : "<<port<<" is listening......"<<endl;
    return serverSocket;
}

SOCKET ReceiveConnect(SOCKET &serverSocket)
{
    SOCKET clientSocket;
    struct sockaddr_in clientAddress;
    memset(&clientAddress,0,sizeof(clientAddress));
    int addrlen =sizeof(clientAddress);

    if((clientSocket=accept(serverSocket,(sockaddr*)&clientAddress,&addrlen))==INVALID_SOCKET)
    {
        cout<<"接受客户端连接失败！";
        Sleep(3000);
        exit(-1);
    }
    cout<<"\nservers Accept connection from "<<inet_ntoa(clientAddress.sin_addr)<<endl;
    return clientSocket;
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

int main(int argc, char* argv[])
{
    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
    {
        cout<<"套接字初始化失败!";
        Sleep(3000);
        exit(-1);
    }

    SOCKET serverSocket=StartServer();
    SOCKET clientSocket=ReceiveConnect(serverSocket);

    ReceiveStruct receiveStruct(&clientSocket);
    _beginthread(receive,0,&receiveStruct);

    SendMsg(clientSocket);

    closesocket(clientSocket);
    closesocket(serverSocket);

    WSACleanup();
    return 0;
}
