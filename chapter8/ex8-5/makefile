CC = gcc
CFLAGS = -Wall -O2 -I .
PROGS = fsize

fsize: fsize.o printInfo.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROGS) *.o *~
