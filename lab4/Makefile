CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic

.PHONY: all buildAndTestNode buildAndTestArray clean

all: node array

# printf rather than echo: /bin/sh's echo does not expand \n portably, so the
# old recipe printed a literal backslash-n on dash.
node: testNode.c node.c node.h
	@printf 'Lab by Azer Sadykhzadeh :)\n\n'
	$(CC) $(CFLAGS) testNode.c node.c -o node

array: testArray.c array.c array.h
	@printf 'Lab by Azer Sadykhzadeh :)\n\n'
	$(CC) $(CFLAGS) testArray.c array.c -o array

buildAndTestNode: node
	./node
	@echo "Finished!"

buildAndTestArray: array
	./array
	@echo "Finished!"

clean:
	rm -f ./node ./array
	@echo "Done :)"
