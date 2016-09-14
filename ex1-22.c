/*************************************************************************
	> File Name: ex1-22.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Sep 2016 03:41:20 PM CST
 ************************************************************************/

#include<stdio.h>

#define COLUMNS 80
#define TABSTOP 8

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
