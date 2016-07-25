#ifndef PINT__H
#define PINT__H

#include <windows.h>

class Pint_ {
public:
    Pint_():beginx(3), beginy(7), xsize(4), ysize(9), time(25){}
    void welcom();

private:
    void print_i(int , int ,int , int ,int);
    void print_d(int , int ,int , int ,int);
    void print_e(int , int ,int , int ,int);
    void print_r(int , int ,int , int ,int);
    void print_s(int , int ,int , int ,int);
    void print_u(int , int ,int , int ,int);
    void print_x(int , int ,int , int ,int);
    void print_t(int , int ,int , int ,int);
    void print_f(int , int ,int , int ,int);
    void print_o(int , int ,int , int ,int);
    void gotoxy(HANDLE, int, int);

private:
    int beginx, beginy, xsize, ysize, time;
};

#endif // PINT__H
