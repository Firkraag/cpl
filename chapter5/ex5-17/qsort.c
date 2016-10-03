/*************************************************************************
	> File Name: qsort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:13:59 AM CST
 ************************************************************************/

#include "sort.h"


/* qsort: sort v[left]...v[right] into increasing order */
void qsort2(void *compare[], void *v[], int left, int right, int field_compare_option[], int field_compare_index) {
    int i, last;
    void swap(void *array[], int i, int j);
    int comp(char *line1, char *line2, int field_compare_option[], int field_compare_index);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    swap(compare, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (comp(compare[i], compare[left], field_compare_option, field_compare_index) < 0) {
            last++;
            swap(v, last, i);
            swap(compare, last, i);
        }
    }
    swap(v, left, last);
    swap(compare, left, last);
    qsort2(compare, v, left, last-1, field_compare_option, field_compare_index);
    qsort2(compare, v, last + 1, right, field_compare_option, field_compare_index);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

