/*************************************************************************
	> File Name: ex1-21.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 10:47:41 PM CST
 ************************************************************************/

#include<stdio.h>

#define TABSTOP 8

int main() {
    int pos = 0; //The position of current c modulo TABSTOP;
    int c = getchar();
    int start;

    //We can use loop invariance to prove that at the start of each iteration, pos equals the position of current c modulo TABSTOP 
    while (c != EOF) {
        if (c == ' ') {
            start = pos;
            while ((c = getchar()) == ' ') {
                pos = (pos + 1) % TABSTOP;
                if (pos == 0) {
                    putchar('\t');
                    start = 0;
                }
            }
            pos = (pos + 1) % TABSTOP;
            if (pos == 0) {
               putchar('\t'); 
            }
            else {
                for (int i = start; i < pos; i++)
                    putchar(' ');
            }
        }
        else if (c == '\n' || c == '\t') {
            putchar(c);
            c = getchar();
            pos = 0;
        }
        else {
            putchar(c);
            c = getchar();
            pos = (pos + 1) % TABSTOP;
        }
    }
}
