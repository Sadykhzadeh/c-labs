CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: bubble sortChar

bubble: bubble_main.c bubble_sort.c bubble_sort.h
	$(CC) $(CFLAGS) bubble_main.c bubble_sort.c -o bubble

sortChar: sortChar_main.c sortChar_bubbleSort.c sortChar_bubbleSort.h
	$(CC) $(CFLAGS) sortChar_main.c sortChar_bubbleSort.c -o sortChar

test: all
	./bubble
	./sortChar

clean:
	rm -f ./bubble ./sortChar
