#include "Calculate.h"
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

int Calculate::priority(char data) {

    int prio = 0;
    switch(data) {
    case '+':
    case '-':
        prio = 1;break;
    case '*':
    case '/':
        prio = 2;break;
    case '(':
        tag = true; break;
    case ')':
        tag = false; break;
    default:
        printf("Wrong input!\n");
        system("pause");
        exit(1);
    }
    if (tag)
        prio += 3;
    return prio;
}

void Calculate::exchange() {
    int i, m, n;
    Node data;
    tag = false;
    size = 0;
    for (i=0; i<=len; i++) {
        if (ar[i].sign != 1) {
            a.push(ar[i]);
        } else {
            int prio = priority(ar[i].a[0]);
            if (ar[i].a[0] == '(' || ar[i].a[0] == ')')
                continue;
            if (prio > pr[size-1] || b._empty()) {
                b.push(ar[i]);
                pr[size++] = prio;
            } else {
            loop:data = b.pop();
                size--;
                a.push(data);
                if (prio > pr[size-1] || b._empty()) {
                    b.push(ar[i]);
                    pr[size++] = prio;
                } else {
                    goto loop;
                }
            }
        }
    }
    while (!b._empty()) {
        data = b.pop();
        a.push(data);
    }
}

void Calculate::change() {
    char t[255];
    int i, j = 0, k=0, l;
loop:printf("Please input the arithmetic expressions: ");
    scanf("%s", t);
    l = strlen(t);
    if (l > 255) {
        printf("The arithmetic expressions is too long!\n\n");
        goto loop;
    }
    len = -1;
    bool sign = true;
    for (i=0; i<l; i++) {
        if (t[i] >= '0' && t[i] <= '9') {
            ar[j].a[k++] = t[i];
            if (i+1 == l)
                len++;
        } else {
            if (t[i-1] >= '0' && t[i-1] <= '9') {
                ar[j++].a[k] = '\0';
                len++;
            }
            ar[j].sign = 1;
            ar[j].a[0] = t[i];
            ar[j++].a[1] = '\0';
            len++;
            k = 0;
        }
    }
    ar[j].a[k] = '\0';
    for (i=0; i<=len; i++) {
        printf("%s", ar[i].a);
    }
    puts("");
}

///sign为0时代表a为正，1为负，2为操作符
void Calculate::calculate() {
    change();
    exchange();


/// ////////////////////
    int i;
    printf("prin:  ");
    for (i=0; i<a.cursize; i++)
        printf("<%s>  ", a._stack[i].a);
    puts("");

    Node data;
    int m, n;
    while (!a._empty()) {
        data = a.pop();
        b.push(data);
    }

/// ///////////////
    printf("prin:  ");
    for (i=0; i<b.cursize; i++)
        printf("<%s>  ", b._stack[i].a);


    Stack<Node> p;
    Node d;
    while (!b._empty()) {
        data = b.pop();
        if (data.sign != 2)
            p.push(data);
        else {
            switch(data.a[0]) {
            case '+':
                add(p.pop(), p.pop(), d); break;
            case '-':
                subtraction(p.pop(), p.pop(), d); break;
            case '*':
                ride(p.pop(), p.pop(), d); break;
            case '/':
                division(p.pop(), p.pop(), d); break;
            default:
                printf("error!\n\n");
                system("pause");
                exit(1);
            }
            p.push(d);
        }
    }
    d = p.pop();
    printf("The result is: %s\n", d.a);
}



void Calculate::add(Node& a, Node& b, Node& c) {
    int t1 = atoi(a.a);
    int t2 = atoi(a.a);
    t1 = t1+t2;
    char *p;
    sprintf(p,"%d",t1);
    strcpy(c.a, p);;
}

void Calculate::subtraction(Node& a, Node& b, Node& c) {
    int t1 = atoi(a.a);
    int t2 = atoi(b.a);
    t1 = t1-t2;
    char *p;
    sprintf(p,"%d",t1);
    strcpy(c.a, p);;
}

