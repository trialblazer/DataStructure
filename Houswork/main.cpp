#include "Calculate.h"

int main()
{
    Calculate my;
    my.calculate();
    return 0;
}






































/*#include <stdio.h>
#include <windows.h>

#define Max 16

typedef struct ListNode{
    int X;
    int Y;
    int sign;   /// ��ǰ�ڵ����������һ���ڵ��p[sign]���ֵ����x = x1+p[sign].x; y = x2+p[sign].y
    struct ListNode* Next;
}ListNode, *Link;
///��������ģ��ջ��
struct List{
    Link head;
    Link tail;

    List();
    ~List();
    bool isEmpty() {return (head->Next == tail);}
    bool push(int m, int n, int s);
    bool pop();
    void prin();
    void getfront(int &x, int &y);
    int getsign();
};

List::List() {
    head = (Link)malloc(sizeof(ListNode));
    if (head == NULL) {
        printf("Memory allocate failure!!");
        Sleep(3000);
        exit(1);
    }
    tail = NULL;
    head->X = -1;
    head->Y = -2;
    head->sign = -1;
    head->Next = tail;
}

List::~List() {
    while (isEmpty())
        pop();
}

bool List::push(int m, int n, int s) {
    Link add = (Link)malloc(sizeof(ListNode));
    if (add == NULL) {
        printf("Memory allocate failure!!");
        Sleep(3000);
        return false;
    }
    add->X = m;
    add->Y = n;
    add->sign = s;
    add->Next = head->Next;
    head->Next = add;
    return true;
}

bool List::pop() {
    if (isEmpty())
        return false;
    Link tmpt = head->Next;
    head->Next = tmpt->Next;
    free(tmpt);
    return true;
}
/// ��ӡ����
void List::prin() {
    Link pointer = head->Next;
    while (pointer != NULL) {
        printf("[%d,%d]", pointer->X, pointer->Y);
        if (pointer->Next != NULL)
            printf("-->");
        pointer = pointer->Next;
    }
}
/// ��ȡջ��Ԫ�صı��
int List::getsign() {
    Link pointer = head->Next;
    return pointer->sign;
}
/// ��ȡջ����Ԫ��
void List::getfront(int &x, int &y) {
    x = head->Next->X;
    y = head->Next->Y;
}




/// ���̽ṹ��
typedef struct Chess{
    struct Array{
        int x;
        int y;
    }p[8];              /// ��������
    struct List Stack;  /// ����·����ջ
    int l;              /// ���̵ĳ�
    int w;              /// ���̵Ŀ�
    int enter_x;        /// �������x
    int enter_y;        /// �������y
    int out_x;          ///��������x
    int out_y;          /// ��������y
    int a[Max][Max];    /// ��������
    int count;          ///�Ѿ�̤����ĸ���

    int num;            ///��ĸ���

    Chess(int rl, int rw, int ex, int ey, int ox, int oy);
    ~Chess() {}

    int _solve_chess(int x, int y);
    void _solve_chess();
    void solve_chess() {_solve_chess(out_x, out_y);}
}Chess;

Chess::Chess(int rl, int rw, int ex, int ey, int ox, int oy) {
    p[0] = {-1,-2};   p[1] = {-2,-1}; p[2] = {-2,1};
    p[3] = {-1,2};  p[4] = {1,2};   p[5] = {2,1};
    p[6] = {2,-1};  p[7] = {1,-2};
    for (int i=0; i<Max; i++)
        for (int j=0; j<Max; j++)
            a[i][j] = 0;
    l = rl;
    w = rw;
    enter_x = ex;
    enter_y = ey;
    out_x = ox;
    out_y = oy;
    count = 0;
    num = 0;
}

/// �ⷨ1��
int Chess::_solve_chess(int x, int y) {
    Stack.push(x, y, 0);
    count++;

    if (x>=l || x<0 || y>=w || y<0)
        return 0;
    if (a[x][y] != 0)
        return 0;

    a[x][y] = l*w-count+1;

    int i, j, t1, t2;
    if (x==enter_x && y==enter_y && count == l*w) {
        if (num == 0)
            printf("\nThe result is: \n\n");
        printf("%d:\n", num+1);
        for (i=0; i<l; i++) {
            for(j=0; j<w; j++)
                printf("%-3d ", a[i][j]);
            puts("");
        }
        printf("\n\n");
        num++;
        return 1;
    }
    t1 = x;
    t2 = y;
    for (i=0; i<8; i++) {
        if (x<l || x>=0 || y<w || y>=0) {
            x = p[i].x + t1;
            y = p[i].y + t2;
            int t = _solve_chess(x, y);
            Stack.pop();
            count--;
            if (t == 1)
                a[x][y] = 0;
        }
    }
    return 1;
}

///���ⷨ2��
void Chess::_solve_chess() {
    count = 0;
    int i, j, t1, t2;
    int p1, q1;
    int x = out_x, y = out_y;
    Stack.push(x, y, -1);
    count++;
    a[x][y] = l*w-count+1;

    while (1) {
        int sign = 0;
        if (count == l*w)
            break;
        t1 = x;
        t2 = y;
        for (i = 0; i<8; i++) {
         loop:x = p[i].x + t1;
            y = p[i].y + t2;
            if (x>=l || x<0 || y>=w || y<0)
                continue;
            if (count != l*w-1 && x==enter_x && y==enter_y)
                continue;
            if (a[x][y] != 0)
                continue;
            Stack.push(x,  y, i);
            count++;
            a[x][y] = l*w-count+1;
            sign = 1;
            break;
        }
        if (sign)
            continue;
        i = Stack.getsign()+1;
        Stack.getfront(t1, t2);
        a[t1][t2] = 0;
        Stack.pop();
        count--;
        if (count == 0)
            break;
        Stack.getfront(t1, t2);
        goto loop;
    }
    if (count == l*w)
        num++;

    printf("\n\n");
    for (i=0; i<l; i++) {
        for(j=0; j<w; j++)
            printf("%-3d ", a[i][j]);
        puts("");
    }
    printf("\n\n");
}



/// �㷨һ�Ĳ��Ժ���
void check1(int a, int b, int c, int d, int e, int f) {
    Chess q(a,b,c,d,e,f);
    q.solve_chess();
    if(q.num == 0)
        printf("The horse can't walk the chessboard!\n\n");
}

/// �㷨���Ĳ��Ժ���
void check2(int a, int b, int c, int d, int e, int f) {
    Chess q(a,b,c,d,e,f);
    q._solve_chess();
    if(q.num == 0)
        printf("The horse can't walk the chessboard!\n\n");
}

int main() {
    //int l, w, entX, entY, outX, outY, i, j;
    //printf("Please input the lenth and the width of the chesspoard(don't over %d):", Max);
    //scanf("%d", &l);
    //scanf("%d", &w);
    //printf("Please inpu the starting position coordinates: ");
    //scanf("%d", &entX);
    //scanf("%d", &entY);
    //printf("Please input the end position corrdinates: ");
    //scanf("%d", &outX);
    //scanf("%d", &outY);
    //Chess q(l, w, entX, entY, outX, outY);

    check1(5,5,0,0,2,0);
    //check2(l,w,entX,entY,outX,outY);
    return 0;
}





*/



