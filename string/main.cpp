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

//�ϲ�����a(������b1��ʼ,��СΪsize1)������b(������b2��ʼ,��СΪsize2),�ϲ����������c;
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

struct Student//����ṹ��
{
    char number[10];
    char name[10];
    char college[20];
    float score;
    struct Student* next;
};

typedef struct Student node;//ʹnode��ʾstruct Student ����
typedef node* Link;//link��Ϊstruct Student*����

Link creat_list(Link head);                     //ʵ��¼�빦��
void save(Link head);                           //��������
void removeNode(Link head);                     //ʵ��ɾ������
void changeNode(Link head);                     //ʵ���޸Ĺ���
void free(Link head);                           //��������
Link findpreNode(char* number, Link head);      //��ѧ�Ų���
Link findprenode(char* name, Link head);        //�����Ʋ���
void search(Link head);                         //��ѯ
void sortbynum(Link head);                      //ʵ��������
void print(Link head);                          //��ӡ����
int secret();                                   //���ܹ���

/*void save(Link head)
{
	Link p;
	FILE *fp;
	int size;
	size=sizeof(node);
	fp=fopen("D:\\cyuyan.txt","r");
	if(fp==NULL)
		printf("�ļ���ȡ����!");
	for(p=head->next;p!=NULL;p=p->next)
		fwrite(p;size;1;fp);
	printf("����ɹ�!");
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
		printf("�ļ���ʧ��!");
    Link add = (Link)malloc(sizeof(node));
    if (add == NULL)
	{
        printf("memory allocate failure!\n");
		exit(1);
    }
    printf("������ѧ��������Ϣ,����Ϊ��ѧ��,����,ѧԺ,���̳ɼ�������0������:\n");
	fprintf(fp,"ѧ��\t\t����\t\tѧԺ\t\t���̳ɼ�\n");
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
	printf("������Ҫɾ����Ϣ��ѧ����ѧ��:\n");
	scanf("%s",oldnumber);
	fflush(stdin);
	Link p = findpreNode(oldnumber, head);
	if (p == NULL) {
        printf("ɾ��ʧ�ܣ���\n");
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
	printf("������Ҫ�޸ĵ�ѧ����ѧ��:\n");
	scanf("%s",oldnumber);
	fflush(stdin);
	Link p = findpreNode(oldnumber, head);
	if (p == NULL) {
        printf("û���ҵ����û���\n");
        return;
	}
	printf("����������Ϣ(ѧ�ţ�������ѧԺ���ɼ�):\n");
	scanf("%s,%s,%s,%f",newnumber,newname,newcollege,&newscore);
	fflush(stdin);
    strcpy(p->number, newnumber);
    strcpy(p->name, newname);
    strcpy(p->college, newcollege);
    p->score = newscore;
    printf("______________________\n�������������޸ĳɹ�!������������");
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
        printf("�ļ�Ϊ�գ�\n\n");
        system("pause");
        return;
	}
	char number[10],name[10], choice;
	Link p = 0;
	printf("\t\t-------------��ѯ����--------------\n");
	printf("\t\t------------1.��ѧ�Ų�ѯ-----------\n");
	printf("\t\t------------2.��������ѯ-----------\n");
	printf("\t\t------------0.  �˳�---------------\n");
	choice = getch();
	fflush(stdin);
	switch(choice)
	{
		case '1': {
            printf("������Ҫ��ѯ��ѧ��\n");
            scanf("%s",number);
            fflush(stdin);
            p = findpreNode(number, head);
            break;
        }
		case '2': {
            printf("������ѧ������:");
            scanf("%s",name);
            fflush(stdin);
            Link p = findprenode(name, head);
            break;
        }
		case '0':
			break;
	}
	if(p == NULL) {
        printf("����ʧ�ܣ���\n\n");
    } else {
        printf("��ѧ������ϢΪ��\n");
        printf("ѧ�ţ�\t����:\tѧԺ��\t���̳ɼ�:\t");
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
	printf("�������");
	system("cls");
}

void  print(Link head)
{
	Link p = head;
    printf("\t\t----------ѧ����Ϣ-----------\n");
	printf("ѧ��\t����\t\tѧԺ\t\t�ɼ�\n");
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
		printf("�������������������%d��\n",3-i);
		printf("���������루��λ��:");
	}
	return 0;
}

int main(void)
{
    Link head;
	int flag=0;
	char username[10], choice;
	printf("----------------------ѧ������ϵͳ-------------------\n");
    printf("�������û���:");
	scanf("%s", username);
	printf("���������루��λ��:");
	//if(secret()==1)
	{
		printf("\n\n\n����������ȷ����\n\n");
		system("pause");
		system("cls");
		printf("--------------------��ӭ��¼ѧ������ϵͳ-------------------\n\n");
		printf("¼��ѧ����Ϣ\n");
		head = creat_list();
		printf("��������������˵�!");
	    getch();
	    fflush(stdin);
		system("cls");
		do
		{
			system("cls");
			printf("-----------------------------------��ӭ�������˵�-------------------------------\n");
			printf("-----------------------------------1.  �޸���Ϣ---------------------------------\n");
			printf("-----------------------------------2.  ɾ����Ϣ---------------------------------\n");
			printf("-----------------------------------3.   ��ѯ   ---------------------------------\n");
			printf("-----------------------------------4.   ����   ---------------------------------\n");
			printf("-----------------------------------5.   ��ӡ   ---------------------------------\n");
			printf("-----------------------------------0.  �˳�ϵͳ---------------------------------\n\n\n");

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




















