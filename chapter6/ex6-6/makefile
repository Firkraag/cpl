CC = gcc
CFLAGS = -Wall -O2 -I .
OBJS = main.o  parseLine.o table.o getline2.o

prePrecessor: $(OBJS)
	$(CC) -o $@ $^ 

clean:
	rm -f prePrecessor $(OBJS) *.o *~
