#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

#define INFINITY 32767
#define MaxVexNum 20

typedef struct {
	int num;                    ///景点编号
	char name[30];              ///景点名称
    char information[150];      ///景点信息
}view;

typedef struct {
	view vex[MaxVexNum];            ///景点
	int arc[MaxVexNum][MaxVexNum];  ///路径数组
	int vexnum,arcnum;              ///景点数，路径数
}graph;

graph creat();                    ///建立校园导游图的图结构
int numexist(graph a,int x);      ///此编号景点是否存在
void founded(graph a);            ///查询景点信息函数
void introduction(graph a);       ///所有景点信息的介绍
void dispath(graph *g);
void print_one_path(graph *g, int len, int b[20][20], int x, int y);
int short_path(graph* g, int a[20][20],int b[20][20], int x, int y, int old);

void changegraph(graph *b);     ///更改图信息
void insertarc(graph *a);       ///增加路径
void insertvex(graph *a);       ///增加景点
void deletearc(graph *a);      ///删除路径
void deletevex(graph *a);       ///删除景点
void printjuzheng(graph a);     ///打印邻接矩阵
void xiaoyuantu();              /// 打印校园地图
void menu();                    /// 菜单
void Save(graph g);             /// 保存文件


int main()
{
	system("color 5e");
	menu();
    return 0;
}


void print_vertex(graph a, bool sign) {
    int i, c = 1;
    system("cls");
    printf("***************************************************************************\n\n");
    printf("   西安邮电大学景点全览\n\n");
    for (i=0; i<=a.vexnum; i++) {
        char name_[30];
        strcpy(name_, a.vex[i].name);
        printf("     %d.%-10s", a.vex[i].num, name_);
        c++;
        if ((c-1)%4 == 0) {
            printf("\n");
        }
    }
    if (c%6 == 0)
        printf("\n");
    else
        printf("\n\n");
    printf("***************************************************************************\n\n");
    if (sign) {
        printf("   功能列表\n\n");
        printf("       1.查询景点信息                             2.学校所有景点信息介绍\n\n");
        printf("       3.查询景点间全部最短路径                   4.更改校园景点信息\n\n");
        printf("       5.查询校园大致景点图                       6.查找最短路径\n\n");
        printf("       0.退出系统\n\n");
        printf("***************************************************************************\n\n");
    }
}

graph creat() {
	graph g;
	FILE *fp;
	int i, j;
    if((fp=fopen("schoolmap.txt","rt")) == NULL) {
        fp = fopen("schoolmap.txt", "wb");
        fclose(fp);
        g.vexnum = 3, g.arcnum = 5;
        for(i=0;i<=g.vexnum;i++)
            g.vex[i].num=i+1;
        strcpy(g.vex[0].name,"正门");
        strcpy(g.vex[0].information,"西安邮电大学正门位于长安新区政府西侧，坐南向北。");
        strcpy(g.vex[1].name,"行政楼");
        strcpy(g.vex[1].information,"行政楼位于学校东侧，是学校老师处理公务、办公的地方。");
        strcpy(g.vex[2].name,"喷泉");
        strcpy(g.vex[2].information,"喷泉位于正门南面，进入校园第一眼就可看到。");
        strcpy(g.vex[3].name,"教学楼");
        strcpy(g.vex[3].information,"学生上课的场所。有A、B两栋教学楼，B楼为阶梯多媒体有三层，A楼有七层");

        for(i=0;i<=g.vexnum;i++)
            for(j=0;j<=g.vexnum;j++)
                g.arc[i][j]=INFINITY;
        for (i=0;i<=g.vexnum; i++)
            g.arc[i][i] = 0;
        g.arc[0][1]=g.arc[1][0]=200;	//正门 ->行政楼
        g.arc[0][2]=g.arc[2][0]=100;  //正门->喷泉
        g.arc[1][2]=g.arc[2][1]=150;  //行政楼->喷泉
        g.arc[2][3]=g.arc[3][2]=150;  //喷泉->教学楼
        g.arc[0][3]=g.arc[3][0]=250;  //正门->教学楼
    } else {
        fscanf(fp, "%d", &g.vexnum);
        fscanf(fp, "%d\n", &g.arcnum);
        for(i=0;i<=g.vexnum;i++)
            fscanf(fp,"%d %s %s\n",&g.vex[i].num,g.vex[i].name,g.vex[i].information);
        for(i=0;i<=g.vexnum;i++)
            for(j=0;j<=g.vexnum;j++)
                fscanf(fp,"%d\n",&g.arc[i][j]);
    }
    return g;
}

