#ifndef MAZE_H
#define MAZE_H

#include "Pint_.h"
#include <windows.h>

#define MaxSize 27	    ///�Թ������

const int offset[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}}; /// �����Թ�ʱ��

typedef struct Node{
    int x, y;
}node;

class Maze {
public:
    Maze();
    ~Maze();
    void menue();

private:
    void maprand(int , int);                /// �����Թ�
    void printmap1();                       /// ��ʾ�Թ�
    void printmap2();                       /// ��սģʽ�´�ӡ�Թ�
    void print_history();                   /// ��ӡ��ʷ��¼
    void print_record();                    /// ��ӡ��߼�¼
    void print_role(bool);                  /// ��ӡ����
    bool walk(int, int);                    /// ��ǰ�ڵ��Ƿ����
    void tip(int&,int&, int&, int&);        /// ��ʾ
    void peoplefind(bool=true);             /// ����ģʽ������
    void automode();                        /// �Զ���ģʽ������
    void challenge();                       /// ��սģʽ������
    void head();                            /// ��ӡ�����ͷ
    void mode_menue();                      /// ģʽ����
    void diff_menue();                      /// �Ѷ�����
    void reset(int&, int&);                 /// �ҵ�ǰ�ڵ����һ���ɴ����ڵ㣨������
    bool find_nearest();                    /// �����·��
    void save();                            /// �浵
    void gotoxy(HANDLE hOut, int x, int y); /// ���


private:
    Pint_ welcom;
    bool graph1[MaxSize][MaxSize], graph2[MaxSize][MaxSize]; /// ������ͼ
    int key[MaxSize][MaxSize];              /// �����������·��
    int exit1, exit2, entrance1, entrance2; /// ���ں��������
    int difficulty;                         /// �Ѷȵȼ���Ϊ������
    int mode;                               /// ģʽ����Ϊ���֣���ս�����䣬�Զ���
    int mapsize;                            /// ��ǰ�Թ���ͼ����
    int count;                              /// �����Թ�ʱ������
    node record[2][3];                      /// ������߼�¼
};

#endif // MAZE_H

