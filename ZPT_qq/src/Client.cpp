#include "Client.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Client::menue() {
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
		    int id = console.receivemessage(a, 0);
			if (id)
                user_menue(id);
			break;
        }
		case '2':
			console.receivemessage(a, 0);
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

void Client::user_menue(int id) {
    while (1) {
        system("cls");
        cout << "1.组   2.会话   3.全部好友   4.我的应用   0.退出(按Q进行功能切换)\n" << endl;
        console.receivemessage('3', id);
        char choice = getch(), choose;
        switch(choice) {
        case '1':
            console.receivemessage('3', id);
            cout << endl << endl;
            group_menue(id);
            break;
        case '2':
            console.receivemessage('4', id);
            cout << endl << endl;
            mess_menue(id);
            break;
        case '3':
            console.receivemessage('5', id);
            cout << endl << endl;
            friend_menue(id);
            break;
        case '4':
            my_menue(id);
            break;
        case '0':
            return;
        }
    }
}


void Client::group_menue(int id) {
    while (1) {
        cout << "\n\n1.查看消息" << endl;
        cout << "2.查看好友资料" << endl;
        cout << "3.修改好友备注" << endl;
        cout << "4.";
    }
}

void Client::mess_menue(int id) {
}

void Client::friend_menue(int id) {
}

void Client::my_menue(int id) {
    while (1) {
        system("cls");
        cout << "1.修改个人资料." << endl;
        cout << "2.查看新消息。" << endl;
        cout << "3.显示资料。" << endl;
        cout << "0.退出。" << endl;
        char a;
        a = getch();
        switch(1) {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}
















