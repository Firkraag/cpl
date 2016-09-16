#include <stdio.h>
#include <string.h>
#include <limits.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}	
}
/* another version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough */
void itoa(int n, char s[], int width) {
	int i = 0, sign = n;
    unsigned value;
    int blanks;

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

	blanks = width - i;
    for (blanks = width - i; blanks > 0; blanks--) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
	int n = 196;
	char s[30];
	itoa(n,s,2);
	printf("%s\n", s);
}

