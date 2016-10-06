/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Sep 2016 06:14:07 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* print the top element of the stack */
double top() {
    if (sp <= 0) {
        printf("error: stack empty\n");
        return 0.0;
    }
    else {
        return val[sp - 1];
    }
}

/* duplicate the top element */
void duplicate(){
    if (sp <= 0) {
        printf("error: stack empty\n");
    }
    else {
        val[sp] = val[sp - 1];
        sp++;
    }
}

/* swap the top two elements */
void swap() {
    if (sp <= 1) {
        printf("error: the stack does not have enough elements\n");
    }
    else {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
}

/* clear the stack */
void clear() {
    sp = 0;
}

