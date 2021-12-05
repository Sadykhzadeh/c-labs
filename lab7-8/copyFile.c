#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Missing arguments\n");
        return -1;
    }
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) return -1;
    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) return -1;
    int buffer[9999], bytes;
    while ((bytes = fread(buffer, 1, 9999, inputFile)))
        if (fwrite(buffer, 1, bytes, outputFile) != bytes) {
            return -1;
        }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}