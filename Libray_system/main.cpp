#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <list>
#include <map>
#include <string>
#include "Struct_List.h"
using namespace std;

/// -----------------------------------------------------------------------------
///                            ȫ��������
/// -----------------------------------------------------------------------------
void gotoxy(HANDLE hOut, int x, int y);  ///����ƶ�
void init_all_file();                    ///��ʼ�������ļ�
bool login(int select, char name[], char account[]);                  ///��½
void login_menue();                      ///��½�˵�
void limit_time(int i);                  ///ʱ���ӳ�

/// ------------------------------------------------------------------------------

///*******************************************************************************
///                                ѧ��
///*******************************************************************************
void client_menue(char ns[], char as[]);        ///ѧ���˵�
void change_passwords(char as[]);               /// �޸����룬�ʻ�Ϊas[]
void look_owe_ifor(char *as);                   ///�鿴������Ϣ
void lent_book(char ns[]);                      /// ͼ�����
void relent_book(char ns[]);                    /// ͼ������
int print_lent_book(char *account);             /// ��ӡ�˺�Ϊaccount���û����ĵ������飬����ֵΪ����Ŀ��
void add_time(struct Date* p);                  /// ��ʱ��p���Bb_MaxSize��
int judge_book_exit(char* name, char* book_num);/// ����-1����ϵͳ����1������ڣ�2��������,book_numΪNULLʱ��ʾ���ܽ��ģ�����Ϊ��������ı��
int calculate_time(struct Date* _begin);        /// ������ʼΪbegin�ĳ���ʱ��
void return_book(char as[]);                    /// �黹ͼ��

///*******************************************************************************
///                                ����Ա
///*******************************************************************************
void server_menue();                                            ///����Ա�˵�

///                      <1>.ѧ����Ϣ������
/// //////////////////////////////////////////////////////////////////////////////
void manage_student_menue();        /// ѧ����Ϣ����˵�
void stu_regist();                  /// ����ѧ���˺�
bool judge_account_exit(char *a);   /// �ж��˺�a�Ƿ����
int get_client_num();               /// ��ȡ�û�����
bool judge_sid_eixt(char *s);       /// �ж�ѧ���Ƿ����
void remove_client();               /// �û�ע��
void reset_passwords();             /// ��������
void look_stu_account();            /// �鿴ĳλѧ���˺�
bool judge_name_exit(char *name);   /// �ж�name�Ƿ����
void look_all_client();             /// �鿴����ѧ��

///                      <2>.ͼ������ܺ���
/// /////////////////////////////////////////////////////////////////////////////
void manage_book_menue();       /// ͼ�����
int prin(char* sort_name);      /// ����0��ʾϵͳ����,1��ӡ��ɣ�2��ʾû��ͼ��
void print_book();              /// �鿴ͼ��
void add_book();                /// ���ͼ��
void delete_book();             /// ɾ��ͼ��
int delet(char* data, int i);   /// iΪ1ʱ��������ɾ����Ϊ2ʱ�������ɾ��.����ֵΪ0�Ǵ���ϵͳ����1�Ǵ���ɾ���ɹ��� 2����û�ҵ�,3��ʾ�����б��������ɾ��
int get_book_num();             /// ��ȡͼ�������
char *get_book_name(char* book_num); /// ��ȡ���Ϊbook_num��ͼ�������
int get_booknum(char *book_num);/// ��ȡ�˺�Ϊbook_num��ͼ�������
void count_book();              /// ͳ��ͼ��
void find_book();               /// ͼ�����
int delete_origin();            /// ����1����ɾ���ɹ���0����ʧ�ܡ��ú�������ɾ��Ϊ�յ�ͼ�������
int get_origin_num(char* origin, int& t);/// ��ȡ���ڷ�����Ϊorigin��ͼ�����Ŀ������-1����ϵͳ����, tΪ����ͼ�鹲�ж�������
int prin_sort_name();           /// ��ӡ���з�����������-1����ϵͳ��������ֵ�����������
int judge_origin_exit(char *origin_name);/// ����-1����ϵͳ����0�������ڣ�1�������

///                           <3>.ͼ����Ĺ��ܺ���
/// /////////////////////////////////////////////////////////////////////////////
void manage_lbook_menue();                      ///ѧ�����裬����
void look_lend_book();                          /// �鿴�������

///                      <4>.���ù��ܺ���
/// //////////////////////////////////////////////////////////////////////////////
void set_menue();                   /// ����
void add_institute();               /// ���ѧԺ
int print_institute();              /// ��ӡ����ѧԺ,����ѧԺ����
void delet_institute();             /// ɾ��ѧԺ
bool judge_inst_exit(char *name);   /// �ж�ѧԺ�Ƿ����
void add_major();                   /// ���רҵ
int print_major();                  /// ��ӡ����רҵ
void delet_major();                 /// ɾ��רҵ
int get_major_size();               /// ��ȡרҵ��
int judge_major_exit(char *name, char *name1);/// �ж�רҵ�Ƿ����,nameΪרҵ����name1ΪѧԺ��,������ѧԺ�е�λ�Σ�����-1
int get_class_size(char *name, char *name1);  /// ����רҵ�༶��
void server_regist();                /// �������Ա�˺�
int get_server_num();                /// ��ȡ����Ա����
bool judge_a_eixt(char *a);          /// �ж�a��server���Ƿ����
void do_server();                    /// �Թ���Ա���в���

///                               <5>.���԰幦�ܺ���
/// ////////////////////////////////////////////////////////////////////////////////
void mess_note(char ns[]);                      /// ���Բ˵�,iΪ1ʱ��ʾʹ�����ǹ���Ա��Ϊ2ʱ��ѧ��
int prin_mess();                            /// ��ӡ���԰�,������������
int add_mess(char *mess, char* name, int j);/// �����԰��������ϢΪmess����Ϊname, jΪ0ʱ��ʾ�����԰������ӣ� Ϊ����ֵʱ��ʾ���j�����Ժ��������
/// ///////////////////////////////////////////////////////////////////////////////

int main()
{
    login_menue();
    return 0;
}

///                                 ȫ��������
void gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}
void init_all_file() {
    FILE *fp;
    ///����Ա
	if ((fp=fopen("server.txt", "rb")) == NULL) {
        fclose(fp);
		if ((fp=fopen("server.txt", "wb+")) == NULL) {
        loop:printf("��ʼ��ʧ��!\n");
            system("pause");
            return;
		}
		Server p;
		strcpy(p.account, "88888");
		strcpy(p.passwords, "88888");
		if (fwrite(&p, sizeof(Server), 1, fp) != 1) {
			goto loop;
		}
		fclose(fp);
	}

	///ѧ��
	if ((fp=fopen("client.txt", "rb")) == NULL) {
		fp = fopen("client.txt", "wb");
		fclose(fp);
	}

	///ѧԺ
    if ((fp=fopen("institute.txt", "rb")) == NULL) {
		fp = fopen("institute.txt", "wb");
		fclose(fp);
	}

	///���԰�
	if ((fp=fopen("tmpt_mess.txt", "rb")) == NULL) {
		fp = fopen("tmpt_mess.txt", "wb");
		fclose(fp);
	}

	///����ͼ��
	if ((fp=fopen("library.txt", "rb")) == NULL) {
		fp = fopen("library.txt", "wb");
		fclose(fp);
	}

    ///ͼ�����
	if ((fp=fopen("sort_book.txt", "rb")) == NULL) {
		fp = fopen("sort_book.txt", "wb");
		fclose(fp);
	}

	///���ͼ�������ļ�
	if ((fp=fopen("lent_book.txt", "rb")) == NULL) {
		fp = fopen("lent_book.txt", "wb");
		fclose(fp);
	}
	delete_origin();
}
bool login(int select, char ns[NP_MaxSize], char as[AS_MaxSize]) {
    while (1) {
		system("cls");
		printf("\t\t*****************��ӭ��½**************\n\n");
		char account[AS_MaxSize], passwords[NP_MaxSize], choice;
		int i, sign = 0;
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(hOut, 20, 6);
        for (i=6; i<=14; i++) {
            gotoxy(hOut, 20, i);
            if (i == 6 || i == 14)
                printf("** * * * * * * * * * * * * * **");
            else
                printf("*                             *");
        }
        gotoxy(hOut, 32, 7);
        printf("�û���½");
        gotoxy(hOut, 26, 10);
        printf("�˺ţ�");
        gotoxy(hOut, 26, 12);
        printf("���룺");
        gotoxy(hOut, 32, 10);
        int a = 32;
        for (i=0; i<AS_MaxSize; i++) {
            account[i] = getch();
            if (account[i] == 13) {
                if (i == 0) {
                gotoxy(hOut, 32, 10);
                    i--;
                    continue;
                } else {
                    account[i] = '\0';
                    break;
                }
            }
            if (account[i] == 8) {
                if (i != 0) {
                    i--;
                    gotoxy(hOut, --a, 10);
                    printf(" ");
                    gotoxy(hOut, a, 10);
                }
                i--;
                continue;
            }
            if (account[i] == 32) {
                gotoxy(hOut, a, 10);
                i--;
                continue;
            }
            a++;
            printf("%c", account[i]);
        }
        account[AS_MaxSize-1] = '\0';
        fflush(stdin);
    loop:gotoxy(hOut, 32, 12);
        a = 32;
        for (i=0; i<NP_MaxSize; i++) {
            passwords[i] = getch();
            if (passwords[i] == 13) {
                if (i == 0) {
                    gotoxy(hOut, 32, 12);
                    i--;
                    continue;
                } else {
                    passwords[i] = '\0';
                    break;
                }
            }
            if (passwords[i] == 8) {
                if (i != 0) {
                    i--;
                    gotoxy(hOut, --a, 12);
                    printf(" ");
                    gotoxy(hOut, a, 12);
                }
                i--;
                continue;
            }
            if (passwords[i] == 32) {
                gotoxy(hOut, a, 12);
                i--;
                continue;
            }
            a++;
            printf("*");
        }
        passwords[NP_MaxSize-1] = '\0';
        fflush(stdin);
        gotoxy(hOut, 44, 17);
        printf("��¼��.....");
        clock_t delay = 1*CLOCKS_PER_SEC;
        clock_t start = clock();
        while (clock()-start < delay)
            fflush(stdin);
        gotoxy(hOut, 40, 17);
		FILE *fp;
        Client p;
        Server p1;
		fp = select!=1? fopen("server.txt", "rb"):fopen("client.txt", "rb");

		if (fp == NULL) {
			printf("�ļ���ʧ��!\n\n");
			limit_time(2);
			return false;
		}

		while (1) {
            select==1? fread(&p, sizeof(struct Client), 1, fp):fread(&p1, sizeof(struct Server), 1, fp);
            if (feof(fp))
                break;
            if (select == 1) {
                if (strcmp(p.account, account) == 0) {
                    sign = 1;
                    break;
                }
            } else {
                if (strcmp(p1.account, account) == 0) {
                    sign = 1;
                    break;
                }
            }
		}
        if (sign == 0) {
            printf("�û��������ڣ����������루��Esc�����أ�\n");
            limit_time(2);
            choice = getch();
			fflush(stdin);
            if (choice == (char)27) {
				fclose(fp);
                return false;
			}
			fclose(fp);
            continue;
        }
        if (select == 1) {
            if (strcmp(passwords, p1.passwords) == 0) {
                strcpy(ns, p.name);
                strcpy(as, p.account);
                fclose(fp);
                return true;
            }
        } else {
            if (strcmp(passwords, p1.passwords) == 0) {
                strcpy(ns, "����Ա");
                strcpy(as, p1.account);
                fclose(fp);
                return true;
            }
        }
        printf("�û������������,����������(��Esc������)\n");
        limit_time(2);
        choice = getch();
		fflush(stdin);
        if (choice == (char)27) {
			fclose(fp);
            return false;
		}
        gotoxy(hOut, 32, 12);
        printf("       ");
        gotoxy(hOut, 40, 17);
        printf("                                        ");
        fclose(fp);
        goto loop;
	}
}
void login_menue() {
    init_all_file();
	while (1) {
    loop:system("cls");
		char choice;
		int select, i;
		printf("\t\t***********��ӭʹ��ͼ�����ϵͳ********   \n\n\n\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n");
		printf("\t\t\t\t1.ѧ����½\n\t\t\t\t2.����Ա��½\n\t\t\t\t0.�˳�\n\t");
		for (i=0; i<60; i++)
            printf("-");
        printf("\n\n��ѡ��");
        char name[NP_MaxSize], account[AS_MaxSize];
		choice = getch();
		fflush(stdin);
		switch(choice) {
		case '1': {
            select = 1;
			break;
		}
		case '2': {
			select = 2;
			break;
		}
		case '0':
			return;
		default:
			goto loop;
		}
		if (login(select, name, account)) {
            select == 1? client_menue(name, account):server_menue();
		}
	}
}
void limit_time(int i) {
    clock_t delay = i*CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock()-start < delay);
}