/*
void lp_ques() {
    CirList lp;
    int num, i;
    printf("Please input the num of the list you want to creat: ");
    scanf("%d", &num);
    for (i=0; i<num; i++)
        lp._insert(i+1);
    printf("Please input the num you want to delete: ");
    scanf("%d", &num);
    printf("The remove data is ");
    bool sign = true;
    while (lp.CurrentSize != 1) {
        if (!lp._remove(num, &i)) {
            printf("\n%d Remove wrong!\n", lp.tail->Next->data);
            exit(-1);
        }
        printf("%d  ", i);
        sign = false;
    }
    if (sign)
        printf("NULL!");
    printf("\nThe last data is %d\n", lp.tail->data);
}






void lp_ques() {
	int a[50], b[50];
    CirList lp;
    int num, i, t=0, Size;
    printf("Please input the num of the list you want to creat: ");
    scanf("%d", &num);
	Size = num;
    for (i=0; i<num; i++)
        lp._insert(i+1);
    bool sign = true;
	printf("Please input the passwords");
	scanf("%d", &num);
	for (i=0; i<num; i++)
        scanf("%d",  );
    while (lp.CurrentSize != 0) {
        if (!lp._remove(num, &i)) {
            printf("\n%d Remove wrong!\n", lp.tail->Next->data);
            exit(-1);
        }
		num = a[i]-1;
		b[t++] = i;
        sign = false;
    }
    if (sign)
        printf("NULL!");
	printf("The delete numer is :");
	for (i = 0; i<Size; i++)
		printf("%d  ", b[i]);
}
*/

/*

/// ����
typedef struct Data {
    DataType data;
    int isEffect;
}Data, *pData;

typedef struct SeqList{
    pData data;
    int CurrentSize;
    int current;
    int MaxSize;

    SeqList(int num);
    ~SeqList();
    bool _remove(int num, DataType* deldata);
    void _insert(DataType data);
}SeqList;

SeqList::SeqList(int num) {
    data = (Data*)malloc(sizeof(Data)*num);
    if (data == NULL) {
        printf("Memory allocate failure!!\n");
        Sleep(3000);
        exit(-1);
    }
    current = 0;
    CurrentSize = 0;
    MaxSize = num;
}

SeqList::~SeqList() {cout << "Hello world!" << endl;
    delete []data;
}

void SeqList::_insert(DataType d) {
    data[CurrentSize].isEffect = 0;
    data[CurrentSize++].data = d;
}

bool SeqList::_remove(int num, DataType* deldata) {
    if (CurrentSize == 0)
        return false;
    ///while (--num > 0) {
    ///    if (data[current].isEffect)
    ///        num++;
    ///    current++;
    ///    if (current >= MaxSize)
    ///        current %= MaxSize;
    ///}
    while (1) {
        while (data[current].isEffect != 0) {
            current++;
            if (current >= MaxSize)
                current %= MaxSize;
        }
        if (num == 1)
            break;
        current++;
        if (current >= MaxSize)
            current %= MaxSize;
        num--;
    }
    data[current].isEffect = 1;
    *deldata = data[current].data;
    current++;
    if (current >= MaxSize)
        current %= MaxSize;
    while (data[current].isEffect != 0) {
        current++;
        if (current >= MaxSize)
            current %= MaxSize;
    }
    CurrentSize--;
    return true;
}

void _lp_ques() {
    int num, i;
    printf("Please input the num of the list you want to creat: ");
    scanf("%d", &num);
    SeqList lp(num);
    for (i=0; i<num; i++)
        lp._insert(i+1);
    printf("Please input the num you want to delete: ");
    scanf("%d", &num);
    printf("The remove data is ");
    i = lp.data[0].data;
    bool sign = true;
    while (lp.CurrentSize != 1) {
        if (!lp._remove(num, &i)) {
            printf("Remove wrong!\n");
            exit(-1);
        }
        printf("%d  ", i);
        sign = false;
    }
    if (sign)
        printf("NULL!");
    printf("\nThe last data is %d\n", lp.data[lp.current]);
}*/































