CC = gcc
CFLAGS = -g -Wall -O2 -I .

PROGS = var_range htoi squeeze any setbits invert rightrot bitcount lower


all: $(PROGS) 

var_range: ex2-1.o
	$(CC) $(CFLAGS) -o $@ $^

htoi: ex2-3.o
	$(CC) $(CFLAGS) -o $@ $^

squeeze: ex2-4.o
	$(CC) $(CFLAGS) -o $@ $^

any: ex2-5.o
	$(CC) $(CFLAGS) -o $@ $^

setbits: ex2-6.o
	$(CC) $(CFLAGS) -o $@ $^

invert: ex2-7.o
	$(CC) $(CFLAGS) -o $@ $^

rightrot: ex2-8.o
	$(CC) $(CFLAGS) -o $@ $^

bitcount: ex2-9.o
	$(CC) $(CFLAGS) -o $@ $^

lower: ex2-10.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROGS) *.o *~
