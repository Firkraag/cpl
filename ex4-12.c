#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[]) {
	static int i = 0;
	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}
	if (n / 10)
		itoa(n / 10, s);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
}	

int main(int argc, char *argv[]) {
	char s[20];
	itoa(atoi(argv[1]), s);
	printf("%s\n", s);
}
