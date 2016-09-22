CC = gcc
CFLAGS = -Wall -O2 -I .
OBJS = main.o getword.o getch.o

countKeyword: $(OBJS)
	$(CC) -o $@ $^ 

clean:
	rm -f countKeyword $(OBJS)
