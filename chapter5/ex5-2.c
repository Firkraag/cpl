/*************************************************************************
	> File Name: bar.c
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Sep 2016 03:06:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>
#include <math.h>

int getch(void);
void ungetch(int c);

int getfloat(double *pf) {
    int c, sign;
    double val, power;
    double decimal;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (c == EOF) {
        return EOF;
    }
    else if (!isdigit(c) && c != 'e' && c != 'E' && c != '+' && c != '-') {
        decimal = 0.0;
        return 0;
    }

    /* get the decimal part of float */
    sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
        c = getch();
	for (val = 0.0; isdigit(c); c = getch()) {
		val = 10.0 * val + (c - '0');
    }
	if (c  == '.')
        c = getch();
	for (power = 1.0; isdigit(c); c = getch()) {
		val = 10.0 * val + (c - '0');
		power *= 10;
	}
    decimal = sign * val / power; 

    /* no power part */
    if (c != 'e' && c != 'E') {
        *pf = decimal;
        ungetch(c);
        return 1;
    }

    /* get the power part of float */
    c = getch();
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (val = 0; isdigit(c); c = getch())
        val = 10 * val + (c - '0');
    val *= sign; 

    ungetch(c);
    power = pow(10, val);
    *pf = decimal * power;
    return 1;
}

int main() {
    int n;
    double array[100];

    for (n = 0; n < 100 && getfloat(&array[n]) != EOF; n++) {
        printf("%f\n", array[n]);
    }
    return 0;
}
