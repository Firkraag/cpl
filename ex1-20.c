/*************************************************************************
	> File Name: ex1-20.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Aug 2016 08:23:03 AM CST
 ************************************************************************/

#include<stdio.h>

#define TABSTOP 4 /* One tab should be replaced with TABSTOP spaces */

int main()
{
    int c;
    int pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            pos = 0;
        }
        else if (c == '\t') {
            for (int i = pos; i < TABSTOP; i++)
                putchar(' ');
            pos = 0;
        }
        else {
            putchar(c);
            pos = (pos + 1) % TABSTOP;
        }
    }
}
