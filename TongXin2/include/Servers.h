#ifndef SERVERS_H
#define SERVERS_H


//#include <afxwin.h>		// 10TCPServer
//#include <afxcmn.h>
#include <winsock2.h>

// ������������WS2_32������
#pragma comment(lib,"WS2_32.lib")

#define MAX_SOCKET 56	// ����˷��������ܽ��ܵ����ͻ���


class Servers
{
protected:
	BOOL CreateAndListen(int nPort);// �����׽��֣�������Ϊ����״̬��׼�����ܿͻ�������
	void CloseAllSocket();// �ر������׽��֣����������׽��ֺ�����accept�������ص��׽���
	BOOL AddClient(SOCKET s);// ��ͻ������б������һ���ͻ�
	void RemoveClient(SOCKET s);// �ӿͻ������б����ƴ�һ���ͻ�

protected:
	SOCKET m_socket;// �����׽��־��
	SOCKET m_arClient[MAX_SOCKET];	// �׽�������// �ͻ������б�
	int m_nClient;			// ��������Ĵ�С

protected:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	// ������ֹͣ����
	afx_msg void OnStart();
	// �����Ϣ
	afx_msg void OnClear();
	// �׽���֪ͨ�¼�
	afx_msg long OnSocket(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#endif // SERVERS_H
