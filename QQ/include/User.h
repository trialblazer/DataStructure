#ifndef USER_H
#define USER_H

#include "Person.h"
#include "List.h"

#define Maxg 10       ///组上限,密码上限，用户最大个数
#define Maxcount 6    /// 用户账号大小

class User {
public:
    void menue();
	char* get_account();
	char* getpasswords();
    void setc(char a[]);                ///设置c数组
    void setrc(int i, int j);           ///设置re数组
    void setsize(int i);                ///设置size大小
    void setaccount(char c[]);          ///设置count
    void setpasswords(char p[]);        ///设置密码

    List friend_list;                   ///好友链表
    Person own;                         ///管理员

private:
    void contact_manage();              ///联系人
	void manage_friend();               ///好友管理设置
	void manage_my_infor();             ///我的信息管理
	void add_friend();                  ///添加好友
	void del_friend();                  ///删除好友
	void sent_mess();                   ///发送消息
	void show_friend_mess();            ///显示好友资料
	void change_friend_inf();           ///修改好友资料
	void look_fr_mess();                ///查看与一个好友有关的消息
    void look_new_mess();               ///查看新消息
    char acc_contain[Maxg][Maxcount];   ///记录总共的用户账号
    int user_count;                     ///用户个数
	char account[Maxcount];             ///帐户名
	char passwords[Maxcount];           ///密码
};


#endif // USER_H
