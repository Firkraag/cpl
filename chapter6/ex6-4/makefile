CC = gcc
CFLAGS = -Wall -O2 -I .
OBJS = main.o tree.o getword.o getch.o

countWord: $(OBJS)
	$(CC) -o $@ $^ 

clean:
	rm -f countWord $(OBJS) *.o *~