///                                ����Ա�����б�
void server_menue() {
	while (1) {
        system("cls");
        int i;
        printf("\t\t    ************��ӭʹ��**********\n\n\n\n\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n");
		printf("\t1.ѧ����Ϣ����\t\t2.ͼ�����\t\t3.ͼ�����\n\t");
		printf("4.����\t\t\t5.���԰�\t\t0.�˳�\n\n\t");
		for (i=0; i<60; i++)
            printf("-");
        printf("\n\n��ѡ��");
		fflush(stdin);
		char choice = getch();
		switch(choice) {
		case '1':
			manage_student_menue();
			break;
		case '2':
            manage_book_menue();
			break;
		case '3':
		    manage_lbook_menue();
			break;
		case '4':
		    set_menue();
			break;
        case '5':
            mess_note("����Ա");
            break;
		case '0':
			return;
		default:
			break;
		}
	}
}

///                         <1>.ѧ����Ϣ�����ܺ���
void manage_student_menue() {
	while (1) {
		system("cls");
		int i;
		printf("\t\t    ************��ӭѧ����Ϣ����**********\n\n\n\n\t");
		for (i=0; i<60; i++)
            printf("-");
        printf("\n");
		printf("\t\t1.ѧ���˺�����\t\t2.ѧ���˺�ע��\n\t\t3.ѧ����������\t\t4.�鿴ѧ���˺�\n\t\t0.�˳�\n\t");
		fflush(stdin);
		for (i=0; i<60; i++)
            printf("-");
        printf("\n\n\n��ѡ��");
		char choice = getch();
		switch(choice) {
		case '1':
		    stu_regist();
			break;
		case '2':
		    remove_client();
			break;
		case '3':
		    reset_passwords();
			break;
        case '4':
            look_stu_account();
            break;
		case '0':
			return;
		default:
			break;
		}
	}
}
void stu_regist() {
    int i;
loop:system("cls");
    printf("\t\t    ************��ӭ����ѧ���˺�**********\n\n\t");
    for (i=0; i<60; i++)
        printf("-");
    printf("\n");
    print_major();
    printf("\n\t  �꼶�� \t1\t2\t3\t4");
    printf("\n\t  �༶��        ");
    for (i=1; i<=Class_MaxSize; i++)
        printf("%d  ", i);
    printf("\n\t");
    for (i=0; i<60; i++)
        printf("-");
    printf("\n");
    char instit_name[NP_MaxSize], major_name[NP_MaxSize];
    int class_num, grade_num;
    printf("\n��ѡ��:\n\n");
    printf("\tѧԺ: ");
    fflush(stdin);
    scanf("%s", instit_name);
    if (!judge_inst_exit(instit_name)) {
        printf("ѧУδ������ѧԺ�������ڴ���\n");
        limit_time(3);
        return;
    }
    printf("\tרҵ: ");
    fflush(stdin);
    scanf("%s", major_name);
    int major_index = judge_major_exit(major_name, instit_name);
    if (major_index == -1) {
        printf("\nѧУδ������רҵ���Ƿ��������?��n/y��\n");
        char a;
        while (1) {
            fflush(stdin);
            a = getch();
            if (a == 'n')
                return;
            if (a == 'y')
                goto loop;
        }
    }
    printf("\t�꼶��");
    fflush(stdin);
    while (1) {
        scanf("%d", &grade_num);
        if (grade_num>0 && grade_num<=4)
            break;
        printf("����������:");
    }
    int num = get_class_size(major_name, instit_name);
    printf("   �༶<1-%d>��", num);
    while (1) {
        scanf("%d", &class_num);
        if (class_num>0 && class_num<=num)
            break;
        printf("���������룺");
    }
    system("cls");
    printf("\t\t    ************��ӭ����ѧ���˺�**********\n\n\t");
    for (i=0; i<60; i++)
        printf("-");
    printf("\n\t�����˻�����Ϣ��\n\n");
    printf("\t\t  ѧԺ�� \t%s\n", instit_name);
    printf("\t\t  רҵ�� \t%s\n", major_name);
    printf("\t\t  �꼶�� \t%d\n", grade_num);
    printf("\t\t  �༶�� \t%d\n", class_num);
    printf("\t");
    for (i=0; i<60; i++)
        printf("-");
    printf("\n�����룬���������֣�ѧ��<1-%d>(����#������)��\n\n", AS_MaxSize-1);
    char name[NP_MaxSize], sid[AS_MaxSize], account[AS_MaxSize];
    struct Client tmpt;
    int sign = 0, j;
    srand(time(NULL));
    list<char*> failure_client;
    map<string, string> success_client;
    map<string, string>::const_iterator p;
    while (1) {
        if (get_client_num() == MC_MaxSize) {
            printf("�û��Ѵﵽ���ޣ��ܾ�ע�ᣡ\n");
            limit_time(3);
            return;
        }
    loop3:while (1) {
            scanf("%s", name);
            if (strlen(name)<NP_MaxSize-1)
                break;
            printf("�������ޣ����������룺");
        }
        if (name[0] == '#')
            break;
        while (1) {
            while (1) {
        loop2:  scanf("%s", sid);
                for (i=0; i<AS_MaxSize-1; i++) {
                    if (sid[i]>'9' || sid[i]<'0') {
                        printf("���������֣�");
                        goto loop2;
                    }
                }
                if (strlen(sid) == AS_MaxSize-1)
                    break;
                printf("������Χ�����������룺");
            }
            if (!judge_sid_eixt(sid))
                break;
            printf("��ѧ���Ѵ��ڣ����������룺");
        }
    loop1:for (j=0; j<AS_MaxSize-1; j++)
            account[j] = (char)(rand()%10+48);
        account[AS_MaxSize-1] = '\0';
        if (judge_account_exit(account))
            goto loop1;
        strcpy(tmpt.account, account);
        strcpy(tmpt.name, name);
        strcpy(tmpt.passwords, "00000");
        strcpy(tmpt.sid, sid);
        tmpt.inform.grade = grade_num;
        strcpy(tmpt.inform.institu_name, instit_name);
        tmpt.inform.class_ = class_num;
        tmpt.inform.index = major_index;

        FILE *fp;
        if ((fp=fopen("client.txt", "ab")) == NULL) {
            sign = 1;
            failure_client.push_back(tmpt.name);
            fclose(fp);
            goto loop3;
        }
        if (fwrite(&tmpt, sizeof(struct Client), 1, fp) != 1) {
            sign = 1;
            failure_client.push_back(tmpt.name);
            fclose(fp);
            goto loop3;
        }
        success_client[string(tmpt.name)] = string(tmpt.account);
        fclose(fp);
    }
    printf("\n\n\t\t\t\t\t\t\tע����...");
    limit_time(2);
    system("cls");
    printf("\t\t    ************��ӭ����ѧ���˺�**********\n\n");
    i=1;
    if (sign == 1) {
        printf("����ϵͳ������һ������ע��ʧ�ܣ�\n\n");
        printf("ע��ʧ��������\n\n");
        while (1) {
            if (failure_client.size() == 0)
                break;
            printf("%d:\t%s\n", i++, failure_client.front());
            failure_client.pop_front();
        }
        printf("\n\n");
    }

    if (!success_client.empty()) {
        printf("ע��ɹ�������\n\n");
        i = 1;
        printf("\t���\t����\t\t�˺�\n");
        for (p=success_client.begin(); p!=success_client.end(); p++)
            printf("\t%d:\t%s\t\t%s\n", i++, (p->first).c_str(), (p->second).c_str());
        printf("\n\n");
    }
    system("pause");
}
int  get_client_num() {
    FILE *fp;
    if ((fp=fopen("client.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return 0;
    }
    struct Client tmpt;
    int num = 0;
    while (1) {
        fread(&tmpt, sizeof(struct Client), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        num++;
    }
    return num;
}
bool judge_account_exit(char *a) {
    FILE *fp;
    if ((fp=fopen("client.txt", "rb")) == 0) {
        printf("ϵͳ����!\n");
        system("pause");
        return false;
    }
    struct Client tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Client), 1, fp);
        if (feof(fp))
            break;
        if (strcmp(tmpt.account, a) == 0)
            return true;
    }
    return false;
}
bool judge_sid_eixt(char *s) {
    FILE *fp;
    if ((fp=fopen("client.txt", "rb")) == 0) {
        printf("ϵͳ����!\n");
        system("pause");
        return false;
    }
    struct Client tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Client), 1, fp);
        if (feof(fp))
            break;
        if (strcmp(tmpt.sid, s) == 0)
            return true;
    }
    return false;
}
void remove_client() {
    while (1) {
        int i;
loop:   system("cls");
        printf("\t\t     *************��ӭע���û�***********   \n\n\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t  1.����ɾ��\n\t\t\t\t  2.����ɾ��\n\t\t\t\t  0.�˳�\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        fflush(stdin);
        char a = getch();
        if (a == '0')
            return;
        if (a != '1' && a != '2')
            goto loop;
        struct Client tmpt;
        list<struct Client> client_list;
        FILE *fp;
        if (a == '1') {
        loop3: system("cls");
            printf("\t\t     *************��ӭע���û�***********   \n\n\n");
            printf("������Ҫɾ��ѧ�����˺ţ�");
            char account[AS_MaxSize];
            fflush(stdin);
        loop1:scanf("%s", account);
            if (!judge_account_exit(account)) {
                printf("���˺Ų����ڣ��Ƿ��������룿��n/y��");
                char a;
                while (1) {
                    fflush(stdin);
                    a = getch();
                    if (a == 'n')
                        goto loop;
                    if (a == 'y')
                        goto loop3;
                }
            }
            if ((fp=fopen("client.txt", "rb")) == 0) {
                printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
                system("pause");
                goto loop;
            }
            while (1) {
                fread(&tmpt, sizeof(struct Client), 1, fp);
                if (feof(fp))
                    break;
                if (strcmp(tmpt.account, account) == 0)
                    continue;
                client_list.push_back(tmpt);
            }
            fclose(fp);
            if ((fp=fopen("client.txt", "wb")) == NULL) {
                printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
                system("pause");
                goto loop;
            }
            while (1) {
                if (client_list.size() == 0)
                    break;
                if (fwrite(&client_list.front(), sizeof(struct Client), 1, fp) != 1) {
                    printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
                    system("pause");
                    fclose(fp);
                    goto loop;
                }
                client_list.pop_front();
            }
            fclose(fp);
        } else {
            system("cls");
            printf("\t\t     *************��ӭע���û�***********   \n\n\n\t     ");
            for (i=0; i<50; i++)
                printf("-");
            printf("\n");
            print_institute();
            printf("\t    ");
            for (i=0; i<50; i++)
                printf("-");
            char instit_name[NP_MaxSize];
            printf("\n");
            printf("\t��ѡ��\n\n\tѧԺ: ");
            fflush(stdin);
            scanf("%s", instit_name);
            if (!judge_inst_exit(instit_name)) {
                printf("ѧУδ������ѧԺ�������ڴ���\n");
                limit_time(3);
                return;
            }
            printf("ȷ��Ҫɾ����ѧԺ������ѧ������n/y��");
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    goto loop;
                if (a == 'y')
                    break;
            }
            if ((fp=fopen("client.txt", "rb")) == 0) {
                printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
                system("pause");
                goto loop;
            }
            while (1) {
                fread(&tmpt, sizeof(struct Client), 1, fp);
                if (feof(fp))
                    break;
                if (strcmp(tmpt.inform.institu_name, instit_name) != 0)
                    client_list.push_back(tmpt);
            }
            fclose(fp);
            if ((fp=fopen("client.txt", "wb")) == 0) {
                printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
                system("pause");
                goto loop;
            }
            while (1) {
                if (client_list.size() == 0)
                    break;
                if (fwrite(&client_list.front(), sizeof(struct Client), 1, fp) ==1) {
                    printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
                    system("pause");
                    goto loop;
                }
                client_list.pop_front();
            }
            fclose(fp);
        }
        printf("\n\n\t\t\t\t\t\tɾ���ɹ�!\n");
        limit_time(2);
        fclose(fp);
        goto loop;
        system("pause");
    }
}
void reset_passwords() {
    while (1) {
        int i;
loop:   system("cls");
        printf("\t\t     *************��ӭ��������***********   \n\n\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t  1.����\n\t\t\t\t  0.�˳�\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        fflush(stdin);
        char a = getch();
        if (a == '0')
            return;
        if (a != '1')
            goto loop;
        printf("������Ҫ��������ѧ�����˺ţ�");
        char account[AS_MaxSize];
        fflush(stdin);
    loop1:scanf("%s", account);
        if (!judge_account_exit(account)) {
            printf("���˺Ų����ڣ��Ƿ��������룿��n/y��");
            char a;
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    return;
                if (a == 'y')
                    goto loop;
            }
        }
        FILE *fp;
        if ((fp=fopen("client.txt", "rb")) == 0) {
            printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
            system("pause");
            goto loop;
        }
        struct Client tmpt;
        list<struct Client> client_list;
        while (1) {
            fread(&tmpt, sizeof(struct Client), 1, fp);
            if (feof(fp))
                break;
            if (strcmp(tmpt.account, account) == 0)
                strcpy(tmpt.passwords, "00000");
            client_list.push_back(tmpt);
        }
        fclose(fp);
        if ((fp=fopen("client.txt", "wb")) == NULL) {
            printf("ϵͳ������������ʧ�ܣ�\n");
            system("pause");
            goto loop;
        }
        while (1) {
            if (client_list.empty())
                break;
            if (fwrite(&client_list.front(), sizeof(struct Client), 1, fp) !=1) {
                printf("ϵͳ����!��������ʧ�ܣ�\n");
                system("pause");
                fclose(fp);
                goto loop;
            }
            client_list.pop_front();
        }
        fclose(fp);
        limit_time(2);
        printf("\t\t\t\t\t���óɹ���");
    }
}
void look_stu_account() {
    while (1) {
        int i;
 loop:  system("cls");
        printf("\t\t    ************��ӭ�鿴ѧ���˺�**********\n\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t1.����\n\t\t\t\t2.�鿴ȫ��\n\t\t\t\t0.�˳�\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        fflush(stdin);
        char a = getch();
        fflush(stdin);
        switch(a) {
            case '1': {
            loop1:  system("cls");
                printf("\t\t       ************��ӭ�鿴ѧ���˺�**********    \n\n");
                printf("������Ҫ����ѧ��ѧ��(5λ)��");
                char sid[AS_MaxSize];
                fflush(stdin);
                while (1) {
            loop2:  scanf("%s", sid);
                    for (i=0; i<AS_MaxSize-1; i++) {
                        if (sid[i]>'9' || sid[i]<'0') {
                            printf("���������֣�");
                            goto loop2;
                        }
                    }
                    if (strlen(sid) == AS_MaxSize-1)
                    break;
                    printf("������Χ�����������룺");
                }
                FILE *fp;
                if ((fp=fopen("client.txt", "rb")) == 0) {
                    printf("ϵͳ����!����ʧ��\n");
                    system("pause");
                    goto loop1;
                }
                struct Client tmpt;
                while (1) {
                    fread(&tmpt, sizeof(struct Client), 1, fp);
                    if (feof(fp))
                        break;
                    if (strcmp(tmpt.sid, sid) == 0) {
                        system("cls");
                        printf("\t\t       ************��ӭ�鿴ѧ���˺�**********    \n\n\t\t");
                        for (i=0; i<50; i++)
                            printf("-");
                        printf("\n");
                        printf("\t\t����\t\t�˺�\t\tѧ��\n");
                        printf("\n\t\t%s\t\t%s\t\t%s\n\n\t\t", tmpt.name, tmpt.account, tmpt.sid);
                        for (i=0; i<50; i++)
                            printf("-");
                        printf("\n\n\t\t\t\t\t\t");
                        system("pause");
                        goto loop;
                    }
                }
                printf("��ѧ�������ڣ��Ƿ�������ң���n/y��");
                while (1) {
                    fflush(stdin);
                    a = getch();
                    if (a == 'n')
                        return;
                    if (a == 'y')
                        goto loop1;
                }
            }
                break;;
            case '2':
                system("cls");
                printf("\t\t       ************��ӭ�鿴ѧ���˺�**********    \n\n\t");
                for (i=0; i<50; i++)
                    printf("-");
                printf("\n");
                look_all_client();
                printf("\t");
                for (i=0; i<50; i++)
                    printf("-");
                printf("\n\n\t\t\t\t\t\t");
                system("pause");
                break;
            case '0':
                return;
            default:
                break;
        }

    }
}
bool judge_name_exit(char *name) {
    FILE *fp;
    if ((fp=fopen("client.txt", "rb")) == NULL)
        return -1;
    struct Client tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Client), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return false;
        }
        if (strcmp(name, tmpt.name) == 0) {
            fclose(fp);
            return true;
        }
    }
}
void look_all_client() {
    FILE *fp;
    if ((fp=fopen("client.txt", "rb")) == 0) {
        printf("ϵͳ����!\n");
        system("pause");
        return;
    }
    struct Client tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Client), 1, fp);
        if (feof(fp))
            break;
        printf("\t\t\t%s  :  %s\n", tmpt.name, tmpt.account);
    }
    return;
}

