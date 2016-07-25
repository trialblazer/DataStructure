#include "Maze.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <list>
#include <stdio.h>


using namespace std;

Maze::Maze() {
    FILE *fp;
	if ((fp = fopen("a.txt", "rb")) == NULL) {
		fp = fopen("a.txt", "wb");
		exit1 = 14, exit2 = 14, entrance1 = 0, entrance2 = 0;
        difficulty = 1;
        mode = 1;
        mapsize = 15;
        count = 0;
        for (int i=0; i<2; i++)
            for (int j=0; j<3; j++) {
                record[i][j].x = 0;
                record[i][j].y = 0;
            }
        print_role(true);
	} else {
	    int temp[20];
        for (int i=0; i<20; i++)
            fread(&temp[i], sizeof(int), 1, fp);
        exit1 = temp[0], exit2 = temp[1], entrance1 = temp[2], entrance2 = temp[3];
        difficulty = temp[4], mode = temp[5], mapsize = temp[6], count = temp[7];
        int t = 8;
        for (int i=0; i<2; i++) {
            for (int j=0; j<3; j++) {
                record[i][j].x = temp[t++];
                record[i][j].y = temp[t++];
            }
        }
        fclose(fp);
	}
	if ((fp = fopen("b.txt", "rb")) == NULL) {
		fp = fopen("b.txt", "wb");
	}
	fclose(fp);
    for (int i=0; i<MaxSize; i++)
		for (int j=0; j<MaxSize; j++)
			graph1[i][j] = false;
    srand(time(NULL));
}
Maze::~Maze() {
    int temp[20];
    temp[0] = exit1, temp[1]=exit2, temp[2]=entrance1, temp[3] = entrance2;
    temp[4] = difficulty, temp[5] = mode, temp[6] = mapsize, temp[7] = count;
    int t = 8;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            temp[t++] = record[i][j].x;
            temp[t++] = record[i][j].y;
        }
    }
    FILE* fp;
	if ((fp = fopen("a.txt", "wb")) == NULL) {
		cout << "�ļ�����ʧ�ܣ�" << endl;
		getch();
		fclose(fp);
		exit(1);
	}
	for (int i=0; i<20; i++) {
		if (fwrite(&temp[i], sizeof(int), 1, fp) != 1) {
			cout << "�ļ�����ʧ�ܣ�" << endl;
			getch();
			fclose(fp);
			exit(1);
		}
	}
	fclose(fp);
}

void Maze::gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}


