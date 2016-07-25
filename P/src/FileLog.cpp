#include "FileLog.h"
/// #include "stdafx.h"

//���ļ�
BOOL FileLog::Open(const char*fileName)
{
    if(fileHandle==INVALID_HANDLE_VALUE)
    {
        fileHandle=CreateFile(fileName,GENERIC_WRITE|GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,
                              OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
        if(fileHandle!=INVALID_HANDLE_VALUE)
        {
            SetFilePointer(fileHandle,0,NULL,FILE_END);
            return TRUE;
        }
    }
    return FALSE;
}

//д�ļ� ���ص�ǰ��������ã�ʵ�����Ӳ���
FileLog& FileLog::Write(const char*content)
{
    Lock();
    if(fileHandle!=INVALID_HANDLE_VALUE)
    {
        DWORD dwSize=0;
        WriteFile(fileHandle,content,strlen(content),&dwSize,NULL);//д
    }
    //��ʼ��ʱ����д����䣬���ڼӵ���û���ͷţ�һ���߳�ռ��֮�󣬵��������߳�ֻ��һֱ�ȴ����þö�û���ҵ�ԭ��
    UnLock();
    return*this;
}

//д��һ��
FileLog& FileLog::WriteLine(const char*content)
{
    Lock();
    if(fileHandle!=INVALID_HANDLE_VALUE)
    {
        DWORD dwSize=0;
        WriteFile(fileHandle,content,strlen(content),&dwSize,NULL);//д
    }
    UnLock();
    return FileLog::Write("\r\n");
}

//���ļ�����
BOOL FileLog::Read(char*buf,int size)
{
    BOOL isOK=FALSE;
    Lock();
    if(fileHandle!=INVALID_HANDLE_VALUE)
    {
        DWORD dwSize=0;
        isOK=ReadFile(fileHandle,buf,size,&dwSize,NULL);//��
    }
    return isOK;
}

//�ر��ļ�
BOOL FileLog::Close()
{
    BOOL isOK=FALSE;
    Lock();
    if(fileHandle!=INVALID_HANDLE_VALUE)
    {
        isOK=CloseHandle(fileHandle);
        fileHandle=INVALID_HANDLE_VALUE;
    }
    UnLock();
    return isOK;
}
