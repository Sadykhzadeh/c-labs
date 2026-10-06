CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic

.PHONY: all compile1 compile2 compile3 clean

all: task1 task2 task3

task1: task1.c
	$(CC) $(CFLAGS) task1.c -o task1

task2: task2.c
	$(CC) $(CFLAGS) task2.c -o task2

task3: task3.c
	$(CC) $(CFLAGS) task3.c -o task3

compile1: task1
	./task1

compile2: task2
	./task2 9 1 21 5 3 7 4

compile3: task3
	./task3

clean:
	rm -f ./task1 ./task2 ./task3
