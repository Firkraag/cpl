#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
//	int i;
//
//	for (i = 0x0;i <= 0x7f; i++) {
//		putchar(i);
//		putchar('\n');
//	}
	int c;
	int count = 0;
	while ((c = getchar()) != EOF) {
        if (isprint(c))
            putchar(c);
        else
            printf(" 0x%x ", c);
		count++;
		if (count == 80) {
			putchar('\n');
			count = 0;
		}
	}
	return 0;
}
