/*************************************************************************
	> File Name: getline.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 05:41:40 PM CST
 ************************************************************************/

#include<stdio.h>

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
