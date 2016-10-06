CC = gcc
INC = ../../include
CFLAGS = -Wall -O2 -I . -I $(INC)

PROGS = entab detab

all: $(PROGS)

entab: entab.o tab.o getch.o

detab: detab.o tab.o 

clean:
	rm -f $(PROGS) *.o *~

