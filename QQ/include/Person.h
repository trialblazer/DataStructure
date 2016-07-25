#ifndef PERSON_H
#define PERSON_H

#define NAME_MAXSIZE 30 ///名称,消息的最大值
#define Maxcount 6/// 用户账号大小

class Person {
public:
	Person();
	void print_information();                   ///显示当前人物的信息
	void change_friend_information();           ///修改好友信息
    void look_messages();                       ///查看消息
    void change_my_information();               ///修改个人信息
	void receivemessage(char a[], char b[]);    ///接收消息a[]代表消息，b[]代表来源
    char signature[50];                         ///个性签名
	char name[NAME_MAXSIZE];                    ///网名
	char truename[NAME_MAXSIZE];                ///备注
	char account[Maxcount];                     ///账号
	char message[NAME_MAXSIZE][NAME_MAXSIZE];   ///消息
	char acc[NAME_MAXSIZE][NAME_MAXSIZE];       ///消息来源
	int count_mess;                             ///消息的数量
	void setname(char c[]);
	int isfriend;                   ///yes为0时则表示不是好友，是1就是好友

private:
    void setsignature();            ///修改个性签名
    void setname();                 ///设置网名
	void settruename();             ///设置备注
};

#endif // PERSON_H
