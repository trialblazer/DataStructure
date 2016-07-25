#include "User.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

using std::cout;
using std::endl;

#define NAME_MAXSIZE 30

void User::menue() {
    while (1) {
        system("cls");
        cout << "1����ϵ�ˡ�" << endl;
        cout << "2�����ѹ���" << endl;
        cout << "3: ��" << endl;
        cout << "0���˳���" << endl;
        char a;
        a = getch();
        switch(a) {
        case '1':
            contact_manage();
            break;
        case '2':
            manage_friend();
            break;
        case '3':
            manage_my_infor();
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}


void User::contact_manage() {
    while (1) {
        system("cls");
        if (friend_list.getsize() == 0) {
            cout << "�������㻹û�к��ѣ���ȥ��Ӻ��Ѱɣ�" << endl;
            clock_t delay1 = 1*CLOCKS_PER_SEC;
            clock_t start1 = clock();
            while (clock()-start1 < delay1);
            return;
        }
        system("cls");
        friend_list.print();
        cout << endl << endl;
        cout << "1.�鿴��Ϣ��" << endl;
        cout << "2.��ʾ��ϵ�����ϡ�" << endl;
        cout << "3.������Ϣ��" << endl;
        cout << "0.�˳���" << endl;
        char a;
        a = getch();
        switch(a) {
        case '1':
            look_fr_mess();
            break;
        case '2':
            show_friend_mess();
            break;
        case '3':
            sent_mess();
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}


void User::manage_friend() {
    while (1) {
        system("cls");
        cout << "1.��Ӻ��ѡ�" << endl;
        cout << "2.ɾ�����ѡ�" << endl;
        cout << "3.�޸ĺ��ѱ�ע" << endl;
        cout << "0.�˳���" << endl;
        char a;
        a = getch();
        switch(a) {
        case '1':
            add_friend();
            break;
        case '2':
           del_friend();
            break;
        case '3':
            change_friend_inf();
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}


void User::manage_my_infor() {
    while (1) {
        system("cls");
        cout << "1.�޸ĸ�������." << endl;
        cout << "2.�鿴����Ϣ��" << endl;
        cout << "3.��ʾ���ϡ�" << endl;
        cout << "0.�˳���" << endl;
        char a;
        a = getch();
        switch(a) {
        case '1':
            own.change_my_information();
            break;
        case '2':
            look_new_mess();
            break;
        case '3':
            own.print_information();
            //my_information();
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}


void User::del_friend() {
    system("cls");
    if (friend_list.getsize() == 0) {
        cout << "�㻹û�к���" << endl;
        clock_t delay1 = 1*CLOCKS_PER_SEC;
        clock_t start1 = clock();
        while (clock()-start1 < delay1);
        return;
    }
    friend_list.print();
    cout << "\n\t\t\t\tɾ������" << endl;
    cout << "������Ҫɾ�����ѵ���ţ�";
    int a;
    std::cin >> a;
    Person* q = friend_list.find(a);
    if (q == NULL)
        cout << "û�в��ҵ��ú���" << endl;
    else
        q->isfriend = 0;
}


void User::look_new_mess() {
    system("cls");
    if (own.count_mess == 0)
        cout << "��ϢΪ�գ�\n\n" << endl;
    else {
        for (int i=0; i<own.count_mess; i++) {
            if (strcmp(own.message[i], "haoyoushenqing") == 0) {
                cout << own.acc[i] << " : " << "���ܼ���Ϊ�����𣿣�ͬ�ⰴ1����ͬ�ⰴ����������";
                char choice = getch();
                if (choice == '1') {
                    Person *p5 = friend_list.find(own.acc[i]);
                    if (p5 == NULL) {
                        cout << "error";
                        return;
                    }
                    int num = p5->count_mess++;
                    strcpy(p5->message[num], "tongyi");
                    strcpy(p5->acc[num], get_account());
                    p5->isfriend = 1;
                    cout << "  ͬ�⣡" << endl;
                }
            } else {
                Person *point = friend_list.find(own.acc[i]);
                if (strcmp(own.message[i], "tongyi") == 0) {
                    point->isfriend = 1;
                    cout << own.acc[i] << "  :  " <<  "��ͬ�������Ϊ���ѣ��������ǿ��������ˡ�" << endl;
                } else {
                    cout << own.acc[i] << "  :  " << own.message[i] << endl;
                }
            }
        }
        own.count_mess= 0;
    }
    system("pause");
}


void User::add_friend() {
    while (1) {
        system("cls");
        cout << "\t\t\t\t��Ӻ���\n\n" << endl;
        cout << "��������Ҫ��Ӻ��ѵ��˺ţ�";
        char a[Maxcount];
        std::cin >> a;
        fflush(stdin);
        int i;
        for (i=0; i<=user_count; i++) {
            if (strcmp(acc_contain[i], a) == 0)
                break;
        }
        if (i == user_count+1) {
            cout << "û�в��ҵ����˺�!(��Esc������,������������)\n" << endl;
            char j = getch();
            fflush(stdin);
            if (j == (char)27)
                return;
        } else {
            Person *p4 = friend_list.find(a);
            ++p4->count_mess;
            int num = p4->count_mess++;
            strcpy(p4->message[num], "haoyoushenqing");
            strcpy(p4->acc[num], own.account);
            cout << "����Է����ͺ�������" << endl;
            clock_t delay = 1*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            return;
        }
    }
}


///�޸ĺ�������
void User::change_friend_inf() {
    system("cls");
    friend_list.print();
    cout << "\n�����������ţ�";
    int index3;
    fflush(stdin);
    std::cin >> index3;
    Person *q3 = friend_list.find(index3);
    q3->change_friend_information();
}


///��ȡ�˺�
char* User::get_account() {
    return account;
}

///��ȡ����
char* User::getpasswords() {
    return passwords;
}


///��ʾ��������
void User::show_friend_mess() {
    cout << "�����������ţ�";
    int index1;
    std::cin >> index1;
    Person *q1 = friend_list.find(index1);
    if (q1 == NULL) {
        cout << "û���ҵ��ú��ѣ�" << endl;
        return;
    }
    q1->print_information();
}


///�鿴��һ�������йص���Ϣ
void User::look_fr_mess() {
    cout << "������Ҫ�鿴��Ϣ�ĺ��ѵ���ţ�";
    char index2 = getch();
    Person *q2 = friend_list.find((int)index2- 48);
    if (q2 == NULL)
        cout << "��Ǹ��û�в��ҵ��ú��ѣ�" << endl;
    else
        q2->look_messages();
}


///������Ϣ
void User::sent_mess() {
    cout << "��������Ҫ������Ϣ�ĺ��ѣ�";
    char index3 = getch();
    system("cls");
    Person *p2 = friend_list.find((int)index3-48);
    if (p2 == NULL) {
        cout << "��Ǹ��û���ҵ��ú��ѣ�" << endl;
        return;
    }
    cout << "��Ϣ��";
    char m1[NAME_MAXSIZE];
    std::cin >> m1;
    int num = p2->count_mess++;
    strcpy(p2->message[num], m1);
    strcpy(p2->acc[num], own.account);

    clock_t delay = 1*CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock()-start < delay);
}


void User::setc(char a[]) {
    strcpy(acc_contain[user_count], a);
}


void User::setsize(int i) {
    user_count = i;
}


void User::setaccount(char c[]) {
    strcpy(account, c);
    strcpy(own.account, c);
}


void User::setpasswords(char p[]) {
    strcpy(passwords, p);
}

/*
void User::deletegroup() {
    if (current_gsize == 0)
        return;
    cout << "����������ɾ��������� ��";
    int a, b, i;
    std::cin >> a;
    if (a == 1 || a == 2) {
        cout << "������Ĭ�Ϸ��飬�޷�ɾ����" << endl;
        return;
    }
    if (a<0 || a>=current_gsize)
        return;
    if (g[a].getsize() > 0) {
        cout << "�����л��к��ѣ���������������еĺ��ѽ��Զ�������һ���顣(��0��ֹ����)" << endl;
        std::cin >> b;
        if (b == 0)
            return;
    }
    int sign1 = 0, sign2 = 0, sign3 = 0;
    for (i=0; i<current_size; i++) {
        if (sign1 == 0)
            g[a-1].add_person(*(g[a].getperson(i)));
        if (g[a-1].getsize() == NAME_MAXSIZE) {
            if (sign2 == 0)
                g[a-2].add_person(*(g[a].getperson(i)));
            sign1 = 1;
            if (g[a-2].getsize() == NAME_MAXSIZE) {
                if (a-3 < 0)
                    break;
                sign2 = 1;
                if (sign3 == 0)
                    g[a-3].add_person(*(g[a].getperson(i)));
                if (g[a-3].getsize() == NAME_MAXSIZE) {
                    if (a-4 < 0)
                    break;
                    sign3 = 1;
                    g[a-4].add_person(*(g[a].getperson(i)));
                }
            }
        }

    }
    if (i < current_size)
        cout << "�в��ֺ���û�ܱ����档" << endl;
    current_gsize--;
}


bool User::addgroup() {
    if (current_size == Maxg) {
        cout << "��ĸ����Դﵽ���ޣ�" << endl;
        return false;
    }
    char a[NAME_MAXSIZE];
    cout << "�������½�������֣�";
    cin >> a;
    g[current_gsize++].setname(a);
    return true;
}


int User::getcurrent_gsize() {
    return current_gsize;
}
int User::getcurrent_size() {
    return current_size;
}*/























