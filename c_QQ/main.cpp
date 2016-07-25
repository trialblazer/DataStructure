#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define Maxcount 4                          //账号大小，实际为3
char key[10];                               //用户密码；

bool apply();                               //用户账号申请；
bool landing();                             //用户账号登陆；
void friends();                             //添加好友
void group();                               //好友分组；
void set(int);                              //设置消息中的时间
void addper_g(char *count, int num);        //在Gro[num]中添加账号count
void delper_g(char *count, int num);        //在Gro[num]中删除账号count
void prin_mess(int j);                      //打印用户Q[j]的所有消息
bool addgroup();                            //添加分组
char * print(int i);                         //昵称为空时返回账号，否则返回昵称
void prin_all();                            //打印Q[0]，也就是‘我’的所有好友
int find(char *count, char *g_name);        //在组中查找好友，返回好友的序号（g_name保存所在组的名称）
int find(char *count);                      //在总好友中查找，返回所查好友在总好友中的次序
void show_g();                              //组中操作菜单
void land_menue();                          //好友操作菜单
void menue();                               //主菜单

struct TIME//定义时间结构体
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

struct Mess //消息
{
    TIME t[20];          //所发消息的时间
    char mess[20][100];  //消息的内容
    char rm[20][20];     //消息的来源
    int mess_size;       //当前消息的个数
};

struct QQINFO  //单个用户信息
{
    char Num[Maxcount]; //用户账号
    char Name[20];    //用户昵称
    int Age;         //用户年龄
    char Sex[10];   //用户性别
    char Pro[20];   //用户所在省份
    char City[20];  //用户所在城市
    char Sign[40];  //用户个性签名
    Mess message;  //用户的消息
} Q[10];
int user_size = 0;  //总共用户的个数

struct Group //分组
{
    char Name[20];        //组的名称
    char h[10][Maxcount];  //组中保存的账号
    int size;                //记录当前组中好有个数
    bool off_on;        //组是打开还是关闭
} Gro[10];
int currentsize = 1; //记录当前组的个数


int main()
{
    menue();
    return 0;
}

