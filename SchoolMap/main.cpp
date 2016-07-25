#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

#define INFINITY 32767
#define MaxVexNum 20

typedef struct {
	int num;                    ///������
	char name[30];              ///��������
    char information[150];      ///������Ϣ
}view;

typedef struct {
	view vex[MaxVexNum];            ///����
	int arc[MaxVexNum][MaxVexNum];  ///·������
	int vexnum,arcnum;              ///��������·����
}graph;

graph creat();                    ///����У԰����ͼ��ͼ�ṹ
int numexist(graph a,int x);      ///�˱�ž����Ƿ����
void founded(graph a);            ///��ѯ������Ϣ����
void introduction(graph a);       ///���о�����Ϣ�Ľ���
void dispath(graph *g);
void print_one_path(graph *g, int len, int b[20][20], int x, int y);
int short_path(graph* g, int a[20][20],int b[20][20], int x, int y, int old);

void changegraph(graph *b);     ///����ͼ��Ϣ
void insertarc(graph *a);       ///����·��
void insertvex(graph *a);       ///���Ӿ���
void deletearc(graph *a);      ///ɾ��·��
void deletevex(graph *a);       ///ɾ������
void printjuzheng(graph a);     ///��ӡ�ڽӾ���
void xiaoyuantu();              /// ��ӡУ԰��ͼ
void menu();                    /// �˵�
void Save(graph g);             /// �����ļ�


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
    printf("   �����ʵ��ѧ����ȫ��\n\n");
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
        printf("   �����б�\n\n");
        printf("       1.��ѯ������Ϣ                             2.ѧУ���о�����Ϣ����\n\n");
        printf("       3.��ѯ�����ȫ�����·��                   4.����У԰������Ϣ\n\n");
        printf("       5.��ѯУ԰���¾���ͼ                       6.�������·��\n\n");
        printf("       0.�˳�ϵͳ\n\n");
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
        strcpy(g.vex[0].name,"����");
        strcpy(g.vex[0].information,"�����ʵ��ѧ����λ�ڳ��������������࣬�����򱱡�");
        strcpy(g.vex[1].name,"����¥");
        strcpy(g.vex[1].information,"����¥λ��ѧУ���࣬��ѧУ��ʦ�����񡢰칫�ĵط���");
        strcpy(g.vex[2].name,"��Ȫ");
        strcpy(g.vex[2].information,"��Ȫλ���������棬����У԰��һ�۾Ϳɿ�����");
        strcpy(g.vex[3].name,"��ѧ¥");
        strcpy(g.vex[3].information,"ѧ���Ͽεĳ�������A��B������ѧ¥��B¥Ϊ���ݶ�ý�������㣬A¥���߲�");

        for(i=0;i<=g.vexnum;i++)
            for(j=0;j<=g.vexnum;j++)
                g.arc[i][j]=INFINITY;
        for (i=0;i<=g.vexnum; i++)
            g.arc[i][i] = 0;
        g.arc[0][1]=g.arc[1][0]=200;	//���� ->����¥
        g.arc[0][2]=g.arc[2][0]=100;  //����->��Ȫ
        g.arc[1][2]=g.arc[2][1]=150;  //����¥->��Ȫ
        g.arc[2][3]=g.arc[3][2]=150;  //��Ȫ->��ѧ¥
        g.arc[0][3]=g.arc[3][0]=250;  //����->��ѧ¥
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
	printf("��������Ҫ��ѯ������Ϣ�ı�ţ�");
	int temp;
	scanf("%d", &temp);
	if(numexist(a,temp)) {
        temp--;
        print_vertex(a, false);
		printf("\n<%d>. %s\n\n    %s\n",a.vex[temp].num,a.vex[temp].name,a.vex[temp].information);
	} else
		printf("\n\t\t\t\t\t\t��������ľ�����Ϣ��Ų����ڣ�");
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
                printf("��·��ͨ��\n\n");
            t++;
            if (t%10 == 0)
                getch();
        }
    getch();

}

void print_one_path(graph *g, int len, int b[20][20], int x, int y) {
    int temp = b[x][y];
    printf(" %s �� %s ��·���ǣ�%s",g->vex[x].name, g->vex[y].name, g->vex[x].name);
    while (temp != y) {
        printf("-->%s", g->vex[temp].name);
        temp = b[temp][y];
    }
    printf("-->%s\n", g->vex[y].name);
    printf("�ܳ���Ϊ��%d\n\n", len);
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
    printf("��������Ҫ��ѯ·���������յ㣺");
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
        printf("����ڵ㲻���ڣ�");
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
	printf("������ߵ�������յ��Լ���Ȩֵ��");
	scanf("%d %d %d",&m,&n,&distance);
	if (numexist(*a, m) && numexist(*a, n) && m != n)	{
        m--, n--;
        a->arc[m][n]=distance;
        a->arc[n][m]=a->arc[m][n];
        a->arcnum++;
        printf("��ӳɹ���");
	} else
        printf("����ڵ㲻���ڣ�");
	getch();
}

void deletearc(graph *a) {
	int v0,v1;
	print_vertex(*a, false);
	if(a->arcnum<=0) {
		printf("ͼ���ޱߣ��޷�ɾ����");
		getch();
		return;
	}
	printf("������Ҫɾ����·����������յ�ı�ţ�");
	scanf("%d %d",&v0,&v1);
	if (numexist(*a, v0) && numexist(*a, v1) && v0 != v1) {
        v0--, v1--;
        a->arc[v0][v1]=INFINITY;
        a->arc[v1][v0]=INFINITY;
        a->arcnum--;
        printf("ɾ����ϣ�");
	} else
        printf("����ڵ㲻��ȷ��");
    getch();
}

