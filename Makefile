CFLAGS = -g3 #-pedantic #-std=c99 -g3 -Wall
CC = gcc

all: seek

jacobi: seek.o
		${CC} ${CFLAGS} -o dumbsolve dumbsolve.c -lm
