/*#include <iostream>
//#include "LinkedQueue.h"
//#include "SeqQueue.h"
//#include "List.h"
using namespace std;


int num = 0;

void f(int n, int min, int max) {
    for (int i=min; i<= max/2; i++) {
        num++;
        f(max, min, max-min);
    }
}

int main() {
    f(4, 1, 4);
    cout << num << endl;
    return 0;
}
*/
/*
#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
using namespace std;

//合并数组a(索引从b1开始,大小为size1)与数组b(索引从b2开始,大小为size2),合并后存入数组c;
void combine(int a[], int b[], int c[], int b1, int b2, int size1, int size2) {
    int *p=a, k=0, i=b1, j, num;
    for (j=b2; i<b1+size1 && j<b2+size2; k++) {
        c[k] = a[i]>b[j]? b[j++]:a[i++];
    }
    i<b1+size1? (p=a, num=i): (p =b, num=j);
    while (k<size1+size2) {
        c[k++] = p[num++];
    }
}

void merge(int a[], int begin, int end) {
    if (begin+1 == end)
        return;
    int mid = (begin+end)/2;
    merge(a, begin, mid);
    merge(a, mid, end);
    int *p = new int[end-begin];
    combine(a, a, p, begin, mid, mid-begin, end-mid);
    for (int i=begin; i<end; i++) {
        a[i] = p[i-begin];
    }
    delete p;
    p = 0;
}

#define Max 30

int main() {
    int a[Max];
    srand(time(NULL));
    for (int i=0; i<Max; i++) {
        a[i] = rand()%200;
        cout << a[i] << "  ";
    }
    cout << endl << endl;
    merge(a, 0, Max);
    for (int i=0; i<Max; i++)
        cout << a[i] << "  ";
    cout << endl;
	return 0;
}*/























#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

struct Student//定义结构体
{
    char number[10];
    char name[10];
    char college[20];
    float score;
    struct Student* next;
};

typedef struct Student node;//使node表示struct Student 类型
typedef node* Link;//link即为struct Student*类型

Link creat_list(Link head);                     //实现录入功能
void save(Link head);                           //保存数据
void removeNode(Link head);                     //实现删除功能
void changeNode(Link head);                     //实现修改功能
void free(Link head);                           //销毁链表
Link findpreNode(char* number, Link head);      //按学号查找
Link findprenode(char* name, Link head);        //按名称查找
void search(Link head);                         //查询
void sortbynum(Link head);                      //实现排序功能
void print(Link head);                          //打印功能
int secret();                                   //加密功能

/*void save(Link head)
{
	Link p;
	FILE *fp;
	int size;
	size=sizeof(node);
	fp=fopen("D:\\cyuyan.txt","r");
	if(fp==NULL)
		printf("文件读取错误!");
	for(p=head->next;p!=NULL;p=p->next)
		fwrite(p;size;1;fp);
	printf("保存成功!");
	getch();
	fclose(fp);
}
	*/

Link creat_list()
{
	FILE *fp;
    Link head;
    fp=fopen("D:\\cyuyan.txt","wt");
	if(fp==NULL)
		printf("文件打开失败!");
    Link add = (Link)malloc(sizeof(node));
    if (add == NULL)
	{
        printf("memory allocate failure!\n");
		exit(1);
    }
    printf("请输入学生评教信息,依次为：学号,姓名,学院,评教成绩（输入0结束）:\n");
	fprintf(fp,"学号\t\t姓名\t\t学院\t\t评教成绩\n");
	scanf("%s", add->number);
    if (add->number[0] == '0')
        return head;
    scanf("%s,%s,%f",add->name,add->college,add->score);
    fflush(stdin);
	fprintf(fp,"%s\t%s\t\t%s\t\t%f\n", add->number,add->name,add->college,add->score);
    add->next = NULL;
    head = add;
    add = NULL;
    Link pointer = head;
	while (1)
	{
        add = (Link)malloc(sizeof(node));
        if (add == NULL)
		{
            printf("memory allocate failure!\n");
            break;
		}
	    scanf("%s", add->number);
		if (add->number[0] == '0')
			return head;
        scanf("%s,%s,%f", add->name,add->college,add->score);
        fflush(stdin);
		fprintf(fp,"%s\t%s\t\t%s\t\t%f\n", add->number,add->name,add->college,add->score);
		add->next = NULL;
		pointer->next = add;
		pointer = add;
		add = NULL;
		//fwrite(head,sizeof(node),2,fp);
	}
	fclose(fp);
    return head;
}

void free(Link head)
{
    Link pointer;
    while (head != NULL)
	{
        pointer = head;
        head = head->next;
        free(pointer);
    }
}

void removeNode(Link head)
{
    system("cls");
    char oldnumber[10];
	Link pre = head;
	printf("请输入要删除信息的学生的学号:\n");
	scanf("%s",oldnumber);
	fflush(stdin);
	Link p = findpreNode(oldnumber, head);
	if (p == NULL) {
        printf("删除失败！！\n");
        system("pause");
        return;
    }
    if (head->next == NULL) {
        free(head);
        return;
    }
    while(pre != NULL) {
        if (pre->next == p)
            break;
        pre = pre->next;
    }
    pre->next = p->next;
    free(p);
    system("pause");
}

