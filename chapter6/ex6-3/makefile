CC = gcc
CFLAGS = -Wall -I . -g
OBJS = main.o tree.o getword.o getch.o dynamic_list.o

countWord: $(OBJS)
	$(CC)  $(CFLAGS) -o $@ $^ 

clean:
	rm -f countWord $(OBJS) *.o *~
