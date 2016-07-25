/*#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class ListNode {
public:
    ListNode():link(NULL),price(0), name("") {}
    ListNode(float p, string n) {price = p; name = n;}
    void setprice(float p) {price = p;}
    const string& getname()const {return name;}
    const float& getprice()const {return price;}
    const int& getnumber()const {return number;}
    void setlink(ListNode* newlink) {link = newlink;}
    const ListNode*const getlink()const {return link;}
    void setnum(int n) {number = n;}
    const int& getnum()const {return number;}

private:
    float price;
    string name;
    int number;
    ListNode* link;
};

class ListBook {
public:
    ListBook() {head = tail = new ListNode; tail = NULL;}
    ~ListBook() {removeall();}
    ListBook(ListBook&);

    bool inserttail();
    void show();
    int getcount();

    bool removeat(int index);
    bool removeat(string raname);
    void removeall();

    const ListNode* findname(string rname);
    ListNode* find(string ranme);

    void sortname();
    void sortprice();
    void sortnum();


    ListNode* gethead() {return head;};
    ListNode* gettail() {return tail;};

private:
    ListNode* head;
    ListNode* tail;
};

void menue() {
    ListBook m;
    while(1) {
        cout << "\n\n";
        cout << "1.查看所有图书。" << endl;
        cout << "2.添加图书。" << endl;
        cout << "3.根据编号删除图书。" << endl;
        cout << "4.根据名称删除图书。" << endl;
        cout << "5.查找图书。" << endl;
        cout << "6.模糊查找。" << endl;
        cout << "7.清空列表。" << endl;
        cout << "8.清屏。" << endl;
        cout << "0.退出。" << endl;
        cout << "\n\n";
        char choice = getch();
        flush(cout);
        switch(choice) {
        case '1': {
            cout << "\n\n";
            cout << "1.按照编号查看。" << endl;
            cout << "2.按照价格查看。" << endl;
            cout << "3.按照名称查看。" << endl;
            char c = getch();
            flush(cout);
            switch(c) {
            case '1': {
                m.sortnum();
                m.show();
                break;
            }
            case '2': {
                m.sortprice();
                m.show();
                break;
            }
            case '3': {
                m.sortname();
                m.show();
                break;
            }
            default: break;
            }
        }
        case '2':
            m.inserttail();
            break;
        case '3': {
            cout << "\n\n";
            cout << "请输入要查找的编号：";
            int index;
            cin >> index;
            m.removeat(index);
            break;
        }
        case '4': {
            cout << "\n\n";
            cout << "请输入要查找的名称：";
            string rname;
            cin >> rname;
            m.removeat(rname);
            break;
        }
        case '5': {

        }
        }
    }
}

int main() {
    menue();
    return 0;
}

*/


#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main() {
    string a, b;
    a = "abcdefg";
    b = "123456789";
    char c[20] = "ABCDEFG";
    char d[20] = "higklmnop";
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;
    cout << "d:" << d << endl << endl << endl;


    cout << strlen(c) << endl;
    cout << sizeof(c) << endl;
    cout << a.length() << endl;
    cout << sizeof(a) << endl;
    b.append(a, 0, 5);
    cout << b.size() << endl;
    cout << sizeof(b) << endl;
    return 0;
}
