void Maze::head() {
    system("cls");
	int i;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, 7, 1);
	for (i=0; i<30; i++)
		cout << "*";
	cout << " " << (char)2 << " ";
	gotoxy(h, 40, 1);
	for (i=0; i<30; i++)
		cout << "*";
	gotoxy(h, 31, 3);
	cout << "Welcom Play Maze" << endl;
}
void Maze::printmap2() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j;
	gotoxy(h, 0, 6);
	for (j=0; j<mapsize; j++)
		cout << "__";
	for (i=0; i<mapsize; i++) {
		gotoxy(h, 0, 7+i);
		cout << "|";
		for (int j=0; j<mapsize; j++) {
			if (graph1[i][j] == false) {
				if (j == mapsize-1)
					cout << (char)2;
				else
					cout << (char)2 << " ";
			} else
				if (j == mapsize-1)
					cout << " ";
				else
					cout << "  ";
		}
		cout << "|";
	}
	gotoxy(h, 0, 7+i);
	for (j=0; j<mapsize; j++)
		cout << "--";


	gotoxy(h, mapsize+22, 6);
	for (j=0; j<mapsize; j++)
		cout << "__";
	for (i=0; i<mapsize; i++) {
		gotoxy(h, mapsize+22, 7+i);
		cout << "|";
		for (int j=0; j<mapsize; j++) {
			if (graph2[i][j] == false) {
				if (j == mapsize-1)
					cout << (char)2;
				else
					cout << (char)2 << " ";
			} else
				if (j == mapsize-1)
					cout << " ";
				else
					cout << "  ";
		}
		cout << "|";
	}
	gotoxy(h, mapsize+22, 7+i);
	for (j=0; j<mapsize; j++)
		cout << "--";
	cout << endl << endl;
}
void Maze::printmap1() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int t = difficulty==1? 23:(difficulty==2? 20:11);
    int i, j;
	gotoxy(h, t, 6);
	for (j=0; j<mapsize; j++)
		cout << "__";
	for (i=0; i<mapsize; i++) {
		gotoxy(h, t, 7+i);
		cout << "|";
		for (int j=0; j<mapsize; j++) {
			if (graph1[i][j] == false) {
				if (j == mapsize-1)
					cout << (char)2;
				else
					cout << (char)2 << " ";
			} else
				if (j == mapsize-1)
					cout << " ";
				else
					cout << "  ";
		}
		cout << "|";
	}
	gotoxy(h, t, 7+i);
	for (j=0; j<mapsize; j++)
		cout << "--";
	cout << endl;
}
void Maze::print_record() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    head();
    gotoxy(h, 20, 6);
    for (int i=0; i<40; i++)
        cout << "*";
    gotoxy(h, 20, 8);
    cout << "����ģʽ��";
    gotoxy(h, 23, 9);
    cout << "���ּ���";
    if (record[0][0].x == 0 && record[0][0].y == 0)
        cout << "̫��ϧ�ˣ���ʱû����߼�¼��";
    else
        cout << record[0][0].x << ":" << record[0][0].y;
    gotoxy(h, 23, 10);
    cout << "רҵ����";
    if (record[0][1].x == 0 && record[0][1].y == 0)
        cout << "̫��ϧ�ˣ���ʱû����߼�¼��";
    else
        cout << record[0][1].x << ":" << record[0][1].y;
    gotoxy(h, 23, 11);
    cout << "��ʦ����";
    if (record[0][2].x == 0 && record[0][2].y == 0)
        cout << "̫��ϧ�ˣ���ʱû����߼�¼��";
    else
        cout << record[0][2].x << ":" << record[0][2].y;

    gotoxy(h, 20, 13);
    cout << "��սģʽ��";
    gotoxy(h, 23, 14);
    cout << "���ּ���";
    if (record[1][0].x == 0 && record[1][0].y == 0)
        cout << "̫��ϧ�ˣ���ʱû����߼�¼��";
    else
        cout << record[1][0].x << ":" << record[1][0].y;
    gotoxy(h, 23, 15);
    cout << "רҵ����";
    if (record[1][1].x == 0 && record[1][1].y == 0)
        cout << "̫��ϧ�ˣ���ʱû����߼�¼��";
    else
        cout << record[1][1].x << ":" << record[1][1].y;
    gotoxy(h, 23, 15);
        for (int i=0; i<40; i++)
            cout << "*";
    getch();
}
void Maze::print_role(bool s) {
    head();
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    gotoxy(h, 7, 1);
    for (i=0; i<30; i++)
    cout << "*";
    cout << " " << (char)2 << " ";
    gotoxy(h, 40, 1);
    for (i=0; i<30; i++)
        cout << "*";
    gotoxy(h, 31, 3);
    cout << "Welcom Play Maze" << endl;
    gotoxy(h, 6, 6);
    cout << " ��Ϸ����";
    gotoxy(h, 11, 7);
    cout << "1.����Ϸ��Ϊ����ģʽ������ģʽ����սģʽ���Զ���ģʽ��";
    if (s) getch();
    gotoxy(h, 11, 8);
    cout << "2.ÿ��ģʽ�ַ������ȼ������ּ���ר�Ҽ��𣬴�ʦ����";
    if (s) getch();
    gotoxy(h, 11, 9);
    cout << "3.����սģʽ���ɼ�����������սͬһ��ͼ��������ɵĻ�ʤ,(��ʦ����֧";
    gotoxy(h, 13, 10);
    cout << "����һģʽ)";
    if (s) getch();
    gotoxy(h, 11, 11);
    cout << "4.���Զ���ģʽ��������Լ���������ͼ����ɺ��ѡ������������ս��";
    if (s) getch();
    gotoxy(h, 11, 12);
    cout << "5.����սģʽ�⣬�����ս����ѡ��浵���������ͼ�͸õ�ͼ�����·����";
    if (s) getch();
    gotoxy(h, 11, 13);
    cout << "6.��Ҳ���������˵��в鿴��߼�¼����ʷ��¼��";
    if (s)  {
        gotoxy(h, 20, 15);
        getch();
        cout << "��ϲ�㣬���������Ϸ����ѧϰ���Ͻ�ȥս���ɣ�";
    }
    getch();
}
void Maze::print_history() {
    head();
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << endl << "��ʷ��¼��" << endl;
    int size, tmpt, t1 = 0;
    FILE *fp;
    if ((fp = fopen("b.txt", "rb")) == NULL) {
		cout << "�ļ���ʧ�ܣ�" << endl;
	}
	int p = 0;
	while (1) {
        fread(&size, sizeof(int), 1, fp);
        if (feof(fp))
            break;
        int t = size==15? 23:(difficulty==19? 20:11);
        gotoxy(h, t, 6+p);
        for (int i=0; i<size; i++)
            cout << "__";
        int j;
        for (j=0; j<size; j++) {
            gotoxy(h, t, 7+j+p);
            cout << "|";
            for (int i=0; i<size; i++) {
                fread(&tmpt, sizeof(int), 1, fp);
                if (tmpt == 0) {
                    if (i == size-1)
                        cout << (char)2;
                    else
                        cout << (char)2 << " ";
                } else
                    if (i == size-1)
                        cout << " ";
                    else
                        cout << "  ";
            }
            cout << "|";
        }
        gotoxy(h, t, 7+j+p);
        for (j=0; j<size; j++)
            cout << "--";
        cout << endl;
        t1++;
        cout << "��Ϊ��";
        int x, y;
        while (1) {
            fread(&x, sizeof(int), 1, fp);
            fread(&y, sizeof(int), 1, fp);
            if (x == size-1 && y == size-1)
                break;
            cout << "<" << x << "," << y << "> ";
        }
        p+=30;
        cout << "<" << size-1 << "," << size-1 << "> " << endl;
	}
	if (t1 == 0)
        cout << "\t\t��ʱû�м�¼���Ͻ�ȥս���ɣ�" << endl;
	getch();
	fclose(fp);
}


