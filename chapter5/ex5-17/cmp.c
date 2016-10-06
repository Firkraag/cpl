/*************************************************************************
	> File Name: cmp.c
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Sep 2016 09:49:36 AM CST
 ************************************************************************/

#include "sort.h"

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
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

int comp(char *line1, char *line2, int field_options[], int field_compare_size) {
    char *field1 = line1;
    char *field2 = line2;

    for (int i = 0; i < field_compare_size; i++)
    {
        int numeric = getOption(field_options[i], NUMERIC);
        int reverse = getOption(field_options[i], REVERSE);
        int (*method)(const char *, const char *) = (numeric ? numcmp : strcmp); 
        int ret = (*method)(field1, field2);

        field1 += (strlen(field1) + 1);
        field2 += (strlen(field2) + 1);

        if (ret != 0) {
            if (reverse)
                return ret * -1;
            else
                return ret;
        }
    }
    return 0;
}