bool apply()
{
    system("cls");
    strcpy(Gro[0].Name, "我的好友");
    Gro[0].off_on = false;
    Gro[0].size = 0;
    Q[0].message.mess_size =  0;
    //以上为对结构体中的成员初始化

    if (user_size != 0) //只能申请一次账号
        return false;
    int a;
    char K[10];
    printf("\t\t---------------------Wlcome-------------------\n");
    printf("\t\t--------------------QQ账号申请----------------\n\n\n");
    printf("请输入您的QQ信息：(3位数字)\n");
    do
    {
        scanf("%s", Q[0].Num);
    }
    while (strlen(Q[0].Num) != Maxcount-1);
loop:
    a=0;
    printf("\n请输入您的密码：");
    scanf("%s", key);
    printf("\n请再次输入：");
    scanf("%s", K);
    fflush(stdin);
    if(strcmp(key,K)==0)
    {
        system("cls");
        printf("恭喜您！成功获得一个新的账号!按Q完善你的信息。");
        user_size++;
        char tmpt;
        scanf("%c", &tmpt);
        if (tmpt == 'q' || tmpt == 'Q')
        {
            printf("\n请输入对应QQ号码的信息，依次为:昵称、性别、年龄、省、市、个性签名。\n");
            scanf("%s %s %d %s %s %s",Q[0].Name, Q[0].Sex, &Q[0].Age,Q[0].Pro, Q[0].City, Q[0].Sign);
        }
        return true;
    }
    else
    {
        printf("两次密码输入不相同，请重新输入！");
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
        printf("\t\t-------------------QQ账号登陆----------------\n\n\n");
        printf("请输入您的QQ账号：");
        do
        {
            scanf("%s", num);
        }
        while (strlen(num) != Maxcount-1);
        if(strcmp(num, Q[0].Num) != 0)
        {
            printf("账号输入错误！没有这个账号！按q退出登陆\n");
            char t = getch();
            if (t == 'q' || t == 'Q')
                return false;
            system("cls");
            continue;
        }
        printf("\n请输入您的密码：");
loop:
        scanf("%s", K1);
        if(strcmp(K1,key)==0)
            return true;
        else
        {
            printf("密码错误，请重新输入：");
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
    printf("请输入您要添加的好友的人数：");
    scanf("%d",&count);
    system("cls");
    printf("\n\t\t--------------------好友信息录入----------------------\n");
    for(i=0; i<count; i++)
    {
        int j = user_size++;
        printf("请输入QQ号码: ");
        do
        {
            scanf("%s", Q[j].Num);
        }
        while (strlen(Q[j].Num) != Maxcount-1);
        printf("\n请输入对应QQ号码的信息，依次为:昵称、性别、年龄、省、市、个性签名。\n");
        scanf("%s %s %d %s %s %s",Q[j].Name, Q[j].Sex, &Q[j].Age,Q[j].Pro, Q[j].City, Q[j].Sign);
        addper_g(Q[j].Num, 0);
        Q[j].message.mess_size = 0;
    }
    printf("添加成功");
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
    printf("请输入新建组的名称：");
    if (currentsize < 10)
    {
        Gro[currentsize].size = 0;
        gets(Gro[currentsize++].Name);
        printf("添加成功\n");
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
        printf("1.打开\关闭分组\n2.移动好友\n3.显示好友资料\n4.查找好友\n5.显示全部好友\n");
        printf("6.发送消息\n7.查看消息\n");
        char choice = getch();
        fflush(stdin);
        switch(choice)
        {
        case '1':
        {
            printf("\n\n请输入要打开\关闭的组的序号：");
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
            printf("\n\n请输入要移动的好友账号：");
            char cou[Maxcount], p[20];
            scanf("%s", cou);
            printf("请输入移动好友最终的组的序号：");
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
            printf("\n\n请输入该好友的账号：");
            char cou[Maxcount];
            scanf("%s", cou);
            system("cls");
            int g = find(cou);
            if (g == -1)
                printf("没有查找到该好友！\n");
            else
                printf("昵称：%s\nQQ号码：%s\n性别：%s\n年龄：%d\n省：%s\n市：%s\n个性签名：%s\n",Q[g].Name,Q[g].Num,Q[g].Sex,Q[g].Age,Q[g].Pro,Q[g].City, Q[g].Sign);
            system("pause");
            break;
        }
        case '4':
        {
            if (user_size < 2)
                break;
            printf("\n\n请输入要查找的好友账号：");
            char cou[Maxcount];
            scanf("%s", cou);
            char name[20];
            int g = find(cou, name);
            printf("该好友所在的组名：  %s\n在该组中的序号为：%d\n", name, g+1);
            system("pause");
            break;
        }
        case '5':
            return;
        case '6':
        {
            printf("\n\n请输入用发送消息的好友的账号：");
            char cou[Maxcount];
            scanf("%s", cou);
            int g = find(cou);
            system("cls");
            if (g == -1)
            {
                printf("没有找到该好友！\n");
                break;
            }
            else
            {
                printf("消息：");
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
            printf("\n\n请输入该好友的账号：");
            char cou[Maxcount];
            gets(cou);
            fflush(stdin);
            int g = find(cou);
            if (g==-1)
            {
                printf("没有找到该好友!\n");
                break;
            }
            else
            {
                if (Q[g].message.mess_size == 0)
                {
                    printf("消息为空！\n");
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
        printf("\n\n1.显示组\n2.显示我的资料\n3.添加好友\n4.添加分组\n0.退出\n");
        char choice = getch();
        fflush(stdin);
        switch(choice)
        {
        case '1':
            show_g();
            break;
        case '2':
            printf("\n\n昵称：%s\nQQ号码：%s\n性别：%s\n年龄：%d\n省：%s\n市：%s\n个性签名：%s\n",Q[0].Name,Q[0].Num,Q[0].Sex,Q[0].Age,Q[0].Pro,Q[0].City, Q[0].Sign);
            system("pause");
            break;
        case '3':
            friends();
            break;
        case '4':
            if (!addgroup())
            {
                printf("添加失败！\n");
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
        printf("1.登陆\n2.注册\n0.退出\n");
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
                printf("不能再申请，抱歉！\n");
            system("pause");
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}

