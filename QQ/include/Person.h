#ifndef PERSON_H
#define PERSON_H

#define NAME_MAXSIZE 30 ///����,��Ϣ�����ֵ
#define Maxcount 6/// �û��˺Ŵ�С

class Person {
public:
	Person();
	void print_information();                   ///��ʾ��ǰ�������Ϣ
	void change_friend_information();           ///�޸ĺ�����Ϣ
    void look_messages();                       ///�鿴��Ϣ
    void change_my_information();               ///�޸ĸ�����Ϣ
	void receivemessage(char a[], char b[]);    ///������Ϣa[]������Ϣ��b[]������Դ
    char signature[50];                         ///����ǩ��
	char name[NAME_MAXSIZE];                    ///����
	char truename[NAME_MAXSIZE];                ///��ע
	char account[Maxcount];                     ///�˺�
	char message[NAME_MAXSIZE][NAME_MAXSIZE];   ///��Ϣ
	char acc[NAME_MAXSIZE][NAME_MAXSIZE];       ///��Ϣ��Դ
	int count_mess;                             ///��Ϣ������
	void setname(char c[]);
	int isfriend;                   ///yesΪ0ʱ���ʾ���Ǻ��ѣ���1���Ǻ���

private:
    void setsignature();            ///�޸ĸ���ǩ��
    void setname();                 ///��������
	void settruename();             ///���ñ�ע
};

#endif // PERSON_H
