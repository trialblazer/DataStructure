#include "Person.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using std::cout;
using std::endl;

Person::Person() {
    strcpy(name, "");
    strcpy(truename, "");
    strcpy(signature, "");
    count_mess = 0;
    isfriend = 0;
}


void Person::setname() {
    system("cls");
    char dataname[NAME_MAXSIZE];
    std::cout << "请输入你的网名(按Esc终止)\n";
    std::cin >> dataname;
    if (dataname[0] == (char)32)
        return;
    strcpy(name, dataname);
    std::cout << "设置成功\n" << endl;
    clock_t delay1 = 1*CLOCKS_PER_SEC;
    clock_t start1 = clock();
    while (clock()-start1 < delay1);
}


void Person::settruename() {
    system("cls");
    char dataname[NAME_MAXSIZE];
    cout << "请输入备注(按Esc终止)：" << endl;
    std::cin >> dataname;
    if (dataname[0] == (char)32)
        return;
    strcpy(truename, dataname);
    cout << "设置成功\n" << endl;
    clock_t delay1 = 1*CLOCKS_PER_SEC;
    clock_t start1 = clock();
    while (clock()-start1 < delay1);
}


 ///显示当前人物的信息
void Person::print_information() {
    system("cls");
    cout << "账号：    " << account << endl;
    cout << "网名：    " << name << endl;
    cout << "备注：    " << truename << endl;
    cout << "个性签名：" << signature;
    cout << endl <<  endl;
    system("pause");
}


void Person::look_messages() {
    system("cls");
    if (count_mess == 0)
        cout << "消息为空！" << endl;
    else {
        for (int i=0; i<=count_mess; i++) {
            if (strcmp(message[i], "haoyoushenqing") == 0) {
                cout << acc[i] << "  :  " << "我能加你为好友？" << endl;
            } else {
                if (strcmp(message[i], "tongyi") == 0) {
                    cout << acc[i] << " : " << "我同意你的好友申请" << endl;
                } else
                cout << acc[i] << "  :  " << message[i] << endl;
            }
        }
    }
    system("pause");
}


void Person::setsignature() {
    system("cls");
    cout << "个性签名：";
    char signate[200];
    std::cin >> signate;
    strcpy(signature, signate);
    cout << "\n\n修改成功。\n"  << endl;
    clock_t delay = 2*CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock()-start < delay);
}


///接收消息a[]代表消息，b[]代表来源
void Person::receivemessage(char a[], char b[]) {
    strcpy(message[count_mess], a);
    strcpy(acc[count_mess], b);
    count_mess++;
}


void Person::setname(char* c) {
    strcpy(name, c);
}


void Person::change_my_information() {
    while(1) {
        system("cls");
        cout << "1: 修改网名" << endl;
        cout << "2：修改个性签名" << endl;
        cout << "3: 修改备注" << endl;
        cout << "0: 退出" << endl;
        char a;
        a = getch();
        switch(a) {
        case '1':
            setname();
            break;
        case '2':
            setsignature();
            break;
        case '3':
            settruename();
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}


void Person::change_friend_information() {
    while(1) {
        system("cls");
        cout << "1: 修改备注" << endl;
        cout << "0: 退出" << endl;
        char a;
        a = getch();
        switch(a) {
        case '1': {
            settruename();
            cout << "修改成功！" << endl;
            clock_t delay = 1 * CLOCKS_PER_SEC;
            clock_t start = clock ();
            while (clock()-start<delay);
            break;
        }
        case '0':
            return;
        default:
            break;
        }
    }
}