void changeNode(Link head)
{
	char oldnumber[10],newnumber[10],newname[20],newcollege[10];
	float newscore;
	printf("请输入要修改的学生的学号:\n");
	scanf("%s",oldnumber);
	fflush(stdin);
	Link p = findpreNode(oldnumber, head);
	if (p == NULL) {
        printf("没有找到该用户！\n");
        return;
	}
	printf("请输入新信息(学号，姓名，学院，成绩):\n");
	scanf("%s,%s,%s,%f",newnumber,newname,newcollege,&newscore);
	fflush(stdin);
    strcpy(p->number, newnumber);
    strcpy(p->name, newname);
    strcpy(p->college, newcollege);
    p->score = newscore;
    printf("______________________\n——————修改成功!——————");
}

Link findpreNode(char* number, Link head) {
    Link pointer = head;
    while (pointer != NULL) {
        if (strcmp(number, pointer->number) == 0)
            return pointer;
        pointer = pointer->next;
    }
    return NULL;
}

Link findprenode(char* name, Link head) {
    Link pointer = head;
    while (pointer != NULL) {
        if (strcmp(name, pointer->name) == 0)
            return pointer;
        pointer = pointer->next;
    }
    return NULL;
}

void search(Link head)
{
    system("cls");
	if (head == NULL) {
        printf("文件为空！\n\n");
        system("pause");
        return;
	}
	char number[10],name[10], choice;
	Link p = 0;
	printf("\t\t-------------查询功能--------------\n");
	printf("\t\t------------1.按学号查询-----------\n");
	printf("\t\t------------2.按姓名查询-----------\n");
	printf("\t\t------------0.  退出---------------\n");
	choice = getch();
	fflush(stdin);
	switch(choice)
	{
		case '1': {
            printf("请输入要查询的学号\n");
            scanf("%s",number);
            fflush(stdin);
            p = findpreNode(number, head);
            break;
        }
		case '2': {
            printf("请输入学生姓名:");
            scanf("%s",name);
            fflush(stdin);
            Link p = findprenode(name, head);
            break;
        }
		case '0':
			break;
	}
	if(p == NULL) {
        printf("查找失败！！\n\n");
    } else {
        printf("该学生的信息为：\n");
        printf("学号：\t姓名:\t学院：\t评教成绩:\t");
        printf("%s\t%s\t\t%s\t\t%f", p->number,p->name,p->college,p->score);
    }
	system("pause");
}

void sortbynum(Link head)
{
	Link pi,pj,pt;
	node t;
	for (Link pi=head; pi!=NULL; pi=pi->next) {
        for (Link pj=pi->next; pj!=NULL; pj=pj->next) {
            if((pj->number)>(pj->next->number)) {

            }
        }
	}
	for(pi=head->next ; pi ; pi=pi->next)
	{
		for(pj=pi->next ; pj ;pj=pj->next)
			if((pi->number)>(pj->number))
			{
				t = *pi;
                *pi = *pj;
            	*pj = t;

                pt = pi->next;
                pi->next = pj->next;
                pj->next = pt;
			}
	}
	printf("排序完成");
	system("cls");
}

void  print(Link head)
{
	Link p = head;
    printf("\t\t----------学生信息-----------\n");
	printf("学号\t姓名\t\t学院\t\t成绩\n");
	while (p != NULL) {
		printf("%s\t%s\t\t%s\t\t%d\n",p->number,p->name,p->college,p->score);
		p = p->next;
    }
    printf("\n\n");
	system("pause");
}

int secret()
{
	int i,j;
	char a[7];
	for(i=0;i<3;i++)
	{
		for(j=0;j<6;j++)
		{
			a[j]=getch();
			printf("*");
		}
		printf("\n");
		a[6]='\0';
		getch();
		fflush(stdin);
		if(strcmp(a,"111111") == 0)
			return 1;
		system("cls");
		printf("密码错误，您还可以输入%d次\n",3-i);
		printf("请输入密码（六位）:");
	}
	return 0;
}

int main(void)
{
    Link head;
	int flag=0;
	char username[10], choice;
	printf("----------------------学生评教系统-------------------\n");
    printf("请输入用户名:");
	scanf("%s", username);
	printf("请输入密码（六位）:");
	//if(secret()==1)
	{
		printf("\n\n\n密码输入正确！！\n\n");
		system("pause");
		system("cls");
		printf("--------------------欢迎登录学生评教系统-------------------\n\n");
		printf("录入学生信息\n");
		head = creat_list();
		printf("按任意键返回主菜单!");
	    getch();
	    fflush(stdin);
		system("cls");
		do
		{
			system("cls");
			printf("-----------------------------------欢迎来到主菜单-------------------------------\n");
			printf("-----------------------------------1.  修改信息---------------------------------\n");
			printf("-----------------------------------2.  删除信息---------------------------------\n");
			printf("-----------------------------------3.   查询   ---------------------------------\n");
			printf("-----------------------------------4.   排序   ---------------------------------\n");
			printf("-----------------------------------5.   打印   ---------------------------------\n");
			printf("-----------------------------------0.  退出系统---------------------------------\n\n\n");

			choice = getch();
			fflush(stdin);
			system("cls");
			switch(choice)
			{
			case '1': changeNode(head);
				break;
			case '2': removeNode(head);
				break;
			case '3':search(head);
				break;
			case '4':sortbynum(head);
				break;
			case '5':print(head);
				break;
			case '0':flag=1;
				break;
			}
		}while(flag!=1);
	}
		system("pause");
		return 0;
}




















