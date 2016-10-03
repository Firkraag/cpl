/*************************************************************************
	> File Name: sort.h
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Oct 2016 11:49:34 AM CST
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H
#endif

#include "cpl.h"

#define NUMERIC 0x1 /* numeric sort */
#define REVERSE 0x2 /* reverse */
#define CASE_INSENSITIVE 0x4 /* case sensitive */
#define DICT_ORDER 0x8 /* condider only letters, numbers and blanks */

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAX_FIELDS 100 /* max number of fields used as keys to sort */

void setOption(int *option, int mask);
int getOption(int option, int mask);
int isDictOrder(int c);
//Fill options[index] with field-specific options from argument of -k represented by string 
void generateFields(char *lineptr[], int lines, char *start[][MAX_FIELDS], char *end[][MAX_FIELDS], int sep);
void getFieldOptions(char *string, int *field_compare_no, int *field_compare_option, int field_compare_index);
void generateCompare(char *compare[], char *lineptr[], int lines, char *fields[][MAX_FIELDS], int field_compare_option[], int field_compare_no[], int field_compare_index, int sep);
void qsort2(void *compare[], void *v[], int left, int right, int field_compare_option[], int field_compare_index);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
/* content is the actual array needed to be sorted, compare is the array to be compared in qsort */
int numcmp(const char *, const char *);
