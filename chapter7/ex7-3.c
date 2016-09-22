#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void minprintf(char *fmt, ...) {
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	void *ptr;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
		case 'i':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'o':
			ival = va_arg(ap, int);
			printf("%o", ival);
			break;
		case 'x':
		case 'X':
			ival = va_arg(ap, int);
			printf("%x", ival);
			break;
		case 'u':
			ival = va_arg(ap, int);
			printf("%u", ival);
			break;
		case 'c':
			ival = va_arg(ap, int);
			putchar(ival);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 'e':
		case 'E':
			dval = va_arg(ap, double);
			printf("%e", dval);
			break;
		case 'g':
		case 'G':
			dval = va_arg(ap, double);
			printf("%g", dval);
			break;
		case 'p':
			ptr = va_arg(ap, void *);
			printf("%p", ptr);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}

int main(int argc, char *argv[]) {
   minprintf("%d, 0%o, 0x%x, %u, %c, %s, %f, %e, %g, %p\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5][0], argv[6], atof(argv[7]), atof(argv[8]), atof(argv[9]), argv); 
}
