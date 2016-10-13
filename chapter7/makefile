CC = gcc
CFLAGS = -Wall -O2 -I .

PROGS = lower upper minprintf

all: $(PROGS)

lower: ex7-1.o
	$(CC) -o lower ex7-1.o

upper: ex7-1.o
	$(CC) -o upper ex7-1.o

minprintf: ex7-3.o
	$(CC) -o minprintf ex7-3.o

clean:
	rm -rf $(PROGS) *.o *~
