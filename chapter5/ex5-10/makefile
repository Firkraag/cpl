CC = gcc
INC = ../../include/
CFLAGS = -Wall -O2 -I . -I $(INC)


polish: polish.o getop.o stack.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f polish *.o *~

