CC = gcc
CFLAGS = -Wall -O2 -I .

OBJS = main.o qsort.o io.o

sort: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f sort *.o *~

