/////////////////////////////////////////////////////
// TCPServer.cpp文件
// 定义网络事件通知消息
#define WM_SOCKET WM_USER + 1
#include "Servers.h"
#include <windows.h>

bool Servers::OnInitDialog()
{
	m_socket = INVALID_SOCKET;
	m_nClient = 0;

	char szHost[256];
	gethostname(szHost, 256);
	HOSTENT* pHost = gethostbyname(szHost);// 通过本机名称取得地址信息
	if(pHost != NULL)
	{
		CString sIP;
		in_addr *addr =(in_addr*) *(pHost->h_addr_list);// 得到第一个IP地址
		// 显示给用户
		sIP.Format(" 本机IP：%s", inet_ntoa(addr[0]));
		m_bar.SetText(sIP, 0, 0);
	}
	return TRUE;
}

void Servers::OnStart()
{
	if(m_socket == INVALID_SOCKET)  // 开启服务
	{
		// 取得端口号
		int nPort;
		cout << "请输入端口号：";
		cin >> nPort;
		if(nPort < 1 || nPort > 65535)
		{
			cout << "端口号错误！" << endl;
			Sleep(3000);
			return;
		}
		// 创建监听套节字，使它进入监听状态
		if(!CreateAndListen(nPort))
		{
			cout << "启动服务出错！" << endl;
			Sleep(3000);
			return;
		}
		cout << " 正在监听……" << endl;
	}
	else				// 停止服务
	{
		CloseAllSocket();// 关闭所有连接
		// 设置相关子窗口控件状态
		///GetDlgItem(IDC_START)->SetWindowText("开启服务");
		//m_bar.SetText(" 空闲", 0, 0);
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
	// 取得有事件发生的套节字句柄
	SOCKET s = wParam;
	// 查看是否出错
	if(WSAGETSELECTERROR(lParam))
	{
		RemoveClient(s);
		::closesocket(s);
		return 0;
	}
	// 处理发生的事件
	switch(WSAGETSELECTEVENT(lParam))
	{
	case FD_ACCEPT:		// 监听中的套接字检测到有连接进入
		{
			if(m_nClient < MAX_SOCKET)
			{
				// 接受连接请求，新的套节字client是新连接的套节字
				SOCKET client = ::accept(s, NULL, NULL);
				// 设置新的套节字为窗口通知消息类型
				int i = ::WSAAsyncSelect(client,
					m_hWnd, WM_SOCKET, FD_READ|FD_WRITE|FD_CLOSE);
				AddClient(client);
			}
			else
			{
				MessageBox("连接客户太多！");
			}
		}
		break;

	case FD_CLOSE:		// 检测到套接字对应的连接被关闭。
		{
			RemoveClient(s);
			::closesocket(s);
		}
		break;

	case FD_READ:		// 套接字接受到对方发送过来的数据包
		{

				// 取得对方的IP地址和端口号（使用getpeername函数）
			// Peer对方的地址信息
			sockaddr_in sockAddr;
			memset(&sockAddr, 0, sizeof(sockAddr));
			int nSockAddrLen = sizeof(sockAddr);
			::getpeername(s, (SOCKADDR*)&sockAddr, &nSockAddrLen);
			// 转化为主机字节顺序
			int nPeerPort = ::ntohs(sockAddr.sin_port);
			// 转化为字符串IP
			CString sPeerIP = ::inet_ntoa(sockAddr.sin_addr);

				// 取得对方的主机名称
			// 取得网络字节顺序的IP值
			DWORD dwIP = ::inet_addr(sPeerIP);
			// 获取主机名称，注意其中第一个参数的转化
			hostent* pHost = ::gethostbyaddr((LPSTR)&dwIP, 4, AF_INET);
			char szHostName[256];
			strncpy(szHostName, pHost->h_name, 256);

			// 接受真正的网络数据
			char szText[1024] = { 0 };
			::recv(s, szText, 1024, 0);
			// 显示给用户
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

	// 填写要关联的本地地址
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(nPort);
	sin.sin_addr.s_addr = INADDR_ANY;
	if(::bind(m_socket, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		return FALSE;
	}

	// 设置socket为窗口通知消息类型
	//::WSAAsyncSelect(m_socket, m_hWnd, WM_SOCKET, FD_ACCEPT|FD_CLOSE);
	// 进入监听模式
	::listen(m_socket, 5);

	return TRUE;
}


BOOL Servers::AddClient(SOCKET s)
{
	if(m_nClient < MAX_SOCKET)
	{
		// 添加新的成员
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

