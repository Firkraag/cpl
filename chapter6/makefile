CC = gcc
CFLAGS = -Wall -O2 -I .
DIR = 6-1 6-3 6-4 6-6
OBJS = ex6-5.o

all: $(OBJS) $(DIR)

6-1:
	(cd ex6-1; make)
6-3:
	(cd ex6-3; make)
6-4:
	(cd ex6-4; make)
6-6:
	(cd ex6-6; make)
clean:
	rm -rf $(OBJS) *.o *~
	for no in $(DIR); do\
		(cd ex$$no; make clean);\
	done
