CFLAGS = -g3 -std=c99 
CC = gcc

#all: seek

#seek: seek.o
#		${CC} ${CFLAGS} -o seek seek.c -lm

all: dumbsolve

dumbsolve: dumbsolve.o
		${CC} ${CFLAGS} dumbsolve.c -o dumbsolve -lm