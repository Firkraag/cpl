/*************************************************************************
	> File Name: getch.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Sep 2016 06:17:20 PM CST
 ************************************************************************/

#include<stdio.h>

#define BUFSIZE 100

/* In order to store EOF, we use type int instead of char */
int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char *s) /* push back an entire string onto the input */
{
    int i = 0;
    int c;

    while ((c = s[i++]) != '\0') {
        ungetch(c);
    }
}
