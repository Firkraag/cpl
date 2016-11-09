CC = gcc
CFLAGS = -g -Wall -O2 -I .

PROGS = strindex atof itoa_r reverse_r swap
DIR = 4-3 4-4 4-5 4-6 4-7 4-8 4-9 4-10 4-11

all: $(PROGS) $(DIR)

strindex: ex4-1.o
	$(CC) $(CFLAGS) -o $@ $^

atof: ex4-2.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

itoa_r: ex4-12.o
	$(CC) $(CFLAGS) -o $@ $^

reverse_r: ex4-13.o
	$(CC) $(CFLAGS) -o $@ $^

swap: ex4-14.o
	$(CC) $(CFLAGS) -o $@ $^

${DIR}:
	(cd ex$@; make)

clean:
	rm -rf $(PROGS) *.o *~
	for no in $(DIR); do\
		(cd ex$$no; make clean);\
	done
