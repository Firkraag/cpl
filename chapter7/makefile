CC = gcc
CFLAGS = -Wall -O2 -I .

PROGS = lower upper print
OBJS = minprintf.o minscanf.o

all: $(PROGS) $(OBJS)

lower: ex7-1.o
	$(CC) $(CFLAGS) -o lower ex7-1.o

upper: ex7-1.o
	$(CC) $(CFLAGS) -o upper ex7-1.o

print: ex7-2.o
	$(CC) $(CFLAGS) -o print ex7-2.o

minprintf.o: ex7-3.c
	$(CC) $(CFLAGS) -c -o minprintf.o ex7-3.c

minscanf.o: ex7-4.c
	$(CC) $(CFLAGS) -c -o minscanf.o ex7-4.c

clean:
	rm -rf $(PROGS) *.o *~
