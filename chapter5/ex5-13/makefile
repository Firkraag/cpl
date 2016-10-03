CC = gcc
INC = ../../include
CFLAGS = -Wall -O2 -I . -I $(INC)

OBJS = main.o io.o alloc.o

tail: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f tail *.o *~

