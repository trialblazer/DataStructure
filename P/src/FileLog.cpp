#include "FileLog.h"
/// #include "stdafx.h"

//打开文件
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

//写文件 返回当前对象的引用，实现连接操作
FileLog& FileLog::Write(const char*content)
{
    Lock();
    if(fileHandle!=INVALID_HANDLE_VALUE)
    {
        DWORD dwSize=0;
        WriteFile(fileHandle,content,strlen(content),&dwSize,NULL);//写
    }
    //开始的时候少写了这句，由于加的锁没有释放，一个线程占用之后，导致其他线程只能一直等待，好久都没有找到原因。
    UnLock();
    return*this;
}

//写入一行
FileLog& FileLog::WriteLine(const char*content)
{
    Lock();
    if(fileHandle!=INVALID_HANDLE_VALUE)
    {
        DWORD dwSize=0;
        WriteFile(fileHandle,content,strlen(content),&dwSize,NULL);//写
    }
    UnLock();
    return FileLog::Write("\r\n");
}

//读文件内容
BOOL FileLog::Read(char*buf,int size)
{
    BOOL isOK=FALSE;
    Lock();
    if(fileHandle!=INVALID_HANDLE_VALUE)
    {
        DWORD dwSize=0;
        isOK=ReadFile(fileHandle,buf,size,&dwSize,NULL);//读
    }
    return isOK;
}

//关闭文件
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
