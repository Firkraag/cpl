CC = gcc
INC = ../include/
CFLAGS = -Wall -O2 -I . -I $(INC)

dir = dir5-7 dir5-10 dir5-11 dir5-12 dir5-13 dir5-14 dir5-15\
		dir5-16 dir5-17 dir5-18 dir5-19 dir5-20
PROGS = getint getfloat strcat strend ex5-5 ex5-6 dateConversion\
		dateConversion2 

all: $(dir) $(PROGS)

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

dir5-7:
	(cd ex5-7; make)

dateConversion: ex5-8.o
	$(CC) -o dateConversion ex5-8.o

dateConversion2: ex5-9.o
	$(CC) -o dateConversion2 ex5-9.o

dir5-10:
	(cd ex5-10; make)

dir5-11:
	(cd ex5-11; make)

dir5-12:
	(cd ex5-12; make)

dir5-13:
	(cd ex5-13; make)

dir5-14:
	(cd ex5-14; make)

dir5-15:
	(cd ex5-15; make)

dir5-16:
	(cd ex5-16; make)

dir5-17:
	(cd ex5-17; make)

dir5-18:
	(cd ex5-18; make)

dir5-19:
	(cd ex5-19; make)

dir5-20:
	(cd ex5-20; make)

clean:
	rm -rf $(PROGS) *.o *~
	for directory in $(dir); do\
		name=`echo $$directory | cut -d 'r' -f 2`;\
		(cd ex$$name; make clean);\
	done