bool Maze::walk(int x, int y) {
	if (x<0 || x>=mapsize || y<0 || y>=mapsize)
		return false;
	if (graph1[x][y] == false)
		return false;
	return true;
}

 void Maze::reset(int &x, int &y) {
    static int t;
	int temp = rand()/3*count%4;
	if (t == temp)
		temp = temp*23%4;
	t = temp;
	int rtemp = temp;
	int m = x, n = y;
	bool sign = false;
   	while (1) {
		if (m>=0 && m<mapsize && n>=0 && n<mapsize && graph1[m][n] == false) {
			x = m;
			y = n;
			break;
		}
		m = x+offset[temp][0];
		n = y+offset[temp][1];
		if (temp == rtemp && sign)
			break;
		sign = true;
		temp++;
		temp %= 4;
	}
}

void Maze::maprand(int x, int y) {
    graph1[x][y] = true;
	count++;
	int m = x, n = y;
	reset(x, y);
	if (m != x || n != y) {
        graph1[(x+m)/2][(y+n)/2] = true;
		maprand(x, y);
    } else {
		while (count < (mapsize/2+1)*(mapsize/2+1)) {
			for (int i=0; i<mapsize; i+=2) {
				for (int j=0; j<mapsize; j+=2) {
					if (graph1[i][j] == true) {
						m = i, n = j;
						reset(m, n);
						if (graph1[m][n] == false) {
							graph1[(i+m)/2][(j+n)/2] = true;
							graph1[m][n] = true;
							count++;
						}
					}
                }
            }
        }
	}
}


