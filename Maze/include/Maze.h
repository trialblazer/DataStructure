#ifndef MAZE_H
#define MAZE_H

#include "Pint_.h"
#include <windows.h>

#define MaxSize 27	    ///迷宫的最大

const int offset[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}}; /// 生成迷宫时用

typedef struct Node{
    int x, y;
}node;

class Maze {
public:
    Maze();
    ~Maze();
    void menue();

private:
    void maprand(int , int);                /// 生成迷宫
    void printmap1();                       /// 显示迷宫
    void printmap2();                       /// 挑战模式下打印迷宫
    void print_history();                   /// 打印历史记录
    void print_record();                    /// 打印最高记录
    void print_role(bool);                  /// 打印规则
    bool walk(int, int);                    /// 当前节点是否可走
    void tip(int&,int&, int&, int&);        /// 提示
    void peoplefind(bool=true);             /// 经典模式处理函数
    void automode();                        /// 自定义模式处理函数
    void challenge();                       /// 挑战模式处理函数
    void head();                            /// 打印界面的头
    void mode_menue();                      /// 模式设置
    void diff_menue();                      /// 难度设置
    void reset(int&, int&);                 /// 找当前节点的下一个可创建节点（创建）
    bool find_nearest();                    /// 找最短路径
    void save();                            /// 存档
    void gotoxy(HANDLE hOut, int x, int y); /// 句柄


private:
    Pint_ welcom;
    bool graph1[MaxSize][MaxSize], graph2[MaxSize][MaxSize]; /// 比赛地图
    int key[MaxSize][MaxSize];              /// 用来保存最短路径
    int exit1, exit2, entrance1, entrance2; /// 出口和入口坐标
    int difficulty;                         /// 难度等级分为三级，
    int mode;                               /// 模式，分为三种，挑战，经典，自定义
    int mapsize;                            /// 当前迷宫地图长度
    int count;                              /// 生成迷宫时计数用
    node record[2][3];                      /// 保存最高记录
};

#endif // MAZE_H

