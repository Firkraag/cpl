#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int minscanf(char *fmt, ...) {
	va_list ap;
	char *p, *sptr;
	int *iptr;
	unsigned *uiptr;
	float *dptr;
	char *cp;
    int c, input;
    int nassigned = 0;
    int ret;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
        if ((c = *p) != '%') {
            if (isspace(c))
            {
                while (isspace(input = getchar()))
                    ;
                ungetc(input, stdin);
                continue;
            }
            else if ((input = getchar()) != c)
            {
                ungetc(input, stdin);
                return nassigned;
            }
            else
                continue;
        }
        while (isspace(input = getchar()))
            ;
        ungetc(input, stdin);
		switch (*++p) {
		case 'd':
			iptr = va_arg(ap, int *);
			ret = scanf("%d", iptr);
			break;
		case 'i':
			iptr = va_arg(ap, int *);
			ret = scanf("%i", iptr);
			break;
		case 'o':
			iptr = va_arg(ap, int *);
			ret = scanf("%o", iptr);
			break;
		case 'x':
			iptr = va_arg(ap, int *);
			ret = scanf("%x", iptr);
			break;
		case 'X':
			iptr = va_arg(ap, int *);
			ret = scanf("%X", iptr);
			break;
		case 'u':
			uiptr = va_arg(ap, unsigned int *);
			ret = scanf("%u", uiptr);
			break;
		case 'c':
			cp = va_arg(ap, char *);
			ret = scanf("%c", cp);
			break;
		case 's':
			sptr = va_arg(ap, char *);
			ret = scanf("%s", sptr);
			break;
		case 'f':
			dptr = va_arg(ap, float *);
			ret = scanf("%f", dptr);
			break;
		case 'e':
			dptr = va_arg(ap, float *);
			ret = scanf("%e", dptr);
			break;
		case 'E':
			dptr = va_arg(ap, float *);
			ret = scanf("%E", dptr);
			break;
		case 'g':
			dptr = va_arg(ap, float *);
			ret = scanf("%g", dptr);
			break;
		case 'G':
			dptr = va_arg(ap, float *);
			ret = scanf("%G", dptr);
			break;
		default:
			break;
		}
        if (ret == 1)
            nassigned++;
        else
            return nassigned;
	}
	va_end(ap);
    return nassigned;
}
