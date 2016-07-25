#ifndef USER_H
#define USER_H

#include "Person.h"
#include "List.h"

#define Maxg 10       ///������,�������ޣ��û�������
#define Maxcount 6    /// �û��˺Ŵ�С

class User {
public:
    void menue();
	char* get_account();
	char* getpasswords();
    void setc(char a[]);                ///����c����
    void setrc(int i, int j);           ///����re����
    void setsize(int i);                ///����size��С
    void setaccount(char c[]);          ///����count
    void setpasswords(char p[]);        ///��������

    List friend_list;                   ///��������
    Person own;                         ///����Ա

private:
    void contact_manage();              ///��ϵ��
	void manage_friend();               ///���ѹ�������
	void manage_my_infor();             ///�ҵ���Ϣ����
	void add_friend();                  ///��Ӻ���
	void del_friend();                  ///ɾ������
	void sent_mess();                   ///������Ϣ
	void show_friend_mess();            ///��ʾ��������
	void change_friend_inf();           ///�޸ĺ�������
	void look_fr_mess();                ///�鿴��һ�������йص���Ϣ
    void look_new_mess();               ///�鿴����Ϣ
    char acc_contain[Maxg][Maxcount];   ///��¼�ܹ����û��˺�
    int user_count;                     ///�û�����
	char account[Maxcount];             ///�ʻ���
	char passwords[Maxcount];           ///����
};


#endif // USER_H
