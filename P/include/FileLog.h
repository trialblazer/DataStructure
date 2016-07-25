#ifndef FILELOG_H
#define FILELOG_H

#include "iostream"
#include "string.h"
#include <windows.h>

using namespace std;

class FileLog
{
private:
    CRITICAL_SECTION cs;
    HANDLE fileHandle;
    void Lock()
    {
        EnterCriticalSection(&cs);// �����ٽ���
    }

    void UnLock()
    {
        LeaveCriticalSection(&cs);//�뿪�ٽ���
    }

public:
    FileLog()
    {
        InitializeCriticalSection(&cs);//��ʼ���ٽ���
        fileHandle=INVALID_HANDLE_VALUE;//�ȳ�ʼ��Ϊ����ľ��
    }

    ~FileLog()
    {
        if(fileHandle!=INVALID_HANDLE_VALUE)
        {
            //CloseHandle�Ĺ����ǹر�һ���򿪵Ķ��������ö������������߳̾����Ҳ�����ǽ��̡��ź����������ں˶���ľ��
            CloseHandle(fileHandle);
        }
        DeleteCriticalSection(&cs);//ɾ���ٽ���
    }

    BOOL Open(const char*fileName);//���ļ�
    FileLog& Write(const char*content);//���ļ���д������
    FileLog& WriteLine(const char*content);//���ļ���д������
    BOOL Read(char*buf,int size);//���ļ�����
    BOOL Close();//�ر��ļ�
};

#endif // FILELOG_H
