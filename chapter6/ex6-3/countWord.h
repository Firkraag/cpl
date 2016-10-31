/*************************************************************************
	> File Name: countWord.h
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 05:36:23 PM CST
 ************************************************************************/

#ifndef _COUNTWORD_H
#define _COUNTWORD_H
#endif

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "dynamic_list.h"

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int binsearch(char *word, char *noise[], int n); 
void free_tree(struct tnode *node);

struct tnode { 
    char *word;
    DL *dl;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *talloc(void);
extern int lineno;
