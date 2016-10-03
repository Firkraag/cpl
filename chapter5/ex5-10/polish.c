/*************************************************************************
	> File Name: polish.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Sep 2016 06:08:45 PM CST
 ************************************************************************/

#include "cpl.h"

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char [], char *argument[], int size);
void push(double);
double pop(void);
double top(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    double recent = 0.0;
    
    if (argc == 1) {
        return 0;
    }
    while ((type = getop(s, argv + 1, argc - 1)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
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
    printf("\t%.8g\n", pop());
    return 0;
}
