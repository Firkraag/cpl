/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Sep 2016 11:13:58 AM CST
 ************************************************************************/

#include<stdio.h>

#define MAXVAL 100

int sp = 0;
int val[MAXVAL];

void push(int c) {
    if (sp < MAXVAL)
        val[sp++] = c;
    else
        printf("error: stack full, can't push %c\n", c);
}

/* pop: pop and return top value from stack */
int pop()
{
    return val[--sp];
}

int empty() {
   return sp == 0; 
}
