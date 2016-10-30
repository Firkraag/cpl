/*************************************************************************
	> File Name: dynamic_list.c
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Sep 2016 08:52:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_list.h"

DL *initDL() {
    DL *dl = (DL *) malloc(sizeof(DL));
    dl->length = INITLEN;
    dl->index = 0;
    dl->data = (int *) malloc(sizeof(int) * INITLEN);
    return dl;
}

void freeDL(DL *dl) {
    free(dl->data);
    free(dl);
}

void expandSize(DL *dl) {
    dl->length *= 2;
    dl->data = (int *) realloc(dl->data, sizeof(int) * dl->length);
}

void append(DL *dl, int number) {
    dl->data[dl->index++] = number;

    if (dl->index >= dl->length)
        expandSize(dl);
}

int size(DL *dl) {
    return dl->index;
}

int *content(DL *dl) {
    return dl->data;
}
