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
		cout << "1:��¼" << endl;
		cout << "2:ע��" << endl;
		cout << "0:�˳�" << endl;
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
        cout << "1.��   2.�Ự   3.ȫ������   4.�ҵ�Ӧ��   0.�˳�(��Q���й����л�)\n" << endl;
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
        cout << "\n\n1.�鿴��Ϣ" << endl;
        cout << "2.�鿴��������" << endl;
        cout << "3.�޸ĺ��ѱ�ע" << endl;
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
        cout << "1.�޸ĸ�������." << endl;
        cout << "2.�鿴����Ϣ��" << endl;
        cout << "3.��ʾ���ϡ�" << endl;
        cout << "0.�˳���" << endl;
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
















