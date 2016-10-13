CC = gcc
CFLAGS = -Wall -O2 -I .

PROGS = Fah2Cel Cel2Fah reverseTable ex1-6 EOF countBlanks compressBlanks copy printWord print printFilter removeBlanks reverse detab entab \
		fold removeComment syntaxCheck

all: $(PROGS)

Fah2Cel: ex1-3.o
	$(CC) -o Fah2Cel ex1-3.o

Cel2Fah: ex1-4.o
	$(CC) -o Cel2Fah ex1-4.o 

reverseTable: ex1-5.o
	$(CC) -o reverseTable ex1-5.o

ex1-6: ex1-6.o

EOF: ex1-7.o
	$(CC) -o EOF ex1-7.o

countBlanks: ex1-8.o
	$(CC) -o countBlanks ex1-8.o

compressBlanks: ex1-9.o
	$(CC) -o compressBlanks ex1-9.o

copy: ex1-10.o
	$(CC) -o copy ex1-10.o

printWord: ex1-12.o
	$(CC) -o printWord ex1-12.o

print: ex1-16.o getline2.o
	$(CC) -o print ex1-16.o getline2.o

printFilter: ex1-17.o getline2.o dynamic_list.o dynamic_list.h
	$(CC) -o printFilter ex1-17.o getline2.o dynamic_list.o

removeBlanks: ex1-18.o getline2.o dynamic_list.o dynamic_list.h
	$(CC) -o removeBlanks ex1-18.o getline2.o dynamic_list.o

reverse: ex1-19.o dynamic_list.h dynamic_list.o getline2.o
	$(CC) -o reverse ex1-19.o dynamic_list.o getline2.o

detab: ex1-20.o
	$(CC) -o detab ex1-20.o

entab: ex1-21.o
	$(CC) -o entab ex1-21.o

fold: ex1-22.o
	$(CC) -o fold ex1-22.o

removeComment: ex1-23.o
	$(CC) -o removeComment ex1-23.o

syntaxCheck: ex1-24.o stack.o stack.h
	$(CC) -o syntaxCheck ex1-24.o stack.o

clean:
	rm -rf $(PROGS) *.o *~
