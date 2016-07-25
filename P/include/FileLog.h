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
        EnterCriticalSection(&cs);// 进入临界区
    }

    void UnLock()
    {
        LeaveCriticalSection(&cs);//离开临界区
    }

public:
    FileLog()
    {
        InitializeCriticalSection(&cs);//初始化临界区
        fileHandle=INVALID_HANDLE_VALUE;//先初始化为错误的句柄
    }

    ~FileLog()
    {
        if(fileHandle!=INVALID_HANDLE_VALUE)
        {
            //CloseHandle的功能是关闭一个打开的对象句柄，该对象句柄可以是线程句柄，也可以是进程、信号量等其他内核对象的句柄
            CloseHandle(fileHandle);
        }
        DeleteCriticalSection(&cs);//删除临界区
    }

    BOOL Open(const char*fileName);//打开文件
    FileLog& Write(const char*content);//向文件中写入内容
    FileLog& WriteLine(const char*content);//向文件中写入内容
    BOOL Read(char*buf,int size);//读文件内容
    BOOL Close();//关闭文件
};

#endif // FILELOG_H
