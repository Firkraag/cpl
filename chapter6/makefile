CC = gcc
CFLAGS = -Wall -O2 -I .
DIR = 6-1 6-3 6-4
PROGS =

all: $(PROGS) $(DIR)

6-1:
	(cd ex6-1; make)

clean:
	rm -rf $(PROGS) *.o *~
	for no in $(DIR); do\
		(cd ex$$no; make clean);\
	done
