CC = gcc
CFLAGS = -Wall -O2 -I .

PROGS = lower upper print printFile diff find
OBJS = minprintf.o minscanf.o isupper.o
DIR = 7-5

all: $(PROGS) $(OBJS) $(DIR)

lower: ex7-1.o
	$(CC) $(CFLAGS) -o lower ex7-1.o

upper: ex7-1.o
	$(CC) $(CFLAGS) -o upper ex7-1.o

print: ex7-2.o
	$(CC) $(CFLAGS) -o print ex7-2.o

minprintf.o: ex7-3.c
	$(CC) $(CFLAGS) -c -o minprintf.o ex7-3.c

minscanf.o: ex7-4.c
	$(CC) $(CFLAGS) -c -o minscanf.o ex7-4.c

7-5:
	(cd ex7-5; make)

diff: ex7-6.c
	$(CC) $(CFLAGS) -o diff ex7-6.c

find: ex7-7.c
	$(CC) $(CFLAGS) -o find ex7-7.c
printFile: ex7-8.o
	$(CC) $(CFLAGS) -o printFile ex7-8.o

isupper.o: ex7-9.c
	$(CC) $(CFLAGS) -c -o isupper.o ex7-9.c
clean:
	rm -rf $(PROGS) *.o *~
	for no in $(DIR); do\
		(cd ex$$no; make clean);\
	done
