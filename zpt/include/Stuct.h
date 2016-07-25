#ifndef STUCT_H
#define STUCT_H

#define Max 6       //账号长度+1
#define MaxUser 5     //客户端上限
#define MaxClient 100 //管理员上限
#define KeyNum 20    //用户名长度，密码长度

typedef struct Time {
	int year;
	int month;
	int day;
	int hour;
	int minuter;
	int second;
}T;

typedef struct BookInform {
	char bookname[KeyNum];
	char author[KeyNum];
	char introduct[MaxClient];
	float price;
}Inform;

struct BookNode {
	Inform information;
	bool islent;
	T lentime;
	BookNode* next;
};

struct Operator {
	char name[KeyNum];
	char id[Max];
	char passwords[KeyNum];
};


#endif // STUCT_H
