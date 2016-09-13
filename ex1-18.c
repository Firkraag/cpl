/*************************************************************************
	> File Name: ex1-18.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 11:50:56 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "dynamic_list.h"

#define MAXLINE 5 /* maximum input line length */

int getline2(char line[], int maxline);
void removeTrailingBlanks(char *string);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    DL *dl = initDL();

    while ((len = getline2(line, MAXLINE)) > 0) {
        append(dl, line, len);
        if (isLine(dl)) {
            removeTrailingBlanks(content(dl));
            printf("%s", content(dl));
            clearContent(dl);
        }
    }
    if (!isLine(dl)) {
        removeTrailingBlanks(content(dl));
        printf("%s", content(dl));
    }
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

void removeTrailingBlanks(char *string)  {
    //The length excludes the null terminator
    int length = strlen(string);
    int i;

    if (length == 0)
        return;
    else if (string[length - 1] == '\n') {
        for (i = length - 2; i >= 0; i--) {
            if (string[i] != ' ' && string[i] != '\t')
                break;
        }
        if (i < 0) {
            string[i + 1] = '\0';
        }
        else {
            string[i + 1] = '\n';
            string[i + 2] = '\0';
        }
    }
    else {
        for (i = length - 1; i >= 0; i--) {
            if (string[i] != ' ' && string[i] != '\t')
                break;
        }
        string[i + 1] = '\0';
    }
}

