/*************************************************************************
	> File Name: polish.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Sep 2016 06:08:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> 

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(float *fptr);
void push(double);
double pop(void);
double top(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    double recent = 0.0;
    float fval;
    
    while ((type = getop(&fval)) != EOF) {
        switch (type) {
        case NUMBER:
            push(fval);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int) pop() % (int) op2);
            else
                printf("error: zero divisor\n");
            break;
        case 't':
            recent = top();
            printf("The top element of the stack is %f\n", recent);
            break;

        case 'd':
            duplicate();
            break;
        case 'x':
            swap();
            break;
        case 'c':
            clear();
            break;
        //sin
        case 's':
            push(sin(pop()));
            break;
        //base-e exponential
        case 'e':
            push(exp(pop()));
            break;
        //power
        case 'p':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        //push the most recently printed value onto stack
        case 'r':
            push(recent);
            break;
        case '\n':
            recent = pop();
            printf("\t%.8g\n", recent);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    printf("%g\n", pop());
    return 0;
}
