#include "File_log.h"
#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

File_log::File_log() {
    FILE *fp;
    if ((fp=fopen("User.txt", "rb")) == NULL) {
        fp = fopen("User.txt", "wb");
        fclose(fp);
    }
    fclose(fp);
    if ((fp=fopen("Institute.txt", "rb")) == NULL) {
        fp = fopen("Institute.txt", "wb");
        fclose(fp);
    }
    fclose(fp);
    if ((fp=fopen("News.txt", "rb")) == NULL) {
        fp = fopen("New.txt", "wb");
        fclose(fp);
    }
    fclose(fp);
    if ((fp=fopen("Secret.txt", "rb")) == NULL) {
        fp = fopen("Secret.txt", "wb");
        fclose(fp);
    }
    fclose(fp);

    init_servers();
}

bool File_log::login(char* a, string p) {
    find_(a);
    bool sign = false;
    if(puser != NULL) {
        if (puser->passwords == p) {
            sign = true;
        }
    }
    delete puser;
    return sign;
}

File_log::~File_log() {
    closesocket(clientSocket);//关闭客户端套接字
    closesocket(serverSocket);//关闭服务器套接字
    WSACleanup();//清理套接字占用的资源
}



User* File_log::find_(char a[]) {
    FILE* fp;
    if ((fp=fopen("User.txt", "rb")) == NULL)
        return NULL;
    puser = new User;
    while (1) {
        fread(&(*puser), sizeof(User), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return NULL;
        }
        if (strcmp(puser->inform.account, a) == 0) {
            fclose(fp);
            return puser;
        }
    }
}

bool File_log::add_user() {
    FILE* fp;
    if ((fp=fopen("User.txt", "ab")) == NULL)
        return NULL;
    cout << "account:";
    cin >> user.inform.account;
    user.passwords = "000000";
    if (fwrite(&user, sizeof(User), 1, fp) != 1)
			return false;
    fclose(fp);
    return true;
}



//获取本机IP
in_addr File_log::getHostName(void) {
    char host_name[255];//获取本地主机名称
    if (gethostname(host_name, sizeof(host_name)) == SOCKET_ERROR) {
        cout<<"Error %d when getting local host name."<<WSAGetLastError();
        Sleep(3000);
        exit(-1);
    }
    struct hostent *phe = gethostbyname(host_name); //从主机名数据库中得到对应的“IP”
    if (phe ==0) {
        cout<<"Yow! Bad host lookup.";
        Sleep(3000);
        exit(-1);
    }
    struct in_addr addr;
    memcpy(&addr, phe->h_addr_list[0], sizeof(struct in_addr));
    return addr;
}





//接收客户端连接
SOCKET File_log::ReceiveConnect(SOCKET &serverSocket, char bf[])
{
    SOCKET clientSocket;//用来和客户端通信的套接字
    struct sockaddr_in clientAddress;//用来和客户端通信的套接字地址
    memset(&clientAddress,0,sizeof(clientAddress));//初始化存放客户端信息的内存
    int addrlen =sizeof(clientAddress);
    if((clientSocket=accept(serverSocket,(sockaddr*)&clientAddress,&addrlen))==INVALID_SOCKET) {
        cout<<"接受客户端连接失败！";
        Sleep(3000);
        exit(-1);
    }
    strcpy(bf, inet_ntoa(clientAddress.sin_addr));
    cout<<"\nservers Accept connection from "<<bf<<endl;
    return clientSocket;
}


string File_log::GetDate(const char*format) {
    time_t tm;
    struct tm *now;
    char timebuf[20];
    time(&tm);
    now=localtime(&tm);
    strftime(timebuf,sizeof(timebuf)/sizeof(char),format,now);
    return string(timebuf);
}

void File_log::printf_() {
    FILE* fp;
    if ((fp=fopen("User.txt", "rb")) == NULL)
        return;
    int n = 1;
    while (1) {
        fread(&user, sizeof(User), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        cout << n++ << "  :  "<< user.inform.account << endl;
    }
}

void File_log::init_servers() {
    WSADATA wsa;//WSADATA结构被用来保存函数WSAStartup返回的Windows Sockets初始化信息
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0) {
        cout<<"套接字初始化失败!";
        Sleep(3000);  //挂起一段时间，单位为毫秒
        exit(-1);
    }
    char bf[100];
    if (CreateAndListen()) {

    }
    serverSocket=StartServer();//启动服务器
    clientSocket=ReceiveConnect(serverSocket, bf);//接收客服端的链接
    ReceiveStruct receiveStruct(&clientSocket);
}


bool File_log::CreateAndListen(int nPort)
{
	if(serverSocket == INVALID_SOCKET)
		closesocket(serverSocket);
	if((serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		return false;
	struct sockaddr_in serverAddress;// 填写要关联的本地地址
    memset(&serverAddress,0,sizeof(sockaddr_in));//初始化指定的内存区域
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//你要绑定【bind】到本地的IP地址上进行监听【listen】，但是你的机器上可能有多块网卡，也就有多个IP地址，这时候你要选择绑定在哪个IP上面，如果指定为INADDR_ANY，那么系统将绑定默认的网卡【即IP地址】。
    serverAddress.sin_port = htons(nport);

	if(bind(m_socket, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
		return false;
    if (listen(serverSocket,SOMAXCONN)==SOCKET_ERROR)
        return false;
	return true;
}

bool File_log::AddClient(SOCKET s)
{
	if(current_size < MaxClient) {
		serverSocket[current_size++] = s;
		return true;
	}
	return false;
}

void File_log::RemoveClient(SOCKET s)
{
	bool bFind = false;
	for(int i=0; i<m_nClient; i++) {
		if(clientsocket[i] == s) {
			bFind = true;
			break;
		}
	}
	if(bFind) {
		current_size--;
		for(int j=i; j<current_size; j++)
			clientsocket[j] = clientsocket[j+1];
	}
}

void File_log::CloseAllSocket()
{
	if(serverSocket != INVALID_SOCKET) {
		closesocket(serverSocket);
		serverSocket = INVALID_SOCKET;
	}
	for(int i=0; i<current_size; i++)
		closesocket(serverSocket[i]);
	current_size = 0;
}

















































