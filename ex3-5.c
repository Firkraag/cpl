#include <stdio.h>
#include <limits.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
/* convert the integer n into a base b character representation in the string s, handles INT_MIN correctly. 2 <= b <= 10*/

void itob(int n, char s[], int b) {	
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
		s[i++] = value % b + '0';
	} while ((value /= b) > 0);

	if (sign < 0)
		s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* convert the integer n into a hexadecimal integer */
void itoh(int n, char s[], int b) {	
	int i = 0, sign = n;
    unsigned value;
    int modulo;

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
        modulo = value % 16;
        if (modulo < 10) {
            s[i++] = modulo + '0';
        }
        else if (modulo == 10) {
            s[i++] = 'A';
        }
        else if (modulo == 11) {
            s[i++] = 'B';
        }
        else if (modulo == 12) {
            s[i++] = 'C';
        }
        else if (modulo == 13) {
            s[i++] = 'D';
        }
        else if (modulo == 14) {
            s[i++] = 'E';
        }
        else if (modulo == 15) {
            s[i++] = 'F';
        }
	} while ((value /= 16) > 0);

	if (sign < 0)
		s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
	int n = INT_MIN; 
	char s[40];
	itoh(n, s, 16);
	printf("%s\n", s);
}
