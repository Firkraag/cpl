/*************************************************************************
	> File Name: preProcessor.h
	> Author: 
	> Mail: 
	> Created Time: Mon 31 Oct 2016 03:26:55 PM CST
 ************************************************************************/

#ifndef _PREPROCESSOR_H
#define _PREPROCESSOR_H
#endif

#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "getline2.h"

struct nlist { /* table entry: */
    struct nlist *prev; /* prev entry in chain */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

int parseLine(char *line, char **name, char **replace);
struct nlist *install(char *name, char *defn);
void printTable();
void undef(char *name);
void freeTable();
