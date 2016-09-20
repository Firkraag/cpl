/*************************************************************************
	> File Name: getch.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Sep 2016 06:17:20 PM CST
 ************************************************************************/

#include<stdio.h>

#define BUFSIZE 100

/* In order to store EOF, we use type int instead of char */
int buffer;
int getFromBuffer = 0;

int getch(void) /* get a (possibly pushed-back) character */
{
    if (getFromBuffer) {
        getFromBuffer = 0;
        return buffer;
    }
    else {
        return getchar();
    }
}

void ungetch(int c) /* push character back on input */
{
    getFromBuffer = 1;
    buffer = c;
}

