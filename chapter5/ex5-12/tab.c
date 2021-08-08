/*************************************************************************
	> File Name: tab.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Oct 2016 03:41:13 PM CST
 ************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "tab.h"

/* Parse command argments read from the shell, filling m, n with starting column and tabstop.
 * When encountered invalid argument, the function will print an error message and exit */ 
void parseArgs(char *args[], int size, int *sptr, int *tptr) {
    int start = START, tabstop = TABSTOP;
    int i;
    char msg[100];

    if (size > 3) {
        sprintf(msg, "Usage: %s [-start] [+tabstop]", args[0]);
        error(msg);
    }
    else {
        for (i = 1; i < size; i++) {
            char *arg = args[i];

            if ((arg[0] != '-') && (arg[0] != '+')) {
                sprintf(msg, "Usage: %s [-start] [+tabstop]", args[0]);
                error(msg);

            }
            else if (arg[0] == '-') {
                if (isNumber(arg + 1))
                    start = atoi(arg + 1);
                else {
                    error("The starting column must be integer");
                }
            }
            else {
                if (isNumber(arg + 1))
                    tabstop = atoi(arg + 1);
                else {
                    error("The tabstop must be integer");
                }
            }
        }
    }
    *sptr = start;
    *tptr = tabstop;
}

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int isNumber(char *string) {
    int c;
    if (*string == '\0')
        return 0;
    else {
        while ((c = *string++) != '\0') {
            if (!isdigit(c))
                return 0;
        }
        return 1;
    }
}
