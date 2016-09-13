/*************************************************************************
	> File Name: ex1-17.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Aug 2016 10:53:05 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 5 /* maximum input line length */
#define MINLENGTH 15
#include "dynamic_list.h"
int getline2(char line[], int maxline);

/* print all input lines that are longer than MAXCHARS characters */
int main()
{
    int len; /* current line length, not including null terminator */
    char line[MAXLINE]; /* current input line */
    DL *dl = initDL();     

    while ((len = getline2(line, MAXLINE)) != 0) {
        append(dl, line, len);
        if (isLine(dl) && size(dl) > MINLENGTH)
            printf("%s", content(dl));
        if (isLine(dl)) {
            clearContent(dl);
        }
    }
    if (size(dl) > MINLENGTH && !isLine(dl))
       printf("%s", content(dl));
    freeDL(dl);
    return 0;
}

/* getline2: read a line into s, return length */
int getline2(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
