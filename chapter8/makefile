CC = gcc
CFLAGS = -g -Wall -O2 -I .

LIB=libsyscall.a
PROGS = cat test ex8-6.o ex8-7.o ex8-8.o
OBJS = fclose.o fopen.o fflush.o fillbuf.o flushbuf.o fgets.o getline.o\
	   ungetc.o fputs.o putc.o syscall.o fseek.o
DIR = 8-5


all: $(PROGS) $(OBJS) $(DIR)

cat: ex8-1.o
	$(CC) $(CFLAGS) -o cat ex8-1.o

test: test.o $(LIB)
	$(CC) $(CFLAGS) -static -o $@ $^

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

8-5:
	(cd ex8-5; make)

clean:
	rm -rf $(PROGS) $(LIB) *.o *~
	for no in $(DIR); do\
		(cd ex$$no; make clean);\
	done
