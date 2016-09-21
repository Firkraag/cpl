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
void qsort(void *compare[], void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *array[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    swap(compare, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (((*comp)(compare[i], compare[left])) < 0) {
            last++;
            swap(v, last, i);
            swap(compare, last, i);
        }
    }
    swap(v, left, last);
    swap(compare, left, last);
    qsort(compare, v, left, last-1, comp);
    qsort(compare, v, last+1, right, comp);
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
