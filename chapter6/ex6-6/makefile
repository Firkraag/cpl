CC = gcc
CFLAGS = -Wall -O2 -I . -g
OBJS = main.o table.o getline2.o

prePrecessor: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f prePrecessor $(OBJS) *.o *~
