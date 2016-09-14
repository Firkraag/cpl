/*************************************************************************
	> File Name: ex1-23.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Sep 2016 08:03:37 PM CST
 ************************************************************************/

#include<stdio.h>

#define BASE 0
#define COMMENT1 1 // comment style '//'
#define COMMENT2 2 // comment style '/* ... */'
#define QUOTE 3

int main() {
    int c;
    int status = BASE;
    
    c = getchar();
    //We can use loop invariance to prove that c is the next character to be processed
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
                else {
                    putchar('/');
                }
            }
            else if (c == '"') {
                putchar(c);
                status = QUOTE;
                c = getchar();
            }
            else {
                putchar(c);
                c = getchar();
            }
        }
        else if (status == COMMENT1) {
            if (c == '\n') {
                status = BASE;
                putchar(c);
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
        else {
            putchar(c);
            if (c == '"') {
                status = BASE;
            }
            c = getchar();
        }
    }
    return 0;
}
