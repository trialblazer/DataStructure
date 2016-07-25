#ifndef LIST_H
#define LIST_H

//#include <stdio.h>

#define AS_MaxSize 6             ///�˺�, ѧ��,ͼ���ų���
#define MC_MaxSize 100          ///�ͻ�������
#define NP_MaxSize 50           ///�û�����󳤶ȣ�������󳤶�,
#define MS_MaxSize 20           ///����Ա����
#define Bb_MaxSize 15           ///��������
#define Major_MaxSize 10        ///һ��ѧԺ�е����רҵ����
#define Class_MaxSize  10       ///һ��רҵ�е����༶����
#define Talk_MaxSize  200      ///ͼ��������

struct Institute {
    char name[NP_MaxSize];       //ѧԺ��
    char major[Major_MaxSize][Major_MaxSize];   //����רҵ
    int num;                        //��ǰרҵ��
    int class_num[Class_MaxSize];  //ÿ��רҵ�����༶��
    void init() {
        num = 0;
    }
};

///�洢ѧԺ��רҵ���༶���꼶����Ϣ
struct Inform {
    char institu_name[NP_MaxSize];    //ѧԺ
    int index;     //����רҵ��ѧԺ�е�λ��
    int grade;      //�꼶
    int class_;   //�༶
};


struct Client {
    char account[AS_MaxSize];                   //�˺�
    char sid[AS_MaxSize];                       //ѧ��
    char name[NP_MaxSize];                      //����
    char passwords[NP_MaxSize];                 //����
    struct Inform inform;                       //������Ϣ
};

struct Server {
    char account[AS_MaxSize];
    char passwords[NP_MaxSize];
};

struct Date {
    int year;
    int month;
    int day;
};

struct Book {
    char name[NP_MaxSize];  //ͼ����
    char introducation[Talk_MaxSize]; //ͼ����
    char author[NP_MaxSize];  //����
    char price[AS_MaxSize*2];      //�۸�
    char book_num[AS_MaxSize];  //ͼ����
    char origin[NP_MaxSize];  //ͼ������
    char num[3];               //ͼ���ܸ���
};


struct LendBook {
    char book_num[AS_MaxSize];  //��ı��
    char name[NP_MaxSize];      //�������
    struct Date begin_;          //����ʱ����ʼֵ
    char user_name[NP_MaxSize];  //���ͼ���˵�����
    char user_account[AS_MaxSize];  //���ͼ���˵��˺�
};
#endif // LIST_H
