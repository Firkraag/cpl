CC = gcc
CFLAGS = -Wall -O2 -I . 

OBJS= polish.o getop.o stack.o

calculator: $(OBJS)
	$(CC) $(CFLAGS) -o calculator $(OBJS) -lm

clean:
	rm -rf $(PROGS) *.o *~
