#include "Pint_.h"
#include <iostream>

using namespace std;

void Pint_::gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

void Pint_::print_i(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Sleep(time);
	cout << " ";
	gotoxy(h, beginx, beginy);
	int i;
	for (i=0; i<xsize+1; i++) {
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<ysize+1; i++) {
		gotoxy(h, (beginx*2+xsize)/2, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx, beginy+ysize+1);
	for (i=0; i<xsize+1; i++) {
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_x(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i;
	gotoxy(h, beginx, beginy);
	for (i=0; i<ysize+2; i++) {
		if (i == ysize/2 || i == ysize/2+1 || i == ysize/2+2)
			continue;
		gotoxy(h, beginx, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<3; i++) {
		gotoxy(h, beginx+1, beginy+ysize/2+i);
		if (i == 1) {
			Sleep(time);
			cout << " " << (char)2;
			continue;
		}
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<ysize+2; i++) {
		if (i == ysize/2 || i == ysize/2+1 || i == ysize/2+2)
			continue;
		gotoxy(h, beginx+xsize, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx+xsize-1, beginy+ysize/2);
	Sleep(time);
	cout << (char)2;
	gotoxy(h, beginx+xsize-1, beginy+ysize/2+2);
	Sleep(time);
	cout << (char)2;
}

void Pint_::print_e(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, beginx, beginy);
	int i;
	for (i=0; i<xsize; i++) {
		Sleep(time);
		cout << (char)2;
	}
	for (i=beginy+1; i<beginy+1+ysize; i++) {
		gotoxy(h, beginx, i);
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx, i);
	for (i=0; i<xsize; i++) {
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx, beginy+ysize/2+1);
	for (i=0; i<xsize; i++) {
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_s(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, beginx, beginy);
	int i;
	for (i=0; i<xsize; i++) {
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<ysize/2+1; i++) {
		gotoxy(h, beginx, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<xsize-1; i++) {
		gotoxy(h, beginx+i, beginy+ysize/2+1);
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<ysize/2+1; i++) {
		gotoxy(h, beginx+xsize-1, beginy+i+ysize/2+1);
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx, beginy+ysize+1);
	for (i=0; i<xsize; i++) {
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_t(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Sleep(time);
	cout << " ";
	gotoxy(h, beginx, beginy);
	int i;
	for (i=0; i<xsize+1; i++) {
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<ysize+2; i++) {
		gotoxy(h, (beginx*2+xsize)/2, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_f(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, beginx, beginy);
	int i;
	for (i=0; i<xsize; i++) {
		Sleep(time);
		cout << (char)2;
	}
	for (i=beginy+1; i<beginy+2+ysize; i++) {
		gotoxy(h, beginx, i);
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx, beginy+ysize/2+1);
	for (i=0; i<xsize; i++) {
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_d(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, beginx, beginy);
	int i;
	for (i=0; i<xsize-2; i++) {
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<ysize+2; i++) {
		gotoxy(h, beginx, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	cout << (char)2 << (char)2;
	gotoxy(h, beginx+xsize-2, beginy+1);
	Sleep(time);
	cout << (char)2;
	gotoxy(h, beginx+xsize-1, beginy+2);
	Sleep(time);
	cout << (char)2;
	gotoxy(h, beginx+xsize-1, beginy+ysize-1);
	Sleep(time);
	cout << (char)2;
	gotoxy(h, beginx+xsize-2, beginy+ysize);
	Sleep(time);
	cout << (char)2;
	for (i=0; i<ysize-3; i++) {
		gotoxy(h, beginx+xsize-1, beginy+3+i);
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_o(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, beginx+1, beginy);
	int i;
	for (i=0; i<3; i++) {
        Sleep(time);
        cout << (char)2;
    }
	for (i=0; i<ysize; i++) {
		gotoxy(h, beginx, beginy+i+1);
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx, beginy+ysize+1);
	cout << " " << (char)2 << (char)2 << (char)2;
	for (i=0; i<ysize; i++) {
		gotoxy(h, beginx+xsize-1, beginy+i+1);
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_r(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, beginx, beginy);
	int i;
	for (i=0; i<xsize-1; i++) {
		Sleep(time);
		cout << (char)2;
	}
	for (i=1; i<ysize+2; i++) {
		gotoxy(h, beginx, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	for (i=1; i<ysize/2; i++) {
		gotoxy(h, beginx+xsize-1, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx, beginy+i);
	for (i=0; i<xsize-1; i++) {
		Sleep(time);
		cout << (char)2;
	}
	gotoxy(h, beginx+1, beginy+xsize);
	Sleep(time);
	cout << (char)2 << (char)2;
	gotoxy(h, beginx+3, beginy+xsize+1);
	Sleep(time);
	cout << (char)2;
	for (i=0; i<xsize-1; i++) {
		gotoxy(h, beginx+4, beginy+ysize/2+i+3);
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::print_u(int beginx, int beginy, int xsize, int ysize, int time) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i;
	for (i=0; i<ysize+1; i++) {
		gotoxy(h, beginx, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<xsize-2; i++) {
		gotoxy(h, beginx+1+i, beginy+ysize+1);
		Sleep(time);
		cout << (char)2;
	}
	for (i=0; i<ysize+1; i++) {
		gotoxy(h, beginx+xsize-1, beginy+i);
		Sleep(time);
		cout << (char)2;
	}
}

void Pint_::welcom() {
	int i;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(h, 7, 1);
	for (i=0; i<30; i++)
		cout << "*";
	cout << " " << (char)2 << " ";
	gotoxy(h, 40, 1);
	for (i=0; i<30; i++)
		cout << "*";
	gotoxy(h, 34, 3);
	cout << "Welcom Use";
	print_e(beginx, beginy, xsize, ysize, time);
	int _beginx = beginx+xsize+1;
	print_x(_beginx, beginy, xsize, ysize, time);
	_beginx += xsize+2;
	print_i(_beginx, beginy, xsize-2, ysize, time);
	_beginx += xsize;
	print_s(_beginx, beginy, xsize, ysize, time);
	_beginx += xsize+1;
	print_t(_beginx, beginy, xsize-2, ysize, time);
	_beginx += xsize*2+2;
	print_f(_beginx, beginy, xsize, ysize, time);
	_beginx += xsize+1;
	print_o(_beginx, beginy, xsize+1, ysize, time);
	_beginx += xsize+2;
	print_r(_beginx, beginy, xsize+1, ysize, time);
	_beginx += xsize*2+3;
	print_u(_beginx, beginy, xsize+1, ysize, time);
	_beginx += xsize+2;
	print_s(_beginx, beginy, xsize+1, ysize, time);
	_beginx += xsize+2;
	print_e(_beginx, beginy, xsize, ysize, time);
	_beginx += xsize+2;
	print_r(_beginx, beginy, xsize+1, ysize, time);
	Sleep(3000);
}
