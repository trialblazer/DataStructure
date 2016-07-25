#ifndef STUCT_H
#define STUCT_H

#define Max 6       //�˺ų���+1
#define MaxUser 5     //�ͻ�������
#define MaxClient 100 //����Ա����
#define KeyNum 20    //�û������ȣ����볤��

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
