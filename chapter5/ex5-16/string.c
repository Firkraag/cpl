/*************************************************************************
	> File Name: filter.c
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Sep 2016 02:49:51 PM CST
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>

#define BUFFERSIZE 100000 

static char buffer[BUFFERSIZE];
static int sp = 0;

void dictOrderFilter(char *src[], char *dest[], int lines) {
    int i;

    for (i = 0; i < lines; i++) {
        int j;
        char *string = src[i];
        int c;

        dest[i] = buffer + sp;
        for (j = 0; (c = string[j]) != '\0'; j++) {
            if (isalnum(c) || isspace(c))
                buffer[sp++] = c;
        }
        buffer[sp++] = '\0';
    }
}

void upper2lower(char *array[], int lines) {
    int i;

    for (i = 0; i < lines; i++) {
        int j;
        char *string = array[i];
        int c;

        for (j = 0; (c = string[j]) != '\0'; j++) {
            if (isupper(c))
                string[j] = 'a' + (c - 'A');
        }
    }
}

void copy(char *src[], char *dest[], int lines) {
    int i;

    for (i = 0; i < lines; i++) {
        int j;
        char *string = src[i];
        int c;

        dest[i] = buffer + sp;
        for (j = 0; (c = string[j]) != '\0'; j++) {
            buffer[sp++] = c;
        }
        buffer[sp++] = '\0';
    }
}

void Reverse(void **array, int length) {
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        void *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    } 
}
