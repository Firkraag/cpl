#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* expand shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, 
and be prepared to handle cases like a-b-c and a-z0-9. Arrange that a leading or trailing is taken literally. */
void expand(char s1[], char s2[]) {
	int i,j=0;
	char a,b;
	int length = strlen(s1);
	for (i = 0; i < length ; i++) {
/* when s1[i] is '-', judge whether s1[i-1] and s1[i+1] are both digits or letters, if so, expansion is taken, thus a leading or trailing - is taken literally */
        printf("%c\n", s1[i - 1]);
        printf("%c\n", s1[i]);
        printf("%c\n", s1[i + 1]);
		if (i > 0 && i < length - 1 && s1[i] == '-' &&  ((islower(s1[i-1]) && islower(s1[i+1])) || (isupper(s1[i - 1]) && isupper(s1[i + 1])) || (isdigit(s1[i-1]) && isdigit(s1[i+1])))) {
				a = s1[i-1]+1;
				b = s1[i+1];
				i++;
				while (a <= b)
					s2[j++] = a++;
			}
				
		else 
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
}

int main() {
		char a[30] = "-ab-1cde-h-N-1-5-7-";
		char b[50];
		expand(a,b);
		printf("%s\n", b);
}
