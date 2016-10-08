/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:10:47 AM CST
 ************************************************************************/

#include "sort.h"


/* sort input lines */
int main(int argc, char *argv[]) {
    char *compare[MAXLINES];
    char *lineptr[MAXLINES]; /* pointers to text lines */
    int nlines; /* number of input lines read */
    int i;
    int global_option = 0;
    int field_compare_option[MAX_FIELDS];
    int field_compare_no[MAX_FIELDS];
    int field_compare_index = 0;
    int sep = ' ';
    int done = 0;

    /* get option */
    for (i = 1; i < argc && ((argv[i])[0] == '-'); i++) {
        char *string = argv[i];
        int j;
        int c;

        for (j = 1; ((c = string[j]) != '\0') && !done; j++) {
            switch(c) {
            case 'n':
                setOption(&global_option, NUMERIC);
                break;
            case 'r':
                setOption(&global_option, REVERSE);
                break;
            case 'f':
                setOption(&global_option, CASE_INSENSITIVE);
                break;
            case 'd':
                setOption(&global_option, DICT_ORDER);
                break;
            case 'k':
                if (string[j + 1] != '\0')
                    string += (j + 1);
                else if (++i == argc) {
                    printf("sort: option requires an argument -- 'k'\n");
                    return 1;
                }
                else {
                    string = argv[i];
                }
                getFieldOptions(string, field_compare_no, field_compare_option, field_compare_index);
                field_compare_index++;
                done = 1;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                i = argc + 1;
                break;
            } 
        }
        done = 0;
    } 


    if (i != argc) {
        printf("Usage: sort [-n] [-r] [-d] [-f] [-k[field spec]]... \n");
        return 1;
    }

    /* read lines and sort */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (field_compare_index == 0) {
            sep = '\0';
            field_compare_index = 1;
            field_compare_option[0] = global_option;
            field_compare_no[0] = 1;
        }
        char *fields[nlines][field_compare_index];
        generateCompare(compare, lineptr, nlines, fields, field_compare_option, field_compare_no, field_compare_index, sep);
        qsort2((void **) compare, (void**) lineptr, 0, nlines-1, field_compare_option, field_compare_index);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}
