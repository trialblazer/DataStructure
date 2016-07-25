#ifndef LIST_H
#define LIST_H

//#include <stdio.h>

#define AS_MaxSize 6             ///账号, 学号,图书编号长度
#define MC_MaxSize 100          ///客户端上限
#define NP_MaxSize 50           ///用户名最大长度，密码最大长度,
#define MS_MaxSize 20           ///管理员上限
#define Bb_MaxSize 15           ///借书上限
#define Major_MaxSize 10        ///一个学院中的最大专业数量
#define Class_MaxSize  10       ///一个专业中的最大班级数量
#define Talk_MaxSize  200      ///图书简介上限

struct Institute {
    char name[NP_MaxSize];       //学院名
    char major[Major_MaxSize][Major_MaxSize];   //所含专业
    int num;                        //当前专业数
    int class_num[Class_MaxSize];  //每个专业所含班级数
    void init() {
        num = 0;
    }
};

///存储学院，专业，班级，年级的信息
struct Inform {
    char institu_name[NP_MaxSize];    //学院
    int index;     //所在专业在学院中的位次
    int grade;      //年级
    int class_;   //班级
};


struct Client {
    char account[AS_MaxSize];                   //账号
    char sid[AS_MaxSize];                       //学号
    char name[NP_MaxSize];                      //名称
    char passwords[NP_MaxSize];                 //密码
    struct Inform inform;                       //其他信息
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
    char name[NP_MaxSize];  //图书名
    char introducation[Talk_MaxSize]; //图书简介
    char author[NP_MaxSize];  //作者
    char price[AS_MaxSize*2];      //价格
    char book_num[AS_MaxSize];  //图书编号
    char origin[NP_MaxSize];  //图书种类
    char num[3];               //图书总个数
};


struct LendBook {
    char book_num[AS_MaxSize];  //书的编号
    char name[NP_MaxSize];      //书的名字
    struct Date begin_;          //借书时间起始值
    char user_name[NP_MaxSize];  //借出图书人的名字
    char user_account[AS_MaxSize];  //借出图书人的账号
};
#endif // LIST_H
