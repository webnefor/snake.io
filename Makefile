
CC=gcc
FLAGS= --std=c99 -Ofast -O3

build:
	$(CC) -o lsnake $(FLAGS) -c snake.c
	$(CC) -o snake $(FLAGS) main.c lsnake
	rm -rf lsnake