#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define Maxcount 4                          //�˺Ŵ�С��ʵ��Ϊ3
char key[10];                               //�û����룻

bool apply();                               //�û��˺����룻
bool landing();                             //�û��˺ŵ�½��
void friends();                             //��Ӻ���
void group();                               //���ѷ��飻
void set(int);                              //������Ϣ�е�ʱ��
void addper_g(char *count, int num);        //��Gro[num]������˺�count
void delper_g(char *count, int num);        //��Gro[num]��ɾ���˺�count
void prin_mess(int j);                      //��ӡ�û�Q[j]��������Ϣ
bool addgroup();                            //��ӷ���
char * print(int i);                         //�ǳ�Ϊ��ʱ�����˺ţ����򷵻��ǳ�
void prin_all();                            //��ӡQ[0]��Ҳ���ǡ��ҡ������к���
int find(char *count, char *g_name);        //�����в��Һ��ѣ����غ��ѵ���ţ�g_name��������������ƣ�
int find(char *count);                      //���ܺ����в��ң���������������ܺ����еĴ���
void show_g();                              //���в����˵�
void land_menue();                          //���Ѳ����˵�
void menue();                               //���˵�

struct TIME//����ʱ��ṹ��
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

struct Mess //��Ϣ
{
    TIME t[20];          //������Ϣ��ʱ��
    char mess[20][100];  //��Ϣ������
    char rm[20][20];     //��Ϣ����Դ
    int mess_size;       //��ǰ��Ϣ�ĸ���
};

struct QQINFO  //�����û���Ϣ
{
    char Num[Maxcount]; //�û��˺�
    char Name[20];    //�û��ǳ�
    int Age;         //�û�����
    char Sex[10];   //�û��Ա�
    char Pro[20];   //�û�����ʡ��
    char City[20];  //�û����ڳ���
    char Sign[40];  //�û�����ǩ��
    Mess message;  //�û�����Ϣ
} Q[10];
int user_size = 0;  //�ܹ��û��ĸ���

struct Group //����
{
    char Name[20];        //�������
    char h[10][Maxcount];  //���б�����˺�
    int size;                //��¼��ǰ���к��и���
    bool off_on;        //���Ǵ򿪻��ǹر�
} Gro[10];
int currentsize = 1; //��¼��ǰ��ĸ���


int main()
{
    menue();
    return 0;
}

bool apply()
{
    system("cls");
    strcpy(Gro[0].Name, "�ҵĺ���");
    Gro[0].off_on = false;
    Gro[0].size = 0;
    Q[0].message.mess_size =  0;
    //����Ϊ�Խṹ���еĳ�Ա��ʼ��

    if (user_size != 0) //ֻ������һ���˺�
        return false;
    int a;
    char K[10];
    printf("\t\t---------------------Wlcome-------------------\n");
    printf("\t\t--------------------QQ�˺�����----------------\n\n\n");
    printf("����������QQ��Ϣ��(3λ����)\n");
    do
    {
        scanf("%s", Q[0].Num);
    }
    while (strlen(Q[0].Num) != Maxcount-1);
loop:
    a=0;
    printf("\n�������������룺");
    scanf("%s", key);
    printf("\n���ٴ����룺");
    scanf("%s", K);
    fflush(stdin);
    if(strcmp(key,K)==0)
    {
        system("cls");
        printf("��ϲ�����ɹ����һ���µ��˺�!��Q���������Ϣ��");
        user_size++;
        char tmpt;
        scanf("%c", &tmpt);
        if (tmpt == 'q' || tmpt == 'Q')
        {
            printf("\n�������ӦQQ�������Ϣ������Ϊ:�ǳơ��Ա����䡢ʡ���С�����ǩ����\n");
            scanf("%s %s %d %s %s %s",Q[0].Name, Q[0].Sex, &Q[0].Age,Q[0].Pro, Q[0].City, Q[0].Sign);
        }
        return true;
    }
    else
    {
        printf("�����������벻��ͬ�����������룡");
        goto loop;
    }
}

bool landing()
{
    system("cls");
    char num[Maxcount];
    char K1[10];
    system("cls");
    while(1)
    {
        printf("\t\t---------------------Welcome----------------\n");
        printf("\t\t-------------------QQ�˺ŵ�½----------------\n\n\n");
        printf("����������QQ�˺ţ�");
        do
        {
            scanf("%s", num);
        }
        while (strlen(num) != Maxcount-1);
        if(strcmp(num, Q[0].Num) != 0)
        {
            printf("�˺��������û������˺ţ���q�˳���½\n");
            char t = getch();
            if (t == 'q' || t == 'Q')
                return false;
            system("cls");
            continue;
        }
        printf("\n�������������룺");
loop:
        scanf("%s", K1);
        if(strcmp(K1,key)==0)
            return true;
        else
        {
            printf("����������������룺");
            goto loop;
        }
        getch();
    }
}

