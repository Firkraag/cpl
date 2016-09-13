/*************************************************************************
	> File Name: ex1-16.c
	> Author:
	> Mail:
	> Created Time: Tue 02 Aug 2016 10:44:20 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 50 /* maximum input line length */
int getline2(char line[], int maxline);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    int count = 0;

    while ((len = getline2(line, MAXLINE)) > 0) {
        printf("%s", line);
        count += len;
        /* print the length of the line */
        if (line[len - 1] == '\n') {
            printf("The length of line is %d\n", count);
            count = 0;
        } 
    }
    return 0;
}
