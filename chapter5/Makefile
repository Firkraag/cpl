CC = gcc
CFLAGS = -Wall -O2 -I .

OBJS = getint getfloat strcat strend ex5-5 ex5-6 ex5-7/sort dateConversion dateConversion2
all: ${OBJS}

getint: ex5-1.o getch.o
	$(CC) -o getint ex5-1.o getch.o

getfloat: ex5-2.o getch.o
	$(CC) -o getfloat ex5-2.o getch.o -lm

strcat: ex5-3.o
	$(CC) -o strcat ex5-3.o

strend: ex5-4.o
	$(CC) -o strend ex5-4.o

ex5-5: ex5-5.o

ex5-6: ex5-6.o getch.o

ex5-7/sort:
	(cd ex5-7; make)

dateConversion: ex5-8.o
	$(CC) -o dateConversion ex5-8.o

dateConversion2: ex5-9.o
	$(CC) -o dateConversion2 ex5-9.o
