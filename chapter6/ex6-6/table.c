/*************************************************************************
	> File Name: table.c
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 07:37:57 PM CST
 ************************************************************************/

#include "preProcessor.h"
#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
static unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
static struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        if (hashtab[hashval] != NULL)
            hashtab[hashval]->prev = np;
        hashtab[hashval] = np;
        np->prev = NULL;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char *name) {
    unsigned hashval = hash(name);
    struct nlist *np;

    if ((np = lookup(name)) != NULL)
    {
        if (np->prev != NULL)
            np->prev->next = np->next;
        else
            hashtab[hashval] = np->next;

        if (np->next != NULL)
            np->next->prev = np->prev;
        
    }
}

void freeTable() {
    for (int i = 0; i < HASHSIZE; i++) {
        struct nlist *np = hashtab[i];
        while (np != NULL) {
            struct nlist *temp = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            np = temp;
        }
    }
}

void printTable() 
{
    for (int i = 0; i < HASHSIZE; i++) {
        struct nlist *np = hashtab[i];
        while (np != NULL) {
            printf("%s:\t%s\n", np->name, np->defn);
            np = np->next;
        }
    }
}
