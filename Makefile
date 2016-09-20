CC = gcc
CFLAGS = -Wall -O2 -I .

CHAPTERS = 1 5

all: $(CHAPTERS)

1: 
	(cd chapter1; make)
2: 
	(cd chapter2; make)
3: 
	(cd chapter3; make)
4: 
	(cd chapter4; make)
5:
	(cd chapter5; make)

