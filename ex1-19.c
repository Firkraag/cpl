/*************************************************************************
	> File Name: ex1-19.c
	> Author:
	> Mail:
	> Created Time: Tue 02 Aug 2016 10:59:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include "dynamic_list.h"

#define MAXLINE 5 /* maximum input line length */

int getline2(char line[], int maxline);
void reverse(char s[], int len);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    DL *dl = initDL();

    while ((len = getline2(line, MAXLINE)) > 0) {
        append(dl, line, len);
        if (isLine(dl)) {
            reverse(content(dl), size(dl) - 1);
            printf("%s", content(dl));
            clearContent(dl);
        }
    }
    if (!isLine(dl)) {
        reverse(content(dl), size(dl));
        printf("%s", content(dl));
    }
    freeDL(dl);
    return 0;
}
/* reverse: reverse character string s
 * len does not include the null terminator */
void reverse(char s[], int len)
{
    int i = 0;
    int j = len - 1;;
    int tmp;

    while (i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}
