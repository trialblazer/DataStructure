/////////////////////////////////////////////////////
// TCPServer.cpp�ļ�
// ���������¼�֪ͨ��Ϣ
#define WM_SOCKET WM_USER + 1
#include "Servers.h"
#include <windows.h>

bool Servers::OnInitDialog()
{
	m_socket = INVALID_SOCKET;
	m_nClient = 0;

	char szHost[256];
	gethostname(szHost, 256);
	HOSTENT* pHost = gethostbyname(szHost);// ͨ����������ȡ�õ�ַ��Ϣ
	if(pHost != NULL)
	{
		CString sIP;
		in_addr *addr =(in_addr*) *(pHost->h_addr_list);// �õ���һ��IP��ַ
		// ��ʾ���û�
		sIP.Format(" ����IP��%s", inet_ntoa(addr[0]));
		m_bar.SetText(sIP, 0, 0);
	}
	return TRUE;
}

void Servers::OnStart()
{
	if(m_socket == INVALID_SOCKET)  // ��������
	{
		// ȡ�ö˿ں�
		int nPort;
		cout << "������˿ںţ�";
		cin >> nPort;
		if(nPort < 1 || nPort > 65535)
		{
			cout << "�˿ںŴ���" << endl;
			Sleep(3000);
			return;
		}
		// ���������׽��֣�ʹ���������״̬
		if(!CreateAndListen(nPort))
		{
			cout << "�����������" << endl;
			Sleep(3000);
			return;
		}
		cout << " ���ڼ�������" << endl;
	}
	else				// ֹͣ����
	{
		CloseAllSocket();// �ر���������
		// ��������Ӵ��ڿؼ�״̬
		///GetDlgItem(IDC_START)->SetWindowText("��������");
		//m_bar.SetText(" ����", 0, 0);
	}
}

void Servers::OnCancel()
{
	CloseAllSocket();
	CDialog::OnCancel();
}

void Servers::OnClear()
{
	m_listInfo.ResetContent();
}

long Servers::OnSocket(WPARAM wParam, LPARAM lParam)
{
	// ȡ�����¼��������׽��־��
	SOCKET s = wParam;
	// �鿴�Ƿ����
	if(WSAGETSELECTERROR(lParam))
	{
		RemoveClient(s);
		::closesocket(s);
		return 0;
	}
	// ���������¼�
	switch(WSAGETSELECTEVENT(lParam))
	{
	case FD_ACCEPT:		// �����е��׽��ּ�⵽�����ӽ���
		{
			if(m_nClient < MAX_SOCKET)
			{
				// �������������µ��׽���client�������ӵ��׽���
				SOCKET client = ::accept(s, NULL, NULL);
				// �����µ��׽���Ϊ����֪ͨ��Ϣ����
				int i = ::WSAAsyncSelect(client,
					m_hWnd, WM_SOCKET, FD_READ|FD_WRITE|FD_CLOSE);
				AddClient(client);
			}
			else
			{
				MessageBox("���ӿͻ�̫�࣡");
			}
		}
		break;

	case FD_CLOSE:		// ��⵽�׽��ֶ�Ӧ�����ӱ��رա�
		{
			RemoveClient(s);
			::closesocket(s);
		}
		break;

	case FD_READ:		// �׽��ֽ��ܵ��Է����͹��������ݰ�
		{

				// ȡ�öԷ���IP��ַ�Ͷ˿ںţ�ʹ��getpeername������
			// Peer�Է��ĵ�ַ��Ϣ
			sockaddr_in sockAddr;
			memset(&sockAddr, 0, sizeof(sockAddr));
			int nSockAddrLen = sizeof(sockAddr);
			::getpeername(s, (SOCKADDR*)&sockAddr, &nSockAddrLen);
			// ת��Ϊ�����ֽ�˳��
			int nPeerPort = ::ntohs(sockAddr.sin_port);
			// ת��Ϊ�ַ���IP
			CString sPeerIP = ::inet_ntoa(sockAddr.sin_addr);

				// ȡ�öԷ�����������
			// ȡ�������ֽ�˳���IPֵ
			DWORD dwIP = ::inet_addr(sPeerIP);
			// ��ȡ�������ƣ�ע�����е�һ��������ת��
			hostent* pHost = ::gethostbyaddr((LPSTR)&dwIP, 4, AF_INET);
			char szHostName[256];
			strncpy(szHostName, pHost->h_name, 256);

			// ������������������
			char szText[1024] = { 0 };
			::recv(s, szText, 1024, 0);
			// ��ʾ���û�
			CString strItem = CString(szHostName) + "["+ sPeerIP+ "]: " + CString(szText);
			m_listInfo.InsertString(0, strItem);
		}
		break;
	}
	return 0;
}


BOOL Servers::CreateAndListen(int nPort)
{
	if(m_socket == INVALID_SOCKET)
		::closesocket(m_socket);
	m_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(m_socket == INVALID_SOCKET)
		return FALSE;

	// ��дҪ�����ı��ص�ַ
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(nPort);
	sin.sin_addr.s_addr = INADDR_ANY;
	if(::bind(m_socket, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		return FALSE;
	}

	// ����socketΪ����֪ͨ��Ϣ����
	//::WSAAsyncSelect(m_socket, m_hWnd, WM_SOCKET, FD_ACCEPT|FD_CLOSE);
	// �������ģʽ
	::listen(m_socket, 5);

	return TRUE;
}


BOOL Servers::AddClient(SOCKET s)
{
	if(m_nClient < MAX_SOCKET)
	{
		// ����µĳ�Ա
		m_arClient[m_nClient++] = s;
		return TRUE;
	}
	return FALSE;
}

void Servers::RemoveClient(SOCKET s)
{
	BOOL bFind = FALSE;
	for(int i=0; i<m_nClient; i++)
	{
		if(m_arClient[i] == s)
		{
			bFind = TRUE;
			break;
		}
	}
	if(bFind)
	{
		m_nClient--;
		for(int j=i; j<m_nClient; j++)
		{
			m_arClient[j] = m_arClient[j+1];
		}
	}
}

void CMainDialog::CloseAllSocket()
{
	if(m_socket != INVALID_SOCKET)
	{
		::closesocket(m_socket);
		m_socket = INVALID_SOCKET;
	}
	for(int i=0; i<m_nClient; i++)
		::closesocket(m_arClient[i]);
	m_nClient = 0;
}