void set(int i)
{
    long n;
    struct tm rt;
    time(&n);
    rt = *(localtime(&n));
    int j = Q[i].message.mess_size;
    Q[i].message.t[j].year = rt.tm_year+1900;
    Q[i].message.t[j].month = rt.tm_mon+1;
    Q[i].message.t[j].day = rt.tm_mday;
    Q[i].message.t[j].hour = rt.tm_hour;
    Q[i].message.t[j].minute = rt.tm_min;
    Q[i].message.t[j].second = rt.tm_sec;
}

void addper_g(char *count, int num)
{
    int s = Gro[num].size++;
    strcpy(Gro[num].h[s], count);
}

void delper_g(char *count, int num)
{
    int i, s = Gro[num].size;
    for (i=0; i<s; i++)
    {
        if (strcmp(count, Gro[num].h[i]) == 0)
            break;
    }
    if (i<s)
    {
        strcpy(Gro[num].h[i], Gro[num].h[s-1]);
        Gro[num].size--;
    }
}

void friends()
{
    system("cls");
    int i, count;
    printf("��������Ҫ��ӵĺ��ѵ�������");
    scanf("%d",&count);
    system("cls");
    printf("\n\t\t--------------------������Ϣ¼��----------------------\n");
    for(i=0; i<count; i++)
    {
        int j = user_size++;
        printf("������QQ����: ");
        do
        {
            scanf("%s", Q[j].Num);
        }
        while (strlen(Q[j].Num) != Maxcount-1);
        printf("\n�������ӦQQ�������Ϣ������Ϊ:�ǳơ��Ա����䡢ʡ���С�����ǩ����\n");
        scanf("%s %s %d %s %s %s",Q[j].Name, Q[j].Sex, &Q[j].Age,Q[j].Pro, Q[j].City, Q[j].Sign);
        addper_g(Q[j].Num, 0);
        Q[j].message.mess_size = 0;
    }
    printf("��ӳɹ�");
    system("pause");
}

void prin_mess(int j)
{
    system("cls");
    int i;
    for (i=0; i<Q[j].message.mess_size; i++)
    {
        printf("\t\t%d:%d:%d\n", Q[j].message.t[i].hour, Q[j].message.t[i].minute, Q[j].message.t[i].second);
        printf("%s  :  %s\n", Q[j].message.rm[i], Q[j].message.mess[i]);
    }
    system("pause");
}

bool addgroup()
{
    system("cls");
    printf("�������½�������ƣ�");
    if (currentsize < 10)
    {
        Gro[currentsize].size = 0;
        gets(Gro[currentsize++].Name);
        printf("��ӳɹ�\n");
        system("pause");
        return true;
    }
    return false;
}


char * print(int i)
{
    return strcmp(Q[i].Name, "")==0?  (Q[i].Num):(Q[i].Name);
}


void prin_all()
{
    int i;
    for (i=1; i<user_size; i++)
        printf("%d  :  %s\n", i, print(i));
}


int find(char *count, char *g_name)
{
    int i;
    for (i=0; i<currentsize; i++)
    {
        int j;
        for (j=0; j<Gro[i].size; j++)
        {
            if (strcmp(Gro[i].h[j], count) == 0)
            {
                strcpy(g_name, Gro[i].Name);
                return j;
            }
        }
    }
    return -1;
}

int find(char *count)
{
    int i;
    for (i=1; i<user_size; i++)
    {
        if (strcmp(Q[i].Num, count) == 0)
            return i;
    }
    return -1;
}

