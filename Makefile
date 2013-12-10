CFLAGS = -g3 -std=c99 #-pedantic #-std=c99 -g3 -Wall
CC = gcc

all: seek

seek: seek.o
		${CC} ${CFLAGS} -o seek seek.c -lm
