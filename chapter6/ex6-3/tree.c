#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_list.h"

struct tnode { 
    char *word;
    DL *dl;
    struct tnode *left;
    struct tnode *right;
};

extern int lineno;

struct tnode *talloc(void);
char *strdup2(char *s); /* make a duplicate of s */

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) { /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = strdup2(w);
        p->dl = initDL();
        append(p->dl, lineno);
        p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) == 0) {
        int *array = content(p->dl);
        int length = size(p->dl);

        if (lineno != array[length - 1])
            append(p->dl, lineno);
    }
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        int *array = content(p->dl);
        int length = size(p->dl);
        int i;

        treeprint(p->left);
        printf("%s:", p->word);
        for (i = 0; i < length; i++) {
            printf("\t%d", array[i]);
        }
        putchar('\n');
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup2(char *s) /* make a duplicate of s */
{
    char *p; 

    p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

void free_tree(struct tnode *node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node->word);
        freeDL(node->dl);
        free(node);
    }
}