void insertvex(graph *a) {
    print_vertex(*a, false);
	int i;
	printf("��������Ҫ���ӵľ������Ϣ����ţ����ƣ���飺");
	a->vexnum++;
	scanf("%d %s  %s",&a->vex[a->vexnum].num,&a->vex[a->vexnum].name,&a->vex[a->vexnum].information);
	for(i=0;i<a->vexnum;i++) {
		a->arc[a->vexnum][i]=INFINITY;
		a->arc[i][a->vexnum]=INFINITY;
	}
	a->arc[a->vexnum][a->vexnum] = 0;
	printf("�������ӳɹ���");
	Sleep(1000);
	print_vertex(*a, false);
	getch();
}

void deletevex(graph *a) {
    print_vertex(*a, false);
	int i=0, j, v, temp = 3;
	if(a->vexnum<=0) {
		printf("ͼ���޾����ɾ��");
		return;
	}
	printf("��������Ҫɾ���ľ�����: ");
	while(temp--) {
	    scanf("%d",&v);
	    if (!numexist(*a, v))
            printf("������������������룡");
        else  break;
	}
	v--;
	if (temp == 0) {
        printf("ɾ��ʧ�ܣ�");
        getch();
	}
	for(i=v;i<=a->vexnum;i++) {
		strcpy(a->vex[i].name,a->vex[i+1].name);//�����滻ǰһ������������Ϣ
		strcpy(a->vex[i].information,a->vex[i+1].information);
	}
	for(i=v;i<=a->vexnum;i++) {//ɾ��v��
		for(j=0;j<v;j++)
			a->arc[i][j]=a->arc[i+1][j];
        for (j=v+1; j<=a->vexnum; j++)
            a->arc[i][j-1] = a->arc[i][j];
    }
    for(i=v;i<a->vexnum;i++)
        for(j=0;j<i;j++)
            a->arc[j][i]=a->arc[j][i+1];//ɾ��v��
    a->vexnum--;
	printf("�ɹ�ɾ��!");
	Sleep(1000);
	print_vertex(*a, false);
	getch();
}

void changegraph(graph *b) {
	while (1) {
		system("cls");
	     printf("���ã��������޸ģ�\n\n");
		 Sleep(200);
		 printf("***************************************************************\n\n");
		 printf("   1.ɾ��·��                                 2.����·��\n\n");
	     printf("   3.ɾ������                                 4.���Ӿ���\n\n");
		 printf("   5.����\n\n");
		 printf("***************************************************************\n\n");
		 char choice = getch();
		 switch(choice) {
			 case '1': deletearc(b); printjuzheng(*b); break;
			 case '2': insertarc(b); printjuzheng(*b); break;
			 case '3': deletevex(b); break;
			 case '4': insertvex(b); break;
			 case '5': return;
			 default:printf("�������"); getch(); break;
		 }
	}
}

void xiaoyuantu() {
    system("cls");
   printf("\n                       �����ʵ��ѧ����ͼ                             \n\n");
   printf("����������������������������������������������������������������������\n");
   printf("��    ����������      ������������          ����������    ������������\n");
   printf("��    ������¥�ĨT�T�T�� ��ѧ�� �ĨT�[      ����������    ��ѧ��������\n");
   printf("��    �����ө���      ������ĩ�  �d�T�T�T�贈������T�T��Ԣ��1 ����\n");
   printf("��        �U          �����ө��������۩������������ݩ�    �����ө�����\n");
   printf("��        �U  ��������    �U      ��ͼ��ݩ������ө���        �U    ��\n");
   printf("��������  �c�T����Ȫ��    �U      �����ө���    �U            �U    ��\n");
   printf("��������  �U  ��������    �U          �U        �U        �����۩�����\n");
   printf("����  �ǨT�p�T�T�T�T�T�T�T�p�T�T�T�T�T�p�T�T�T�T�p�T�T�T�T������Է����\n");
   printf("����  ��  �U              �U          �U        �U        �����ө�����\n");
   printf("�����ũ�  �U              �U          �U        �U            �U    ��\n");
   printf("��������  �U              �U          �U        �U            �U    ��\n");
   printf("��        �U              �U          �U  �������贈����      �U    ��\n");
   printf("��      ���۩�����    �����۩���      �U  �� �� �� �� ��  �����۩�����\n");
   printf("��      ����ѧ¥�ĨT�T��ʵ��¥�ĨT�T�T�g  �� �� �� �� �ĨT��ѧ��������\n");
   printf("��      ����������    ����������      �U  �� �� �� �� ��  �� Ԣ��2����\n");
   printf("��                                    �U  �������ߩ�����  �����ө�����\n");
   printf("��                                    �U          ��������    �U    ��\n");
   printf("��                              �������۩���      ����ʳ��    �U    ��\n");
   printf("��                              ��   ���� �ĨT�T�T�̹㳡�ĨT�T�a    ��\n");
   printf("��                              ������������      ��������          ��\n");
   printf("����������������������������������������������������������������������\n");
   getch();
}

void save(graph g) {
    int i,j;
    FILE *fp;
    if((fp=fopen("schoolmap.txt","wt")) == NULL) {
        printf("�ļ�д�����!");
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
            default:printf("������Ĳ��������ڣ����������룺"); Sleep(1000); break;
        }
    }
}
