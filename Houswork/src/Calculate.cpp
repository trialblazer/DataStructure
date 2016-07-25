#include "Calculate.h"

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
