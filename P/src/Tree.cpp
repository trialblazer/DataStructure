#include "Tree.h"

// Server.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <windows.h>
#include <process.h>
#include <iostream>
#include "FileLog.h"
#include "time.h"
using namespace std;
#pragma comment(lib,"ws2_32.lib")

//���̵߳��õķ���ֻ��һ��ָ���͵Ĳ�������ʱ����Ҫ������������Զ���һ���ṹ��������Ϊ�ṹ���ֶ�
typedef struct _receiveStruct
{
    SOCKET *Socket;
    FileLog *fileLog;
    _receiveStruct(SOCKET *_socket,FileLog *_fileLog):Socket(_socket),fileLog(_fileLog){}
} ReceiveStruct;

//��ȡ�������ڵ��ַ���
string GetDate(constchar*format)
{
    time_t tm;
    struct tm *now;
    char timebuf[20];
    time(&tm);
    now=localtime(&tm);
    strftime(timebuf,sizeof(timebuf)/sizeof(char),format,now);
    returnstring(timebuf);
}

//���������߳�
void receive(PVOID param)
{
    ReceiveStruct* receiveStruct=(ReceiveStruct*)param;
    char buf[2048];
    int bytes;
    while(1)
    {
        //��������
if((bytes=recv(*receiveStruct->Socket,buf,sizeof(buf),0))==SOCKET_ERROR){
            cout<<"��������ʧ��!\n";
            _endthread();//��ֹ��ǰ�߳�
        }
        buf[bytes]='\0';
        cout<<"�ͻ���˵��"<<buf<<endl;
        receiveStruct->fileLog->Write("�ͻ���    ").WriteLine(GetDate("%Y-%m-%d %H:%M:%S").c_str()).WriteLine(buf);//��¼��������
    }
}


//��ȡ����IP
in_addr getHostName(void)
{
    char host_name[255];
    //��ȡ������������
if (gethostname(host_name, sizeof(host_name)) == SOCKET_ERROR) {
        cout<<"Error %d when getting local host name."<<WSAGetLastError();
        Sleep(3000);
        exit(-1);
    }

    //�����������ݿ��еõ���Ӧ�ġ�IP��
struct hostent *phe = gethostbyname(host_name);
    if (phe ==0) {
        cout<<"Yow! Bad host lookup.";
        Sleep(3000);
        exit(-1);
    }

    struct in_addr addr;
    memcpy(&addr, phe->h_addr_list[0], sizeof(struct in_addr));
    return addr;
}


//����������
SOCKET StartServer(void)
{
    //�����׽���
    SOCKET serverSocket;
    if((serverSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==INVALID_SOCKET){
        cout<<"�����׽���ʧ�ܣ�";
        Sleep(3000);
        exit(-1);
    }
    short port=1986;
    struct sockaddr_in serverAddress;
    //��ʼ��ָ�����ڴ�����
    memset(&serverAddress,0,sizeof(sockaddr_in));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(port);

    //��
if(bind(serverSocket,(sockaddr*)&serverAddress,sizeof(serverAddress))==SOCKET_ERROR){
        cout<<"�׽��ְ󶨵��˿�ʧ�ܣ��˿�:"<<port;
        Sleep(3000);
        exit(-1);
    }

    //��������״̬
if(listen(serverSocket,SOMAXCONN)==SOCKET_ERROR){
        cout<<"����ʧ�ܣ�";
        Sleep(3000);
        exit(-1);
    }

    //��ȡ������IP
struct in_addr addr = getHostName();
    cout<<"Server "<<inet_ntoa(addr)<<" : "<<port<<" is listening......"<<endl;
    return serverSocket;
}


//���տͻ�������
SOCKET ReceiveConnect(SOCKET &serverSocket)
{
    SOCKET clientSocket;//�����Ϳͻ���ͨ�ŵ��׽���
struct sockaddr_in clientAddress;//�����Ϳͻ���ͨ�ŵ��׽��ֵ�ַ
    memset(&clientAddress,0,sizeof(clientAddress));//��ʼ����ſͻ�����Ϣ���ڴ�
int addrlen =sizeof(clientAddress);

    //��������
if((clientSocket=accept(serverSocket,(sockaddr*)&clientAddress,&addrlen))==INVALID_SOCKET){
        cout<<"���ܿͻ�������ʧ�ܣ�";
        Sleep(3000);
        exit(-1);
    }
     cout<<"Accept connection from "<<inet_ntoa(clientAddress.sin_addr)<<endl;
    return clientSocket;
}


//��������
void SendMsg(SOCKET &clientSocket,FileLog &fileLog)
{
    char buf[2048];
    while(1){
        cout<<"������˵��";
        gets_s(buf);
        if(send(clientSocket,buf,strlen(buf),0)==SOCKET_ERROR){
            cout<<"��������ʧ�ܣ�"<<endl;
            Sleep(3000);
            exit(-1);
        }
        fileLog.Write("������   ").WriteLine(GetDate("%Y-%m-%d %H:%M:%S").c_str()).WriteLine(buf);//��¼��������
    }
}


int main(int argc, char* argv[]){
    WSADATA wsa;//WSADATA�ṹ���������溯��WSAStartup���ص�Windows Sockets��ʼ����Ϣ

    //MAKEWORD(a,b)�ǽ�����byte�ͺϲ���һ��word�ͣ�һ���ڸ�8λ(b)��һ���ڵ�8λ(a)
if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){
        cout<<"�׽��ֳ�ʼ��ʧ��!";
        Sleep(3000);
        exit(-1);
    }

    SOCKET serverSocket=StartServer();//����������
    SOCKET clientSocket=ReceiveConnect(serverSocket);//���տͷ��˵�����

    FileLog fileLog;
    fileLog.Open(GetDate("%Y%m%d").append(".log").c_str());//�򿪼�¼���������ļ�

    ReceiveStruct receiveStruct(&clientSocket,&fileLog);
    _beginthread(receive,0,&receiveStruct);//����һ���������ݵ��߳�

    SendMsg(clientSocket,fileLog);//��������

    fileLog.Close();//�ر��ļ�
    closesocket(clientSocket);//�رտͻ����׽��֣����Ϸ���FIN�źţ�����û�н��յ����Ƿ�����ɵ����ݶ��ᶪʧ��
    closesocket(serverSocket);//�رշ������׽���

    //�����׽���ռ�õ���Դ
    WSACleanup();
    return0;
}





































































/*
Tree::Tree()
{
    //ctor
}

Tree::~Tree()
{
    //dtor
}*/
