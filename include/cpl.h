/*************************************************************************
	> File Name: cpl.h
	> Author: 
	> Mail: 
	> Created Time: Thu 22 Sep 2016 03:05:39 PM CST
 ************************************************************************/

#ifndef _CPL_H
#define _CPL_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>


/* getline2: read a line into s, return length */
int getline2(char s[], int lim);

int getch(void); /* get a (possibly pushed-back) character */
void ungetch(int c); /* push character back on input */