///                         <2>.ͼ������ܺ���
void manage_book_menue() {
    while (1) {
		system("cls");
		int i;
		system("cls");
		printf("\n\t\t ****************��ӭʹ��ϵͳ����****************\n\n\n\t  ");
		for (i=0; i<60; i++)
            printf("-");
        printf("\n");
		printf("\t\t\t1.���ͼ��\t\t2.ɾ��ͼ��\n\t\t\t3.ͼ��ͳ��\t\t4.ͼ�����\n\t\t\t");
		printf("5.�鿴ͼ��\t\t0.�˳�\n\t  ");
		for (i=0; i<60; i++)
            printf("-");
        printf("\n\n");

		fflush(stdin);
		char choice = getch();
		switch(choice) {
		case '1':
		    add_book();
			break;
		case '2':
		    delete_book();
			break;
		case '3':
		    count_book();
			break;
		case '4':
            find_book();
			break;
        case '5':
            print_book();
            break;
		case '0':
			return;
		default:
			break;
		}
	}
}
void add_book() {
     while (1) {
        int i;
loop:   system("cls");
        printf("\t\t    ************��ӭ���ͼ��**********\n\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t1.���\n\t\t\t\t0.�˳�\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        fflush(stdin);
        char a = getch();
        fflush(stdin);
        if (a == '0')
            return;
        if (a != '1')
            goto loop;
loop1:  system("cls");
        printf("\t\t       ************��ӭ���ͼ��**********    \n\n");
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(hOut, 0, 4);
        printf("������ͼ����(%dλ)��", AS_MaxSize-2);
        gotoxy(hOut, 0, 5);
        printf("������ͼ�����ƣ�");
        gotoxy(hOut, 0, 6);
        printf("������ͼ�����ߣ�");
        gotoxy(hOut, 0, 7);
        printf("������ͼ��۸�");
        gotoxy(hOut, 0, 8);
        printf("������ͼ���飺");
        gotoxy(hOut, 0, 10);
        printf("������ͼ��������");
        gotoxy(hOut, 0, 12);
        int p = prin_sort_name();
        char book_name[NP_MaxSize]="", book_author[NP_MaxSize], bool_intro[Talk_MaxSize], book_num[AS_MaxSize];
        while (1) {
            fflush(stdin);
    loop2:  gotoxy(hOut, 22, 4);
            scanf("%s", book_num);
            getchar();
            for (i=0; i<strlen(book_num); i++) {
                if (book_num[i]>'9' || book_num[i]<'0') {
                    gotoxy(hOut, 22, 4);
                    printf("���������֣�");
                    limit_time(1);
                    gotoxy(hOut, 22, 4);
                    printf("                    ");
                    goto loop2;
                }
            }
            if (strlen(book_num) == AS_MaxSize-2)
                break;

            gotoxy(hOut, 22, 4);
            printf("������%dλ��", AS_MaxSize-2);
            limit_time(1);
            goto loop1;
        }
        int n = get_booknum(book_num);
        if (n>0) {
            gotoxy(hOut, 22, 4);
            printf("�ñ���Ѵ���!���������룡");
            limit_time(2);
            goto loop1;
        }
        struct Book book;
        strcpy(book.book_num, book_num);
        gotoxy(hOut, 16, 5);
        fflush(stdin);
        scanf("%s", book.name);
        getchar();
        gotoxy(hOut, 16, 6);
        fflush(stdin);
        scanf("%s", book.author);
        getchar();
        gotoxy(hOut, 16, 7);
        fflush(stdin);
        scanf("%s", &book.price);
        getchar();
        gotoxy(hOut, 16, 8);
        fflush(stdin);
        scanf("%s", book.introducation);
        while (1) {
            gotoxy(hOut, 16, 10);
            fflush(stdin);
            scanf("%s", &book.num);
            if (strlen(book.num) < 3)
                break;
            gotoxy(hOut, 16, 10);
            printf("          ");
        }
        gotoxy(hOut, 0, 12+p);
        printf("������ͼ����ࣺ");
        char sort_name[NP_MaxSize];
        scanf("%s", sort_name);
        strcpy(book.origin, sort_name);
        FILE *fp, *fb;
        if ((fp=fopen("library.txt", "ab")) == NULL) {
        loop3:printf("ϵͳ�������ʧ��!\n");
            system("pause");
            goto loop;
        }
        int sign = 0, t = 97, c = 0;
        int num = judge_origin_exit(sort_name);
        if (num == 0) {
            if ((fb=fopen("sort_book.txt", "ab")) == NULL)
                goto loop3;
            if (fwrite(&sort_name, sizeof(sort_name), 1, fb) != 1) {
                fclose(fb);
                goto loop3;
            }
            fclose(fb);
        }
        if (num == -1)
            goto loop3;
        for (i=0; i<atoi(book.num); i++) {
            book.book_num[4] = (char)t++;
            book.book_num[5] = '\0';
            if (fwrite(&book, sizeof(struct Book), 1, fp) != 1) {
                c++;
                sign = 1;
            }
        }
        if (sign == 1) {
            printf("ϵͳ����%d�������ʧ��", c);
            system("pause");
            fclose(fp);
            goto loop;
        }
        printf("\n\n\t\t\t\t\t\t\t��ӳɹ�!\n");
        fclose(fp);
        limit_time(2);
        goto loop;
	}
}
int  prin(char* sort_name) {
    FILE *fp;
    struct Book tmpt;
    char tmpt_name[NP_MaxSize], num_[AS_MaxSize];;
    if (get_book_num() == 0) {
        return 2;
    }
    if ((fp=fopen("library.txt", "rb")) == NULL)
        return 0;
    if (sort_name == NULL) {
        printf("\t����ͼ�飺\n\n");
        printf("\t\tͼ����\t\t\tͼ����\n");
        while (1) {
            fread(&tmpt, sizeof(struct Book), 1, fp);
            if (feof(fp)) {
                fclose(fp);
                return 1;
            }
            if (strcmp(tmpt_name, tmpt.name) == 0)
                continue;
            strcpy(tmpt_name, tmpt.name);
            strcpy(num_, tmpt.book_num);
            num_[AS_MaxSize-2] = '\0';
            printf("\t\t%s:\t\t\t\t%s\n", num_, tmpt.name);
        }
    } else {
        strcpy(tmpt_name, "");
        int num = judge_origin_exit(sort_name);
        if (num == -1)
            return 0;
        if (num == 0)
            return 2;
        int j = 1;
        while (1) {
            fread(&tmpt, sizeof(struct Book), 1, fp);
            if (feof(fp)) {
                fclose(fp);
                return 1;
            }
            if (strcmp(tmpt.origin, sort_name) == 0) {
                if (strcmp(tmpt_name, tmpt.name) == 0)
                    continue;
                strcpy(tmpt_name, tmpt.name);
                strcpy(num_, tmpt.num);
                num_[AS_MaxSize-2] = '\0';
                printf("\t%d:\t%s\t\t\t\t%s\n", j++, tmpt.name, num_);
            }
        }
    }
}
void delete_book() {
    while (1) {
        int i, t;
loop:   system("cls");
        printf("\t\t    ************��ӭɾ��ͼ��**********\n\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t1.��ͼ������ɾ��\n\t\t\t\t2.��ͼ����ɾ��\n\t\t\t\t0.�˳�\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        fflush(stdin);
        char a = getch();
        fflush(stdin);
        if (a == '0')
            return;
        if (a != '1' && a != '2')
            goto loop;
loop1:  system("cls");
        printf("\t\t       ************��ӭɾ��ͼ��**********    \n\n");
        char book_name[NP_MaxSize], book_num[AS_MaxSize];
        if (a == '1') {
            printf("������Ҫɾ��ͼ������ƣ�");
            scanf("%s", book_name);
            t = delet(book_name, 1);
        }
        if (a == '2') {
            printf("������Ҫɾ��ͼ��ı�ţ�");
            while (1) {
            loop2:fflush(stdin);
                scanf("%s", book_num);
                for (i=0; i<strlen(book_num); i++) {
                    if (book_num[i]>'9' || book_num[i]<'0') {
                        printf("����������:");
                        limit_time(1);
                        goto loop1;
                    }
                }
                if (strlen(book_num) == AS_MaxSize-2)
                    break;
                printf("������%dλ��\n", AS_MaxSize-2);
                limit_time(1);
                goto loop1;
            }
            int d = 0, m;
            d = get_booknum(book_num);
            if (d == 0) {
                printf("\n\n\t\t\t\t\t\t\tͼ����û�и��飡");
                limit_time(2);
                goto loop;
            }
            //book_num[AS_MaxSize-2] = (char)(96+d);
            //book_num[AS_MaxSize-1] = '\0';
            t = delet(book_num, 2);
        }
        if (t == 0)
            printf("\n\n\n\n\t\t\t\t\t\t\t����ϵͳ����ɾ��ʧ�ܣ�\n");
        if (t == 2)
            printf("\n\n\n\n\t\t\t\t\t\t\t�����û���ҵ����飡\n");
        if (t == 1)
            printf("\n\n\t\t\t\t\t\t\tɾ���ɹ�!\n");
        if (t == 3)
            printf("\n\n\t\t\t\t\t�����ѱ����������ɾ����");
        delete_origin();
        limit_time(2);
        goto loop;
    }
}
int  delet(char* data, int i) {
    FILE *fp;
    list <struct Book> del_list;
    struct Book tmpt;
    struct LendBook lent_book;
    int sign = 0;
    if (i == 1) {
        if ((fp=fopen("lent_book.txt", "rb")) == NULL)
            return 0;
        while (1) {
            fread(&lent_book, sizeof(struct LendBook), 1, fp);
            if (feof(fp)) {
                fclose(fp);
                break;
            }
            if (strcmp(lent_book.name, data) == 0) {
                fclose(fp);
                return 3;
            }
        }
        if ((fp=fopen("library.txt", "rb")) == NULL)
            return 0;
        while (1) {
            fread(&tmpt, sizeof(struct Book), 1, fp);
            if (feof(fp))
                break;
            if (strcmp(tmpt.name, data) == 0) {
                sign = 1;
                continue;
            }
            del_list.push_back(tmpt);
        }
    } else {
        char booknum[AS_MaxSize];
        strcpy(booknum, data);
        int j = 1, t = get_booknum(data), sign_num = 0;
    loop:while (j<=t) {
            booknum[AS_MaxSize-2] = (char)(96+j);
            booknum[AS_MaxSize-1] = '\0';
            if ((fp=fopen("lent_book.txt", "rb")) == NULL)
                return 0;
            while (1) {
                fread(&lent_book, sizeof(struct LendBook), 1, fp);
                if (feof(fp)) {
                    fclose(fp);
                    break;
                }
                if (strcmp(lent_book.book_num, booknum) == 0) {
                    fclose(fp);
                    sign_num++;
                    j++;
                    goto loop;
                }
            }
            strcpy(data, booknum);
            break;
        }
        if (sign_num == t)
            return 3;
        if ((fp=fopen("library.txt", "rb")) == NULL)
            return 0;
        char name[NP_MaxSize];
        strcpy(name, get_book_name(data));
        while (1) {
            fread(&tmpt, sizeof(struct Book), 1, fp);
            if (feof(fp))
                break;
            if (strcmp(tmpt.name, name) == 0) {
                int t = atoi(tmpt.num)-1;
                itoa(t, tmpt.num, 10);
            }
            if (strcmp(tmpt.book_num, data) == 0) {
                sign = 1;
                continue;
            }
            del_list.push_back(tmpt);
        }
    }
    fclose(fp);
    if (sign == 0)
        return 2;
    if ((fp=fopen("library.txt", "wb")) == NULL)
        return 0;
    int num = 0;
    while (1) {
        if (del_list.empty()) {
            break;
        }
        if (fwrite(&del_list.front(), sizeof(struct Book), 1, fp)!=1) {
            printf("ϵͳ���󣡰�������ٴγ��ԣ�\n");
            num++;
            if (num == 20) {
                fclose(fp);
                return 0;
            }
            getchar();
            continue;
        }
        del_list.pop_front();
    }
    fclose(fp);
    return 1;
}
int  get_booknum(char *book_num) {
    FILE *fp;
    struct Book tmpt;
    if ((fp=fopen("library.txt", "rb")) == NULL) {
        fclose(fp);
        return 0;
    }
    while (1) {
        fread(&tmpt, sizeof(struct Book), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return 0;
        }
        tmpt.book_num[4] = '\0';
        if (strcmp(tmpt.book_num, book_num) == 0) {
            fclose(fp);
            return atoi(tmpt.num);
        }
    }
}
int  get_book_num() {
    FILE *fp;
    struct Book tmpt;
    int num = 0;
    if ((fp=fopen("library.txt", "rb")) == NULL) {
        return -1;
    }
    while (1) {
        fread(&tmpt, sizeof(struct Book), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return num;
        }
        num++;
    }
}
void count_book() {
loop:system("cls");
    printf("\t\t    ************��ӭ�鿴ͼ����Ŀ**********\n\n\n\t");
    FILE *fp;
    char name[NP_MaxSize];
    int num = 0, t, i;
    for (i=0; i<60; i++)
            printf("-");
        printf("\n");
    if ((fp=fopen("sort_book.txt", "rb")) == NULL) {
    loop1:printf("ϵͳ���󣡲鿴ʧ�ܣ���������ͳ�ƣ����Ե�....");
        limit_time(2);
        goto loop;
    }
    int sum = 0;
    while (1) {
        fread(name, sizeof(name), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        int n = 0;
        t = get_origin_num(name, n);
        sum += n;
        if (t == -1)
            goto loop1;
        printf("\t\t\t%s���� %d �� %d ����\n", name, n, t);
    }
    printf("\n\t\t\t�ݲع��� %d �� %d ����\n\t", sum, get_book_num());
    for (i=0; i<60; i++)
            printf("-");
    printf("\n\n\n\t\t\t\t\t\t\t");
    system("pause");
}
void find_book() {
loop:system("cls");
    printf("\t\t    ************��ӭ����ͼ��**********\n\n\n\n");
    printf("������Ҫ����ͼ������֣�");
    char book_name[NP_MaxSize];
    scanf("%s", book_name);
    FILE *fp;
    struct Book tmpt;
    if ((fp=fopen("library.txt", "rb")) == NULL) {
        printf("ϵͳ����");
        system("pause");
        goto loop;
        fclose(fp);
    }
    int sign = 0, i;
    while (1) {
        fread(&tmpt, sizeof(struct Book), 1, fp);
        if (feof(fp)) {
        loop1:fclose(fp);
            if (sign == 0) {
                system("cls");
                printf("\t\t    ************��ӭ����ͼ��**********\n\n\n\n\t");
                for (i=0; i<60; i++)
                    printf("-");
                printf("\n");
                printf("\n\n\t\t\t\tû���ҵ���ͼ��!\n\n\n\t");
            }
            fclose(fp);
            for (i=0; i<60; i++)
                printf("-");
            printf("\n\n\n\t\t\t\t\t\t");
            system("pause");
            return;
        }
        char num[AS_MaxSize];
        if (strcmp(tmpt.name, book_name) == 0) {
            strcpy(num, tmpt.book_num);
            num[AS_MaxSize-2] = '\0';
            printf("\n��ţ�%s\n���֣�%s\n���ߣ�%s\n�۸�%s\n��飺%s\n\n", num, tmpt.name, tmpt.author, tmpt.price, tmpt.introducation);
            sign = 1;
            goto loop1;
        }
    }
}
void print_book() {
    int i;
    while (1) {
    loop:system("cls");
        printf("\t\t    ************��ӭ�鿴ͼ��**********\n\n\n\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t  1.�鿴����\n\t\t\t\t  2.����鿴\n\t\t\t\t  0.�˳�\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        char a = getch();
        fflush(stdin);
loop1:  system("cls");
        printf("\t\t     *************��ӭ�鿴ͼ��***********   \n\n\n\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n");
        char *p, sort_name[NP_MaxSize];
        switch(a) {
        case '1':
            p = NULL;
            break;
        case '2': {
            int num = prin_sort_name();
            if (num == -1) {
                printf("\t");
                for (i=0; i<60; i++)
                    printf("-");
                printf("\n");
        loop2:  printf("ϵͳ����");
                limit_time(2);
                goto loop1;
            }
            if (num == 0) {
                printf("\t\t\t\t��û��ͼ����࣡\n\t");
                for (i=0; i<60; i++)
                    printf("-");
                limit_time(2);
                goto loop;
            }
            printf("\t");
            for (i=0; i<60; i++)
                printf("-");
            printf("\n");
            printf("\n\n������Ҫ�鿴ͼ��ķ�������");
            scanf("%s", sort_name);
            int tmpt = judge_origin_exit(sort_name);
            if (tmpt == -1)
                goto loop2;
            if (tmpt == 0) {
                printf("\n\n\t\t\t\t\t\t�÷��಻���ڣ�\n");
                limit_time(2);
                goto loop;
            }
            p = sort_name;
            break;
        }
        case '0':
            return;
        default:
            goto loop;
        }
        system("cls");
        printf("\t\t     *************��ӭ�鿴ͼ��***********   \n\n\n\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n");
        prin(p);
        printf("\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n\n\t\t\t\t\t\t");
        system("pause");
    }
}
int delete_origin() {
    FILE *fp;
    list<string> sorted_list;
    char name[NP_MaxSize];
    int t;
    if ((fp=fopen("sort_book.txt", "rb")) == NULL)
        return 0;
    while (1) {
        fread(&name, sizeof(name), 1, fp);
        if (feof(fp))
            break;
        int n = 0;
        t = get_origin_num(name, n);
        if (t == -1)
            return 0;
        if (t != 0)
            sorted_list.push_back(string(name));
    }
    fclose(fp);
    if ((fp=fopen("sort_book.txt", "wb")) == 0)
        return 0;
    while (1) {
        if (sorted_list.empty())
            break;
        if (fwrite(sorted_list.front().c_str(), sizeof (name), 1, fp) != 1) {
            fclose(fp);
            return 0;
        }
        sorted_list.pop_front();
    }
    fclose(fp);
    return 1;
}
int judge_origin_exit(char* origin_name) {
    FILE *fp;
    int num = 0;
    if ((fp=fopen("sort_book.txt", "rb")) == NULL)
        return -1;
    char tmpt[NP_MaxSize];
    while (1) {
        fread(&tmpt, sizeof(tmpt), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return 0;
        }
        if (strcmp(origin_name, tmpt) == 0) {
            fclose(fp);
            return 1;
        }
    }
}
int get_origin_num(char* origin, int& t) {
    FILE *fp;
    struct Book tmpt;
    int num = 0;
    if ((fp=fopen("library.txt", "rb")) == NULL) {
        return -1;
    }
    char name[NP_MaxSize]="";
    while (1) {
        fread(&tmpt, sizeof(struct Book), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return num;
        }

        if (strcmp(tmpt.origin, origin) == 0) {
            if (strcmp(name, tmpt.name) != 0) {
                strcpy(name, tmpt.name);
                t++;
            }
            num++;
        }
    }
}
int prin_sort_name() {
    FILE *fp;
    int num = 0;
    if ((fp=fopen("sort_book.txt", "rb")) == NULL)
        return -1;
    char tmpt[NP_MaxSize];
    while (1) {
        fread(tmpt, sizeof(tmpt), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return num;
        }
        num++;
        printf("\t\t\t%d\t%s\n", num, tmpt);
    }
}
char *get_book_name(char* book_num) {
    FILE *fp;
    struct Book tmpt;
    if ((fp=fopen("library.txt", "rb")) == NULL)
        return NULL;
    while (1) {
        fread(&tmpt, sizeof(struct Book), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return NULL;
        }
        if (strcmp(tmpt.book_num, book_num) == 0)
            return tmpt.name;
    }
}

///                         <3>.ͼ����Ĺ��ܺ���
void manage_lbook_menue() {
    while (1) {
		system("cls");
		printf("\t\t\t  ��ӭ�鿴ͼ��������\n\n\n\t");
		printf("\t\t1.�鿴ͼ��������\t0.�˳�\n");
		fflush(stdin);
		char choice = getch();
		switch(choice) {
		case '1':
		    look_lend_book();
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}
void look_lend_book() {
	loop1:system("cls");
	printf("\t\t\t  ��ӭ�鿴ͼ��������\n\n");
	FILE *fp;
	struct LendBook p;
	if ((fp=fopen("lent_book.txt", "rb")) == NULL) {
		printf("ϵͳ���󣡲鿴ʧ�ܣ�\n");
		limit_time(2);
		return;
	}
	while (1) {
		fread(&p, sizeof(struct LendBook), 1, fp);
		if (feof(fp))
			break;
        printf("      ���:\t%s\n", p.book_num);
        printf("    ͼ����:\t%s\n", p.name);
        printf("    ������:\t%s\n", p.user_name);
        printf("�������˺�:\t%s\n", p.user_account);
        printf("  ����ʱ��:\t%d-%d-%d\n", p.begin_.year, p.begin_.month, p.begin_.day);
        int a = calculate_time(&p.begin_)-Bb_MaxSize;
        int b = a<0? 0:a;
        printf("  ��������:\t%d\n\n\n", b);
	}
	fclose(fp);
	printf("\n\n\n\n\t\t\t\t\t\t");
	system("pause");
}

///                         <4>.���ù��ܺ���
void set_menue() {
    system("cls");
    printf("\t\t\t\t��ӭʹ�ø߼�����\n\n");
    printf("������ϵͳ��½���룺");
    char a[NP_MaxSize];
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, p = 20;
    gotoxy(hOut, 20, 2);
    for (i=0; i<NP_MaxSize; i++) {
            a[i] = getch();
            if (a[i] == 13) {
                if (i == 0) {
                    gotoxy(hOut, 20, 2);
                    i--;
                    continue;
                } else {
                    a[i] = '\0';
                    break;
                }
            }
            if (a[i] == 8) {
                if (i != 0) {
                    i--;
                    gotoxy(hOut, --p, 2);
                    printf(" ");
                    gotoxy(hOut, p, 2);
                }
                i--;
                continue;
            }
            if (a[i] == 32) {
                gotoxy(hOut, p, 2);
                i--;
                continue;
            }
            p++;
            printf("*");
        }
        a[NP_MaxSize-1] = '\0';
    if (strcmp(a, "88888") != 0) {
        printf("ERROR!�ܾ����ʣ�");
        limit_time(2);
        return;
    }
    while (1) {
		system("cls");
		printf("\n\t\t ****************��ӭʹ��ϵͳ����****************\n\n\n\t  ");
		for (i=0; i<60; i++)
            printf("-");
        printf("\n");
		printf("\t\t\t1.���ѧԺ\t\t2.���רҵ\n\t\t\t3.ɾ��ѧԺ\t\t4.ɾ��רҵ\n\t\t\t5.����Ա����\t\t0.�˳�\n\t  ");
		for (i=0; i<60; i++)
            printf("-");
        printf("\n\n");
        fflush(stdin);
		char choice = getch();
		switch(choice) {
		case '1':
		    add_institute();
			break;
		case '2':
		    add_major();
			break;
		case '3':
		    delet_institute();
			break;
		case '4':
		    delet_major();
			break;
        case '5':
            do_server();
            break;
		case '0':
			return;
		default:
			break;
		}
	}
}
void add_institute() {
    while (1) {
        int i;
loop:   system("cls");
        printf("\t\t    ************��ӭ���ѧԺ**********\n\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t1.���\n\t\t\t\t0.�˳�\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        fflush(stdin);
        char a = getch();
        fflush(stdin);
        if (a == '0')
            return;
        if (a != '1')
            goto loop;
loop1:  system("cls");
        printf("\t\t       ************��ӭ���ѧԺ**********    \n\n");
        printf("������Ҫ���ѧԺ�����ƣ�");
        struct Institute tmpt;
        fflush(stdin);
        scanf("%s", tmpt.name);
        getchar();
        if (judge_inst_exit(tmpt.name)) {
            printf("\n\n�������ѧԺ�Ѵ��ڣ��Ƿ�������루n/y��");
            char a;
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    return;
                if (a == 'y')
                    goto loop1;
            }
        }
        tmpt.init();
        FILE *fp;
        if ((fp=fopen("institute.txt", "ab")) == NULL) {
            printf("ϵͳ�������ʧ�ܣ�\n");
            return;
        }
        if (fwrite(&tmpt, sizeof(struct Institute), 1, fp) != 1) {
            printf("ϵͳ�������ʧ�ܣ�\n");
            return;
        }
        printf("\n\n\t\t\t\t\t\t��ӳɹ�!\n");
        limit_time(2);
        fclose(fp);
    }
}
void delet_institute() {
    while (1) {
        int i;
loop:   system("cls");
        printf("\t\t     *************��ӭɾ��ѧԺ***********   \n\n\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t  1.ɾ��\n\t\t\t\t  0.�˳�\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        char a = getch();
        fflush(stdin);
        if (a == '0')
            return;
        if (a != '1')
            goto loop;
        int num = print_institute();
loop1:  system("cls");
        printf("\t\t     *************��ӭɾ��ѧԺ***********   \n\n\n\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n");
        if (num == 0) {
            printf("\t\t\tѧУ��δ�����κ�ѧԺ�������ڴ�����\n\t");
            for (i=0; i<60; i++)
            printf("-");
            clock_t delay = 3*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            return;
        }
        if (num == -1) {
            printf("\t\t\tϵͳ����������Զ���ת����һ����\n\t");
            for (i=0; i<60; i++)
            printf("-");
            clock_t delay = 2*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            goto loop;
        }
        print_institute();
        printf("\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n\n");
        printf("������Ҫɾ��ѧԺ�����ƣ�");
        char institu_name[NP_MaxSize];
        fflush(stdin);
        scanf("%s", institu_name);
        getchar();
        if (!judge_inst_exit(institu_name)) {
            printf("\n\n�������ѧԺ�����ڣ��Ƿ�������루n/y��");
            char a;
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    return;
                if (a == 'y')
                    goto loop1;
            }
        }

        FILE *fp;
        if ((fp=fopen("institute.txt", "rb")) == NULL) {
            printf("ϵͳ����ɾ��ʧ�ܣ�\n");
            goto loop;
        }
        struct Institute tmpt;
        list<struct Institute> institu;
        while (1) {
            fread(&tmpt, sizeof(struct Institute), 1, fp);
            if (feof(fp))
                break;
            if (strcmp(tmpt.name, institu_name) == 0)
                continue;
            institu.push_back(tmpt);
        }
        fclose(fp);
        if ((fp=fopen("institute.txt", "wb")) == NULL) {
            printf("ϵͳ����ɾ��ʧ�ܣ�\n");
            fclose(fp);
            goto loop;
        }
        while (1) {
            if (institu.empty())
                break;
            struct Institute *pointer = &institu.front();
            strcpy(tmpt.name, pointer->name);
            for (i=0; i<Major_MaxSize; i++)
                strcpy(tmpt.major[i], pointer->major[i]);
            for (i=0; i<Class_MaxSize; i++)
                tmpt.class_num[i] = pointer->class_num[i];
            tmpt.num = pointer->num;
            if (fwrite(&tmpt, sizeof(struct Institute), 1, fp) != 1) {
                printf("ϵͳ����ɾ��ʧ�ܣ�\n");
                fclose(fp);
                goto loop;
            }
            institu.pop_front();
        }
        printf("\n\n\t\t\t\t\t\tɾ���ɹ�!\n");
        clock_t delay = 2*CLOCKS_PER_SEC;
        clock_t start = clock();
        while (clock()-start < delay);
        fclose(fp);
    }
}
bool judge_inst_exit(char *name) {
    FILE *fp;
    if ((fp=fopen("institute.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return true;
    }
    struct Institute tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Institute), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return false;
        }
        if (strcmp(tmpt.name, name) == 0) {
            fclose(fp);
            return true;
        }
    }
}
int  print_institute() {
    FILE *fp;
    if ((fp=fopen("institute.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return -1;
    }
    struct Institute tmpt;
    int i = 0;
    printf("\t����ѧԺ:\t���\tѧԺ��\n");
    while (1) {
        fread(&tmpt, sizeof(struct Institute), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        printf("\t\t\t%d\t%s\n", ++i, tmpt.name);

    }
    return i;
}
int  judge_major_exit(char *name, char *name1) {
    FILE *fp;
    if ((fp=fopen("institute.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return -1;
    }
    struct Institute tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Institute), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return -1;
        }
        int i;
        if (strcmp(tmpt.name, name1) == 0) {
            for (i=0; i<tmpt.num; i++) {
                if (strcmp(tmpt.major[i], name) == 0) {
                    fclose(fp);
                    return i;
                }
            }
            return -1;
        }
    }
}
void add_major() {
    while (1) {
        int i;
loop:   system("cls");
        printf("\t\t    ************��ӭ���רҵ**********\n\n\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t1.���\n\t\t\t\t0.�˳�\n\t   ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        fflush(stdin);
        char a = getch();
        fflush(stdin);
        if (a == '0')
            return;
        if (a != '1')
            goto loop;
        int num = print_institute();
loop1:  system("cls");
        printf("\t\t       ************��ӭ���רҵ**********    \n\n\n\t   ");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n");
        if (num == 0) {
            printf("\t\t\tѧУ��δ�����κ�ѧԺ�������ڴ�����\n\t");
        loop2:for (i=0; i<60; i++)
            printf("-");
            clock_t delay = 3*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            return;
        }
        if (num == -1) {
            printf("\t\t\tϵͳ����������Զ���ת����һ����\n\t");
            goto loop2;
        }

        if (get_major_size() >= Major_MaxSize) {
            printf("\t\t\t����������ޣ�\n\t");
            goto loop2;
        }
        print_institute();
        printf("\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n\n");
        printf("������Ҫ���רҵ����ѧԺ�����ƣ�");
        char institu_name[NP_MaxSize];
        char major_name[NP_MaxSize];
        fflush(stdin);
        scanf("%s", institu_name);
        getchar();
        if (!judge_inst_exit(institu_name)) {
            printf("\n\n�������ѧԺ�����ڣ��Ƿ�������루n/y��");
            char a;
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    return;
                if (a == 'y')
                    goto loop1;
            }
        }
        printf("\n������Ҫ���רҵ�����֣�");
        fflush(stdin);
        scanf("%s", major_name);
        getchar();
        if (judge_major_exit(major_name, institu_name) != -1) {
            printf("\n\n�������רҵ�Ѵ��ڣ��Ƿ�������루n/y��");
            char a;
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    return;
                if (a == 'y')
                    goto loop1;
            }
        }
        printf("\n��רҵ�༶��(1-%d)��", Class_MaxSize);
        while (1) {
            scanf("%d", &num);
            if (num<Class_MaxSize && num > 0)
                break;
            printf("�����������������룺");
        }
        struct Institute tmpt;
        FILE *fp;
        if ((fp=fopen("institute.txt", "rb")) == NULL) {
            printf("ϵͳ�������ʧ�ܣ�\n");
            goto loop;
        }
        list<struct Institute> institu;
        while (1) {
            fread(&tmpt, sizeof(struct Institute), 1, fp);
            if (feof(fp))
                break;
            institu.push_back(tmpt);
        }
        fclose(fp);
        if ((fp=fopen("institute.txt", "wb")) == NULL) {
            printf("ϵͳ�������ʧ�ܣ�\n");
            fclose(fp);
            goto loop;
        }
        while (1) {
            if (institu.empty())
                break;
            struct Institute *pointer = &institu.front();
            strcpy(tmpt.name, pointer->name);
            for (i=0; i<pointer->num; i++) {
                strcpy(tmpt.major[i], pointer->major[i]);
                tmpt.class_num[i] = pointer->class_num[i];
            }
            tmpt.num = pointer->num;
            if (strcmp(pointer->name, institu_name) == 0) {
                strcpy(tmpt.major[tmpt.num], major_name);
                tmpt.class_num[tmpt.num++] = num;
            }
            if (fwrite(&tmpt, sizeof(struct Institute), 1, fp) != 1) {
                printf("ϵͳ����ɾ��ʧ�ܣ�\n");
                fclose(fp);
                goto loop;
            }
            institu.pop_front();
        }
        printf("\n\n\t\t\t\t\t\t��ӳɹ�!\n");
        clock_t delay = 2*CLOCKS_PER_SEC;
        clock_t start = clock();
        while (clock()-start < delay);
        fclose(fp);
    }
}
void delet_major() {
    while (1) {
        int i;
loop:   system("cls");
        printf("\t\t     *************��ӭɾ��רҵ***********   \n\n\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n");
        printf("\t\t\t\t  1.ɾ��\n\t\t\t\t  0.�˳�\n\t    ");
        for (i=0; i<50; i++)
            printf("-");
        printf("\n\n");
        printf("��ѡ��:");
        char a = getch();
        fflush(stdin);
        if (a == '0')
            return;
        if (a != '1')
            goto loop;
        int num = print_institute();
loop1:  system("cls");
        printf("\t\t     *************��ӭɾ��רҵ***********   \n\n\n\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n");
        if (num == 0) {
            printf("\t\t\tѧУ��δ�����κ�רҵ�������ڴ�����\n\t");
            for (i=0; i<60; i++)
            printf("-");
            clock_t delay = 3*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            return;
        }
        if (num == -1) {
            printf("\t\t\tϵͳ����������Զ���ת����һ����\n\t");
            for (i=0; i<60; i++)
            printf("-");
            clock_t delay = 2*CLOCKS_PER_SEC;
            clock_t start = clock();
            while (clock()-start < delay);
            goto loop;
        }
        print_major();
        printf("\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n\n");
        printf("������Ҫɾ��רҵ����ѧԺ�����ƣ�");
        char institu_name[NP_MaxSize], major_name[NP_MaxSize];
        fflush(stdin);
        scanf("%s", institu_name);
        getchar();
        if (!judge_inst_exit(institu_name)) {
            printf("\n\n�������ѧԺ�����ڣ��Ƿ�������루n/y��");
            char a;
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    return;
                if (a == 'y')
                    goto loop1;
            }
        }
        printf("\n������Ҫɾ��רҵ���ƣ�");
        fflush(stdin);
        scanf("%s", major_name);
        if (judge_major_exit(major_name, institu_name) == -1) {
            printf("\n\n�������רҵ�����ڣ��Ƿ�������루n/y��");
            char a;
            while (1) {
                fflush(stdin);
                a = getch();
                if (a == 'n')
                    return;
                if (a == 'y')
                    goto loop1;
            }
        }
        FILE *fp;
        if ((fp=fopen("institute.txt", "rb")) == NULL) {
            printf("ϵͳ����ɾ��ʧ�ܣ�\n");
            goto loop;
        }
        struct Institute tmpt;
        list<struct Institute> institu;
        while (1) {
            fread(&tmpt, sizeof(struct Institute), 1, fp);
            if (feof(fp))
                break;
            institu.push_back(tmpt);
        }
        fclose(fp);
        if ((fp=fopen("institute.txt", "wb")) == NULL) {
            printf("ϵͳ����ɾ��ʧ�ܣ�\n");
            fclose(fp);
            goto loop;
        }
        while (1) {
            if (institu.empty())
                break;
            struct Institute *pointer = &institu.front();
            strcpy(tmpt.name, pointer->name);
            int sign = 0;
            for (i=0; i<pointer->num; i++) {
                if (strcmp(major_name, pointer->major[i]) == 0) {
                    strcpy(tmpt.major[i], pointer->major[pointer->num-1]);
                    sign = 1;
                    pointer->num--;
                } else
                    strcpy(tmpt.major[i], pointer->major[i]);
                if (sign == 1) {
                    tmpt.class_num[i] = pointer->class_num[pointer->num];
                } else
                    tmpt.class_num[i] = pointer->class_num[i];
            }
            tmpt.num = pointer->num;
            if (fwrite(&tmpt, sizeof(struct Institute), 1, fp) != 1) {
                printf("ϵͳ����ɾ��ʧ�ܣ�\n");
                fclose(fp);
                goto loop;
            }
            institu.pop_front();
        }
        printf("\n\n\t\t\t\t\t\tɾ���ɹ�!\n");
        clock_t delay = 2*CLOCKS_PER_SEC;
        clock_t start = clock();
        while (clock()-start < delay);
        fclose(fp);
    }
}
int  print_major() {
    FILE *fp;
    if ((fp=fopen("institute.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return -1;
    }
    struct Institute tmpt;
    int i = 0, j, num = 0;
    printf("\t����ѧԺ:\t���\tѧԺ��\n");
    while (1) {
        fread(&tmpt, sizeof(struct Institute), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        printf("\t\t\t%d\t%s\n", ++i, tmpt.name);
        if (tmpt.num != 0) {
            num+=tmpt.num;
            for (j=1; j<=tmpt.num; j++)
                printf("\t\t\t\t   %d)\t%s\n", j, tmpt.major[j-1]);
        }
    }
    return num;
}
int  get_major_size() {
     FILE *fp;
    if ((fp=fopen("institute.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return 0;
    }
    struct Institute tmpt;
    int num = 0;
    while (1) {
        fread(&tmpt, sizeof(struct Institute), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        if (tmpt.num != 0)
            num+=tmpt.num;
    }
    return num;
}
int  get_class_size(char *name, char *name1) {
    FILE *fp;
    if ((fp=fopen("institute.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return 0;
    }
    struct Institute tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Institute), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return 0;
        }
        int i;
        if (strcmp(tmpt.name, name1) == 0) {
            for (i=0; i<tmpt.num; i++) {
                if (strcmp(tmpt.major[i], name) == 0) {
                    fclose(fp);
                    return tmpt.class_num[i];
                }
            }
            return 0;
        }
    }
}
void server_regist() {
    if (get_server_num()>=MS_MaxSize) {
        cout << "����Ա�����ﵽ���ޣ�����ע�ᣡ" << endl;
        limit_time(2);
		return;
    }
	srand(time(NULL));
	char a[AS_MaxSize], b[NP_MaxSize], rb[NP_MaxSize];
	int i;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
loop:for (i=0; i<AS_MaxSize-1; i++)
        a[i] = (char)(rand()%9+49);
    a[AS_MaxSize-1] = '\0';
    if (judge_account_exit(a) || judge_a_eixt(a) || (strcmp(a, "88888") == 0))
        goto loop;
    system("cls");
    for (i=3; i<=16; i++) {
        gotoxy(hOut, 20, i);
        if (i == 3 || i == 16)
            cout << "** * * * * * * * * * * * * * **";
        else
            cout << "*                             *";
    }
    gotoxy(hOut, 32, 5);
    printf("����Աע��");
    gotoxy(hOut, 26, 8);
    printf("�˺ţ�");
    gotoxy(hOut, 26, 10);
    printf("���룺");
    gotoxy(hOut, 22, 12);
    printf("����ȷ�ϣ�");
    gotoxy(hOut, 32, 8);
    printf("%s", a);
    gotoxy(hOut, 32, 10);
    fflush(stdin);
    scanf("%s", b);
    gotoxy(hOut, 32, 12);
    fflush(stdin);
    scanf("%s", rb);
    gotoxy(hOut, 49, 19);
    printf("ע����.....");
    limit_time(2);
    if (strcmp(b, rb) != 0) {
        gotoxy(hOut, 44, 19);
        printf("�����������벻ͬ��ע��ʧ�ܣ�");
        limit_time(2);
        return;
    }
    struct Server tmpt;
    strcpy(tmpt.account, a);
    strcpy(tmpt.passwords, b);
    FILE *fp;
    if ((fp=fopen("server.txt", "ab")) == NULL) {
    loop1:printf("ϵͳ����!\n");
        limit_time(2);
        return;
    }
    if (fwrite(&tmpt, sizeof(struct Server), 1, fp) != 1)
        goto loop1;
    gotoxy(hOut, 49, 19);
    printf("                        ");
    gotoxy(hOut, 49, 19);
    printf("ע��ɹ���");
    limit_time(1);
    fclose(fp);
    return;
}
int  get_server_num() {
    FILE *fp;
    if ((fp=fopen("server.txt", "rb")) == NULL) {
        printf("ϵͳ����!\n");
        system("pause");
        return 0;
    }
    struct Server tmpt;
    int num = 0;
    while (1) {
        fread(&tmpt, sizeof(struct Server), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        num++;
    }
    return num;
}
bool judge_a_eixt(char *a) {
    FILE *fp;
    if ((fp=fopen("server.txt", "rb")) == 0) {
        printf("ϵͳ����!\n");
        limit_time(2);
        return false;
    }
    struct Server tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Server), 1, fp);
        if (feof(fp))
            break;
        if (strcmp(tmpt.account, a) == 0) {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}
void do_server() {
    int i;
loop:system("cls");
    printf("\t\t    ************��ӭ����Ա�ʻ�����**********\n\n\n\n\t");
    for (i=0; i<60; i++)
        printf("-");
    printf("\n\t1.�鿴\t\t2.ע��\t\t3.ע��\t\t0.�˳�\n\t");
    for (i=0; i<60; i++)
        printf("-");
    FILE *fp;
    if ((fp=fopen("server.txt", "rb")) == 0) {
        printf("ϵͳ����!\n");
        limit_time(2);
        return;
    }
    fflush(stdin);
    char c = getch();
    struct Server tmpt;
    i=0;
    switch(c) {
    case '1': {
        system("cls");
        while (1) {
            fread(&tmpt, sizeof(struct Server), 1, fp);
            if (feof(fp)) {
                fclose(fp);
                break;
            }
            if (i == 0) {
                i++;
                continue;
            }
            printf("\n\t\t%d:\t\t\t\t%s\n", i++, tmpt.account);
        }
        printf("\n\n\t\t\t\t\t\t");
        system("pause");
        goto loop;
    }
    case '2': {
        system("cls");
        printf("\n\t������Ҫɾ�����˺ţ�");
        list<struct Server> server_list;
        char a[AS_MaxSize];
        scanf("%s", a);
        if (strcmp(a, "88888") == 0) {
            printf("\n\n\t\t\t\t\t\tû���ҵ����˺ţ�");
            limit_time(2);
            goto loop;
        }
        int sign = 0;
        while (1) {
            fread(&tmpt, sizeof(struct Server), 1, fp);
            if (feof(fp)) {
                fclose(fp);
                break;
            }
            if (strcmp(a, tmpt.account) == 0) {
                sign = 1;
                continue;
            }
            server_list.push_back(tmpt);
        }
        if (sign == 0) {
            printf("û���ҵ����û���");
            limit_time(2);
            goto loop;
        }
        if ((fp=fopen("server.txt", "wb")) == 0) {
            printf("ϵͳ����!\n");
            limit_time(2);
            return;
        }
        while(1) {
            if (server_list.empty()) {
                fclose(fp);
                break;
            }
            if (fwrite(&server_list.front(), sizeof(struct Server), 1, fp) != 1) {
                printf("ϵͳ����!\n");
                limit_time(2);
                return;
            }
            server_list.pop_front();
        }
        printf("\n\n\t\t\t\t\t\t\tɾ���ɹ���");
        limit_time(2);
        goto loop;
    }
    case '3':
        server_regist();
        goto loop;
    case '0':
        return;
    default:
        goto loop;
    }
}

///                       <5>.���԰幦�ܺ���
void mess_note(char ns[]) {
    int j;
loop:system("cls");
	printf("\t\t     *************��ӭ����***********   \n\n\n\t");
    for (j=0; j<60; j++)
        printf("-");
    printf("\n");
	int num = prin_mess();
	printf("\n\t");
	for (j=0; j<60; j++)
        printf("-");
	printf("\n\n\t\t1.����\t\t2.�ظ�\t\t0.�˳�\n\t");
	fflush(stdin);
	for (j=0; j<60; j++)
        printf("-");
    printf("\n");
	char choice = getch();
	char mess[Talk_MaxSize];
	switch(choice) {
	case '1': {
	    system("cls");
        printf("\t\t\t\t��ӭ����\n\n\n");
		printf("�����ԣ�");
		scanf("%s", mess);
		int n;
		n = add_mess(mess, ns, 0);
		if (n == -1) {
			printf("ϵͳ��������ʧ�ܣ�\n");
			limit_time(2);
		}
		goto loop;
	}
	case '2': {
		if (num == 0) {
            system("cls");
            printf("\t\t     *************��ӭ����***********   \n\n\n\t");
            for (j=0; j<60; j++)
                printf("-");
            printf("\n");
            int num = prin_mess();
            printf("\t\t\t\t����Ϊ�գ�\n\t");
            fflush(stdin);
            for (j=0; j<60; j++)
                printf("-");
			limit_time(2);
			goto loop;
		}
		printf("������Ҫ�ظ�����ţ�");
		int a;
		fflush(stdin);
		scanf("%d", &a);
		if (a>num || a<0) {
			printf("��������");
			limit_time(2);
			goto loop;
		}
		printf("������ظ���Ϣ��");
		fflush(stdin);
		scanf("%s", mess);
		add_mess(mess, ns, a);
		goto loop;
	}
	case '0':
		return;
	default:
		goto loop;
	}
}
int prin_mess() {
	FILE *fp;
	if ((fp=fopen("tmpt_mess.txt", "rb")) == NULL)
		return -1;
	map<string, string> leave_mess;
	char name[NP_MaxSize], mess[Talk_MaxSize];
	int i = 0;
	while (1) {
		fread(name, sizeof(name), 1, fp);
		fread(mess, sizeof(mess), 1, fp);
		if (feof(fp))
			return i;
        printf("\t\t(%d) %s:\t\t%s\n", ++i, name, mess);
	}
}
int add_mess(char* mess, char* name, int j) {
    char m[Talk_MaxSize], n[NP_MaxSize];
    strcpy(m, mess);
    strcpy(n, name);
	FILE *fp;
	if (j == 0) {
		if ((fp=fopen("tmpt_mess.txt", "ab")) == NULL)
			return -1;
		if (fwrite(n, sizeof(n), 1, fp) != 1) {
			fclose(fp);
			return -1;
		}
		if (fwrite(m, sizeof(m), 1, fp) != 1) {
			fclose(fp);
			return -1;
		}
		fclose(fp);
		return 1;
	} else {
	    list<string>a;
	    list<string>b;
	    char ns[NP_MaxSize], ms[Talk_MaxSize];
		int i = 1;
		if ((fp=fopen("tmpt_mess.txt", "rb")) == NULL)
			return -1;
		while (1) {
			fread(ns, sizeof(ns), 1, fp);
			fread(ms, sizeof(ms), 1, fp);
			if (feof(fp))
				break;
            a.push_back(string(ns));
            b.push_back(string(ms));
			if (i == j) {
                a.push_back(string(n));
                b.push_back(string(m));
            }
			i++;
		}
		fclose(fp);
		if ((fp=fopen("tmpt_mess.txt", "wb")) == NULL)
			return -1;
		while (1) {
            if (a.empty())
                break;
            if (fwrite(a.front().c_str(), sizeof(ns), 1, fp) != 1) {
                fclose(fp);
                return -1;
            }
            if (fwrite(b.front().c_str(), sizeof(ms), 1, fp) != 1) {
                fclose(fp);
                return -1;
            }
            a.pop_front();
            b.pop_front();
		}
		fclose(fp);
		return 1;
	}
}

///                             ѧ���������б�
void client_menue(char ns[], char as[]) {
    while (1) {
        system("cls");
        int j;
        printf("\t\t     *************��ӭʹ***********   \n\n\n\t");
        for (j=0; j<60; j++)
            printf("-");
        printf("\n\t");
		printf("\t1.ͼ�����\t2.ͼ������\t3.ͼ��黹\n\t\t4.�鿴ͼ��\t5.ͼ��ͳ��\t");
		printf("6.����ͼ��\n\t\t7.���԰�\t8.�޸�����\t9.�鿴������Ϣ\n\t\t0.�˳�\n\t");

		fflush(stdin);
		for (j=0; j<60; j++)
            printf("-");
        printf("\n\n\n��ѡ��");
		char choice = getch();
		switch(choice) {
		case '1':
			lent_book(as);
			break;
		case '2':
            relent_book(as);
			break;
		case '3':
		    return_book(as);
			break;
		case '4':
		    print_book();
			break;
        case '5':
            count_book();
            break;
        case '6':
            find_book();
            break;
        case '7':
            mess_note(ns);
            break;
        case '8':
            change_passwords(as);
            break;
		case '9':
		    look_owe_ifor(as);
			break;
        case '0':
            return;
		default:
			break;
		}
	}
}

///                         ����ͼ��Ĺ��ܺ���, ���԰幦��ͬ��
void lent_book(char as[]) {
    int i;
loop:system("cls");
    printf("\t\t    ************��ӭͼ�����**********\n\n\t");
    for (i=0; i<60; i++)
        printf("-");
    printf("\n");
    char book_name[NP_MaxSize];
    printf("\n\t������Ҫ��ͼ������֣�");
    fflush(stdin);
    scanf("%s", book_name);
    char book_num[AS_MaxSize], user_name[NP_MaxSize];
    int t=0, num = judge_book_exit(book_name, book_num);
    if (num == -1) {
    loop2: printf("ϵͳ����");
        limit_time(2);
        return;
    }
    if (num == 2) {
        printf("�����û�и��飬�Ƿ��������n/y��");
       loop1: while (1) {
            fflush(stdin);
            char a = getch();
            if (a == 'n')
                return;
            if (a == 'y')
                goto loop;
        }
    }
    if (strcmp(book_num, "") == 0) {
        printf("�����ѱ����꣬���Ժ��ٽ裬�Ƿ��������n/y��");
        goto loop1;
    }

    FILE *fp;
    struct Client user;
    if ((fp=fopen("client.txt", "rb")) == NULL)
        goto loop2;
    while (1) {
        fread(&user, sizeof(struct Client), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        if (strcmp(as, user.account) == 0) {
            strcpy(user_name, user.name);
            fclose(fp);
            break;
        }
    }
    struct LendBook tmpt;
    strcpy(tmpt.name, book_name);
    strcpy(tmpt.user_account, as);
    strcpy(tmpt.book_num, book_num);
    strcpy(tmpt.user_name, user.name);
    long a;
	struct tm b;
	time(&a);
	b=*(localtime(&a));
	tmpt.begin_.year = b.tm_year+1900;
	tmpt.begin_.month = b.tm_mon+1;
	tmpt.begin_.day = b.tm_mday;
    if ((fp=fopen("lent_book.txt", "ab")) == NULL)
        goto loop2;
    if (fwrite(&tmpt, sizeof(struct LendBook), 1, fp) != 1) {
        fclose(fp);
        goto loop2;
    }
    fclose(fp);
    printf("\n\n\t\t\t\t\t\t\t\t���ĳɹ���");
    limit_time(3);
}
int judge_book_exit(char* name, char* book_num) {
    FILE *fp;
    struct Book tmpt;
    list<string> a;
    list<string> b;
    int sign = 0, count_num = 0, num = 0;
    if ((fp=fopen("library.txt", "rb")) == NULL)
        return -1;
    while (1) {
        fread(&tmpt, sizeof(struct Book), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        if (strcmp(tmpt.name, name) == 0) {
            num = atoi(tmpt.num);
            sign = 1;
            a.push_back(string(tmpt.book_num));
        }
    }
    if (sign == 0)
        return 2;
    int i;
    fclose(fp);
    struct LendBook lent_book;
    if ((fp=fopen("lent_book.txt", "rb")) == NULL)
        return -1;
    while (1) {
        fread(&lent_book, sizeof(struct LendBook), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            break;
        }
        if (strcmp(lent_book.name, name) == 0) {
            count_num++;
            b.push_back(string(lent_book.book_num));
        }
    }
    num-=count_num;
    if (num>0) {
        while (1) {
        loop3:if (a.empty())
                break;
            int i;
            list<string>::iterator p = b.begin();
            for (p = b.begin(); p!=b.end(); p++) {
                if (strcmp(a.front().c_str(), p->c_str()) == 0) {
                    a.pop_front();
                    goto loop3;
                }
            }
            strcpy(book_num, a.front().c_str());
            break;
        }
    } else
        strcpy(book_num, "");
    return 1;
}
void relent_book(char as[]) {
loop1:system("cls");
	printf("\t\t\t  ��ӭͼ������\n\n");
	char book_num[AS_MaxSize];
	fflush(stdin);
	int num = print_lent_book(as);
	if (num ==-1) {
		printf("ϵͳ��������ʧ�ܣ�\n");
		limit_time(2);
		return;
	}
	if (num == 0) {
		printf("\n\n����δ�����κ�ͼ�飡");
		limit_time(2);
		return;
	}
	printf("\n\n��������Ҫ����ͼ��ı�ţ�");
	scanf("%s", book_num);

	FILE *fp;
	if ((fp=fopen("lent_book.txt", "rb")) == NULL) {
		printf("ϵͳ��������ʧ�ܣ�\n");
		limit_time(2);
		return;
	}
	struct LendBook tmpt;
	list<struct LendBook> lent_book;
	list<struct LendBook> lent;
	int sign = 0;
	while (1) {
		fread(&tmpt, sizeof(struct LendBook), 1, fp);
		if (feof(fp))
			break;
		if (strcmp(book_num, tmpt.book_num) == 0) {
            sign = 1;
            int time = calculate_time(&tmpt.begin_);
			if (time>Bb_MaxSize) {
				printf("�����Ѿ����ڣ����ܱ����裡");
				limit_time(2);
				fclose(fp);
				return;
			}
			if (time>3) {
                printf("���黹���Խ��Ķ��죬�������裡");
                limit_time(2);
                fclose(fp);
                return;
			}
			add_time(&tmpt.begin_);
		}
		lent_book.push_back(tmpt);
		lent.push_back(tmpt);
	}
	fclose(fp);
	if (sign == 0) {
        printf("��û�н��ĸ��飡");
        limit_time(2);
        return;
	}
	if ((fp=fopen("lent_book.txt", "wb")) == NULL) {
		printf("ϵͳ��������ʧ�ܣ�\n");
		limit_time(2);
		return;
	}
    while(1) {
		if (lent_book.empty())
			break;
		if (fwrite(&lent_book.front(), sizeof(struct LendBook), 1, fp) != 1) {
			printf("ϵͳ�������ڳ�����һ�����裬���Ե�....\n");
			limit_time(2);
			while (1) {
                if (lent.empty()) {
                    fclose(fp);
                    printf("\t\t\t\t����ɹ���");
                    limit_time(2);
                }
                break;
                if (fwrite(&lent_book.front(), sizeof(struct LendBook), 1, fp) != 1) {
                    printf("����ʧ�ܣ��������Ͽ����Ѷ�ʧ��");
                    system("pause");
                    fclose(fp);
                    return;
                }
                lent.pop_back();
			}
		}
		lent_book.pop_back();
	}
	fclose(fp);
	printf("\n\n\t\t\t\t\t\t����ɹ���");
	limit_time(2);
}
int print_lent_book(char *account) {
	FILE *fp;
	if ((fp=fopen("lent_book.txt", "rb")) == NULL)
		return -1;
	struct LendBook tmpt;
	int num = 0;
	while (1) {
		fread(&tmpt, sizeof(struct LendBook), 1, fp);
		if (feof(fp))
			return num;
		if (strcmp(account, tmpt.user_account) == 0) {
			printf("\t\t%s:\t\t%s\n", tmpt.book_num, tmpt.name);
			num++;
		}
	}
}
void add_time(struct Date* p) {
	p->day +=Bb_MaxSize;
	if (p->day>=30) {
		p->day %= 30;
		p->month += 1;
	}
	if (p->month>=12) {
		p->month %= 12;
		p->year += 1;
	}
}
int calculate_time(struct Date* _begin) {
	struct Date _end;
	long a;
	struct tm b;
	time(&a);
	b=*(localtime(&a));
	_end.year = b.tm_year+1900;
	_end.month = b.tm_mon+1;
	_end.day = b.tm_mday;
	int num = _end.day-_begin->day+(_end.month-_begin->month)*30+(_end.year-_begin->year)*365;
	num-=Bb_MaxSize;
	return num>0? num:0;
}
void return_book(char as[]) {
loop1:system("cls");
	printf("\t\t\t  ��ӭͼ��黹\n\n\t");
	char book_num[AS_MaxSize];
	fflush(stdin);
	int num = print_lent_book(as);
	if (num ==-1) {
		printf("ϵͳ���󣡹黹ʧ�ܣ�\n");
		limit_time(2);
		return;
	}
	if (num = 0) {
		printf("\n\n����δ��Լ�κ�ͼ�飡");
		limit_time(2);
		return;
	}
	printf("\n\n\t��������Ҫѧ�黹ͼ��ı�ţ�");
	scanf("%s", book_num);
	FILE *fp;
	if ((fp=fopen("lent_book.txt", "rb")) == NULL) {
		printf("ϵͳ���󣡹黹ʧ�ܣ�\n");
		limit_time(2);
		return;
	}
	struct LendBook tmpt;
	list<struct LendBook> lentbook;
	list<struct LendBook> lent;
	int sign = 0;
	while (1) {
		fread(&tmpt, sizeof(struct LendBook), 1, fp);
		if (feof(fp))
			break;
		if (strcmp(book_num, tmpt.book_num) == NULL) {
            sign = 1;
			int day = calculate_time(&tmpt.begin_);
			if (day>Bb_MaxSize) {
				printf("�����Ѿ����� %d �죡", day-Bb_MaxSize);
				system("pause");
				continue;
			}
			continue;
		}
		lentbook.push_back(tmpt);
		lent.push_back(tmpt);
	}
	fclose(fp);
	if (sign == 0) {
        printf("\n\n\t\t\t\t��û�н��ĸ��飡");
        limit_time(2);
        return;
	}
	if ((fp=fopen("lent_book.txt", "wb")) == NULL) {
		printf("ϵͳ���󣡹黹ʧ�ܣ�\n");
		limit_time(2);
		return;
	}
    while(1) {
		if (lentbook.empty())
			break;
		if (fwrite(&lentbook.front(), sizeof(struct LendBook), 1, fp) != 1) {
			printf("ϵͳ�������ڳ�����һ�����裬���Ե�....\n");
			limit_time(2);
			fclose(fp);
			if ((fp=fopen("lent_book.txt", "wb")) == NULL) {
                printf("ϵͳ���󣡳���ʧ�ܣ�\n");
                limit_time(2);
                return;
            }
			while (1) {
                if (lent.empty()) {
                    fclose(fp);
                    printf("\n\n\t\t\t\t\t\t\t�黹�ɹ���");
                    limit_time(2);
                }
                break;
                if (fwrite(&lentbook.front(), sizeof(struct LendBook), 1, fp) != 1) {
                    printf("����ʧ�ܣ��黹���Ͽ����Ѷ�ʧ��");
                    system("pause");
                    fclose(fp);
                    return;
                }
                lent.pop_front();
			}
		}
		lentbook.pop_front();
	}
	fclose(fp);
	printf("\n\n\t\t\t\t\t\t\t�黹�ɹ���");
	limit_time(2);
}
void change_passwords(char as[]) {
    while (1) {
        int i;
 loop:  system("cls");
        printf("\t\t    ************��ӭ�޸�����**********\n\n\t");
        for (i=0; i<60; i++)
            printf("-");
        printf("\n\n\t����������룺");
        char pass[NP_MaxSize];
        fflush(stdin);
        scanf("%s", pass);
        FILE *fp;
        if ((fp=fopen("client.txt", "rb")) == 0) {
            printf("ϵͳ����!\n");
            system("pause");
            goto loop;
        }
        struct Client tmpt;
        while (1) {
            fread(&tmpt, sizeof(struct Client), 1, fp);
            if (feof(fp)) {
                fclose(fp);
                break;
            }
            if (strcmp(tmpt.account, as) == 0) {
                if (strcmp(tmpt.passwords, pass) == 0) {
                    fclose(fp);
                    break;
                } else {
                    printf("������������޸Ĵ���");
                    limit_time(2);
                    fclose(fp);
                    return;
                }
            }
        }
        char a[NP_MaxSize], ra[NP_MaxSize];
        printf("\t�����������룺");
        scanf("%s", a);
        printf("\t��ȷ�������룺");
        scanf("%s", ra);
        if (strcmp(a, ra) != 0) {
            printf("�����������벻ͬ���޸�ʧ�ܣ�");
            limit_time(2);
            break;
        }

        list<struct Client> client_list;
        if ((fp=fopen("client.txt", "rb")) == 0) {
            printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
            limit_time(2);
            goto loop;
        }
        while (1) {
            fread(&tmpt, sizeof(struct Client), 1, fp);
            if (feof(fp))
                break;
            if (strcmp(tmpt.account, as) == 0)
                strcpy(tmpt.passwords, a);
            client_list.push_back(tmpt);
        }
        fclose(fp);
        if ((fp=fopen("client.txt", "wb")) == NULL) {
            printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
            limit_time(2);
            goto loop;
        }
        while (1) {
            if (client_list.size() == 0)
                break;
            if (fwrite(&client_list.front(), sizeof(struct Client), 1, fp) != 1) {
                printf("ϵͳ����!ɾ��ʧ�ܣ�\n");
                limit_time(2);
                fclose(fp);
                goto loop;
            }
            client_list.pop_front();
        }
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t�޸ĳɹ�!\n");
        limit_time(2);
        return;

    }
}
void look_owe_ifor(char *as) {
    system("cls");
    printf("\t\t    ************��ӭ�鿴������Ϣ**********\n\n");
    FILE *fp;
    if ((fp=fopen("client.txt", "rb")) == NULL)
        return;
    struct Client tmpt;
    while (1) {
        fread(&tmpt, sizeof(struct Client), 1, fp);
        if (feof(fp)) {
            fclose(fp);
            return;
        }
        if (strcmp(as, tmpt.account) == 0) {
            printf("\t\t\t�˺ţ�  %s\n", tmpt.account);
            printf("\t\t\tѧ�ţ�  %s\n", tmpt.sid);
            printf("\t\t\t���֣�  %s\n", tmpt.name);
            printf("\t\t\tѧԺ��  %s\n", tmpt.inform.institu_name);
            printf("\t\t\t�꼶��  %d\n", tmpt.inform.grade);
            printf("\t\t\t�༶��  %d\n", tmpt.inform.class_);
            system("pause");
            fclose(fp);
            return;
        }
    }
}


