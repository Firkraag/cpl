CC = gcc
CFLAGS = -g -Wall -O2 -I . 

OBJS= polish.o getch.o getop.o stack.o

calculator:  $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm


clean:
	rm -rf calculator *.o *~


