CFLAGS = -g3 #-pedantic #-std=c99 -g3 -Wall
CC = gcc

all: seek

seek: seek.o
		${CC} ${CFLAGS} -o seek seek.c -lm
