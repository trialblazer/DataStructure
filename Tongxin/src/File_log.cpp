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
    closesocket(clientSocket);//�رտͻ����׽���
    closesocket(serverSocket);//�رշ������׽���
    WSACleanup();//�����׽���ռ�õ���Դ
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



//��ȡ����IP
in_addr File_log::getHostName(void) {
    char host_name[255];//��ȡ������������
    if (gethostname(host_name, sizeof(host_name)) == SOCKET_ERROR) {
        cout<<"Error %d when getting local host name."<<WSAGetLastError();
        Sleep(3000);
        exit(-1);
    }
    struct hostent *phe = gethostbyname(host_name); //�����������ݿ��еõ���Ӧ�ġ�IP��
    if (phe ==0) {
        cout<<"Yow! Bad host lookup.";
        Sleep(3000);
        exit(-1);
    }
    struct in_addr addr;
    memcpy(&addr, phe->h_addr_list[0], sizeof(struct in_addr));
    return addr;
}





//���տͻ�������
SOCKET File_log::ReceiveConnect(SOCKET &serverSocket, char bf[])
{
    SOCKET clientSocket;//�����Ϳͻ���ͨ�ŵ��׽���
    struct sockaddr_in clientAddress;//�����Ϳͻ���ͨ�ŵ��׽��ֵ�ַ
    memset(&clientAddress,0,sizeof(clientAddress));//��ʼ����ſͻ�����Ϣ���ڴ�
    int addrlen =sizeof(clientAddress);
    if((clientSocket=accept(serverSocket,(sockaddr*)&clientAddress,&addrlen))==INVALID_SOCKET) {
        cout<<"���ܿͻ�������ʧ�ܣ�";
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
    WSADATA wsa;//WSADATA�ṹ���������溯��WSAStartup���ص�Windows Sockets��ʼ����Ϣ
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0) {
        cout<<"�׽��ֳ�ʼ��ʧ��!";
        Sleep(3000);  //����һ��ʱ�䣬��λΪ����
        exit(-1);
    }
    char bf[100];
    if (CreateAndListen()) {

    }
    serverSocket=StartServer();//����������
    clientSocket=ReceiveConnect(serverSocket, bf);//���տͷ��˵�����
    ReceiveStruct receiveStruct(&clientSocket);
}


bool File_log::CreateAndListen(int nPort)
{
	if(serverSocket == INVALID_SOCKET)
		closesocket(serverSocket);
	if((serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		return false;
	struct sockaddr_in serverAddress;// ��дҪ�����ı��ص�ַ
    memset(&serverAddress,0,sizeof(sockaddr_in));//��ʼ��ָ�����ڴ�����
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//��Ҫ�󶨡�bind�������ص�IP��ַ�Ͻ��м�����listen����������Ļ����Ͽ����ж��������Ҳ���ж��IP��ַ����ʱ����Ҫѡ������ĸ�IP���棬���ָ��ΪINADDR_ANY����ôϵͳ����Ĭ�ϵ���������IP��ַ����
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

















































