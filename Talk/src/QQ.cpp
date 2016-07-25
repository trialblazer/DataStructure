#include "QQ.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

#define Maxaccount 5

void QQ::menue() {
while (1) {
		system("cls");
		cout << "1:登录" << endl;
		cout << "2:注册" << endl;
		cout << "0:退出" << endl;
		cout << "please choose a number from 1 and 2. " << endl;
		char a;
		a = getch();
		switch(a) {
		case '1': {
			if (login())
                u[b].menue();
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


int QQ::enter() {
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
        cout << "QQ登陆" ;
        gotoxy(hOut, 24, 10);
        cout << "用户名：";
        gotoxy(hOut, 26, 12);
        cout << "密码：";
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
        cout << "登录中.....";

        ///时间延迟。
        clock_t delay = 2*CLOCKS_PER_SEC;
        clock_t start = clock();
        while (clock()-start < delay);

        gotoxy(hOut, 40, 17);
        for (i=0; i<current+1; i++) {
            if (strcmp(a, u[i].getcount()) == 0)
                break;
        }
        if (i == current+1) {
            cout << "用户名不存在，请重新输入（按Esc键返回）" << endl;
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
        cout << "用户密码输入错误,请重新输入(按Esc键返回)" << endl;
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
	srand(time(NULL));
	string id , pass, rpass, name, rname;
	int i, sign = 0;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    for (i=0; i<Maxaccount; i++)
        id[i] = (char)(rand()%9+49);
    id[Maxcount] = '\0';
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
        cout << "QQ注册" ;
        gotoxy(hOut, 26, 8);
        cout << "网名：";
        gotoxy(hOut, 24, 10);
        cout << "用户名：";
        gotoxy(hOut, 26, 12);
        cout << "密码：";
        gotoxy(hOut, 22, 14);
        cout << "密码确认：";
        gotoxy(hOut, 32, 10);
        cout << id;
        gotoxy(hOut, 32, 8);
        if (sign == 0) {
            cin >> name;
            strcpy(rname, name);
        } else {
            cout << rname;
        }
        gotoxy(hOut, 32, 12);
        cin >> pass;
        gotoxy(hOut, 32, 14);
        cin >> rpass;
        fflush(stdin);
        gotoxy(hOut, 44, 19);
        cout << "注册中.....";

        clock_t delay = 1 * CLOCKS_PER_SEC;
        clock_t start = clock ();
        while (clock()-start<delay);

        gotoxy(hOut, 44, 19);
		if (strcmp(pass, rpass) != 0) {
			cout << "两次密码输入不同，请重新输入。" << endl;
			clock_t delay = 1*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            sign = 1;
			continue;
		}
		user_list->insert();
		user_list->setname(trun);
		user_list->
		cout << "注册成功！" << endl;
		system("pause");
		return;
	}
}

