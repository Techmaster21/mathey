all : calcey.o mathey.o matrixey.o helpey.o mathey

calcey.o: calcey.c mathey.h
	gcc -c calcey.c

mathey.o: mathey.c mathey.h
	gcc -c mathey.c

matrixey.o: matrixey.c
	gcc -c matrixey.c

helpey.o: helpey.c
	gcc -c helpey.c

mathey: mathey.o matrixey.o helpey.o calcey.o
	gcc calcey.o mathey.o matrixey.o helpey.o -o mathey
