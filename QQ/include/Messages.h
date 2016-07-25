#ifndef MESSAGES_H
#define MESSAGES_H

#define Maxcount 6
#define NAME_MAXSIZE 30

class Messages {
public:
    Messages();
    char account[Maxcount];                     ///账号
	char message[NAME_MAXSIZE][NAME_MAXSIZE];   ///消息
	char acc[NAME_MAXSIZE][NAME_MAXSIZE];       ///消息来源
	int count_mess;                             ///消息的数量

private:

};

#endif // MESSAGES_H