void show_g()
{
    while (1)
    {
        system("cls");
        int i;
        for (i=0; i<currentsize; i++)
        {
            printf("%d   :   %s\n", i+1, Gro[i].Name);
            if (Gro[i].off_on == true)
            {
                int j;
                for (j=0; j<Gro[i].size; j++)
                {
                    printf("  %d) :  %s\n", j+1, Gro[i].h[j]);
                }
            }
        }
        printf("\n\n");
        printf("1.��\�رշ���\n2.�ƶ�����\n3.��ʾ��������\n4.���Һ���\n5.��ʾȫ������\n");
        printf("6.������Ϣ\n7.�鿴��Ϣ\n");
        char choice = getch();
        fflush(stdin);
        switch(choice)
        {
        case '1':
        {
            printf("\n\n������Ҫ��\�رյ������ţ�");
            int index;
            scanf("%d", &index);
            system("cls");
            Gro[index-1].off_on = Gro[index-1].off_on == true? false:true;
            break;
        }
        case '2':
        {
            if (user_size < 2)
                break;
            printf("\n\n������Ҫ�ƶ��ĺ����˺ţ�");
            char cou[Maxcount], p[20];
            scanf("%s", cou);
            printf("�������ƶ��������յ������ţ�");
            int index, i;
            scanf("%d", &index);
            addper_g(cou, index-1);
            find(cou, p);
            for (i=0; i<currentsize; i++)
                if (strcmp(p, Gro[i].Name) == 0)
                    break;
            delper_g(cou, i);
            break;
        }
        case '3':
        {
            if (user_size < 2)
                break;
            printf("\n\n������ú��ѵ��˺ţ�");
            char cou[Maxcount];
            scanf("%s", cou);
            system("cls");
            int g = find(cou);
            if (g == -1)
                printf("û�в��ҵ��ú��ѣ�\n");
            else
                printf("�ǳƣ�%s\nQQ���룺%s\n�Ա�%s\n���䣺%d\nʡ��%s\n�У�%s\n����ǩ����%s\n",Q[g].Name,Q[g].Num,Q[g].Sex,Q[g].Age,Q[g].Pro,Q[g].City, Q[g].Sign);
            system("pause");
            break;
        }
        case '4':
        {
            if (user_size < 2)
                break;
            printf("\n\n������Ҫ���ҵĺ����˺ţ�");
            char cou[Maxcount];
            scanf("%s", cou);
            char name[20];
            int g = find(cou, name);
            printf("�ú������ڵ�������  %s\n�ڸ����е����Ϊ��%d\n", name, g+1);
            system("pause");
            break;
        }
        case '5':
            return;
        case '6':
        {
            printf("\n\n�������÷�����Ϣ�ĺ��ѵ��˺ţ�");
            char cou[Maxcount];
            scanf("%s", cou);
            int g = find(cou);
            system("cls");
            if (g == -1)
            {
                printf("û���ҵ��ú��ѣ�\n");
                break;
            }
            else
            {
                printf("��Ϣ��");
                scanf("%s", Q[g].message.mess[Q[g].message.mess_size]);
                set(g);
                if (strlen(Q[0].Name) == 0)
                    strcpy(Q[g].message.rm[Q[g].message.mess_size++], Q[0].Num);
                else
                    strcpy(Q[g].message.rm[Q[g].message.mess_size++], Q[0].Name);
            }
            break;
        }
        case '7':
        {
            printf("\n\n������ú��ѵ��˺ţ�");
            char cou[Maxcount];
            gets(cou);
            fflush(stdin);
            int g = find(cou);
            if (g==-1)
            {
                printf("û���ҵ��ú���!\n");
                break;
            }
            else
            {
                if (Q[g].message.mess_size == 0)
                {
                    printf("��ϢΪ�գ�\n");
                    system("pause");
                }
                else
                    prin_mess(g);
            }
            break;
        }
        default:
            break;
        }
    }
}

void land_menue()
{
    while (1)
    {
        system("cls");
        prin_all();
        printf("\n\n1.��ʾ��\n2.��ʾ�ҵ�����\n3.��Ӻ���\n4.��ӷ���\n0.�˳�\n");
        char choice = getch();
        fflush(stdin);
        switch(choice)
        {
        case '1':
            show_g();
            break;
        case '2':
            printf("\n\n�ǳƣ�%s\nQQ���룺%s\n�Ա�%s\n���䣺%d\nʡ��%s\n�У�%s\n����ǩ����%s\n",Q[0].Name,Q[0].Num,Q[0].Sex,Q[0].Age,Q[0].Pro,Q[0].City, Q[0].Sign);
            system("pause");
            break;
        case '3':
            friends();
            break;
        case '4':
            if (!addgroup())
            {
                printf("���ʧ�ܣ�\n");
                system("pause");
            }
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}

void menue()
{
    while (1)
    {
        system("cls");
        printf("1.��½\n2.ע��\n0.�˳�\n");
        char choice = getch();
        fflush(stdin);
        switch(choice)
        {
        case '1':
            if (landing())
                land_menue();
            break;
        case '2':
            if(!apply())
                printf("���������룬��Ǹ��\n");
            system("pause");
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}

