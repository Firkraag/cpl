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
    DL *dl;
    dl = (DL *) malloc(sizeof(DL));
    dl->length = INITLEN;
    dl->index = 0;
    dl->data = (char *) malloc(sizeof(char) * INITLEN);
    //The allocated memory is not initialized
    dl->data[0] = '\0';
    return dl;
}

void freeDL(DL *dl) {
    free(dl->data);
    free(dl);
}

void expandSize(DL *dl, int newSize) {
    dl->data = (char *) realloc(dl->data, newSize);
    dl->length = newSize;

}

void append(DL *dl, char *string, int length) {
    int requireSize = length + dl->index + 1;
    int newSize = dl->length;

    if (requireSize > newSize)
        while (requireSize > newSize)
            newSize *= 2;
        expandSize(dl, newSize);
    strcat(dl->data, string);
    dl->index += length;
}

int isLine(DL *dl) {
   return dl->index > 0 && (dl->data[dl->index - 1] == '\n');
}

int size(DL *dl) {
    return dl->index;
}

char *content(DL *dl) {
    return dl->data;
}

void clearContent(DL *dl) {
    dl->data[0] = '\0';
    dl->index = 0;
}
