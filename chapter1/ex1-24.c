/*************************************************************************
	> File Name: ex1-24.c
	> Author:
	> Mail: 
	> Created Time: Thu 15 Sep 2016 10:14:42 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "stack.h"

#define BASE 0
#define COMMENT1 1 // comment style '//'
#define COMMENT2 2 // comment style '/* ... */'
#define SINGLE 3 // single quote 
#define DOUBLE 4 // double quote

void error(char *msg);

int main() {
    int c;
    int status = BASE;
    
    c = getchar();
    while (c != EOF) {
        if (status == BASE) {
            if (c == '/') {
                c = getchar();
                if (c == '/') {
                    status = COMMENT1;
                    c = getchar();
                }
                else if (c == '*') {
                    status = COMMENT2;
                    c = getchar();
                }
            }
            else if (c == '\'') {
                status = SINGLE;
                c = getchar();
            }
            else if (c == '"') {
                status = DOUBLE;
                c = getchar();
            }
            else if (c == '{' || c == '[' || c == '(') {
                push(c);
                c = getchar();
            }
            else if (c == '}') {
                if (empty() || (c = pop()) != '{') 
                    error("unmatched braces");
                c = getchar();
            }
            else if (c == ']') {
                if (empty() || (c = pop()) != '[') 
                    error("unmatched brackets");
                c = getchar();
            }
            else if (c == ')') {
                if (empty() || (c = pop()) != '(') 
                    error("unmatched parentheses");
                c = getchar();
            }
            else {
                c = getchar();
            }
        }
        else if (status == COMMENT1) {
            if (c == '\n') {
                status = BASE;
            }
            c = getchar();
        }
        else if (status == COMMENT2) {
            if (c == '*') {
                c = getchar();
                if (c == '/') {
                    status = BASE;
                    c = getchar();
                }
            }
            else {
                c = getchar();
            }
        }
        else if (status == SINGLE) {
            if (c == '\\') {
                c = getchar(); 
                if (c == EOF) {
                    error("unmatched single quote");
                }
            }
            else if (c == '\'') {
                status = BASE;
            }
            else if (c == '\n') {
                error("unmatched single quote");
            }
            c = getchar();
        }
        else if (status == DOUBLE) {
            if (c == '\\') {
                c = getchar(); 
                if (c == EOF) {
                    error("unmatched double quote");
                }
            }
            else if (c == '"') {
                status = BASE;
            }
            else if (c == '\n') {
                error("unmatched double quote");
            }
            c = getchar();

        }
        else {
            c = getchar();
        }
    }
    if (status != BASE && status != COMMENT1) {
        error("Terminating characters for single quote, double quote or comment missing");
    }
    else if (!empty()) {
        error("There are some unmatched parentheses, brackets or braces.");
    }
    else {
        printf("There are no rudimentary syntax errors\n");
        return 0;
    }
}


void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
