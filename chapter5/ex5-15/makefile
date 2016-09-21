CC = gcc
CFLAGS = -Wall -O2 -I .

OBJS = main.o qsort.o io.o cmp.o alloc.o

sort: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f sort *.o *~

