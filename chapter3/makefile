CC = gcc
CFLAGS = -g -Wall -O2 -I .

PROGS = binsearch escape expand itoa itob itoan


all: $(PROGS) 

binsearch: ex3-1.o
	$(CC) $(CFLAGS) -o $@ $^

escape: ex3-2.o
	$(CC) $(CFLAGS) -o $@ $^

expand: ex3-3.o
	$(CC) $(CFLAGS) -o $@ $^

itoa: ex3-4.o
	$(CC) $(CFLAGS) -o $@ $^

itob: ex3-5.o
	$(CC) $(CFLAGS) -o $@ $^

itoan: ex3-6.o
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -rf $(PROGS) *.o *~