void Maze::automode() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    head();
    int x=entrance1, y=entrance2, t2 = 7;
    int t1 = difficulty==1? 24:(difficulty==2? 21:12);
    for (int i=0; i<mapsize; i++)
        for (int j=0; j<mapsize; j++)
            graph1[i][j] = false;
    graph1[x][y] = true;
	printmap1();
	gotoxy(h, t1, t2);
	cout << "!";

	if (difficulty == 1) {
        gotoxy(h, 0, 25);
    } else if (difficulty == 2) {
        gotoxy(h, 0, 29);
    } else
        gotoxy(h, 0, 38);
    cout << "��ܰ��ʾ��" << "��Exc��һ���˳�,ͨ����w''a''s''d'�������ƶ�,��q���";
	while (1) {
        fflush(stdin);
        Sleep(150);
		char a = getch();
		switch(a) {
		case 'a':
			if (x>=0 && x<mapsize && y-1>=0 && y-1<mapsize) {
                graph1[x][y-1] = true;
                gotoxy(h, t1, t2);
                cout << " ";
                t1 -= 2;
                y = y-1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 'd':
			if (x>=0 && x<mapsize && y+1>=0 && y+1<mapsize) {
                graph1[x][y+1] = true;
                gotoxy(h, t1, t2);
                cout << " ";
                t1 += 2;
                y += 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 'w':
			if (x-1>=0 && x-1<mapsize && y>=0 && y<mapsize) {
                graph1[x-1][y] = true;
                gotoxy(h, t1, t2);
                cout << " ";
                t2--;
                x -= 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 's':
			if (x+1>=0 && x+1<mapsize && y>=0 && y<mapsize) {
                graph1[x+1][y] = true;
                gotoxy(h, t1, t2);
                cout << " ";
                t2++;
                x += 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
        case 'q': {
            if (difficulty == 1) {
                gotoxy(h, 34, 24);
            } else if (difficulty == 2) {
                gotoxy(h, 34, 28);
            } else {
                gotoxy(h, 34, 36);
            }
            cout << "����Թ��Ѵ����ɹ����Ͽ�������ս�ɣ���n/y��\n\n\n";
            while (1) {
                char choice = getch();
                switch(choice) {
                    case 'n': return;
                    case 'y': peoplefind(false); return;
                    default: break;
                }
            }
        }
		case 27: {
		    count = 0;
            for (int i=0; i<mapsize; i++)
                for (int j=0; j<mapsize; j++)
                    graph1[i][j] = false;
        }
            return;
		default:
			break;
		}
	}
}
void Maze::challenge() {
    head();
    maprand(entrance1, entrance2);
    for (int i=0; i<mapsize; i++) {
        for (int j=0; j<mapsize; j++)
            graph2[i][j] = graph1[i][j];
    }
    printmap2();
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (difficulty == 1) {
        gotoxy(h, 0, 25);
    } else if (difficulty == 2) {
        gotoxy(h, 0, 29);
    } else
        gotoxy(h, 0, 38);
    cout << "��ܰ��ʾ����Exc��һ���˳�,�׷�ͨ����w''a''s''d'�������ƶ����ҷ�ͨ����i''j''k''l'�������ƶ�";

    int x=entrance1, y=entrance2, t2=7, t1=1;
    int x_=entrance1, y_=entrance2, t2_=7, t1_= difficulty==1? 38:42;
	gotoxy(h, t1, t2);
	cout << "!";
	gotoxy(h, t1_, t2_);
	cout << "!";
	SYSTEMTIME sys;
    GetLocalTime( &sys );
    int minute = sys.wMinute, second = sys.wSecond;
	while (1) {
        int s = difficulty==1? 23:(difficulty==2? 20:11);
        GetLocalTime(&sys);
        gotoxy(h, 0, 5);
        int x1 = sys.wMinute, y1 = sys.wSecond;
        int temp1 = (y1+60-second)/60;
        y1 = (y1+60-second)%60;
        x1+=temp1;
        x1--;
        x1 = (x1+60-minute)%60;
        cout << "time: " << x1 << ":" << y1;

        if (x == exit1 && y == exit2) {
            if (difficulty == 1)
                gotoxy(h, 0, 24);
            else if (difficulty == 2)
                gotoxy(h, 0, 28);
            cout << "����Բ����������ʤ���ǵ�һλ����ϲ�㣡";
            bool tag = false;
            if (((x1*60+y1) < (record[mode-1][difficulty-1].x*60+record[mode-1][difficulty-1].y)) || (record[mode-1][difficulty-1].x == 0 && record[mode-1][difficulty-1].y == 0)) {
                record[mode-1][difficulty-1].x = x1;
                record[mode-1][difficulty-1].y = y1;
                tag = true;
            }
            if (difficulty == 1) {
                if (tag) cout << "���������ʷ��¼��";
            } else if (difficulty == 2) {
                if (tag) cout << "���������ʷ��¼��";
            } else {
                if (tag) cout << "���������ʷ��¼��";
            }
            break;
        }
        if (x_ == exit1 && y_ == exit2) {
            if (difficulty == 1)
                gotoxy(h, 0, 24);
            else if (difficulty == 2)
                gotoxy(h, 0, 28);
            cout << "����Բ����������ʤ���ǵڶ�λ����ϲ�㣡";
            bool tag = false;
            if (((x1*60+y1) < (record[mode-1][difficulty-1].x*60+record[mode-1][difficulty-1].y)) || (record[mode-1][difficulty-1].x == 0 && record[mode-1][difficulty-1].y == 0)) {
                    record[mode-1][difficulty-1].x = x1;
                    record[mode-1][difficulty-1].y = y1;
                    tag = true;
            }
            if (difficulty == 1) {
                if (tag) cout << "���������ʷ��¼��";
            } else if (difficulty == 2) {
                if (tag) cout << "���������ʷ��¼��";
            } else {
                if (tag) cout << "���������ʷ��¼��";
            }
            break;
        }
        fflush(stdin);
		char a = getch();
		Sleep(200);
		switch(a) {
		case 'a':
			if (walk(x, y-1)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t1 -= 2;
                y = y-1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 'd':
			if (walk(x, y+1)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t1 += 2;
                y += 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 'w':
			if (walk(x-1, y)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t2--;
                x -= 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 's':
			if (walk(x+1, y)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t2++;
                x += 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;

        case 'j':
			if (walk(x_, y_-1)) {
                gotoxy(h, t1_, t2_);
                cout << " ";
                t1_ -= 2;
                y_ = y_-1;
				gotoxy(h, t1_, t2_);
                cout << "!";
			}
			break;
		case 'l':
			if (walk(x_, y_+1)) {
                gotoxy(h, t1_, t2_);
                cout << " ";
                t1_ += 2;
                y_ += 1;
				gotoxy(h, t1_, t2_);
                cout << "!";
			}
			break;
		case 'i':
			if (walk(x_-1, y_)) {
                gotoxy(h, t1_, t2_);
                cout << " ";
                t2_--;
                x_ -= 1;
				gotoxy(h, t1_, t2_);
                cout << "!";
			}
			break;
		case 'k':
			if (walk(x_+1, y_)) {
                gotoxy(h, t1_, t2_);
                cout << " ";
                t2_++;
                x_ += 1;
				gotoxy(h, t1_, t2_);
                cout << "!";
			}
			break;
		case 27: {
		    count = 0;
            for (int i=0; i<mapsize; i++)
                for (int j=0; j<mapsize; j++)
                    graph1[i][j] = false;
        }
            return;
		default:
			break;
		}
    }
    getch();
    count = 0;
    for (int i=0; i<mapsize; i++)
		for (int j=0; j<mapsize; j++)
			graph1[i][j] = false;
}
void Maze::peoplefind(bool sign) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    head();
    if (sign)
        maprand(entrance1, entrance2);
    int x=entrance1, y=entrance2, t2 = 7;
    int t1 = difficulty==1? 24:(difficulty==2? 21:12);
	printmap1();
	gotoxy(h, t1, t2);
	cout << "!";
    if (difficulty == 1) {
        gotoxy(h, 0, 25);
    } else if (difficulty == 2) {
        gotoxy(h, 0, 29);
    } else
        gotoxy(h, 0, 38);
    if (!find_nearest()) {
        cout << "����������Թ��߲�ͨ���㱻��ˣ�ˣ�";
        getch();
        return;
    }
    cout << "��ܰ��ʾ��" << "��Exc��һ���˳�����q��ʾ��ͨ����w''a''s''d'�������ƶ�";
    SYSTEMTIME sys;
    GetLocalTime( &sys );
    int minute = sys.wMinute, second = sys.wSecond, x1, y1;
	while (1) {
        int s = difficulty==1? 23:(difficulty==2? 20:11);
        GetLocalTime(&sys);
        gotoxy(h, s, 5);
        x1 = sys.wMinute, y1 = sys.wSecond;
        int temp1 = (y1+60-second)/60;
        y1 = (y1+60-second)%60;
        x1+=temp1;
        x1--;
        x1 = (x1+60-minute)%60;
        cout << "time: " << x1 << ":" << y1;
        bool tag = false;
        if (x == exit1 && y == exit2) {
            if (mode != 3) {
                if (((x1*60+y1) < (record[mode-1][difficulty-1].x*60+record[mode-1][difficulty-1].y)) || (record[mode-1][difficulty-1].x == 0 && record[mode-1][difficulty-1].y == 0)) {
                    record[mode-1][difficulty-1].x = x1;
                    record[mode-1][difficulty-1].y = y1;
                    tag = true;
                }
            }
            if (difficulty == 1) {
                gotoxy(h, 0, 24);
                cout << "��ϲ��ɹ�ͨ�أ����Ѿ���ţ���ˣ�";
                if (tag) cout << "���������ʷ��¼��";
            } else if (difficulty == 2) {
                gotoxy(h, 0, 28);
                cout << "    ��ϲ��ɹ�ͨ�أ����ֱ�ﱤ�ˣ�";
                if (tag) cout << "���������ʷ��¼��";
            } else {
                gotoxy(h, 0, 36);
                cout << "   ��ϲ��ɹ�ͨ�أ���������Ҳ�������޵У�";
                if (tag) cout << "���������ʷ��¼��";
            }
            getch();
            break;;
        }
        fflush(stdin);
		char a = getch();
		Sleep(300);
		switch(a) {
		case 'a':
			if (walk(x, y-1)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t1 -= 2;
                y = y-1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 'd':
			if (walk(x, y+1)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t1 += 2;
                y += 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 'w':
			if (walk(x-1, y)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t2--;
                x -= 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 's':
			if (walk(x+1, y)) {
                gotoxy(h, t1, t2);
                cout << " ";
                t2++;
                x += 1;
				gotoxy(h, t1, t2);
                cout << "!";
			}
			break;
		case 27: {
		    count = 0;
            for (int i=0; i<mapsize; i++)
                for (int j=0; j<mapsize; j++)
                    graph1[i][j] = false;
        }
            return;
        case 'q':
            tip(t1, t2, x, y);
            break;
		default:
			break;
		}
	}
	if (difficulty == 1) {
        gotoxy(h, 40, 26);
    } else if (difficulty == 2) {
        gotoxy(h, 40, 30);
    } else
        gotoxy(h, 40, 38);
    cout << "��Ϸ�Ƿ�浵��(n/y)";
    bool tag = false;
    while (1) {
        if (tag)
            break;
        char c = getch();
        switch(c) {
            case 'n': tag = true; break;
            case 'y': save(); tag = true; break;
            default:break;
        }
    }
	count = 0;
    for (int i=0; i<mapsize; i++)
		for (int j=0; j<mapsize; j++)
			graph1[i][j] = false;
}


void Maze::menue() {
    welcom.welcom();
    while (1) {
        head();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(h, 25, 6);
        for (int i=0; i<27; i++)
            cout << "*";
        gotoxy(h, 34, 8);
        cout << "1.�Ѷ�ѡ��";
        gotoxy(h, 34, 9);
        cout << "2.ģʽѡ��";
        gotoxy(h, 34, 10);
        cout << "3.��ʼ��Ϸ";
        gotoxy(h, 34, 11);
        cout << "4.�鿴�ɼ�";
        gotoxy(h, 34, 12);
        cout << "5.�鿴��¼";
        gotoxy(h, 34, 13);
        cout << "6.�鿴����";
        gotoxy(h, 34, 14);
        cout << "0.�˳�";
        gotoxy(h, 25, 16);
        for (int i=0; i<27; i++)
            cout << "*";
        char choice = getch();
        switch(choice) {
            case '1': diff_menue(); break;
            case '2': mode_menue(); break;
            case '3': {
                if (mode == 1)
                    peoplefind();
                if (mode == 2)
                    challenge();
                if (mode == 3)
                    automode();
                break;
            }
            case '4': print_record(); break;
            case '5': print_history(); break;
            case '6': print_role(false); break;
            case '0':return;
            default: break;
        }
    }
}
void Maze::mode_menue() {
    while (1) {
        head();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(h, 25, 6);
        for (int i=0; i<27; i++)
            cout << "*";
        gotoxy(h, 26, 5);
        cout << "��ǰģʽ��" << mode;
        gotoxy(h, 34, 8);
        cout << "1.����ģʽ";
        gotoxy(h, 34, 9);
        cout << "2.��սģʽ";
        gotoxy(h, 34, 10);
        cout << "3.�Զ���ģʽ";
        gotoxy(h, 34, 11);
        cout << "0.ȷ��";
        gotoxy(h, 25, 13);
        for (int i=0; i<27; i++)
            cout << "*";
        char choice = getch();
        switch(choice) {
            case '1':
                mode = 1; break;
            case '2':
                if (difficulty == 3) {
                    cout << "\n\n\n" << "�Բ������ڵ�ǰ�Ѷ��²���ʹ�ø�ģʽ��" << endl;
                    Sleep(2500);
                    break;
                }
                mode = 2;
                break;
            case '3':
                mode = 3;
                break;
            case '0':return;
            default: break;
        }
    }
}
void Maze::diff_menue() {
    while (1) {
        head();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(h, 25, 6);
        for (int i=0; i<27; i++)
            cout << "*";
        gotoxy(h, 26, 5);
        cout << "��ǰ����" << difficulty;
        gotoxy(h, 34, 8);
        cout << "1.���ּ���";
        gotoxy(h, 34, 9);
        cout << "2.ר�Ҽ���";
        gotoxy(h, 34, 10);
        cout << "3.��ʦ����";
        gotoxy(h, 34, 11);
        cout << "0.ȷ��";
        gotoxy(h, 25, 13);
        for (int i=0; i<27; i++)
            cout << "*";
        char choice = getch();
        switch(choice) {
            case '1': difficulty = 1; mapsize = 15; exit1 = 14; exit2 = 14; break;
            case '2': difficulty = 2; mapsize = 19; exit1 = 18; exit2 = 18; break;
            case '3':
                if (mode == 2) {
                    head();
                    cout << "\n\n\n�Բ�����սģʽ��֧�ִ�ʦ����";
                    getch();
                    break;
                }
                difficulty = 3; mapsize = 27; exit1 = 26; exit2 = 26; break;
            case '0':return;
            default: break;
        }
    }
}


bool Maze::find_nearest() {
    for (int i=0; i<mapsize; i++) {
        for (int j=0; j<mapsize; j++) {
            if (graph1[i][j] == true)
                key[i][j] = 0;
            else
                key[i][j] = -1;
        }
    }
    int m = exit1, n = exit2;
    if (graph1[m][n] == false)
        return false;
    int x = exit1, y = exit2;
    key[m][n] = 1;
    list<node> l;
    node nd;
    nd.x = m, nd.y = n;
    l.push_back(nd);
    list<node>::iterator t;
    while (1) {
        if (l.empty())
            return true;
        nd = l.front();
        m = nd.x;
        n = nd.y;
        l.pop_front();
        if (m == entrance1 && n == entrance2)
            continue;
        if (m+1>=0 && m+1<mapsize && n>=0 && n<mapsize) {
            if ((key[m+1][n] > key[m][n]+1 || key[m+1][n] == 0) && key[m+1][n] != -1) {
                key[m+1][n] = key[m][n]+1;
                x = m+1;
                nd.x = m+1, nd.y = n;
                l.push_back(nd);
            }
        }
        if ((m-1>=0 && m-1<mapsize && n>=0 && n<mapsize) && key[m-1][n] != -1) {
            if (key[m-1][n] > key[m][n]+1 || key[m-1][n] == 0) {
                key[m-1][n] = key[m][n]+1;
                x = m-1;
                nd.x = m-1, nd.y = n;
                l.push_back(nd);
            }
        }
        if ((m>=0 && m<mapsize && n+1>=0 && n+1<mapsize) && key[m][n+1] != -1) {
            if (key[m][n+1] > key[m][n]+1 || key[m][n+1] == 0) {
                key[m][n+1] = key[m][n]+1;
                y++;
                nd.x = m, nd.y = n+1;
                l.push_back(nd);
            }
        }
        if ((m>=0 && m<mapsize && n-1>=0 && n-1<mapsize) && key[m][n-1] != -1) {
            if (key[m][n-1] > key[m][n]+1 || key[m][n-1] == 0) {
                key[m][n-1] = key[m][n]+1;
                y--;
                nd.x = m, nd.y = n-1;
                l.push_back(nd);
            }
        }
        if (l.empty())
            return true;
    }
}
void Maze::tip(int& t1, int& t2, int& x, int& y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int temp = key[x][y]-1;
    if (key[x][y-1] == temp) {
        gotoxy(h, t1, t2);
        cout << " ";
        t1 -= 2;
        y = y-1;
        gotoxy(h, t1, t2);
        cout << "!";
    }
    if (key[x][y+1] == temp) {
        gotoxy(h, t1, t2);
        cout << " ";
        t1 += 2;
        y++;
        gotoxy(h, t1, t2);
        cout << "!";
    }
    if (key[x-1][y] == temp) {
        gotoxy(h, t1, t2);
        cout << " ";
        t2--;
        x -= 1;
        gotoxy(h, t1, t2);
        cout << "!";
    }
    if (key[x+1][y] == temp) {
        gotoxy(h, t1, t2);
        cout << " ";
        t2++;
        x += 1;
        gotoxy(h, t1, t2);
        cout << "!";
    }
}

void Maze::save() {
    FILE* fp;
	if ((fp = fopen("b.txt", "ab")) == NULL) {
		cout << "���ļ�ʧ�ܣ��浵ʧ�ܣ�" << endl;
		getch();
		fclose(fp);
		return;
	}
	int temp = mapsize;
	if (fwrite(&temp, sizeof(int), 1, fp) != 1) {
        cout << "�ļ�����ʧ��, �浵ʧ�ܣ�" << endl;
        getch();
        fclose(fp);
        fp = fopen("b.txt", "wb");
        fclose(fp);
        return;
    }
	for (int i=0; i<mapsize; i++) {
        for (int j=0; j<mapsize; j++) {
            temp = graph1[i][j];
            if (fwrite(&temp, sizeof(int), 1, fp) != 1) {
                cout << "�ļ�����ʧ��, �浵ʧ�ܣ�" << i << endl;
                getch();
                fclose(fp);
                fp = fopen("b.txt", "wb");
                fclose(fp);
                return;
            }
		}
	}
	int x = entrance1, y = entrance2;
	int tmpt[2] = {x, y};
	for (int i=0; i<2; i++) {
        if (fwrite(&tmpt[i], sizeof(int), 1, fp) != 1) {
            cout << "�ļ�����ʧ��, �浵ʧ�ܣ�" << i << endl;
            getch();
            fclose(fp);
            fp = fopen("b.txt", "wb");
            fclose(fp);
            return;
        }
    }
	while (x!=exit1 || y!=exit2) {
        int t = key[x][y]-1;
        if (key[x][y-1] == t)
            y = y-1;
        if (key[x][y+1] == t)
            y++;
        if (key[x-1][y] == t)
            x -= 1;
        if (key[x+1][y] == t)
            x += 1;
        tmpt[0] = x, tmpt[1] = y;
        for (int i=0; i<2; i++) {
            if (fwrite(&tmpt[i], sizeof(int), 1, fp) != 1) {
                cout << "�ļ�����ʧ��, �浵ʧ�ܣ�" << i << endl;
                getch();
                fclose(fp);
                fp = fopen("b.txt", "wb");
                fclose(fp);
                return;
            }
        }
    }
	fclose(fp);
}





































