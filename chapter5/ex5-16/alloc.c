/*************************************************************************
	> File Name: alloc.c
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Sep 2016 10:13:17 AM CST
 ************************************************************************/

#include<stdio.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return 0;
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
