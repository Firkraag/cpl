#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void reverse(char *s);
//void processMin(char *s);

/* itoa convert n to characters in s; compared to the original version of itoa, we have changed the type of n from int to long to to handle the largest negative number; the original version can't handle it since when n = INT_MIN, -n = INT_MAX + 1 and overflow occurs */ 
void itoa(int n, char s[]) {
	int i = 0, sign = n;
    unsigned value;

    if (n == INT_MIN) {
        value = (unsigned) INT_MAX + 1;
    }
    else if (n < 0) {
        value = -n;
    }
    else {
        value = n;
    }

	do {
		s[i++] = value % 10 + '0';
	} while ((value /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/*void processMin(char *s) {
    int n = INT_MAX;
    int i = 0, j = 0;
    int promote = 1;
    int result;

	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

    while (j < i && promote > 0) {
        result = s[j] - '0' + promote;
        if (result > 9) {
            s[j++] = '0';
            promote = 1;
        }
        else {
            promote = 0;
            s[j++] = '0' + result;
        }
    }
    if (j == i && promote == 1) {
        s[i++] = '1';
    }
    s[i++] = '-';
    s[i] = '\0';
    reverse(s);
} */
/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
int main(int argc, char *argv[]) {
	char s[100];	
	itoa(atoi(argv[1]),s);
	printf("%s\n", s);
}
