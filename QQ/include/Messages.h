#ifndef MESSAGES_H
#define MESSAGES_H

#define Maxcount 6
#define NAME_MAXSIZE 30

class Messages {
public:
    Messages();
    char account[Maxcount];                     ///�˺�
	char message[NAME_MAXSIZE][NAME_MAXSIZE];   ///��Ϣ
	char acc[NAME_MAXSIZE][NAME_MAXSIZE];       ///��Ϣ��Դ
	int count_mess;                             ///��Ϣ������

private:

};

#endif // MESSAGES_H
