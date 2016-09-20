#include <stdio.h>
#include <string.h>

/* strend: returns 1 if the string t occurs at the end of the string s, and zero otherwise */
int strend(char *s, char *t) {
	int len_s = strlen(s);
	int len_t = strlen(t);
	int i = 0;
	int start = len_s - len_t;	/* where in the array s the comparison should start */ 

	if (start < 0) /* if len_s < len_t, there is no need to continue */
		return 0;
	while (start < len_s)
		if (s[start++] != t[i++])
			return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	printf("%d\n", strend(argv[1], argv[2]));
	return 0;
}