int numexist(graph a,int x) {
	if(x-1 >=0 && x-1 <= a.vexnum)
		return 1;
	else
		return 0;
}

void founded(graph a) {
	print_vertex(a, false);
	printf("请输入您要查询景点信息的编号：");
	int temp;
	scanf("%d", &temp);
	if(numexist(a,temp)) {
        temp--;
        print_vertex(a, false);
		printf("\n<%d>. %s\n\n    %s\n",a.vex[temp].num,a.vex[temp].name,a.vex[temp].information);
	} else
		printf("\n\t\t\t\t\t\t您所输入的景点信息编号不存在！");
    getch();
}

void introduction(graph a) {
	int i;
	system("cls");
	printf("**************************************************\n");
	for(i=0;i<=a.vexnum;i++)
	printf("<%d>. %s\n    %s\n",a.vex[i].num,a.vex[i].name,a.vex[i].information);
	printf("***************************************************");
	getch();
}

void dispath(graph *g) {
    int i, j, t = 1;
    print_vertex(*g, false);

    //printjuzheng(*g);

    int a[20][20], b[20][20];
    for (i=0; i<=g->vexnum; i++)
        for (j=0; j<=g->vexnum; j++)
            a[i][j] = INFINITY;
    for (i=0; i<=g->vexnum; i++)
        for (j=0; j<=g->vexnum; j++) {
            if (i == j)
                continue;
            short_path(g, a, b, i, j, INFINITY);
            if (a[i][j] != INFINITY)
                print_one_path(g, a[i][j], b, i, j);
            else
                printf("此路不通！\n\n");
            t++;
            if (t%10 == 0)
                getch();
        }
    getch();

}

void print_one_path(graph *g, int len, int b[20][20], int x, int y) {
    int temp = b[x][y];
    printf(" %s 到 %s 的路径是：%s",g->vex[x].name, g->vex[y].name, g->vex[x].name);
    while (temp != y) {
        printf("-->%s", g->vex[temp].name);
        temp = b[temp][y];
    }
    printf("-->%s\n", g->vex[y].name);
    printf("总长度为：%d\n\n", len);
}

int short_path(graph *g, int a[20][20],int b[20][20], int i, int j, int old) {
    if (a[i][j] == INFINITY) {
        b[i][j] = j;
        if (g->arc[i][j] != INFINITY && g->arc[i][j] != 0) {
            a[i][j] = g->arc[i][j];
        } else {
            int min = INFINITY, t, k;
            for (k=0; k<g->vexnum; k++) {
                if (k == old)
                    continue;
                if (g->arc[i][k] != 0 && g->arc[i][k] != INFINITY) {
                    t = short_path(g, a, b, i, k, INFINITY)+short_path(g, a, b, k, j, i);
                    if (min > t) {
                        min = t;
                        b[i][j] = k;
                    }
                }
            }
            a[i][j] = min;
        }
    }
    return a[i][j];
}

void find_shortpath(graph *g) {
    print_vertex(*g, false);
    //printjuzheng(*g);
    printf("请输入所要查询路径的起点和终点：");
    int v0, v1, i, j;
    scanf("%d", &v0);
    scanf("%d", &v1);
    if (numexist(*g, v0) && numexist(*g, v1)) {
        int a[20][20], b[20][20];
        for (i=0; i<=g->vexnum; i++)
            for (j=0; j<=g->vexnum; j++)
                a[i][j] = INFINITY;
        v0--, v1--;
        short_path(g, a, b, v0, v1, INFINITY);
        print_one_path(g, a[v0][v1], b, v0, v1);
    } else
        printf("输入节点不存在！");
    getch();
}

