#include "QQ.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define NAME_MAXSIZE 30 ///����,��Ϣ�����ֵ

using std::cout;
using std::cin;
using std::endl;

QQ::QQ() {
    user_size = -1;
}


void QQ::menue() {
while (1) {
		system("cls");
		cout << "1:��¼" << endl;
		cout << "2:ע��" << endl;
		cout << "0:�˳�" << endl;
		cout << "please choose a number from 1 and 2. " << endl;
		char a;
		a = getch();
		switch(a) {
		case '1': {
		   curr_order = login();
			if (curr_order != -1) {
                refresh();
                u[curr_order].menue();
            }
			break;
        }
		case '2':
			regist();
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}


void gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}


int QQ::login() {
	int i;
	char a[Maxcount], b[Maxcount], j;
	while (1) {
        system("cls");
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(hOut, 20, 6);
        for (i=6; i<=14; i++) {
            gotoxy(hOut, 20, i);
            if (i == 6 || i == 14)
                cout << "** * * * * * * * * * * * * * **";
            else
                cout << "*                             *";
        }
        gotoxy(hOut, 32, 7);
        cout << "QQ��½" ;
        gotoxy(hOut, 24, 10);
        cout << "�û�����";
        gotoxy(hOut, 26, 12);
        cout << "���룺";
        gotoxy(hOut, 32, 10);
        for (i=0; i<Maxcount; i++) {
            cin.get(a[i]);
            if (a[i] == '\n' && i == 0) {
                gotoxy(hOut, 32, 10);
                --i;
                continue;
            }
            if (a[i] == '\n') {
                a[i] = '\0';
                break;
            }
        }
        fflush(stdin);
    loop:gotoxy(hOut, 32, 12);
        for (i=0; i<Maxcount; i++) {
            cin.get(b[i]);
            if (b[i] == '\n' && i == 0) {
                gotoxy(hOut, 32, 12);
                --i;
                continue;
            }
            if (b[i] == '\n') {
                b[i] = '\0';
                break;
            }
        }
        fflush(stdin);
        gotoxy(hOut, 44, 17);
        cout << "��¼��.....";

        ///ʱ���ӳ١�
        clock_t delay = 2*CLOCKS_PER_SEC;
        clock_t start = clock();
        while (clock()-start < delay);

        gotoxy(hOut, 40, 17);
        for (i=0; i<user_size+1; i++) {
            if (strcmp(a, u[i].get_account()) == 0)
                break;
        }
        if (i == user_size+1) {
            cout << "�û��������ڣ����������루��Esc�����أ�" << endl;
            clock_t delay = 2*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            j = getch();
            if (j == (char)27)
                return -1;
            continue;
        }
        if (strcmp(b, u[i].getpasswords()) == 0) {
            return i;
        }
        cout << "�û������������,����������(��Esc������)" << endl;
        clock_t delay1 = 2*CLOCKS_PER_SEC;
        clock_t start1 = clock();
        while (clock()-start1 < delay1);
        j = getch();
        if (j == (char)27)
            return -1;
        gotoxy(hOut, 32, 12);
        cout << "       ";
        gotoxy(hOut, 40, 17);
        cout << "                                        ";
        goto loop;
	}
}


void QQ::regist() {
	if (user_size+1>Maxcount) {
        cout << "�û��ﵽ���ޣ�����ע�ᣡ" << endl;
        system("pause");
		return;
    }
	srand(time(NULL));
	char a[Maxcount] , b[Maxg], rb[Maxg], c[NAME_MAXSIZE], rc[NAME_MAXSIZE];
	int i, sign = 0;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    for (i=0; i<Maxcount-1; i++)
        a[i] = (char)(rand()%9+49);
    a[Maxcount-1] = '\0';
	while (1) {
		system("cls");
        for (i=3; i<=16; i++) {
            gotoxy(hOut, 20, i);
            if (i == 3 || i == 16)
                cout << "** * * * * * * * * * * * * * **";
            else
                cout << "*                             *";
        }
        gotoxy(hOut, 32, 5);
        cout << "QQע��" ;
        gotoxy(hOut, 26, 8);
        cout << "������";
        gotoxy(hOut, 24, 10);
        cout << "�û�����";
        gotoxy(hOut, 26, 12);
        cout << "���룺";
        gotoxy(hOut, 22, 14);
        cout << "����ȷ�ϣ�";
        gotoxy(hOut, 32, 10);
        cout << a;
        gotoxy(hOut, 32, 8);
        if (sign == 0) {
            for (i=0; i<NAME_MAXSIZE; i++) {
                cin.get(c[i]);
                if (c[i] == '\n' && i == 0) {
                    gotoxy(hOut, 32, 8);
                    --i;
                    continue;
                }
                if (c[i] == '\n') {
                    c[i] = '\0';
                    break;
                }
            }
            strcpy(rc, c);
        } else {
            cout << rc;
        }
        gotoxy(hOut, 32, 12);
        for (i=0; i<Maxcount; i++) {
            cin.get(b[i]);
            if (b[i] == '\n' && i == 0) {
                gotoxy(hOut, 32, 12);
                --i;
                continue;
            }
            if (b[i] == '\n') {
                b[i] = '\0';
                break;
            }
        }
        gotoxy(hOut, 32, 14);
        for (i=0; i<Maxcount; i++) {
            cin.get(rb[i]);
            if (rb[i] == '\n' && i == 0) {
                gotoxy(hOut, 32, 14);
                --i;
                continue;
            }
            if (rb[i] == '\n') {
                rb[i] = '\0';
                break;
            }
        }
        fflush(stdin);
        gotoxy(hOut, 44, 19);
        cout << "ע����.....";

        clock_t delay = 2 * CLOCKS_PER_SEC;
        clock_t start = clock ();
        while (clock()-start<delay);

        gotoxy(hOut, 44, 19);
		if (strlen(b) > Maxg-1) {
			cout << "�������,������ʮλ����" << endl;
			clock_t delay = 2*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            sign = 1;
			continue;
		}
		if (strcmp(b, rb) != 0) {
			cout << "�����������벻ͬ�����������롣" << endl;
			clock_t delay = 2*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            sign = 1;
			continue;
		}
		++user_size;
		u[user_size].setaccount(a);
		u[user_size].setpasswords(b);
		strcpy(u[user_size].own.account, a);
		u[user_size].own.setname(c);

        for (i=0; i<Maxcount; i++) {
            if (i == curr_order)
                continue;
            u[i].setsize(user_size);
            u[i].setc(a);
            u[i].friend_list.insert(a, c);
		}
		cout << "ע��ɹ���" << endl;
		system("pause");
		return;
	}
}


void QQ::refresh() {
    for (int i=0; i<=user_size; i++) {
        if (i == curr_order)
            continue;
        Person *p1 = u[i].friend_list.find(u[curr_order].get_account());
        if (p1 == NULL)
            return;
        Person *p2 = u[curr_order].friend_list.find(u[i].get_account());
        if (p2 == NULL)
            return;
        if (p1->count_mess != p2->count_mess) {
            for (int j=0; j<p1->count_mess; j++) {
                int t = u[curr_order].own.count_mess;
                if (strcmp(p2->message[j], p1->message[j]) == 0)
                    continue;
                else {
                    strcpy(u[curr_order].own.message[t], p1->message[j]);
                    strcpy(u[curr_order].own.acc[t], p1->acc[j]);
                    strcpy(p2->message[j], p1->message[j]);
                    strcpy(p2->acc[j], p1->acc[j]);
                    p2->count_mess = p1->count_mess;
                    u[curr_order].own.count_mess++;
                    p2->isfriend = p1->isfriend;

                    strcpy(p2->name, u[i].own.name);
                    strcpy(p2->signature, u[i].own.signature);
                }
            }
        }
    }
}

