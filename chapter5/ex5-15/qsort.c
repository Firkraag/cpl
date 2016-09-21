/*************************************************************************
	> File Name: qsort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:13:59 AM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <ctype.h>

void copyString(char *source, char *dest, int caseSensitive);

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int caseSensitive) {
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        char string1[strlen(v[i]) + 1], string2[strlen(v[left]) + 1];

        copyString(v[i], string1, caseSensitive);
        copyString(v[left], string2, caseSensitive);
        if (((*comp)(string1, string2)) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1, comp, caseSensitive);
    qsort(v, last+1, right, comp, caseSensitive);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* copy string from source to dest. if not case sensitive, convert uppercase to lowercase */
void copyString(char source[], char dest[], int caseSensitive) {
    int c, i;
    
    for (i = 0; (c = source[i]) != '\0'; i++) {
        if (!caseSensitive && isupper(c)) {
            dest[i] = 'a' + (c - 'A');
        }
        else {
            dest[i] = c;
        }
    }
    dest[i] = '\0';
}
