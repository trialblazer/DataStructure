#ifndef SERVERS_H
#define SERVERS_H


//#include <afxwin.h>		// 10TCPServer
//#include <afxcmn.h>
#include <winsock2.h>

// 告诉连接器与WS2_32库连接
#pragma comment(lib,"WS2_32.lib")

#define MAX_SOCKET 56	// 定义此服务器所能接受的最大客户量


class Servers
{
protected:
	BOOL CreateAndListen(int nPort);// 创建套节字，并设置为监听状态，准备接受客户的连接
	void CloseAllSocket();// 关闭所有套节字，包括监听套节字和所有accept函数返回的套节字
	BOOL AddClient(SOCKET s);// 向客户连接列表中添加一个客户
	void RemoveClient(SOCKET s);// 从客户连接列表中移处一个客户

protected:
	SOCKET m_socket;// 监听套节字句柄
	SOCKET m_arClient[MAX_SOCKET];	// 套节字数组// 客户连接列表
	int m_nClient;			// 上述数组的大小

protected:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	// 开启或停止服务
	afx_msg void OnStart();
	// 清空信息
	afx_msg void OnClear();
	// 套节字通知事件
	afx_msg long OnSocket(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#endif // SERVERS_H
