CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic

.PHONY: all buildAndTestCopy buildAndTestHT clean

all: copy ht studentAF.o

copy: copyFile.c
	$(CC) $(CFLAGS) copyFile.c -o copy

ht: headAndTail.c
	$(CC) $(CFLAGS) headAndTail.c -o ht

# studentAF.c has no main of its own, so it was never built by any target and
# nothing noticed that it did not compile.
studentAF.o: studentAF.c
	$(CC) $(CFLAGS) -c studentAF.c -o studentAF.o

buildAndTestCopy: copy
	./copy copyFile.c helloWorld.c
	@echo "Finished! :D"

buildAndTestHT: ht
	./ht ./headAndTail.c h 10
	@echo "===="
	./ht ./headAndTail.c t 10
	@echo "Finished!"

clean:
	rm -f ./copy ./ht ./studentAF.o ./helloWorld.c
	@echo "Done :)"
