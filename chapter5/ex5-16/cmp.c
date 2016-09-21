/*************************************************************************
	> File Name: cmp.c
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Sep 2016 09:49:36 AM CST
 ************************************************************************/

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
