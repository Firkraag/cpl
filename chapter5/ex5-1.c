/*************************************************************************
	> File Name: getint.c
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Sep 2016 11:13:00 AM CST
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign = 1;
    
    while (isspace(c = getch())) /* skip white space */
        ;
    if (c == EOF) {
        return EOF;
    }
    else if (c == '+' || c == '-') {
        sign = (c == '-') ? -1 : 1;
        c = getch();
        if (!isdigit(c)) {
            *pn = 0;
            ungetch(c);
            return 0;
        }
    }
    else if (!isdigit(c)) {
        *pn = 0;
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    ungetch(c);
    return 1;
}


int main() {
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("%d\n", array[n]);
        ;
}