void Calculate::division(Node& a, Node& b, Node& c) {
    int t1 = atoi(a.a);
    int t2 = atoi(b.a);
    t1 = t1/t2;
    char *p;
    sprintf(p,"%d",t1);
    strcpy(c.a, p);
}

void Calculate::ride(Node& a, Node& b, Node& c) {
    int t1 = atoi(a.a);
    int t2 = atoi(b.a);
    t1 = t1*t2;
    char *p;
    sprintf(p,"%d",t1);
    strcpy(c.a, p);
}

/*

void Calculate::add(Node& a, Node& b, Node& c) {
    int len1 = strlen(a.a)-1;
    int len2 = strlen(b.a)-1;

    int i, j, m, n, tmpt=0, k=0;
    short q = 0;
    for(i=len1, j=len2; i>=0 && j>=0; i--, j--) {
        m = (int)a.a[i]-48;
        n = (int)b.a[j]-48;
        m += n;
        m += tmpt;
        tmpt = m/10;
        m %= 10;
        c.a[k++] = (char)(m+48);
    }
    if (len1 > len2)
        while (i>=0) {
            m = (int)a.a[i]-48;
            m += tmpt;
            tmpt = m/10;
            m %= 10;
            c.a[k++] = (char)(m+48);
            i--;
        }
    if (len1 < len2) {
        while (j>=0) {
            n = (int)b.a[j]-48;
            n += tmpt;
            tmpt = n/10;
            n %= 10;
            c.a[k++] = (char)(n+48);
        }
    }
    if (tmpt != 0)
        c.a[k++] = (char)(tmpt+48);
    for (i=0; i<k/2; i++) {
        char q = c.a[i];
        c.a[i] = c.a[k-i-1];
        c.a[k-i-1] = q;
    }
    c.a[k] = '\0';
}

void Calculate::subtraction(Node& a, Node& b, Node& c) {
    char* p1 = a.a;
    char* p2 = b.a;
    int len1 = strlen(p1)-1;
    int len2 = strlen(p2)-1;
    int i, j, m, n, tmpt = 0, sign = 0, k = 0;
    if (len1 == len2) {
        for (i=0; i<=len1; i++) {
            if (a.a[i] < b.a[i]) {
                sign = 1;
                break;
            }
        }
    } else {
        if (len1 < len2)
            sign = 1;
    }
    if (sign == 1) {
          char* t = p1;
          p1 = p2;
          p2 = t;
          i = len1;
          len1 = len2;
          len2 = len1;
    }

    for(i=len1, j=len2; i >= 0 && j>= 0; i--, j--) {
        m = (int)p1[i]-48;
        n = (int)p2[i]-48;
        m += tmpt;
        m -= n;
        if (m < 0) {
            m += 10;
            tmpt = -1;
        } else
            tmpt = m/10;
        c.a[k++] = (char)(m+48);
    }
     while (i>=0) {
        m += tmpt;
        if (m < 0) {
            m += 10;
            tmpt = -1;
        } else
            tmpt = 0;
        c.a[k++] = (char)(m+48);
        i--;
    }
    for (i=0; i<k/2; i++) {
        char q = c.a[i];
        c.a[i] = c.a[k-i-1];
        c.a[k-i-1] = q;
    }
    c.a[k] = '\0';
}

*/
/*
void Calculate::add(Node& a, Node& b, Node& c) {
    int len1 = strlen(a.a)-1;
    int len2 = strlen(b.a)-1;
    short s = 4, sign = 0;  /// sign标记计算结果的正负
    if (a.sign == 0 && b.sign == 0)
        s = 1;
    if (a.sign == 1 && b.sign == 1) {
        s = 2;
        sign = 1;
    }
    if (a.sign == 0 && b.sign == 1) {
        if (len1 == len2) {
            int i;
            for (i=0; i<=len1; i++) {
                if (a.a[i] < b.a[i]) {
                    sign = 1;
                    s = 3;
                    break;
                } else
                    s = 4;
            }
        } else {
            if (len1 < len2) {
                sign = 1;
                s = 3;
            } else
                s = 4;
        }
    }
    if (a.sign == 1 && b.sign == 0) {
        if (len1 == len2) {
            int i;
            for (i=0; i<=len1; i++) {
                if (a.a[i] > b.a[i]) {
                    sign = 1;
                    s = 5;
                    break;
                } else
                    s = 6;
            }
        } else {
            if (len1 > len2) {
                sign = 1;
                s = 5;
            } else
                s = 6;
        }
    }
    int i, j, m, n, tmpt=0, k=0;
    short q = 0;
    for(i=len1, j=len2; i >= 0 && j>= 0; i--, j--) {
        m = (int)a.a[i]-48;
        n = (int)b.a[j]-48;
        if (q == 1)
            --n;
        if (q == 2)
            --m;
        q = 0;
        switch(s) {
        case 1:
        case 2:
            m += n;
            m += tmpt;
            break;
        case 3:
        case 5:
            if (i>0) {
                m += 10;
                q = 2;
            }
            m += tmpt;
            m -= n;
            break;
        case 4:
        case 6:
            if (i>0) {
                n += 10;
                q = 1;
            }
            n += tmpt;
            n -= m;
            m = n;
            break;
        }
        tmpt = m/10;
        m %= 10;
        c.a[k++] = (char)(m+48);
    }
    if (len1 > len2)
        while (i>=0) {
            c.a[k++] = a.a[i];
            i--;
        }
    if (len1 < len2)
        for (i=len2-1; i>=0; i--) {
            while (j>=0) {
                c.a[k++] = b.a[j];
                j--;
            }
        }
    for (i=0; i<k/2; i++) {
        char q = c.a[i];
        c.a[i] = c.a[k-i-1];
        c.a[k-i-1] = q;
    }
    c.a[k] = '\0';
    c.sign = sign;
}

void Calculate::subtraction(Node& a, Node& b, Node& c) {
    int len1 = strlen(a.a)-1;
    int len2 = strlen(b.a)-1;
    short s = 0, sign = 0;  /// sign标记计算结果的正负
    if (a.sign == 0 && b.sign == 0) {
        if (len1 == len2) {
            int i;
            for (i=0; i<=len1; i++) {
                if (a.a[i] < b.a[i]) {
                    sign = 1;
                    s = 2;
                    break;
                } else
                    s = 3;
            }
        } else {
            if (len1 < len2) {
                sign = 1;
                s = 2;
            }else
                s = 3;
        }
    }
    if (a.sign == 1 && b.sign == 1) {
        if (len1 == len2) {
            int i;
            for (i=0; i<=len1; i++) {
                if (a.a[i] > b.a[i]) {
                    sign = 1;
                    s = 4;
                    break;
                } else
                    s = 5;
            }
        } else {
            if (len1 > len2) {
                sign = 1;
                s = 4;
            } else
                s = 5;
        }
    }
    if (a.sign == 0 && b.sign == 1)
        s = 1;
    if (a.sign == 1 && b.sign == 0) {
        sign = 1;
     }
    int i, j, m, n, tmpt=0, k=0;
    for(i=len1, j=len2; i >= 0 && j>= 0; i--, j--) {
        m = (int)a.a[i]-48;
        n = (int)b.a[i]-48;
        if (m>n)
            tmpt = -1;
        switch(s) {
        case 1:
            m -= n;
            break;
        case 2:
            n -= m;
            m += n;
            m += tmpt;
            break;
        case 3:
        case 4:
            m -= n;
            break;
        }
        tmpt = m/10;
        m %= 10;
        c.a[k++] = (char)(m+48);
    }
    if (len1 > len2)
        while (i>=0) {
            c.a[k++] = a.a[i];
            i--;
        }
    if (len1 < len2)
        for (i=len2-1; i>=0; i--) {
            while (j>=0) {
                c.a[k++] = a.a[j];
                j--;
            }
        }
    int p = k/2;
    for (i=0; i<p; i++) {
        char q = c.a[i];
        c.a[i] = c.a[k-i-1];
        c.a[k-i-1] = q;
    }
    c.a[k] = '\0';
    c.sign = sign;
}
*/
