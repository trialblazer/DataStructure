#include "Server.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

Server::Server() {

}

void gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

bool Server::login() {
    int i, id;
	string passwords;
	while (1) {
        system("cls");
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(hOut, 20, 6);
        for (i=6; i<=14; i++) {
            gotoxy(hOut, 20, i);
            if (i == 6 || i == 14)
                cout << "** * * * * * * * * * * * * * * **";
            else
                cout << "*                                *";
        }
        gotoxy(hOut, 32, 7);
        cout << "QQ��½" ;
        gotoxy(hOut, 24, 10);
        cout << "�û�����";
        gotoxy(hOut, 26, 12);
        cout << "���룺";
        gotoxy(hOut, 32, 10);
        cin >> id;
        fflush(stdin);
    loop:gotoxy(hOut, 32, 12);
        cin >> passwords;
        fflush(stdin);
        gotoxy(hOut, 44, 17);
        cout << "��¼��.....";

        ///ʱ���ӳ١�
        clock_t delay = 1*CLOCKS_PER_SEC;
        clock_t start = clock();
        while (clock()-start < delay);

        gotoxy(hOut, 40, 17);
        user_itor = Users.find(id);

        if (user_itor == Users.end()) {
            cout << "�û��������ڣ����������루��Esc�����أ�" << endl;
            clock_t delay = 2*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            j = getch();
            if (j == (char)27)
                return 0;
            continue;
        }
        if (passwords == user_itor->second.getpasswords()) {
            return id;
        }
        cout << "�û������������,����������(��Esc������)" << endl;
        clock_t delay1 = 2*CLOCKS_PER_SEC;
        clock_t start1 = clock();
        while (clock()-start1 < delay1);
        j = getch();
        if (j == (char)27)
            return 0;
        gotoxy(hOut, 32, 12);
        cout << "       ";
        gotoxy(hOut, 40, 17);
        cout << "                                        ";
        goto loop;
	}
}


int Server::receivemessage(char choice, int id) {
    switch(choice) {
    case '1':
        if (login())
            return 1;
        return 0;
    case '2':
        return rigist();
    case '3':
        show_group(id);
    case '4':
        show_mess(id);
    case '5':
        ȫ������
    case '6':

    default:
        return 0;
    }
}

void Server::show_group(int id) {
    int order = 1;
    for (p_group = Groups.begin(); p_group != Groups.end(); ++p_group) {
        cout << order++ << " : " << p_group->first;
        group_itor = group_list.begin();
        while (group_itor != group_list.end())
            cout << *itor++ << endl;
    }

}

void Server::show_mess(int id) {

}

itor=ilist.begin();
       while(itor!=ilist.end())
       {
          cout<< *itor++<<endl;
       }

    for(it=m.begin();it!=m.end();++it)
        cout<<"key: "<<it->first <<" value: "<<it->second<<endl;




void Server::rigist() {
	srand(time(NULL));
	string pass, rpass, name;
	int id;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    id = rand()*2;
	while (1) {
		system("cls");
        for (int i=3; i<=16; i++) {
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
        cout << id;
        gotoxy(hOut, 32, 8);
        cin >> name;
        gotoxy(hOut, 32, 12);
        cin >> pass;
        gotoxy(hOut, 32, 14);
        cin >> rpass;
        gotoxy(hOut, 44, 19);
        cout << "ע����.....";

        clock_t delay = 1 * CLOCKS_PER_SEC;
        clock_t start = clock ();
        while (clock()-start<delay);

        gotoxy(hOut, 44, 19);
		if (pass != rpass) {
			cout << "�����������벻ͬ�����������롣" << endl;
			clock_t delay = 2*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
			continue;
		}
		cout << "ע��ɹ���" << endl;
		system("pause");
		return;
	}
}






