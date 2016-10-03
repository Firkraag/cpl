CC = gcc
INC = ../../include/
CFLAGS = -Wall -O2 -I . -I $(INC)

OBJS = main.o fields.o qsort.o io.o cmp.o alloc.o option.o 

sort: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f sort *.o *~