void printjuzheng(graph a) {
	int i,j,k=0;
	printf("%-5s", " ");
	for (i=0; i<=a.vexnum; i++)
        printf("%-5d", i+1);
    printf("\n");
	for(i=0;i<=a.vexnum;i++) {
	    printf("%-5d", i+1);
		for(j=0;j<=a.vexnum;j++) {
			if(a.arc[i][j]==INFINITY)
				printf("%-5s", "-");
			else
				printf("%-5d",a.arc[i][j]);
		}
		printf("\n");
	}
	getch();
}

void insertarc(graph *a) {
    print_vertex(*a, false);
	int m,n,distance;
	printf("请输入边的起点与终点以及其权值。");
	scanf("%d %d %d",&m,&n,&distance);
	if (numexist(*a, m) && numexist(*a, n) && m != n)	{
        m--, n--;
        a->arc[m][n]=distance;
        a->arc[n][m]=a->arc[m][n];
        a->arcnum++;
        printf("添加成功！");
	} else
        printf("输入节点不存在！");
	getch();
}

void deletearc(graph *a) {
	int v0,v1;
	print_vertex(*a, false);
	if(a->arcnum<=0) {
		printf("图中无边，无法删除！");
		getch();
		return;
	}
	printf("输入您要删除的路径的起点与终点的编号：");
	scanf("%d %d",&v0,&v1);
	if (numexist(*a, v0) && numexist(*a, v1) && v0 != v1) {
        v0--, v1--;
        a->arc[v0][v1]=INFINITY;
        a->arc[v1][v0]=INFINITY;
        a->arcnum--;
        printf("删除完毕！");
	} else
        printf("输入节点不正确！");
    getch();
}

void insertvex(graph *a) {
    print_vertex(*a, false);
	int i;
	printf("请输入您要增加的景点的信息：编号，名称，简介：");
	a->vexnum++;
	scanf("%d %s  %s",&a->vex[a->vexnum].num,&a->vex[a->vexnum].name,&a->vex[a->vexnum].information);
	for(i=0;i<a->vexnum;i++) {
		a->arc[a->vexnum][i]=INFINITY;
		a->arc[i][a->vexnum]=INFINITY;
	}
	a->arc[a->vexnum][a->vexnum] = 0;
	printf("景点增加成功！");
	Sleep(1000);
	print_vertex(*a, false);
	getch();
}

void deletevex(graph *a) {
    print_vertex(*a, false);
	int i=0, j, v, temp = 3;
	if(a->vexnum<=0) {
		printf("图中无景点可删！");
		return;
	}
	printf("请输入您要删除的景点编号: ");
	while(temp--) {
	    scanf("%d",&v);
	    if (!numexist(*a, v))
            printf("您输入错误！请重新输入！");
        else  break;
	}
	v--;
	if (temp == 0) {
        printf("删除失败！");
        getch();
	}
	for(i=v;i<=a->vexnum;i++) {
		strcpy(a->vex[i].name,a->vex[i+1].name);//后面替换前一个景点名及信息
		strcpy(a->vex[i].information,a->vex[i+1].information);
	}
	for(i=v;i<=a->vexnum;i++) {//删除v行
		for(j=0;j<v;j++)
			a->arc[i][j]=a->arc[i+1][j];
        for (j=v+1; j<=a->vexnum; j++)
            a->arc[i][j-1] = a->arc[i][j];
    }
    for(i=v;i<a->vexnum;i++)
        for(j=0;j<i;j++)
            a->arc[j][i]=a->arc[j][i+1];//删除v列
    a->vexnum--;
	printf("成功删除!");
	Sleep(1000);
	print_vertex(*a, false);
	getch();
}

