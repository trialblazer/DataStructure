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
    std::cout << "�������������(��Esc��ֹ)\n";
    std::cin >> dataname;
    if (dataname[0] == (char)32)
        return;
    strcpy(name, dataname);
    std::cout << "���óɹ�\n" << endl;
    clock_t delay1 = 1*CLOCKS_PER_SEC;
    clock_t start1 = clock();
    while (clock()-start1 < delay1);
}


void Person::settruename() {
    system("cls");
    char dataname[NAME_MAXSIZE];
    cout << "�����뱸ע(��Esc��ֹ)��" << endl;
    std::cin >> dataname;
    if (dataname[0] == (char)32)
        return;
    strcpy(truename, dataname);
    cout << "���óɹ�\n" << endl;
    clock_t delay1 = 1*CLOCKS_PER_SEC;
    clock_t start1 = clock();
    while (clock()-start1 < delay1);
}


 ///��ʾ��ǰ�������Ϣ
void Person::print_information() {
    system("cls");
    cout << "�˺ţ�    " << account << endl;
    cout << "������    " << name << endl;
    cout << "��ע��    " << truename << endl;
    cout << "����ǩ����" << signature;
    cout << endl <<  endl;
    system("pause");
}


void Person::look_messages() {
    system("cls");
    if (count_mess == 0)
        cout << "��ϢΪ�գ�" << endl;
    else {
        for (int i=0; i<=count_mess; i++) {
            if (strcmp(message[i], "haoyoushenqing") == 0) {
                cout << acc[i] << "  :  " << "���ܼ���Ϊ���ѣ�" << endl;
            } else {
                if (strcmp(message[i], "tongyi") == 0) {
                    cout << acc[i] << " : " << "��ͬ����ĺ�������" << endl;
                } else
                cout << acc[i] << "  :  " << message[i] << endl;
            }
        }
    }
    system("pause");
}


void Person::setsignature() {
    system("cls");
    cout << "����ǩ����";
    char signate[200];
    std::cin >> signate;
    strcpy(signature, signate);
    cout << "\n\n�޸ĳɹ���\n"  << endl;
    clock_t delay = 2*CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock()-start < delay);
}


///������Ϣa[]������Ϣ��b[]������Դ
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
        cout << "1: �޸�����" << endl;
        cout << "2���޸ĸ���ǩ��" << endl;
        cout << "3: �޸ı�ע" << endl;
        cout << "0: �˳�" << endl;
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
        cout << "1: �޸ı�ע" << endl;
        cout << "0: �˳�" << endl;
        char a;
        a = getch();
        switch(a) {
        case '1': {
            settruename();
            cout << "�޸ĳɹ���" << endl;
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
