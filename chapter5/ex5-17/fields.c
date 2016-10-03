/*************************************************************************
	> File Name: fields.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Oct 2016 09:17:14 PM CST
 ************************************************************************/

#include "sort.h"

#define BUFFERSIZE 100000 
static int extractFieldNo(char **sptr);

void generateCompare(char *compare[], char *lineptr[], int lines, char *fields[][MAX_FIELDS], int field_compare_option[], int field_compare_no[], int field_compare_index, int sep) {
    static char buffer[BUFFERSIZE];
    static int sp = 0;
    char *start[lines][MAX_FIELDS];
    char *end[lines][MAX_FIELDS];

    //When this function return, start[l][k] and end[l][k]
    //is the start and end addresses of the (k + 1)th field of the (l + 1)th line delimited by argument sep
    generateFields(lineptr, lines, start, end, sep);
    
    for (int i = 0; i < lines; i++) {
        compare[i] = buffer + sp;
        for (int j = 0; j < field_compare_index; j++) {
            int option = field_compare_option[j];
            int field_no = field_compare_no[j];
            char *field_start = start[i][field_no - 1]; 
            char *field_end = end[i][field_no - 1]; 
            int dict_order = getOption(option, DICT_ORDER);
            int case_insensitive = getOption(option, CASE_INSENSITIVE);

            for (char *ptr = field_start; ptr <= field_end; ptr++) {
                int c = *ptr;
                if (dict_order) {
                    if (!isDictOrder(c))  
                        continue;
                }

                if (case_insensitive)
                {
                    buffer[sp++] = tolower(c);
                    
                }
                else {
                    buffer[sp++] = c;
                }
            }
            buffer[sp++] = '\0';
        }
    }
}


void generateFields(char *lineptr[], int lines, char *start[][MAX_FIELDS], char *end[][MAX_FIELDS], int sep) {

    for (int i = 0; i < lines; i++) {
        int field_index = 0;
        int c;
        char *ptr = lineptr[i];

        start[i][0] = ptr;
        while ((c = *ptr) != '\0') {
            if (sep == c) {
                end[i][field_index] = ptr;
                start[i][++field_index] = ptr + 1;
            }
            ptr++;
        }
        end[i][field_index] = ptr - 1;
    }
}

void getFieldOptions(char *string, int *field_compare_no, int *field_compare_option, int field_compare_index) {
    int option = 0;
    int c;

    field_compare_no[field_compare_index] = extractFieldNo(&string);
    while ((c = *string++) != '\0') {
        switch(c) {
        case 'n':
            setOption(&option, NUMERIC);
            break;
        case 'r':
            setOption(&option, REVERSE);
            break;
        case 'f':
            setOption(&option, CASE_INSENSITIVE);
            break;
        case 'd':
            setOption(&option, DICT_ORDER);
            break;
        default:
            printf("sort: invalid field specification '%c'\n", c);
            exit(1);
            break;
        }
    }
    field_compare_option[field_compare_index] = option;
}

static int extractFieldNo(char **sptr) {
    char *string = *sptr;
    char *start = string;
    int c;
    int field_no;

    while (isdigit(c = *string))
        string++;
    if (string == start) {
        printf("sort: invalid number at field start\n");
        exit(1);
    }
    c = *string;
    *string = '\0';
    field_no = atoi(start);
    *string = c;
    *sptr = string;
    return field_no;
}