void changegraph(graph *b) {
	while (1) {
		system("cls");
	     printf("您好！请慎重修改！\n\n");
		 Sleep(200);
		 printf("***************************************************************\n\n");
		 printf("   1.删除路线                                 2.增加路线\n\n");
	     printf("   3.删除景点                                 4.增加景点\n\n");
		 printf("   5.返回\n\n");
		 printf("***************************************************************\n\n");
		 char choice = getch();
		 switch(choice) {
			 case '1': deletearc(b); printjuzheng(*b); break;
			 case '2': insertarc(b); printjuzheng(*b); break;
			 case '3': deletevex(b); break;
			 case '4': insertvex(b); break;
			 case '5': return;
			 default:printf("输入错误！"); getch(); break;
		 }
	}
}

void xiaoyuantu() {
    system("cls");
   printf("\n                       西安邮电大学导游图                             \n\n");
   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("┃    ┏━━━┓      ┏━━━━┓          ┏━━━┓    ┏━━━┓┃\n");
   printf("┃    ┃行政楼┠═══┨ 大学生 ┠═╗      ┃体育场┃    ┃学生公┃┃\n");
   printf("┃    ┗━┯━┛      ┃活动中心┃  ╠═══╋━━━╋══┨寓区1 ┃┃\n");
   printf("┃        ║          ┗━┯━━┛┏┷━━┓┃体育馆┃    ┗━┯━┛┃\n");
   printf("┃        ║  ┏━━┓    ║      ┃图书馆┃┗━┯━┛        ║    ┃\n");
   printf("┃┏━┓  ╟═┨喷泉┃    ║      ┗━┯━┛    ║            ║    ┃\n");
   printf("┃┃正┃  ║  ┗━━┛    ║          ║        ║        ┏━┷━┓┃\n");
   printf("┃┃  ┣═╬═══════╬═════╬════╬════┨旭日苑┃┃\n");
   printf("┃┃  ┃  ║              ║          ║        ║        ┗━┯━┛┃\n");
   printf("┃┃门┃  ║              ║          ║        ║            ║    ┃\n");
   printf("┃┗━┛  ║              ║          ║        ║            ║    ┃\n");
   printf("┃        ║              ║          ║  ┏━━╋━━┓      ║    ┃\n");
   printf("┃      ┏┷━━┓    ┏━┷━┓      ║  ┃ 篮 ┃ 土 ┃  ┏━┷━┓┃\n");
   printf("┃      ┃教学楼┠══┨实验楼┠═══╣  ┃ 球 ┃ 操 ┠═┨学生公┃┃\n");
   printf("┃      ┗━━━┛    ┗━━━┛      ║  ┃ 场 ┃ 场 ┃  ┃ 寓区2┃┃\n");
   printf("┃                                    ║  ┗━━┻━━┛  ┗━┯━┛┃\n");
   printf("┃                                    ║          ┏━━┓    ║    ┃\n");
   printf("┃                              ┏━━┷━┓      ┃美食┃    ║    ┃\n");
   printf("┃                              ┃   澡堂 ┠═══┨广场┠══╝    ┃\n");
   printf("┃                              ┗━━━━┛      ┗━━┛          ┃\n");
   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
   getch();
}

void save(graph g) {
    int i,j;
    FILE *fp;
    if((fp=fopen("schoolmap.txt","wt")) == NULL) {
        printf("文件写入错误!");
        getch();
        exit(1);
    }
    fprintf(fp,"%d %d\n",g.vexnum,g.arcnum);
    for(i=0;i<=g.vexnum;i++)
        fprintf(fp,"%d %s %s\n",g.vex[i].num,g.vex[i].name,g.vex[i].information);
    for(i=0;i<=g.vexnum;i++)
        for(j=0;j<=g.vexnum;j++)
            fprintf(fp,"%d\n",g.arc[i][j]);
	fclose(fp);
}

void menu() {
	graph b;
	b=creat();
    while (1) {
        print_vertex(b, true);
        fflush(stdin);
        char choice = getch();
        switch(choice) {
            case '1' : founded(b); break;
            case '2': introduction(b); break;
            case '3': dispath(&b); break;
            case '4': changegraph(&b); break;
            case '5': xiaoyuantu(); break;
            case '6': find_shortpath(&b); break;
            case '0': save(b); return;
            default:printf("您输入的操作不存在，请重新输入："); Sleep(1000); break;
        }
    }
}
