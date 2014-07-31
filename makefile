all : calcey.o mathey.o matrixey.o mathey

calcey.o: calcey.c mathey.h
	gcc -c calcey.c

mathey.o: mathey.c mathey.h
	gcc -c mathey.c

matrixey.o: matrixey.c
	gcc -c matrixey.c

mathey: mathey.o matrixey.o calcey.o
	gcc calcey.o mathey.o matrixey.o -o mathey
