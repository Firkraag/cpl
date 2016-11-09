CHAPTERS = 1 2 3 4 5 6 7 8

all: $(CHAPTERS)

$(CHAPTERS):
	(cd chapter$@; make)

clean:
	rm -rf *.o *~
	for no in $(CHAPTERS); do\
		(cd chapter$$no; make clean);\
	done

