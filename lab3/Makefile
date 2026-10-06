CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: arrSum caecar stringToTheHead

arrSum: arrSum.c
	$(CC) $(CFLAGS) arrSum.c -o arrSum

caecar: caecar.c
	$(CC) $(CFLAGS) caecar.c -o caecar

stringToTheHead: stringToTheHead.c
	$(CC) $(CFLAGS) stringToTheHead.c -o stringToTheHead

test: caecar
	./caecar

clean:
	rm -f ./arrSum ./caecar ./stringToTheHead
